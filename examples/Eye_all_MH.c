#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <getopt.h>
#include <time.h>

#include <sys/time.h>

#include <mpi.h>

#include <gmcmc/gmcmc_eye.h>
#include <gmcmc/gmcmc_popmcmc.h>

#include "common.h"

// Whether to infer initial conditions
#define INFER_ICS

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
  const char * data_file = "data/MacroC500Hz_Data.h5";

  /*
   * Set up default MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set number of tempered distributions to use
  mcmc_options.num_temperatures = 100;

  // Set number of burn-in and posterior samples
  mcmc_options.num_burn_in_samples   =  5000;
  mcmc_options.num_posterior_samples = 50000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate            =  50;
  mcmc_options.upper_acceptance_rate =   0.5;
  mcmc_options.lower_acceptance_rate =   0.2;

  // Callbacks
  mcmc_options.acceptance = acceptance_monitor;
  mcmc_options.burn_in_writer = NULL;
  mcmc_options.posterior_writer = NULL;

  int error;
  if ((error = parse_options(argc, argv, &mcmc_options, &data_file)) != 0) {
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return error;
  }

  if (argc < optind + 2) {
    fprintf(stderr, "Usage: %s [options] <input> [burn-in-file] <output>\n", argv[0]);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -1;
  }

  char * input_file = argv[optind++];

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
  // Avoid divide by zero in temperature scale
  if (mcmc_options.num_temperatures == 1)
    temperatures[0] = 1.0;
  else {
    for (unsigned int i = 0; i < mcmc_options.num_temperatures; i++)
      temperatures[i] = pow(i * (1.0 / (mcmc_options.num_temperatures - 1.0)), 5.0);
  }
  mcmc_options.temperatures = temperatures;

  // Print out MCMC options on node 0
  if (rank == 0) {
    fprintf(stdout, "Number of cores: %d\n", size);
    print_options(stdout, &mcmc_options);
  }


  /*
   * Common model settings
   */

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(7 * sizeof(gmcmc_distribution *))) == NULL) {
    fputs("Failed to allocate space for priors\n", stderr);
    free(temperatures);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }

  // Prior for 'A'
  if ((error = gmcmc_distribution_create_uniform(&priors[0], 0.0, 15.0)) != 0) {
    // Clean up
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }
  // Prior for 'p'
  if ((error = gmcmc_distribution_create_uniform(&priors[1], 0.0, 15.0)) != 0) {
    // Clean up
    gmcmc_distribution_destroy(priors[0]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }
  // Prior for 'tao'
  if ((error = gmcmc_distribution_create_uniform(&priors[2], 0.0, 15.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 2; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }
  // Prior for latency mean
  if ((error = gmcmc_distribution_create_uniform(&priors[3], 1.0, 100.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 3; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }
  // Prior for latency variance
  if ((error = gmcmc_distribution_create_uniform(&priors[4], 1.0, 5.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 4; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }
  // Prior for refract mean
  if ((error = gmcmc_distribution_create_uniform(&priors[5], 1.0, 500.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 5; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }
  // Prior for refract variance
  if ((error = gmcmc_distribution_create_uniform(&priors[6], 1.0, 5.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 6; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }

  // Load the dataset
  gmcmc_eye_dataset * dataset;
  if ((error = gmcmc_eye_dataset_load_hdf5(&dataset, data_file)) != 0) {
    // Clean up
    for (unsigned int i = 0; i < 7; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    free(temperatures);
    fputs("Unable to load dataset\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  // Create the model
  gmcmc_model * model;
  if ((error = gmcmc_model_create(&model, 7, priors)) != 0) {
    // Clean up
    for (unsigned int i = 0; i < 7; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    free(temperatures);
    gmcmc_eye_dataset_destroy(dataset);
    fputs("Unable to create model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  // Priors have been copied into model so don't need them any more
  for (unsigned int i = 0; i < 7; i++)
    gmcmc_distribution_destroy(priors[i]);
  free(priors);

  // Set up starting values for all temperatures
  double params[] = { 3.0, 3.0, 2.0, 50.0, 2.0, 100.0, 2.0 };
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_eye_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to set initial parameter values\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  // Set initial step size
  gmcmc_model_set_stepsize(model, 0.5);

  /*
   * Stochastic eye model settings
   */

  /*
   * Create a parallel random number generator to use
   */
  gmcmc_prng64 * rng;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_dcmt607, rank)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_eye_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to create parallel RNG\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  // Seed the RNG as a copy is made for the model
  gmcmc_prng64_seed(rng, 4721);

  gmcmc_eye_model * eye_model;
  if ((gmcmc_eye_model_create(&eye_model, input_file,
                              115, 2010, rng)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_eye_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    gmcmc_prng64_destroy(rng);
    fputs("Unable to create parallel RNG\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  gmcmc_model_set_modelspecific(model, eye_model);


  /*
   * Output file format.
   */
  if (optind + 1 < argc) {
    if ((error = gmcmc_filewriter_create_hdf5(&mcmc_options.burn_in_writer,
                                              argv[optind++], 7, 1,
                                              mcmc_options.num_temperatures,
                                              mcmc_options.num_burn_in_samples)) != 0) {
      // Clean up
      free(temperatures);
      gmcmc_eye_dataset_destroy(dataset);
      gmcmc_model_destroy(model);
      gmcmc_eye_model_destroy(eye_model);
      fputs("Unable to create HDF5 burn-in writer\n", stderr);
      MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
      return -5;
    }
  }

  if ((error = gmcmc_filewriter_create_hdf5(&mcmc_options.posterior_writer,
                                            argv[optind], 7, 1,
                                            mcmc_options.num_temperatures,
                                            mcmc_options.num_posterior_samples)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_eye_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    gmcmc_eye_model_destroy(eye_model);
    gmcmc_filewriter_destroy(mcmc_options.burn_in_writer);
    fputs("Unable to create HDF5 posterior writer\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  // Seed the RNG
  time_t seed = time(NULL);
  gmcmc_prng64_seed(rng, seed);
  fprintf(stdout, "Using PRNG seed: %ld\n", seed);

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
  error = gmcmc_popmcmc_mpi(model, dataset, gmcmc_eye_likelihood_mh, gmcmc_proposal_mh, &mcmc_options, rng);

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
  gmcmc_eye_dataset_destroy(dataset);
  gmcmc_model_destroy(model);
  gmcmc_eye_model_destroy(eye_model);
  gmcmc_filewriter_destroy(mcmc_options.burn_in_writer);
  gmcmc_filewriter_destroy(mcmc_options.posterior_writer);
  gmcmc_prng64_destroy(rng);

  MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");

  return error;
}
