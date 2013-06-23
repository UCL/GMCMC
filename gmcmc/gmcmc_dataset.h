/*
 * gmcmc_dataset.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_DATASET_H
#define GMCMC_DATASET_H

#include <stddef.h>

/**
 * Dataset type.
 */
typedef struct {
  void (*destroy)(void *);              /**< Destroy dataset-specific data structures */
  double (*x)(const void *, size_t);    /**< Get time value */
  double (*y)(const void *, size_t);    /**< Get data value */
  size_t (*n)(const void *);            /**< Get number of time points */
} gmcmc_dataset_type;

/**
 * A dataset.
 */
typedef struct {
  const gmcmc_dataset_type * type;      /**< Dataset type */
  void * data;                          /**< Dataset-specific data structures */
} gmcmc_dataset;

/**
 * Destroys a dataset, freeing any memory used to store the data.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_dataset_destroy(gmcmc_dataset *);

/**
 * Gets an x (time) value.
 *
 * @param [in] dataset  the dataset
 * @param [in] i        the index of the value
 *
 * @return a time value.
 */
static inline double gmcmc_dataset_x(const gmcmc_dataset * dataset, size_t i) {
  return dataset->type->x(dataset->data, i);
}

/**
 * Gets a y (data) value.
 *
 * @param [in] dataset  the dataset
 * @param [in] i        the index of the value
 *
 * @return a data value.
 */
static inline double gmcmc_dataset_y(const gmcmc_dataset * dataset, size_t i) {
  return dataset->type->y(dataset->data, i);
}

/**
 * Gets the number of (x,y) data points.
 *
 * @param [in] dataset  the dataset
 *
 * @return the size of the dataset.
 */
static inline size_t gmcmc_dataset_size(const gmcmc_dataset * dataset) {
  return dataset->type->n(dataset->data);
}

/**
 * Loads a dataset from a Matlab file.  The file must contain real-valued column
 * vectors of data named TimePoints and Data for the x and y points respectively.
 * Both vectors must be the same size.
 *
 * @param [out] dataset   the dataset object to load data into
 * @param [in]  filename  the name of the Matlab .m file containing the data
 *
 * @return 0 on success.
 */
int gmcmc_dataset_create_matlab(gmcmc_dataset **, const char *);

#endif  /* GMCMC_DATASET_H */
