#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <getopt.h>
#include <time.h>

#include <sys/time.h>

#include <mpi.h>

#include <gmcmc/gmcmc_ode.h>
#include <gmcmc/gmcmc_popmcmc.h>

#include "common.h"

// Whether to infer initial conditions
// #define INFER_ICS

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
 * Function to evaluate the right-hand side of a system of ODEs.
 *
 * @param [in]  t       the current timepoint
 * @param [in]  y       current values of the time-dependent variables
 * @param [out] yout    values of the time-dependent variables at time t
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
static int vyshemirsky_2008(double, const double *, double *, const double *);

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
  const char * data_file = "data/Vyshemirsky_2008_Model4_Benchmark_Data.mat";

  /*
   * Set up default MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set number of tempered distributions to use
  mcmc_options.num_temperatures = 100;

  // Set number of burn-in and posterior samples
  mcmc_options.num_burn_in_samples   =  50000;
  mcmc_options.num_posterior_samples = 100000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate            =  50;
  mcmc_options.upper_acceptance_rate =   0.7;
  mcmc_options.lower_acceptance_rate =   0.3;

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


  // How often to save posterior samples.
  gmcmc_matlab_save_size = 8500000 / mcmc_options.num_temperatures;  // Results in ~1GB files for this model

  // Save burn-in
  gmcmc_matlab_save_burn_in = true;

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
#ifdef INFER_ICS
  const unsigned int num_params = 14;    // Parameters and initial conditions
#else
  const unsigned int num_params = 7;    // Just parameters
#endif

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL) {
    fputs("Failed to allocate space for priors\n", stderr);
    free(temperatures);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }

  for (unsigned int i = 0; i < 7; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
      // Clean up
      for (unsigned int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      free(temperatures);
      fputs("Unable to create priors\n", stderr);
      MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
      return -3;
    }
  }

#ifdef INFER_ICS
  for (unsigned int i = 7; i < 14; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
      // Clean up
      for (unsigned int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      free(temperatures);
      fputs("Unable to create priors\n", stderr);
      MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
      return -3;
    }
  }
#endif

  // Load the dataset
  gmcmc_ode_dataset * dataset;
  if ((error = gmcmc_ode_dataset_load_matlab(&dataset, data_file)) != 0) {
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
  if ((error = gmcmc_model_create(&model, num_params, priors)) != 0) {
    // Clean up
    for (unsigned int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    free(temperatures);
    gmcmc_ode_dataset_destroy(dataset);
    fputs("Unable to create model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -4;
  }

  // Priors have been copied into model so don't need them any more
  for (unsigned int i = 0; i < num_params; i++)
    gmcmc_distribution_destroy(priors[i]);
  free(priors);

  // Set initial step size
  gmcmc_model_set_stepsize(model, 0.1);

  /*
   * ODE model settings
   */
  gmcmc_ode_model * ode_model;
  if ((error = gmcmc_ode_model_create(&ode_model, 4, 3, vyshemirsky_2008)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_ode_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to create ODE specific model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -6;
  }

#ifndef INFER_ICS
  double ics[] = { 1.0, 0.0, 1.0,  0.0,  0.0,  1.0, 0.0 };
  gmcmc_ode_model_set_ics(ode_model, ics);
#endif

  gmcmc_model_set_modelspecific(model, ode_model);

  gmcmc_ode_model_set_tolerances(ode_model, 1.0e-08, 1.0e-08);


  /*
   * Create a parallel random number generator to use
   */
  gmcmc_prng64 * rng;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_dcmt607, rank)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_ode_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    gmcmc_ode_model_destroy(ode_model);
    fputs("Unable to create parallel RNG\n", stderr);
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
  error = gmcmc_popmcmc_mpi(model, dataset, gmcmc_ode_likelihood_simp_mmala, gmcmc_proposal_simp_mmala, &mcmc_options, rng);

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
  gmcmc_ode_dataset_destroy(dataset);
  gmcmc_model_destroy(model);
  gmcmc_ode_model_destroy(ode_model);
  gmcmc_prng64_destroy(rng);

  MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");

  return error;
}

/**
 * Function to evaluate the right-hand side of a system of ODEs.
 *
 * @param [in]  t       the current timepoint
 * @param [in]  y       current values of the time-dependent variables
 * @param [out] yout    values of the time-dependent variables at time t
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
static int vyshemirsky_2008(double t, const double * y, double * ydot, const double * params) {
  (void)t;      // Unused

  // Model parameters
  double k1 = params[0];
  double k2 = params[1];
  double k3 = params[2];
  double k4 = params[3];
  double k5 = params[4];
  double k6 = params[5];
  double k7 = params[6];

  // Model states
  double S      = y[0];
//   double dS     = y[1];
  double R      = y[2];
  double RS     = y[3];
  double Rpp    = y[4];
  double PhA    = y[5];
  double RppPhA = y[6];

  // d/dt(S)      = -k1*S - k2*S*R + k3*RS
  ydot[0] = -k1*S - k2*S*R + k3*RS;

  // d/dt(dS)     = k1*S
  ydot[1] = k1*S;

  // d/dt(R)      = -k2*S*R + k3*RS + k7*RppPhA
  ydot[2] = -k2*S*R + k3*RS + k7*RppPhA;

  // d/dt(RS)     = k2*S*R - k3*RS - k4*RS
  ydot[3] = k2*S*R - k3*RS - k4*RS;

  // d/dt(Rpp)    = k4*RS - k5*Rpp*PhA + k6*RppPhA
  ydot[4] = k4*RS - k5*Rpp*PhA + k6*RppPhA;

  // d/dt(PhA)    = -k5*Rpp*PhA + k6*RppPhA + k7*RppPhA
  ydot[5] = -k5*Rpp*PhA + k6*RppPhA + k7*RppPhA;

  // d/dt(RppPhA) = k5*Rpp*PhA - k6*RppPhA - k7*RppPhA
  ydot[6] = k5*Rpp*PhA - k6*RppPhA - k7*RppPhA;

  return 0;
}
