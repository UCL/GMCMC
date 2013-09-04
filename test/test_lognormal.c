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
  gmcmc_distribution * lognormal = NULL;

  // Temporarily disable the error handler
  gmcmc_error_handler_t error_handler = gmcmc_error_handler;
  gmcmc_error_handler = NULL;

  // zero sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // negative sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, -1.0e-07), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // NaN mu
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, NAN, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // NaN sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // NaN mu and sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, NAN, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // Infinite mu
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal,  INFINITY, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // Negative infinite mu
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, -INFINITY, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // Infinite sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(lognormal);

  // Restore the error handler
  gmcmc_error_handler = error_handler;
}

static void test_lognormal01() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(lognormal,  INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(lognormal, -INFINITY)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(lognormal,  INFINITY)));

  // Test limits of 2nd order PDF
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(lognormal, -INFINITY)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(lognormal,  INFINITY)));

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(lognormal, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // lognormal = makedist('Lognormal', 'mu', 0.0, 'sigma', 1.0);
  // for i=1:10;
  //   x = random(lognormal);
  //   y = logpdf(lognormal, autodiff(x));
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.712008323467287), -1.601148649224616, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.712008323467287), -0.270052927965647, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.712008323467287), 0.584109309687657, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 6.258152505240481), -4.434390671177970, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 6.258152505240481), 0.133247793801254, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 6.258152505240481), 0.159791567745052, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.104470884773661), -1.211286242934042, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.104470884773661), -31.193828482108046, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.104470884773661), 9.572044901950710, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 2.368302184003618), -2.152783270750088, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 2.368302184003618), -0.058196407773810, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 2.368302184003618), 0.422243414186909, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.375428391238457), -1.288509412134830, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.375428391238457), -0.495289150987806, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.375428391238457), 0.727046210744265, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.270444521917488), -0.466274577046293, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.270444521917488), -8.532945241203073, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.270444521917488), 3.697616031967902, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.648176643161933), -0.579347531802555, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.648176643161933), -2.211730455624473, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.648176643161933), 1.542789316075636, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.408639671255502), -1.320258762278770, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.408639671255502), -0.466674016695441, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.408639671255502), 0.709904754498866, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 35.816079468166791), -10.899797802049777, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 35.816079468166791), 0.071989926815341, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 35.816079468166791), 0.027920420516400, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 15.949652304221461), -7.523266294338335, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 15.949652304221461), 0.110938909271179, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 15.949652304221461), 0.062697291509943, 1.0e-07);

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

  CU_ASSERT_DOUBLE_EQUAL_REL(mean, 1.64872127070013, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL_REL(variance, 4.67077427047161, 1.0e-03);
}

static void test_lognormal005() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.5) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(lognormal,  INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(lognormal, -INFINITY)) ==  1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(lognormal,  INFINITY)) == -1);

  // Test limits of 2nd order PDF
  CU_ASSERT_DOUBLE_EQUAL_ABS(gmcmc_distribution_log_pdf_2nd_order(lognormal, -INFINITY), 0.0, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_ABS(gmcmc_distribution_log_pdf_2nd_order(lognormal,  INFINITY), 0.0, 1.0e-07);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(lognormal, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // lognormal = makedist('Lognormal', 'mu', 0.0, 'sigma', 0.5);
  // for i=1:10;
  //   x = random(lognormal);
  //   y = logpdf(lognormal, autodiff(x));
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.308437359397570), -0.639167898891620, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.308437359397570), 0.057575762837348, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.308437359397570), 3.057081771069023, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 2.501629969687860), -2.824300983320481, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 2.501629969687860), 1.066412723510441, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 2.501629969687860), 1.598957499097718, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.323219561248481), -1.647562492875920, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.323219561248481), -17.071038957835412, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.323219561248481), 12.375488613837085, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.538928908040790), -1.028549430006082, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.538928908040790), 0.470682327787582, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.538928908040790), 2.599210385288297, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.172786592368133), -0.435979611645395, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.172786592368133), -0.309066903254860, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.172786592368133), 3.410680191971718, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.520042807774022), -0.426971544638985, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.520042807774022), -6.952074980299628, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.520042807774022), 7.691674493339304, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.805094182789773), -0.102996362395452, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.805094182789773), -2.319211943801768, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.805094182789773), 4.968362814570829, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.186861268748585), -0.455799348449500, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.186861268748585), -0.265196173479121, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.186861268748585), 3.370233830460708, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 5.984653663176074), -8.417452151626954, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 5.984653663176074), 1.028763605375301, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 5.984653663176074), 0.668376187683547, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 3.993701579264713), -5.445400598835951, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 3.993701579264713), 1.136508066435303, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 3.993701579264713), 1.001577088475511, 1.0e-07);

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

  CU_ASSERT_DOUBLE_EQUAL_REL(mean, 1.13314845306683, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL_REL(variance, 0.364695854012387, 1.0e-03);
}

static void test_lognormal0025() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.25) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(lognormal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(lognormal,  INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(lognormal, -INFINITY)) ==  1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(lognormal,  INFINITY)) == -1);

  // Test limits of 2nd order PDF
  CU_ASSERT_DOUBLE_EQUAL_ABS(gmcmc_distribution_log_pdf_2nd_order(lognormal, -INFINITY), 0.0, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_ABS(gmcmc_distribution_log_pdf_2nd_order(lognormal,  INFINITY), 0.0, 1.0e-07);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(lognormal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(lognormal, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // lognormal = makedist('Lognormal', 'mu', 0.0, 'sigma', 0.25);
  // for i=1:10;
  //   x = random(lognormal);
  //   y = logpdf(lognormal, autodiff(x));
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, %.15f), %.15f, 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.143869467814213), 0.188396066554850, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.143869467814213), 1.005943939025822, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.143869467814213), 13.987609994149018, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.581654187769204), -1.672682549111763, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.581654187769204), 4.005641756189522, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.581654187769204), 10.115991298051515, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.568524019939775), -1.519127027566887, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.568524019939775), -17.651650751849793, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.568524019939775), 28.143050141830283, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.240535734286115), -0.119858919354107, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.240535734286115), 1.973899835204360, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.240535734286115), 12.897653455510852, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.082952719359499), 0.336858878879296, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.082952719359499), 0.253991660502598, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.082952719359499), 14.774421555045393, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.721139936332763), -0.060746438155358, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.721139936332763), -8.640144403742980, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.721139936332763), 22.187094617676184, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 0.897270406727968), 0.481752812588073, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.897270406727968), -3.047429257356228, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.897270406727968), 17.831859693608319, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.089431626467942), 0.323003948745108, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.089431626467942), 0.340083633661156, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.089431626467942), 14.686557293984361, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 2.446355179277137), -6.829705736135567, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 2.446355179277137), 5.442213735634667, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 2.446355179277137), 6.540342193780615, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf(lognormal, 1.998424774482320), -4.059894160804786, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.998424774482320), 5.042845869517450, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL_REL(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.998424774482320), 8.006305868653326, 1.0e-07);

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

  CU_ASSERT_DOUBLE_EQUAL_REL(mean, 1.03174340749910, 1.0e-05);
  CU_ASSERT_DOUBLE_EQUAL_REL(variance, 0.0686539941489670, 1.0e-03);
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
