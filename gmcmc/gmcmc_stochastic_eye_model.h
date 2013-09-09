#ifndef GMCMC_STOCHASTIC_EYE_MODEL_H
#define GMCMC_STOCHASTIC_EYE_MODEL_H

#include <gmcmc/gmcmc_model.h>

/**
 * Stochastic eye model-specific data.
 *
 * A stochastic eye model has an array of vectors each containing times in
 * milliseconds at which a photon is detected.
 */
typedef struct gmcmc_stochastic_eye_model gmcmc_stochastic_eye_model;

/**
 * Stochastic eye model proposal function using Metropolis-Hastings.
 */
extern const gmcmc_proposal_function gmcmc_stochastic_eye_proposal_mh;

/**
 * Stochastic eye model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_stochastic_eye_likelihood_mh;

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
int gmcmc_stochastic_eye_model_create(gmcmc_stochastic_eye_model **,
                                      unsigned int **, size_t *, size_t,
                                      const gmcmc_prng64 *);

/**
 * Destroys the stochastic eye model-specific data.
 *
 * @param [in] eye_model  the stochastic eye model-specific data object to
 *                        destroy
 */
void gmcmc_stochastic_eye_model_destroy(gmcmc_stochastic_eye_model *);

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
int gmcmc_stochastic_eye_set_num_bump_approx_timepoints(gmcmc_stochastic_eye_model *,
                                                         size_t);

#endif
