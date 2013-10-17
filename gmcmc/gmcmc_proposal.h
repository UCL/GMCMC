#ifndef GMCMC_PROPOSAL_H
#define GMCMC_PROPOSAL_H

#include <stddef.h>

/**
 * Calculates the proposal mean vector and covariance matrix based on the
 * likelihood.
 *
 * @param [in]  n            size of the parameter vector, mean vector and
 *                             covariance matrix (n by n)
 * @param [in]  params       parameter vector
 * @param [in]  likelihood   likelihood value
 * @param [in]  temperature  chain temperature
 * @param [in]  stepsize     parameter step size
 * @param [in]  geometry     geometry data output from the likelihood function
 * @param [out] mean         mean vector
 * @param [out] covariance   covariance matrix
 * @param [in]  ldc          leading dimension of the covariance matrix
 *
 * @return 0 on success,
 *         greater than zero on fatal error,
 *         less than zero on non-fatal error.
 */
typedef int (*gmcmc_proposal_function)(size_t, const double *, double, double,
                                       double, const void *,
                                       double *, double *, size_t);

/**
 * Proposal function using Metropolis-Hastings.
 */
extern const gmcmc_proposal_function gmcmc_proposal_mh;

/**
 * Proposal function using Simplified M-MALA.
 */
extern const gmcmc_proposal_function gmcmc_proposal_simp_mmala;

/**
 * Proposal function using truncated Simplified M-MALA.
 */
extern const gmcmc_proposal_function gmcmc_proposal_simp_mmala_trunc;

#endif /* GMCMC_PROPOSAL_H */
