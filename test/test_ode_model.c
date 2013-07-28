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

static int cvodes_rhs(realtype t, N_Vector y, N_Vector ydot, void * userdata) {
  (void)t;      // Unused

  // Parameters are stored in userdata
  double * params = (double *)userdata;
  double a = params[0];
  double b = params[1];
  double c = params[2];

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

static int cvodes_solve(size_t n, const double * timepoints, const double * params, double * simdata, size_t lds) {
  size_t num_species = 2;

  // Create CVODES solver
  void * cvode_mem;
  if ((cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON)) == NULL)
    GMCMC_ERROR("Failed to create CVODES solver", GMCMC_ELINAL);

  // Initialise CVODES solver
  int error;
  realtype ics[] = { params[3], params[4] };
  N_Vector ics_v = N_VMake_Serial(num_species, ics);   // Initial conditions are being inferred as part of parameter vector
  if ((error = CVodeInit(cvode_mem, cvodes_rhs, timepoints[0],
                         ics_v)) != CV_SUCCESS) {
    N_VDestroy(ics_v);
    GMCMC_ERROR("Failed to initialise ODE solver", GMCMC_ELINAL);
  }
  N_VDestroy(ics_v);

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
  for (size_t i = 1; i < n; i++) {
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

static int init_fitzhugh_mh() {
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
  if ((error = gmcmc_model_create(&model, 5, priors, gmcmc_ode_proposal_mh, gmcmc_ode_likelihood_mh)) != 0) {
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
  if ((error = gmcmc_ode_model_create(&ode_model, 2, 0, cvodes_solve)) != 0) {
    gmcmc_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create ODE specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ode_model);

  return 0;
}

static void test_fitzhugh_ode_proposal_mh0() {
  // Input arguments
  double params[] = {  3.753693316308367,  7.297489480593286,  3.928901293928624, -1.258434479129602, -1.718597617518663 };
  double likelihood = -1.991015638869035e+04;
  double temperature = 0.0;
  double stepsize = 0.05;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  3.753693316308367,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  7.297489480593286,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  3.928901293928624,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -1.258434479129602,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4], -1.718597617518663,  1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.0025, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.0025, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.0025, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.0025, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.0025, 1.0e-04);
}

static void test_fitzhugh_ode_proposal_mh1() {
  // Input arguments
  double params[] = {  5.122218788773759,  4.456300578316980,  2.934938906668503, -1.162318611802445,  1.396294514134621 };
  double likelihood = -1.992633892183833e+04;
  double temperature = 0.000016935087808;
  double stepsize = 0.3;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  5.122218788773759,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  4.456300578316980,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.934938906668503,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -1.162318611802445,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  1.396294514134621,  1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.09, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.09, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.09, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.09, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.09, 1.0e-02);
}

static void test_fitzhugh_ode_proposal_mh2() {
  // Input arguments
  double params[] = {  1.043730032450508,  1.280250502067740,  1.731417327150401, -3.054030331401278,  1.997807620521317 };
  double likelihood = -1.410644132062635e+04;
  double temperature = 0.000541922809870;
  double stepsize = 0.6;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  1.043730032450508,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  1.280250502067740,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  1.731417327150401,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -3.054030331401278,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  1.997807620521317,  1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.36, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.36, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.36, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.36, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.36, 1.0e-02);
}

static void test_fitzhugh_ode_proposal_mh3() {
  // Input arguments
  double params[] = {  0.303720949185782,  0.597592276776456,  2.277062323473790, -1.087102685374022,  0.933785343930140 };
  double likelihood = -6.850384887005405e+02;
  double temperature = 0.004115226337449;
  double stepsize = 0.72;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.303720949185782, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.597592276776456, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.277062323473790, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -1.087102685374022, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  0.933785343930140, 1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.5184, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.5184, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.5184, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.5184, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.5184, 1.0e-04);
}

static void test_fitzhugh_ode_proposal_mh4() {
  // Input arguments
  double params[] = {  0.099854854380603,  0.176022301639854,  3.063477503584402, -1.176786820361752,  1.301899062446680 };
  double likelihood = -66.402349092391390;
  double temperature = 0.017341529915833;
  double stepsize = 0.32;

  // Output arguments
  double mean[5], covariance[5 * 5];
  size_t ldc = 5;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.099854854380603, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  0.176022301639854, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  3.063477503584402, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -1.176786820361752, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[4],  1.301899062446680, 1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.1024, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.1024, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.1024, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[16], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[17], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[18], 0.1024, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[19], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[20], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[21], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[22], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[23], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[24], 0.1024, 1.0e-04);
}

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
  CU_ASSERT_DOUBLE_EQUAL(likelihood, 1.574079522133029e+02, 1.0e-03);
}

#include "test_fitzhugh_mh.c"
#if 0
static int init_fitzhugh_simp_mmala() {
  int error;

  // Load the dataset
  if ((error = gmcmc_dataset_create_matlab(&data, "../data/FitzHugh_Benchmark_Data.mat")) != 0)
    GMCMC_ERROR("Failed to create Fitz Hugh Nagumo dataset", error);

  // Create the priors for each of the parameters
  gmcmc_distribution ** priors;
  if ((priors = malloc(5 * sizeof(gmcmc_distribution *))) == NULL) {
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to allocate priors", GMCMC_ENOMEM);
  }

  for (int i = 0; i < 5; i++) {
    if ((error = gmcmc_distribution_create_uniform(&priors[i], 0.0, 10.0)) != 0) {
      for (int j = 0; j < i; j++)
        gmcmc_distribution_destroy(priors[j]);
      free(priors);
      gmcmc_dataset_destroy(data);
      GMCMC_ERROR("Failed to create prior", error);
    }
  }

  // Create the model
  if ((error = gmcmc_model_create(&model, 5, priors, gmcmc_ode_proposal_simp_mmala, gmcmc_ode_likelihood_simp_mmala)) != 0) {
    for (int j = 0; j < 4; j++)
      gmcmc_distribution_destroy(priors[j]);
    free(priors);
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to create Fitz Hugh Nagumo model", error);
  }

  // Don't need priors any more
  for (int j = 0; j < 4; j++)
    gmcmc_distribution_destroy(priors[j]);
  free(priors);

  // Set initial parameter values
  double params[] = { 0.2, 0.2, 3.0, -1.0, 1.0 };
  if ((error = gmcmc_model_set_params(model, params)) != 0) {
    gmcmc_model_destroy(model);
    gmcmc_dataset_destroy(data);
    GMCMC_ERROR("Failed to set initial parameters", error);
  }

  // Set initial step size
  gmcmc_model_set_stepsize(model, 0.05);

  // Create ODE model specific stuff
  gmcmc_ode_model * ode_model;
  if ((error = gmcmc_ode_model_create(&ode_model, 2, 1, fitzhugh_mh)) != 0) {
    gmcmc_dataset_destroy(data);
    gmcmc_model_destroy(model);
    GMCMC_ERROR("Unable to create ODE specific model", error);
  }

  gmcmc_model_set_modelspecific(model, ode_model);

  return 0;
}

static void test_fitzhugh_ode_proposal_simp_mmala0() {
  // Input arguments
  double params[] = {  0.725404224946106, -0.0630548731896562,  0.714742903826096, -0.204966058299775 };
  double likelihood = 2.134142999129227e+02;
  double temperature = 0.0;
  double stepsize = 1.0;

  // Output arguments
  double mean[4], covariance[4 * 4];
  size_t ldc = 4;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  0.725404224946106,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[1], -0.0630548731896562, 1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  0.714742903826096,  1.0e-15);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -0.204966058299775,  1.0e-15);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 1.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 1.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 1.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 1.0, 1.0e-02);
}

static void test_fitzhugh_ode_proposal_simp_mmala1() {
  // Input arguments
  double params[] = { 3.4665789e+00, 2.1221985e-01, -1.3872798e+00, -7.0527936e-01 };
  double likelihood = -8.9007692e+02;
  double temperature = 1.693508780843028e-05;
  double stepsize = 0.8;

  // Output arguments
  double mean[4], covariance[4 * 4];
  size_t ldc = 4;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  3.4665789e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[1],  2.1221985e-01, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[2], -1.3872798e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], -7.0527936e-01, 1.0e-07);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.64, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.64, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.64, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.64, 1.0e-02);
}

static void test_fitzhugh_ode_proposal_simp_mmala2() {
  // Input arguments
  double params[] = { 2.6762215e+00, -8.0350436e-01, 7.5516193e-01, 3.6432629e+00 };
  double likelihood = 9.9686730e+02;
  double temperature = 0.000541922809870;
  double stepsize = 1.2;

  // Output arguments
  double mean[4], covariance[4 * 4];
  size_t ldc = 4;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0],  2.6762215e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[1], -8.0350436e-01, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  7.5516193e-01, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[3],  3.6432629e+00, 1.0e-07);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 1.44, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 1.44, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 1.44, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.00, 1.0e-02);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 1.44, 1.0e-02);
}

static void test_fitzhugh_ode_proposal_simp_mmala3() {
  // Input arguments
  double params[] = { -9.1429320e-01, -1.4124436e+00,  2.3061665e+00,  2.3206083e+00 };
  double likelihood = 1.8617143e+03;
  double temperature = 0.004115226337449;
  double stepsize = 0.512;

  // Output arguments
  double mean[4], covariance[4 * 4];
  size_t ldc = 4;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0], -9.1429320e-01, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[1], -1.4124436e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[2],  2.3061665e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[3],  2.3206083e+00, 1.0e-07);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 0.262144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 0.262144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 0.262144, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.000000, 1.0e-06);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 0.262144, 1.0e-06);
}

static void test_fitzhugh_ode_proposal_simp_mmala4() {
  // Input arguments
  double params[] = { 1.2474997e+00, 2.3760790e+00, 2.9115780e+00, 3.2896986e+00 };
  double likelihood = 2.0286676e+03;
  double temperature = 0.017341529915833;
  double stepsize = 1.44;

  // Output arguments
  double mean[4], covariance[4 * 4];
  size_t ldc = 4;

  // Call test function
  int error = gmcmc_proposal(model, params, likelihood, temperature, stepsize, NULL, mean, covariance, ldc);

  // Check return value
  CU_ASSERT(error == 0);

  // Check mean
  CU_ASSERT_DOUBLE_EQUAL(mean[0], 1.2474997e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[1], 2.3760790e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[2], 2.9115780e+00, 1.0e-07);
  CU_ASSERT_DOUBLE_EQUAL(mean[3], 3.2896986e+00, 1.0e-07);

  // Check covariance
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 0], 2.0736, 1.0e-04)
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 1], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 2], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 3], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 4], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 5], 2.0736, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 6], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 7], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 8], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[ 9], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[10], 2.0736, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[11], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[12], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[13], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[14], 0.0000, 1.0e-04);
  CU_ASSERT_DOUBLE_EQUAL(covariance[15], 2.0736, 1.0e-04);
}

static void test_fitzhugh_ode_likelihood_simp_mmala0() {
  // Input argument
  double params[] = {  0.725404224946106, -0.0630548731896562,  0.714742903826096, -0.204966058299775 };

  // Output argument
  double likelihood;

  // Call test function
  int error = gmcmc_likelihood(data, model, params, &likelihood, NULL, NULL);

  // Check return value
  CU_ASSERT(error == 0);

  // Check log likelihood
  CU_ASSERT_DOUBLE_EQUAL(likelihood, 2.134142999129227e+02, 1.0e-03);
}

#include "test_fitzhugh_simp_mmala.c"
#endif

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

  CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh1);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh2);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh3);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_proposal_mh4);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

  CU_ADD_TEST(fitzhugh_mh, test_fitzhugh_ode_likelihood_mh0);
  if (CU_get_error() != CUE_SUCCESS)
    CUNIT_ERROR("Failed to add test to suite");

#include "test_fitzhugh_mh_main.c"
#if 0
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

#include "test_fitzhugh_simp_mmala_main.c"
#endif

  error = CU_basic_run_tests();
  if (error != CUE_SUCCESS)
    CUNIT_ERROR("Failed to run tests");

  CU_cleanup_registry();

  return 0;
}
