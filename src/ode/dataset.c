#include <gmcmc/gmcmc_ode.h>
#include <stdlib.h>

/**
 * Destroys an ODE dataset.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_ode_dataset_destroy(gmcmc_ode_dataset * dataset) {
  dataset->type->destroy(dataset->data);
  free(dataset);
}
