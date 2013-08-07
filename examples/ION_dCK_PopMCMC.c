#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <getopt.h>

#include <sys/time.h>

#include <mpi.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_ion_model.h>
#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_popmcmc.h>

#include <gmcmc/gmcmc_matlab.h>

#include "common.h"

// Whether to use log space for parameter values - helps with very small/large values
#define LOG10SPACE

#define MPI_ERROR_CHECK(call, msg) \
  do { \
    int error = (call); \
    if (error != MPI_SUCCESS) { \
      fprintf(stderr, "%s\n%s returned %d in %s (%s:%d):\n", \
                      msg, #call, error, __func__, __FILE__, __LINE__); \
      char string[MPI_MAX_ERROR_STRING]; \
      int length; \
      int errorerror = MPI_Error_string(error, string, &length); \
      if (errorerror != MPI_SUCCESS) \
        fprintf(stderr, "\tadditionally, MPI_Error_string returned %d when looking up the error code\n", errorerror);\
      else \
        fprintf(stderr, "\t%s\n", string); \
      return error; \
    } \
  } while (false)

/**
 * Calculates the Q matrix from the current parameter values.
 *
 * @param [in]  params  the parameter values
 * @param [out] Q       the Q matrix, initialised to zero
 * @param [in]  ldq     the leading dimension of the Q matrix
 */
static void calculate_Q_matrix(const double *, double *, size_t);

int main(int argc, char * argv[]) {
  // Since we are using MPI for parallel processing initialise it here before
  // parsing the arguments for our program
  MPI_ERROR_CHECK(MPI_Init(&argc, &argv), "Failed to initialise MPI");

  // Handle MPI errors ourselves
  MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

  // Get the MPI process ID and number of cores
  int rank, size;
  MPI_ERROR_CHECK(MPI_Comm_rank(MPI_COMM_WORLD, &rank), "Unable to get MPI rank");
  MPI_ERROR_CHECK(MPI_Comm_size(MPI_COMM_WORLD, &size), "Unable to get MPI communicator size");

  // Default dataset file
  const char * data_file = "data/ION_dCK_0,5s.mat";

  /*
   * Set up default MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set number of tempered distributions to use
  mcmc_options.num_temperatures = 10;

  // Set number of burn-in and posterior samples
  mcmc_options.num_burn_in_samples   = 2000;
  mcmc_options.num_posterior_samples = 5000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate            =  50;
  mcmc_options.upper_acceptance_rate =   0.5;
  mcmc_options.lower_acceptance_rate =   0.2;

  // Callbacks
  mcmc_options.acceptance = acceptance_monitor;
  mcmc_options.write = gmcmc_matlab_popmcmc_write;

  int error;
  if ((error = parse_options(argc, argv, &mcmc_options, &data_file)) != 0) {
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return error;
  }

  // Output file
  gmcmc_matlab_outputID = argv[optind];

  // How often to save posterior samples
  gmcmc_matlab_posterior_save_size = 15000000 / mcmc_options.num_temperatures;  // Results in ~1GB files for this model

  // Save burn-in
  gmcmc_matlab_save_burn_in = true;

  // Set up temperature schedule
  // Since we are using MPI we *could* just initialise the temperatures this
  // process needs but there isn't necessarily going to be a 1-1 mapping of
  // processes to temperatures so initialise them all here just in case.
  double * temperatures = malloc(mcmc_options.num_temperatures * sizeof(double));
  if (temperatures == NULL) {
    fputs("Unable to allocate temperature schedule\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }
  for (unsigned int i = 0; i < mcmc_options.num_temperatures; i++)
    temperatures[i] = pow(i * (1.0 / (mcmc_options.num_temperatures - 1.0)), 5.0);
  mcmc_options.temperatures = temperatures;

  // Print out MCMC options on node 0
  if (rank == 0) {
    fprintf(stdout, "Number of cores: %d\n", size);
    print_options(stdout, &mcmc_options);
  }


  /*
   * Common model settings
   */
  const unsigned int num_params = 4;

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL) {
    fputs("Failed to allocate space for priors\n", stderr);
    free(temperatures);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }

#ifdef LOG10SPACE
  // Set up priors for log space
  for (unsigned int i = 0; i < num_params; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], -2.0, 4.0)) != 0) {
      // Clean up
      for (unsigned int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[i]);
      free(priors);
      free(temperatures);
      fputs("Unable to create priors\n", stderr);
      MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
      return -3;
    }
  }
#else
  // Set up priors for standard space
  for (unsigned int i = 0; i < num_params; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.01, 10000.0)) != 0) {
      // Clean up
      for (unsigned int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[i]);
      free(priors);
      free(temperatures);
      fputs("Unable to create priors\n", stderr);
      MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
      return -3;
    }
  }
#endif

  // Load the dataset
  gmcmc_dataset * dataset;
  if ((error = gmcmc_dataset_create_matlab_ion(&dataset, data_file)) != 0) {
    // Clean up
    for (unsigned int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    free(temperatures);
    fputs("Unable to load dataset\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  // Create the model
  gmcmc_model * model;
  if ((error = gmcmc_model_create(&model, num_params, priors, gmcmc_ion_proposal_mh, gmcmc_ion_likelihood_mh)) != 0) {
    // Clean up
    for (unsigned int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    fputs("Unable to create model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  // Priors have been copied into model so don't need them here any more
  for (unsigned int i = 0; i < num_params; i++)
    gmcmc_distribution_destroy(priors[i]);
  free(priors);

  // Set up starting values for all temperatures
#ifdef LOG10SPACE
  double params[] = { 2.0, 2.0, 3.0, 3.0 };
#else
  double params[] = { 100.0, 100.0, 1000.0, 1000.0 };
#endif
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to set initial parameter values\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  // Set initial step size
  gmcmc_model_set_stepsize(model, 1.0);

  /*
   * ION model settings
   */
  gmcmc_ion_model * ion_model;
  if ((error = gmcmc_ion_model_create(&ion_model, 2, 1, calculate_Q_matrix)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to create Ion Channel specific model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  gmcmc_model_set_modelspecific(model, ion_model);


  /*
   * Create a parallel random number generator to use
   */
  gmcmc_prng64 * rng;
  const gmcmc_prng64_type * rng_type = gmcmc_prng64_dcmt607;
  int id = rank;
  if (id >= rng_type->max_id) {
    rng_type = gmcmc_prng64_dcmt1279;
    id -= rng_type->max_id;
  }
  if (id >= rng_type->max_id) {
    rng_type = gmcmc_prng64_dcmt2203;
    id -= rng_type->max_id;
  }
  if (id >= rng_type->max_id) {
    rng_type = gmcmc_prng64_dcmt2281;
    id -= rng_type->max_id;
  }
  if ((error = gmcmc_prng64_create(&rng, rng_type, id)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    gmcmc_ion_model_destroy(ion_model);
    fputs("Unable to create parallel RNG\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3241);

  // Start timer
  struct timeval start, stop;
  if (rank == 0)  {
    if (gettimeofday(&start, NULL) != 0) {
      fputs("gettimeofday failed\n", stderr);
      return -5;
    }
  }

  /*
   * Call main population MCMC routine using MPI
   */
  error = gmcmc_popmcmc_mpi(&mcmc_options, model, dataset, rng);

  if (rank == 0) {
    // Stop timer
    if (gettimeofday(&stop, NULL) != 0) {
      fputs("gettimeofday failed\n", stderr);
      return -6;
    }

    double time = ((double)(stop.tv_sec - start.tv_sec) +
                   (double)(stop.tv_usec - start.tv_usec) * 1.e-6);

    fprintf(stdout, "Simulation took %.3f seconds\n", time);
  }

  // Clean up (dataset, model, rng)
  free(temperatures);
  gmcmc_dataset_destroy(dataset);
  gmcmc_model_destroy(model);
  gmcmc_ion_model_destroy(ion_model);
  gmcmc_prng64_destroy(rng);

  MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");

  return error;
}

static void calculate_Q_matrix(const double * params, double * Q, size_t ldq) {
  // Rename for clarity
#ifdef LOG10SPACE
  double K_1   = pow(10.0, params[0]);
  double K_2   = pow(10.0, params[1]);
  double Beta  = pow(10.0, params[2]);
  double Alpha = pow(10.0, params[3]);
#else
  double K_1   = params[0];
  double K_2   = params[1];
  double Beta  = params[2];
  double Alpha = params[3];
#endif

  // Construct Q matrix
  // 3 states for this model
  Q[0] = -K_1;
  Q[1] =  K_2;
  Q[2] =  0.0;

  Q[ldq + 0] =  K_1;
  Q[ldq + 1] = -K_2 - Beta;
  Q[ldq + 2] = Alpha;

  Q[2 * ldq + 0] =  0.0;
  Q[2 * ldq + 1] = Beta;
  Q[2 * ldq + 2] = -Alpha;
}
