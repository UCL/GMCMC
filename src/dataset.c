/*
 * gmcmc_dataset.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#include <gmcmc/gmcmc_dataset.h>
#include <stdlib.h>

/**
 * Destroys a dataset, freeing any memory used to store the data.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_dataset_destroy(gmcmc_dataset * dataset) {
  // If the type has a specific destructor defined for the dataset-specific data
  // structures, call it, else call the "default" destructor (free).
  if (dataset->type->destroy != NULL)
    dataset->type->destroy(dataset->data);
  else
    free(dataset->data);
  free(dataset);
}
