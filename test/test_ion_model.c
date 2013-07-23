#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_ion_model.h>
#include <stdlib.h>

static gmcmc_dataset * data;
static gmcmc_model * model;

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

  // Load the dataset
  if ((error = gmcmc_dataset_create_matlab(&data, "../data/ION_dCK_0,5s.mat")) != 0)
    GMCMC_ERROR("Failed to create Castillo Katz dataset", error);

  // Create the priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(4 * sizeof(gmcmc_distribution *))) == NULL) {
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
  }

  for (int i = 0; i < 4; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], -2.0, 4.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, 4, priors, gmcmc_ion_proposal_mh, gmcmc_ion_likelihood_mh)) != 0) {
    for (int j = 0; j < 4; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to create Castillo Katz model", error);
  }

  // Don't need priors any more
  for (int j = 0; j < 4; j++)
    gmcmc_distribution_destroy(priors[j]);
  free(priors);

  // Set initial parameter values
  double params[] = { 2.0, 2.0, 3.0, 3.0 };
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    gmcmc_model_destroy(model);
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to set initial parameters", error);
  }

  // Set initial step size
  gmcmc_model_set_stepsize(model, 1.0);

  // Create ion model specific stuff
  gmcmc_ion_model * ion_model;
  if ((error = gmcmc_ion_model_create(&ion_model, 2, 1, castillo_katz)) != 0) {
    gmcmc_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create Ion Channel specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ion_model);

  return 0;
}

static void five_state(const double * params, double * Q, size_t ldq) {
  // As described in Ch 18 & 20 in Single Channel Recording book

  // Rename for clarity
  double K_p1     = pow(10.0, params[0]);       // k_{+1}
  double K_m1     = pow(10.0, params[1]);       // k_{-1}
  double K_p2     = pow(10.0, params[2]);       // k_{+2}
  double K_m2     = pow(10.0, params[3]);       // k_{-2}
  double KStar_p2 = pow(10.0, params[4]);       // k*_{+2}
  double KStar_m2 = pow(10.0, params[5]);       // k*_{-2}
  double Beta_1   = pow(10.0, params[6]);       // Beta_{1}
  double Alpha_1  = pow(10.0, params[7]);       // Alpha_{1}
  double Beta_2   = pow(10.0, params[8]);       // Beta_{2}
  double Alpha_2  = pow(10.0, params[9]);       // Alpha_{2}

  // Agonist concentration
  double X_A = 1e-7;    // This should become an extra variable to be passed

  // Construct Q matrix - [1 2 3] are closed states, [4 5] are open
  // Q_FF
  Q[0 * ldq + 0] = -(Beta_2 + 2.0 * K_m2);
  Q[0 * ldq + 1] = K_p2 * X_A;
  Q[1 * ldq + 0] = 2.0 * K_m2;
  Q[1 * ldq + 1] = -(Beta_1 + K_p2 * X_A + K_m1);
  Q[1 * ldq + 2] = 2.0 * K_p1 * X_A;
  Q[2 * ldq + 1] = K_m1;
  Q[2 * ldq + 2] = -2.0 * K_p1 * X_A;

  //Q_AF
  Q[0 * ldq + 4] = Alpha_2;
  Q[1 * ldq + 3] = Alpha_1;

  // Q_FA
  Q[3 * ldq + 1] = Beta_1;
  Q[4 * ldq + 0] = Beta_2;

  // Q_AA
  Q[3 * ldq + 3] = -(Alpha_1 + KStar_p2 * X_A);
  Q[3 * ldq + 4] = 2.0 * KStar_m2;
  Q[4 * ldq + 3] = KStar_p2 * X_A;
  Q[4 * ldq + 4] = -(Alpha_2 + 2.0 * KStar_m2);
}

static int init_five_state() {
  int error;

  // Load the dataset
  if ((error = gmcmc_dataset_create_matlab(&data, "../data/ION_Five_State_True_Data_Long.mat")) != 0)
    GMCMC_ERROR("Failed to create Five State dataset", error);

  // Create the priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(10 * sizeof(gmcmc_distribution *))) == NULL) {
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
  }

  for (int i = 0; i < 10; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], -2.0, 10.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, 10, priors, gmcmc_ion_proposal_mh, gmcmc_ion_likelihood_mh)) != 0) {
    for (int j = 0; j < 10; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to create Five State model", error);
  }

  // Don't need priors any more
  for (int j = 0; j < 10; j++)
    gmcmc_distribution_destroy(priors[j]);
  free(priors);

  // Set initial parameter values
  double params[] = { log10(5.0e+07), log10(2.0e+03), log10(5.0e+08), log10(2.0e+03), log10(5.0e+08),
                      log10(0.333333333333333), log10(15), log10(3.0e+03), log10(1.5e+04), log10(0.5) };

  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    gmcmc_model_destroy(model);
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to set initial parameters", error);
  }

  // Set initial step size
  gmcmc_model_set_stepsize(model, 0.01);

  // Create ion model specific stuff
  gmcmc_ion_model * ion_model;
  if ((error = gmcmc_ion_model_create(&ion_model, 3, 2, five_state)) != 0) {
    gmcmc_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create Ion Channel specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ion_model);

  return 0;
}

static int cleanup() {
  gmcmc_ion_model * ion_model = (gmcmc_ion_model *)gmcmc_model_get_modelspecific(model);
  gmcmc_ion_model_destroy(ion_model);
  gmcmc_model_destroy(model);
  gmcmc_dataset_destroy(data);
  return 0;
}

static void test_castillo_katz_ion_likelihood_mh0() {
  // Input argument
  double params[4] = {  0.725404224946106, -0.0630548731896562,  0.714742903826096, -0.204966058299775 };

  // Output argument
  double likelihood;

  // Call test function
  int error = gmcmc_likelihood(data, model, params, &likelihood, NULL, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(likelihood, 2.134142999129227e+02, 1.0e-04);
}

#include "test_castillo_katz_fn.c"
//
// static void test_five_state_ion_likelihood_mh0() {
//   // Input argument
//   double params[10] = { log10(5.0e+07), log10(2.0e+03), log10(5.0e+08), log10(2.0e+03), log10(5.0e+08),
//                         log10(0.333333333333333), log10(15), log10(3.0e+03), log10(1.5e+04),log10(0.5) };
//   // Output argument
//   double likelihood;
//
//   // Call test function
//   int error = gmcmc_likelihood(data, model, params, 10, &likelihood, NULL, NULL);
//
//   // Check return value
//   CU_ASSERT(error == 0);
//
//   // Check log likelihood
//   CU_ASSERT_DOUBLE_EQUAL(likelihood, 1.630281159570081e+03, 1.0e-04);
// }
//
// #include "test_five_state_fn.c"

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

  CU_ADD_TEST(castillo_katz, test_castillo_katz_ion_likelihood_mh0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

#include "test_castillo_katz_main.c"
/*
  CU_pSuite five_state = CU_add_suite("Five State", init_five_state, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(five_state, test_five_state_ion_likelihood_mh0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

#include "test_five_state_main.c"*/

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
