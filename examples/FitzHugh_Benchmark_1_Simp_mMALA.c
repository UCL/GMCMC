#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <getopt.h>

#include <mpi.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_ode_model.h>
#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_popmcmc.h>

#include <gmcmc/gmcmc_matlab.h>

#include "acceptance.h"

// Whether to use log space for parameter values - helps with very small/large values
// #define LOG10SPACE

// Whether to use log space for initial conditions - helps with very small/large values
// #define LOG10SPACE_ICS

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
static int fitzhughnagumo(double, const double *, double *, const double *);

int main(int argc, char * argv[]) {
  // Since we are using MPI for parallel processing initialise it here before
  // parsing the arguments for our program
  MPI_ERROR_CHECK(MPI_Init(&argc, &argv), "Failed to initialise MPI");

  // Default dataset file
  const char * data_file = "data/FitzHugh_Benchmark_Data.mat";

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
  gmcmc_matlab_outputID = argv[optind];


  // How often to save posterior samples.
  gmcmc_matlab_posterior_save_size = 20000;

  // Handle MPI errors ourselves
  MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

  /*
   * Set up MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set number of tempered distributions to use
  mcmc_options.num_temperatures = 10;

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
  mcmc_options.num_burn_in_samples   =  5000;
  mcmc_options.num_posterior_samples = 20000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate      =  50;
  mcmc_options.upper_step_size =   0.7;
  mcmc_options.lower_step_size =   0.4;

  // Callbacks
  mcmc_options.acceptance = acceptance_monitor;
  mcmc_options.write = gmcmc_matlab_popmcmc_write;

  int error;

  /*
   * Common model settings
   */
#ifdef INFER_ICS
  const unsigned int num_params = 5;    // Parameters and initial conditions
#else
  const unsigned int num_params = 3;    // Just parameters
#endif

  // Set up priors for each of the parameters (and initial conditions)
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL) {
    fputs("Failed to allocate space for priors\n", stderr);
    free(temperatures);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }

#ifdef LOG10SPACE
  // Set up priors for log space
  for (unsigned int i = 0; i < 3; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], -2.0, 2.0)) != 0) {
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
  for (unsigned int i = 0; i < 3; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
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

#ifdef INFER_ICS
#ifdef LOG10SPACE_ICS
  // Set up priors for log space
  for (unsigned int i = 3; i < 5; i++) {
    if ((error = gmcmc_distribution_create_normal(&priors[i], 0.0, 1.0)) != 0) {
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
  for (unsigned int i = 3; i < 5; i++) {
    if ((error = gmcmc_distribution_create_normal(&priors[i], 0.0, 2.0)) != 0) {
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
#endif

  // Load the dataset
  gmcmc_dataset * dataset;
  if ((error = gmcmc_dataset_create_matlab_ode(&dataset, data_file)) != 0) {
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
  if ((error = gmcmc_model_create(&model, num_params, priors, gmcmc_ode_proposal_simp_mmala_trunc, gmcmc_ode_likelihood_simp_mmala)) != 0) {
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

  // Priors have been copied into model so don't need them any more
  for (unsigned int i = 0; i < num_params; i++)
    gmcmc_distribution_destroy(priors[i]);
  free(priors);

  // Set up starting values for all temperatures
#ifdef INFER_ICS
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
#else
  double params[] = { 0.2, 0.2, 3.0 };
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
  gmcmc_model_set_stepsize(model, 0.05);

  /*
   * ODE model settings
   */
  gmcmc_ode_model * ode_model;
  if ((error = gmcmc_ode_model_create(&ode_model, 2, 0, fitzhughnagumo)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to create ODE specific model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -6;
  }

#ifndef INFER_ICS
  double ics[] = { -1.0, 1.0 };
  gmcmc_ode_model_set_initial_conditions(ode_model, ics);
#endif

  gmcmc_model_set_modelspecific(model, ode_model);

  gmcmc_ode_model_set_tolerances(ode_model, 1.0e-08, 1.0e-08);


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
    gmcmc_ode_model_destroy(ode_model);
    fputs("Unable to create parallel RNG\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -5;
  }

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3241);

  /*
   * Call main population MCMC routine using MPI
   */
  error = gmcmc_popmcmc_mpi(&mcmc_options, model, dataset, rng);

  // Clean up (dataset, model, rng)
  free(temperatures);
  gmcmc_dataset_destroy(dataset);
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
static int fitzhughnagumo(double t, const double * y, double * ydot, const double * params) {
  (void)t;      // Unused

  // Reparameterise if necessary
#ifdef LOG10SPACE
  double a = pow(10.0, params[0]);
  double b = pow(10.0, params[1]);
  double c = pow(10.0, params[2]);
#else
  double a = params[0];
  double b = params[1];
  double c = params[2];
#endif

#ifdef LOG10SPACE_ICS
  double v = pow(10.0, y[0]);
  double r = pow(10.0, y[1]);
#else
  double v = y[0];
  double r = y[1];
#endif

  // d/dt(V) = c*(V-(V^3)/3+R)
  double vt = c * (v - ((v*v*v) / 3.0) + r);

  // d/dt(R) = -(V-a+b*R)/c
  double rt = -(v - a + b * r) / c;

#ifdef LOG10SPACE_ICS
  ydot[0] = log10(vt);
  ydot[1] = log10(rt);
#else
  ydot[0] = vt;
  ydot[1] = rt;
#endif

  return 0;
}
