#include <gmcmc/gmcmc_proposal.h>
#include <gmcmc/gmcmc_geometry.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <cblas.h>
#include <lapacke.h>

/**
 * Proposal function using Simplified M-MALA.
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
static int proposal_simp_mmala(size_t n, const double * params,
                               double likelihood, double temperature,
                               double stepsize, const void * geometry,
                               double * mean, double * covariance, size_t ldc) {
  (void)likelihood;     // Unused

  const gmcmc_geometry_simp_mmala * g = (const gmcmc_geometry_simp_mmala *)geometry;

  // Calculate posterior gradient and metric tensor
  size_t ldg = (n + 1u) & ~1u;
  double * gradient = NULL, * G = NULL;
  if ((gradient = malloc(n * sizeof(double))) == NULL ||
      (G = malloc(n * ldg * sizeof(double))) == NULL) {
    free(gradient);
    free(G);
    GMCMC_ERROR("Failed to allocate posterior gradients", GMCMC_ENOMEM);
  }
  // Posterior_Grad   = Chain.GradLL*Chain.Temp + Chain.GradLogPrior;
  for (size_t i = 0; i < n; i++)
    gradient[i] = g->gradient_log_likelihood[i] * temperature + g->gradient_log_prior[i];
  // Posterior_G      = Chain.FI*Chain.Temp - diag(Chain.HessianLogPrior);
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      G[j * ldg + i] = g->FI[j * g->ldfi + i] * temperature;
    G[j * ldg + j] -= g->hessian_log_prior[j];
  }


  // Calculate cholesky
  long info = LAPACKE_dpotrf(LAPACK_COL_MAJOR, 'L', n, G, ldg);
  if (info != 0) {
    free(gradient);
    free(G);
    if (info < 0)
      GMCMC_ERROR("Invalid argument to LAPACK function", GMCMC_EINVAL);
    else
      GMCMC_WARNING("Posterior gradient is not positive definite", GMCMC_ELINAL);
  }

  // NaturalGradient  = (CholG\(CholG'\Posterior_Grad'))';
  cblas_dtrsv(CblasColMajor, CblasLower, CblasNoTrans, CblasNonUnit, n, G, ldg, gradient, 1);
  cblas_dtrsv(CblasColMajor, CblasLower, CblasTrans, CblasNonUnit, n, G, ldg, gradient, 1);

  // Proposal_Mean    = CurrentParas + (StepSize^2/2)*NaturalGradient;
  for (size_t i = 0; i < n; i++)
    mean[i] = params[i] + ((stepsize * stepsize) / 2.0) * gradient[i];

  // Proposal_Covariance = CholG\(CholG'\( diag(ones(1, NumOfParas)*(StepSize^2)) )); % Stepsize is squared in the covariance term
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      covariance[j * ldc + i] = 0.0;
    covariance[j * ldc + j] = stepsize * stepsize;
    for (size_t i = j + 1; i < n; i++)
      covariance[j * ldc + i] = 0.0;
  }
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, n, n, 1.0, G, ldg, covariance, ldc);
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasTrans, CblasNonUnit, n, n, 1.0, G, ldg, covariance, ldc);

  free(gradient);
  free(G);

  return 0;
}
const gmcmc_proposal_function gmcmc_proposal_simp_mmala = &proposal_simp_mmala;
