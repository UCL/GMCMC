#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <getopt.h>

#include <mpi.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_ion_model.h>
#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_popmcmc.h>

#include "acceptance.h"
#include "matlab.h"

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

  // Default dataset file
  const char * data_file = "data/ION_Five_State_Balanced_Data_Long.mat";

  // Process command line options
  int c;
  while ((c = getopt(argc, argv, "d:")) != -1) {
    switch (c) {
      case 'd':
        data_file = optarg;
        break;
      default:
        fprintf(stdout, "Usage: %s [-d <dataset>] output\n", argv[0]);
        return -1;
    }
  }

  if (optind >= argc) {
    fprintf(stdout, "Usage: %s [-d <dataset>] output\n", argv[0]);
    return -1;
  }

  // Output file
  outputID = argv[optind];

  // Handle MPI errors ourselves
  MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

  /*
   * Set up MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set number of tempered distributions to use
  mcmc_options.num_temperatures = 20;

  // Set up temperature schedule
  // Since we are using MPI we *could* just initialise the temperatures this
  // process needs but there isn't necessarily going to be a 1-1 mapping of
  // processes to temperatures so initialise them all here just in case.
  double * temperatures = malloc(mcmc_options.num_temperatures * sizeof(double));
  if (temperatures == NULL) {
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    fputs("Unable to allocate temperature schedule\n", stderr);
    return -2;
  }
  for (unsigned int i = 0; i < mcmc_options.num_temperatures; i++)
    temperatures[i] = pow(i * (1.0 / (mcmc_options.num_temperatures - 1.0)), 5.0);
  mcmc_options.temperatures = temperatures;

  // Set number of burn-in and posterior samples
  mcmc_options.num_burn_in_samples   = 2000;
  mcmc_options.num_posterior_samples = 5000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate      =  50;
  mcmc_options.upper_step_size =   0.5;
  mcmc_options.lower_step_size =   0.2;

  // Callbacks
  mcmc_options.acceptance = acceptance_monitor;
  mcmc_options.write = write_matlab;

  int error;

  /*
   * Common model settings
   */
  const unsigned int num_params = 9;

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
    if ((error = gmcmc_distribution_create_uniform(&priors[i], -2.0, 10.0)) != 0) {
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
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 1.0e-2, 1.0e10)) != 0) {
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

  // Set the step size
  gmcmc_model_set_stepsize(model, 0.01);

  // Set up starting values for all temperatures
#ifdef LOG10SPACE
  double params[] = { 7.6990, 3.3010, 8.6990, 3.3010, 1.1761, 3.4771, 4.1761, 2.6990, 8.6990 };
#else
  double params[] = { 5e7, 2000, 5e8, 2000, 15, 3000, 15000, 500, 5e8 };
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

  /*
   * ION model settings
   */
  gmcmc_ion_model * ion_model;
  if ((error = gmcmc_ion_model_create(&ion_model, 3, 2, calculate_Q_matrix)) != 0) {
    // Clean up
    for (unsigned int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
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
  // Get the MPI process ID
  int rank;
  MPI_ERROR_CHECK(MPI_Comm_rank(MPI_COMM_WORLD, &rank), "Unable to get MPI rank");

  // Create a parallel RNG for the MPI process
  gmcmc_prng64 * rng;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_dcmt521, rank)) != 0) {
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
  gmcmc_prng64_seed(rng, 1234);

  /*
   * Call main population MCMC routine using MPI
   */
  error = gmcmc_popmcmc_mpi(&mcmc_options, model, dataset, rng);

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
  // As described in Ch 18 & 20 in Single Channel Recording book

  // Rename for clarity
#ifdef LOG10SPACE
  double K_p1     = pow(10.0, params[0]);       // k_{+1}
  double K_m1     = pow(10.0, params[1]);       // k_{-1}
  double K_p2     = pow(10.0, params[2]);       // k_{+2}
  double K_m2     = pow(10.0, params[3]);       // k_{-2}
  double Beta_1   = pow(10.0, params[4]);       // Beta_{1}
  double Alpha_1  = pow(10.0, params[5]);       // Alpha_{1}
  double Beta_2   = pow(10.0, params[6]);       // Beta_{2}
  double Alpha_2  = pow(10.0, params[7]);       // Alpha_{2}
  double KStar_p2 = pow(10.0, params[8]);       // k*_{+2}
#else
  double K_p1     = params[0];  // k_{+1}
  double K_m1     = params[1];  // k_{-1}
  double K_p2     = params[2];  // k_{+2}
  double K_m2     = params[3];  // k_{-2}
  double Beta_1   = params[4];  // Beta_{1}
  double Alpha_1  = params[5];  // Alpha_{1}
  double Beta_2   = params[6];  // Beta_{2}
  double Alpha_2  = params[7];  // Alpha_{2}
  double KStar_p2 = params[8];  // k*_{+2}
#endif

  // Microsopic reveribility condition
  double KStar_m2 = (Alpha_2 / Beta_2) * (Beta_1 / Alpha_1) * (K_m2 / K_p2) * KStar_p2; // k*_{-2}

  // Agonist concentration
  double X_A = 1e-7;    // This should become an extra variable to be passed

  // Construct Q matrix - [1 2 3] are closed states, [4 5] are open
  // Q_FF
  Q[0 * ldq + 0] = -(Beta_2 + 2.0 * K_m2);
  Q[0 * ldq + 1] = K_p2 * X_A;
  Q[1 * ldq + 0] = 2.0 * K_m2;
  Q[1 * ldq + 1] = -(Beta_1 + K_p2 * X_A + K_m1);
  Q[1 * ldq + 2] = 2.0 * K_p1 * X_A;
  Q[2 * ldq + 1] = K_m1;
  Q[2 * ldq + 2] = -2.0 * K_p1 * X_A;

  //Q_AF
  Q[0 * ldq + 4] = Alpha_2;
  Q[1 * ldq + 3] = Alpha_1;

  // Q_FA
  Q[3 * ldq + 1] = Beta_1;
  Q[4 * ldq + 0] = Beta_2;

  // Q_AA
  Q[3 * ldq + 3] = -(Alpha_1 + KStar_p2 * X_A);
  Q[3 * ldq + 4] = 2.0 * KStar_m2;
  Q[4 * ldq + 3] = KStar_p2 * X_A;
  Q[4 * ldq + 4] = -(Alpha_2 + 2.0 * KStar_m2);
}
