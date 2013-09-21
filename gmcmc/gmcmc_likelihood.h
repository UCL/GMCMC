#ifndef GMCMC_LIKELIHOOD_H
#define GMCMC_LIKELIHOOD_H

#include <gmcmc/gmcmc_model.h>

/**
 * Calculates the likelihood of the data given the model and parameters.
 *
 * @param [in]  dataset     the dataset
 * @param [in]  model       the model to evaluate
 * @param [in]  params      the current parameter values to evaluate the model
 * @param [in]  n           the number of parameters in the model
 * @param [out] likelihood  the log likelihood
 * @param [out] serdata     serialised data to be passed to the proposal function
 * @param [out] size        size of serialised data object, in bytes
 *
 * @return 0 on success,
 *         greater than zero on fatal error,
 *         less than zero on non-fatal error.
 */
typedef int (*gmcmc_likelihood_function)(const void *, const gmcmc_model *, const double *,
                                         double *, void **, size_t *);

#endif /** GMCMC_LIKELIHOOD_H */
