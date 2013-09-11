#include <gmcmc/gmcmc_matlab.h>

#include <string.h>
#include <math.h>

#include <gmcmc/gmcmc_errno.h>

#include <mat.h>
#include <matrix.h>

static inline size_t min(size_t a, size_t b) { return (a < b) ? a : b; }
static inline size_t max(size_t a, size_t b) { return (a > b) ? a : b; }

/**
 * How often to write the samples to file.
 */
size_t gmcmc_matlab_save_size = 10000;

/**
 * Whether to save burn-in samples or not.
 */
bool gmcmc_matlab_save_burn_in = true;

/**
 * Where to write the samples to.
 */
const char * gmcmc_matlab_outputID = NULL;

/**
 * Creates an array of cells in MATLAB each containing a struct.
 *
 * @param [in] ncells      the number of cells to create in the array
 * @param [in] fieldnames  the names of the fields to put in each struct
 * @param [in] fielddims   the dimensions of each field
 * @param [in] nfields     the number of fields in each struct
 *
 * @return the MATLAB cell array or NULL if there is not enough memory.
 */
static mxArray * create_matlab_array(mwSize ncells, const char * fieldnames[],
                                     const mwSize fielddims[][2], int nfields) {
  // Create a MATLAB cell array of length ncells
  mxArray * cells = mxCreateCellArray(1, &ncells);
  if (cells == NULL)
    GMCMC_ERROR_VAL("Failed to create MATLAB cell matrix", GMCMC_ENOMEM, NULL);

  // In each cell...
  for (mwIndex j = 0; j < ncells; j++) {
    // Create a 1x1 struct matrix
    mxArray * structs = mxCreateStructMatrix(1, 1, nfields, fieldnames);
    if (structs == NULL) {
      mxDestroyArray(cells);
      GMCMC_ERROR_VAL("Failed to create MATLAB struct matrix", GMCMC_ENOMEM, NULL);
    }

    // Create real arrays for each field in the struct
    for (int i = 0; i < nfields; i++) {
      mxArray * field = mxCreateDoubleMatrix(fielddims[i][0], fielddims[i][1], 0);
      if (field == NULL) {
        mxDestroyArray(cells);
        GMCMC_ERROR_VAL("Failed to create MATLAB struct field", GMCMC_ENOMEM, NULL);
      }

      mxSetField(structs, 0, fieldnames[i], field);
    }

    // Set the struct matrix to be part of the cell array
    mxSetCell(cells, j, structs);
  }

  return cells;
}

/**
 * Copies a value into a struct field in a MATLAB cell array.
 *
 * @param [in] cells   the MATLAB cell matrix
 * @param [in] index   the index of the struct in the MATLAB cell array
 * @param [in] name    the name of the field to write in the struct
 * @param [in] offset  the offset in the field to start writing
 * @param [in] value   a pointer to the value to write
 *
 * @return 0 on success, GMCMC_EIO if an error occurred.
 */
static int write_matlab_field(mxArray * cells, mwIndex index, const char * fieldname, size_t offset, const double * value) {
  mxArray * structs = mxGetCell(cells, index);
  if (structs == NULL)
    GMCMC_ERROR("Failed to get struct from MATLAB cell matrix", GMCMC_EIO);

  mxArray * field;
  if ((field = mxGetField(structs, 0, fieldname)) == NULL)
    GMCMC_ERROR("Failed to get field from MATLAB struct", GMCMC_EIO);

  double * ptr;
  if ((ptr = mxGetPr(field)) == NULL)
    GMCMC_ERROR("Failed to get pointer from MATLAB array", GMCMC_EIO);

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
 * @param [in] stepsize        the current stepsize
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the Matlab
 *                         structure array,
 *         GMCMC_EIO     if there was an error writing the Matlab structure
 *                         array to a file.
 */
int gmcmc_matlab_popmcmc_write(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
                               size_t i, size_t j,
                               const double * params, const double * log_prior,
                               double log_likelihood, double stepsize) {
  static mxArray * samples = NULL;      // The MATLAB cell array
  static size_t k = 0;                  // Index into the MATLAB cell array [0, gmcmc_matlab_save_size)
  static size_t written = 0;            // The number of samples written to file so far
  static const char * fieldnames[] = { "Paras", "LL", "LogPrior", "StepSize" };
  static const int nfields = 4;

  const size_t num_params = gmcmc_model_get_num_params(model);

  // Lazily create the samples array
  if (samples == NULL) {
    const mwSize n = (gmcmc_matlab_save_burn_in) ?
                     min(gmcmc_matlab_save_size, max(options->num_burn_in_samples,
                                                     options->num_posterior_samples)) :
                     min(gmcmc_matlab_save_size, options->num_posterior_samples);
    const mwSize fielddims[][2] = { { n, num_params }, { n, 1 }, { n, num_params }, { n, 1 } };

    if ((samples = create_matlab_array(options->num_temperatures, fieldnames, fielddims, nfields)) == NULL)
      GMCMC_ERROR("Failed to create MATLAB sample array", GMCMC_ENOMEM);
  }

  // If saving burn-in and this is a burn-in iteration
  if ((gmcmc_matlab_save_burn_in && i < options->num_burn_in_samples) || i >= options->num_burn_in_samples) {
    // Copy the current parameters, log prior and log likelihood into the arrays
    int error;
    if ((error = write_matlab_field(samples, j, "Paras", k, params)) != 0 ||
        (error = write_matlab_field(samples, j, "LogPrior", k, log_prior)) != 0 ||
        (error = write_matlab_field(samples, j, "LL", k, &log_likelihood)) != 0 ||
        (error = write_matlab_field(samples, j, "StepSize", k, &stepsize)) != 0) {
      mxDestroyArray(samples);
      samples = NULL;
      k = 0;
      written = 0;
      GMCMC_ERROR("Failed to copy samples into MATLAB struct", GMCMC_EIO);
    }
    if (j == options->num_temperatures - 1)
      k++;
  }

  // If the arrays are full or this is the last burn-in or posterior sample then
  // write the cell array to file
  if ((k == gmcmc_matlab_save_size || i == options->num_burn_in_samples - 1 ||
       i == options->num_burn_in_samples + options->num_posterior_samples - 1) &&
       j == options->num_temperatures - 1) {
    char * filename;
    const char * varname = (i < options->num_burn_in_samples) ? "Samples_BurnIn" : "Samples_Posterior";
    const char * template = (i < options->num_burn_in_samples) ? "%s_BurnIn_%zu-%zu.mat" : "%s_Posterior_%zu-%zu.mat";
    // Format the filename for the samples
    size_t outputlen = strlen(gmcmc_matlab_outputID) + strlen(template) + 10 + floor(log10(written + 1)) + floor(log10(written + k));
    if ((filename = malloc(outputlen)) == NULL) {
      mxDestroyArray(samples);
      samples = NULL;
      k = 0;
      written = 0;
      GMCMC_ERROR("Failed to allocate space for MATLAB file name", GMCMC_ENOMEM);
    }
    snprintf(filename, outputlen, template, gmcmc_matlab_outputID, written + 1, written + k);

    // Open a Matlab file
    MATFile * file = matOpen(filename, "w7.3");       // Use HDF5
    free(filename);
    if (file == NULL) {
      mxDestroyArray(samples);
      samples = NULL;
      k = 0;
      written = 0;
      GMCMC_ERROR("Failed to open MATLAB file", GMCMC_EIO);
    }

    // Write the structure array to the file
    if (matPutVariable(file, varname, samples) != 0) {
      mxDestroyArray(samples);
      samples = NULL;
      k = 0;
      written = 0;
      matClose(file);
      GMCMC_ERROR("Failed to write burn in samples to file", GMCMC_EIO);
    }

    // Close the file
    if (matClose(file) != 0) {
      mxDestroyArray(samples);
      samples = NULL;
      k = 0;
      written = 0;
      GMCMC_ERROR("Failed to close burn in sample file", GMCMC_EIO);
    }

    written += k;
    k = 0;

    if (i == options->num_burn_in_samples - 1)
      written = 0;
  }

  return 0;
}
