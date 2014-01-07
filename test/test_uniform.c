#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_distribution.h>
#include <math.h>
#include <fenv.h>

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

static void test_create() {
  gmcmc_distribution * uniform = NULL;

  // Temporarily disable the error handler
  gmcmc_error_handler_t error_handler = gmcmc_error_handler;
  gmcmc_error_handler = NULL;

  // upper == lower
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, 0.0, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(uniform);

  // lower > upper
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, 1.0, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(uniform);

  // NaN lower
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, NAN, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(uniform);

  // NaN upper
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, 0.0, NAN), GMCMC_EINVAL);

  // NaN lower and upper
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, NAN, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(uniform);

  // -Inf lower
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, -INFINITY, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(uniform);

  // Inf upper
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, 0.0, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(uniform);

  // -Inf lower, Inf upper
  CU_ASSERT_EQUAL(gmcmc_distribution_create_uniform(&uniform, -INFINITY, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(uniform);

  // Restore the error handler
  gmcmc_error_handler = error_handler;
}

static void test_uniform01() {
  // Create the distribution
  gmcmc_distribution * uniform;
  CU_ASSERT_FATAL(gmcmc_distribution_create_uniform(&uniform, 0.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(uniform, 0.0)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(uniform, 1.0)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(uniform, 0.0)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(uniform, 1.0)));

  // Test limits of 2nd order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(uniform, 0.0)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(uniform, 1.0)));

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(uniform, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(uniform, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(uniform, NAN)));

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(uniform, rng);

    // Test range
    CU_ASSERT(x > 0.0);
    CU_ASSERT(x < 1.0);

    // Test PDF
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf(uniform, x), 0.0, 1.0e-15);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 0.5, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(variance, 0.083333, 1.0e-04);

  gmcmc_distribution_destroy(uniform);
}

static void test_uniform11() {
  // Create the distribution
  gmcmc_distribution * uniform;
  CU_ASSERT_FATAL(gmcmc_distribution_create_uniform(&uniform, -1.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(uniform, -1.0)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(uniform,  1.0)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(uniform, -1.0)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(uniform,  1.0)));

  // Test limits of 2nd order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(uniform, -1.0)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(uniform,  1.0)));

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(uniform, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(uniform, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(uniform, NAN)));

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(uniform, rng);

    // Test range
    CU_ASSERT(x > -1.0);
    CU_ASSERT(x <  1.0);

    // Test PDF
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf(uniform, x), -0.693147180559945, 1.0e-07);
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_1st_order(uniform, x), 0.0, 1.0e-15);
    CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_2nd_order(uniform, x), 0.0, 1.0e-15);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 0.0, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(variance, 0.333333, 1.0e-04);

  gmcmc_distribution_destroy(uniform);
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

  CU_pSuite uniform = CU_add_suite("uniform", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(uniform, test_create);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite uniform01 = CU_add_suite("uniform(0,1)", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(uniform01, test_uniform01);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite uniform11 = CU_add_suite("uniform(1,1)", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(uniform11, test_uniform11);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return error;
}
