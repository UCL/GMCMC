#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "src/ion_model.c"

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
  CU_ASSERT_DOUBLE_EQUAL(v[0], -1109.9020, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1],   -90.0980, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0], -0.0985, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1],  0.9951, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0], -0.9951, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1], -0.0985, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      D[j * ldd + i] = 0.0;
    D[j * ldd + j] = v[j];
    for (size_t i = j + 1; i < n; i++)
      D[j * ldd + i] = 0.0;
  }

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XV[j * ldxv + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = V[j * ldv + k];
      for (size_t i = 0; i < n; i++)
        XV[j * ldxv + i] += temp * X[k * ldx + i];
    }
  }

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      VD[j * ldvd + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = D[j * ldd + k];
      for (size_t i = 0; i < n; i++)
        VD[j * ldvd + i] += temp * V[k * ldv + i];
    }
  }

  // Check that X*V == V*D
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XV[j * ldxv + i], VD[j * ldvd + i], 0.0001);
  }
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
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      D[j * ldd + i] = 0.0;
    D[j * ldd + j] = v[j];
    for (size_t i = j + 1; i < n; i++)
      D[j * ldd + i] = 0.0;
  }

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XV[j * ldxv + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = V[j * ldv + k];
      for (size_t i = 0; i < n; i++)
        XV[j * ldxv + i] += temp * X[k * ldx + i];
    }
  }

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      VD[j * ldvd + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = D[j * ldd + k];
      for (size_t i = 0; i < n; i++)
        VD[j * ldvd + i] += temp * V[k * ldv + i];
    }
  }

  // Check that X*V == V*D
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XV[j * ldxv + i], VD[j * ldvd + i], 0.0001);
  }
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
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0], -1.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 2], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0], -0.7234, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1], -0.6904, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 2],  0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[2 * ldv + 0],  0.3416, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[2 * ldv + 1],  0.5577, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[2 * ldv + 2],  0.7564, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      D[j * ldd + i] = 0.0;
    D[j * ldd + j] = v[j];
    for (size_t i = j + 1; i < n; i++)
      D[j * ldd + i] = 0.0;
  }

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XV[j * ldxv + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = V[j * ldv + k];
      for (size_t i = 0; i < n; i++)
        XV[j * ldxv + i] += temp * X[k * ldx + i];
    }
  }

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      VD[j * ldvd + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = D[j * ldd + k];
      for (size_t i = 0; i < n; i++)
        VD[j * ldvd + i] += temp * V[k * ldv + i];
    }
  }

  // Check that X*V == V*D
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XV[j * ldxv + i], VD[j * ldvd + i], 0.0001);
  }
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
  CU_ASSERT_DOUBLE_EQUAL(v[0], -3.4771, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1],  1.2553, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0], -0.9803, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1], -0.1977, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1], -1.0000, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      D[j * ldd + i] = 0.0;
    D[j * ldd + j] = v[j];
    for (size_t i = j + 1; i < n; i++)
      D[j * ldd + i] = 0.0;
  }

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XV[j * ldxv + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = V[j * ldv + k];
      for (size_t i = 0; i < n; i++)
        XV[j * ldxv + i] += temp * X[k * ldx + i];
    }
  }

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      VD[j * ldvd + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = D[j * ldd + k];
      for (size_t i = 0; i < n; i++)
        VD[j * ldvd + i] += temp * V[k * ldv + i];
    }
  }

  // Check that X*V == V*D
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XV[j * ldxv + i], VD[j * ldvd + i], 0.0001);
  }
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
  CU_ASSERT_DOUBLE_EQUAL(v[0], -3.4771, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(v[1], -4.1422, 0.0001);

  // Check eigenvectors
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 0],  0.4185, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[0 * ldv + 1],  0.9082, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 0], -0.0000, 0.0001);
  CU_ASSERT_DOUBLE_EQUAL(V[1 * ldv + 1],  1.0000, 0.0001);

  // D is matrix X in Schur form
  const size_t ldd = (n + 1u) & ~1u;
  double D[ldd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      D[j * ldd + i] = 0.0;
    D[j * ldd + j] = v[j];
    for (size_t i = j + 1; i < n; i++)
      D[j * ldd + i] = 0.0;
  }

  // Calculate X*V
  const size_t ldxv = (n + 1u) & ~1u;
  double XV[ldxv * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XV[j * ldxv + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = V[j * ldv + k];
      for (size_t i = 0; i < n; i++)
        XV[j * ldxv + i] += temp * X[k * ldx + i];
    }
  }

  // Calculate V*D
  const size_t ldvd = (n + 1u) & ~1u;
  double VD[ldvd * n];
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      VD[j * ldvd + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = D[j * ldd + k];
      for (size_t i = 0; i < n; i++)
        VD[j * ldvd + i] += temp * V[k * ldv + i];
    }
  }

  // Check that X*V == V*D
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XV[j * ldxv + i], VD[j * ldvd + i], 0.0001);
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

  CU_pSuite suite = CU_add_suite("eig", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(suite, test_eig0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_eig1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_eig2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_eig3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_eig4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
