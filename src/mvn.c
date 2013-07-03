#include "distribution/randn.c"

/**
 * Constant for log(2 * pi) (used in the log multivariate normal PDF).
 */
#define M_LOG2PI 1.83787706640935

/**
 * External declaration of Cholesky decomposition routine from LAPACK (64-bit).
 */
extern void dpotrf_(const char *, const long *, double *, const long *, long *);

/**
 * Computes the Cholesky decomposition on a real positive-definite matrix.
 *
 * The decomposition has the form:
 *   A = U**T * U, if uplo == CblasUpper, or
 *   L = L * L**T, if uplo == CblasLower
 * where U is an upper triangular matrix and L is a lower triangular matrix.
 *
 * @ref http://www.netlib.org/lapack/lapack_routine/dpotrf.f
 *
 * @param [in]     uplo  CblasUpper if the upper triangle of A is stored,
 *                       CblasLower if the lower triangle of A is stored,
 * @param [in]     n     the order of the matrix A,
 * @param [in,out] A     On entry, the symmetric matrix A. If uplo == CblasUpper,
 *                         the leading n-by-n upper triangular part of A contains
 *                         the upper triangular part of the matrix A, and the
 *                         strictly lower triangular part of A is not referenced.
 *                         If uplo == CblasLower, the leading n-by-n lower
 *                         triangular part of A contains the lower triangular
 *                         part of the matrix A, and the strictly upper triangular
 *                         part of A is not referenced.
 *                         On exit, if the return value is 0, the decomposition
 *                         U or L from the Cholesky decomposition A = U**T * U
 *                         or A = L * L**T.
 * @param [in]     lda     the leading dimension of the array A.
 *
 * @return 0 on success,
 *         less than 0,   the i-th argument had an illegal value
 *         greater than 0 the leading minor of order i is not positive definite,
 *                          and the decomposition could not be completed.
 */
static inline long clapack_dpotrf(enum CBLAS_UPLO uplo, long n, double * A, long lda) {
  long info = 0;
  if (uplo == CblasUpper)
    dpotrf_("Upper", &n, A, &lda, &info);
  else
    dpotrf_("Lower", &n, A, &lda, &info);
  return info;
}

/**
 * External declaration of inverse from Cholesky decomposition routine from
 * LAPACK (64-bit).
 */
extern void dpotri_(const char *, const long *, double *, const long *, long *);

/**
 * Computes the inverse of a real symmetric positive definite matrix A using the
 * Cholesky decomposition A = U**T*U or A = L*L**T computed by clapack_dpotrf.
 *
 * @param [in]     uplo  CblasUpper if the upper triangle of A is stored,
 *                       CblasLower if the lower triangle of A is stored,
 * @param [in]     n     the order of the matrix A,
 *
 * @param [in,out] A     A is double array, length lda * n
 *                         On entry, the triangular factor U or L from the
 *                         Cholesky decomposition A = U**T*U or A = L*L**T, as
 *                         computed by clapack_dpotrf.
 *                         On exit, the upper or lower triangle of the (symmetric)
 *                         inverse of A, overwriting the input factor U or L.
 * @param [in]     lda     the leading dimension of the array A.
 *
 * @return 0 on success,
 *         less than 0,    the i-th argument had an illegal value
 *         greater than 0  the (i,i) element of the factor U or L is zero, and
 *                           the inverse could not be computed.
 */
static inline long clapack_dpotri(enum CBLAS_UPLO uplo, long n, double * A, long lda) {
  long info = 0;
  if (uplo == CblasUpper)
    dpotri_("Upper", &n, A, &lda, &info);
  else
    dpotri_("Lower", &n, A, &lda, &info);
  return info;
}

/**
 * Generates a multivariate normal random vector.  The covariance matrix is
 * overwritten with its Cholesky decomposition on output.
 *
 * @param [in]     n      the dimensionality of the distribution
 * @param [in]     mean   the mean vector (length n)
 * @param [in,out] C      the covariance matrix(n-by-n)
 * @param [in]     ldc    leading dimension of the covariance matrix (ldc >= n)
 * @param [in,out] rng    a random number generator
 * @param [out]    x      the random vector (length n)
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if ldc < n,
 *         GMCMC_ENOMEM if there is not enough memory to allocate a temporary vector,
 *         GMCMC_ELINAL if the covariance matrix is not positive definite.
 */
static int gmcmc_mvn_sample(size_t n, const double * mean, double * C,
                            size_t ldc, const gmcmc_prng64 * rng, double * x) {
  if (ldc < n)
    GMCMC_ERROR("Invalid leading dimension", GMCMC_EINVAL);

  // Quick return
  if (n == 0)
    return 0;

  // Calculate the Cholesky decomposition of the covariance matrix
  long info = clapack_dpotrf(CblasLower, n, C, ldc);
  if (info != 0)
    GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_ELINAL);

  double * z = malloc(n * sizeof(double));
  if (z == NULL)
    GMCMC_ERROR("Unable to allocate standard normal vector", GMCMC_ENOMEM);

  // z = ~N(0,1)
  for (size_t i = 0; i < n; i++)
    z[i] = gmcmc_randn(rng);

  // Use memcpy and BLAS DGEMV (matrix-vector product y = Ax + y) to compute
  // x = Az + mean
  memcpy(x, mean, n * sizeof(double));
  cblas_dgemv(CblasColMajor, CblasNoTrans, n, n, 1.0, C, ldc, z, 1, 1.0, x, 1);

  free(z);

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
static double log_det(size_t n, const double * C, size_t ldc) {
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
 * @param [in,out] C        the Cholesky decomposition of the covariance matrix (n-by-n)
 * @param [in]     ldc      the leading dimension of the covariance matrix
 * @param [out]    res      the result
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if temporary vectors could not be allocated,
 *         GMCMC_ELINAL if the covariance matrix is singular.
 */
static int gmcmc_mvn_logpdf(size_t n, const double * x, const double * mean, double * C, size_t ldc, double * res) {
  if (n == 0) {
    *res = -INFINITY;
    return 0;
  }

  // Calculate the log determinant of the covariance matrix before overwriting it with its inverse
  double ldet = log_det(n, C, ldc);

  // Calculate the inverse from the Cholesky
  long info = clapack_dpotri(CblasLower, n, C, ldc);
  if (info != 0)
    GMCMC_ERROR("Proposal covariance matrix is singular", GMCMC_ELINAL);

  double * x_mu = malloc(n * sizeof(double));
  if (x_mu == NULL)
    GMCMC_ERROR("Unable to allocate temporary vector", GMCMC_ENOMEM);

  double * x_muTinv = malloc(n * sizeof(double));
  if (x_muTinv == NULL) {
    free(x_mu);
    GMCMC_ERROR("Unable to allocate temporary vector", GMCMC_ENOMEM);
  }

  // x_mu = x - mean
  for (size_t i = 0; i < n; i++)
    x_mu[i] = x[i] - mean[i];

  // Use CBLAS DGEMV to compute mean = (x - mu)'*inv(covariance) = inv(covariance)'*(x - mu)
  cblas_dgemv(CblasColMajor, CblasTrans, n, n, 1.0, C, ldc, x_mu, 1, 0.0, x_muTinv, 1);
  // Use CBLAS DDOT to compute (x - mu)'*inv(cov)*x_mu
  double p = cblas_ddot(n, x_muTinv, 1, x_mu, 1);

  free(x_mu);
  free(x_muTinv);

  // LogResult = -(k/2)*log(2*pi) - sum(log(diag(chol(Covar)))) -0.5*(( Diff'/Covar )*Diff);
  *res = -(n / 2.0) * M_LOG2PI - 0.5 * ldet - 0.5 * p;

  return 0;
}
