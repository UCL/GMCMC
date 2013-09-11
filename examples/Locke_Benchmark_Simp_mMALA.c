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
 * Function to evaluate the right-hand side of the Locke 2005a model.
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

/**
 * Function to evaluate the sensitivities right-hand side of the Locke 2005a
 * model.
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
static int locke_2005a_sens(double, const double *, const double *,
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
  const char * data_file = "data/Locke_Benchmark_Data.mat";

  /*
   * Set up default MCMC options
   */
  gmcmc_popmcmc_options mcmc_options;

  // Set number of tempered distributions to use
  mcmc_options.num_temperatures = 20;

  // Set number of burn-in and posterior samples
  mcmc_options.num_burn_in_samples   =  5000;
  mcmc_options.num_posterior_samples = 20000;

  // Set iteration interval for adapting stepsizes
  mcmc_options.adapt_rate            =  50;
  mcmc_options.upper_acceptance_rate =   0.7;
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


  // How often to save posterior samples.
  gmcmc_matlab_save_size = 2000000 / mcmc_options.num_temperatures;  // Results in ~1GB files for this model

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
// #ifdef INFER_ICS
//   // Parameters and initial conditions
//   double params[] = {  3.7051,  9.7142,  7.8618,  3.2829,  6.3907,  1.0631,  0.9271,
//                        5.0376,  7.3892,  0.4716,  4.1307,  5.7775,  4.4555,  7.6121,
//                        0.6187,  7.7768,  9.0002,  3.6414,  5.6429,  8.2453,  1.2789,
//                        5.3527,  0.1290, 13.6937,  9.1584,  1.9919,  5.9266,  1.1007 };
// #else
//   // Just parameters
//   double params[] = {  3.7051,  9.7142,  7.8618,  3.2829,  6.3907,  1.0631,  0.9271,
//                        5.0376,  7.3892,  0.4716,  4.1307,  5.7775,  4.4555,  7.6121,
//                        0.6187,  7.7768,  9.0002,  3.6414,  5.6429,  8.2453,  1.2789,
//                        5.3527 };
// #endif
//   if ((error = gmcmc_model_set_params(model, params)) != 0) {
//     // Clean up
//     free(temperatures);
//     gmcmc_dataset_destroy(dataset);
//     gmcmc_model_destroy(model);
//     fputs("Unable to set initial parameter values\n", stderr);
//     MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
//     return -5;
//   }

  // Set initial step size and upper and lower bounds
  gmcmc_model_set_stepsize(model, 0.05);
  gmcmc_model_set_stepsize_bounds(model, 1.0e-06, 1.0e+05);

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

//   gmcmc_ode_model_set_rhs_sens(ode_model, locke_2005a_sens);

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
  if (rank == 0)
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
static int locke_2005a_sens(double t, const double * y, const double * ydot,
                            const double ** yS, double ** ySdot, const double * params) {
  (void)t;      // Unused
  (void)ydot;

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

  double LHYm_g1  = yS[ 0][0];
  double LHYc_g1  = yS[ 0][1];
  double LHYn_g1  = yS[ 0][2];
  double TOC1m_g1 = yS[ 0][3];
  double TOC1c_g1 = yS[ 0][4];
  double TOC1n_g1 = yS[ 0][5];
  double LHYm_g2  = yS[ 1][0];
  double LHYc_g2  = yS[ 1][1];
  double LHYn_g2  = yS[ 1][2];
  double TOC1m_g2 = yS[ 1][3];
  double TOC1c_g2 = yS[ 1][4];
  double TOC1n_g2 = yS[ 1][5];

  double LHYm_k1  = yS[ 2][0];
  double LHYc_k1  = yS[ 2][1];
  double LHYn_k1  = yS[ 2][2];
  double TOC1m_k1 = yS[ 2][3];
  double TOC1c_k1 = yS[ 2][4];
  double TOC1n_k1 = yS[ 2][5];
  double LHYm_k2  = yS[ 3][0];
  double LHYc_k2  = yS[ 3][1];
  double LHYn_k2  = yS[ 3][2];
  double TOC1m_k2 = yS[ 3][3];
  double TOC1c_k2 = yS[ 3][4];
  double TOC1n_k2 = yS[ 3][5];
  double LHYm_k3  = yS[ 4][0];
  double LHYc_k3  = yS[ 4][1];
  double LHYn_k3  = yS[ 4][2];
  double TOC1m_k3 = yS[ 4][3];
  double TOC1c_k3 = yS[ 4][4];
  double TOC1n_k3 = yS[ 4][5];
  double LHYm_k4  = yS[ 5][0];
  double LHYc_k4  = yS[ 5][1];
  double LHYn_k4  = yS[ 5][2];
  double TOC1m_k4 = yS[ 5][3];
  double TOC1c_k4 = yS[ 5][4];
  double TOC1n_k4 = yS[ 5][5];
  double LHYm_k5  = yS[ 6][0];
  double LHYc_k5  = yS[ 6][1];
  double LHYn_k5  = yS[ 6][2];
  double TOC1m_k5 = yS[ 6][3];
  double TOC1c_k5 = yS[ 6][4];
  double TOC1n_k5 = yS[ 6][5];
  double LHYm_k6  = yS[ 7][0];
  double LHYc_k6  = yS[ 7][1];
  double LHYn_k6  = yS[ 7][2];
  double TOC1m_k6 = yS[ 7][3];
  double TOC1c_k6 = yS[ 7][4];
  double TOC1n_k6 = yS[ 7][5];

  double LHYm_m1  = yS[ 8][0];
  double LHYc_m1  = yS[ 8][1];
  double LHYn_m1  = yS[ 8][2];
  double TOC1m_m1 = yS[ 8][3];
  double TOC1c_m1 = yS[ 8][4];
  double TOC1n_m1 = yS[ 8][5];
  double LHYm_m2  = yS[ 9][0];
  double LHYc_m2  = yS[ 9][1];
  double LHYn_m2  = yS[ 9][2];
  double TOC1m_m2 = yS[ 9][3];
  double TOC1c_m2 = yS[ 9][4];
  double TOC1n_m2 = yS[ 9][5];
  double LHYm_m3  = yS[10][0];
  double LHYc_m3  = yS[10][1];
  double LHYn_m3  = yS[10][2];
  double TOC1m_m3 = yS[10][3];
  double TOC1c_m3 = yS[10][4];
  double TOC1n_m3 = yS[10][5];
  double LHYm_m4  = yS[11][0];
  double LHYc_m4  = yS[11][1];
  double LHYn_m4  = yS[11][2];
  double TOC1m_m4 = yS[11][3];
  double TOC1c_m4 = yS[11][4];
  double TOC1n_m4 = yS[11][5];
  double LHYm_m5  = yS[12][0];
  double LHYc_m5  = yS[12][1];
  double LHYn_m5  = yS[12][2];
  double TOC1m_m5 = yS[12][3];
  double TOC1c_m5 = yS[12][4];
  double TOC1n_m5 = yS[12][5];
  double LHYm_m6  = yS[13][0];
  double LHYc_m6  = yS[13][1];
  double LHYn_m6  = yS[13][2];
  double TOC1m_m6 = yS[13][3];
  double TOC1c_m6 = yS[13][4];
  double TOC1n_m6 = yS[13][5];

  double LHYm_n1  = yS[14][0];
  double LHYc_n1  = yS[14][1];
  double LHYn_n1  = yS[14][2];
  double TOC1m_n1 = yS[14][3];
  double TOC1c_n1 = yS[14][4];
  double TOC1n_n1 = yS[14][5];
  double LHYm_n2  = yS[15][0];
  double LHYc_n2  = yS[15][1];
  double LHYn_n2  = yS[15][2];
  double TOC1m_n2 = yS[15][3];
  double TOC1c_n2 = yS[15][4];
  double TOC1n_n2 = yS[15][5];

  double LHYm_p1  = yS[16][0];
  double LHYc_p1  = yS[16][1];
  double LHYn_p1  = yS[16][2];
  double TOC1m_p1 = yS[16][3];
  double TOC1c_p1 = yS[16][4];
  double TOC1n_p1 = yS[16][5];
  double LHYm_p2  = yS[17][0];
  double LHYc_p2  = yS[17][1];
  double LHYn_p2  = yS[17][2];
  double TOC1m_p2 = yS[17][3];
  double TOC1c_p2 = yS[17][4];
  double TOC1n_p2 = yS[17][5];

  double LHYm_r1  = yS[18][0];
  double LHYc_r1  = yS[18][1];
  double LHYn_r1  = yS[18][2];
  double TOC1m_r1 = yS[18][3];
  double TOC1c_r1 = yS[18][4];
  double TOC1n_r1 = yS[18][5];
  double LHYm_r2  = yS[19][0];
  double LHYc_r2  = yS[19][1];
  double LHYn_r2  = yS[19][2];
  double TOC1m_r2 = yS[19][3];
  double TOC1c_r2 = yS[19][4];
  double TOC1n_r2 = yS[19][5];
  double LHYm_r3  = yS[20][0];
  double LHYc_r3  = yS[20][1];
  double LHYn_r3  = yS[20][2];
  double TOC1m_r3 = yS[20][3];
  double TOC1c_r3 = yS[20][4];
  double TOC1n_r3 = yS[20][5];
  double LHYm_r4  = yS[21][0];
  double LHYc_r4  = yS[21][1];
  double LHYn_r4  = yS[21][2];
  double TOC1m_r4 = yS[21][3];
  double TOC1c_r4 = yS[21][4];
  double TOC1n_r4 = yS[21][5];

#ifdef INFER_ICS
  double LHYm_LHYm0   = yS[22][0];
  double LHYc_LHYm0   = yS[22][1];
  double LHYn_LHYm0   = yS[22][2];
  double TOC1m_LHYm0  = yS[22][3];
  double TOC1c_LHYm0  = yS[22][4];
  double TOC1n_LHYm0  = yS[22][5];

  double LHYm_LHYc0   = yS[23][0];
  double LHYc_LHYc0   = yS[23][1];
  double LHYn_LHYc0   = yS[23][2];
  double TOC1m_LHYc0  = yS[23][3];
  double TOC1c_LHYc0  = yS[23][4];
  double TOC1n_LHYc0  = yS[23][5];

  double LHYm_LHYn0   = yS[24][0];
  double LHYc_LHYn0   = yS[24][1];
  double LHYn_LHYn0   = yS[24][2];
  double TOC1m_LHYn0  = yS[24][3];
  double TOC1c_LHYn0  = yS[24][4];
  double TOC1n_LHYn0  = yS[24][5];

  double LHYm_TOC1m0  = yS[25][0];
  double LHYc_TOC1m0  = yS[25][1];
  double LHYn_TOC1m0  = yS[25][2];
  double TOC1m_TOC1m0 = yS[25][3];
  double TOC1c_TOC1m0 = yS[25][4];
  double TOC1n_TOC1m0 = yS[25][5];

  double LHYm_TOC1c0  = yS[26][0];
  double LHYc_TOC1c0  = yS[26][1];
  double LHYn_TOC1c0  = yS[26][2];
  double TOC1m_TOC1c0 = yS[26][3];
  double TOC1c_TOC1c0 = yS[26][4];
  double TOC1n_TOC1c0 = yS[26][5];

  double LHYm_TOC1n0  = yS[27][0];
  double LHYc_TOC1n0  = yS[27][1];
  double LHYn_TOC1n0  = yS[27][2];
  double TOC1m_TOC1n0 = yS[27][3];
  double TOC1c_TOC1n0 = yS[27][4];
  double TOC1n_TOC1n0 = yS[27][5];
#endif
  // i=-1; j=0; grep "DDTvector\[" SBLocke2005_1st_Paras_ICs.c | cut -d'=' -f2 | while read eq; do echo "ySdot[$i][$j] = ${eq}"; let j=j+1; if [ $[$j % 6] -eq 0 ]; then let i=i+1; j=0; fi; done
  ySdot[ 0][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_g1+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_g1+(-(pow(TOC1n,a)*a*pow(g1,a-1.0)*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0));
  ySdot[ 0][1] = (p1)*LHYm_g1+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_g1+(r2)*LHYn_g1;
  ySdot[ 0][2] = (r1)*LHYc_g1+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_g1;
  ySdot[ 0][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_g1+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_g1;
  ySdot[ 0][4] = (p2)*TOC1m_g1+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_g1+(r4)*TOC1n_g1;
  ySdot[ 0][5] = (r3)*TOC1c_g1+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_g1;
  ySdot[ 1][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_g2+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_g2;
  ySdot[ 1][1] = (p1)*LHYm_g2+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_g2+(r2)*LHYn_g2;
  ySdot[ 1][2] = (r1)*LHYc_g2+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_g2;
  ySdot[ 1][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_g2+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_g2+((b*pow(g2,b-1.0)*n2)/(pow(LHYn,b)+pow(g2,b))-(b*pow(g2,b)*pow(g2,b-1.0)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0));
  ySdot[ 1][4] = (p2)*TOC1m_g2+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_g2+(r4)*TOC1n_g2;
  ySdot[ 1][5] = (r3)*TOC1c_g2+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_g2;
  ySdot[ 2][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_k1+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_k1+((LHYm*m1)/pow(LHYm+k1,2.0));
  ySdot[ 2][1] = (p1)*LHYm_k1+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_k1+(r2)*LHYn_k1;
  ySdot[ 2][2] = (r1)*LHYc_k1+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_k1;
  ySdot[ 2][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_k1+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_k1;
  ySdot[ 2][4] = (p2)*TOC1m_k1+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_k1+(r4)*TOC1n_k1;
  ySdot[ 2][5] = (r3)*TOC1c_k1+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_k1;
  ySdot[ 3][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_k2+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_k2;
  ySdot[ 3][1] = (p1)*LHYm_k2+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_k2+(r2)*LHYn_k2+((LHYc*m2)/pow(LHYc+k2,2.0));
  ySdot[ 3][2] = (r1)*LHYc_k2+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_k2;
  ySdot[ 3][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_k2+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_k2;
  ySdot[ 3][4] = (p2)*TOC1m_k2+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_k2+(r4)*TOC1n_k2;
  ySdot[ 3][5] = (r3)*TOC1c_k2+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_k2;
  ySdot[ 4][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_k3+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_k3;
  ySdot[ 4][1] = (p1)*LHYm_k3+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_k3+(r2)*LHYn_k3;
  ySdot[ 4][2] = (r1)*LHYc_k3+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_k3+((LHYn*m3)/pow(LHYn+k3,2.0));
  ySdot[ 4][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_k3+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_k3;
  ySdot[ 4][4] = (p2)*TOC1m_k3+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_k3+(r4)*TOC1n_k3;
  ySdot[ 4][5] = (r3)*TOC1c_k3+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_k3;
  ySdot[ 5][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_k4+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_k4;
  ySdot[ 5][1] = (p1)*LHYm_k4+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_k4+(r2)*LHYn_k4;
  ySdot[ 5][2] = (r1)*LHYc_k4+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_k4;
  ySdot[ 5][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_k4+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_k4+((TOC1m*m4)/pow(TOC1m+k4,2.0));
  ySdot[ 5][4] = (p2)*TOC1m_k4+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_k4+(r4)*TOC1n_k4;
  ySdot[ 5][5] = (r3)*TOC1c_k4+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_k4;
  ySdot[ 6][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_k5+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_k5;
  ySdot[ 6][1] = (p1)*LHYm_k5+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_k5+(r2)*LHYn_k5;
  ySdot[ 6][2] = (r1)*LHYc_k5+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_k5;
  ySdot[ 6][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_k5+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_k5;
  ySdot[ 6][4] = (p2)*TOC1m_k5+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_k5+(r4)*TOC1n_k5+((TOC1c*m5)/pow(TOC1c+k5,2.0));
  ySdot[ 6][5] = (r3)*TOC1c_k5+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_k5;
  ySdot[ 7][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_k6+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_k6;
  ySdot[ 7][1] = (p1)*LHYm_k6+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_k6+(r2)*LHYn_k6;
  ySdot[ 7][2] = (r1)*LHYc_k6+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_k6;
  ySdot[ 7][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_k6+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_k6;
  ySdot[ 7][4] = (p2)*TOC1m_k6+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_k6+(r4)*TOC1n_k6;
  ySdot[ 7][5] = (r3)*TOC1c_k6+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_k6+((TOC1n*m6)/pow(TOC1n+k6,2.0));
  ySdot[ 8][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_m1+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_m1+(-LHYm/(LHYm+k1));
  ySdot[ 8][1] = (p1)*LHYm_m1+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_m1+(r2)*LHYn_m1;
  ySdot[ 8][2] = (r1)*LHYc_m1+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_m1;
  ySdot[ 8][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_m1+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_m1;
  ySdot[ 8][4] = (p2)*TOC1m_m1+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_m1+(r4)*TOC1n_m1;
  ySdot[ 8][5] = (r3)*TOC1c_m1+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_m1;
  ySdot[ 9][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_m2+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_m2;
  ySdot[ 9][1] = (p1)*LHYm_m2+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_m2+(r2)*LHYn_m2+(-LHYc/(LHYc+k2));
  ySdot[ 9][2] = (r1)*LHYc_m2+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_m2;
  ySdot[ 9][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_m2+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_m2;
  ySdot[ 9][4] = (p2)*TOC1m_m2+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_m2+(r4)*TOC1n_m2;
  ySdot[ 9][5] = (r3)*TOC1c_m2+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_m2;
  ySdot[10][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_m3+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_m3;
  ySdot[10][1] = (p1)*LHYm_m3+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_m3+(r2)*LHYn_m3;
  ySdot[10][2] = (r1)*LHYc_m3+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_m3+(-LHYn/(LHYn+k3));
  ySdot[10][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_m3+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_m3;
  ySdot[10][4] = (p2)*TOC1m_m3+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_m3+(r4)*TOC1n_m3;
  ySdot[10][5] = (r3)*TOC1c_m3+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_m3;
  ySdot[11][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_m4+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_m4;
  ySdot[11][1] = (p1)*LHYm_m4+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_m4+(r2)*LHYn_m4;
  ySdot[11][2] = (r1)*LHYc_m4+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_m4;
  ySdot[11][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_m4+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_m4+(-TOC1m/(TOC1m+k4));
  ySdot[11][4] = (p2)*TOC1m_m4+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_m4+(r4)*TOC1n_m4;
  ySdot[11][5] = (r3)*TOC1c_m4+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_m4;
  ySdot[12][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_m5+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_m5;
  ySdot[12][1] = (p1)*LHYm_m5+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_m5+(r2)*LHYn_m5;
  ySdot[12][2] = (r1)*LHYc_m5+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_m5;
  ySdot[12][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_m5+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_m5;
  ySdot[12][4] = (p2)*TOC1m_m5+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_m5+(r4)*TOC1n_m5+(-TOC1c/(TOC1c+k5));
  ySdot[12][5] = (r3)*TOC1c_m5+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_m5;
  ySdot[13][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_m6+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_m6;
  ySdot[13][1] = (p1)*LHYm_m6+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_m6+(r2)*LHYn_m6;
  ySdot[13][2] = (r1)*LHYc_m6+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_m6;
  ySdot[13][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_m6+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_m6;
  ySdot[13][4] = (p2)*TOC1m_m6+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_m6+(r4)*TOC1n_m6;
  ySdot[13][5] = (r3)*TOC1c_m6+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_m6+(-TOC1n/(TOC1n+k6));
  ySdot[14][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_n1+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_n1+(pow(TOC1n,a)/(pow(TOC1n,a)+pow(g1,a)));
  ySdot[14][1] = (p1)*LHYm_n1+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_n1+(r2)*LHYn_n1;
  ySdot[14][2] = (r1)*LHYc_n1+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_n1;
  ySdot[14][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_n1+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_n1;
  ySdot[14][4] = (p2)*TOC1m_n1+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_n1+(r4)*TOC1n_n1;
  ySdot[14][5] = (r3)*TOC1c_n1+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_n1;
  ySdot[15][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_n2+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_n2;
  ySdot[15][1] = (p1)*LHYm_n2+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_n2+(r2)*LHYn_n2;
  ySdot[15][2] = (r1)*LHYc_n2+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_n2;
  ySdot[15][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_n2+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_n2+(pow(g2,b)/(pow(LHYn,b)+pow(g2,b)));
  ySdot[15][4] = (p2)*TOC1m_n2+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_n2+(r4)*TOC1n_n2;
  ySdot[15][5] = (r3)*TOC1c_n2+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_n2;
  ySdot[16][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_p1+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_p1;
  ySdot[16][1] = (p1)*LHYm_p1+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_p1+(r2)*LHYn_p1+(LHYm);
  ySdot[16][2] = (r1)*LHYc_p1+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_p1;
  ySdot[16][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_p1+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_p1;
  ySdot[16][4] = (p2)*TOC1m_p1+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_p1+(r4)*TOC1n_p1;
  ySdot[16][5] = (r3)*TOC1c_p1+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_p1;
  ySdot[17][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_p2+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_p2;
  ySdot[17][1] = (p1)*LHYm_p2+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_p2+(r2)*LHYn_p2;
  ySdot[17][2] = (r1)*LHYc_p2+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_p2;
  ySdot[17][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_p2+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_p2;
  ySdot[17][4] = (p2)*TOC1m_p2+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_p2+(r4)*TOC1n_p2+(TOC1m);
  ySdot[17][5] = (r3)*TOC1c_p2+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_p2;
  ySdot[18][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_r1+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_r1;
  ySdot[18][1] = (p1)*LHYm_r1+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_r1+(r2)*LHYn_r1+(-LHYc);
  ySdot[18][2] = (r1)*LHYc_r1+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_r1+(LHYc);
  ySdot[18][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_r1+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_r1;
  ySdot[18][4] = (p2)*TOC1m_r1+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_r1+(r4)*TOC1n_r1;
  ySdot[18][5] = (r3)*TOC1c_r1+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_r1;
  ySdot[19][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_r2+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_r2;
  ySdot[19][1] = (p1)*LHYm_r2+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_r2+(r2)*LHYn_r2+(LHYn);
  ySdot[19][2] = (r1)*LHYc_r2+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_r2+(-LHYn);
  ySdot[19][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_r2+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_r2;
  ySdot[19][4] = (p2)*TOC1m_r2+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_r2+(r4)*TOC1n_r2;
  ySdot[19][5] = (r3)*TOC1c_r2+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_r2;
  ySdot[20][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_r3+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_r3;
  ySdot[20][1] = (p1)*LHYm_r3+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_r3+(r2)*LHYn_r3;
  ySdot[20][2] = (r1)*LHYc_r3+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_r3;
  ySdot[20][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_r3+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_r3;
  ySdot[20][4] = (p2)*TOC1m_r3+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_r3+(r4)*TOC1n_r3+(-TOC1c);
  ySdot[20][5] = (r3)*TOC1c_r3+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_r3+(TOC1c);
  ySdot[21][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_r4+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_r4;
  ySdot[21][1] = (p1)*LHYm_r4+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_r4+(r2)*LHYn_r4;
  ySdot[21][2] = (r1)*LHYc_r4+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_r4;
  ySdot[21][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_r4+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_r4;
  ySdot[21][4] = (p2)*TOC1m_r4+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_r4+(r4)*TOC1n_r4+(TOC1n);
  ySdot[21][5] = (r3)*TOC1c_r4+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_r4+(-TOC1n);

#ifdef INFER_ICS
  ySdot[22][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_LHYm0+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_LHYm0;
  ySdot[22][1] = (p1)*LHYm_LHYm0+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_LHYm0+(r2)*LHYn_LHYm0;
  ySdot[22][2] = (r1)*LHYc_LHYm0+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_LHYm0;
  ySdot[22][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_LHYm0+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_LHYm0;
  ySdot[22][4] = (p2)*TOC1m_LHYm0+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_LHYm0+(r4)*TOC1n_LHYm0;
  ySdot[22][5] = (r3)*TOC1c_LHYm0+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_LHYm0;
  ySdot[23][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_LHYc0+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_LHYc0;
  ySdot[23][1] = (p1)*LHYm_LHYc0+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_LHYc0+(r2)*LHYn_LHYc0;
  ySdot[23][2] = (r1)*LHYc_LHYc0+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_LHYc0;
  ySdot[23][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_LHYc0+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_LHYc0;
  ySdot[23][4] = (p2)*TOC1m_LHYc0+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_LHYc0+(r4)*TOC1n_LHYc0;
  ySdot[23][5] = (r3)*TOC1c_LHYc0+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_LHYc0;
  ySdot[24][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_LHYn0+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_LHYn0;
  ySdot[24][1] = (p1)*LHYm_LHYn0+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_LHYn0+(r2)*LHYn_LHYn0;
  ySdot[24][2] = (r1)*LHYc_LHYn0+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_LHYn0;
  ySdot[24][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_LHYn0+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_LHYn0;
  ySdot[24][4] = (p2)*TOC1m_LHYn0+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_LHYn0+(r4)*TOC1n_LHYn0;
  ySdot[24][5] = (r3)*TOC1c_LHYn0+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_LHYn0;
  ySdot[25][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_TOC1m0+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_TOC1m0;
  ySdot[25][1] = (p1)*LHYm_TOC1m0+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_TOC1m0+(r2)*LHYn_TOC1m0;
  ySdot[25][2] = (r1)*LHYc_TOC1m0+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_TOC1m0;
  ySdot[25][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_TOC1m0+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_TOC1m0;
  ySdot[25][4] = (p2)*TOC1m_TOC1m0+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_TOC1m0+(r4)*TOC1n_TOC1m0;
  ySdot[25][5] = (r3)*TOC1c_TOC1m0+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_TOC1m0;
  ySdot[26][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_TOC1c0+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_TOC1c0;
  ySdot[26][1] = (p1)*LHYm_TOC1c0+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_TOC1c0+(r2)*LHYn_TOC1c0;
  ySdot[26][2] = (r1)*LHYc_TOC1c0+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_TOC1c0;
  ySdot[26][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_TOC1c0+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_TOC1c0;
  ySdot[26][4] = (p2)*TOC1m_TOC1c0+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_TOC1c0+(r4)*TOC1n_TOC1c0;
  ySdot[26][5] = (r3)*TOC1c_TOC1c0+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_TOC1c0;
  ySdot[27][0] = ((LHYm*m1)/pow(LHYm+k1,2.0)-m1/(LHYm+k1))*LHYm_TOC1n0+((pow(TOC1n,a-1.0)*a*n1)/(pow(TOC1n,a)+pow(g1,a))-(pow(TOC1n,a)*pow(TOC1n,a-1.0)*a*n1)/pow(pow(TOC1n,a)+pow(g1,a),2.0))*TOC1n_TOC1n0;
  ySdot[27][1] = (p1)*LHYm_TOC1n0+((LHYc*m2)/pow(LHYc+k2,2.0)-m2/(LHYc+k2)-r1)*LHYc_TOC1n0+(r2)*LHYn_TOC1n0;
  ySdot[27][2] = (r1)*LHYc_TOC1n0+((LHYn*m3)/pow(LHYn+k3,2.0)-m3/(LHYn+k3)-r2)*LHYn_TOC1n0;
  ySdot[27][3] = (-(pow(LHYn,b-1.0)*b*pow(g2,b)*n2)/pow(pow(LHYn,b)+pow(g2,b),2.0))*LHYn_TOC1n0+((TOC1m*m4)/pow(TOC1m+k4,2.0)-m4/(TOC1m+k4))*TOC1m_TOC1n0;
  ySdot[27][4] = (p2)*TOC1m_TOC1n0+((TOC1c*m5)/pow(TOC1c+k5,2.0)-m5/(TOC1c+k5)-r3)*TOC1c_TOC1n0+(r4)*TOC1n_TOC1n0;
  ySdot[27][5] = (r3)*TOC1c_TOC1n0+((TOC1n*m6)/pow(TOC1n+k6,2.0)-m6/(TOC1n+k6)-r4)*TOC1n_TOC1n0;
#endif

  return 0;
}
