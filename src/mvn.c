#include <math.h>
#include "distribution/randn.c"
#include "clapack.h"

/**
 * Constant for log(2 * pi) (used in the log multivariate normal PDF).
 */
#define M_LOG2PI 1.83787706640935

/**
 * Generates a multivariate normal random vector.  The covariance matrix is
 * overwritten with its Cholesky decomposition on output.
 *
 * @param [in]     n      the dimensionality of the distribution
 * @param [in]     mean   the mean vector (length n)
 * @param [in]     C      the covariance matrix(n-by-n)
 * @param [in]     ldc    leading dimension of the covariance matrix (ldc >= n)
 * @param [in,out] rng    a random number generator
 * @param [out]    x      the random vector (length n)
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if ldc < n,
 *         GMCMC_ENOMEM if there is not enough memory to allocate a temporary vector,
 *         GMCMC_ELINAL if the covariance matrix is not positive definite.
 */
static inline int gmcmc_mvn_sample(size_t n, const double * mean, const double * C,
                                   size_t ldc, const gmcmc_prng64 * rng, double * x) {
  if (ldc < n)
    GMCMC_ERROR("Invalid leading dimension", GMCMC_EINVAL);

  // Quick return
  if (n == 0)
    return 0;

  // Calculate the Cholesky decomposition of the covariance matrix
  double * cholC;
  size_t ldcc = (n + 1u) & ~1u;
  if ((cholC = malloc(ldcc * n * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate cholesky", GMCMC_ENOMEM);
  for (size_t j = 0; j < n; j++)
    memcpy(&cholC[j * ldcc], &C[j * ldc], n * sizeof(double));
  long info = clapack_dpotrf(CblasLower, n, cholC, ldcc);
  if (info != 0) {
    free(cholC);
    GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_ELINAL);
  }

  // x = ~N(0,1)
  for (size_t i = 0; i < n; i++)
    x[i] = gmcmc_randn(rng);

  // Use BLAS DTRMV (matrix-vector product) to compute x = Ax
  cblas_dtrmv(CblasColMajor, CblasLower, CblasNoTrans, CblasNonUnit, n, cholC, ldcc, x, 1);

  // Add the mean
  for (size_t i = 0; i < n; i++)
    x[i] += mean[i];

  free(cholC);

  return 0;
}

/**
 * Calculates the log of the determinant of a matrix from its Cholesky
 * decomposition.
 *
 * @param [in] n    the size of the matrix
 * @param [in] C    the Cholesky decomposition of a matrix (n by n)
 * @param [in] ldc  the leading dimension of C (ldc >= n)
 *
 * @return the log determinant.
 */
static inline double log_det(size_t n, const double * C, size_t ldc) {
  if (n == 0)
    return -INFINITY;

  // sum(log(diag(chol(Covar))))
  double sum = 0.0;
  for (size_t i = 0; i < n; i++)
    sum += log(C[i * ldc + i]);

  return sum * 2.0;
}

/**
 * Calculates the log of the PDF of the multivariate normal distribution at x.
 * The Cholesky decomposition of the covariance matrix is overwritten with the
 * inverse on output
 *
 * @param [in]     n        the dimensionality of the distribution
 * @param [in]     x        the random vector (length n)
 * @param [in]     mean     the mean of the distribution (length n)
 * @param [in] C        the Cholesky decomposition of the covariance matrix (n-by-n)
 * @param [in]     ldc      the leading dimension of the covariance matrix
 * @param [out]    res      the result
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if temporary vectors could not be allocated,
 *         GMCMC_ELINAL if the covariance matrix is singular.
 */
static inline int gmcmc_mvn_logpdf(size_t n, const double * x,
                                   const double * mean, const double * C, size_t ldc,
                                   double * res) {
  if (n == 0) {
    *res = -INFINITY;
    return 0;
  }

  // Calculate the Cholesky decomposition of the covariance matrix
  double * inv;
  size_t ldi = (n + 1u) & ~1u;
  if ((inv = malloc(ldi * n * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate inverse", GMCMC_ENOMEM);
  for (size_t j = 0; j < n; j++)
    memcpy(&inv[j * ldi], &C[j * ldc], n * sizeof(double));
  long info = clapack_dpotrf(CblasLower, n, inv, ldi);
  if (info != 0) {
    free(inv);
    GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_ELINAL);
  }

  // Calculate the log determinant of the covariance matrix before overwriting it with its inverse
  double ldet = log_det(n, inv, ldi);

  // Calculate the inverse from the Cholesky
  info = clapack_dpotri(CblasLower, n, inv, ldi);
  if (info != 0) {
    free(inv);
    GMCMC_ERROR("Proposal covariance matrix is singular", GMCMC_ELINAL);
  }

  double * x_mu = NULL, * x_muTinv = NULL;;
  if ((x_mu = malloc(n * sizeof(double))) == NULL || (x_muTinv = malloc(n * sizeof(double))) == NULL) {
    free(inv);
    free(x_mu);
    free(x_muTinv);
    GMCMC_ERROR("Unable to allocate temporary vectors", GMCMC_ENOMEM);
  }

  // x_mu = x - mean
  for (size_t i = 0; i < n; i++)
    x_mu[i] = x[i] - mean[i];

  // Use CBLAS DSYMV to compute inv(covariance)*(x - mu)
  cblas_dsymv(CblasColMajor, CblasLower, n, 1.0, inv, ldi, x_mu, 1, 0.0, x_muTinv, 1);
  // Use CBLAS DDOT to compute (x - mu)'*inv(covariance)*x_mu
  double p = cblas_ddot(n, x_muTinv, 1, x_mu, 1);

  free(inv);
  free(x_mu);
  free(x_muTinv);

  // LogResult = -(k/2)*log(2*pi) - sum(log(diag(chol(Covar)))) -0.5*(( Diff'/Covar )*Diff);
  *res = -(n / 2.0) * M_LOG2PI - 0.5 * ldet - 0.5 * p;

  return 0;
}

/**
 * Calculates the log PDF of the multivariate normal distribution with
 * Mean = [ 0   Sigma = [ s 0 0
 *          0             0 s 0
 *          0 ]           0 0 s ]
 * for some scalar s.
 *
 * When Sigma is assumed to be dense evaluating the multivariate normal PDF is
 * an O(n^3) operation due to the Cholesky decomposition and inverse of the
 * covariance matrix.  If Sigma is diagonal then this can be reduced to O(n).
 *
 * @param [in]  n      the dimensionality of the distribution
 * @param [in]  x      the sample vector
 * @param [in]  sigma  the value along the diagonal of the covariance matrix
 * @param [out] res    the probability of x
 *
 * @return 0 on success, GMCMC_EINVAL if sigma is less than or equal to zero.
 */
static inline int gmcmc_mvn_logpdf0(size_t n, const double * x, double sigma, double * res) {
  if (islessequal(sigma, 0.0))
    return GMCMC_EINVAL;

  if (n == 0) {
    *res = -INFINITY;
    return 0;
  }

  // (x - mu)' * inv(Sigma) * (x - mu) becomes sum(x^2)/sigma
  double p = 0.0;
  for (size_t i = 0; i < n; i++)
    p += x[i] * x[i];

  // log(det(Sigma)) becomes n * log(sigma)
  *res = -(n / 2.0) * (M_LOG2PI + log(sigma)) - (p / (2.0 * sigma));

  return 0;
}
