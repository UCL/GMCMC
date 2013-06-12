/*
 * gmcmc_dataset.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_DATASET_H
#define GMCMC_DATASET_H

/**
 * A dataset generated from the system.
 */
typedef struct gmcmc_dataset gmcmc_dataset;

/**
 * Loads a dataset from a Matlab file.  The file must contain real-valued column
 * vectors of data named TimePoints and Data for the x and y points respectively.
 * Both vectors must be the same size.
 *
 * @param dataset   the dataset object to load data into
 * @param filename  the name of the Matlab .m file containing the data
 *
 * @return 0 on success.
 */
int gmcmc_dataset_load_matlab(gmcmc_dataset **, const char *);

/**
 * Destroys a dataset, freeing any memory used to store the data.
 *
 * @param dataset  the dataset to destroy.
 */
void gmcmc_dataset_destroy(gmcmc_dataset *);

/**
 * Gets a pointer to the x (time) values.
 *
 * @param dataset  the dataset
 *
 * @return a pointer to the time values.
 */
const double * gmcmc_dataset_xs(const gmcmc_dataset *);

/**
 * Gets a pointer to the y (data) values.
 *
 * @param dataset  the dataset
 *
 * @return a pointer to the data values.
 */
const double * gmcmc_dataset_ys(const gmcmc_dataset *);

/**
 * Gets the number of (x,y) data points.
 *
 * @param dataset  the dataset
 *
 * @return the size of the dataset.
 */
size_t gmcmc_dataset_size(const gmcmc_dataset *);

#endif  /* GMCMC_DATASET_H */
