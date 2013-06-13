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
struct gmcmc_dataset {
  double * xs, * ys;    /**< X data, Y data (TimePoints and Data) */
  size_t n;             /**< Number of data points */
};

/**
 * Loads a dataset from a Matlab file.  The file must contain real-valued column
 * vectors of data named TimePoints and Data for the x and y points respectively.
 * Both vectors must be the same size.
 *
 * @param [out] dataset   the dataset object to load data into
 * @param [in]  filename  the name of the Matlab .m file containing the data
 *
 * @return 0 on success,
 *         GMCMC_EIO if there was an error reading the Matlab file,
 *         GMCMC_ENOMEM if there is not enough memory to create the dataset.
 */
int gmcmc_dataset_load_matlab(gmcmc_dataset ** dataset, const char * filename) {
  MATFile * file = matOpen(filename, "r");
  if (file == NULL)
    GMCMC_ERROR("Unable to open Matlab data file", GMCMC_EIO);

  mxArray * timepoints, * data;
  if ((timepoints = matGetVariable(file, "TimePoints")) == NULL) {
    matClose(file);
    GMCMC_ERROR("Unable to find TimePoints", GMCMC_EIO);
  }
  if ((data = matGetVariable(file, "Data")) == NULL) {
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("Unable to find Data", GMCMC_EIO);
  }

  if (!mxIsDouble(data) || !mxIsDouble(timepoints)) {
    mxDestroyArray(data);
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("Matlab file is not double precision", GMCMC_EIO);
  }

  if (mxGetN(data) != 1 || mxGetN(timepoints) != 1 || mxGetM(data) != mxGetM(timepoints)) {
    mxDestroyArray(data);
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("Matlab data is wrong size", GMCMC_EIO);
  }

  double * xs, * ys;
  size_t n;
  if ((xs = mxGetData(timepoints)) == NULL) {
    mxDestroyArray(data);
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("timepoints contains no data", GMCMC_EIO);
  }
  if ((ys = mxGetData(data)) == NULL) {
    mxDestroyArray(data);
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("Data contains no data", GMCMC_EIO);
  }
  n = mxGetM(data);

  *dataset = malloc(sizeof(gmcmc_dataset));
  if (*dataset == NULL) {
    mxDestroyArray(data);
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("Unable to allocate dataset", GMCMC_ENOMEM);
  }

  if (((*dataset)->xs = malloc(n * sizeof(double))) == NULL) {
    free(*dataset);
    mxDestroyArray(data);
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("Unable to allocate timepoints", GMCMC_ENOMEM);
  }

  if (((*dataset)->ys = malloc(n * sizeof(double))) == NULL) {
    free((*dataset)->xs);
    free(*dataset);
    mxDestroyArray(data);
    mxDestroyArray(timepoints);
    matClose(file);
    GMCMC_ERROR("Unable to allocate data", GMCMC_ENOMEM);
  }

  memcpy((*dataset)->xs, xs, n * sizeof(double));
  memcpy((*dataset)->ys, ys, n * sizeof(double));
  (*dataset)->n = n;

  mxDestroyArray(data);
  mxDestroyArray(timepoints);
  matClose(file);

  return 0;
}

/**
 * Destroys a dataset, freeing any memory used to store the data.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_dataset_destroy(gmcmc_dataset * dataset) {
  free(dataset->xs);
  free(dataset->ys);
  free(dataset);
}

/**
 * Gets a pointer to the x (time) values.
 *
 * @param [in] dataset  the dataset
 *
 * @return a pointer to the time values.
 */
const double * gmcmc_dataset_xs(const gmcmc_dataset * dataset) {
  return dataset->xs;
}

/**
 * Gets a pointer to the y (data) values.
 *
 * @param [in] dataset  the dataset
 *
 * @return a pointer to the data values.
 */
const double * gmcmc_dataset_ys(const gmcmc_dataset * dataset) {
  return dataset->ys;
}

/**
 * Gets the number of (x,y) data points.
 *
 * @param [in] dataset  the dataset
 *
 * @return the size of the dataset.
 */
size_t gmcmc_dataset_size(const gmcmc_dataset * dataset) {
  return dataset->n;
}
