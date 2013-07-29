#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_ode_model.h>
#include <stdlib.h>
#include <cvodes/cvodes.h>
#include <cvodes/cvodes_dense.h>
#include <nvector/nvector_serial.h>

static gmcmc_dataset * data;
static gmcmc_model * model;

static int cleanup() {
  gmcmc_ode_model * ode_model = (gmcmc_ode_model *)gmcmc_model_get_modelspecific(model);
  gmcmc_ode_model_destroy(ode_model);
  gmcmc_model_destroy(model);
  gmcmc_dataset_destroy(data);
  return 0;
}

static int fitzhugh_rhs(realtype t, N_Vector y, N_Vector ydot, void * userdata) {
  (void)t;      // Unused

  // Parameters are stored in userdata
  double * params = (double *)userdata;

  realtype a = params[0];
  realtype b = params[1];
  realtype c = params[2];

  realtype v = NV_Ith_S(y, 0);
  realtype r = NV_Ith_S(y, 1);

  // d/dt(V) = c*(V-(V^3)/3+R)
  realtype vt = c * (v - ((v*v*v) / 3.0) + r);
  NV_Ith_S(ydot, 0) = vt;

  // d/dt(R) = -(V-a+b*R)/c
  realtype rt = -(v - a + b * r) / c;
  NV_Ith_S(ydot, 1) = rt;

  return 0;
}

static int fitzhugh_solve(size_t num_timepoints, size_t num_species, const double * timepoints, const double * params, double * simdata, size_t lds) {
  const unsigned int num_params = 3;

  realtype cvodes_ics[num_species];
  for (unsigned int i = 0; i < num_species; i++)
    cvodes_ics[i] = params[num_params + i];

  // Create CVODES solver
  void * cvode_mem;
  if ((cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON)) == NULL)
    GMCMC_ERROR("Failed to create CVODES solver", GMCMC_ELINAL);

  // Initialise CVODES solver
  N_Vector ics = N_VMake_Serial(num_species, cvodes_ics);
  int error = CVodeInit(cvode_mem, fitzhugh_rhs, timepoints[0], ics);
  N_VDestroy(ics);
  if (error != CV_SUCCESS)
    GMCMC_ERROR("Failed to initialise ODE solver", GMCMC_ELINAL);

  // Set user data
  if ((error = CVodeSetUserData(cvode_mem, (void *)params)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to set ODE solver user data", GMCMC_ELINAL);
  }

  // Specify integration tolerances
  if ((error = CVodeSStolerances(cvode_mem, 1.0e-08, 1.0e-08)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to specify ODE solver integration tolerances", GMCMC_ELINAL);
  }

  // Attach linear solver module
  if ((error = CVDense(cvode_mem, num_species)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to attach ODE linear solver module", GMCMC_ELINAL);
  }

  // Initial values (part of parameter vector)
  for (unsigned int i = 0; i < num_species; i++)
    simdata[i * lds] = params[3 + i];

  // Advance solution in time
  N_Vector yout = N_VNew_Serial(num_species);
  for (size_t i = 1; i < num_timepoints; i++) {
    double tret;
    if ((error = CVode(cvode_mem, timepoints[i], yout, &tret, CV_NORMAL)) != CV_SUCCESS) {
      CVodeFree(&cvode_mem);
      GMCMC_ERROR("Failed to solve ODE", GMCMC_ELINAL);
    }
    for (unsigned int j = 0; j < num_species; j++)
      simdata[j * lds + i] = NV_Ith_S(yout, j);
  }
  N_VDestroy(yout);

  // Free the solver
  CVodeFree(&cvode_mem);

  return 0;
}

// static int init_fitzhugh_mh() {
//   int error;
//
//   // Load the dataset
//   if ((error = gmcmc_dataset_create_matlab_ode(&data, "../data/FitzHugh_Benchmark_Data.mat")) != 0)
//     GMCMC_ERROR("Failed to create Fitz Hugh Nagumo dataset", error);
//
//   // Create the priors for each of the parameters and initial conditions
//   gmcmc_distribution ** priors;
//   if ((priors = malloc(5 * sizeof(gmcmc_distribution *))) == NULL) {
//     gmcmc_dataset_destroy(data);
//     GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
//   }
//
//   // Parameters
//   for (int i = 0; i < 3; i++) {
//     if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
//       for (int j = 0; j < i; j++)
//         gmcmc_distribution_destroy(priors[j]);
//       free(priors);
//       gmcmc_dataset_destroy(data);
//       GMCMC_ERROR("Failed to create prior", error);
//     }
//   }
//
//   // Initial conditions
//   for (int i = 3; i < 5; i++) {
//     if ((error = gmcmc_distribution_create_normal(&priors[i], 0.0, 2.0)) != 0) {
//       for (int j = 0; j < i; j++)
//         gmcmc_distribution_destroy(priors[j]);
//       free(priors);
//       gmcmc_dataset_destroy(data);
//       GMCMC_ERROR("Failed to create prior", error);
//     }
//   }
//
//   // Create the model
//   if ((error = gmcmc_model_create(&model, 5, priors, gmcmc_ode_proposal_mh, gmcmc_ode_likelihood_mh)) != 0) {
//     for (int j = 0; j < 5; j++)
//       gmcmc_distribution_destroy(priors[j]);
//     free(priors);
//     gmcmc_dataset_destroy(data);
//     GMCMC_ERROR("Failed to create Fitz Hugh Nagumo model", error);
//   }
//
//   // Don't need priors any more
//   for (int j = 0; j < 5; j++)
//     gmcmc_distribution_destroy(priors[j]);
//   free(priors);
//
//   // Set starting parameter values and initial conditions
//   double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
//   if ((error = gmcmc_model_set_params(model, params)) != 0) {
//     gmcmc_model_destroy(model);
//     gmcmc_dataset_destroy(data);
//     GMCMC_ERROR("Failed to set initial parameters", error);
//   }
//
//   // Set starting step size
//   gmcmc_model_set_stepsize(model, 0.05);
//
//   // Create ODE model specific stuff
//   gmcmc_ode_model * ode_model;
//   if ((error = gmcmc_ode_model_create(&ode_model, 2, 0, fitzhugh_solve)) != 0) {
//     gmcmc_dataset_destroy(data);
//     gmcmc_model_destroy(model);
//     GMCMC_ERROR("Unable to create ODE specific model", error);
//   }
//
//   gmcmc_model_set_modelspecific(model, ode_model);
//
//   return 0;
// }
//
// static void test_fitzhugh_ode_proposal_mh0() {
//   // Input arguments
//   double params[] = { 3.75369331630836722, 7.29748948059328573, 3.92890129392862431, -1.25843447912960249, -1.71859761751866258 };
//   double likelihood = -19910.156388690345920624;
//   double temperature = 0.0;
//   double stepsize = 0.05;
//
//   // Output arguments
//   double mean[5], covariance[5 * 5];
//   size_t ldc = 5;
//
//   // Call test function
//   int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);
//
//   // Check return value
//   CU_ASSERT(error == 0);
//
//   // Check mean
//   CU_ASSERT_DOUBLE_EQUAL(mean[0],  3.75369331630836722,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[1],  7.29748948059328573,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[2],  3.92890129392862431,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[3], -1.25843447912960249,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[4], -1.71859761751866258,  1.0e-15);
//
//   // Check covariance
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.0025, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.0025, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.0025, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.0025, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.0025, 1.0e-15);
// }
//
// static void test_fitzhugh_ode_proposal_mh1() {
//   // Input arguments
//   double params[] = { 3.04837492547656463, 6.86231635078205748, 4.79993810438850410, -0.09967384043969969, -0.56680832815333382 };
//   double likelihood = -19186.91807532797247404;
//   double temperature = 0.000016935087808;
//   double stepsize = 0.3;
//
//   // Output arguments
//   double mean[5], covariance[5 * 5];
//   size_t ldc = 5;
//
//   // Call test function
//   int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);
//
//   // Check return value
//   CU_ASSERT(error == 0);
//
//   // Check mean
//   CU_ASSERT_DOUBLE_EQUAL(mean[0],  3.04837492547656463, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[1],  6.86231635078205748, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[2],  4.79993810438850410, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[3], -0.09967384043969969, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[4], -0.56680832815333382, 1.0e-15);
//
//   // Check covariance
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.09, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.09, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.09, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.09, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.09, 1.0e-15);
// }
//
// static void test_fitzhugh_ode_proposal_mh2() {
//   // Input arguments
//   double params[] = { 0.08829895521208686, 1.71812890595143641, 3.79060599495364148, -2.92860922416152558, 1.29210637801978523 };
//   double likelihood = -14266.39300342947899480;
//   double temperature = 0.000541922809870;
//   double stepsize = 0.6;
//
//   // Output arguments
//   double mean[5], covariance[5 * 5];
//   size_t ldc = 5;
//
//   // Call test function
//   int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);
//
//   // Check return value
//   CU_ASSERT(error == 0);
//
//   // Check mean
//   CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.08829895521208686,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[1],  1.71812890595143641,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[2],  3.79060599495364148,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[3], -2.92860922416152558,  1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[4],  1.29210637801978523,  1.0e-15);
//
//   // Check covariance
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.36, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.36, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.36, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.36, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.00, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.36, 1.0e-15);
// }
//
// static void test_fitzhugh_ode_proposal_mh3() {
//   // Input arguments
//   double params[] = { 0.30372094918578207, 0.59759227677645554, 2.27706232347379034, -1.08710268537402177, 0.93378534393013957 };
//   double likelihood = -685.03848870054048348;
//   double temperature = 0.004115226337449;
//   double stepsize = 0.72;
//
//   // Output arguments
//   double mean[5], covariance[5 * 5];
//   size_t ldc = 5;
//
//   // Call test function
//   int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);
//
//   // Check return value
//   CU_ASSERT(error == 0);
//
//   // Check mean
//   CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.30372094918578207, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.59759227677645554, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.27706232347379034, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[3], -1.08710268537402177, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[4],  0.93378534393013957, 1.0e-15);
//
//   // Check covariance
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.5184, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.5184, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.5184, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.5184, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.5184, 1.0e-15);
// }
//
// static void test_fitzhugh_ode_proposal_mh4() {
//   // Input arguments
//   double params[] = { 0.09985485438060315, 0.17602230163985444, 3.06347750358440152, -1.17678682036175175, 1.30189906244667952 };
//   double likelihood = -66.40234909239138972;
//   double temperature = 0.017341529915833;
//   double stepsize = 0.32;
//
//   // Output arguments
//   double mean[5], covariance[5 * 5];
//   size_t ldc = 5;
//
//   // Call test function
//   int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);
//
//   // Check return value
//   CU_ASSERT(error == 0);
//
//   // Check mean
//   CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.09985485438060315, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.17602230163985444, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[2],  3.06347750358440152, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[3], -1.17678682036175175, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(mean[4],  1.30189906244667952, 1.0e-15);
//
//   // Check covariance
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.1024, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.1024, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.1024, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.1024, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.0000, 1.0e-15);
//   CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.1024, 1.0e-15);
// }
/*
static void test_fitzhugh_ode_likelihood_mh0() {
  // Input argument
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };

  // Output argument
  double likelihood;

  // Call test function
  int error = gmcmc_likelihood(data, model, params, &likelihood, NULL, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(likelihood, 157.407952213302934, 1.0e-06);
}*/

// #include "test_fitzhugh_mh.c"

static int init_fitzhugh_simp_mmala() {
  int error;

  // Load the dataset
  if ((error = gmcmc_dataset_create_matlab_ode(&data, "../data/FitzHugh_Benchmark_Data.mat")) != 0)
    GMCMC_ERROR("Failed to create Fitz Hugh Nagumo dataset", error);

  // Create the priors for each of the parameters and initial conditions
  gmcmc_distribution ** priors;
  if ((priors = malloc(5 * sizeof(gmcmc_distribution *))) == NULL) {
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
  }

  // Parameters
  for (int i = 0; i < 3; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Initial conditions
  for (int i = 3; i < 5; i++) {
    if ((error = gmcmc_distribution_create_normal(&priors[i], 0.0, 2.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, 5, priors, gmcmc_ode_proposal_simp_mmala, gmcmc_ode_likelihood_simp_mmala)) != 0) {
    for (int j = 0; j < 5; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    gmcmc_dataset_destroy(data);
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
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to set initial parameters", error);
  }

  // Set starting step size
  gmcmc_model_set_stepsize(model, 0.05);

  // Create ODE model specific stuff
  gmcmc_ode_model * ode_model;
  if ((error = gmcmc_ode_model_create(&ode_model, 2, 0, fitzhugh_solve)) != 0) {
    gmcmc_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create ODE specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ode_model);

  return 0;
}

static void test_fitzhugh_ode_proposal_simp_mmala0() {
  // Input arguments
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
  double likelihood = 1.574080577970586e+02;
  double temperature = 1.693508780843028e-05;
  double stepsize = 0.05;
  size_t ldfi = 6u & ~1u;
  double serdata[5 * (3 + ldfi)];
  double * grad_ll = &serdata[0];
  double * grad_log_prior = &grad_ll[5];
  double * FI = &grad_log_prior[5];
  double * hessian_log_prior = &FI[5 * ldfi];

  grad_ll[0] = -1.070151942731803e+02;
  grad_ll[1] = -1.346556037556456e+02;
  grad_ll[2] = -1.973831276516403e+02;
  grad_ll[3] = 0.0;
  grad_ll[4] = 0.0;

  grad_log_prior[0] =  0.0;
  grad_log_prior[1] =  0.0;
  grad_log_prior[2] =  0.0;
  grad_log_prior[3] =  0.25;
  grad_log_prior[4] = -0.25;

  FI[0 * ldfi + 0] = 120316.531081183;
  FI[0 * ldfi + 1] = 14055.7330081162;
  FI[0 * ldfi + 2] = 65011.4112903610;
  FI[0 * ldfi + 3] = 0.0;
  FI[0 * ldfi + 4] = 0.0;
  FI[1 * ldfi + 0] = 14055.7330081162;
  FI[1 * ldfi + 1] =  4153.22271141330;
  FI[1 * ldfi + 2] =  9386.70767232743;
  FI[1 * ldfi + 3] =     0.0;
  FI[1 * ldfi + 4] =     0.0;
  FI[2 * ldfi + 0] = 65011.4112903610;
  FI[2 * ldfi + 1] =  9386.70767232743;
  FI[2 * ldfi + 2] = 45343.4336235647;
  FI[2 * ldfi + 3] =     0.0;
  FI[2 * ldfi + 4] =     0.0;
  FI[3 * ldfi + 0] =  0.0;
  FI[3 * ldfi + 1] =  0.0;
  FI[3 * ldfi + 2] =  0.0;
  FI[3 * ldfi + 3] =  0.0;
  FI[3 * ldfi + 4] =  0.0;
  FI[4 * ldfi + 0] =  0.0;
  FI[4 * ldfi + 1] =  0.0;
  FI[4 * ldfi + 2] =  0.0;
  FI[4 * ldfi + 3] =  0.0;
  FI[4 * ldfi + 4] =  0.0;

  hessian_log_prior[0] =  0.0;
  hessian_log_prior[1] =  0.0;
  hessian_log_prior[2] =  0.0;
  hessian_log_prior[3] = -0.25;
  hessian_log_prior[4] = -0.25;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, serdata, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.200009340556823,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.199944424645276,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.999992671439815,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -0.998750000000000,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  0.998750000000000,  1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0],  0.005478759445322, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], -0.001481183345936, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], -0.007548578068104, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], -0.001481183345936, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6],  0.067196543565177, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], -0.011786943524723, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], -0.007548578068104, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], -0.011786943524723, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12],  0.016518528633670, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18],  0.01, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23],  0.0, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24],  0.01, 1.0e-15);
}

static void test_fitzhugh_ode_proposal_simp_mmala1() {
  // Input arguments
  double params[] = { 0.103216027982443, 0.114050900604848, 3.176101354314640, -0.640910306027424, 1.275693702988488 };
  double likelihood = -227.575800991256358;
  double temperature = 1.693508780843028e-05;
  double stepsize = 0.05;
  size_t ldfi = 6u & ~1u;
  double serdata[5 * (3 + ldfi)];
  double * grad_ll = &serdata[0];
  double * grad_log_prior = &grad_ll[5];
  double * FI = &grad_log_prior[5];
  double * hessian_log_prior = &FI[5 * ldfi];

  grad_ll[0] = 2488.307921250810978;
  grad_ll[1] =   34.621150515919112;
  grad_ll[2] = -652.013036490050354;
  grad_ll[3] = 0.0;
  grad_ll[4] = 0.0;

  grad_log_prior[0] =  0.0;
  grad_log_prior[1] =  0.0;
  grad_log_prior[2] =  0.0;
  grad_log_prior[3] =  0.160227576506856;
  grad_log_prior[4] = -0.318923425747122;

  FI[0 * ldfi + 0] = 73849.283478198049124;
  FI[0 * ldfi + 1] = -3585.235450996659893;
  FI[0 * ldfi + 2] = 50967.600431084036245;
  FI[0 * ldfi + 3] = 0.0;
  FI[0 * ldfi + 4] = 0.0;
  FI[1 * ldfi + 0] = -3585.235450996659893;
  FI[1 * ldfi + 1] =  2238.767543796857808;
  FI[1 * ldfi + 2] = -3179.923494471355298;
  FI[1 * ldfi + 3] =     0.0;
  FI[1 * ldfi + 4] =     0.0;
  FI[2 * ldfi + 0] = 50967.600431084036245;
  FI[2 * ldfi + 1] = -3179.923494471355298;
  FI[2 * ldfi + 2] = 55954.435327576269628;
  FI[2 * ldfi + 3] =     0.0;
  FI[2 * ldfi + 4] =     0.0;
  FI[3 * ldfi + 0] =  0.0;
  FI[3 * ldfi + 1] =  0.0;
  FI[3 * ldfi + 2] =  0.0;
  FI[3 * ldfi + 3] =  0.0;
  FI[3 * ldfi + 4] =  0.0;
  FI[4 * ldfi + 0] =  0.0;
  FI[4 * ldfi + 1] =  0.0;
  FI[4 * ldfi + 2] =  0.0;
  FI[4 * ldfi + 3] =  0.0;
  FI[4 * ldfi + 4] =  0.0;

  hessian_log_prior[0] =  0.0;
  hessian_log_prior[1] =  0.0;
  hessian_log_prior[2] =  0.0;
  hessian_log_prior[3] = -0.25;
  hessian_log_prior[4] = -0.25;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, serdata, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.103357669641303,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.114096822488396,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  3.175960380258764,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -0.640109168144890,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  1.274099085859752,  1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0],  0.005428575138679, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1],  0.001816646501261, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], -0.004841522394102, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5],  0.001816646501261, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6],  0.072337217257050, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7],  0.002456225371143, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], -0.004841522394102, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11],  0.002456225371143, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12],  0.007187882162898, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18],  0.010000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24],  0.010000000000000, 1.0e-15);
}

static void test_fitzhugh_ode_proposal_simp_mmala2() {
  // Input arguments
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
  double likelihood = 157.408057797058575;
  double temperature = 5.419228098697690e-04;
  double stepsize = 0.05;
  size_t ldfi = 6u & ~1u;
  double serdata[5 * (3 + ldfi)];
  double * grad_ll = &serdata[0];
  double * grad_log_prior = &grad_ll[5];
  double * FI = &grad_log_prior[5];
  double * hessian_log_prior = &FI[5 * ldfi];

  grad_ll[0] = -107.015194273180327;
  grad_ll[1] = -134.655603755645586;
  grad_ll[2] = -197.383127651640280;
  grad_ll[3] =    0.000000000000000;
  grad_ll[4] =    0.000000000000000;

  grad_log_prior[0] =  0.000000000000000;
  grad_log_prior[1] =  0.000000000000000;
  grad_log_prior[2] =  0.000000000000000;
  grad_log_prior[3] =  0.250000000000000;
  grad_log_prior[4] = -0.250000000000000;

  FI[0 * ldfi + 0] = 120316.531081182896742;
  FI[0 * ldfi + 1] =  14055.733008116238125;
  FI[0 * ldfi + 2] =  65011.411290360978455;
  FI[0 * ldfi + 3] =      0.000000000000000;
  FI[0 * ldfi + 4] =      0.000000000000000;
  FI[1 * ldfi + 0] =  14055.733008116238125;
  FI[1 * ldfi + 1] =   4153.222711413294746;
  FI[1 * ldfi + 2] =   9386.707672327431283;
  FI[1 * ldfi + 3] =      0.000000000000000;
  FI[1 * ldfi + 4] =      0.000000000000000;
  FI[2 * ldfi + 0] =  65011.411290360978455;
  FI[2 * ldfi + 1] =   9386.707672327431283;
  FI[2 * ldfi + 2] =  45343.433623564727895;
  FI[2 * ldfi + 3] =      0.000000000000000;
  FI[2 * ldfi + 4] =      0.000000000000000;
  FI[3 * ldfi + 0] =      0.000000000000000;
  FI[3 * ldfi + 1] =      0.000000000000000;
  FI[3 * ldfi + 2] =      0.000000000000000;
  FI[3 * ldfi + 3] =      0.000000000000000;
  FI[3 * ldfi + 4] =      0.000000000000000;
  FI[4 * ldfi + 0] =      0.000000000000000;
  FI[4 * ldfi + 1] =      0.000000000000000;
  FI[4 * ldfi + 2] =      0.000000000000000;
  FI[4 * ldfi + 3] =      0.000000000000000;
  FI[4 * ldfi + 4] =      0.000000000000000;

  hessian_log_prior[0] =  0.0;
  hessian_log_prior[1] =  0.0;
  hessian_log_prior[2] =  0.0;
  hessian_log_prior[3] = -0.25;
  hessian_log_prior[4] = -0.25;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, serdata, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.200009340556823, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.199944424645276, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.999992671439815, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -0.998750000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  0.998750000000000, 1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0],  0.000171211232666, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], -0.000046286979561, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], -0.000235893064628, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], -0.000046286979561, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6],  0.002099891986412, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], -0.000368341985148, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], -0.000235893064628, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], -0.000368341985148, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12],  0.000516204019802, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18],  0.010000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24],  0.010000000000000, 1.0e-15);
}

static void test_fitzhugh_ode_proposal_simp_mmala3() {
  // Input arguments
  double params[] = { 0.239720619179379, 0.222350623941811, 2.937781998751281, -0.927275709617390, 0.978253394170023 };
  double likelihood = 123.717122572185005;
  double temperature = 5.419228098697690e-04;
  double stepsize = 0.05;
  size_t ldfi = 6u & ~1u;
  double serdata[5 * (3 + ldfi)];
  double * grad_ll = &serdata[0];
  double * grad_log_prior = &grad_ll[5];
  double * FI = &grad_log_prior[5];
  double * hessian_log_prior = &FI[5 * ldfi];

  grad_ll[0] = 1498.278263643481296;
  grad_ll[1] =  176.963615896931913;
  grad_ll[2] = 1244.383613793341055;
  grad_ll[3] =    0.000000000000000;
  grad_ll[4] =    0.000000000000000;

  grad_log_prior[0] =  0.000000000000000;
  grad_log_prior[1] =  0.000000000000000;
  grad_log_prior[2] =  0.000000000000000;
  grad_log_prior[3] =  0.231818927404348;
  grad_log_prior[4] = -0.244563348542506;

  FI[0 * ldfi + 0] = 148983.528540931903990;
  FI[0 * ldfi + 1] =  24050.474993759369681;
  FI[0 * ldfi + 2] =  74803.613228124479065;
  FI[0 * ldfi + 3] =      0.000000000000000;
  FI[0 * ldfi + 4] =      0.000000000000000;
  FI[1 * ldfi + 0] =  24050.474993759369681;
  FI[1 * ldfi + 1] =   6633.636208098416319;
  FI[1 * ldfi + 2] =  13966.308071732422832;
  FI[1 * ldfi + 3] =      0.000000000000000;
  FI[1 * ldfi + 4] =      0.000000000000000;
  FI[2 * ldfi + 0] =  74803.613228124479065;
  FI[2 * ldfi + 1] =  13966.308071732422832;
  FI[2 * ldfi + 2] =  45759.830260311442544;
  FI[2 * ldfi + 3] =      0.000000000000000;
  FI[2 * ldfi + 4] =      0.000000000000000;
  FI[3 * ldfi + 0] =      0.000000000000000;
  FI[3 * ldfi + 1] =      0.000000000000000;
  FI[3 * ldfi + 2] =      0.000000000000000;
  FI[3 * ldfi + 3] =      0.000000000000000;
  FI[3 * ldfi + 4] =      0.000000000000000;
  FI[4 * ldfi + 0] =      0.000000000000000;
  FI[4 * ldfi + 1] =      0.000000000000000;
  FI[4 * ldfi + 2] =      0.000000000000000;
  FI[4 * ldfi + 3] =      0.000000000000000;
  FI[4 * ldfi + 4] =      0.000000000000000;

  hessian_log_prior[0] =  0.0;
  hessian_log_prior[1] =  0.0;
  hessian_log_prior[2] =  0.0;
  hessian_log_prior[3] = -0.25;
  hessian_log_prior[4] = -0.25;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, serdata, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.239699929955214, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.222254332657281, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.937879200641208, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -0.926116614980369, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  0.977030577427310, 1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0],  0.000176923663812, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], -0.000091017435797, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], -0.000261437852859, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], -0.000091017435797, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6],  0.001992506198023, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], -0.000459344412173, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], -0.000261437852859, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], -0.000459344412173, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12],  0.000668381953143, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18],  0.010000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24],  0.010000000000000, 1.0e-15);
}

static void test_fitzhugh_ode_proposal_simp_mmala4() {
  // Input arguments
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
  double likelihood = 157.408057797058575;
  double temperature = 0.004115226337449;
  double stepsize = 0.05;
  size_t ldfi = 6u & ~1u;
  double serdata[5 * (3 + ldfi)];
  double * grad_ll = &serdata[0];
  double * grad_log_prior = &grad_ll[5];
  double * FI = &grad_log_prior[5];
  double * hessian_log_prior = &FI[5 * ldfi];

  grad_ll[0] = -107.015194273180327;
  grad_ll[1] = -134.655603755645586;
  grad_ll[2] = -197.383127651640280;
  grad_ll[3] =    0.000000000000000;
  grad_ll[4] =    0.000000000000000;

  grad_log_prior[0] =  0.000000000000000;
  grad_log_prior[1] =  0.000000000000000;
  grad_log_prior[2] =  0.000000000000000;
  grad_log_prior[3] =  0.250000000000000;
  grad_log_prior[4] = -0.250000000000000;

  FI[0 * ldfi + 0] = 120316.531081182896742;
  FI[0 * ldfi + 1] =  14055.733008116238125;
  FI[0 * ldfi + 2] =  65011.411290360978455;
  FI[0 * ldfi + 3] =      0.000000000000000;
  FI[0 * ldfi + 4] =      0.000000000000000;
  FI[1 * ldfi + 0] =  14055.733008116238125;
  FI[1 * ldfi + 1] =   4153.222711413294746;
  FI[1 * ldfi + 2] =   9386.707672327431283;
  FI[1 * ldfi + 3] =      0.000000000000000;
  FI[1 * ldfi + 4] =      0.000000000000000;
  FI[2 * ldfi + 0] =  65011.411290360978455;
  FI[2 * ldfi + 1] =   9386.707672327431283;
  FI[2 * ldfi + 2] =  45343.433623564727895;
  FI[2 * ldfi + 3] =      0.000000000000000;
  FI[2 * ldfi + 4] =      0.000000000000000;
  FI[3 * ldfi + 0] =      0.000000000000000;
  FI[3 * ldfi + 1] =      0.000000000000000;
  FI[3 * ldfi + 2] =      0.000000000000000;
  FI[3 * ldfi + 3] =      0.000000000000000;
  FI[3 * ldfi + 4] =      0.000000000000000;
  FI[4 * ldfi + 0] =      0.000000000000000;
  FI[4 * ldfi + 1] =      0.000000000000000;
  FI[4 * ldfi + 2] =      0.000000000000000;
  FI[4 * ldfi + 3] =      0.000000000000000;
  FI[4 * ldfi + 4] =      0.000000000000000;

  hessian_log_prior[0] =  0.0;
  hessian_log_prior[1] =  0.0;
  hessian_log_prior[2] =  0.0;
  hessian_log_prior[3] = -0.25;
  hessian_log_prior[4] = -0.25;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, serdata, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.200009340556823, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.199944424645276, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.999992671439815, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -0.998750000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  0.998750000000000, 1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0],  0.000022546335166, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], -0.000006095404716, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], -0.000031064107276, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], -0.000006095404716, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6],  0.000276528985865, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], -0.000048505940431, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], -0.000031064107276, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], -0.000048505940431, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12],  0.000067977484089, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18],  0.010000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23],  0.000000000000000, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24],  0.010000000000000, 1.0e-15);
}

static void test_fitzhugh_ode_likelihood_simp_mmala0() {
  // Input argument
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };

  // Output arguments
  double likelihood;
  size_t ldfi = 6u & ~1u, size;
  double * serdata;

  // Call test function
  int error = gmcmc_likelihood(data, model, params, &likelihood, (void **)&serdata, &size);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(likelihood, 157.408057797058575, 1.0e-06);

  // Check serialised data
  CU_ASSERT(size == 5 * (3 + ldfi) * sizeof(double));
  CU_ASSERT_FATAL(serdata != NULL);

  // Unpack simdata
  double * grad_ll = &serdata[0];
  double * grad_log_prior = &grad_ll[5];
  double * FI = &grad_log_prior[5];
  double * hessian_log_prior = &FI[5 * ldfi];

  CU_ASSERT_DOUBLE_EQUAL(grad_ll[0], -107.015194273180327, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_ll[1], -134.655603755645586, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_ll[2], -197.383127651640280, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_ll[3],    0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_ll[4],    0.000000000000000, 1.0e-03);

  CU_ASSERT_DOUBLE_EQUAL(grad_log_prior[0],  0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_log_prior[1],  0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_log_prior[2],  0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_log_prior[3],  0.250000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(grad_log_prior[4], -0.250000000000000, 1.0e-03);

  CU_ASSERT_DOUBLE_EQUAL(FI[0 * ldfi + 0], 120316.531081182896742, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[0 * ldfi + 1],  14055.733008116238125, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[0 * ldfi + 2],  65011.411290360978455, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[0 * ldfi + 3],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[0 * ldfi + 4],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[1 * ldfi + 0],  14055.733008116238125, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[1 * ldfi + 1],   4153.222711413294746, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[1 * ldfi + 2],   9386.707672327431283, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[1 * ldfi + 3],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[1 * ldfi + 4],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[2 * ldfi + 0],  65011.411290360978455, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[2 * ldfi + 1],   9386.707672327431283, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[2 * ldfi + 2],  45343.433623564727895, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[2 * ldfi + 3],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[2 * ldfi + 4],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[3 * ldfi + 0],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[3 * ldfi + 1],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[3 * ldfi + 2],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[3 * ldfi + 3],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[3 * ldfi + 4],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[4 * ldfi + 0],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[4 * ldfi + 1],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[4 * ldfi + 2],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[4 * ldfi + 3],      0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(FI[4 * ldfi + 4],      0.000000000000000, 1.0e-03);

  CU_ASSERT_DOUBLE_EQUAL(hessian_log_prior[0],  0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(hessian_log_prior[1],  0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(hessian_log_prior[2],  0.000000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(hessian_log_prior[3], -0.250000000000000, 1.0e-03);
  CU_ASSERT_DOUBLE_EQUAL(hessian_log_prior[4], -0.250000000000000, 1.0e-03);

  free(serdata);
}

// #include "test_fitzhugh_simp_mmala.c"

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

//   CU_pSuite fitzhugh_mh = CU_add_suite("Fitz Hugh Nagumo MH", init_fitzhugh_mh, cleanup);
//   if (CU_get_error() != CUE_SUCCESS)
//     CUNIT_ERROR("Failed to add suite to registry");
//
//   CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh0);
//   if (CU_get_error() != CUE_SUCCESS)
//     CUNIT_ERROR("Failed to add test to suite");
//
//   CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh1);
//   if (CU_get_error() != CUE_SUCCESS)
//     CUNIT_ERROR("Failed to add test to suite");
//
//   CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh2);
//   if (CU_get_error() != CUE_SUCCESS)
//     CUNIT_ERROR("Failed to add test to suite");
//
//   CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh3);
//   if (CU_get_error() != CUE_SUCCESS)
//     CUNIT_ERROR("Failed to add test to suite");
//
//   CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh4);
//   if (CU_get_error() != CUE_SUCCESS)
//     CUNIT_ERROR("Failed to add test to suite");
//
//   CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_likelihood0);
//   if (CU_get_error() != CUE_SUCCESS)
//     CUNIT_ERROR("Failed to add test to suite");

// #include "test_fitzhugh_mh_main.c"

  CU_pSuite fitzhugh_simp_mmala = CU_add_suite("Fitz Hugh Nagumo Simplified mMALA", init_fitzhugh_simp_mmala, cleanup);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add suite to registry");

  CU_ADD_TEST(fitzhugh_simp_mmala, test_fitzhugh_ode_proposal_simp_mmala0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_simp_mmala, test_fitzhugh_ode_proposal_simp_mmala1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_simp_mmala, test_fitzhugh_ode_proposal_simp_mmala2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_simp_mmala, test_fitzhugh_ode_proposal_simp_mmala3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_simp_mmala, test_fitzhugh_ode_proposal_simp_mmala4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_simp_mmala, test_fitzhugh_ode_likelihood_simp_mmala0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

// #include "test_fitzhugh_simp_mmala_main.c"

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
