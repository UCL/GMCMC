#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <cblas.h>
#include <stdlib.h>
#include "../src/mvn.c"

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

static double * X;
static size_t ldx;
static gmcmc_prng64 * rng;

static int init_sample() {
  int error;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_mt19937_64, 0)) != 0)
    GMCMC_ERROR("Failed to create RNG", error);
  if ((X = malloc((ldx = 5u & ~1u) * N * sizeof(double))) == NULL) {
    gmcmc_prng64_destroy(rng);
    GMCMC_ERROR("Failed to allocate X", GMCMC_ENOMEM);
  }
  return 0;
}

static int cleanup_sample() {
  free(X);
  return 0;
}

static void test_mvn_sample0() {
  // Input arguments
  double mu[] = { 0.537667139546100, 1.833885014595086, -2.258846861003648, 0.862173320368121 };
  double sigma[] = { 13.448159045144756,  9.262621609097568, -4.625091506787965, 10.644757941358025,
                      9.262621609097568, 11.603005022466061, -1.117456379707958, 10.081095682477658,
                     -4.625091506787965, -1.117456379707958,  4.506432405029324, -2.394987833402893,
                     10.644757941358025, 10.081095682477658, -2.394987833402893, 11.378597393300055 };
  size_t block[] = { 0, 1, 2, 3 };

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  // Generate N samples and simultaneously calculate the sample mean using the
  // online algorithm from Knuth
  double mean[] = { 0.0, 0.0, 0.0, 0.0 };
  int error;
  for (size_t i = 0; i < N; i++) {
    // Generate sample
    if ((error = gmcmc_mvn_sample(4, mu, sigma, 4, rng, block, &X[i * ldx])) != 0)
      GMCMC_ERROR_VOID("Failed to create sample", error);

    // Calculate mean
    for (size_t j = 0; j < 4; j++) {
      double delta = X[i * ldx + j] - mean[j];
      mean[j] += delta / ((double)i + 1);
    }
  }

  // x(j) -= mean
  for (size_t j = 0; j < N; j++) {
    for (size_t i = 0; i < 4; i++)
      X[j * ldx + i] -= mean[i];
  }

  // cov = \frac{1}{N - 1} \sum_{j=1}^N (x_j - mean)*(x_j - mean)^T
  double cov[16];
  const double alpha = 1.0 / (N - 1.0);
  for (size_t j = 0; j < 4; j++) {
    for (size_t i = 0; i < 4; i++)
      cov[j * 4 + i] = 0.0;
    for (size_t k = 0; k < N; k++) {
      const double temp = alpha * X[k * ldx + j];
      for (size_t i = 0; i < 4; i++)
        cov[j * 4 + i] += temp * X[k * ldx + i];
    }
  }

  for (size_t i = 0; i < 4; i++)
    CU_ASSERT_DOUBLE_EQUAL_REL(mean[i], mu[i], 1.0e-03);
  for (size_t j = 0; j < 4; j++) {
    for (size_t i = 0; i < 4; i++)
      CU_ASSERT_DOUBLE_EQUAL_REL(cov[j * 4 + i], sigma[j * 4 + i], 1.0e-02);
  }
}

static void test_mvn_sample1() {
  // Input arguments
  double mu[] = { 0.537667139546100, 1.833885014595086, -2.258846861003648, 0.862173320368121 };
  double sigma[] = { 13.448159045144756,  9.262621609097568, -4.625091506787965, 10.644757941358025,
                      9.262621609097568, 11.603005022466061, -1.117456379707958, 10.081095682477658,
                     -4.625091506787965, -1.117456379707958,  4.506432405029324, -2.394987833402893,
                     10.644757941358025, 10.081095682477658, -2.394987833402893, 11.378597393300055 };
  size_t * block = NULL;

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  // Generate N samples and simultaneously calculate the sample mean using the
  // online algorithm from Knuth
  double mean[] = { 0.0, 0.0, 0.0, 0.0 };
  int error;
  for (size_t i = 0; i < N; i++) {
    // Generate sample
    if ((error = gmcmc_mvn_sample(4, mu, sigma, 4, rng, block, &X[i * ldx])) != 0)
      GMCMC_ERROR_VOID("Failed to create sample", error);

    // Calculate mean
    for (size_t j = 0; j < 4; j++) {
      double delta = X[i * ldx + j] - mean[j];
      mean[j] += delta / ((double)i + 1);
    }
  }

  // x(j) -= mean
  for (size_t j = 0; j < N; j++) {
    for (size_t i = 0; i < 4; i++)
      X[j * ldx + i] -= mean[i];
  }

  // cov = \frac{1}{N - 1} \sum_{j=1}^N (x_j - mean)*(x_j - mean)^T
  double cov[16];
  const double alpha = 1.0 / (N - 1.0);
  for (size_t j = 0; j < 4; j++) {
    for (size_t i = 0; i < 4; i++)
      cov[j * 4 + i] = 0.0;
    for (size_t k = 0; k < N; k++) {
      const double temp = alpha * X[k * ldx + j];
      for (size_t i = 0; i < 4; i++)
        cov[j * 4 + i] += temp * X[k * ldx + i];
    }
  }

  for (size_t i = 0; i < 4; i++)
    CU_ASSERT_DOUBLE_EQUAL_REL(mean[i], mu[i], 1.0e-03);
  for (size_t j = 0; j < 4; j++) {
    for (size_t i = 0; i < 4; i++)
      CU_ASSERT_DOUBLE_EQUAL_REL(cov[j * 4 + i], sigma[j * 4 + i], 1.0e-02);
  }
}

static void test_mvn_sample2() {
  // Input arguments
  double mu[] = { 0.537667139546100, 1.833885014595086, -2.258846861003648, 0.862173320368121 };
  double sigma[] = { 13.448159045144756,  9.262621609097568, -4.625091506787965, 10.644757941358025,
                      9.262621609097568, 11.603005022466061, -1.117456379707958, 10.081095682477658,
                     -4.625091506787965, -1.117456379707958,  4.506432405029324, -2.394987833402893,
                     10.644757941358025, 10.081095682477658, -2.394987833402893, 11.378597393300055 };
  size_t block[] = { 1, 3 };

  // Seed the RNG
  gmcmc_prng64_seed(rng, 3421);

  // Generate N samples and simultaneously calculate the sample mean using the
  // online algorithm from Knuth
  double mean[] = { 0.0, 0.0, 0.0, 0.0 };
  int error;
  for (size_t i = 0; i < N; i++) {
    // Generate sample
    X[i * ldx] = mu[0]; // Copy mean into those elements of X that are not being updated
    X[i * ldx + 2] = mu[2];
    if ((error = gmcmc_mvn_sample(2, mu, sigma, 4, rng, block, &X[i * ldx])) != 0)
      GMCMC_ERROR_VOID("Failed to create sample", error);

    // Calculate mean
    for (size_t j = 0; j < 4; j++) {
      double delta = X[i * ldx + j] - mean[j];
      mean[j] += delta / ((double)i + 1);
    }
  }

  // x(j) -= mean
  for (size_t j = 0; j < N; j++) {
    for (size_t i = 0; i < 4; i++)
      X[j * ldx + i] -= mean[i];
  }

  // cov = \frac{1}{N - 1} \sum_{j=1}^N (x_j - mean)*(x_j - mean)^T
  double cov[16];
  const double alpha = 1.0 / (N - 1.0);
  for (size_t j = 0; j < 4; j++) {
    for (size_t i = 0; i < 4; i++)
      cov[j * 4 + i] = 0.0;
    for (size_t k = 0; k < N; k++) {
      const double temp = alpha * X[k * ldx + j];
      for (size_t i = 0; i < 4; i++)
        cov[j * 4 + i] += temp * X[k * ldx + i];
    }
  }

  for (size_t i = 0; i < 4; i++)
    CU_ASSERT_DOUBLE_EQUAL_REL(mean[i], mu[i], 1.0e-03);
  for (size_t j = 0; j < 4; j++) {
    for (size_t i = 0; i < 4; i++)
      CU_ASSERT_DOUBLE_EQUAL_REL(cov[j * 4 + i], sigma[j * 4 + i], 1.0e-02);
  }
}

static void test_mvn_logpdf0() {
  double mu[] = { 0.537667139546100, 1.833885014595086, -2.258846861003648, 0.862173320368121 };
  double sigma[] = { 13.448159045144756, 9.262621609097568, -4.625091506787965, 10.644757941358025,
                     9.262621609097568, 11.603005022466061, -1.117456379707958, 10.081095682477658,
                     -4.625091506787965, -1.117456379707958, 4.506432405029324, -2.394987833402893,
                     10.644757941358025, 10.081095682477658, -2.394987833402893, 11.378597393300055 };
  double x[] = { 3.000163410398294, 0.770327615358076, -3.159823396955795, 3.436984148359264, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -8.912086653874059, 1.0e-07);
}

static void test_mvn_logpdf1() {
  double sigma[] = { 13.448159045144756, 9.262621609097568, -4.625091506787965, 10.644757941358025,
                     9.262621609097568, 11.603005022466061, -1.117456379707958, 10.081095682477658,
                     -4.625091506787965, -1.117456379707958, 4.506432405029324, -2.394987833402893,
                     10.644757941358025, 10.081095682477658, -2.394987833402893, 11.378597393300055 };
  double x[] = { 3.000163410398294, 0.770327615358076, -3.159823396955795, 3.436984148359264, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -8.675631036383903, 1.0e-07);
}

static void test_mvn_logpdfv0() {
  double mu[] = { 0.537667139546100, 1.833885014595086, -2.258846861003648, 0.862173320368121 };
  double sigma[] = { 13.448159045144756, 11.603005022466061, 4.506432405029324, 11.378597393300055 };
  double x[] = { 3.000163410398294, 0.770327615358076, -3.159823396955795, 3.436984148359264, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -8.825013273330061, 1.0e-07);
}

static void test_mvn_logpdfv1() {
  double sigma[] = { 13.448159045144756, 11.603005022466061, 4.506432405029324, 11.378597393300055 };
  double x[] = { 3.000163410398294, 0.770327615358076, -3.159823396955795, 3.436984148359264, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -10.156539207554928, 1.0e-07);
}

static void test_mvn_logpdfs0() {
  double mu[] = { 0.537667139546100, 1.833885014595086, -2.258846861003648, 0.862173320368121 };
  double sigma = 13.448159045144756;
  double x[] = { 3.000163410398294, 0.770327615358076, -3.159823396955795, 3.436984148359264, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.417619075164975, 1.0e-07);
}

static void test_mvn_logpdfs1() {
  double sigma = 13.448159045144756;
  double x[] = { 3.000163410398294, 0.770327615358076, -3.159823396955795, 3.436984148359264, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -10.040577104592721, 1.0e-07);
}

static void test_mvn_logpdf2() {
  double mu[] = { 0.488893770311789, 1.034693009917860, 0.726885133383238, -0.303440924786016 };
  double sigma[] = { 1.345046900251238, 0.413079876608304, 3.821104132525598, -2.463089753533145,
                     0.413079876608304, 1.903315790354978, 0.572426884866194, 0.955235031519136,
                     3.821104132525598, 0.572426884866194, 11.437667056415835, -7.499474265063946,
                     -2.463089753533145, 0.955235031519136, -7.499474265063946, 6.411876650556795 };
  double x[] = { -0.514160720839647, 0.686589588784673, -2.210618022707853, 1.779415869993292, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -3.490319297943123, 1.0e-07);
}

static void test_mvn_logpdf3() {
  double sigma[] = { 1.345046900251238, 0.413079876608304, 3.821104132525598, -2.463089753533145,
                     0.413079876608304, 1.903315790354978, 0.572426884866194, 0.955235031519136,
                     3.821104132525598, 0.572426884866194, 11.437667056415835, -7.499474265063946,
                     -2.463089753533145, 0.955235031519136, -7.499474265063946, 6.411876650556795 };
  double x[] = { -0.514160720839647, 0.686589588784673, -2.210618022707853, 1.779415869993292, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -3.518213248559060, 1.0e-07);
}

static void test_mvn_logpdfv2() {
  double mu[] = { 0.488893770311789, 1.034693009917860, 0.726885133383238, -0.303440924786016 };
  double sigma[] = { 1.345046900251238, 1.903315790354978, 11.437667056415835, 6.411876650556795 };
  double x[] = { -0.514160720839647, 0.686589588784673, -2.210618022707853, 1.779415869993292, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.414657398830830, 1.0e-07);
}

static void test_mvn_logpdfv3() {
  double sigma[] = { 1.345046900251238, 1.903315790354978, 11.437667056415835, 6.411876650556795 };
  double x[] = { -0.514160720839647, 0.686589588784673, -2.210618022707853, 1.779415869993292, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -6.975948878763938, 1.0e-07);
}

static void test_mvn_logpdfs2() {
  double mu[] = { 0.488893770311789, 1.034693009917860, 0.726885133383238, -0.303440924786016 };
  double sigma = 1.345046900251238;
  double x[] = { -0.514160720839647, 0.686589588784673, -2.210618022707853, 1.779415869993292, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.508024561090181, 1.0e-07);
}

static void test_mvn_logpdfs3() {
  double sigma = 1.345046900251238;
  double x[] = { -0.514160720839647, 0.686589588784673, -2.210618022707853, 1.779415869993292, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.535754251538330, 1.0e-07);
}

static void test_mvn_logpdf4() {
  double mu[] = { 1.093265669039484, 1.109273297614398, -0.863652821988714, 0.077359091130425 };
  double sigma[] = { 5.637117231365240, 1.163321321329860, -2.723128440559655, -5.065690130633797,
                     1.163321321329860, 1.386250271980310, -0.186335702507454, -1.319576348742758,
                     -2.723128440559655, -0.186335702507454, 2.581062999690693, 1.452771508575535,
                     -5.065690130633797, -1.319576348742758, 1.452771508575535, 5.359795272122508 };
  double x[] = { -1.427206871338603, 3.105520438197855, 0.520597794227001, 2.381915338008273, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -6.645508961179885, 1.0e-07);
}

static void test_mvn_logpdf5() {
  double sigma[] = { 5.637117231365240, 1.163321321329860, -2.723128440559655, -5.065690130633797,
                     1.163321321329860, 1.386250271980310, -0.186335702507454, -1.319576348742758,
                     -2.723128440559655, -0.186335702507454, 2.581062999690693, 1.452771508575535,
                     -5.065690130633797, -1.319576348742758, 1.452771508575535, 5.359795272122508 };
  double x[] = { -1.427206871338603, 3.105520438197855, 0.520597794227001, 2.381915338008273, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -24.265792241902602, 1.0e-07);
}

static void test_mvn_logpdfv4() {
  double mu[] = { 1.093265669039484, 1.109273297614398, -0.863652821988714, 0.077359091130425 };
  double sigma[] = { 5.637117231365240, 1.386250271980310, 2.581062999690693, 5.359795272122508 };
  double x[] = { -1.427206871338603, 3.105520438197855, 0.520597794227001, 2.381915338008273, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -8.884754839506989, 1.0e-07);
}

static void test_mvn_logpdfv5() {
  double sigma[] = { 5.637117231365240, 1.386250271980310, 2.581062999690693, 5.359795272122508 };
  double x[] = { -1.427206871338603, 3.105520438197855, 0.520597794227001, 2.381915338008273, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -10.258285336967628, 1.0e-07);
}

static void test_mvn_logpdfs4() {
  double mu[] = { 1.093265669039484, 1.109273297614398, -0.863652821988714, 0.077359091130425 };
  double sigma = 5.637117231365240;
  double x[] = { -1.427206871338603, 3.105520438197855, 0.520597794227001, 2.381915338008273, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -8.692469271418531, 1.0e-07);
}

static void test_mvn_logpdfs5() {
  double sigma = 5.637117231365240;
  double x[] = { -1.427206871338603, 3.105520438197855, 0.520597794227001, 2.381915338008273, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -8.697862599901271, 1.0e-07);
}

static void test_mvn_logpdf6() {
  double mu[] = { -0.192418510588264, 0.888610425420721, -0.764849236567874, -1.402268969338759 };
  double sigma[] = { 4.731273637091657, -1.092394890745478, -0.386329685788648, 2.750978068199349,
                     -1.092394890745478, 2.167832390107410, 1.891161727053351, 0.075190657937774,
                     -0.386329685788648, 1.891161727053351, 2.085758985083697, 0.024924596611678,
                     2.750978068199349, 0.075190657937774, 0.024924596611678, 2.629621146094861 };
  double x[] = { 1.378591702534938, 4.104347854989594, 2.073368598073831, 1.402941447716558, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.470070364484704, 1.0e-07);
}

static void test_mvn_logpdf7() {
  double sigma[] = { 4.731273637091657, -1.092394890745478, -0.386329685788648, 2.750978068199349,
                     -1.092394890745478, 2.167832390107410, 1.891161727053351, 0.075190657937774,
                     -0.386329685788648, 1.891161727053351, 2.085758985083697, 0.024924596611678,
                     2.750978068199349, 0.075190657937774, 0.024924596611678, 2.629621146094861 };
  double x[] = { 1.378591702534938, 4.104347854989594, 2.073368598073831, 1.402941447716558, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -34.379190296344014, 1.0e-07);
}

static void test_mvn_logpdfv6() {
  double mu[] = { -0.192418510588264, 0.888610425420721, -0.764849236567874, -1.402268969338759 };
  double sigma[] = { 4.731273637091657, 2.167832390107410, 2.085758985083697, 2.629621146094861 };
  double x[] = { 1.378591702534938, 4.104347854989594, 2.073368598073831, 1.402941447716558, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -11.763949939229716, 1.0e-07);
}

static void test_mvn_logpdfv7() {
  double sigma[] = { 4.731273637091657, 2.167832390107410, 2.085758985083697, 2.629621146094861 };
  double x[] = { 1.378591702534938, 4.104347854989594, 2.073368598073831, 1.402941447716558, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -11.181690571512586, 1.0e-07);
}

static void test_mvn_logpdfs6() {
  double mu[] = { -0.192418510588264, 0.888610425420721, -0.764849236567874, -1.402268969338759 };
  double sigma = 4.731273637091657;
  double x[] = { 1.378591702534938, 4.104347854989594, 2.073368598073831, 1.402941447716558, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.820717132139528, 1.0e-07);
}

static void test_mvn_logpdfs7() {
  double sigma = 4.731273637091657;
  double x[] = { 1.378591702534938, 4.104347854989594, 2.073368598073831, 1.402941447716558, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.427542048048114, 1.0e-07);
}

static void test_mvn_logpdf8() {
  double mu[] = { -0.082494425370955, -1.933022917850987, -0.438966153934773, -1.794678841455123 };
  double sigma[] = { 5.563841478777587, -2.713145208452899, -2.126091368696406, -1.502441269016176,
                     -2.713145208452899, 2.336193869994514, -0.998211531588691, 0.069683124545366,
                     -2.126091368696406, -0.998211531588691, 5.746080189309868, 2.222304004375298,
                     -1.502441269016176, 0.069683124545366, 2.222304004375298, 1.563467201677911 };
  double x[] = { 3.306356344167859, -5.559317641642550, 2.048579135226712, -2.426167349154004, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.909753470048106, 1.0e-07);
}

static void test_mvn_logpdf9() {
  double sigma[] = { 5.563841478777587, -2.713145208452899, -2.126091368696406, -1.502441269016176,
                     -2.713145208452899, 2.336193869994514, -0.998211531588691, 0.069683124545366,
                     -2.126091368696406, -0.998211531588691, 5.746080189309868, 2.222304004375298,
                     -1.502441269016176, 0.069683124545366, 2.222304004375298, 1.563467201677911 };
  double x[] = { 3.306356344167859, -5.559317641642550, 2.048579135226712, -2.426167349154004, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -30.178419330265690, 1.0e-07);
}

static void test_mvn_logpdfv8() {
  double mu[] = { -0.082494425370955, -1.933022917850987, -0.438966153934773, -1.794678841455123 };
  double sigma[] = { 5.563841478777587, 2.336193869994514, 5.746080189309868, 1.563467201677911 };
  double x[] = { 3.306356344167859, -5.559317641642550, 2.048579135226712, -2.426167349154004, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -10.568303923651714, 1.0e-07);
}

static void test_mvn_logpdfv9() {
  double sigma[] = { 5.563841478777587, 2.336193869994514, 5.746080189309868, 1.563467201677911 };
  double x[] = { 3.306356344167859, -5.559317641642550, 2.048579135226712, -2.426167349154004, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -15.900518133436520, 1.0e-07);
}

static void test_mvn_logpdfs8() {
  double mu[] = { -0.082494425370955, -1.933022917850987, -0.438966153934773, -1.794678841455123 };
  double sigma = 5.563841478777587;
  double x[] = { 3.306356344167859, -5.559317641642550, 2.048579135226712, -2.426167349154004, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.914035490453534, 1.0e-07);
}

static void test_mvn_logpdfs9() {
  double sigma = 5.563841478777587;
  double x[] = { 3.306356344167859, -5.559317641642550, 2.048579135226712, -2.426167349154004, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -11.774259870556167, 1.0e-07);
}

static void test_mvn_logpdf10() {
  double mu[] = { 2.908008030729362, 0.825218894228491, 1.378971977916614, -1.058180257987362 };
  double sigma[] = { 4.977566690319046, -3.616567361999817, -1.674710838110257, -0.101506889659740,
                     -3.616567361999817, 5.813466791241152, 0.964813424208664, 1.445372149658658,
                     -1.674710838110257, 0.964813424208664, 1.533887093883376, -0.109081254487404,
                     -0.101506889659740, 1.445372149658658, -0.109081254487404, 0.846068968465308 };
  double x[] = { 2.959076213526364, 0.320486000309358, -0.307563094783529, -1.341636920117010, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -5.950388000218717, 1.0e-07);
}

static void test_mvn_logpdf11() {
  double sigma[] = { 4.977566690319046, -3.616567361999817, -1.674710838110257, -0.101506889659740,
                     -3.616567361999817, 5.813466791241152, 0.964813424208664, 1.445372149658658,
                     -1.674710838110257, 0.964813424208664, 1.533887093883376, -0.109081254487404,
                     -0.101506889659740, 1.445372149658658, -0.109081254487404, 0.846068968465308 };
  double x[] = { 2.959076213526364, 0.320486000309358, -0.307563094783529, -1.341636920117010, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -17.195541607265184, 1.0e-07);
}

static void test_mvn_logpdfv10() {
  double mu[] = { 2.908008030729362, 0.825218894228491, 1.378971977916614, -1.058180257987362 };
  double sigma[] = { 4.977566690319046, 5.813466791241152, 1.533887093883376, 0.846068968465308 };
  double x[] = { 2.959076213526364, 0.320486000309358, -0.307563094783529, -1.341636920117010, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -6.485481367844956, 1.0e-07);
}

static void test_mvn_logpdfv11() {
  double sigma[] = { 4.977566690319046, 5.813466791241152, 1.533887093883376, 0.846068968465308 };
  double x[] = { 2.959076213526364, 0.320486000309358, -0.307563094783529, -1.341636920117010, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.471604016919811, 1.0e-07);
}

static void test_mvn_logpdfs10() {
  double mu[] = { 2.908008030729362, 0.825218894228491, 1.378971977916614, -1.058180257987362 };
  double sigma = 4.977566690319046;
  double x[] = { 2.959076213526364, 0.320486000309358, -0.307563094783529, -1.341636920117010, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.205281732039815, 1.0e-07);
}

static void test_mvn_logpdfs11() {
  double sigma = 4.977566690319046;
  double x[] = { 2.959076213526364, 0.320486000309358, -0.307563094783529, -1.341636920117010, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.965825686882223, 1.0e-07);
}

static void test_mvn_logpdf12() {
  double mu[] = { -0.831366511567624, -0.979206305167302, -1.156401655664002, -0.533557109315987 };
  double sigma[] = { 4.608603450203692, -2.619771794458920, -0.587264319651041, -0.276401879789209,
                     -2.619771794458920, 4.112025896948845, 0.334413531596105, -2.850848982530037,
                     -0.587264319651041, 0.334413531596105, 2.613391652037389, -2.843169439047864,
                     -0.276401879789209, -2.850848982530037, -2.843169439047864, 6.745777655301490 };
  double x[] = { 2.722599122163624, -2.501410637110625, -3.612113376520683, 0.838799033587756, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -5.941581523077063, 1.0e-07);
}

static void test_mvn_logpdf13() {
  double sigma[] = { 4.608603450203692, -2.619771794458920, -0.587264319651041, -0.276401879789209,
                     -2.619771794458920, 4.112025896948845, 0.334413531596105, -2.850848982530037,
                     -0.587264319651041, 0.334413531596105, 2.613391652037389, -2.843169439047864,
                     -0.276401879789209, -2.850848982530037, -2.843169439047864, 6.745777655301490 };
  double x[] = { 2.722599122163624, -2.501410637110625, -3.612113376520683, 0.838799033587756, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -422.092317586792205, 1.0e-07);
}

static void test_mvn_logpdfv12() {
  double mu[] = { -0.831366511567624, -0.979206305167302, -1.156401655664002, -0.533557109315987 };
  double sigma[] = { 4.608603450203692, 4.112025896948845, 2.613391652037389, 6.745777655301490 };
  double x[] = { 2.722599122163624, -2.501410637110625, -3.612113376520683, 0.838799033587756, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.526909245050302, 1.0e-07);
}

static void test_mvn_logpdfv13() {
  double sigma[] = { 4.608603450203692, 4.112025896948845, 2.613391652037389, 6.745777655301490 };
  double x[] = { 2.722599122163624, -2.501410637110625, -3.612113376520683, 0.838799033587756, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -10.694889541327875, 1.0e-07);
}

static void test_mvn_logpdfs12() {
  double mu[] = { -0.831366511567624, -0.979206305167302, -1.156401655664002, -0.533557109315987 };
  double sigma = 4.608603450203692;
  double x[] = { 2.722599122163624, -2.501410637110625, -3.612113376520683, 0.838799033587756, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.211927844581709, 1.0e-07);
}

static void test_mvn_logpdfs13() {
  double sigma = 4.608603450203692;
  double x[] = { 2.722599122163624, -2.501410637110625, -3.612113376520683, 0.838799033587756, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -9.706534168976351, 1.0e-07);
}

static void test_mvn_logpdf14() {
  double mu[] = { -0.176534114231451, 0.791416061628634, -1.332004421315247, -2.329867155805076 };
  double sigma[] = { 4.276638314511500, -0.552440738377919, 0.032796801027512, 0.386049222610469,
                     -0.552440738377919, 1.431732443150110, -1.504459212954794, 1.466539176337116,
                     0.032796801027512, -1.504459212954794, 2.349303176856232, -1.358427075480577,
                     0.386049222610469, 1.466539176337116, -1.358427075480577, 2.648505199045618 };
  double x[] = { 1.188644186177750, 0.535912319629119, -1.396945114535671, -2.560390420405192, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -4.515353667414425, 1.0e-07);
}

static void test_mvn_logpdf15() {
  double sigma[] = { 4.276638314511500, -0.552440738377919, 0.032796801027512, 0.386049222610469,
                     -0.552440738377919, 1.431732443150110, -1.504459212954794, 1.466539176337116,
                     0.032796801027512, -1.504459212954794, 2.349303176856232, -1.358427075480577,
                     0.386049222610469, 1.466539176337116, -1.358427075480577, 2.648505199045618 };
  double x[] = { 1.188644186177750, 0.535912319629119, -1.396945114535671, -2.560390420405192, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -11.208154829556499, 1.0e-07);
}

static void test_mvn_logpdfv14() {
  double mu[] = { -0.176534114231451, 0.791416061628634, -1.332004421315247, -2.329867155805076 };
  double sigma[] = { 4.276638314511500, 1.431732443150110, 2.349303176856232, 2.648505199045618 };
  double x[] = { 1.188644186177750, 0.535912319629119, -1.396945114535671, -2.560390420405192, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -5.747460067064008, 1.0e-07);
}

static void test_mvn_logpdfv15() {
  double sigma[] = { 4.276638314511500, 1.431732443150110, 2.349303176856232, 2.648505199045618 };
  double x[] = { 1.188644186177750, 0.535912319629119, -1.396945114535671, -2.560390420405192, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.414251536143509, 1.0e-07);
}

static void test_mvn_logpdfs14() {
  double mu[] = { -0.176534114231451, 0.791416061628634, -1.332004421315247, -2.329867155805076 };
  double sigma = 4.276638314511500;
  double x[] = { 1.188644186177750, 0.535912319629119, -1.396945114535671, -2.560390420405192, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -6.814321552197987, 1.0e-07);
}

static void test_mvn_logpdfs15() {
  double sigma = 4.276638314511500;
  double x[] = { 1.188644186177750, 0.535912319629119, -1.396945114535671, -2.560390420405192, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -7.775447902590498, 1.0e-07);
}

static void test_mvn_logpdf16() {
  double mu[] = { -0.303107621351741, 0.023045624425105, 0.051290355848775, 0.826062790211595 };
  double sigma[] = { 2.409855816717180, 0.617644532465503, -0.024602986982356, 0.610579147511600,
                     0.617644532465503, 1.565241026515496, -0.863004640740354, -0.755068114287319,
                     -0.024602986982356, -0.863004640740354, 1.296371140304045, -0.980649463617985,
                     0.610579147511600, -0.755068114287319, -0.980649463617985, 4.201017964875745 };
  double x[] = { -1.662564488996878, -0.899256948267473, -0.211984048196217, 1.316243383769307, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -5.185838951951856, 1.0e-07);
}

static void test_mvn_logpdf17() {
  double sigma[] = { 2.409855816717180, 0.617644532465503, -0.024602986982356, 0.610579147511600,
                     0.617644532465503, 1.565241026515496, -0.863004640740354, -0.755068114287319,
                     -0.024602986982356, -0.863004640740354, 1.296371140304045, -0.980649463617985,
                     0.610579147511600, -0.755068114287319, -0.980649463617985, 4.201017964875745 };
  double x[] = { -1.662564488996878, -0.899256948267473, -0.211984048196217, 1.316243383769307, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -4.761097043185913, 1.0e-07);
}

static void test_mvn_logpdfv16() {
  double mu[] = { -0.303107621351741, 0.023045624425105, 0.051290355848775, 0.826062790211595 };
  double sigma[] = { 2.409855816717180, 1.565241026515496, 1.296371140304045, 4.201017964875745 };
  double x[] = { -1.662564488996878, -0.899256948267473, -0.211984048196217, 1.316243383769307, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -5.897516221046564, 1.0e-07);
}

static void test_mvn_logpdfv17() {
  double sigma[] = { 2.409855816717180, 1.565241026515496, 1.296371140304045, 4.201017964875745 };
  double x[] = { -1.662564488996878, -0.899256948267473, -0.211984048196217, 1.316243383769307, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -6.242359312735628, 1.0e-07);
}

static void test_mvn_logpdfs16() {
  double mu[] = { -0.303107621351741, 0.023045624425105, 0.051290355848775, 0.826062790211595 };
  double sigma = 2.409855816717180;
  double x[] = { -1.662564488996878, -0.899256948267473, -0.211984048196217, 1.316243383769307, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -6.059065444885929, 1.0e-07);
}

static void test_mvn_logpdfs17() {
  double sigma = 2.409855816717180;
  double x[] = { -1.662564488996878, -0.899256948267473, -0.211984048196217, 1.316243383769307, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -6.544958038154931, 1.0e-07);
}

static void test_mvn_logpdf18() {
  double mu[] = { -0.192239517539275, -0.274070229932602, 1.530072514424096, -0.249024742513714 };
  double sigma[] = { 4.367903602208544, -0.450006330287706, -0.700047331686692, 0.459093585365624,
                     -0.450006330287706, 3.514630437371984, 2.599212172251052, -0.807941805358519,
                     -0.700047331686692, 2.599212172251052, 1.960209938147062, -0.653905313031246,
                     0.459093585365624, -0.807941805358519, -0.653905313031246, 1.795908371223251 };
  double x[] = { -0.166179806959453, -5.918078976941027, -2.621947385003284, 2.647749532987382, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, mu, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -8.191635146964892, 1.0e-07);
}

static void test_mvn_logpdf19() {
  double sigma[] = { 4.367903602208544, -0.450006330287706, -0.700047331686692, 0.459093585365624,
                     -0.450006330287706, 3.514630437371984, 2.599212172251052, -0.807941805358519,
                     -0.700047331686692, 2.599212172251052, 1.960209938147062, -0.653905313031246,
                     0.459093585365624, -0.807941805358519, -0.653905313031246, 1.795908371223251 };
  double x[] = { -0.166179806959453, -5.918078976941027, -2.621947385003284, 2.647749532987382, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdf(4, x, NULL, sigma, 4, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -238.628821843038821, 1.0e-07);
}

static void test_mvn_logpdfv18() {
  double mu[] = { -0.192239517539275, -0.274070229932602, 1.530072514424096, -0.249024742513714 };
  double sigma[] = { 4.367903602208544, 3.514630437371984, 1.960209938147062, 1.795908371223251 };
  double x[] = { -0.166179806959453, -5.918078976941027, -2.621947385003284, 2.647749532987382, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -16.935998626057145, 1.0e-07);
}

static void test_mvn_logpdfv19() {
  double sigma[] = { 4.367903602208544, 3.514630437371984, 1.960209938147062, 1.795908371223251 };
  double x[] = { -0.166179806959453, -5.918078976941027, -2.621947385003284, 2.647749532987382, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfv(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -14.361715645015897, 1.0e-07);
}

static void test_mvn_logpdfs18() {
  double mu[] = { -0.192239517539275, -0.274070229932602, 1.530072514424096, -0.249024742513714 };
  double sigma = 4.367903602208544;
  double x[] = { -0.166179806959453, -5.918078976941027, -2.621947385003284, 2.647749532987382, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, mu, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -13.204832488767380, 1.0e-07);
}

static void test_mvn_logpdfs19() {
  double sigma = 4.367903602208544;
  double x[] = { -0.166179806959453, -5.918078976941027, -2.621947385003284, 2.647749532987382, };

  double res;
  CU_ASSERT(gmcmc_mvn_logpdfs(4, x, NULL, sigma, &res) == 0);

  CU_ASSERT_DOUBLE_EQUAL(res, -12.226145126684443, 1.0e-07);
}

#define CUNIT_ERROR(message) \
  do { \
    CU_cleanup_registry(); \
    fprintf(stderr, "%s\nCUnit error code %d in %s (%s:%d): %s\n", \
                     message, CU_get_error(), __func__, __FILE__, __LINE__, \
                     CU_get_error_msg()); \
    return CU_get_error(); \
  } while (0)

#define ADD_TEST(suite, test) \
  do { \
    CU_ADD_TEST(suite, test); \
    if (CU_get_error() != CUE_SUCCESS) \
      CUNIT_ERROR("Failed to add test to suite"); \
  } while (0)

int main() {
  CU_ErrorCode error = CU_initialize_registry();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to initialise test registry");

  CU_pSuite sample = CU_add_suite("gmcmc_mvn_sample", init_sample, cleanup_sample);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  ADD_TEST(sample, test_mvn_sample0);
  ADD_TEST(sample, test_mvn_sample1);
  ADD_TEST(sample, test_mvn_sample2);

  CU_pSuite pdf = CU_add_suite("gmcmc_mvn_logpdf", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  ADD_TEST(pdf, test_mvn_logpdf0);
  ADD_TEST(pdf, test_mvn_logpdf1);
  ADD_TEST(pdf, test_mvn_logpdf2);
  ADD_TEST(pdf, test_mvn_logpdf3);
  ADD_TEST(pdf, test_mvn_logpdf4);
  ADD_TEST(pdf, test_mvn_logpdf5);
  ADD_TEST(pdf, test_mvn_logpdf6);
  ADD_TEST(pdf, test_mvn_logpdf7);
  ADD_TEST(pdf, test_mvn_logpdf8);
  ADD_TEST(pdf, test_mvn_logpdf9);
  ADD_TEST(pdf, test_mvn_logpdf10);
  ADD_TEST(pdf, test_mvn_logpdf11);
  ADD_TEST(pdf, test_mvn_logpdf12);
  ADD_TEST(pdf, test_mvn_logpdf13);
  ADD_TEST(pdf, test_mvn_logpdf14);
  ADD_TEST(pdf, test_mvn_logpdf15);
  ADD_TEST(pdf, test_mvn_logpdf16);
  ADD_TEST(pdf, test_mvn_logpdf17);
  ADD_TEST(pdf, test_mvn_logpdf18);
  ADD_TEST(pdf, test_mvn_logpdf19);

  CU_pSuite pdfv = CU_add_suite("gmcmc_mvn_logpdfv", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  ADD_TEST(pdfv, test_mvn_logpdfv0);
  ADD_TEST(pdfv, test_mvn_logpdfv1);
  ADD_TEST(pdfv, test_mvn_logpdfv2);
  ADD_TEST(pdfv, test_mvn_logpdfv3);
  ADD_TEST(pdfv, test_mvn_logpdfv4);
  ADD_TEST(pdfv, test_mvn_logpdfv5);
  ADD_TEST(pdfv, test_mvn_logpdfv6);
  ADD_TEST(pdfv, test_mvn_logpdfv7);
  ADD_TEST(pdfv, test_mvn_logpdfv8);
  ADD_TEST(pdfv, test_mvn_logpdfv9);
  ADD_TEST(pdfv, test_mvn_logpdfv10);
  ADD_TEST(pdfv, test_mvn_logpdfv11);
  ADD_TEST(pdfv, test_mvn_logpdfv12);
  ADD_TEST(pdfv, test_mvn_logpdfv13);
  ADD_TEST(pdfv, test_mvn_logpdfv14);
  ADD_TEST(pdfv, test_mvn_logpdfv15);
  ADD_TEST(pdfv, test_mvn_logpdfv16);
  ADD_TEST(pdfv, test_mvn_logpdfv17);
  ADD_TEST(pdfv, test_mvn_logpdfv18);
  ADD_TEST(pdfv, test_mvn_logpdfv19);

  CU_pSuite pdfs = CU_add_suite("gmcmc_mvn_logpdfs", NULL, NULL);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  ADD_TEST(pdfs, test_mvn_logpdfs0);
  ADD_TEST(pdfs, test_mvn_logpdfs1);
  ADD_TEST(pdfs, test_mvn_logpdfs2);
  ADD_TEST(pdfs, test_mvn_logpdfs3);
  ADD_TEST(pdfs, test_mvn_logpdfs4);
  ADD_TEST(pdfs, test_mvn_logpdfs5);
  ADD_TEST(pdfs, test_mvn_logpdfs6);
  ADD_TEST(pdfs, test_mvn_logpdfs7);
  ADD_TEST(pdfs, test_mvn_logpdfs8);
  ADD_TEST(pdfs, test_mvn_logpdfs9);
  ADD_TEST(pdfs, test_mvn_logpdfs10);
  ADD_TEST(pdfs, test_mvn_logpdfs11);
  ADD_TEST(pdfs, test_mvn_logpdfs12);
  ADD_TEST(pdfs, test_mvn_logpdfs13);
  ADD_TEST(pdfs, test_mvn_logpdfs14);
  ADD_TEST(pdfs, test_mvn_logpdfs15);
  ADD_TEST(pdfs, test_mvn_logpdfs16);
  ADD_TEST(pdfs, test_mvn_logpdfs17);
  ADD_TEST(pdfs, test_mvn_logpdfs18);
  ADD_TEST(pdfs, test_mvn_logpdfs19);

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
