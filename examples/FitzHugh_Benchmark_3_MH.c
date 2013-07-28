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

#include <cvodes/cvodes.h>
#include <cvodes/cvodes_dense.h>
#include <nvector/nvector_serial.h>

#include "acceptance.h"
#include "matlab.h"

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
 * ODE solver function.
 *
 * @param [in]  n           the number of timepoints
 * @param [in]  timepoints  the timepoints
 * @param [in]  params      the current parameter values
 * @param [out] simdata     simulated data from the system of ODEs
 * @param [in]  lds         leading dimension of simdata
 *
 * @return 0 on success,
 *         GMCMC_ELINAL if there was an error with a CVODES solver function.
 */
static int cvodes_solve(size_t, const double *, const double *, double *, size_t);

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
  outputID = argv[optind];

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
  mcmc_options.upper_step_size =   0.5;
  mcmc_options.lower_step_size =   0.2;

  // Callbacks
  mcmc_options.acceptance = acceptance_monitor;
  mcmc_options.write = write_matlab;

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
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
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
  if ((error = gmcmc_ode_model_create(&ode_model, 2, 0, cvodes_solve)) != 0) {
    // Clean up
    free(temperatures);
    gmcmc_dataset_destroy(dataset);
    gmcmc_model_destroy(model);
    fputs("Unable to create ODE specific model\n", stderr);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -6;
  }

  gmcmc_model_set_modelspecific(model, ode_model);


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
 * Right-hand side of system of ODEs to solve in likelihood function.
 *
 * @param [in]  t       the current timepoint
 * @param [in]  y       the current y values
 * @param [out] yt      the new y values
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         < 0 if any of the parameter values are invalid,
 *         > 0 if any of the y values are invalid.
 */
static int cvodes_rhs(realtype t, N_Vector y, N_Vector ydot, void * userdata) {
  (void)t;      // Unused

  // Parameters are stored in userdata
  realtype * params = (realtype *)userdata;
  realtype a = params[0];
  realtype b = params[1];
  realtype c = params[2];

  realtype v = NV_Ith_S(y, 0);
  realtype r = NV_Ith_S(y, 1);

  // d/dt(V) = c*(V-(V^3)/3+R)
  realtype vt = c * (v - ((v*v*v) / 3.0) + r);
  NV_Ith_S(ydot, 0) = vt;

  // d/dt(R) = -(V-a+b*R)/c
  realtype rt = -(v - a + b * r) / c;
  NV_Ith_S(ydot, 1) = rt;

  return 0;
}

/**
 * ODE solver function.
 *
 * @param [in]  n           the number of timepoints
 * @param [in]  timepoints  the timepoints
 * @param [in]  params      the current parameter values
 * @param [out] simdata     simulated data from the system of ODEs
 * @param [in]  lds         leading dimension of simdata
 *
 * @return 0 on success,
 *         GMCMC_ELINAL if there was an error with a CVODES solver function.
 */
static int cvodes_solve(size_t n, const double * timepoints, const double * params,
                        double * simdata, size_t lds) {
  const unsigned int num_species = 2;
  const unsigned int num_params = 3;

  realtype cvodes_params[num_params];
  // Reparameterise if necessary (and convert to CVODES type)
#ifdef LOG10SPACE
  for (unsigned int i = 0; i < num_params; i++)
    cvodes_params[i] = pow(10.0, params[i]);
#else
  for (unsigned int i = 0; i < num_params; i++)
    cvodes_params[i] = params[i];
#endif

  realtype cvodes_ics[num_species];
#ifdef INFER_ICS
#ifdef LOG10SPACE_ICS
  for (unsigned int i = 0; i < num_species; i++)
    cvodes_ics[i] = pow(10.0, params[num_params + i]);
#else
  for (unsigned int i = 0; i < num_species; i++)
    cvodes_ics[i] = params[num_params + i];
#endif
#else
  cvodes_ics[0] = -1.0;
  cvodes_ics[1] =  1.0;
#endif

  // Create CVODES solver
  void * cvode_mem;
  if ((cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON)) == NULL)
    GMCMC_ERROR("Failed to create CVODES solver", GMCMC_ELINAL);

  // Initialise CVODES solver
  N_Vector ics = N_VMake_Serial(num_species, cvodes_ics);
  int error = CVodeInit(cvode_mem, cvodes_rhs, timepoints[0], ics);
  N_VDestroy(ics);
  if (error != CV_SUCCESS)
    GMCMC_ERROR("Failed to initialise ODE solver", GMCMC_ELINAL);

  // Set user data
  if ((error = CVodeSetUserData(cvode_mem, (void *)cvodes_params)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to set ODE solver user data", GMCMC_ELINAL);
  }

  // Specify integration tolerances
  if ((error = CVodeSStolerances(cvode_mem, 1.0e-08, 1.0e-08)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to specify ODE solver integration tolerances", GMCMC_ELINAL);
  }

  // Attach linear solver module
  if ((error = CVDense(cvode_mem, num_species)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to attach ODE linear solver module", GMCMC_ELINAL);
  }

  // Initial values (part of parameter vector)
  for (unsigned int i = 0; i < num_species; i++)
    simdata[i * lds] = params[3 + i];

  // Advance solution in time
  N_Vector yout = N_VNew_Serial(num_species);
  for (size_t i = 1; i < n; i++) {
    double tret;
    if ((error = CVode(cvode_mem, timepoints[i], yout, &tret, CV_NORMAL)) != CV_SUCCESS) {
      CVodeFree(&cvode_mem);
      GMCMC_ERROR("Failed to solve ODE", GMCMC_ELINAL);
    }
    for (unsigned int j = 0; j < num_species; j++)
      simdata[j * lds + i] = NV_Ith_S(yout, j);
  }
  N_VDestroy(yout);

  // Free the solver
  CVodeFree(&cvode_mem);

  return 0;
}
