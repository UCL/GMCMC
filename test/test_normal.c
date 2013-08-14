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
  gmcmc_distribution * normal = NULL;

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, NAN, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, NAN, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, INFINITY, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, -INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, INFINITY, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, INFINITY, -INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);
}

static void test_normal01() {
  // Create the distribution
  gmcmc_distribution * normal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_normal(&normal, 0.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -INFINITY), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  INFINITY), 0.0, 1.0e-15);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(normal,  INFINITY)) ==  1);

  // Test limits of 2nd order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(normal,  INFINITY)) ==  1);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_pdf(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_1st_order(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_2nd_order(normal, NAN)));

  // Samples chosen from Matlab:
  //   rng(0, 'twister'); for i=1:10; x = randn(1); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, %.15f), %.15f, 1.0e-15);\n', x, normpdf(x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  0.537667139546100), 0.345251718318436, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  1.833885014595086), 0.074236030784428, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -2.258846861003648), 0.031112889137383, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  0.862173320368121), 0.275102932765851, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  0.318765239858981), 0.379180030460439, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -1.307688296305273), 0.169659316483818, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -0.433592022305684), 0.363149910237219, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  0.342624466538650), 0.376200024970309, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  3.578396939725760), 0.000661235262534, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  2.769437029884877), 0.008618628924385, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(normal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 0.0, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL(variance, 1.0, 1.0e-03);
}

static void test_normal11() {
  // Create the distribution
  gmcmc_distribution * normal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_normal(&normal, 1.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -INFINITY), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  INFINITY), 0.0, 1.0e-15);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(normal,  INFINITY)) ==  1);

  // Test limits of 2nd order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(normal,  INFINITY)) ==  1);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_pdf(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_1st_order(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_2nd_order(normal, NAN)));

  // Samples chosen from Matlab:
  //   rng(0, 'twister'); for i=1:10; x = 1.0 + randn(1); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, %.15f), %.15f, 1.0e-15);\n', x, normpdf(x, 1.0, 1.0)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  1.537667139546100), 0.345251718318436, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  2.833885014595086), 0.074236030784428, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -1.258846861003648), 0.031112889137383, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  1.862173320368121), 0.275102932765851, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  1.318765239858981), 0.379180030460439, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -0.307688296305273), 0.169659316483818, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  0.566407977694317), 0.363149910237219, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  1.342624466538650), 0.376200024970309, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  4.578396939725760), 0.000661235262534, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  3.769437029884877), 0.008618628924385, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(normal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 1.0, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL(variance, 1.0, 1.0e-03);
}

static void test_normal15() {
  // Create the distribution
  gmcmc_distribution * normal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_normal(&normal, 1.0, 5.0) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -INFINITY), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  INFINITY), 0.0, 1.0e-15);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(normal,  INFINITY)) ==  1);

  // Test limits of 2nd order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(normal,  INFINITY)) ==  1);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_pdf(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_1st_order(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_2nd_order(normal, NAN)));

  // Samples chosen from Matlab:
  //   rng(0, 'twister'); for i=1:10; x = 1.0 + randn(1) * 5.0; fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, %.15f), %.15f, 1.0e-15);\n', x, normpdf(x, 1.0, 5.0)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,   3.688335697730500), 0.069050343663687, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  10.169425072975432), 0.014847206156886, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal, -10.294234305018239), 0.006222577827477, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,   5.310866601840603), 0.055020586553170, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,   2.593826199294904), 0.075836006092088, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  -5.538441481526367), 0.033931863296764, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  -1.167960111528418), 0.072629982047444, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,   2.713122332693250), 0.075240004994062, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  18.891984698628804), 0.000132247052507, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(normal,  14.847185149424385), 0.001723725784877, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(normal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 1.0, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL(variance, 25.0, 1.0e-03);
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

  CU_pSuite normal = CU_add_suite("normal", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(normal, test_create);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(normal, test_normal01);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(normal, test_normal11);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(normal, test_normal15);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
