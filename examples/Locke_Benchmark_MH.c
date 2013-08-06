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
static int locke_2005a(double, const double *, double *, const double *);

int main(int argc, char * argv[]) {
  // Since we are using MPI for parallel processing initialise it here before
  // parsing the arguments for our program
  MPI_ERROR_CHECK(MPI_Init(&argc, &argv), "Failed to initialise MPI");

  // Default dataset file
  const char * data_file = "data/Locke_Benchmark_Data.mat";

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
  mcmc_options.num_burn_in_samples   =  5000;
  mcmc_options.num_posterior_samples = 20000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate            =  50;
  mcmc_options.upper_acceptance_rate =   0.5;
  mcmc_options.lower_acceptance_rate =   0.2;

  // Callbacks
  mcmc_options.acceptance = acceptance_monitor;
  mcmc_options.write = gmcmc_matlab_popmcmc_write;

  int error;

  /*
   * Common model settings
   */
#ifdef INFER_ICS
  const unsigned int num_params = 28;    // Parameters and initial conditions
#else
  const unsigned int num_params = 22;    // Just parameters
#endif

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL) {
    fputs("Failed to allocate space for priors\n", stderr);
    free(temperatures);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -2;
  }

  for (unsigned int i = 0; i < 22; i++) {
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
  // Prior for IC 1
  if ((error = gmcmc_distribution_create_uniform(&priors[22], 0.0, 0.5)) != 0) {
      // Clean up
    for (unsigned int j = 0; j < 22; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }

  // Prior for IC 2
  if ((error = gmcmc_distribution_create_uniform(&priors[23], 11.0, 16.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 23; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }

  // Prior for IC 3
  if ((error = gmcmc_distribution_create_uniform(&priors[24], 7.0, 12.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 24; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }

  // Prior for IC 4
  if ((error = gmcmc_distribution_create_uniform(&priors[25], 0.0, 4.0)) != 0) {
      // Clean up
    for (unsigned int j = 0; j < 25; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }

  // Prior for IC 5
  if ((error = gmcmc_distribution_create_uniform(&priors[26], 4.0, 8.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 26; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
  }

  // Prior for IC 6
  if ((error = gmcmc_distribution_create_uniform(&priors[27], 0.0, 3.0)) != 0) {
    // Clean up
    for (unsigned int j = 0; j < 27; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    free(temperatures);
    fputs("Unable to create priors\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -3;
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
  if ((error = gmcmc_model_create(&model, num_params, priors, gmcmc_ode_proposal_mh, gmcmc_ode_likelihood_mh)) != 0) {
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
  // Parameters and initial conditions
  double params[] = {  3.7051,  9.7142,  7.8618,  3.2829,  6.3907,  1.0631,  0.9271,
                       5.0376,  7.3892,  0.4716,  4.1307,  5.7775,  4.4555,  7.6121,
                       0.6187,  7.7768,  9.0002,  3.6414,  5.6429,  8.2453,  1.2789,
                       5.3527,  0.1290, 13.6937,  9.1584,  1.9919,  5.9266,  1.1007 };
#else
  // Just parameters
  double params[] = {  3.7051,  9.7142,  7.8618,  3.2829,  6.3907,  1.0631,  0.9271,
                       5.0376,  7.3892,  0.4716,  4.1307,  5.7775,  4.4555,  7.6121,
                       0.6187,  7.7768,  9.0002,  3.6414,  5.6429,  8.2453,  1.2789,
                       5.3527 };
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
  if ((error = gmcmc_ode_model_create(&ode_model, 6, 0, locke_2005a)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to create ODE specific model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -6;
  }

#ifndef INFER_ICS
  double ics[] = {0.1290, 13.6937,  9.1584,  1.9919,  5.9266,  1.1007 };
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
static int locke_2005a(double t, const double * y, double * ydot, const double * params) {
  (void)t;      // Unused

  // Model variables
  const double a = 1;
  const double b = 2;

  // Model parameters
  double g1 = params[ 0];
  double g2 = params[ 1];

  double k1 = params[ 2];
  double k2 = params[ 3];
  double k3 = params[ 4];
  double k4 = params[ 5];
  double k5 = params[ 6];
  double k6 = params[ 7];

  double m1 = params[ 8];
  double m2 = params[ 9];
  double m3 = params[10];
  double m4 = params[11];
  double m5 = params[12];
  double m6 = params[13];

  double n1 = params[14];
  double n2 = params[15];

  double p1 = params[16];
  double p2 = params[17];

  double r1 = params[18];
  double r2 = params[19];
  double r3 = params[20];
  double r4 = params[21];

  // Model states
  double LHYm  = y[0];
  double LHYc  = y[1];
  double LHYn  = y[2];
  double TOC1m = y[3];
  double TOC1c = y[4];
  double TOC1n = y[5];

  // d/dt(LHYm) = (n1*TOC1n^a)/(g1^a + TOC1n^a) - (m1*LHYm)/(k1 + LHYm)
  ydot[0] = (n1 * pow(TOC1n, a)) / (pow(g1, a) + pow(TOC1n, a)) - (m1 * LHYm) / (k1 + LHYm);

  // d/dt(LHYc) = p1*LHYm - r1*LHYc + r2*LHYn - (m2*LHYc)/(k2 + LHYc)
  ydot[1] = p1 * LHYm - r1 * LHYc + r2 * LHYn - (m2 * LHYc) / (k2 + LHYc);

  // d/dt(LHYn) = r1*LHYc - r2*LHYn - (m3*LHYn)/(k3 + LHYn)
  ydot[2] = r1 * LHYc - r2 * LHYn - (m3 * LHYn) / (k3 + LHYn);

  // d/dt(TOC1m) = (n2*g2^b)/(g2^b + LHYn^b) - (m4*TOC1m)/(k4 + TOC1m)
  ydot[3] = (n2 * pow(g2, b)) / (pow(g2, b) + pow(LHYn, b)) - (m4 * TOC1m) / (k4 + TOC1m);

  // d/dt(TOC1c) = p2*TOC1m - r3*TOC1c + r4*TOC1n - (m5*TOC1c)/(k5 + TOC1c)
  ydot[4] = p2 * TOC1m - r3 * TOC1c + r4 * TOC1n - (m5 * TOC1c) / (k5 + TOC1c);

  // d/dt(TOC1n) = r3*TOC1c - r4*TOC1n - (m6*TOC1n)/(k6 + TOC1n)
  ydot[5] = r3 * TOC1c - r4 * TOC1n - (m6 * TOC1n) / (k6 + TOC1n);

  return 0;
}
