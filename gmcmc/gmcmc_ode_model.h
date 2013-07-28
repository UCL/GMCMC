#ifndef GMCMC_ODE_MODEL_H
#define GMCMC_ODE_MODEL_H

#include <gmcmc/gmcmc_model.h>

/**
 * ODE model-specific data.
 *
 * In addition to data common to all models, ODE models have
 */
typedef struct gmcmc_ode_model gmcmc_ode_model;

/**
 * ODE model proposal function using Metropolis-Hastings.
 */
extern const gmcmc_proposal_function gmcmc_ode_proposal_mh;

/**
 * ODE model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_ode_likelihood_mh;

/**
 * ODE model proposal function using Simplified M-MALA.
 */
extern const gmcmc_proposal_function gmcmc_ode_proposal_simp_mmala;

/**
 * ODE model likelihood function using Simplified M-MALA.
 */
extern const gmcmc_likelihood_function gmcmc_ode_likelihood_simp_mmala;

/**
 * Creates an ODE model-specific data object.
 *
 * @param [out] ode_model   the ODE model
 * @param [in]  observed    the number of observed species in the model
 * @param [in]  unobserved  the number of unobserved species in the model
 * @param [in]  solve       function to solve system of ODEs
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if solve is NULL,
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_ode_model_create(gmcmc_ode_model **, unsigned int, unsigned int,
                           int (*)(size_t, const double *, const double *,
                                   double *, size_t));

/**
 * Destroys the ODE model-specific data.
 *
 * @param [in] ode_model  the ODE model-specific data object to destroy
 */
void gmcmc_ode_model_destroy(gmcmc_ode_model *);

#endif /* GMCMC_ODE_MODEL_H */
