#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_distribution.h>
#include <math.h>

#define N 100000000

#define CU_ASSERT_DOUBLE_EQUAL_ABS(actual, expected, granularity) \
  CU_assertImplementation(((fabs((double)(actual) - (expected)) <= fabs((double)(granularity)))), __LINE__, ("CU_ASSERT_DOUBLE_EQUAL_ABS(" #actual ","  #expected "," #granularity ")"), __FILE__, "", CU_FALSE)
#define CU_ASSERT_DOUBLE_EQUAL_ABS_FATAL(actual, expected, granularity) \
  CU_assertImplementation(((fabs((double)(actual) - (expected)) <= fabs((double)(granularity)))), __LINE__, ("CU_ASSERT_DOUBLE_EQUAL_ABS_FATAL(" #actual ","  #expected "," #granularity ")"), __FILE__, "", CU_TRUE)
#define CU_ASSERT_DOUBLE_EQUAL_REL(actual, expected, granularity) \
  CU_assertImplementation(( \
    fabs(expected) > 0.0 ? \
    ((fabs((double)(actual) - (expected)) / fabs(expected)) <= fabs((double)(granularity))) : \
    ((fabs((double)(actual) - (expected))) <= fabs((double)(granularity)))), __LINE__, ("CU_ASSERT_DOUBLE_EQUAL_REL(" #actual ","  #expected "," #granularity ")"), __FILE__, "", CU_FALSE)
#define CU_ASSERT_DOUBLE_EQUAL_REL_FATAL(actual, expected, granularity) \
  CU_assertImplementation(( \
    fabs(expected) > 0.0 ? \
    ((fabs((double)(actual) - (expected)) / fabs(expected)) <= fabs((double)(granularity))) : \
    ((fabs((double)(actual) - (expected))) <= fabs((double)(granularity)))), __LINE__, ("CU_ASSERT_DOUBLE_EQUAL_REL_FATAL(" #actual ","  #expected "," #granularity ")"), __FILE__, "", CU_TRUE)

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
  gmcmc_distribution * gamma = NULL;

  // Temporarily disable the error handler
  gmcmc_error_handler_t error_handler = gmcmc_error_handler;
  gmcmc_error_handler = NULL;

  // Zero a fails
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, 0.0, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // Negative a fails
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, -1.0e-07, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // Zero b fails
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, 1.0, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // Negative b fails
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, 1.0, -1.0e-07), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // NaN a
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, NAN, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // NaN b
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, 1.0, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // NaN a and b
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, NAN, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // Infinite a fails
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, INFINITY, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // Infinite b fails
  CU_ASSERT_EQUAL(gmcmc_distribution_create_gamma(&gamma, 1.0, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(gamma);

  // Restore the error handler
  gmcmc_error_handler = error_handler;
}

static void test_gamma11() {
  // Create the distribution
  gmcmc_distribution * gamma;
  CU_ASSERT_FATAL(gmcmc_distribution_create_gamma(&gamma, 1.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(gamma, -1.0e-07)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(gamma, INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, -1.0e-07)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, INFINITY)));

  // Test limits of 2nd order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, -1.0e-07)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, INFINITY)));

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(gamma, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // gamma = makedist('Gamma', 'a', 1.0, 'b', 1.0);
  // for i=1:10;
  //   x = random(gamma);
  //   y = logpdf(gamma, autodiff(x));
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 3.564840345094010), -3.564840345094010, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 3.564840345094010), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 3.564840345094010), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 1.647480556777979), -1.647480556777979, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 1.647480556777979), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 1.647480556777979), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 0.067523295792796), -0.067523295792796, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 0.067523295792796), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 0.067523295792796), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 0.987373351569427), -0.987373351569427, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 0.987373351569427), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 0.987373351569427), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 7.482941841675066), -7.482941841675066, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 7.482941841675066), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 7.482941841675066), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 0.616496511948365), -0.616496511948365, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 0.616496511948365), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 0.616496511948365), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 0.512925679947363), -0.512925679947363, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 0.512925679947363), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 0.512925679947363), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 2.772692931993200), -2.772692931993200, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 2.772692931993200), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 2.772692931993200), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 2.622390048278854), -2.622390048278854, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 2.622390048278854), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 2.622390048278854), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 0.086905969984606), -0.086905969984606, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 0.086905969984606), -1.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 0.086905969984606), 0.000000000000000, 1.0e-07);

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

  CU_ASSERT_DOUBLE_EQUAL_REL(mean, 1.0, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL_REL(variance, 1.0, 1.0e-03);
}

static void test_gamma12() {
  // Create the distribution
  gmcmc_distribution * gamma;
  CU_ASSERT_FATAL(gmcmc_distribution_create_gamma(&gamma, 1.0, 2.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(gamma, -1.0e-07)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(gamma, INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, -1.0e-07)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, INFINITY)));

  // Test limits of 2nd order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, -1.0e-07)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, INFINITY)));

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(gamma, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // gamma = makedist('Gamma', 'a', 1.0, 'b', 2.0);
  // for i=1:10;
  //   x = random(gamma);
  //   y = logpdf(gamma, autodiff(x));
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 7.129680690188019), -4.257987525653955, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 7.129680690188019), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 7.129680690188019), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 3.294961113555958), -2.340627737337924, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 3.294961113555958), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 3.294961113555958), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 0.135046591585592), -0.760670476352741, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 0.135046591585592), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 0.135046591585592), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 1.974746703138853), -1.680520532129372, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 1.974746703138853), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 1.974746703138853), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 14.965883683350132), -8.176089022235011, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 14.965883683350132), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 14.965883683350132), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 1.232993023896729), -1.309643692508310, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 1.232993023896729), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 1.232993023896729), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 1.025851359894725), -1.206072860507308, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 1.025851359894725), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 1.025851359894725), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 5.545385863986399), -3.465840112553145, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 5.545385863986399), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 5.545385863986399), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 5.244780096557709), -3.315537228838800, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 5.244780096557709), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 5.244780096557709), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 0.173811939969212), -0.780053150544551, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 0.173811939969212), -0.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 0.173811939969212), 0.000000000000000, 1.0e-07);

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

  CU_ASSERT_DOUBLE_EQUAL_REL(mean, 2.0, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL_REL(variance, 4.0, 1.0e-03);
}

static void test_gamma52() {
  // Create the distribution
  gmcmc_distribution * gamma;
  CU_ASSERT_FATAL(gmcmc_distribution_create_gamma(&gamma, 5.0, 2.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(gamma, -1.0e-07)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(gamma, INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, -1.0e-07)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, INFINITY)));

  // Test limits of 2nd order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, -1.0e-07)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, INFINITY)));

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(gamma, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(gamma, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(gamma, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // gamma = makedist('Gamma', 'a', 5.0, 'b', 2.0);
  // for i=1:10;
  //   x = random(gamma);
  //   y = logpdf(gamma, autodiff(x));
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, %.15f), %.15f, 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 19.710196458528475), 62.341897871701995, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 19.710196458528475), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 19.710196458528475), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 13.575885602598271), 40.871809875946276, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 13.575885602598271), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 13.575885602598271), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 4.746827768665336), 9.970107457181001, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 4.746827768665336), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 4.746827768665336), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 10.893280403588752), 31.482691679412962, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 10.893280403588752), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 10.893280403588752), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 29.544739113301027), 96.762797163405921, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 29.544739113301027), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 29.544739113301027), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 9.063547159636419), 25.078625325579797, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 9.063547159636419), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 9.063547159636419), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 8.475490876723510), 23.020428335384615, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 8.475490876723510), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 8.475490876723510), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 17.362387897335104), 54.124567907525190, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 17.362387897335104), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 17.362387897335104), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 16.892860474988737), 52.481221929312909, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 16.892860474988737), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 16.892860474988737), 0.000000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(gamma, 5.028041550015748), 10.954355691907445, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(gamma, 5.028041550015748), 3.500000000000000, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(gamma, 5.028041550015748), 0.000000000000000, 1.0e-07);

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

  CU_ASSERT_DOUBLE_EQUAL_REL(mean, 10.0, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL_REL(variance, 20.0, 1.0e-03);
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

  CU_pSuite gamma = CU_add_suite("gamma", init, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(gamma, test_create);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma, test_gamma11);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma, test_gamma12);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(gamma, test_gamma52);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
