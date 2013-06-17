#ifndef GMCMC_LIKELIHOOD_H
#define GMCMC_LIKELIHOOD_H

/**
 * Immutable likelihood type.
 */
typedef struct gmcmc_likelihood gmcmc_likelihood;

/**
 * Create a new likelihood object.
 *
 * @param [out] likelihood  the likelihood object to create
 * @param [in]  ll          the log likelihood value
 * @param [in]  specifics   extra values specific to the type of likelihood
 *                            calculation.  These are not copied into the object
 *                            and remain owned by the caller.
 * @param [in]  destroy     destructor for specifics
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to create another
 *                        likelihood object.
 */
int gmcmc_likelihood_create(gmcmc_likelihood **, double, void *, void (*)(void *));

/**
 * Destroys a likelihood object.
 *
 * @param likelihood  the likelihood object to destroy.
 */
void gmcmc_likelihood_destroy(gmcmc_likelihood *);

/**
 * Gets the value of the log likelihood from the likelihood object.
 *
 * @param [in] likelihood  the likelihood object
 *
 * @return the log likelihood value.
 */
double gmcmc_likelihood_log_likelihood(const gmcmc_likelihood *);

/**
 * Gets the pointer to the likelihood specific values from the likelihood object.
 *
 * @param [in] likelihood  the likelihood object
 *
 * @return the pointer to the likelihood specific values.
 */
const void * gmcmc_likelihood_likelihoodspecific(const gmcmc_likelihood *);

#endif
