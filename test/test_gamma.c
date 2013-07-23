#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_distribution.h>

#define N 100000000

static gmcmc_prng64 * rng;
static gmcmc_distribution * gamma;
static double expected_mean, expected_variance;

static int init_1_05() {
  int error;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_mt19937_64, 0)) != 0)
    GMCMC_ERROR("Failed to create RNG", error);
  expected_mean = 0.5;
  expected_variance = 0.25;
  if ((error = gmcmc_distribution_create_gamma(&gamma, 1.0, 0.5)) != 0)
    GMCMC_ERROR("Failed to create gamma distribution", error);
  return 0;
}

static int init_2_05() {
  int error;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_mt19937_64, 0)) != 0)
    GMCMC_ERROR("Failed to create RNG", error);
  expected_mean = 1.0;
  expected_variance = 0.5;
  if ((error = gmcmc_distribution_create_gamma(&gamma, 2.0, 0.5)) != 0)
    GMCMC_ERROR("Failed to create gamma distribution", error);
  return 0;
}

static int init_3_05() {
  int error;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_mt19937_64, 0)) != 0)
    GMCMC_ERROR("Failed to create RNG", error);
  expected_mean = 1.5;
  expected_variance = 0.75;
  if ((error = gmcmc_distribution_create_gamma(&gamma, 3.0, 0.5)) != 0)
    GMCMC_ERROR("Failed to create gamma distribution", error);
  return 0;
}

static int init_5_1() {
  int error;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_mt19937_64, 0)) != 0)
    GMCMC_ERROR("Failed to create RNG", error);
  expected_mean = 5.0;
  expected_variance = 5.0;
  if ((error = gmcmc_distribution_create_gamma(&gamma, 5.0, 1.0)) != 0)
    GMCMC_ERROR("Failed to create gamma distribution", error);
  return 0;
}

static int init_9_2() {
  int error;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_mt19937_64, 0)) != 0)
    GMCMC_ERROR("Failed to create RNG", error);
  expected_mean = 18.0;
  expected_variance = 36.0;
  if ((error = gmcmc_distribution_create_gamma(&gamma, 9.0, 2.0)) != 0)
    GMCMC_ERROR("Failed to create gamma distribution", error);
  return 0;
}

static int cleanup() {
  gmcmc_distribution_destroy(gamma);
  gmcmc_prng64_destroy(rng);
  return 0;
}

static void test_sample() {
  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(gamma, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT_DOUBLE_EQUAL(mean, expected_mean, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(variance, expected_variance, 1.0e-02);
}

static void test_pdf_1_05() {
  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('gamma','a',1,'b',0.5); for i=1:10; x = random('gamma',1,0.5); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd,x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.782420172547005), 0.056603007194808, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.823740278388989), 0.385068755001938, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.033761647896398), 1.869411891292722, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.493686675784713), 0.745107950567125, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 3.741470920837533), 0.001125199797727, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.308248255974182), 1.079664849686903, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.256462839973681), 1.197482576872556, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.386346465996600), 0.124986974459529, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.311195024139427), 0.145258136483790, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.043452984992303), 1.833526589694318, 1.0e-15);
}

static void test_pdf_2_05() {
  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('gamma','a',2,'b',0.5); for i=1:10; x = random('gamma',2,0.5); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd,x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 2.666093831133728), 0.051546091832466, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.522947467576099), 0.289687363783276, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.242155219675207), 0.596788539784572, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.074638678075194), 0.501075493626470, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 4.728476950005852), 0.001478013406010, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.793290644395063), 0.649305116360592, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.707906641842118), 0.687315411158653, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 2.212217100646737), 0.106018188012722, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 2.123695119092765), 0.121488177567665, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.271654046006495), 0.631132381052327, 1.0e-15);
}

static void test_pdf_3_05() {
  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('gamma','a',3,'b',0.5); for i=1:10; x = random('gamma',3,0.5); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd,x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 3.461158573343483), 0.047225748127517, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 2.168453218243133), 0.245960615884652, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.525259280166670), 0.385987326927419, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.633106410751510), 0.406996574036367, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 5.663468972854375), 0.001545248731726, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.282509054795532), 0.506066582766374, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 1.172883446052087), 0.527006640751124, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 2.957022899081561), 0.094478265342364, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 2.857483276854746), 0.107658654458715, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 0.570463506951977), 0.415927293267128, 1.0e-15);
}

static void test_pdf_5_1() {
  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('gamma','a',5,'b',1); for i=1:10; x = random('gamma',5,1); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd,x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  9.855098229264238), 0.020626132739342, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  6.787942801299136), 0.099718411697439, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  2.373413884332668), 0.123174871984540, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  5.446640201794376), 0.158073009888774, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 14.772369556650514), 0.000762133111297, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  4.531773579818210), 0.189119935884333, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  4.237745438361755), 0.194043347847911, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  8.681193948667552), 0.040170937386172, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  8.446430237494368), 0.045524324666986, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma,  2.514020775007874), 0.134722104150597, 1.0e-15);
}

static void test_pdf_9_2() {
  // Samples chosen from Matlab:
  //   rng(0, 'twister'); pd = makedist('gamma','a',9,'b',2); for i=1:10; x = random('gamma',9,2); fprintf('CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, %.15f), %.15f, 1.0e-15);\n', x, pdf(pd,x)); end
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 30.528232846468995), 0.008584229221574, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 22.921360182019267), 0.038888615183944, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 10.717638685148414), 0.039691429564277, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 19.429924621458792), 0.059405125562790, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 42.046355144053486), 0.000350579355247, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 16.964720595645268), 0.068824162507171, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 16.154316584652875), 0.069767467313453, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 27.667084325468210), 0.016333740037534, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 27.088111290023239), 0.018421741621763, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_pdf(gamma, 11.151560934578809), 0.043889852447851, 1.0e-15);
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

  CU_pSuite gamma_1_05 = CU_add_suite("gamma(1,0.5)", init_1_05, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(gamma_1_05, test_sample);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma_1_05, test_pdf_1_05);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite gamma_2_05 = CU_add_suite("gamma(2,0.5)", init_2_05, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(gamma_2_05, test_sample);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma_2_05, test_pdf_2_05);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite gamma_3_05 = CU_add_suite("gamma(3,0.5)", init_3_05, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(gamma_3_05, test_sample);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma_3_05, test_pdf_3_05);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite gamma_5_1 = CU_add_suite("gamma(5,1)", init_3_05, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(gamma_5_1, test_sample);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma_5_1, test_pdf_5_1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_pSuite gamma_9_2 = CU_add_suite("gamma(9,2)", init_9_2, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(gamma_9_2, test_sample);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma_9_2, test_pdf_9_2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
