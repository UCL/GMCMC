#include <gmcmc/gmcmc_eye.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include "../mvn.c"
#include "stochastic_eye_sim.c"

/**
 * Stochastic eye model likelihood function using Metropolis-Hastings.
 *
 * @param [in]  dataset     dataset
 * @param [in]  model       model to evaluate
 * @param [in]  params      current parameter values to evaluate the model
 * @param [in]  n           number of parameters in the current block
 * @param [in]  block       indices of the parameters in the current block (may
 *                            be NULL if there is no blocking)
 * @param [out] likelihood  likelihood value
 * @param [out] geometry    geometry for the current parameter block (may be
 *                            NULL if no geometry is required by the current
 *                            stage of the algorithm)
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate temporary
 *                        variables,
 *         GMCMC_ELINAL if there was an unrecoverable error in an external
 *                        linear algebra routine.
 */
static int eye_likelihood_mh(const void * dataset, const gmcmc_model * model,
                             const double * params, size_t n, const size_t * block,
                             double * likelihood, void ** geometry) {
  // Metropolis-Hastings likelihood functions don't calculate geometry
  (void)geometry;
  (void)n;
  (void)block;

  // Initialise log likelihood to negative infinity so that it is set on
  // non-fatal errors
  *likelihood = -INFINITY;

  // Get the model specific data
  const gmcmc_eye_model * eye_model = (const gmcmc_eye_model *)gmcmc_model_get_modelspecific(model);
  const gmcmc_eye_dataset * eye_dataset = (const gmcmc_eye_dataset *)dataset;

  size_t num_timepoints = gmcmc_eye_dataset_num_timepoints(eye_dataset);
  size_t offset = gmcmc_eye_model_offset(eye_model);    // First timepoint to compare
  size_t length = gmcmc_eye_model_length(eye_model);    // Last timepoint to compare

  if (offset + length > num_timepoints)
    GMCMC_ERROR("Number of timepoints to compare is greater than number of timepoints in dataset", GMCMC_EINVAL);

  double * macro_c;
  if ((macro_c = malloc(num_timepoints * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate macro_c", GMCMC_ENOMEM);

  // Simulate a "bump" over num_timepoints in macro_c
  int error;
  if ((error = stochastic_eye_sim(eye_model, params, macro_c, num_timepoints)) != 0) {
    free(macro_c);
    if (error != GMCMC_EINVAL)
      GMCMC_ERROR("Failed to simulate bump approximation", error);
    GMCMC_WARNING("Invalid parameter values", error);
  }

  // Compare the simulated data to the real data
  const double * data = gmcmc_eye_dataset_data(dataset);
  const double * noisevar = gmcmc_eye_dataset_noisevar(dataset);
  if ((error = gmcmc_mvn_logpdfv(length, &macro_c[offset], &data[offset], &noisevar[offset], likelihood)) != 0) {
    free(macro_c);
    GMCMC_ERROR("Failed to calculated likelihood", error);
  }

  free(macro_c);

  return error;
}
const gmcmc_likelihood_function gmcmc_eye_likelihood_mh = &eye_likelihood_mh;
