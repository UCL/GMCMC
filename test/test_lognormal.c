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
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.712008323467287), -1.601148649224616) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.712008323467287), -0.898165691409667) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.712008323467287), 0.183443256330647) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 6.258152505240481), -4.434390671177970) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 6.258152505240481), -0.452830929291358) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 6.258152505240481), 0.046825218992493) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.104470884773661), -1.211286242934042) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.104470884773661), 12.049738678206625) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.104470884773661), -206.964683289526533) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 2.368302184003618), -2.152783270750088) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 2.368302184003618), -0.786290420600007) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 2.368302184003618), 0.153716450912390) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.375428391238457), -1.288509412134830) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.375428391238457), -0.958803270500723) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.375428391238457), 0.168498092109165) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.270444521917488), -0.466274577046293) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.270444521917488), 1.137713177267269) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.270444521917488), -17.879190803910650) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.648176643161933), -0.579347531802555) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.648176643161933), -0.873848176526798) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.648176643161933), -1.032035243179407) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.408639671255502), -1.320258762278770) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.408639671255502), -0.953135492302291) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.408639671255502), 0.172670657206919) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 35.816079468166791), -10.899797802049777) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 35.816079468166791), -0.127830767848140) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 35.816079468166791), 0.002789538911442) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 15.949652304221461), -7.523266294338335) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 15.949652304221461), -0.236333492291064) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 15.949652304221461), 0.010886519497053) <= 1.0e-07);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(lognormal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT(reldif(mean, 1.64872127070013) <= 1.0e-04);
  CU_ASSERT(reldif(variance, 4.67077427047161) <= 1.0e-03);
}

static void test_lognormal005() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.5) == 0);

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
  // lognormal = makedist('Lognormal', 'mu', 0.0, 'sigma', 0.5);
  // for i=1:10;
  //   x = random(lognormal);
  //   y = logpdf(lognormal, autodiff(x));
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.308437359397570), -0.639167898891620) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.308437359397570), -1.586116648371859) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.308437359397570), -1.124215165618951) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 2.501629969687860), -2.824300983320481) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 2.501629969687860), -1.865891473059300) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 2.501629969687860), 0.106704019857457) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.323219561248481), -1.647562492875920) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.323219561248481), 10.883294650916872) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.323219561248481), -71.959701866166796) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.538928908040790), -1.028549430006082) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.538928908040790), -1.770287520431730) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.538928908040790), -0.538636229734529) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.172786592368133), -0.435979611645395) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.172786592368133), -1.396273192730999) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.172786592368133), -1.717624512719876) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.520042807774022), -0.426971544638985) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.520042807774022), 3.106237733629976) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.520042807774022), -20.763506514374054) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.805094182789773), -0.102996362395452) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.805094182789773), -0.164969463483646) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.805094182789773), -5.966250227324580) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.186861268748585), -0.455799348449500) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.186861268748585), -1.419920741751232) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.186861268748585), -1.643252787889747) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 5.984653663176074), -8.417452151626954) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 5.984653663176074), -1.362951699217075) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 5.984653663176074), 0.116059433114282) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 3.993701579264713), -5.445400598835951) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 3.993701579264713), -1.637296610673058) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 3.993701579264713), 0.159180527032416) <= 1.0e-07);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(lognormal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT(reldif(mean, 1.13314845306683) <= 1.0e-05);
  CU_ASSERT(reldif(variance, 0.364695854012387) <= 1.0e-03);
}

static void test_lognormal0025() {
  // Create the distribution
  gmcmc_distribution * lognormal;
  CU_ASSERT_FATAL(gmcmc_distribution_create_lognormal(&lognormal, 0.0, 0.25) == 0);

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
  // lognormal = makedist('Lognormal', 'mu', 0.0, 'sigma', 0.25);
  // for i=1:10;
  //   x = random(lognormal);
  //   y = logpdf(lognormal, autodiff(x));
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.x);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.dx);
  //   fprintf('CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, %.15f), %.15f) <= 1.0e-07);\n', x, y.d2x);
  // end
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.143869467814213), 0.188396066554850) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.143869467814213), -2.754395188294449) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.143869467814213), -9.820364230299631) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.581654187769204), -1.672682549111763) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.581654187769204), -5.270140668445961) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.581654187769204), -3.063786425046703) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.568524019939775), -1.519127027566887) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.568524019939775), 14.133769484121009) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.568524019939775), -74.362415910641360) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.240535734286115), -0.119858919354107) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.240535734286115), -3.586106517143216) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.240535734286115), -7.506069096611800) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.082952719359499), 0.336858878879296) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.082952719359499), -2.100794354883273) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.082952719359499), -11.702844430417802) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.721139936332763), -0.060746438155358) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.721139936332763), 5.866757576533456) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.721139936332763), -38.902092063951997) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 0.897270406727968), 0.481752812588073) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 0.897270406727968), 0.818446795655188) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 0.897270406727968), -20.785603034958726) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.089431626467942), 0.323003948745108) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.089431626467942), -2.175903295409201) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.089431626467942), -11.483652295955538) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 2.446355179277137), -6.829705736135567) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 2.446355179277137), -6.259756509857244) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 2.446355179277137), -0.114695399220926) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf(lognormal, 1.998424774482320), -4.059894160804786) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_1st_order(lognormal, 1.998424774482320), -6.043634103099116) <= 1.0e-07);
  CU_ASSERT(reldif(gmcmc_distribution_log_pdf_2nd_order(lognormal, 1.998424774482320), -0.982109404674804) <= 1.0e-07);

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  double mean = 0, m2 = 0;
  for (uint64_t j = 0; j < N; j++) {
    double x = gmcmc_distribution_sample(lognormal, rng);

    // Calculate mean and variance using "online" algorithm (avoids overflow)
    double delta = x - mean;
    mean += delta / (double)(j + 1);
    m2 += delta * (x - mean);
  }
  double variance = m2 / (N - 1);

  CU_ASSERT(reldif(mean, 1.03174340749910) <= 1.0e-05);
  CU_ASSERT(reldif(variance, 0.0686539941489670) <= 1.0e-03);
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
