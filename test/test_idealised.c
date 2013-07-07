#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "src/ion_model.c"

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

int main(int argc, char * argv[]) {
  CU_ErrorCode error = CU_initialize_registry();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to initialise test registry");

  CU_pSuite suite = CU_add_suite("idealised", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(suite, test_idealised0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_idealised1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_idealised2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_idealised3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(suite, test_idealised4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
