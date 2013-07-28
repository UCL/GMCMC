/*
 * gmcmc_dataset.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#include <gmcmc/gmcmc_dataset.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>
#include <mat.h>
#include <matrix.h>

/**
 * An ion channel dataset loaded from Matlab.
 */
typedef struct {
  MATFile * file;       /**< Matlab file pointer */
  mxArray * timepoints; /**< Matlab array containing timepoints */
  mxArray * data;       /**< Matlab array containing data */
} matlab_ion_dataset;

/**
 * Destructor for ion channel Matlab datasets.  Frees the Matlab mxArrays and
 * closes the MATFile pointer.
 *
 * @param [in] data  the Matlab ion channel dataset.
 */
static void destroy_ion(void * data) {
  matlab_ion_dataset * m = (matlab_ion_dataset *)data;
  mxDestroyArray(m->timepoints);
  mxDestroyArray(m->data);
  matClose(m->file);
  free(m);
}

/**
 * An ODE dataset loaded from Matlab.
 */
typedef struct {
  MATFile * file;       /**< Matlab file pointer */
  mxArray * timepoints; /**< Matlab array containing timepoints */
  mxArray * data;       /**< Matlab array containing data vectors */
  mxArray * noisecov;   /**< Matlab array containing noise covariance */
} matlab_ode_dataset;

/**
 * Destructor for ODE Matlab datasets.  Frees the Matlab mxArrays and closes the
 * MATFile pointer.
 *
 * @param [in] data  the Matlab ODE dataset.
 */
static void destroy_ode(void * data) {
  matlab_ode_dataset * m = (matlab_ode_dataset *)data;
  mxDestroyArray(m->timepoints);
  mxDestroyArray(m->data);
  mxDestroyArray(m->noisecov);
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
static const double * ion_timepoints(const void * data) {
  matlab_ion_dataset * m = (matlab_ion_dataset *)data;
  double * ts = mxGetPr(m->timepoints);
  if (ts == NULL)
    GMCMC_ERROR_VAL("timepoints contains no real data", GMCMC_EIO, NULL);
  return ts;
}

/**
 * Get a pointer to the timepoints from a Matlab ODE dataset.
 *
 * @param [in] data  the Matlab ODE dataset
 *
 * @return a pointer to the timepoints or NULL if the mxArray contains no real
 *           data.
 */
static const double * ode_timepoints(const void * data) {
  matlab_ode_dataset * m = (matlab_ode_dataset *)data;
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
static const double * ion_data(const void * data, size_t i) {
  matlab_ion_dataset * m = (matlab_ion_dataset *)data;
  if (i >= mxGetN(m->data))
    GMCMC_ERROR_VAL("index is out of range", GMCMC_EINVAL, NULL);
  double * ys = mxGetPr(m->data);
  if (ys == NULL)
    GMCMC_ERROR_VAL("data contains no real data", GMCMC_EIO, NULL);
  return &ys[i * mxGetM(m->data)];
}

/**
 * Gets a pointer to a data vector from a Matlab ODE dataset.
 *
 * @param [in] data  the Matlab ODE dataset
 * @param [in] i     the index of the data vector to return
 *
 * @return a pointer to a data vector or NULL if i is out of range or the
 *           mxArray contains no real data.
 */
static const double * ode_data(const void * data, size_t i) {
  matlab_ode_dataset * m = (matlab_ode_dataset *)data;
  if (i >= mxGetN(m->data))
    GMCMC_ERROR_VAL("index is out of range", GMCMC_EINVAL, NULL);
  double * ys = mxGetPr(m->data);
  if (ys == NULL)
    GMCMC_ERROR_VAL("data contains no real data", GMCMC_EIO, NULL);
  return &ys[i * mxGetM(m->data)];
}

/**
 * Gets a pointer to the noise covariance vector from a Matlab ODE dataset.
 *
 * @param [in] data  the Matlab ODE dataset
 *
 * @return a pointer to the noise covariance vector or NULL if the mxArray
 *           contains no real data.
 */
static const void * ode_noisecov(const void * data) {
  matlab_ode_dataset * m = (matlab_ode_dataset *)data;
  void * a = mxGetData(m->noisecov);
  if (a == NULL)
    GMCMC_ERROR_VAL("noisecov contains no real data", GMCMC_EIO, NULL);
  return a;
}

/**
 * Gets the number of timepoints in the dataset.
 *
 * @return the number of timepoints.
 */
static size_t ion_m(const void * data) {
  matlab_ion_dataset * m = (matlab_ion_dataset *)data;
  return mxGetM(m->timepoints);
}

/**
 * Gets the number of timepoints in the dataset.
 *
 * @return the number of timepoints.
 */
static size_t ode_m(const void * data) {
  matlab_ode_dataset * m = (matlab_ode_dataset *)data;
  return mxGetM(m->timepoints);
}

/**
 * Gets the number of data vectors in the dataset.
 *
 * @return the number of data vectors.
 */
static size_t ion_n(const void * data) {
  matlab_ion_dataset * m = (matlab_ion_dataset *)data;
  return mxGetN(m->data);
}

/**
 * Gets the number of data vectors in the dataset.
 *
 * @return the number of data vectors.
 */
static size_t ode_n(const void * data) {
  matlab_ode_dataset * m = (matlab_ode_dataset *)data;
  return mxGetN(m->data);
}

/**
 * Ion channel Matlab dataset type.
 */
static const gmcmc_dataset_type ion_type = { destroy_ion, ion_timepoints, ion_data,
                                             NULL, ion_m, ion_n };

/**
 * ODE Matlab dataset type.
 */
static const gmcmc_dataset_type ode_type = { destroy_ode, ode_timepoints, ode_data,
                                             ode_noisecov, ode_m, ode_n };

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
  matlab_ion_dataset * m;
  if ((m = malloc(sizeof(matlab_ion_dataset))) == NULL)
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
  (*dataset)->type = &ion_type;
  (*dataset)->data = m;

  return 0;
}

/**
 * Loads an ODE dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "TimePoints" containing strictly increasing
 * timepoints, a matrix of data points named "Data" and a column vector of noise
 * covariances names "NoiseVariance".
 * The length of the timepoints vector must match the length of the noise
 * covariances and the number of rows in the data.
 * The noise covariances will be available via gmcmc_dataset_get_auxdata.
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the Matlab .mat file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid ODE data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_dataset_create_matlab_ode(gmcmc_dataset ** dataset, const char * filename) {
  // Allocate the Matlab dataset structure
  matlab_ode_dataset * m;
  if ((m = malloc(sizeof(matlab_ode_dataset))) == NULL)
    GMCMC_ERROR("Failed to allocate Matlab-specific dataset structure", GMCMC_ENOMEM);

  // Open the Matlab data file
  m->file = matOpen(filename, "r");
  if (m->file == NULL) {
    free(m);
    GMCMC_ERROR("Unable to open Matlab data file", GMCMC_EIO);
  }

  // Get pointers to the TimePoints, Data and NoiseCov mxArrays
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
  if ((m->noisecov = matGetVariable(m->file, "NoiseVariance")) == NULL) {
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to find noise covariance", GMCMC_EINVAL);
  }

  // Check the mxArrays are stored in double precision
  if (!mxIsDouble(m->noisecov) || !mxIsDouble(m->data) || !mxIsDouble(m->timepoints)) {
    mxDestroyArray(m->noisecov);
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab file is not double precision", GMCMC_EIO);
  }

  // Check the dimensions of the data matrix, noise covariance and timepoint vectors
  if (mxGetM(m->noisecov) < 1 || mxGetN(m->timepoints) < 1 ||
      mxGetM(m->data) != mxGetM(m->timepoints) ||
      mxGetN(m->noisecov) != mxGetN(m->data)) {
    mxDestroyArray(m->noisecov);
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab data is wrong size", GMCMC_EIO);
  }

  // Allocate the dataset structure
  if ((*dataset = malloc(sizeof(gmcmc_dataset))) == NULL) {
    mxDestroyArray(m->noisecov);
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to allocate dataset", GMCMC_ENOMEM);
  }

  // Set the dataset type and dataset-specific structure
  (*dataset)->type = &ode_type;
  (*dataset)->data = m;

  return 0;
}
