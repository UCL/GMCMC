#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include <mpi.h>

#include <mat.h>
#include <matrix.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_ion_model.h>
#include <gmcmc/gmcmc_distribution.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_popmcmc.h>

// Whether to use log space for parameter values - helps with very small/large values
#define LOG10SPACE

// How often to save posterior samples
#define POSTERIOR_SAVE_SIZE 1000

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
 * @param [in]  n       the number of parameters
 * @param [out] Q       the Q matrix, initialised to zero
 * @param [in]  ldq     the leading dimension of the Q matrix
 */
static void calculate_Q_matrix(const double *, size_t, double *, size_t);

/**
 * Acceptance callback.
 *
 * @param [in] options     the MCMC options
 * @param [in] model       the model
 * @param [in] iteration   whether the current iteration is from burn in
 *                           (GMCMC_BURN_IN) or posterior (GMCMC_POSTERIOR)
 * @param [in] i           the iteration number
 * @param [in] acceptance  the acceptance ratios for each temperature
 * @param [in] exchange    the exchange ratios for each temerature
 * @param [in] stepsizes   the step sizes for each temperature
 */
static void acceptance_monitor(const gmcmc_popmcmc_options *, const gmcmc_model *,
                               GMCMC_ITERATION, size_t, const double *,
                               const double *, const double *);

/**
 * Stores a sample in a global array that is later written to a Matlab file.
 *
 * @param [in] options         the MCMC options
 * @param [in] model           the model
 * @param [in] iteration       whether the current iteration is from burn in
 *                               (GMCMC_BURN_IN) or posterior (GMCMC_POSTERIOR)
 * @param [in] i               the current iteration number
 * @param [in] j               the index on the temperature scale
 * @param [in] params          the current parameter values
 * @param [in] log_prior       the log prior of the sample
 * @param [in] log_likelihood  the log likelihood of the sample
 *
 * @return zero on success, non-zero on failure.
 */
static int write_matlab(const gmcmc_popmcmc_options *, const gmcmc_model *,
                        GMCMC_ITERATION, size_t, size_t,
                        const double *, const double *, double);

static const char * outputID;

int main(int argc, char * argv[]) {
  // Since we are using MPI for parallel processing initialise it here before
  // parsing the arguments for our program
  MPI_ERROR_CHECK(MPI_Init(&argc, &argv), "Failed to initialise MPI");

  if (argc < 2) {
    fprintf(stderr, "Usage:\n\t%s <filename>\nwhere:\n\t<filename> is a file to save the samples in\n", argv[0]);
    MPI_ERROR_CHECK(MPI_Finalize(), "Failed to shut down MPI");
    return -1;
  }

  // Output file
  outputID = argv[1];

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
  for (int i = 0; i < mcmc_options.num_temperatures; i++)
    temperatures[i] = pow(i * (1.0 / (mcmc_options.num_temperatures - 1.0)), 5.0);
  mcmc_options.temperatures = temperatures;

  // Set number of burn-in and posterior samples
  mcmc_options.num_burn_in_samples   = 1000;
  mcmc_options.num_posterior_samples = 1000;

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
  for (int i = 0; i < num_params; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], -2.0, 4.0)) != 0) {
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
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10000.0)) != 0) {
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
  if ((error = gmcmc_dataset_create_matlab(&dataset, "ION_dCK_0,5s.mat")) != 0) {
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
  gmcmc_model * model;
  if ((error = gmcmc_model_create(&model, num_params, priors, gmcmc_ion_proposal_mh, gmcmc_ion_likelihood_mh)) != 0) {
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

  /**
   * Open the burn in and posterior sample files
   */


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

static void calculate_Q_matrix(const double * params, size_t num_params, double * Q, size_t ldq) {
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

static void acceptance_monitor(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
                               GMCMC_ITERATION iteration, size_t i, const double * accepts,
                               const double * exchanges, const double * stepsizes) {
  if (iteration == GMCMC_BURN_IN) {
    fprintf(stderr, "Burn in iteration: %zu of %zu\n\n", i, options->num_burn_in_samples);

    // Display summary information for each chain
    fputs("Parameter acceptance rates:\n", stderr);
    for (size_t j = 0; j < options->num_temperatures; j++)
      fprintf(stderr, "%15.6f", accepts[j]);
    fputs("\n\n", stderr);

    fputs("Parameter stepsizes:\n", stderr);
    for (size_t j = 0; j < options->num_temperatures; j++)
      fprintf(stderr, "%15.6f", stepsizes[j]);
    fputs("\n\n", stderr);

    // Display exchange rate
    fputs("Model parameter exchange ratios:\n", stderr);
    for (size_t j = 0; j < options->num_temperatures; j++)
      fprintf(stderr, "%15.6f", exchanges[j]);
    fputs("\n\n\n", stderr);
  }
  else
    fprintf(stderr, "Posterior iteration: %zu of %zu\n\n", i, options->num_posterior_samples);
}

static mxArray * create_matlab_array(size_t num_samples, unsigned int num_temperatures, unsigned int num_params) {
  // Create a Matlab structure array to hold the samples
  const char * fields[] = { "Paras", "LL", "LogPrior" };
  mxArray * res = mxCreateStructMatrix(1, num_temperatures, 3, fields);
  if (res == NULL)
    GMCMC_ERROR_VAL("Failed to create Matlab structure array", GMCMC_ENOMEM, NULL);

  for (unsigned int j = 0; j < num_temperatures; j++) {
    // Create arrays for the parameters, log likelihood and log prior
    mxArray * params = NULL, * log_prior = NULL, * log_likelihood = NULL;
    if ((params = mxCreateDoubleMatrix(num_samples, num_params, 0)) == NULL ||
        (log_prior = mxCreateDoubleMatrix(num_samples, num_params, 0)) == NULL ||
        (log_likelihood = mxCreateDoubleMatrix(num_samples, 1, 0)) == NULL) {
      mxDestroyArray(params);
      mxDestroyArray(log_prior);
      mxDestroyArray(log_likelihood);
      mxDestroyArray(res);
      GMCMC_ERROR_VAL("Failed to create parameter, log_prior and log_likelihood arrays", GMCMC_ENOMEM, NULL);
    }

    // Set the arrays to be part of the struct array
    mxSetField(res, j, "Paras", params);
    mxSetField(res, j, "LL", log_likelihood);
    mxSetField(res, j, "LogPrior", log_prior);
  }

  return res;
}

static int write_matlab_field(mxArray * array, const char * name, size_t index, size_t offset, const double * value, size_t size) {
  mxArray * field;
  if ((field = mxGetField(array, index, name)) == NULL)
    GMCMC_ERROR("Failed to get field from Matlab struct", GMCMC_EIO);
  double * ptr;
  if ((ptr = mxGetPr(field)) == NULL)
    GMCMC_ERROR("Failed to get pointer from Matlab array", GMCMC_EIO);
  memcpy(&ptr[offset * size], value, size * sizeof(double));
  return 0;
}

static int write_matlab(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
                        GMCMC_ITERATION iteration, size_t i, size_t j,
                        const double * params, const double * log_prior, double log_likelihood) {
  static mxArray * burn_in = NULL, * posterior = NULL;

  const size_t num_params = gmcmc_model_get_num_params(model);

  if (iteration == GMCMC_BURN_IN) {
    // Lazily create a Matlab struct-of-arrays big enough to hold all the burn in samples
    if (burn_in == NULL) {
      if ((burn_in = create_matlab_array(options->num_burn_in_samples, options->num_temperatures, num_params)) == NULL)
        GMCMC_ERROR("Failed to create burn in Matlab array", GMCMC_ENOMEM);
    }

    // Copy the current parameters, log prior and log likelihood into the arrays
    int error;
    if ((error = write_matlab_field(burn_in, "Paras", j, i, params, num_params)) != 0 ||
        (error = write_matlab_field(burn_in, "LogPrior", j, i, log_prior, num_params)) != 0 ||
        (error = write_matlab_field(burn_in, "LL", j, i, &log_likelihood, 1)) != 0)
      GMCMC_ERROR("Failed to write Matlab fields", GMCMC_EIO);

    // If the arrays are full write them to a file
    if (i == options->num_burn_in_samples - 1 && j == options->num_temperatures - 1) {
      // Format the filename for the burn in samples
      char * filename;
      size_t outputlen = strlen(outputID) + 22 + floor(log10(options->num_burn_in_samples));
      if ((filename = malloc(outputlen)) == NULL)
        GMCMC_ERROR("Failed to allocate space for burn in file name", GMCMC_ENOMEM);
      snprintf(filename, outputlen, "results/%s_BurnIn_%zu.mat", outputID, options->num_burn_in_samples);

      // Open a Matlab file
      MATFile * file = matOpen(filename, "w7.3");       // Use HDF5
      free(filename);
      if (file == NULL)
        GMCMC_ERROR("Failed to open Matlab file", GMCMC_EIO);

      // Write the structure array to the file
      if (matPutVariable(file, "Samples_BurnIn", burn_in) != 0) {
        matClose(file);
        GMCMC_ERROR("Failed to write burn in samples to file", GMCMC_EIO);
      }

      // Close the file
      if (matClose(file) != 0)
        GMCMC_ERROR("Failed to close burn in sample file", GMCMC_EIO);

      // Free the burn-in array
      mxDestroyArray(burn_in);
    }
  }
  else {
    // Lazily create a Matlab struct-of-arrays big enough to hold POSTERIOR_SAVE_SIZE posterior samples
    if (posterior == NULL) {
      if ((posterior = create_matlab_array(POSTERIOR_SAVE_SIZE, options->num_temperatures, num_params)) == NULL)
        GMCMC_ERROR("Failed to create burn in Matlab array", GMCMC_ENOMEM);
    }

    // Copy the current parameters, log prior and log likelihood into the arrays
    int error;
    if ((error = write_matlab_field(posterior, "Paras", j, i % POSTERIOR_SAVE_SIZE, params, num_params)) != 0 ||
        (error = write_matlab_field(posterior, "LogPrior", j, i % POSTERIOR_SAVE_SIZE, log_prior, num_params)) != 0 ||
        (error = write_matlab_field(posterior, "LL", j, i % POSTERIOR_SAVE_SIZE, &log_likelihood, 1)) != 0)
      GMCMC_ERROR("Failed to write Matlab fields", GMCMC_EIO);

    // If the arrays are full write them to a file
    if ((i % POSTERIOR_SAVE_SIZE == POSTERIOR_SAVE_SIZE - 1 ||
        i == options->num_posterior_samples - 1) && j == options->num_temperatures - 1) {
      // Format the filename for the burn in samples
      char * filename;
      size_t outputlen = strlen(outputID) + 25 + floor(log10(i + 1));
      if ((filename = malloc(outputlen)) == NULL)
        GMCMC_ERROR("Failed to allocate space for burn in file name", GMCMC_ENOMEM);
      snprintf(filename, outputlen, "results/%s_Posterior_%zu.mat", outputID, i + 1);

      // Open a Matlab file
      MATFile * file = matOpen(filename, "w7.3");       // Use HDF5
      free(filename);
      if (file == NULL)
        GMCMC_ERROR("Failed to open Matlab file", GMCMC_EIO);

      // Write the structure array to the file
      if (matPutVariable(file, "Samples_Posterior", posterior) != 0) {
        matClose(file);
        GMCMC_ERROR("Failed to write posterior samples to file", GMCMC_EIO);
      }

      // Close the file
      if (matClose(file) != 0)
        GMCMC_ERROR("Failed to close posterior sample file", GMCMC_EIO);

      // If that was the last sample
      if (i == options->num_posterior_samples - 1) {
        // Free the posterior array
        mxDestroyArray(posterior);
      }
    }
  }

  return 0;
}
