#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "src/ion_model.c"

static inline void schur(size_t n, const double * v, double * D, size_t ldd) {
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      D[j * ldd + i] = 0.0;
    D[j * ldd + j] = v[j];
    for (size_t i = j + 1; i < n; i++)
      D[j * ldd + i] = 0.0;
  }
}

static inline void gemm(size_t n,
                        const double * A, size_t lda, const double * B, size_t ldb,
                        double * C, size_t ldc) {
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      C[j * ldc + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      const double temp = B[j * ldb + k];
      for (size_t i = 0; i < n; i++)
        C[j * ldc + i] += temp * A[k * lda + i];
    }
  }
}

static inline void sum(size_t n, const double * A, size_t lda, double * B, size_t ldb) {
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      B[j * ldb + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      for (size_t i = 0; i < n; i++)
        B[j * ldb + i] += A[(k * n * lda) + j * lda + i];
    }
  }
}

static inline int equals(size_t n, const double * A, size_t lda, const double * B, size_t ldb) {
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++) {
      if (fabs(A[j * lda + i] - B[j * ldb + i]) > 0.0001)
        return (j + 1) * n + i + 1;
    }
  }
  return 0;
}

static inline int is_identity(size_t n, const double * A, size_t lda) {
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++) {
      const double x = (i == j) ? 1.0 : 0.0;
      if (fabs(A[j * lda + i] - x) > 0.0001)
        return (j + 1) * lda + i + 1;
    }
  }
  return 0;
}

static void test_eig0() {
  // Q_FF from Castillo_Katz using initial parameters
  // [V,D] = eig(X)
  // X*V = V*D

  // Input arguments
  const size_t n = 2;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] =  -100.0;
  X[0 * ldx + 1] =   100.0;
  X[1 * ldx + 0] =   100.0;
  X[1 * ldx + 1] = -1100.0;

  // Output arguments
  double v[n];
  const size_t ldv = (n + 1u) & ~1u;
  double V[ldv * n];

  // Call test function
  int error = eig(n, X, ldx, v, V, ldv);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0],   -90.0980, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -1109.9020, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0],  0.9951, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1],  0.0985, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0], -0.0985, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1],  0.9951, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  schur(n, v, D, ldd);

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  gemm(n, X, ldx, V, ldv, XV, ldxv);

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  gemm(n, V, ldv, D, ldd, VD, ldvd);

  // Check that X*V == V*D
  CU_ASSERT(equals(n, XV, ldxv, VD, ldvd) == 0);
}

static void test_eig1() {
  // Q_AA from Castillo_Katz using initial parameters
  // [V,D] = eig(X)
  // X*V = V*D

  // Input arguments
  const size_t n = 1;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -1000.0;

  // Output arguments
  double v[n];
  const size_t ldv = (n + 1u) & ~1u;
  double V[ldv * n];

  // Call test function
  int error = eig(n, X, ldx, v, V, ldv);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0], -1000.0, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0], 1.0, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  schur(n, v, D, ldd);

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  gemm(n, X, ldx, V, ldv, XV, ldxv);

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  gemm(n, V, ldv, D, ldd, VD, ldvd);

  // Check that X*V == V*D
  CU_ASSERT(equals(n, XV, ldxv, VD, ldvd) == 0);
}

static void test_eig2() {
  // Q_FF from Five_State/Five_State_Balanced using initial parameters
  // [V,D] = eig(X)
  // X*V = V*D

  // Input arguments
  const size_t n = 3;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -10.7782;
  X[0 * ldx + 1] =   0.0000;
  X[0 * ldx + 2] =   0.0000;
  X[1 * ldx + 0] =   6.6021;
  X[1 * ldx + 1] =  -4.4771;
  X[1 * ldx + 2] =   0.0000;
  X[2 * ldx + 0] =   0.0000;
  X[2 * ldx + 1] =   3.3010;
  X[2 * ldx + 2] =  -0.0000;

  // Output arguments
  double v[n];
  const size_t ldv = (n + 1u) & ~1u;
  double V[ldv * n];

  // Call test function
  int error = eig(n, X, ldx, v, V, ldv);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0], -10.7782, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1],  -4.4771, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[2],  -0.0000, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0],  0.7234, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1],  0.6904, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[2 * ldv + 0],  0.3416, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[2 * ldv + 1],  0.5577, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[2 * ldv + 2],  0.7564, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  schur(n, v, D, ldd);

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  gemm(n, X, ldx, V, ldv, XV, ldxv);

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  gemm(n, V, ldv, D, ldd, VD, ldvd);

  // Check that X*V == V*D
  CU_ASSERT(equals(n, XV, ldxv, VD, ldvd) == 0);
}

static void test_eig3() {
  // Q_AA from Five_State using initial parameters
  // [V,D] = eig(X)
  // X*V = V*D

  // Input arguments
  const size_t n = 2;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -3.4771;
  X[0 * ldx + 1] = -0.9542;
  X[1 * ldx + 0] =  0.0000;
  X[1 * ldx + 1] =  1.2553;

  // Output arguments
  double v[n];
  const size_t ldv = (n + 1u) & ~1u;
  double V[ldv * n];

  // Call test function
  int error = eig(n, X, ldx, v, V, ldv);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0],  1.2553, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -3.4771, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0],  0.9803, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1],  0.1977, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  schur(n, v, D, ldd);

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  gemm(n, X, ldx, V, ldv, XV, ldxv);

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  gemm(n, V, ldv, D, ldd, VD, ldvd);

  // Check that X*V == V*D
  CU_ASSERT(equals(n, XV, ldxv, VD, ldvd) == 0);
}

static void test_eig4() {
  // Q_AA from Five_State_Balanced using initial parameters
  // [V,D] = eig(X)
  // X*V = V*D

  // Input arguments
  const size_t n = 2;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -3.4771;
  X[0 * ldx + 1] =  1.4432;
  X[1 * ldx + 0] =  0.0000;
  X[1 * ldx + 1] = -4.1422;

  // Output arguments
  double v[n];
  const size_t ldv = (n + 1u) & ~1u;
  double V[ldv * n];

  // Call test function
  int error = eig(n, X, ldx, v, V, ldv);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0], -4.1422, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -3.4771, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0],  0.4185, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1],  0.9082, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  schur(n, v, D, ldd);

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  gemm(n, X, ldx, V, ldv, XV, ldxv);

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  gemm(n, V, ldv, D, ldd, VD, ldvd);

  // Check that X*V == V*D
  CU_ASSERT(equals(n, XV, ldxv, VD, ldvd) == 0);
}

static void test_inv0() {
  // Matrix of eigenvectors from Castillo_Katz Q_FF with initial parameters
  // Y = inv(X)
  // X*Y = I

  // Input arguments
  const size_t n = 2;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -9.8537e-02;
  X[0 * ldx + 1] =  9.9513e-01;
  X[1 * ldx + 0] = -9.9513e-01;
  X[1 * ldx + 1] = -9.8537e-02;

  // Output arguments
  const size_t ldy = (n + 1u) & ~1u;
  double Y[ldy * n];

  // Call test function
  int error = inv(n, X, ldx, Y, ldy);

  // Check return value
  CU_ASSERT(error == 0);

  // Check inverse
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 0], -9.8538e-02, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 1], -9.9513e-01, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 0],  9.9513e-01, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 1], -9.8538e-02, 0.0001);

  // Calculate X*Y
  const size_t ldxy = (n + 1u) & ~1u;
  double XY[ldxy * n];
  gemm(n, X, ldx ,Y, ldy, XY, ldxy);

  // Check that X*Y == I
  CU_ASSERT(is_identity(n, XY, ldxy) == 0);
}

static void test_inv1() {
  // Matrix of eigenvectors from Castillo_Katz Q_AA with initial parameters
  // Y = inv(X)
  // X*Y = I

  // Input arguments
  const size_t n = 1;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = 1.0000;

  // Output arguments
  const size_t ldy = (n + 1u) & ~1u;
  double Y[ldy * n];

  // Call test function
  int error = inv(n, X, ldx, Y, ldy);

  // Check return value
  CU_ASSERT(error == 0);

  // Check inverse
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 0], 1.0000, 0.0001);

  // Calculate X*Y
  const size_t ldxy = (n + 1u) & ~1u;
  double XY[ldxy * n];
  gemm(n, X, ldx ,Y, ldy, XY, ldxy);

  // Check that X*Y == I
  CU_ASSERT(is_identity(n, XY, ldxy) == 0);
}

static void test_inv2() {
  // Matrix of eigenvectors from Five_State/Five_State_Balanced Q_FF with initial parameters
  // Y = inv(X)
  // X*Y = I

  // Input arguments
  const size_t n = 3;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -1.0000;
  X[0 * ldx + 1] =  2.9506e-03;
  X[0 * ldx + 2] = -1.5528e-06;
  X[1 * ldx + 0] = -2.2984e-01;
  X[1 * ldx + 1] = -9.7322e-01;
  X[1 * ldx + 2] =  4.7406e-03;
  X[2 * ldx + 0] =  1.4530e-01;
  X[2 * ldx + 1] =  6.9019e-01;
  X[2 * ldx + 2] =  7.0889e-01;

  // Output arguments
  const size_t ldy = (n + 1u) & ~1u;
  double Y[ldy * n];

  // Call test function
  int error = inv(n, X, ldx, Y, ldy);

  // Check return value
  CU_ASSERT(error == 0);

  // Check inverse
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 0], -9.9931e-01, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 1], -3.0169e-03, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 2],  1.7986e-05, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 0],  2.3588e-01, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 1], -1.0220,     0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 2],  6.8347e-03, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[2 * ldy + 0], -2.4828e-02, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[2 * ldy + 1],  9.9561e-01, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[2 * ldy + 2],  1.4040,     0.0001);

  // Calculate X*Y
  const size_t ldxy = (n + 1u) & ~1u;
  double XY[ldxy * n];
  gemm(n, X, ldx ,Y, ldy, XY, ldxy);

  // Check that X*Y == I
  CU_ASSERT(is_identity(n, XY, ldxy) == 0);
}

static void test_inv3() {
  // Matrix of eigenvectors from Five_State Q_AA with initial parameters
  // Y = inv(X)
  // X*Y = I

  // Input arguments
  const size_t n = 2;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -1.0000;
  X[0 * ldx + 1] =  2.1866e-04;
  X[1 * ldx + 0] = -1.6397e-02;
  X[1 * ldx + 1] = -9.9987e-01;

  // Output arguments
  const size_t ldy = (n + 1u) & ~1u;
  double Y[ldy * n];

  // Call test function
  int error = inv(n, X, ldx, Y, ldy);

  // Check return value
  CU_ASSERT(error == 0);

  // Check inverse
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 0], -1.0000,     0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 1], -2.1869e-04, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 0],  1.6400e-02, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 1], -1.0001,     0.0001);

  // Calculate X*Y
  const size_t ldxy = (n + 1u) & ~1u;
  double XY[ldxy * n];
  gemm(n, X, ldx ,Y, ldy, XY, ldxy);

  // Check that X*Y == I
  CU_ASSERT(is_identity(n, XY, ldxy) == 0);
}

static void test_inv4() {
  // Matrix of eigenvectors from Five_State_Balanced Q_AA with initial parameters
  // Y = inv(X)
  // X*Y = I

  // Input arguments
  const size_t n = 2;
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  X[0 * ldx + 0] = -1.0000;
  X[0 * ldx + 1] =  2.6150e-04;
  X[1 * ldx + 0] = -1.9609e-02;
  X[1 * ldx + 1] = -9.9981e-01;

  // Output arguments
  const size_t ldy = (n + 1u) & ~1u;
  double Y[ldy * n];

  // Call test function
  int error = inv(n, X, ldx, Y, ldy);

  // Check return value
  CU_ASSERT(error == 0);

  // Check inverse
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 0], -1.0000,     0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[0 * ldy + 1], -2.6155e-04, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 0],  1.9613e-02, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(Y[1 * ldy + 1], -1.0002,     0.0001);

  // Calculate X*Y
  const size_t ldxy = (n + 1u) & ~1u;
  double XY[ldxy * n];
  gemm(n, X, ldx ,Y, ldy, XY, ldxy);

  // Check that X*Y == I
  CU_ASSERT(is_identity(n, XY, ldxy) == 0);
}

static void test_specmat0() {
  // Q_FF from Castillo_Katz using initial parameters
  // [X V] = eig(Q_FF)
  // Y = inv(X)
  // for j=1:n
  //  SpecMat[j] = X(:,j)*Y(j,:)
  // end
  // \sum_{j=1}^n SpecMat_j = I

  // Input arguments
  const size_t n = 2;
  const size_t ldq = (n + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] =  -100.0;
  Q[0 * ldq + 1] =   100.0;
  Q[1 * ldq + 0] =   100.0;
  Q[1 * ldq + 1] = -1100.0;

  // Output arguments
  double v[n];
  const size_t lds = (n + 1u) & ~1u;
  double S[lds * n * n];

  // Call test function
  int error = calculate_specmat_eigenvectors(n, Q, ldq, v, S, lds);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0],   -90.0980, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -1109.9020, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0],  0.9903, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1], -0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0], -0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1],  0.0097, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0],  0.0097, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1],  0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0],  0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  0.9903, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  sum(n, S, lds, X, ldx);

  // Check that X == I
  CU_ASSERT(is_identity(n, X, ldx) == 0);
}

static void test_specmat1() {
  // Q_AA from Castillo_Katz using initial parameters
  // [X V] = eig(Q_AA)
  // Y = inv(X)
  // for j=1:n
  //  SpecMat[j] = X(:,j)*Y(j,:)
  // end
  // \sum_{j=1}^n SpecMat_j = I

  // Input arguments
  const size_t n = 1;
  const size_t ldq = (n + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] = -1000.0;

  // Output arguments
  double v[n];
  const size_t lds = (n + 1u) & ~1u;
  double S[lds * n * n];

  // Call test function
  int error = calculate_specmat_eigenvectors(n, Q, ldq, v, S, lds);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0], -1000.0, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0], 1.0000, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  sum(n, S, lds, X, ldx);

  // Check that X == I
  CU_ASSERT(is_identity(n, X, ldx) == 0);
}

static void test_specmat2() {
  // Q_FF from Five_State/Five_State_Balanced using initial parameters
  // [X V] = eig(Q_FF)
  // Y = inv(X)
  // for j=1:n
  //  SpecMat[j] = X(:,j)*Y(j,:)
  // end
  // \sum_{j=1}^n SpecMat_j = I

  // Input arguments
  const size_t n = 3;
  const size_t ldq = (n + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] = -10.7782;
  Q[0 * ldq + 1] =   0.0000;
  Q[0 * ldq + 2] =   0.0000;
  Q[1 * ldq + 0] =   6.6021;
  Q[1 * ldq + 1] =  -4.4771;
  Q[1 * ldq + 2] =   0.0000;
  Q[2 * ldq + 0] =   0.0000;
  Q[2 * ldq + 1] =   3.3010;
  Q[2 * ldq + 2] =  -0.0000;

  // Output arguments
  double v[n];
  const size_t lds = (n + 1u) & ~1u;
  double S[lds * n * n];

  // Call test function
  int error = calculate_specmat_eigenvectors(n, Q, ldq, v, S, lds);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0], -10.7782, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1],  -4.4771, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[2],  -0.0000, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0],  0.7234, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0],  0.3416, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[4 * lds + 0], -0.7234, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[4 * lds + 1],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[4 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[5 * lds + 0], -0.5844, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[5 * lds + 1],  0.8078, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[5 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[6 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[6 * lds + 1], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[6 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[7 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[7 * lds + 1], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[7 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[8 * lds + 0],  0.2427, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[8 * lds + 1], -0.8078, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[8 * lds + 2],  1.0000, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  sum(n, S, lds, X, ldx);

  // Check that X == I
  CU_ASSERT(is_identity(n, X, ldx) == 0);
}

static void test_specmat3() {
  // Q_AA from Five_State using initial parameters
  // [X V] = eig(Q_AA)
  // Y = inv(X)
  // for j=1:n
  //  SpecMat[j] = X(:,j)*Y(j,:)
  // end
  // \sum_{j=1}^n SpecMat_j = I

  // Input arguments
  const size_t n = 2;
  const size_t ldq = (n + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] = -3.4771;
  Q[0 * ldq + 1] = -0.9542;
  Q[1 * ldq + 0] =  0.0000;
  Q[1 * ldq + 1] =  1.2553;

  // Output arguments
  double v[n];
  const size_t lds = (n + 1u) & ~1u;
  double S[lds * n * n];

  // Call test function
  int error = calculate_specmat_eigenvectors(n, Q, ldq, v, S, lds);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0],  1.2553, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -3.4771, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0], -0.1977, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0],  0.1977, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  0.0000, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  sum(n, S, lds, X, ldx);

  // Check that X == I
  CU_ASSERT(is_identity(n, X, ldx) == 0);
}

static void test_specmat4() {
  // Q_AA from Five_State_Balanced using initial parameters
  // [X V] = eig(Q_AA)
  // Y = inv(X)
  // for j=1:n
  //  SpecMat[j] = X(:,j)*Y(j,:)
  // end
  // \sum_{j=1}^n SpecMat_j = I

  // Input arguments
  const size_t n = 2;
  const size_t ldq = (n + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] = -3.4771;
  Q[0 * ldq + 1] =  1.4432;
  Q[1 * ldq + 0] =  0.0000;
  Q[1 * ldq + 1] = -4.1422;

  // Output arguments
  double v[n];
  const size_t lds = (n + 1u) & ~1u;
  double S[lds * n * n];

  // Call test function
  int error = calculate_specmat_eigenvectors(n, Q, ldq, v, S, lds);

  // Check return value
  CU_ASSERT(error == 0);

  // Check eigenvalues
  CU_ASSERT_DOUBLE_EQUAL(v[0], -4.1422, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -3.4771, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0], -0.9082, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0],  0.9082, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  0.0000, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  sum(n, S, lds, X, ldx);

  // Check that X == I
  CU_ASSERT(is_identity(n, X, ldx) == 0);
}

static void test_idealised0() {
  // Moving from closed to open in Castillo_Katz using initial parameters
  // G_FA = zeros(length(EqStates_F));
  // for j = 1:length(EqStates_F)
  //   G_FA = G_FA + exp( V_Q_FF(j)*Sojourn ).*SpecMat_Q_FF{j};
  // end
  // G_FA = G_FA*Q_FA;

  // Input arguments
  const size_t m = 2, n = 1;
  double sojourn = 8.7987e-05;
  double v[] = { -1.1099e+03, -9.0098e+01 };
  const size_t ldq = (m + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] =  0.0000;
  Q[0 * ldq + 1] =  1.0000e+03;
  const size_t lds = (m + 1u) & ~1u;
  double S[lds * m * m];
  S[0 * lds + 0] =  9.7097e-03;
  S[0 * lds + 1] =  9.8058e-02;//-9.8058e-02;
  S[1 * lds + 0] =  9.8058e-02;//-9.8058e-02
  S[1 * lds + 1] =  9.9029e-01;

  S[2 * lds + 0] =  9.9029e-01;
  S[2 * lds + 1] = -9.8058e-02;//9.8058e-02;
  S[3 * lds + 0] = -9.8058e-02;//9.8058e-02;
  S[3 * lds + 1] =  9.7097e-03;

  // Input/output arguments
  double ll[] = { -1.0986, -1.0986 };

  // Call test function
  int error = idealised_transition_probability(m, n, sojourn, v, Q, ldq, S, lds, ll);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(ll[0], 5.7216, 0.0001);
}

static void test_idealised1() {
  // Moving from open to closed in Castillo_Katz using initial parameters
  // G_AF = zeros(length(EqStates_A));
  // for j = 1:length(EqStates_A)
  //   G_AF = G_AF + exp( V_Q_AA(j)*Sojourn ).*SpecMat_Q_AA{j};
  // end
  // G_AF = G_AF*Q_AF;

  // Input arguments
  const size_t m = 1, n = 2;
  double sojourn = 6.9581e-04;
  double v[] = { -1.0000e+03 };
  const size_t ldq = (m + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] = 0.0000;
  Q[1 * ldq + 0] = 1.0000e+03;
  const size_t lds = (m + 1u) & ~1u;
  double S[lds * m * m];
  S[0 * lds + 0] =  1.0000;

  // Input/output arguments
  double ll[] = { 5.7216, 0.0000 };

  // Call test function
  int error = idealised_transition_probability(m, n, sojourn, v, Q, ldq, S, lds, ll);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT(isinf(ll[0]) == -1);
  CU_ASSERT_DOUBLE_EQUAL(ll[1], 11.9335, 0.0001);
}

static void test_idealised2() {
  // Moving from closed to open in Five_State/Five_State_Balanced using initial parameters
  // G_FA = zeros(length(EqStates_F));
  // for j = 1:length(EqStates_F)
  //   G_FA = G_FA + exp( V_Q_FF(j)*Sojourn ).*SpecMat_Q_FF{j};
  // end
  // G_FA = G_FA*Q_FA;

  // Input arguments
  const size_t m = 3, n = 2;
  double sojourn = 6.2719;
  double v[] = { -1.9019e+04, -2.0629e+03, -2.6390e-01 };
  const size_t ldq = (m + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] =  0.0000;
  Q[0 * ldq + 1] =  1.5000e+01;
  Q[0 * ldq + 2] =  0.0000;
  Q[1 * ldq + 0] =  1.5000e+04;
  Q[1 * ldq + 1] =  0.0000;
  Q[1 * ldq + 2] =  0.0000;
  const size_t lds = (m + 1u) & ~1u;
  double S[lds * m * m];
  S[0 * lds + 0] =  0.9993;
  S[0 * lds + 1] = -2.9485e-03;
  S[0 * lds + 2] =  1.5517e-06;
  S[1 * lds + 0] = -2.3588e-01;
  S[1 * lds + 1] =  6.9599e-04;
  S[1 * lds + 2] = -3.6628e-07;
  S[2 * lds + 0] =  2.4827e-02;
  S[2 * lds + 1] = -7.3256e-05;
  S[2 * lds + 2] =  3.8552e-08;

  S[3 * lds + 0] =  6.9342e-04;
  S[3 * lds + 1] =  2.9361e-03;
  S[3 * lds + 2] = -1.4302e-05;
  S[4 * lds + 0] =  2.3489e-01;
  S[4 * lds + 1] =  9.9459e-01;
  S[4 * lds + 2] = -4.8447e-03;
  S[5 * lds + 0] = -2.883e-01;
  S[5 * lds + 1] = -9.6894e-01;
  S[5 * lds + 2] =  4.7198e-03;

  S[6 * lds + 0] =  2.6135e-06;
  S[6 * lds + 1] =  1.2414e-05;
  S[6 * lds + 2] =  1.2750e-05;
  S[7 * lds + 0] =  9.9311e-04;
  S[7 * lds + 1] =  4.7172e-03;
  S[7 * lds + 2] =  4.8451e-03;
  S[8 * lds + 0] =  2.0401e-01;
  S[8 * lds + 1] =  9.6902e-01;
  S[8 * lds + 2] =  9.9528e-01;

  // Input/output arguments
  double ll[] = { -1.1054e+01, -5.5342, -2.3592e-01 };

  // Call test function
  int error = idealised_transition_probability(m, n, sojourn, v, Q, ldq, S, lds, ll);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(ll[0], -4.5079, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(ll[1], -3.5403, 0.0001);
}

static void test_idealised3() {
  // Moving from open to closed in Five_State using initial parameters
  // G_AF = zeros(length(EqStates_A));
  // for j = 1:length(EqStates_F)
  //   G_AF = G_AF + exp( V_Q_AA(j)*Sojourn ).*SpecMat_Q_AA{j};
  // end
  // G_AF = G_AF*Q_AF;

  // Input arguments
  const size_t m = 2, n = 3;
  double sojourn = 2.2389e-01;
  double v[] = { -3.0500e+03, -1.1557 };
  const size_t ldq = (m + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] =  0.0000;
  Q[0 * ldq + 1] =  5.0000e-01;
  Q[1 * ldq + 0] =  3.0000e+03;
  Q[1 * ldq + 1] =  0.0000;
  Q[2 * ldq + 0] =  0.0000;
  Q[2 * ldq + 1] =  0.0000;
  const size_t lds = (m + 1u) & ~1u;
  double S[lds * m * m];
  S[0 * lds + 0] =  1.0000;
  S[0 * lds + 1] = -2.1866e-04;
  S[1 * lds + 0] = -1.6340e-02;
  S[1 * lds + 1] =  3.5860e-06;

  S[2 * lds + 0] =  3.5860e-06;
  S[2 * lds + 1] =  2.1866e-04;
  S[3 * lds + 0] =  1.6340e-02;
  S[3 * lds + 1] =  1.0000;

  // Input/output arguments
  double ll[] = { -4.5079, -3.5403, 0.0 };

  // Call test function
  int error = idealised_transition_probability(m, n, sojourn, v, Q, ldq, S, lds, ll);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(ll[0], -4.4860, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(ll[1], -4.2145, 0.0001);
  CU_ASSERT(isinf(ll[2]) == -1);
}

static void test_idealised4() {
  // Moving from open to closed in Five_State_Balanced using initial parameters
  // G_AF = zeros(length(EqStates_A));
  // for j = 1:length(EqStates_A)
  //   G_AF = G_AF + exp( V_Q_AA(j)*Sojourn ).*SpecMat_Q_AA{j};
  // end
  // G_AF = G_AF*Q_AF;

  // Input arguments
  const size_t m = 2, n = 3;
  double sojourn = 3.2395e-03;
  double v[] = { -3.0500e+03, -5.0065e+02 };
  const size_t ldq = (m + 1u) & ~1u;
  double Q[ldq * n];
  Q[0 * ldq + 0] =  0.0000;
  Q[0 * ldq + 1] =  5.0000e+02;
  Q[1 * ldq + 0] =  3.0000e+03;
  Q[1 * ldq + 1] =  0.0000;
  Q[2 * ldq + 0] =  0.0000;
  Q[2 * ldq + 1] =  0.0000;
  const size_t lds = (m + 1u) & ~1u;
  double S[lds * m * m];
  S[0 * lds + 0] =  1.0000;
  S[0 * lds + 1] = -2.6150e-04;
  S[1 * lds + 0] = -1.9613e-02;
  S[1 * lds + 1] =  5.1288e-06;

  S[2 * lds + 0] =  5.1288e-06;
  S[2 * lds + 1] =  2.6150e-04;
  S[3 * lds + 0] =  1.9613e-02;
  S[3 * lds + 1] =  1.0000;

  // Input/output arguments
  double ll[] = { -4.5438, -3.5762, 0.0000 };
  // Call test function
  int error = idealised_transition_probability(m, n, sojourn, v, Q, ldq, S, lds, ll);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(ll[0],  1.0240, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(ll[1], -5.1161, 0.0001);
  CU_ASSERT(isinf(ll[2]) == -1);
}

#define CUNIT_ERROR(message) \
  do { \
    CU_cleanup_registry(); \
    fprintf(stderr, "%s\nCUnit error code %d in %s (%s:%d): %s\n", \
                     message, CU_get_error(), __func__, __FILE__, __LINE__, \
                     CU_get_error_msg()); \
    return CU_get_error(); \
  } while (0)

int main() {
  CU_ErrorCode error = CU_initialize_registry();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to initialise test registry");

  CU_pSuite eig = CU_add_suite("eig", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(eig, test_eig0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(eig, test_eig1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(eig, test_eig2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(eig, test_eig3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(eig, test_eig4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite inv = CU_add_suite("inv", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(inv, test_inv0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(inv, test_inv1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(inv, test_inv2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(inv, test_inv3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(inv, test_inv4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite specmat = CU_add_suite("specmat", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(specmat, test_specmat0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(specmat, test_specmat1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(specmat, test_specmat2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(specmat, test_specmat3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(specmat, test_specmat4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite idealised = CU_add_suite("idealised", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(idealised, test_idealised0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(idealised, test_idealised1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(idealised, test_idealised2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(idealised, test_idealised3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(idealised, test_idealised4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
