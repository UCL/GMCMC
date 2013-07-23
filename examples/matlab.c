#include "matlab.h"

#include <string.h>
#include <math.h>

#include <gmcmc/gmcmc_errno.h>

#include <mat.h>
#include <matrix.h>

/**
 * Where to write the samples to.
 */
const char * outputID;

/**
 * Creates an array of cells in Matlab containing fields for the parameters,
 * log likelihood and log prior.
 *
 * @param [in] num_samples       the number of samples to store in each struct
 * @param [in] num_temperatures  the number of cells to create in the array
 *                                 (one for each temperature)
 * @param [in] num_params        the number of parameters in each sample (and
 *                                 log prior)
 *
 * @return the Matlab cell array or NULL if an error occurred.
 */
static mxArray * create_matlab_array(size_t num_samples,
                                     unsigned int num_temperatures,
                                     unsigned int num_params) {
  // Create a Matlab cell matrix to hold the samples
  mxArray * cells = mxCreateCellMatrix(1, num_temperatures);
  if (cells == NULL)
    GMCMC_ERROR_VAL("Failed to create Matlab cell matrix", GMCMC_ENOMEM, NULL);

  for (unsigned int j = 0; j < num_temperatures; j++) {
    // Create a 1x1 struct matrix
    const char * fields[] = { "Paras", "LL", "LogPrior" };
    mxArray * structs = mxCreateStructMatrix(1, 1, 3, fields);
    if (structs == NULL) {
      mxDestroyArray(cells);
      GMCMC_ERROR_VAL("Failed to create Matlab struct matrix", GMCMC_ENOMEM, NULL);
    }

    // Create arrays for the parameters, log likelihood and log prior
    mxArray * params = NULL, * log_prior = NULL, * log_likelihood = NULL;
    if ((params = mxCreateDoubleMatrix(num_samples, num_params, 0)) == NULL ||
        (log_prior = mxCreateDoubleMatrix(num_samples, num_params, 0)) == NULL ||
        (log_likelihood = mxCreateDoubleMatrix(num_samples, 1, 0)) == NULL) {
      mxDestroyArray(params);
      mxDestroyArray(log_prior);
      mxDestroyArray(log_likelihood);
      mxDestroyArray(cells);
      GMCMC_ERROR_VAL("Failed to create parameter, log_prior and log_likelihood arrays", GMCMC_ENOMEM, NULL);
    }

    // Set the arrays to be part of the struct matrix
    mwIndex subs[] = { 0, 0 };
    mwIndex index = mxCalcSingleSubscript(structs, 2, subs);
    mxSetField(structs, index, "Paras", params);
    mxSetField(structs, index, "LL", log_likelihood);
    mxSetField(structs, index, "LogPrior", log_prior);

    // Set the struct matrix to be part of the cell array
    subs[1] = j;
    index = mxCalcSingleSubscript(cells, 2, subs);
    mxSetCell(cells, index, structs);
  }

  return cells;
}

/**
 * Copies a value into a struct field in a Matlab cell array.
 *
 * @param [in] cells   the Matlab cell matrix
 * @param [in] name    the name of the field to write
 * @param [in] index   the index of the structure in the Matlab cell array
 * @param [in] offset  the offset in the field to start writing
 * @param [in] value   a pointer to the value to write
 *
 * @return 0 on success, GMCMC_EIO if an error occurred.
 */
static int write_matlab_field(mxArray * cells, const char * name, size_t index, size_t offset, const double * value) {
  mxArray * structs = mxGetCell(cells, index);
  if (structs == NULL)
    GMCMC_ERROR("Failed to get struct from Matlab cell matrix", GMCMC_EIO);

  mwIndex subs[] = { 0, 0 };
  mwIndex i = mxCalcSingleSubscript(structs, 2, subs);
  mxArray * field;
  if ((field = mxGetField(structs, i, name)) == NULL)
    GMCMC_ERROR("Failed to get field from Matlab struct", GMCMC_EIO);

  double * ptr;
  if ((ptr = mxGetPr(field)) == NULL)
    GMCMC_ERROR("Failed to get pointer from Matlab array", GMCMC_EIO);

  size_t ld = mxGetM(field);
  size_t n = mxGetN(field);

  for (size_t i = 0; i < n; i++)
    ptr[i * ld + offset] = value[i];

  return 0;
}

/**
 * Stores a sample in a global array that is later written to a Matlab file.
 *
 * @param [in] options         the MCMC options
 * @param [in] model           the model
 * @param [in] i               the current iteration number
 * @param [in] j               the index on the temperature scale
 * @param [in] params          the current parameter values
 * @param [in] log_prior       the log prior of the sample
 * @param [in] log_likelihood  the log likelihood of the sample
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the Matlab
 *                         structure array,
 *         GMCMC_EIO     if there was an error writing the Matlab structure
 *                         array to a file.
 */
int write_matlab(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
                 size_t i, size_t j,
                 const double * params, const double * log_prior, double log_likelihood) {
  static mxArray * burn_in = NULL, * posterior = NULL;

  const size_t num_params = gmcmc_model_get_num_params(model);

  if (i < options->num_burn_in_samples) {
    // Lazily create a Matlab struct-of-arrays big enough to hold all the burn in samples
    if (burn_in == NULL) {
      if ((burn_in = create_matlab_array(options->num_burn_in_samples, options->num_temperatures, num_params)) == NULL)
        GMCMC_ERROR("Failed to create burn in Matlab array", GMCMC_ENOMEM);
    }

    // Copy the current parameters, log prior and log likelihood into the arrays
    int error;
    if ((error = write_matlab_field(burn_in, "Paras", j, i, params)) != 0 ||
        (error = write_matlab_field(burn_in, "LogPrior", j, i, log_prior)) != 0 ||
        (error = write_matlab_field(burn_in, "LL", j, i, &log_likelihood)) != 0)
      GMCMC_ERROR("Failed to write Matlab fields", GMCMC_EIO);

    // If the arrays are full write them to a file
    if (i == options->num_burn_in_samples - 1 && j == options->num_temperatures - 1) {
      // Format the filename for the burn in samples
      char * filename;
      size_t outputlen = strlen(outputID) + 22 + floor(log10(options->num_burn_in_samples));
      if ((filename = malloc(outputlen)) == NULL)
        GMCMC_ERROR("Failed to allocate space for burn in file name", GMCMC_ENOMEM);
      snprintf(filename, outputlen, "%s_BurnIn_%zu.mat", outputID, options->num_burn_in_samples);

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

    // Have already written num_burn_in_samples
    i -= options->num_burn_in_samples;

    // Copy the current parameters, log prior and log likelihood into the arrays
    int error;
    if ((error = write_matlab_field(posterior, "Paras", j, i % POSTERIOR_SAVE_SIZE, params)) != 0 ||
        (error = write_matlab_field(posterior, "LogPrior", j, i % POSTERIOR_SAVE_SIZE, log_prior)) != 0 ||
        (error = write_matlab_field(posterior, "LL", j, i % POSTERIOR_SAVE_SIZE, &log_likelihood)) != 0)
      GMCMC_ERROR("Failed to write Matlab fields", GMCMC_EIO);

    // If the arrays are full write them to a file
    if ((i % POSTERIOR_SAVE_SIZE == POSTERIOR_SAVE_SIZE - 1 ||
        i == options->num_posterior_samples - 1) && j == options->num_temperatures - 1) {
      // Format the filename for the burn in samples
      char * filename;
      size_t outputlen = strlen(outputID) + 25 + floor(log10(i + 1));
      if ((filename = malloc(outputlen)) == NULL)
        GMCMC_ERROR("Failed to allocate space for burn in file name", GMCMC_ENOMEM);
      snprintf(filename, outputlen, "%s_Posterior_%zu.mat", outputID, i + 1);

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

#ifdef TEST
int main(int argc, char * argv[]) {
  outputID = "test";

  double temperatures[] = { 1.0 };
  gmcmc_popmcmc_options options = {
    .num_posterior_samples = 10,
    .num_burn_in_samples = 10,
    .temperatures = temperatures,
    .num_temperatures = 1,
    .adapt_rate = 50,
    .upper_step_size = 0.5,
    .lower_step_size = 0.2,
    .acceptance = NULL,
    .write = write_matlab
  };

  int error;

  size_t num_params = 4;
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL)
    GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
  for (size_t i = 0; i < num_params; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 1.0)) != 0) {
      for (size_t j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  gmcmc_model * model;
  if ((error = gmcmc_model_create(&model, num_params, priors, NULL, NULL)) != 0) {
    for (size_t j = 0; j < num_params; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    GMCMC_ERROR("Failed to create model", error);
  }

  for (size_t j = 0; j < num_params; j++)
    gmcmc_distribution_destroy(priors[j]);
  free(priors);


  size_t n = options.num_burn_in_samples + options.num_posterior_samples;
  for (size_t i = 0; i < n; i++) {
    double params[] = { i * num_params + 0.0, i * num_params + 1.0, i * num_params + 2.0, i * num_params + 3.0 };
    double log_prior[] = { i * num_params + 4.0, i * num_params + 5.0, i * num_params + 6.0, i * num_params + 7.0 };
    double log_likelihood = i;

    fprintf(stderr, "params{%zu} = ", i);
    for (size_t j = 0; j < num_params; j++) {
      fprintf(stderr, "%.15f", params[j]);
      if (j < num_params - 1)
        fprintf(stderr, ", ");
      else
        fprintf(stderr, "\n");
    }

    fprintf(stderr, "log_prior{%zu} = ", i);
    for (size_t j = 0; j < num_params; j++) {
      fprintf(stderr, "%.15f", log_prior[j]);
      if (j < num_params - 1)
        fprintf(stderr, ", ");
      else
        fprintf(stderr, "\n");
    }

    fprintf(stderr, "log_likelihood{%zu} = %.15f\n", i, log_likelihood);

    if ((error = options.write(&options, model, i, 0, params, log_prior, log_likelihood)) != 0) {
      gmcmc_model_destroy(model);
      GMCMC_ERROR("Failed to write samples", error);
    }
  }

  gmcmc_model_destroy(model);

  return 0;
}
#endif
