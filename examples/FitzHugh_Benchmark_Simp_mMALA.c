#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <getopt.h>
#include <time.h>

#include <sys/time.h>

#include <mpi.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_ode_model.h>
#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_popmcmc.h>

#include <gmcmc/gmcmc_matlab.h>

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

/**
 * Function to evaluate the right-hand side of the Fitz Hugh Nagumo model.
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

/**
 * Function to evaluate the sensitivities right-hand side of the Fitz Hugh
 * Nagumo model.
 *
 * @param [in]  t      is the current value of the independent variable
 * @param [in]  y      is the current value of the state vector, y(t)
 * @param [in]  ydot   is the current value of the right-hand side of the state
 *                      equations
 * @param [in]  yS     contains the current values of the sensitivity vectors
 * @param [out] ySdot  is the output of CVSensRhsFn. On exit it must contain the
 *                       sensitivity right-hand side vectors
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
static int fitzhughnagumo_sens(double, const double *, const double *,
                               const double **, double **, const double *);

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
  const char * data_file = "data/FitzHugh_Benchmark_Data_1000.mat";

  /*
   * Set up default MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set number of tempered distributions to use
  mcmc_options.num_temperatures = 10;

  // Set number of burn-in and posterior samples
  mcmc_options.num_burn_in_samples   =  5000;
  mcmc_options.num_posterior_samples = 20000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate            =  50;
  mcmc_options.upper_acceptance_rate =   0.7;
  mcmc_options.lower_acceptance_rate =   0.4;

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
  gmcmc_matlab_save_size = 12500000 / mcmc_options.num_temperatures;  // Results in ~1GB files for this model

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
  const unsigned int num_params = 5;    // Parameters and initial conditions
#else
  const unsigned int num_params = 3;    // Just parameters
#endif

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL) {
    fputs("Failed to allocate space for priors\n", stderr);
    free(temperatures);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }

  for (unsigned int i = 0; i < 3; i++) {
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
  // Set up priors for initial conditions
  for (unsigned int i = 3; i < 5; i++) {
    if ((error = gmcmc_distribution_create_normal(&priors[i], 0.0, 2.0)) != 0) {
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

  gmcmc_ode_model_set_rhs_sens(ode_model, fitzhughnagumo_sens);

  gmcmc_ode_model_set_tolerances(ode_model, 1.0e-08, 1.0e-08);


  /*
   * Create a parallel random number generator to use
   */
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

  // Model parameters
  double a = params[0];
  double b = params[1];
  double c = params[2];

  // Model states
  double v = y[0];
  double r = y[1];

  // d/dt(V) = c*(V-(V^3)/3+R)
  ydot[0] = c * (v - ((v*v*v) / 3.0) + r);

  // d/dt(R) = -(V-a+b*R)/c
  ydot[1] = -(v - a + b * r) / c;

  return 0;
}

/**
 * Function to evaluate the sensitivities right-hand side of the Fitz Hugh
 * Nagumo model.
 *
 * @param [in]  t      is the current value of the independent variable
 * @param [in]  y      is the current value of the state vector, y(t)
 * @param [in]  ydot   is the current value of the right-hand side of the state
 *                      equations
 * @param [in]  yS     contains the current values of the sensitivity vectors
 * @param [out] ySdot  is the output of CVSensRhsFn. On exit it must contain the
 *                       sensitivity right-hand side vectors
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
static int fitzhughnagumo_sens(double t, const double * y, const double * ydot,
                               const double ** yS, double ** ySdot, const double * params) {
  (void)t;      // Unused
  (void)ydot;

  // Model parameters
  double a = params[0];
  double b = params[1];
  double c = params[2];

  // Model states
  double v = y[0];
  double r = y[1];
  double v_a = yS[0][0];
  double r_a = yS[0][1];
  double v_b = yS[1][0];
  double r_b = yS[1][1];
  double v_c = yS[2][0];
  double r_c = yS[2][1];
#ifdef INFER_ICS
  double v_v0 = yS[3][0];
  double r_v0 = yS[3][1];
  double v_r0 = yS[4][0];
  double r_r0 = yS[4][1];
#endif

  // d/dt(V_a) = (-c*(V^2 - 1))*V_a + (c)*R_a
  ySdot[0][0] = (-c * (v*v - 1.0)) * v_a + c * r_a;

  // d/dt(R_a) = (-1/c)*V_a + (-b/c)*R_a + 1/c
  ySdot[0][1] = (-1.0 / c) * v_a + (-b / c) * r_a + 1.0 / c;

  // d/dt(V_b) = (-c*(V^2 - 1))*V_b + (c)*R_b
  ySdot[1][0] = (-c * (v*v - 1.0)) * v_b + c * r_b;

  // d/dt(R_b) = (-1/c)*V_b + (-b/c)*R_b - R/c
  ySdot[1][1] = (-1.0 / c) * v_b + (-b / c) * r_b - r / c;

  // d/dt(V_c) = (-c*(V^2 - 1))*V_c + (c)*R_c + V - V^3/3 + R
  ySdot[2][0] = (-c * (v*v - 1.0)) * v_c + c * r_c + v - (v*v*v) / 3.0 + r;

  // d/dt(R_c) = (-1/c)*V_c + (-b/c)*R_c + (V - a + R*b)/c^2
  ySdot[2][1] = (-1.0 / c) * v_c + (-b / c) * r_c + (v - a + r * b) / (c*c);

#ifdef INFER_ICS
  // d/dt(V_V0) = (-c*(V^2 - 1))*V_V0 + (c)*R_V0
  ySdot[3][0] = (-c * (v*v - 1.0)) * v_v0 + c * r_v0;

  // d/dt(R_V0) = (-1/c)*V_V0 + (-b/c)*R_V0
  ySdot[3][1] = (-1.0 / c) * v_v0 + (-b / c) * r_v0;

  // d/dt(V_R0) = (-c*(V^2 - 1))*V_R0 + (c)*R_R0
  ySdot[4][0] = (-c * (v*v - 1.0)) * v_r0 + c * r_r0;

  // d/dt(R_R0) = (-1/c)*V_R0 + (-b/c)*R_R0
  ySdot[4][1] = (-1.0 / c) * v_r0 + (-b / c) * r_r0;
#endif

  return 0;
}
