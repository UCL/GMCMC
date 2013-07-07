#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "src/ion_model.c"

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
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XY[j * ldxy + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = Y[j * ldy + k];
      for (size_t i = 0; i < n; i++)
        XY[j * ldxy + i] += temp * X[k * ldx + i];
    }
  }

  // Check that X*Y == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XY[j * ldxy + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XY[j * ldxy + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = Y[j * ldy + k];
      for (size_t i = 0; i < n; i++)
        XY[j * ldxy + i] += temp * X[k * ldx + i];
    }
  }

  // Check that X*Y == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XY[j * ldxy + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XY[j * ldxy + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = Y[j * ldy + k];
      for (size_t i = 0; i < n; i++)
        XY[j * ldxy + i] += temp * X[k * ldx + i];
    }
  }

  // Check that X*Y == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XY[j * ldxy + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XY[j * ldxy + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = Y[j * ldy + k];
      for (size_t i = 0; i < n; i++)
        XY[j * ldxy + i] += temp * X[k * ldx + i];
    }
  }

  // Check that X*Y == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XY[j * ldxy + i], (i == j) ? 1.0 : 0.0, 0.0001);
  }
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
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      XY[j * ldxy + i] = 0.0;
    for (size_t k = 0; k < n; k++) {
      double temp = Y[j * ldy + k];
      for (size_t i = 0; i < n; i++)
        XY[j * ldxy + i] += temp * X[k * ldx + i];
    }
  }

  // Check that X*Y == I
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      CU_ASSERT_DOUBLE_EQUAL(XY[j * ldxy + i], (i == j) ? 1.0 : 0.0, 0.0001);
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

  CU_pSuite suite = CU_add_suite("inv", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(suite, test_inv0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_inv1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_inv2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_inv3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_inv4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
