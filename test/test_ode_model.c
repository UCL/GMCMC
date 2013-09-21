#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_ode.h>
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

static gmcmc_ode_dataset * data;
static gmcmc_model * model;

static int cleanup() {
  gmcmc_ode_model * ode_model = (gmcmc_ode_model *)gmcmc_model_get_modelspecific(model);
  gmcmc_ode_model_destroy(ode_model);
  gmcmc_model_destroy(model);
  gmcmc_ode_dataset_destroy(data);
  return 0;
}

/**
 * ODE right-hand side for the Fitz Hugh Nagumo model.
 */
static int fitzhugh_rhs(double t, const double * y, double * ydot, const double * params) {
  (void)t;      // Unused

  // Parameters
  double a = params[0];
  double b = params[1];
  double c = params[2];

  // Variables
  double v = y[0];
  double r = y[1];

  // d/dt(V) = c*(V-(V^3)/3+R)
  double vt = c * (v - ((v*v*v) / 3.0) + r);
  ydot[0] = vt;

  // d/dt(R) = -(V-a+b*R)/c
  double rt = -(v - a + b * r) / c;
  ydot[1] = rt;

  return 0;
}

static int init_fitzhugh_mh() {
  int error;

  // Load the dataset
  if ((error = gmcmc_ode_dataset_load_matlab(&data, "../data/FitzHugh_Benchmark_Data.mat")) != 0)
    GMCMC_ERROR("Failed to create Fitz Hugh Nagumo dataset", error);

  // Create the priors for each of the parameters and initial conditions
  gmcmc_distribution ** priors;
  if ((priors = malloc(5 * sizeof(gmcmc_distribution *))) == NULL) {
    gmcmc_ode_dataset_destroy(data);
    GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
  }

  // Parameters
  for (int i = 0; i < 3; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_ode_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Initial conditions
  for (int i = 3; i < 5; i++) {
    if ((error = gmcmc_distribution_create_normal(&priors[i], 0.0, 2.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_ode_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, 5, priors)) != 0) {
    for (int j = 0; j < 5; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    gmcmc_ode_dataset_destroy(data);
    GMCMC_ERROR("Failed to create Fitz Hugh Nagumo model", error);
  }

  // Don't need priors any more
  for (int j = 0; j < 5; j++)
    gmcmc_distribution_destroy(priors[j]);
  free(priors);

  // Set starting parameter values and initial conditions
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    gmcmc_model_destroy(model);
    gmcmc_ode_dataset_destroy(data);
    GMCMC_ERROR("Failed to set initial parameters", error);
  }

  // Set starting step size
  gmcmc_model_set_stepsize(model, 0.05);

  // Create ODE model specific stuff
  gmcmc_ode_model * ode_model;
  if ((error = gmcmc_ode_model_create(&ode_model, 2, 0, fitzhugh_rhs)) != 0) {
    gmcmc_ode_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create ODE specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ode_model);

  return 0;
}

#include "test_fitzhugh_mh.c"

static int init_fitzhugh_simp_mmala() {
  int error;

  // Load the dataset
  if ((error = gmcmc_ode_dataset_load_matlab(&data, "../data/FitzHugh_Benchmark_Data.mat")) != 0)
    GMCMC_ERROR("Failed to create Fitz Hugh Nagumo dataset", error);

  // Create the priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(3 * sizeof(gmcmc_distribution *))) == NULL) {
    gmcmc_ode_dataset_destroy(data);
    GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
  }

  // Parameters
  for (int i = 0; i < 3; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_ode_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, 3, priors)) != 0) {
    for (int j = 0; j < 3; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    gmcmc_ode_dataset_destroy(data);
    GMCMC_ERROR("Failed to create Fitz Hugh Nagumo model", error);
  }

  // Don't need priors any more
  for (int j = 0; j < 3; j++)
    gmcmc_distribution_destroy(priors[j]);
  free(priors);

  // Set starting parameter values and initial conditions
  double params[] = { 0.2, 0.2, 3.0 };
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    gmcmc_model_destroy(model);
    gmcmc_ode_dataset_destroy(data);
    GMCMC_ERROR("Failed to set initial parameters", error);
  }

  // Set starting step size
  gmcmc_model_set_stepsize(model, 0.05);

  // Create ODE model specific stuff
  gmcmc_ode_model * ode_model;
  if ((error = gmcmc_ode_model_create(&ode_model, 2, 0, fitzhugh_rhs)) != 0) {
    gmcmc_ode_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create ODE specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ode_model);

  // Set initial conditions
  double ics[] = { -1.0, 1.0 };
  if ((error = gmcmc_ode_model_set_ics(ode_model, ics)) != 0) {
    gmcmc_ode_dataset_destroy(data);
    gmcmc_model_destroy(model);
    gmcmc_ode_model_destroy(ode_model);
    GMCMC_ERROR("Unable to create ODE specific model", error);
  }

  return 0;
}

#include "test_fitzhugh_simp_mmala.c"

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

  CU_pSuite fitzhugh_mh = CU_add_suite("Fitz Hugh Nagumo MH", init_fitzhugh_mh, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

#include "test_fitzhugh_mh_main.c"

  CU_pSuite fitzhugh_simp_mmala = CU_add_suite("Fitz Hugh Nagumo Simplified mMALA", init_fitzhugh_simp_mmala, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

#include "test_fitzhugh_simp_mmala_main.c"

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
