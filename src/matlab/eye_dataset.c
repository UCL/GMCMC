#include <gmcmc/gmcmc_eye.h>
#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>

#include <mat.h>

/**
 * A stochastic eye dataset loaded from Matlab.
 */
typedef struct {
  MATFile * file;       /**< Matlab file pointer */
  mxArray * data_mean;  /**< Matlab array containing data */
  mxArray * data_var;   /**< Matlab array containing variance */
} matlab_dataset;

/**
 * Destructor for stochastic eye Matlab datasets.  Frees the Matlab mxArrays and
 * closes the MATFile pointer.
 *
 * @param [in] data  the Matlab stochastic eye dataset.
 */
static void destroy(void * data) {
  matlab_dataset * m = (matlab_dataset *)data;
  mxDestroyArray(m->data_mean);
  mxDestroyArray(m->data_var);
  matClose(m->file);
  free(m);
}

/**
 * Get a pointer to the data vector from a Matlab stochastic eye dataset.
 *
 * @param [in] data  the Matlab stochastic eye dataset
 *
 * @return a pointer to the data vector or NULL if the mxArray contains no real
 *           data.
 */
static const double * data(const void * data) {
  const matlab_dataset * m = (const matlab_dataset *)data;
  double * d = mxGetPr(m->data_mean);
  if (d == NULL)
    GMCMC_ERROR_VAL("data_mean contains no real data", GMCMC_EIO, NULL);
  return d;
}

/**
 * Gets a pointer to a variance vector from a Matlab stochastic eye dataset.
 *
 * @param [in] data  the Matlab stochastic dataset
 *
 * @return a pointer to a data vector or NULL if the mxArray contains no real
 *         data.
 */
static const double * noisevar(const void * data) {
  const matlab_dataset * m = (const matlab_dataset *)data;
  double * v = mxGetPr(m->data_var);
  if (v == NULL)
    GMCMC_ERROR_VAL("data_var contains no real data", GMCMC_EIO, NULL);
  return v;
}

/**
 * Gets the number of timepoints in the dataset.
 *
 * @return the number of timepoints.
 */
static size_t num_timepoints(const void * data) {
  const matlab_dataset * m = (const matlab_dataset *)data;
  return mxGetM(m->data_mean);
}

/**
 * Stochastic eye Matlab dataset type.
 */
static const gmcmc_eye_dataset_type type = { destroy,
                                             num_timepoints,
                                             data,
                                             noisevar };

/**
 * Loads a stochastic eye dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "Data_Mean" containing the data points and a
 * variance vector for the data named "Data_Var".
 * The dimensionality of the data must match that of the variance.
 *
 * @param [out] dataset         the dataset object to load data into
 * @param [in]  filename        the name of the Matlab .mat file containing the
 *                                data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid stochastic eye
 *                        data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_eye_dataset_load_matlab(gmcmc_eye_dataset ** dataset, const char * filename) {
  // Allocate the Matlab dataset structure
  matlab_dataset * m;
  if ((m = malloc(sizeof(matlab_dataset))) == NULL)
    GMCMC_ERROR("Failed to allocate Matlab-specific dataset structure", GMCMC_ENOMEM);

  // Open the Matlab data file
  m->file = matOpen(filename, "r");
  if (m->file == NULL) {
    free(m);
    GMCMC_ERROR("Unable to open Matlab data file", GMCMC_EIO);
  }

  // Get pointers to the Data_Mean and Data_Var mxArrays
  if ((m->data_mean = matGetVariable(m->file, "Data_Mean")) == NULL) {
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to find Data_Mean", GMCMC_EINVAL);
  }
  if ((m->data_var = matGetVariable(m->file, "Data_Var")) == NULL) {
    mxDestroyArray(m->data_mean);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to find Data_Var", GMCMC_EINVAL);
  }

  // Check the mxArrays are stored in double precision
  if (!mxIsDouble(m->data_mean) || !mxIsDouble(m->data_var)) {
    mxDestroyArray(m->data_mean);
    mxDestroyArray(m->data_var);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab file is not double precision", GMCMC_EINVAL);
  }

  // Check the dimensions of the data and variance vectors
  if (mxGetN(m->data_mean) < 1 || mxGetN(m->data_var) < 1 ||
      mxGetM(m->data_mean) != mxGetM(m->data_var)) {
    mxDestroyArray(m->data_mean);
    mxDestroyArray(m->data_var);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab data is wrong size", GMCMC_EINVAL);
  }

  // Allocate the dataset structure
  if ((*dataset = malloc(sizeof(gmcmc_eye_dataset))) == NULL) {
    mxDestroyArray(m->data_mean);
    mxDestroyArray(m->data_var);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to allocate dataset", GMCMC_ENOMEM);
  }

  // Set the dataset type and dataset-specific structure
  (*dataset)->type = &type;
  (*dataset)->data = m;

  return 0;
}
