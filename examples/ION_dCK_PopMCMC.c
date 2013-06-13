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

static void calculate_Q_matrix(const double *, double *, size_t);

int main(int argc, char * argv[]) {
  const char * outputID = NULL; // output file

  // Since we are using MPI for parallel processing initialise it here before
  // parsing the arguments for our program
  MPI_ERROR_CHECK(MPI_Init(&argc, &argv), "Failed to initialise MPI");

  // Process command line arguments
  struct option options[] = {
    { "output", required_argument, NULL, 'o' },
    { NULL,     0,                 NULL,  0  }
  };

  int c, index;
  while ((c = getopt_long(argc, argv, "o:", options, &index)) != -1) {
    switch (c) {
      case 'o':
        if (optarg == NULL) {
          fputs("Option \"output\" requires an argument\n", stderr);
          return -index;
        }
        outputID = optarg;
        break;
      default:
        fprintf(stderr, "Unknown option '%c'\n", c);
        return -index;
    }
  }

  if (outputID == NULL) {
    fprintf(stderr, "Usage:\n\t%s -o|--output=<filename>\nwhere:\n\t<filename> is a file to save the samples in\n", argv[0]);
    return -1;
  }

  /*
   * Set up MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set output file for saving samples
  mcmc_options.outputID = outputID;

  // Decide whether to save burn-in
  mcmc_options.save_burn_in = true;

  // Set number of tempered distributions to use
  mcmc_options.num_temps = 10;

  // Set up temperature schedule
  // Since we are using MPI we *could* just initialise the temperatures this
  // process needs but there isn't necessarily going to be a 1-1 mapping of
  // processes to temperatures so initialise them all here just in case.
  double * temperatures = malloc(mcmc_options.num_temps * sizeof(double));
  if (temperatures == NULL) {
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    fputs("Unable to allocate temperature schedule\n", stderr);
    return -2;
  }
  for (int i = 0; i < mcmc_options.num_temps; i++)
    temperatures[i] = pow(i * (1.0 / (mcmc_options.num_temps - 1.0)), 5.0);
  mcmc_options.temperatures = temperatures;

  // Set number of burn-in and posterior samples, and how often to save
  mcmc_options.num_burn_in_samples   = 1000;
  mcmc_options.num_posterior_samples = 1000;
  mcmc_options.posterior_save_size   = 1000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate = 50;
  mcmc_options.upper      = 0.5;
  mcmc_options.lower      = 0.2;

  int error;

  /*
   * Common model settings
   */
  gmcmc_model * model;

  const unsigned int num_params = 4;

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL) {
    fputs("Failed to allocate space for priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }

#ifdef LOG10SPACE
  // Set up priors for log space
  for (int i = 0; i < num_params; i++) {
    if ((error = gmcmc_distribution_create(&priors[i], gmcmc_distribution_uniform, -2.0, 4.0)) != 0) {
      // Clean up
      for (int j = 0; j < i; j++)
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
  for (int i = 0; i < num_params; i++) {
    if ((error = gmcmc_distribution_create(&priors[i], gmcmc_distribution_uniform, 0.0, 10000.0)) != 0) {
      // Clean up
      for (int j = 0; j < i; j++)
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
  if ((error = gmcmc_dataset_load_matlab(&dataset, "ION_dCK_0,5s.mat")) != 0) {
    // Clean up
    for (int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    free(temperatures);
    fputs("Unable to load dataset\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, dataset, num_params, priors, gmcmc_ion_proposal_mh, gmcmc_ion_likelihood_mh)) != 0) {
    // Clean up
    for (int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    fputs("Unable to create model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  // Priors have been copied into model so don't need them here any more
  for (int i = 0; i < num_params; i++)
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
    fputs("Unable to set initial parameter values\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

#if 0
  // Set up parameter names for reference
  const char * param_names[] = { "K_1", "K_2", "Beta", "Alpha" };
  if ((error = gmcmc_model_set_param_names(model, param_names)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    fputs("Unable to set parameter names\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  // Set up blocking for parameters - either fixed blocks or random blocks
  // (This is used for higher-dimensional problems with ill-conditioned metric
  // tensors)
  // Either 'fixed'
  int * blocks = malloc(4 * sizeof(int));
  blocks[0] = 0; blocks[1] = 1; blocks[2] = 2; blocks[3] = 3;
  int block_sizes[] = { 4 };
  if ((error = gmcmc_model_set_blocking(model, &blocks, block_sizes, 1)) != 0) {
    // Clean up
    free(blocks);
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    fputs("Unable to set parameter blocking\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -6;
  }
  free(blocks);
  // or 'random'
  /*int block_sizes[] = { 1, 1, 1 };
  gmcmc_model_set_blocking(model, 3, block_sizes, NULL);*/
#endif

  /*
   * ION model settings
   */
  gmcmc_ion_model * ion_model;
  if ((error = gmcmc_ion_model_create(&ion_model, 2, 1, calculate_Q_matrix)) != 0) {
    // Clean up
    for (int i = 0; i < num_params; i++)
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
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_dcmt607, rank)) != 0) {
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
  error = gmcmc_popmcmc_mpi(&mcmc_options, model, rng);

  // Clean up (dataset, priors, model, rng)
  for (int i = 0; i < num_params; i++)
    gmcmc_distribution_destroy(priors[i]);
  free(priors);
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

  Q[2 * ldq + 0] = Beta;
  Q[2 * ldq + 1] = Beta;
  Q[2 * ldq + 2] = -Alpha;
}
