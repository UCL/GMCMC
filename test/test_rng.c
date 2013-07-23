#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_rng.h>
#include <stdlib.h>

#define N 10000000

/**
 * The parallel RNGs under test.
 */
static gmcmc_prng64 ** rngs;
static int n;

/**
 * Suite cleanup function.
 */
static int destroy_rngs() {
  if (rngs != NULL) {
    for (int i = 0; i < n; i++)
      gmcmc_prng64_destroy(rngs[i]);
  }
  free(rngs);
  return 0;
}

/**
 * Suite initialisation functions.
 */
static int create_mt19937() {
  int error;
  n = gmcmc_prng64_mt19937->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_mt19937->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_mt19937, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create mt19937", error);
    }
  }
  return 0;
}

static int create_mt19937_64() {
  int error;
  n = gmcmc_prng64_mt19937_64->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_mt19937_64->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_mt19937_64, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create mt19937_64", error);
    }
  }
  return 0;
}

static int create_dcmt521() {
  int error;
  n = gmcmc_prng64_dcmt521->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt521->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt521, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt521", error);
    }
  }
  return 0;
}

static int create_dcmt607() {
  int error;
  n = gmcmc_prng64_dcmt607->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt607->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt607, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt607", error);
    }
  }
  return 0;
}

static int create_dcmt1279() {
  int error;
  n = gmcmc_prng64_dcmt1279->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt1279->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt1279, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt1279", error);
    }
  }
  return 0;
}

static int create_dcmt2203() {
  int error;
  n = gmcmc_prng64_dcmt2203->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt2203->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt2203, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt2203", error);
    }
  }
  return 0;
}

static int create_dcmt2281() {
  int error;
  n = gmcmc_prng64_dcmt2281->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt2281->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt2281, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt2281", error);
    }
  }
  return 0;
}

static int create_dcmt3217() {
  int error;
  n = gmcmc_prng64_dcmt2281->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt3217->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt3217, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt3217", error);
    }
  }
  return 0;
}

static int create_dcmt4253() {
  int error;
  n = gmcmc_prng64_dcmt4253->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt4253->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt4253, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt4253", error);
    }
  }
  return 0;
}

static int create_dcmt9689() {
  int error;
  n = gmcmc_prng64_dcmt9689->max_id;
  if ((rngs = calloc(n, sizeof(gmcmc_prng64 *))) == NULL)
    GMCMC_ERROR("Failed to allocate rngs", GMCMC_ENOMEM);
  for (int i = 0; i < gmcmc_prng64_dcmt9689->max_id; i++) {
    if ((error = gmcmc_prng64_create(&rngs[i], gmcmc_prng64_dcmt9689, i)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_prng64_destroy(rngs[j]);
      free(rngs);
      GMCMC_ERROR("Failed to create dcmt9689", error);
    }
  }
  return 0;
}

/**
 * Integer generation test.
 */
static void test_get() {
  // Test each parallel RNG substream
  for (int i = 0; i < n; i++) {

    // Seed the RNG
    gmcmc_prng64_seed(rngs[i], 3241);

    double mean = 0, m2 = 0;
    for (uint64_t j = 0; j < N; j++) {
      uint64_t x = gmcmc_prng64_get(rngs[i]);

      // Test range
      CU_ASSERT(x >= rngs[i]->type->min);
      CU_ASSERT(x <= rngs[i]->type->max);

      // Calculate mean and variance using "online" algorithm (avoids overflow)
      double delta = x - mean;
      mean += delta / (j + 1);
      m2 += delta * (x - mean);
    }
    double variance = m2 / (N - 1);

    double n = rngs[i]->type->max - rngs[i]->type->min + 1;
    CU_ASSERT_DOUBLE_EQUAL(mean, (double)(rngs[i]->type->min + rngs[i]->type->max) / 2.0, 1.0e+07);
    CU_ASSERT_DOUBLE_EQUAL(variance, (n * n - 1.0) / 12.0, 1.0e+16);
  }
}

/**
 * Real generation test.
 */
static void test_get_double() {
  // Test each parallel RNG substream
  for (int i = 0; i < n; i++) {

    // Seed the RNG
    gmcmc_prng64_seed(rngs[i], 3241);

    double mean = 0, m2 = 0;
    for (uint64_t j = 0; j < N; j++) {
      double x = gmcmc_prng64_get_double(rngs[i]);

      // Test range
      CU_ASSERT(x >= 0.0);
      CU_ASSERT(x <  1.0);

      // Calculate mean and variance using "online" algorithm (avoids overflow)
      double delta = x - mean;
      mean += delta / (j + 1);
      m2 += delta * (x - mean);
    }
    double variance = m2 / (N - 1);

    CU_ASSERT_DOUBLE_EQUAL(mean, 0.5, 1.0e-03);
    CU_ASSERT_DOUBLE_EQUAL(variance, 0.0833, 1.0e-02);
  }
}

#define CUNIT_ERROR(message) \
  do { \
    CU_cleanup_registry(); \
    fprintf(stderr, "%s\nCUnit error code %d in %s (%s:%d): %s\n", \
                     message, CU_get_error(), __func__, __FILE__, __LINE__, \
                     CU_get_error_msg()); \
    return CU_get_error(); \
  } while (0)

#define TEST(rng) \
  do { \
    CU_pSuite rng = CU_add_suite(#rng, create_ ## rng, destroy_rngs); \
    if (CU_get_error() != CUE_SUCCESS) \
      CUNIT_ERROR("Failed to add suite to registry"); \
    \
    CU_ADD_TEST(rng, test_get); \
    if (CU_get_error() != CUE_SUCCESS) \
      CUNIT_ERROR("Failed to add test to suite"); \
    \
    CU_ADD_TEST(rng, test_get_double); \
    if (CU_get_error() != CUE_SUCCESS) \
      CUNIT_ERROR("Failed to add test to suite"); \
  } while(0)

int main() {
  CU_ErrorCode error = CU_initialize_registry();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to initialise test registry");


  TEST(mt19937);
  TEST(mt19937_64);
  TEST(dcmt521);
  TEST(dcmt607);
  TEST(dcmt1279);
  TEST(dcmt2203);
  TEST(dcmt2281);
  TEST(dcmt3217);
  TEST(dcmt4253);
  TEST(dcmt9689);

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
