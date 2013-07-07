#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "src/ion_model.c"

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
  CU_ASSERT_DOUBLE_EQUAL(v[0], -1109.9020, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1],   -90.0980, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0],  0.0097, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1], -0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0], -0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1],  0.9903, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0],  0.9903, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1],  0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0],  0.0981, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  0.0097, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      X[j * ldx + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      for (size_t i = 0; i < n; i++)
        X[j * ldx + i] += S[(k * n * lds) + j * lds + i];
    }
  }

  // Check that X == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(X[j * ldx + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      X[j * ldx + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      for (size_t i = 0; i < n; i++)
        X[j * ldx + i] += S[(k * n * lds) + j * lds + i];
    }
  }

  // Check that X == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(X[j * ldx + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0], -1.0478, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 2], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0],  0.3209, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 2], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[4 * lds + 0],  1.0478, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[4 * lds + 1],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[4 * lds + 2], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[5 * lds + 0], -0.7725, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[5 * lds + 1], -0.7373, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[5 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[6 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[6 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[6 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[7 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[7 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[7 * lds + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[8 * lds + 0],  0.4516, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[8 * lds + 1],  0.7373, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[8 * lds + 2],  1.0000, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      X[j * ldx + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      for (size_t i = 0; i < n; i++)
        X[j * ldx + i] += S[(k * n * lds) + j * lds + i];
    }
  }

  // Check that X == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(X[j * ldx + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  CU_ASSERT_DOUBLE_EQUAL(v[0], -3.4771, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1],  1.2553, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1],  0.2016, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1], -0.2016, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  1.0000, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      X[j * ldx + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      for (size_t i = 0; i < n; i++)
        X[j * ldx + i] += S[(k * n * lds) + j * lds + i];
    }
  }

  // Check that X == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(X[j * ldx + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  CU_ASSERT_DOUBLE_EQUAL(v[0], -3.4771, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -4.1422, 0.0001);

  // Check spectral matrices
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 0],  1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[0 * lds + 1],  2.1700, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[1 * lds + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 0],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[2 * lds + 1], -2.1700, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(S[3 * lds + 1],  1.0000, 0.0001);

  // Calculate the sum of the spectral matrices
  const size_t ldx = (n + 1u) & ~1u;
  double X[ldx * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      X[j * ldx + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      for (size_t i = 0; i < n; i++)
        X[j * ldx + i] += S[(k * n * lds) + j * lds + i];
    }
  }

  // Check that X == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(X[j * ldx + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
}

#define CUNIT_ERROR(message) \
  do { \
    CU_cleanup_registry(); \
    fprintf(stderr, "%s\nCUnit error code %d in %s (%s:%d): %s\n", \
                     message, CU_get_error(), __func__, __FILE__, __LINE__, \
                     CU_get_error_msg()); \
    return CU_get_error(); \
  } while (0)

int main(int argc, char * argv[]) {
  CU_ErrorCode error = CU_initialize_registry();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to initialise test registry");

  CU_pSuite suite = CU_add_suite("specmat", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(suite, test_specmat0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_specmat1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_specmat2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_specmat3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_specmat4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
