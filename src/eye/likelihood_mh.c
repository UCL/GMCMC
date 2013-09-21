#include <gmcmc/gmcmc_eye.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include "../mvn.c"
#include "stochastic_eye_sim.c"

/**
 * Stochastic eye model likelihood function using Metropolis-Hastings.
 */
static int eye_likelihood_mh(const void * dataset, const gmcmc_model * model,
                             const double * params, double * likelihood, void ** serdata, size_t * size) {
  (void)serdata;
  (void)size;

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
