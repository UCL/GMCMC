#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_ion.h>
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

static gmcmc_ion_dataset * data;
static gmcmc_model * model;

static int cleanup() {
  gmcmc_ion_model * ion_model = (gmcmc_ion_model *)gmcmc_model_get_modelspecific(model);
  gmcmc_ion_model_destroy(ion_model);
  gmcmc_model_destroy(model);
  gmcmc_ion_dataset_destroy(data);
  return 0;
}

/**
 * Q matrix for Castillo Katz model.
 */
static void castillo_katz(const double * params, double * Q, size_t ldq) {
  // Rename for clarity
  double K_1   = pow(10.0, params[0]);
  double K_2   = pow(10.0, params[1]);
  double Beta  = pow(10.0, params[2]);
  double Alpha = pow(10.0, params[3]);

  // Construct Q matrix
  // 3 states for this model
  Q[0] = -K_1;
  Q[1] =  K_2;
  Q[2] =  0.0;

  Q[ldq + 0] =  K_1;
  Q[ldq + 1] = -K_2 - Beta;
  Q[ldq + 2] = Alpha;

  Q[2 * ldq + 0] =  0.0;
  Q[2 * ldq + 1] = Beta;
  Q[2 * ldq + 2] = -Alpha;
}

static int init_castillo_katz() {
  int error;

  /*
   * Common model settings
   */
  const unsigned int num_params = 4;

  // Set up priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(num_params * sizeof(gmcmc_distribution *))) == NULL)
    GMCMC_ERROR("Failed to allocate space for priors", GMCMC_ENOMEM);

  // Set up priors for log space
  for (unsigned int i = 0; i < num_params; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], -2.0, 4.0)) != 0) {
      // Clean up
      for (unsigned int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[i]);
      free(priors);
      GMCMC_ERROR("Unable to create priors", error);
    }
  }

  // Load the data
  if ((error = gmcmc_ion_dataset_load_hdf5(&data, "../data/ION_dCK_0,5s.h5")) != 0) {
    // Clean up
    for (unsigned int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    GMCMC_ERROR("Unable to load data", error);
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, num_params, priors)) != 0) {
    // Clean up
    for (unsigned int i = 0; i < num_params; i++)
      gmcmc_distribution_destroy(priors[i]);
    free(priors);
    gmcmc_ion_dataset_destroy(data);
    GMCMC_ERROR("Unable to create model", error);
  }

  // Priors have been copied into model so don't need them here any more
  for (unsigned int i = 0; i < num_params; i++)
    gmcmc_distribution_destroy(priors[i]);
  free(priors);

  // Set up starting values for all temperatures
  double params[] = { 2.0, 2.0, 3.0, 3.0 };
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    // Clean up
    gmcmc_ion_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to set initial parameter values", error);
  }

  // Set initial step size
  gmcmc_model_set_stepsize(model, 1.0);

  /*
   * ION model settings
   */
  gmcmc_ion_model * ion_model;
  if ((error = gmcmc_ion_model_create(&ion_model, 2, 1, castillo_katz)) != 0) {
    // Clean up
    gmcmc_ion_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create Ion Channel specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ion_model);

  return error;
}

#include "test_castillo_katz.c"

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

  CU_pSuite castillo_katz = CU_add_suite("Castillo Katz", init_castillo_katz, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

#include "test_castillo_katz_main.c"

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
