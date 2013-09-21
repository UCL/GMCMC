#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_eye.h>
#include <gmcmc/gmcmc_proposal.h>

#include <stdlib.h>

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

static gmcmc_eye_dataset * data;
static gmcmc_model * model;

static int cleanup() {
  gmcmc_eye_model * eye_model = (gmcmc_eye_model *)gmcmc_model_get_modelspecific(model);
  gmcmc_eye_model_destroy(eye_model);
  gmcmc_model_destroy(model);
  gmcmc_eye_dataset_destroy(data);
  return 0;
}

static int init_eye() {
  int error;

  /*
   * Common model settings
   */

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(6 * sizeof(gmcmc_distribution *))) == NULL)
    GMCMC_ERROR("Failed to allocate space for priors", GMCMC_ENOMEM);

  if ((error = gmcmc_distribution_create_uniform(&priors[0], 0.0, 15.0)) != 0) {
    free(priors);
    GMCMC_ERROR("Unable to create priors", error);
  }
  if ((error = gmcmc_distribution_create_uniform(&priors[1], 0.0, 15.0)) != 0) {
    gmcmc_distribution_destroy(priors[0]);
    free(priors);
    GMCMC_ERROR("Unable to create priors", error);
  }
  if ((error = gmcmc_distribution_create_uniform(&priors[2], 1.0, 100.0)) != 0) {
    for (unsigned int j = 0; j < 2; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    GMCMC_ERROR("Unable to create priors", error);
  }
  if ((error = gmcmc_distribution_create_uniform(&priors[3], 1.0, 5.0)) != 0) {
    for (unsigned int j = 0; j < 3; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    GMCMC_ERROR("Unable to create priors", error);
  }
  if ((error = gmcmc_distribution_create_uniform(&priors[4], 1.0, 500.0)) != 0) {
    for (unsigned int j = 0; j < 4; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    GMCMC_ERROR("Unable to create priors", error);
  }
  if ((error = gmcmc_distribution_create_uniform(&priors[5], 1.0, 5.0)) != 0) {
    for (unsigned int j = 0; j < 5; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    GMCMC_ERROR("Unable to create priors", error);
  }

  // Load the dataset
  if ((error = gmcmc_eye_dataset_load_matlab(&data, "../data/MacroC500Hz_Data.mat")) != 0) {
    // Clean up
    for (unsigned int i = 0; i < 6; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    GMCMC_ERROR("Unable to load dataset", error);
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, 6, priors)) != 0) {
    for (unsigned int i = 0; i < 6; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    gmcmc_eye_dataset_destroy(data);
    GMCMC_ERROR("Unable to create model", error);
  }

  // Priors have been copied into model so don't need them any more
  for (unsigned int i = 0; i < 6; i++)
    gmcmc_distribution_destroy(priors[i]);
  free(priors);

  // Set up starting values for all temperatures
  double params[] = { 3.0, 2.0, 50.0, 2.0, 100.0, 2.0 };
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    gmcmc_eye_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to set initial parameter values", error);
  }

  // Set initial step size
  gmcmc_model_set_stepsize(model, 0.5);

  /*
   * Stochastic eye model settings
   */

  /*
   * Create a parallel random number generator to use
   */
  gmcmc_prng64 * rng;
  if ((error = gmcmc_prng64_create(&rng, gmcmc_prng64_dcmt607, 0)) != 0) {
    gmcmc_eye_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create parallel RNG\n", error);
  }

  // Seed the RNG
  gmcmc_prng64_seed(rng, 0);

  gmcmc_eye_model * eye_model;
  if ((gmcmc_eye_model_create(&eye_model, "../data/WNBG05_500Hz.txt",
                              115, 2010, rng)) != 0) {
    gmcmc_eye_dataset_destroy(data);
    gmcmc_model_destroy(model);
    gmcmc_prng64_destroy(rng);
    GMCMC_ERROR("Unable to create parallel RNG", error);
  }

  gmcmc_model_set_modelspecific(model, eye_model);

  return error;
}

#include "test_eye.c"

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

  CU_pSuite eye = CU_add_suite("Eye ALL", init_eye, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

#include "test_eye_main.c"

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
