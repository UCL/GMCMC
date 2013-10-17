#ifndef GMCMC_LIKELIHOOD_H
#define GMCMC_LIKELIHOOD_H

#include <gmcmc/gmcmc_model.h>

/**
 * Calculates the likelihood of the data given the model and parameters.
 *
 * @param [in]  dataset     dataset
 * @param [in]  model       model to evaluate
 * @param [in]  n           number of parameters in the current block
 * @param [in]  block       indices of the parameters in the current block (may
 *                            be NULL if there is no blocking)
 * @param [in]  params      current parameter values to evaluate the model
 * @param [out] likelihood  likelihood value
 * @param [out] geometry    geometry for the current parameter block (may be
 *                            NULL if no geometry is required by the current
 *                            stage of the algorithm)
 *
 * @return 0 on success,
 *         greater than zero on fatal error,
 *         less than zero on non-fatal error.
 */
typedef int (*gmcmc_likelihood_function)(const void *, const gmcmc_model *,
                                         size_t, const size_t *, const double *,
                                         double *, void **);

#endif /* GMCMC_LIKELIHOOD_H */
