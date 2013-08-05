#ifndef GMCMC_CLAPACK_H
#define GMCMC_CLAPACK_H

#include <stdlib.h>
#include <cblas.h>
/**
 * Inline wrapper functions for LAPACK using a similar interface to CBLAS.
 */
// TODO: Complete documentation of external LAPACK function wrappers

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

// Eigenvectors
extern void dgeev_(const char *, const char *, const long *,
                   double *, const long *, double *, double *,
                   double *, const long *, double *, const long *,
                   double *, const long *, long *);
static inline long clapack_dgeev(bool jobvl, bool jobvr, long n,
                                 double * A, long lda, double * wr, double * wi,
                                 double * VL, long ldvl, double * VR, long ldvr) {
  long info = 0, lwork = -1;
  double size, * work;

  const char * jvl = (jobvl) ? "V" : "N";
  const char * jvr = (jobvr) ? "V" : "N";

  dgeev_(jvl, jvr, &n, A, &lda, wr, wi, VL, &ldvl, VR, &ldvr, &size, &lwork, &info);
  if (info != 0)
    return info;

  lwork = size;
  if ((work = malloc((size_t)lwork * sizeof(double))) == NULL)
    return -12;

  dgeev_(jvl, jvr, &n, A, &lda, wr, wi, VL, &ldvl, VR, &ldvr, work, &lwork, &info);

  free(work);

  return info;
}

// LU decomposition
extern void dgetrf_(const long *, const long *, double *, const long *, long *, long *);
static inline long clapack_dgetrf(long m, long n, double * A, long lda, long ** ipiv) {
  long info = 0, min = (m < n) ? m : n;

  if ((*ipiv = malloc((size_t)min * sizeof(long))) == NULL)
    return -5;

  dgetrf_(&m, &n, A, &lda, *ipiv, &info);

  return info;
}

// Inverse from LU decomposition
extern void dgetri_(const long *, double *, const long *, const long *, double *, const long *, long *);
static inline long clapack_dgetri(long n, double * A, long lda, const long * ipiv) {
  long info = 0, lwork = -1;
  double size, * work;

  dgetri_(&n, A, &lda, ipiv, &size, &lwork, &info);
  if (info != 0)
    return info;

  lwork = size;
  if ((work = malloc((size_t)lwork * sizeof(double))) == NULL)
    return -5;

  dgetri_(&n, A, &lda, ipiv, work, &lwork, &info);

  free(work);

  return info;
}

// Matrix right division
extern void dgesv_(const long *, const long *, double *, const long *, long *, double *, const long *, long *);
static inline long clapack_dgesv(long n, long nrhs, double * A, long lda, double * B, long ldb) {
  long info = 0, * ipiv;

  if ((ipiv = malloc(n * sizeof(long))) == NULL)
    return -5;

  dgesv_(&n, &nrhs, A, &lda, ipiv, B, &ldb, &info);

  free(ipiv);

  return info;
}

#endif
