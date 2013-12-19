#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef MKL
#include <mkl_cblas.h>
#include <mkl_lapacke.h>
#else
#include <cblas.h>
#include <lapacke.h>
#endif

#include "distribution/randn.c"

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
 * @param [in]     map    an array of indices (length n) to update in x (may be
 *                          NULL)
 * @param [out]    x      the random vector
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if ldc < n,
 *         GMCMC_ENOMEM if there is not enough memory to allocate a temporary
 *                        matrix/vector,
 *         GMCMC_ELINAL if the covariance matrix is not positive definite.
 */
static inline int gmcmc_mvn_sample(size_t n, const double * mean, const double * C,
                                   size_t ldc, const gmcmc_prng64 * rng,
                                   const size_t * map, double * x) {
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

  long info = LAPACKE_dpotrf(LAPACK_COL_MAJOR, 'L', (lapack_int)n, cholC, (lapack_int)ldcc);
  if (info != 0) {
    free(cholC);
    GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_EINVAL);
  }

  if (map != NULL) {
    // If x is not contiguous (required for BLAS/LAPACK), allocate a contiguous
    // vector, y, of length n to store the result and copy it into x
    double * y;
    if ((y = malloc(n * sizeof(double))) == NULL) {
      free(cholC);
      GMCMC_ERROR("Failed to allocate sample vector", GMCMC_ENOMEM);
    }

    // Generate the sample in y then copy into x using the map
    // y = ~N(0,1)
    for (size_t i = 0; i < n; i++)
      y[i] = gmcmc_randn(rng);

    // Use BLAS DTRMV (matrix-vector product) to compute y = Ay
    cblas_dtrmv(CblasColMajor, CblasLower, CblasNoTrans, CblasNonUnit, (int)n, cholC, (int)ldcc, y, 1);

    // Add the mean, x[map[i]] = y[i] + mean[i]
    for (size_t i = 0; i < n; i++)
      x[map[i]] = y[i] + mean[i];

    free(y);
  }
  else {
    // Generate the sample in place
    // x = ~N(0,1)
    for (size_t i = 0; i < n; i++)
      x[i] = gmcmc_randn(rng);

    // Use BLAS DTRMV (matrix-vector product) to compute x = Ax
    cblas_dtrmv(CblasColMajor, CblasLower, CblasNoTrans, CblasNonUnit, (int)n, cholC, (int)ldcc, x, 1);

    // Add the mean, x[i] += mean[i]
    for (size_t i = 0; i < n; i++)
      x[i] += mean[i];
  }

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
 *
 * @param [in]  n      dimensionality of the distribution
 * @param [in]  x      random vector (length n)
 * @param [in]  mu     mean of the distribution (length n, may be NULL for mean
 *                       of zero)
 * @param [in]  sigma  covariance matrix (n-by-n)
 * @param [in]  lds    leading dimension of the covariance matrix
 * @param [out] res    result
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if temporary variables could not be allocated,
 *         GMCMC_ELINAL if the covariance matrix is singular.
 */
static inline int gmcmc_mvn_logpdf(size_t n, const double * x,
                                   const double * mu, const double * sigma, size_t lds,
                                   double * res) {
  if (n == 0) {
    *res = -INFINITY;
    return 0;
  }

  // Create a copy of the covariance matrix so that the inverse can be
  // calculated in-place without overwriting the original
  double * inv;
  size_t ldi = (n + 1u) & ~1u;
  if ((inv = malloc(ldi * n * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate inverse", GMCMC_ENOMEM);
  for (size_t j = 0; j < n; j++)
    memcpy(&inv[j * ldi], &sigma[j * lds], n * sizeof(double));

  // Calculate the Cholesky decomposition of the covariance matrix
  long info = LAPACKE_dpotrf(LAPACK_COL_MAJOR, 'L', (lapack_int)n, inv, (lapack_int)ldi);
  if (info != 0) {
    free(inv);
    GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_EINVAL);
  }

  // Calculate the log determinant of the covariance matrix before overwriting
  // it with the inverse
  double ldet = log_det(n, inv, ldi);

  // Calculate the inverse from the Cholesky
  info = LAPACKE_dpotri(LAPACK_COL_MAJOR, 'L', (lapack_int)n, inv, (lapack_int)ldi);
  if (info != 0) {
    free(inv);
    GMCMC_ERROR("Proposal covariance matrix is singular", GMCMC_EINVAL);
  }

  double p;
  if (mu == NULL) {
    // Allocate vectors to store x' * inv(Σ)
    double * xTinv;
    if ((xTinv = malloc(n * sizeof(double))) == NULL) {
      free(inv);
      GMCMC_ERROR("Unable to allocate temporary vector", GMCMC_ENOMEM);
    }

    // Use CBLAS DSYMV to compute x' * inv(Σ)
    cblas_dsymv(CblasColMajor, CblasLower, (lapack_int)n, 1.0, inv, (lapack_int)ldi, x, 1, 0.0, xTinv, 1);
    // Use CBLAS DDOT to compute x' * inv(Σ) * x
    p = cblas_ddot((int)n, xTinv, 1, x, 1);

    free(xTinv);
  }
  else {
    // Allocate vectors to store (x - mu) and (x - mu)' * inv(Σ)
    double * x_mu = NULL, * x_muTinv = NULL;
    if ((x_mu = malloc(n * sizeof(double))) == NULL ||
        (x_muTinv = malloc(n * sizeof(double))) == NULL) {
      free(inv);
      free(x_mu);
      free(x_muTinv);
      GMCMC_ERROR("Unable to allocate temporary vectors", GMCMC_ENOMEM);
    }

    // x_mu = x - mu
    for (size_t i = 0; i < n; i++)
      x_mu[i] = x[i] - mu[i];

    // Use CBLAS DSYMV to compute (x - mu)' * inv(Σ)
    cblas_dsymv(CblasColMajor, CblasLower, (int)n, 1.0, inv, (int)ldi, x_mu, 1, 0.0, x_muTinv, 1);
    // Use CBLAS DDOT to compute (x - mu)' * inv(Σ) * (x - mu)
    p = cblas_ddot((int)n, x_muTinv, 1, x_mu, 1);

    free(x_mu);
    free(x_muTinv);
  }

  free(inv);

  // LogResult = -(k/2)*log(2*pi) - sum(log(diag(chol(Covar)))) -0.5*(( Diff'/Covar )*Diff);
  *res = -((double)n / 2.0) * M_LOG2PI - 0.5 * ldet - 0.5 * p;

  return 0;
}

/**
 * Calculates the log PDF of the multivariate normal distribution with
 * Sigma = [ s1  0  0
 *            0 s2  0
 *            0  0 s3 ]
 * for some vector [ s1 s2 s3 ].
 *
 * When Sigma is assumed to be dense evaluating the multivariate normal PDF is
 * an O(n^3) operation due to the Cholesky decomposition and inverse of the
 * covariance matrix.  If Sigma is diagonal then this can be reduced to O(n).
 *
 * @param [in]  n      dimensionality of the distribution
 * @param [in]  x      random vector (length n)
 * @param [in]  mu     mean of the distribution (length n, may be NULL for mean
 *                       of zero)
 * @param [in]  sigma  the diagonal of the covariance matrix
 * @param [out] res    result
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if any element of sigma is less than or equal to zero.
 */
static inline int gmcmc_mvn_logpdfv(size_t n, const double * x,
                                    const double * mu, const double * sigma,
                                    double * res) {
  if (n == 0) {
    *res = -INFINITY;
    return 0;
  }


  // (x - mu)' * inv(Sigma) * (x - mu) becomes sum(x^2/sigma)
  // log(det(Sigma)) becomes sum(log(sqrt(sigma))) * 2.0
  double p = 0.0, log_det = 0.0;
  if (mu == NULL) {
    for (size_t i = 0; i < n; i++) {
      // The values along the diagonal must be greater than zero to be positive
      // definite.
      if (islessequal(sigma[i], 0.0))
        GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_EINVAL);
      p += x[i] * (1.0 / sigma[i]) * x[i];
      log_det += log(sigma[i]);
    }
  }
  else {
    for (size_t i = 0; i < n; i++) {
      // The values along the diagonal must be greater than zero to be positive
      // definite.
      if (islessequal(sigma[i], 0.0))
        GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_EINVAL);
      p += (x[i] - mu[i]) * (1.0 / sigma[i]) * (x[i] - mu[i]);
      log_det += log(sigma[i]);
    }
  }

  *res = -((double)n / 2.0) * M_LOG2PI - 0.5 * (log_det + p);

  return 0;
}

/**
 * Calculates the log PDF of the multivariate normal distribution with
 * Sigma = [ s 0 0
 *           0 s 0
 *           0 0 s ]
 * for some scalar s.
 *
 * When Sigma is assumed to be dense evaluating the multivariate normal PDF is
 * an O(n^3) operation due to the Cholesky decomposition and inverse of the
 * covariance matrix.  If Sigma is diagonal then this can be reduced to O(n).
 *
 * @param [in]  n      dimensionality of the distribution
 * @param [in]  x      random vector (length n)
 * @param [in]  mu     mean of the distribution (length n, may be NULL for mean
 *                       of zero)
 * @param [in]  sigma  the value along the diagonal of the covariance matrix
 *                       (variance)
 * @param [out] res    result
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if sigma is less than or equal to zero.
 */
static inline int gmcmc_mvn_logpdfs(size_t n, const double * x,
                                    const double * mu, double sigma,
                                    double * res) {
  if (n == 0) {
    *res = -INFINITY;
    return 0;
  }

  // The values along the diagonal must be greater than zero to be positive
  // definite.  This check must come after the (n == 0) check for consistent
  // behaviour with gmcmc_mvn_logpdf.
  if (islessequal(sigma, 0.0))
    GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_EINVAL);

  // (x - mu)' * inv(Sigma) * (x - mu) becomes sum(x^2)/sigma
  double p = 0.0;
  if (mu == NULL) {
    for (size_t i = 0; i < n; i++)
      p += x[i] * x[i];
  }
  else {
    for (size_t i = 0; i < n; i++)
      p += (x[i] - mu[i]) * (x[i] - mu[i]);
  }

  // log(det(Sigma)) becomes n * log(sigma)
  *res = -((double)n / 2.0) * (M_LOG2PI + log(sigma)) - (p / (2.0 * sigma));

  return 0;
}
