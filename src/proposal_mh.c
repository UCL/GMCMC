#include <gmcmc/gmcmc_proposal.h>
#include <string.h>

/**
 * Proposal function using Metropolis-Hastings.
 * likelihood.
 *
 * @param [in]  n            size of the mean vector and covariance matrix
 *                             (n by n) and number of parameters in the current
 *                             block
 * @param [in]  blocks       the indices of the parameters in the current block
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
static int proposal_mh(size_t n, const size_t * blocks, const double * params,
                       double likelihood, double temperature, double stepsize,
                       void * geometry,
                       double * mean, double * covariance, size_t ldc) {
  (void)likelihood;
  (void)geometry;
  (void)temperature;
  (void)blocks;

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
const gmcmc_proposal_function gmcmc_proposal_mh = &proposal_mh;
