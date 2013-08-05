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
  void (*destroy)(void *);                      /**< Destroy dataset-specific
                                                     data structures */
  const double * (*t)(const void *);            /**< Get time points */
  const double * (*y)(const void *, size_t);    /**< Get data series */
  const void * (*aux)(const void *);            /**< Get auxiliary data vector */
                                                /*     (may be NULL) */
  size_t (*m)(const void *);                    /**< Get number of time points */
  size_t (*n)(const void *);                    /**< Get number of data series */
} gmcmc_dataset_type;

/**
 * A Geometric MCMC dataset has an array of timepoints t and one or more arrays
 * of data points y(t).  There are m timepoints and n arrays of m data points.
 *
 * For some datasets there is also an auxiliary data vector.
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
 * Gets a pointer to the timepoints t.
 *
 * @param [in] dataset  the dataset
 *
 * @return a pointer to the time points.
 */
static inline const double * gmcmc_dataset_get_timepoints(const gmcmc_dataset * dataset) {
  return dataset->type->t(dataset->data);
}

/**
 * Gets a pointer to a data vector y_i(t).
 *
 * @param [in] dataset  the dataset
 * @param [in] i        the index of the data vector
 *
 * @return a pointer to y_i(t), or NULL if i is out of range.
 */
static inline const double * gmcmc_dataset_get_data(const gmcmc_dataset * dataset, size_t i) {
  return dataset->type->y(dataset->data, i);
}

/**
 * Gets the number of timepoints t.
 *
 * @param [in] dataset  the dataset
 *
 * @return the number of timepoints.
 */
static inline size_t gmcmc_dataset_get_num_timepoints(const gmcmc_dataset * dataset) {
  return dataset->type->m(dataset->data);
}

/**
 * Gets the number of data vectors y.
 *
 * @param [in] dataset  the dataset
 *
 * @return the number of data vectors.
 */
static inline size_t gmcmc_dataset_get_num_series(const gmcmc_dataset * dataset) {
  return dataset->type->n(dataset->data);
}

/**
 * Gets a pointer to any auxiliary data in the dataset.
 *
 * @param [in] dataset  the dataset.
 *
 * @return a pointer to the auxiliary data.
 */
static inline const void * gmcmc_dataset_get_auxdata(const gmcmc_dataset * dataset) {
  return (dataset->type->aux == NULL) ? NULL : dataset->type->aux(dataset->data);
}

#endif  /* GMCMC_DATASET_H */
