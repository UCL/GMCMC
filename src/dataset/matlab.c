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
 * A dataset generated from the system.
 */
typedef struct {
  MATFile * file;               /**< Matlab file pointer */
  mxArray * timepoints, * data; /**< Matlab arrays containing time points and data */
} matlab_dataset;

static void destroy(void * data) {
  matlab_dataset * m = (matlab_dataset *)data;
  mxDestroyArray(m->timepoints);
  mxDestroyArray(m->data);
  matClose(m->file);
  free(m);
}

static double x(const void * data, size_t i) {
  matlab_dataset * m = (matlab_dataset *)data;
  if (i >= mxGetM(m->timepoints))
    GMCMC_ERROR_VAL("index is out of range", GMCMC_EINVAL, 0.0);
  double * xs = mxGetData(m->timepoints);
  if (xs == NULL)
    GMCMC_ERROR_VAL("TimePoints contains no real data", GMCMC_EIO, 0.0);
  return xs[i];
}

static double y(const void * data, size_t i) {
  matlab_dataset * m = (matlab_dataset *)data;
  if (i >= mxGetM(m->data))
    GMCMC_ERROR_VAL("index is out of range", GMCMC_EINVAL, 0.0);
  double * ys = mxGetData(m->data);
  if (ys == NULL)
    GMCMC_ERROR_VAL("TimePoints contains no real data", GMCMC_EIO, 0.0);
  return ys[i];
}

static size_t n(const void * data) {
  matlab_dataset * m = (matlab_dataset *)data;
  return mxGetM(m->timepoints);
}

static const gmcmc_dataset_type type = { destroy, x, y, n };

/**
 * Creates a dataset from a Matlab file.  The file must contain real-valued
 * column vectors of data named TimePoints and Data for the x and y points
 * respectively.  Both vectors must be the same size.
 *
 * @param [out] dataset   the dataset object to load data into
 * @param [in]  filename  the name of the Matlab .m file containing the data
 *
 * @return 0 on success,
 *         GMCMC_EIO if there was an error reading the Matlab file,
 *         GMCMC_ENOMEM if there is not enough memory to create the dataset.
 */
int gmcmc_dataset_create_matlab(gmcmc_dataset ** dataset, const char * filename) {
  matlab_dataset * m;
  if ((m = malloc(sizeof(matlab_dataset))) == NULL)
    GMCMC_ERROR("Failed to allocate Matlab-specific dataset structure", GMCMC_ENOMEM);

  m->file = matOpen(filename, "r");
  if (m->file == NULL) {
    free(m);
    GMCMC_ERROR("Unable to open Matlab data file", GMCMC_EIO);
  }

  if ((m->timepoints = matGetVariable(m->file, "TimePoints")) == NULL) {
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to find TimePoints", GMCMC_EIO);
  }
  if ((m->data = matGetVariable(m->file, "Data")) == NULL) {
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to find Data", GMCMC_EIO);
  }

  if (!mxIsDouble(m->data) || !mxIsDouble(m->timepoints)) {
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab file is not double precision", GMCMC_EIO);
  }

  if (mxGetN(m->data) != 1 || mxGetN(m->timepoints) != 1 || mxGetM(m->data) != mxGetM(m->timepoints)) {
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Matlab data is wrong size", GMCMC_EIO);
  }

  if ((*dataset = malloc(sizeof(gmcmc_dataset))) == NULL) {
    mxDestroyArray(m->data);
    mxDestroyArray(m->timepoints);
    matClose(m->file);
    free(m);
    GMCMC_ERROR("Unable to allocate dataset", GMCMC_ENOMEM);
  }

  (*dataset)->type = &type;
  (*dataset)->data = m;

  return 0;
}
