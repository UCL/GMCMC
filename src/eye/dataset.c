#include <gmcmc/gmcmc_eye.h>
#include <stdlib.h>

/**
 * Destroys a stochastic eye dataset.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_eye_dataset_destroy(gmcmc_eye_dataset * dataset) {
  dataset->type->destroy(dataset->data);
  free(dataset);
}
