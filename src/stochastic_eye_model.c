#include <gmcmc/gmcmc_stochastic_eye_model.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mvn.c"

/**
 * Stochastic eye model-specific data.
 *
 * A stochastic eye model has an array of vectors each containing times in
 * milliseconds at which a photon is detected.
 */
struct gmcmc_stochastic_eye_model {
  unsigned int ** stimuli;
  size_t * num_stimuli;
  size_t num_photoreceptors;
  const gmcmc_prng64 * rng;
  size_t offset, length;
  size_t num_bump_approx_timepoints;
};

static int stochastic_eye_sim(const gmcmc_stochastic_eye_model *,
                              const double *, double *, size_t);

/**
 * Stochastic eye model proposal function using Metropolis-Hastings.
 */
static int stochastic_eye_proposal_mh(size_t n, const double * params, double likelihood,
                                      double temperature, double stepsize, const void * serdata,
                                      double * mean, double * covariance, size_t ldc) {
  (void)likelihood;
  (void)serdata;
  (void)temperature;

  // Proposal_Mean    = Chain.Paras(Chain.CurrentBlock);
  memcpy(mean, params, n * sizeof(double));

  // Proposal_Covariance = eye(Chain.CurrentBlockSize)*(Chain.StepSize(Chain.CurrentBlockNum)^2);
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      covariance[j * ldc + i] = 0.0;
    covariance[j * ldc + j] = stepsize * stepsize;
    for (size_t i = j + 1; i < n; i++)
      covariance[j * ldc + i] = 0.0;
  }

  return 0;
}
const gmcmc_proposal_function gmcmc_stochastic_eye_proposal_mh = &stochastic_eye_proposal_mh;

/**
 * Stochastic eye model likelihood function using Metropolis-Hastings.
 */
static int stochastic_eye_likelihood_mh(const gmcmc_dataset * dataset, const gmcmc_model * model,
                                        const double * params,
                                        double * likelihood, void ** serdata, size_t * size) {
  (void)serdata;
  (void)size;
  // Initialise error status
  int error = 0;

  // Initialise log likelihood to negative infinity so that it is set on
  // non-fatal errors
  *likelihood = -INFINITY;

  // Get the model specific data
  gmcmc_stochastic_eye_model * eye_model = (gmcmc_stochastic_eye_model *)gmcmc_model_get_modelspecific(model);

  size_t num_timepoints = gmcmc_dataset_get_num_timepoints(dataset);
  double * macro_c;
  if ((macro_c = malloc(num_timepoints * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate macro_c", GMCMC_ENOMEM);

  if ((error = stochastic_eye_sim(eye_model, params, macro_c, num_timepoints)) != 0) {
    free(macro_c);
    GMCMC_ERROR("Failed to simulate data", error);
  }

  const double * data = gmcmc_dataset_get_data(dataset, 0);
  const double * noisevar = gmcmc_dataset_get_auxdata(dataset);

  if ((error = gmcmc_mvn_logpdfv(eye_model->length, &macro_c[eye_model->offset], &data[eye_model->offset], &noisevar[eye_model->offset], likelihood)) != 0) {
    free(macro_c);
    GMCMC_ERROR("Failed to calculated likelihood", error);
  }

  free(macro_c);

  return error;
}
const gmcmc_likelihood_function gmcmc_stochastic_eye_likelihood_mh = &stochastic_eye_likelihood_mh;

/**
 * Creates a stochastic eye model-specific data object.
 *
 * @param [out] eye_model           the stochastic eye model
 * @param [in]  stimuli             the integer times in milliseconds that a
 *                                    photon is detected by a photoreceptor
 * @param [in]  num_stimuli         the number of times in each stimuli vector
 * @param [in]  num_photoreceptors  the number of photoreceptors
 * @param [in]  rng                 an RNG to use for the stochastic simulation
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if stimuli or num_stimuli is NULL, or
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_stochastic_eye_model_create(gmcmc_stochastic_eye_model ** eye_model,
                                      unsigned int ** stimuli, size_t * num_stimuli,
                                      size_t num_photoreceptors, const gmcmc_prng64 * rng) {
  if (stimuli == NULL)
    GMCMC_ERROR("stimuli is NULL", GMCMC_EINVAL);
  else if (num_stimuli == NULL)
    GMCMC_ERROR("num_stimuli is NULL", GMCMC_EINVAL);

  if ((*eye_model = malloc(sizeof(gmcmc_stochastic_eye_model))) == NULL)
    GMCMC_ERROR("Unable to allocate Stochastic Eye model", GMCMC_ENOMEM);

  (*eye_model)->rng = rng;
  (*eye_model)->num_photoreceptors = num_photoreceptors;
  (*eye_model)->num_bump_approx_timepoints = 1001;

  if (((*eye_model)->num_stimuli = malloc(num_photoreceptors * sizeof(size_t))) == NULL) {
    free(*eye_model);
    GMCMC_ERROR("Unable to allocate num_stimuli", GMCMC_ENOMEM);
  }
  if (((*eye_model)->stimuli = malloc(num_photoreceptors * sizeof(unsigned int *))) == NULL) {
    free((*eye_model)->num_stimuli);
    free(*eye_model);
    GMCMC_ERROR("Unable to allocate stimuli", GMCMC_ENOMEM);
  }
  memcpy((*eye_model)->num_stimuli, num_stimuli, num_photoreceptors * sizeof(size_t));

  for (size_t i = 0; i < num_photoreceptors; i++) {
    if (((*eye_model)->stimuli[i] = malloc(num_stimuli[i] * sizeof(unsigned int))) == NULL) {
      for (size_t j = 0; j < i; j++)
        free((*eye_model)->stimuli[j]);
      free((*eye_model)->num_stimuli);
      free(*eye_model);
      GMCMC_ERROR("Unable to allocate stimuli vector", GMCMC_ENOMEM);
    }
    memcpy((*eye_model)->stimuli[i], stimuli[i], num_stimuli[i] * sizeof(unsigned int));
  }

  return 0;
}

/**
 * Destroys the stochastic eye model-specific data.
 *
 * @param [in] eye_model  the stochastic eye model-specific data object to
 *                        destroy
 */
void gmcmc_stochastic_eye_model_destroy(gmcmc_stochastic_eye_model * eye_model) {
  if (eye_model != NULL) {
    for (size_t i = 0; i < eye_model->num_photoreceptors; i++)
      free(eye_model->stimuli[i]);
    free(eye_model->num_stimuli);
    free(eye_model);
  }
}

/**
 * Set the number of timepoints to use when approximating the photoreceptor
 * "bump".
 *
 * @param [in] eye_model                   the model
 * @param [in] num_bump_approx_timepoints  the number of timepoints
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if the number of timepoints is zero.
 */
int gmcmc_stochastic_eye_set_num_bump_approx_timepoints(gmcmc_stochastic_eye_model * eye_model,
                                                         size_t num_bump_approx_timepoints) {
  if (num_bump_approx_timepoints == 0)
    GMCMC_ERROR("Number of bump approximation timepoints is zero", GMCMC_EINVAL);
  eye_model->num_bump_approx_timepoints = num_bump_approx_timepoints;
  return 0;
}

static inline size_t min(size_t a, size_t b) { return (a < b) ? a : b; }

static int stochastic_eye_sim(const gmcmc_stochastic_eye_model * eye_model,
                              const double * params, double * macro_c, size_t num_timepoints) {
  // 3 shape parameters (A, p, tao)
  double a   = params[0];
  double p   = params[1];
  double tao = params[2];

  // 2 latency parameters (mean and variance)
  double mean_lat = params[3];
  double var_lat  = params[4];

  // 2 refract parameters (mean and variance)
  double mean_ref = params[5];
  double var_ref  = params[6];

  double * bump_approx;
  if ((bump_approx = malloc(eye_model->num_bump_approx_timepoints * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate bump approximation", GMCMC_ENOMEM);

  double i_fac = a * exp(p) / pow(p, p);
  int bump_duration = -1;
  bool bump_set = true;
  for (int x = eye_model->num_bump_approx_timepoints - 1; x >= 0; x--) {
    bump_approx[x] = i_fac * pow(x / tao, p) * exp(-x / tao);
    if (bump_approx[x] < 0.025 && bump_set)
      bump_duration = x;
    else
      bump_set = false;
  }

  if (bump_duration == -1)
    return 1;

  for (size_t i = 0; i < eye_model->num_photoreceptors; i++) {
    unsigned int lrefrac = 0;
    for (size_t j = 0; j < eye_model->num_stimuli[i]; j++) {
      unsigned int stimuli = eye_model->stimuli[i][j];
      if (stimuli > lrefrac) {
        unsigned int latency = floor(exp(log(mean_lat) + log(var_lat) * gmcmc_randn(eye_model->rng)));
        unsigned int refract = floor(exp(log(mean_ref) + log(var_ref) * gmcmc_randn(eye_model->rng)));

        for (size_t k = 0; k < eye_model->num_bump_approx_timepoints && k < num_timepoints - stimuli - latency; k++)
          macro_c[stimuli + latency + k] += bump_approx[k];

        lrefrac = min(stimuli + latency + bump_duration + refract, num_timepoints);
      }
    }
  }

  return 0;
}
