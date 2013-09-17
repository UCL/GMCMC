#include <gmcmc/gmcmc_proposal.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <math.h>
#include <cblas.h>
#include <lapacke.h>

/**
 * Proposal function using truncated Simplified M-MALA.
 */
static int proposal_simp_mmala_trunc(size_t n, const double * params,
                                     double likelihood, double temperature,
                                     double stepsize, const void * serdata,
                                     double * mean, double * covariance, size_t ldc) {
  (void)likelihood;     // Unused

  // Unpack the serialised data
  size_t ldfi = (n + 1u) & ~1u;
  const double * gradient_ll = serdata;
  const double * gradient_log_prior = &gradient_ll[ldfi];
  const double * FI = &gradient_log_prior[ldfi];
  const double * hessian_log_prior = &FI[ldfi * n];

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
    gradient[i] = gradient_ll[i] * temperature + gradient_log_prior[i];

  double max_grad = 10000.0;
  for (size_t i = 0; i < n; i++)
    gradient[i] = (gradient[i] * max_grad) / fmax(fabs(gradient[i]), max_grad);

  // Posterior_G      = Chain.FI*Chain.Temp - diag(Chain.HessianLogPrior);
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      G[j * ldg + i] = FI[j * ldfi + i] * temperature;
    G[j * ldg + j] -= hessian_log_prior[j] - (1.0 / stepsize);
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

  // Proposal_Mean    = CurrentParas + NaturalGradient;
  for (size_t i = 0; i < n; i++)
    mean[i] = params[i] + gradient[i];

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

  free(gradient);
  free(G);

  return 0;
}
const gmcmc_proposal_function gmcmc_proposal_simp_mmala_trunc = &proposal_simp_mmala_trunc;
