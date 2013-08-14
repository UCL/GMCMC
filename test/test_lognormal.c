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

static void test_create() {
  gmcmc_distribution * lognormal = NULL;

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, NAN, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, NAN, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, INFINITY, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, -INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, INFINITY, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, INFINITY, -INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);
}

static void test_lognormal01() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, -INFINITY), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  INFINITY), 0.0, 1.0e-15);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(lognormal,  INFINITY)) == -1);

  // Test limits of 2nd order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(lognormal,  INFINITY)) == -1);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_pdf(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_1st_order(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_2nd_order(lognormal, NAN)));

  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('logn','mu',0,'sigma',1); for i=1:10; x = random('logn',0,1); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd, x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  1.712008323467287), 0.201664742855459, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  6.258152505240481), 0.011862291742214, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  0.104470884773661), 0.297813971852448, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  2.368302184003618), 0.116160401583884, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  1.375428391238457), 0.275681404336157, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  0.270444521917488), 0.627335008603283, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  0.648176643161933), 0.560263801647808, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  1.408639671255502), 0.267066186369014, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 35.816079468166791), 0.000018461966590, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 15.949652304221461), 0.000540364690088, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(lognormal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 1.64872127070013, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL(variance, 4.67077427047161, 1.0e-03);
}

static void test_lognormal005() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.05) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, -INFINITY), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  INFINITY), 0.0, 1.0e-15);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(lognormal,  INFINITY)) == -1);

  // Test limits of 2nd order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(lognormal,  INFINITY)) == -1);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_pdf(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_1st_order(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_2nd_order(lognormal, NAN)));

  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('logn','mu',0,'sigma',0.5); for i=1:10; x = random('logn',0,0.5); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd, x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.308437359397570), 0.527731367250773, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 2.501629969687860), 0.059350129063005, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 0.323219561248481), 0.192518602631632, 1.0e-14);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.538928908040790), 0.357525199934134, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.172786592368133), 0.646630909541326, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 0.520042807774022), 0.652482118577983, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 0.805094182789773), 0.902130255068667, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.186861268748585), 0.633941025587549, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 5.984653663176074), 0.000220976951967, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 3.993701579264713), 0.004316110632368, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(lognormal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 1.13314845306683, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL(variance, 0.364695854012387, 1.0e-03);
}

static void test_lognormal0025() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.025) == 0);

  // Test limits of PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, -INFINITY), 0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal,  INFINITY), 0.0, 1.0e-15);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_1st_order(lognormal,  INFINITY)) == -1);

  // Test limits of 2nd order PDF
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_pdf_2nd_order(lognormal,  INFINITY)) == -1);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_pdf(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_1st_order(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_pdf_2nd_order(lognormal, NAN)));

  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('logn','mu',0,'sigma',0.25); for i=1:10; x = random('logn',0,0.25); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd, x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.143869467814213), 1.207311596412018, 1.0e-14);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.581654187769204), 0.187742760354290, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 0.568524019939775), 0.218902899762647, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.240535734286115), 0.887045572852161, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.082952719359499), 1.400541403819369, 1.0e-14);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 0.721139936332763), 0.941061826899187, 1.0e-14);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 0.897270406727968), 1.618909561774137, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.089431626467942), 1.381270805181196, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 2.446355179277137), 0.001081176221891, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(lognormal, 1.998424774482320), 0.017250844834262, 1.0e-15);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(lognormal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, 1.03174340749910, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL(variance, 0.0686539941489670, 1.0e-03);
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

  CU_pSuite lognormal = CU_add_suite("lognormal", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(lognormal, test_create);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(lognormal, test_lognormal01);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(lognormal, test_lognormal005);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(lognormal, test_lognormal0025);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
