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
    mxSetField(structs, 0, "Paras", params);
    mxSetField(structs, 0, "LL", log_likelihood);
    mxSetField(structs, 0, "LogPrior", log_prior);

    // Set the struct matrix to be part of the cell array
    mxSetCell(cells, j, structs);
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
 * @param [in] value   the value to write
 * @param [in] size    the size of the value to write
 *
 * @return 0 on success, GMCMC_EIO if an error occurred.
 */
static int write_matlab_field(mxArray * cells, const char * name, size_t index, size_t offset, const double * value, size_t size) {
  mxArray * structs = mxGetCell(cells, index);
  if (structs == NULL)
    GMCMC_ERROR("Failed to get struct from Matlab cell matrix", GMCMC_EIO);

  mxArray * field;
  if ((field = mxGetField(structs, 0, name)) == NULL)
    GMCMC_ERROR("Failed to get field from Matlab struct", GMCMC_EIO);

  double * ptr;
  if ((ptr = mxGetPr(field)) == NULL)
    GMCMC_ERROR("Failed to get pointer from Matlab array", GMCMC_EIO);

  memcpy(&ptr[offset * size], value, size * sizeof(double));

  return 0;
}

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
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the Matlab
 *                         structure array,
 *         GMCMC_EIO     if there was an error writing the Matlab structure
 *                         array to a file.
 */
int write_matlab(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
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
