#include <gmcmc/gmcmc_proposal.h>
#include <gmcmc/gmcmc_geometry.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <cblas.h>

extern void dpotrf_(const char *, const int *, double *, const int *, int *);
static inline int dpotrf(bool upper, int n, double * A, int lda) {
  int info;
  if (upper)
    dpotrf_("Upper", &n, A, &lda, &info);
  else
    dpotrf_("Lower", &n, A, &lda, &info);
  return info;
}

/**
 * Proposal function using truncated Simplified M-MALA.
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
static int proposal_simp_mmala_trunc(size_t n, const size_t * blocks, const double * params,
                                     double likelihood, double temperature,
                                     double stepsize, void * geometry,
                                     double * mean, double * covariance, size_t ldc) {
  (void)likelihood;     // Unused

  gmcmc_geometry_simp_mmala * g = (gmcmc_geometry_simp_mmala *)geometry;

  // Calculate posterior gradient and metric tensor
  size_t ldg = (n + 1u) & ~1u;
  double * gradient = NULL, * G = NULL;
  if ((gradient = malloc(n * sizeof(double))) == NULL ||
      (G = malloc(n * ldg * sizeof(double))) == NULL) {
    free(gradient);
    free(G);
    free(g->gradient_log_prior);
    free(g->gradient_log_likelihood);
    free(g->hessian_log_prior);
    free(g->FI);
    free(g);
    GMCMC_ERROR("Failed to allocate posterior gradients", GMCMC_ENOMEM);
  }
  // Posterior_Grad   = Chain.GradLL*Chain.Temp + Chain.GradLogPrior;
  for (size_t i = 0; i < n; i++)
    gradient[i] = g->gradient_log_likelihood[i] * temperature + g->gradient_log_prior[i];

  double max_grad = 10000.0;
  for (size_t i = 0; i < n; i++)
    gradient[i] = (gradient[i] * max_grad) / fmax(fabs(gradient[i]), max_grad);

  // Posterior_G      = Chain.FI*Chain.Temp - diag(Chain.HessianLogPrior);
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      G[j * ldg + i] = g->FI[j * g->ldfi + i] * temperature;
    G[j * ldg + j] -= g->hessian_log_prior[j] - (1.0 / stepsize);
  }


  // Calculate cholesky
  int info = dpotrf(false, n, G, ldg);
  if (info != 0) {
    free(gradient);
    free(G);
    free(g->gradient_log_prior);
    free(g->gradient_log_likelihood);
    free(g->hessian_log_prior);
    free(g->FI);
    free(g);
    if (info < 0)
      GMCMC_ERROR("Invalid argument to LAPACK function", GMCMC_EINVAL);
    else
      GMCMC_WARNING("Posterior gradient is not positive definite", GMCMC_ELINAL);
  }

  // NaturalGradient  = (CholG\(CholG'\Posterior_Grad'))';
  cblas_dtrsv(CblasColMajor, CblasLower, CblasNoTrans, CblasNonUnit, n, G, ldg, gradient, 1);
  cblas_dtrsv(CblasColMajor, CblasLower, CblasTrans, CblasNonUnit, n, G, ldg, gradient, 1);

  // Proposal_Mean    = CurrentParas + NaturalGradient;
  for (size_t i = 0; i < n; i++)
    mean[i] = params[blocks[i]] + gradient[i];

  // Proposal_Covariance = CholG\(CholG'\( diag(ones(1, NumOfParas)) ));
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      covariance[j * ldc + i] = 0.0;
    covariance[j * ldc + j] = 1.0;
    for (size_t i = j + 1; i < n; i++)
      covariance[j * ldc + i] = 0.0;
  }
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, n, n, 1.0, G, ldg, covariance, ldc);
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasTrans, CblasNonUnit, n, n, 1.0, G, ldg, covariance, ldc);

  // Free temporary variables
  free(gradient);
  free(G);

  // Free geometry info
  free(g->gradient_log_prior);
  free(g->gradient_log_likelihood);
  free(g->hessian_log_prior);
  free(g->FI);
  free(g);

  return 0;
}
const gmcmc_proposal_function gmcmc_proposal_simp_mmala_trunc = &proposal_simp_mmala_trunc;
