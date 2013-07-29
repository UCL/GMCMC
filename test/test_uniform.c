#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_distribution.h>

#define N 100000000

static gmcmc_prng64 * rng;

static int init() {
  int error;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_mt19937_64, 0)) != 0)
    GMCMC_ERROR("Failed to create RNG", error);
  return 0;
}

static int cleanup() {
  gmcmc_prng64_destroy(rng);
  return 0;
}

static void test_uniform_m2_4() {
  // Uniform prior from Castillo Katz in log space

  // Create the distribution
  gmcmc_distribution * uniform;
  CU_ASSERT_FATAL(gmcmc_distribution_create_uniform(&uniform, -2.0, 4.0) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, -2.0), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform,  4.0), 0.0, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(uniform, rng);

    // Test range
    CU_ASSERT(x > -2.0);
    CU_ASSERT(x <  4.0);

    // Test PDF
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, x), 0.166666666666667, 1.0e-15);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 1.0, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(variance, 3.0, 1.0e-04);
}

static void test_uniform_0_10000() {
  // Uniform prior from Castillo Katz

  // Create the distribution
  gmcmc_distribution * uniform;
  CU_ASSERT_FATAL(gmcmc_distribution_create_uniform(&uniform, 0.0, 10000.0) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform,     0.0), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, 10000.0), 0.0, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(uniform, rng);

    // Test range
    CU_ASSERT(x >     0.0);
    CU_ASSERT(x < 10000.0);

    // Test PDF
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, x), 0.0001, 1.0e-15);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 5000.0, 1.0e-01);
  CU_ASSERT_DOUBLE_EQUAL(variance, 8333333.3333, 1.0e+03);
}

static void test_uniform_m2_10() {
  // Uniform prior from Five State in log space

  // Create the distribution
  gmcmc_distribution * uniform;
  CU_ASSERT_FATAL(gmcmc_distribution_create_uniform(&uniform, -2.0, 10.0) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, -2.0), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, 10.0), 0.0, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(uniform, rng);

    // Test range
    CU_ASSERT(x > -2.0);
    CU_ASSERT(x < 10.0);

    // Test PDF
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, x), 0.083333333333333, 1.0e-15);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 4.0, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(variance, 12.0, 1.0e-03);
}

static void test_uniform_1em2_1e9() {
  // Uniform prior from Five State

  // Create the distribution
  gmcmc_distribution * uniform;
  CU_ASSERT_FATAL(gmcmc_distribution_create_uniform(&uniform, 1.0e-02, 1.0e+09) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, 1.0e-02), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, 1.0e+09), 0.0, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(uniform, rng);

    // Test range
    CU_ASSERT(x > 1.0e-02);
    CU_ASSERT(x < 1.0e+09);

    // Test PDF
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(uniform, x), 1.0e-09, 1.0e-13);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 5.0e+08, 1.0e+05);
  CU_ASSERT_DOUBLE_EQUAL(variance, 8.333333e+16, 1.0e+13);
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

  CU_pSuite uniform_m2_4 = CU_add_suite("uniform(-2,4)", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(uniform_m2_4, test_uniform_m2_4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite uniform_0_10000 = CU_add_suite("uniform(0,10000)", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(uniform_0_10000, test_uniform_0_10000);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite uniform_m2_10 = CU_add_suite("uniform(-2,10)", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(uniform_m2_10, test_uniform_m2_10);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite uniform_1em2_1e9 = CU_add_suite("uniform(1.0e-02,1.0e+09)", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(uniform_1em2_1e9, test_uniform_1em2_1e9);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
