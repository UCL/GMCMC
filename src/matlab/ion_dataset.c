#include <gmcmc/gmcmc_matlab.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <gmcmc/gmcmc_errno.h>

#include <mat.h>
#include <matrix.h>

/**
 * An ion channel dataset loaded from Matlab.
 */
typedef struct {
  MATFile * file;       /**< Matlab file pointer */
  mxArray * timepoints; /**< Matlab array containing timepoints */
  mxArray * data;       /**< Matlab array containing data */
} matlab_dataset;

/**
 * Destructor for ion channel Matlab datasets.  Frees the Matlab mxArrays and
 * closes the MATFile pointer.
 *
 * @param [in] data  the Matlab ion channel dataset.
 */
static void destroy(void * data) {
  matlab_dataset * m = (matlab_dataset *)data;
  mxDestroyArray(m->timepoints);
  mxDestroyArray(m->data);
  matClose(m->file);
  free(m);
}

/**
 * Get a pointer to the timepoints from a Matlab ion channel dataset.
 *
 * @param [in] data  the Matlab ion channel dataset
 *
 * @return a pointer to the timepoints or NULL if the mxArray contains no real
 *           data.
 */
static const double * timepoints(const void * data) {
  matlab_dataset * m = (matlab_dataset *)data;
  double * ts = mxGetPr(m->timepoints);
  if (ts == NULL)
    GMCMC_ERROR_VAL("timepoints contains no real data", GMCMC_EIO, NULL);
  return ts;
}

/**
 * Gets a pointer to a data vector from a Matlab ion channel dataset.
 *
 * @param [in] data  the Matlab ion channel dataset
 * @param [in] i     the index of the data vector to return
 *
 * @return a pointer to a data vector or NULL if i is out of range or the
 *           mxArray contains no real data.
 */
static const double * data(const void * data, size_t i) {
  matlab_dataset * m = (matlab_dataset *)data;
  if (i >= mxGetN(m->data))
    GMCMC_ERROR_VAL("index is out of range", GMCMC_EINVAL, NULL);
  double * ys = mxGetPr(m->data);
  if (ys == NULL)
    GMCMC_ERROR_VAL("data contains no real data", GMCMC_EIO, NULL);
  return &ys[i * mxGetM(m->data)];
}

/**
 * Gets the number of timepoints in the dataset.
 *
 * @return the number of timepoints.
 */
static size_t m(const void * data) {
  matlab_dataset * m = (matlab_dataset *)data;
  return mxGetM(m->timepoints);
}

/**
 * Gets the number of data vectors in the dataset.
 *
 * @return the number of data vectors.
 */
static size_t n(const void * data) {
  matlab_dataset * m = (matlab_dataset *)data;
  return mxGetN(m->data);
}

/**
 * Ion channel Matlab dataset type.
 */
static const gmcmc_dataset_type type = { destroy, timepoints, data,
                                             NULL, m, n };

/**
 * Loads an ion channel dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "TimePoints" containing strictly increasing
 * timepoints and a vector of data points named "Data".
 * The dimensionality of the timepoints must match that of the data.
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the Matlab .mat file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid ion channel
 *                        data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_dataset_create_matlab_ion(gmcmc_dataset ** dataset, const char * filename) {
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

  // Get pointers to the TimePoints and Data mxArrays
  if ((m->timepoints = matGetVariable(m->file, "TimePoints")) == NULL) {
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to find timepoints", GMCMC_EINVAL);
  }
  if ((m->data = matGetVariable(m->file, "Data")) == NULL) {
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to find data", GMCMC_EINVAL);
  }

  // Check the mxArrays are stored in double precision
  if (!mxIsDouble(m->data) || !mxIsDouble(m->timepoints)) {
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab file is not double precision", GMCMC_EINVAL);
  }

  // Check the dimensions of the timepoints and data vectors
  if (mxGetN(m->data) < 1 || mxGetN(m->timepoints) < 1 ||
      mxGetM(m->data) != mxGetM(m->timepoints)) {
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab data is wrong size", GMCMC_EINVAL);
  }

  // Allocate the dataset structure
  if ((*dataset = malloc(sizeof(gmcmc_dataset))) == NULL) {
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to allocate dataset", GMCMC_ENOMEM);
  }

  // Set the dataset type and dataset-specific structure
  (*dataset)->type = &type;
  (*dataset)->data = m;

  return 0;
}
