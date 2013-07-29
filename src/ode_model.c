#include <gmcmc/gmcmc_ode_model.h>
#include <gmcmc/gmcmc_errno.h>
#include <string.h>
#include <cblas.h>
#include "mvn.c"

/**
 * Computes the sum of x.
 *
 * @param [in]     n  the length of x
 * @param [in,out] x  a vector to sum
 *
 * @return the sum.
 */
static inline double sum(size_t n, const double * x) {
  // No sum
  if (n == 0)
    return 0.0;

  // Do normal sum
  double sum = 0.0;
  for (size_t i = 0; i < n; i++)
    sum += x[i];

  return sum;
}

/**
 * ODE model-specific data.
 *
 * In addition to data common to all models, ODE models have a number of
 * observed and unobserved species and a function to solve a system of ODEs.
 */
struct gmcmc_ode_model {
  unsigned int observed, unobserved;    /**< Number of observed and unobserved*/
                                        /*   species                          */
  int (*solve)(size_t, size_t,          /**< Function to solve system of ODEs */
               const double *,          /*   using solver of choice           */
               const double *,
               double *, size_t);
};

/**
 * ODE model proposal function using Metropolis-Hastings.
 */
static int ode_proposal_mh(size_t n, const double * params, double likelihood,
                           double temperature, double stepsize, const void * serdata,
                           double * mean, double * covariance, size_t ldc) {
  (void)likelihood;
  (void)serdata;
  (void)temperature;

  // Proposal_Mean    = Chain.Paras(Chain.CurrentBlock);
  memcpy(mean, params, n * sizeof(double));

  // Proposal_Covariance = eye(Chain.CurrentBlockSize)*(Chain.StepSize(Chain.CurrentBlockNum)^2);
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      covariance[j * ldc + i] = 0.0;
    covariance[j * ldc + j] = stepsize * stepsize;
    for (size_t i = j + 1; i < n; i++)
      covariance[j * ldc + i] = 0.0;
  }

  return 0;
}
const gmcmc_proposal_function gmcmc_ode_proposal_mh = &ode_proposal_mh;

/**
 * ODE model likelihood function using Metropolis-Hastings.
 */
static int ode_likelihood_mh(const gmcmc_dataset * dataset, const gmcmc_model * model,
                             const double * params,
                             double * likelihood, void ** serdata, size_t * size) {
  (void)serdata;
  (void)size;

  // Get a pointer to the ODE model-specific data
  const gmcmc_ode_model * ode_model = (gmcmc_ode_model *)gmcmc_model_get_modelspecific(model);
  const unsigned int num_species = ode_model->observed + ode_model->unobserved;

  // Get the timepoints
  const size_t num_timepoints = gmcmc_dataset_get_num_timepoints(dataset);
  const double * timepoints = gmcmc_dataset_get_timepoints(dataset);

  // Allocate simulated data
  double * simdata;
  size_t lds = (num_timepoints + 1u) & ~1u;
  if ((simdata = malloc(lds * num_species * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate simulated data", GMCMC_ENOMEM);

  // Solve the system of equations using the function specified in the ODE model
  int error;
  if ((error = ode_model->solve(num_timepoints, num_species, timepoints, params,
                                simdata, lds)) != 0) {
    free(simdata);
    GMCMC_ERROR("Failed to solve system of ODEs", error);
  }

  // Allocate the log likelihood
  double * ll;
  if ((ll = malloc(ode_model->observed * sizeof(double))) == NULL) {
    free(simdata);
    GMCMC_ERROR("Failed to allocate log likelihood", GMCMC_ENOMEM);
  }

  // Create the covariance matrix based on the noise covariance
  const double * noisecov = (const double *)gmcmc_dataset_get_auxdata(dataset);
  double * covariance;
  size_t ldc = (num_timepoints + 1u) & ~1u;
  if ((covariance = calloc(num_timepoints, ldc * sizeof(double))) == NULL) {
    free(ll);
    free(simdata);
    GMCMC_ERROR("Failed to allocate covariance", GMCMC_ENOMEM);
  }

  for (size_t i = 0; i < ode_model->observed; i++) {
    for (size_t j = 0; j < num_timepoints; j++)
      covariance[j * ldc + j] = noisecov[i];

    // Calculate an element of the log likelihood
    if ((error = gmcmc_mvn_logpdf(num_timepoints, &simdata[i * lds], gmcmc_dataset_get_data(dataset, i), covariance, ldc, &ll[i])) != 0) {
      free(covariance);
      free(ll);
      free(simdata);
      GMCMC_ERROR("Failed to calculate log normal PDF", GMCMC_ENOMEM);
    }
  }

  free(covariance);
  free(simdata);

  *likelihood = sum(ode_model->observed, ll);

  free(ll);

  return 0;
}
const gmcmc_likelihood_function gmcmc_ode_likelihood_mh = &ode_likelihood_mh;

/**
 * ODE model proposal function using Simplified M-MALA.
 */
static int ode_proposal_simp_mmala(size_t n, const double * params,
                                   double likelihood, double temperature,
                                   double stepsize, const void * serdata,
                                   double * mean, double * covariance, size_t ldc) {
  (void)likelihood;     // Unused

  // Unpack the serialised data
  size_t ldfi = (n + 1u) & ~1u;
  const double * gradient_ll = (const double *)serdata;
  const double * gradient_log_prior = &gradient_ll[n];
  const double * FI = &gradient_log_prior[n];
  const double * hessian_log_prior = &FI[ldfi * n];

  // Calculate posterior gradient and metric tensor
  size_t ldg = (n + 1u) & ~1u;
  double * gradient = NULL, * G = NULL;
  if ((gradient = malloc(n * sizeof(double))) == NULL ||
      (G = malloc(n * ldg * sizeof(double))) == NULL) {
    free(gradient);
    free(G);
    GMCMC_ERROR("Failed to allocate posterior gradients", GMCMC_ENOMEM);
  }
  // Posterior_Grad   = Chain.GradLL*Chain.Temp + Chain.GradLogPrior;
  for (size_t i = 0; i < n; i++)
    gradient[i] = gradient_ll[i] * temperature + gradient_log_prior[i];
  // Posterior_G      = Chain.FI*Chain.Temp - diag(Chain.HessianLogPrior);
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < n; i++)
      G[j * ldg + i] = FI[j * ldfi + i] * temperature;
    G[j * ldg + j] -= hessian_log_prior[j];
  }


  // Calculate cholesky
  long info = clapack_dpotrf(CblasLower, n, G, ldg);
  if (info != 0) {
    free(gradient);
    free(G);
    GMCMC_ERROR("Posterior gradient is not positive definite", GMCMC_ELINAL);
  }

  // NaturalGradient  = (CholG\(CholG'\Posterior_Grad'))';
  cblas_dtrsv(CblasColMajor, CblasLower, CblasNoTrans, CblasNonUnit, n, G, ldg, gradient, 1);
  cblas_dtrsv(CblasColMajor, CblasLower, CblasTrans, CblasNonUnit, n, G, ldg, gradient, 1);

  // Proposal_Mean    = CurrentParas + (StepSize^2/2)*NaturalGradient;
  for (size_t i = 0; i < n; i++)
    mean[i] = params[i] + ((stepsize * stepsize) / 2.0) * gradient[i];

  // Proposal_Covariance = CholG\(CholG'\( diag(ones(1, NumOfParas)*(StepSize^2)) )); % Stepsize is squared in the covariance term
  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < j; i++)
      covariance[j * ldc + i] = 0.0;
    covariance[j * ldc + j] = stepsize * stepsize;
    for (size_t i = j + 1; i < n; i++)
      covariance[j * ldc + i] = 0.0;
  }
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasNonUnit, n, n, 1.0, G, ldg, covariance, ldc);
  cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasTrans, CblasNonUnit, n, n, 1.0, G, ldg, covariance, ldc);

  free(gradient);
  free(G);

  return 0;
}
const gmcmc_proposal_function gmcmc_ode_proposal_simp_mmala = &ode_proposal_simp_mmala;

/**
 * ODE model likelihood function using Simplified M-MALA.
 */
static int ode_likelihood_simp_mmala(const gmcmc_dataset * data, const gmcmc_model * model,
                                     const double * params,
                                     double * likelihood, void ** serdata, size_t * size) {
  // TODO: Simplified M-MALA ODE likelihood function
  (void)data;
  (void)model;
  (void)params;
  (void)likelihood;
  (void)serdata;
  (void)size;
  return 0;
}
const gmcmc_likelihood_function gmcmc_ode_likelihood_simp_mmala = &ode_likelihood_simp_mmala;

/**
 * Creates an ODE model-specific data object.
 *
 * @param [out] ode_model   the ODE model
 * @param [in]  observed    the number of observed species in the model
 * @param [in]  unobserved  the number of unobserved species in the model
 * @param [in]  solve       function to solve system of ODEs
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if solve is NULL,
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_ode_model_create(gmcmc_ode_model ** ode_model, unsigned int observed,
                           unsigned int unobserved,
                           int (*solve)(size_t, size_t, const double *, const double *,
                                   double *, size_t)) {
  if (solve == NULL)
    GMCMC_ERROR("solve is NULL", GMCMC_EINVAL);

  if ((*ode_model = malloc(sizeof(gmcmc_ode_model))) == NULL)
    GMCMC_ERROR("Unable to allocate ODE model", GMCMC_ENOMEM);

  (*ode_model)->observed = observed;
  (*ode_model)->unobserved = unobserved;
  (*ode_model)->solve = solve;

  return 0;
}

/**
 * Destroys the ODE model-specific data.
 *
 * @param [in] ode_model  the ODE model-specific data object to destroy
 */
void gmcmc_ode_model_destroy(gmcmc_ode_model * ode_model) {
  free(ode_model);
}
