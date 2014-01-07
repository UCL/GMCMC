#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_rng.h>
#include <gmcmc/gmcmc_distribution.h>
#include <math.h>

#define N 100000000

static inline double reldif(double a, double b) {
  double c = fabs(a);
  double d = fabs(b);

  d = fmax(c, d);

  return (d == 0.0) ? 0.0 : fabs(a - b) / d;
}

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

  // Temporarily disable the error handler
  gmcmc_error_handler_t error_handler = gmcmc_error_handler;
  gmcmc_error_handler = NULL;

  // zero sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, 0.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // negative sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, -1.0e-07), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // NaN mu
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, NAN, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // NaN sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // NaN mu and sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, NAN, NAN), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // Infinite mu
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal,  INFINITY, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // Negative infinite mu
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, -INFINITY, 1.0), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // Infinite sigma
  CU_ASSERT_EQUAL(gmcmc_distribution_create_normal(&normal, 0.0, INFINITY), GMCMC_EINVAL);
  gmcmc_distribution_destroy(normal);

  // Restore the error handler
  gmcmc_error_handler = error_handler;
}

static void test_normal01() {
  // Create the distribution
  gmcmc_distribution * normal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_normal(&normal, 0.0, 1.0) == 0);

  // Test limits of log PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(normal,  INFINITY)) == -1);

  // Test limits of 1st order derivative of log PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(normal, -INFINITY)) ==  1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(normal,  INFINITY)) == -1);

  // Test limits of 2nd order derivative of log PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_2nd_order(normal, -INFINITY), -1.0, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_2nd_order(normal,  INFINITY), -1.0, 1.0e-07);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(normal, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // normal = makedist('Normal', 'mu', 0.0, 'sigma', 1.0);
  // for i=1:10;
  //   x = random(normal);
  //   y = logpdf(normal, autodiff(x));
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 0.537667139546100), -1.063481509678515) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 0.537667139546100), -0.537667139546100) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 0.537667139546100), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 1.833885014595086), -2.600505656582883) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 1.833885014595086), -1.833885014595086) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 1.833885014595086), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -2.258846861003648), -3.470133103937690) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -2.258846861003648), 2.258846861003648) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -2.258846861003648), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 0.862173320368121), -1.290609950381968) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 0.862173320368121), -0.862173320368121) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 0.862173320368121), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 0.318765239858981), -0.969744172275849) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 0.318765239858981), -0.318765239858981) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 0.318765239858981), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -1.307688296305273), -1.773962873351567) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -1.307688296305273), 1.307688296305273) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -1.307688296305273), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -0.433592022305684), -1.012939554108239) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -0.433592022305684), 0.433592022305684) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -0.433592022305684), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 0.342624466538650), -0.977634295740120) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 0.342624466538650), -0.342624466538650) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 0.342624466538650), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 3.578396939725760), -7.321400862324017) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 3.578396939725760), -3.578396939725760) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 3.578396939725760), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 2.769437029884877), -4.753829264453458) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 2.769437029884877), -2.769437029884877) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 2.769437029884877), -1.000000000000000) <= 1.0e-07);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(normal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT(reldif(mean, 0.0) <= 1.0e-05);
  CU_ASSERT(reldif(variance, 1.0) <= 1.0e-03);
}

static void test_normal11() {
  // Create the distribution
  gmcmc_distribution * normal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_normal(&normal, 1.0, 1.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(normal,  INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(normal, -INFINITY)) ==  1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(normal,  INFINITY)) == -1);

  // Test limits of 2nd order PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_2nd_order(normal, -INFINITY), -1.0, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_2nd_order(normal,  INFINITY), -1.0, 1.0e-07);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(normal, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // normal = makedist('Normal', 'mu', 1.0, 'sigma', 1.0);
  // for i=1:10;
  //   x = random(normal);
  //   y = logpdf(normal, autodiff(x));
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 1.537667139546100), -1.063481509678515) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 1.537667139546100), -0.537667139546100) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 1.537667139546100), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 2.833885014595086), -2.600505656582883) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 2.833885014595086), -1.833885014595086) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 2.833885014595086), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -1.258846861003648), -3.470133103937690) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -1.258846861003648), 2.258846861003648) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -1.258846861003648), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 1.862173320368121), -1.290609950381968) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 1.862173320368121), -0.862173320368121) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 1.862173320368121), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 1.318765239858981), -0.969744172275850) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 1.318765239858981), -0.318765239858981) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 1.318765239858981), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -0.307688296305273), -1.773962873351567) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -0.307688296305273), 1.307688296305273) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -0.307688296305273), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 0.566407977694317), -1.012939554108239) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 0.566407977694317), 0.433592022305683) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 0.566407977694317), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 1.342624466538650), -0.977634295740120) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 1.342624466538650), -0.342624466538650) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 1.342624466538650), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 4.578396939725760), -7.321400862324015) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 4.578396939725760), -3.578396939725760) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 4.578396939725760), -1.000000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 3.769437029884877), -4.753829264453458) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 3.769437029884877), -2.769437029884877) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 3.769437029884877), -1.000000000000000) <= 1.0e-07);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(normal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT(reldif(mean, 1.0) <= 1.0e-05);
  CU_ASSERT(reldif(variance, 1.0) <= 1.0e-03);
}

static void test_normal15() {
  // Create the distribution
  gmcmc_distribution * normal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_normal(&normal, 1.0, 5.0) == 0);

  // Test limits of PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(normal, -INFINITY)) == -1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf(normal,  INFINITY)) == -1);

  // Test limits of 1st order PDF
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(normal, -INFINITY)) ==  1);
  CU_ASSERT(isinf(gmcmc_distribution_log_pdf_1st_order(normal,  INFINITY)) == -1);

  // Test limits of 2nd order PDF
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_2nd_order(normal, -INFINITY), -0.04, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(gmcmc_distribution_log_pdf_2nd_order(normal,  INFINITY), -0.04, 1.0e-07);

  // Test calling PDFs with NaN
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_1st_order(normal, NAN)));
  CU_ASSERT(isnan(gmcmc_distribution_log_pdf_2nd_order(normal, NAN)));

  // Samples chosen from Matlab:
  // rng(0, 'twister');
  // normal = makedist('Normal', 'mu', 1.0, 'sigma', 5.0);
  // for i=1:10;
  //   x = random(normal);
  //   y = logpdf(normal, autodiff(x));
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, %.15f), %.15f) <= 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 3.688335697730500), -2.672919422112615) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 3.688335697730500), -0.107533427909220) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 3.688335697730500), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 10.169425072975432), -4.209943569016983) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 10.169425072975432), -0.366777002919017) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 10.169425072975432), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -10.294234305018239), -5.079571016371789) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -10.294234305018239), 0.451769372200730) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -10.294234305018239), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 5.310866601840603), -2.900047862816068) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 5.310866601840603), -0.172434664073624) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 5.310866601840603), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 2.593826199294904), -2.579182084709950) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 2.593826199294904), -0.063753047971796) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 2.593826199294904), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -5.538441481526367), -3.383400785785667) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -5.538441481526367), 0.261537659261055) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -5.538441481526367), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, -1.167960111528418), -2.622377466542339) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, -1.167960111528418), 0.086718404461137) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, -1.167960111528418), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 2.713122332693250), -2.587072208174220) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 2.713122332693250), -0.068524893307730) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 2.713122332693250), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 18.891984698628804), -8.930838774758119) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 18.891984698628804), -0.715679387945152) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 18.891984698628804), -0.040000000000000) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(normal, 14.847185149424385), -6.363267176887557) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(normal, 14.847185149424385), -0.553887405976975) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(normal, 14.847185149424385), -0.040000000000000) <= 1.0e-07);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(normal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT(reldif(mean, 1.0) <= 1.0e-05);
  CU_ASSERT(reldif(variance, 25.0) <= 1.0e-03);
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
