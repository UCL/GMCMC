#include <gmcmc/gmcmc_ode_model.h>
#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>
#include <string.h>
#include <cblas.h>
#include <math.h>

#include <cvodes/cvodes.h>
#include <cvodes/cvodes_dense.h>
#include <nvector/nvector_serial.h>

#include "clapack.h"
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

#include "cvodes.c"

/**
 * ODE model-specific data.
 *
 * In addition to data common to all models, ODE models have a number of
 * observed and unobserved species and a function to evaluate the right-hand
 * side of a system of ODEs.
 */
struct gmcmc_ode_model {
  /**
   * Number of observed and unobserved species.
   */
  unsigned int observed, unobserved;

  /**
   * Function to evaluate the right-hand side of a system of ODEs.
   */
  gmcmc_ode_rhs rhs;

  /**
   * Fixed initial conditions for the system of ODEs.  Will be NULL if the
   * initial conditions are being inferred as part of the parameter vector in
   * the model.
   */
  double * ics;

  /**
   * ODE integrator options.
   */
  cvodes_options options;
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

  const size_t num_params = gmcmc_model_get_num_params(model);

  // Get a pointer to the ODE model-specific data
  const gmcmc_ode_model * ode_model = (gmcmc_ode_model *)gmcmc_model_get_modelspecific(model);
  const unsigned int num_species = ode_model->observed + ode_model->unobserved;

  // Get the timepoints
  const size_t num_timepoints = gmcmc_dataset_get_num_timepoints(dataset);
  const double * timepoints = gmcmc_dataset_get_timepoints(dataset);

  // Get initial conditions
  const double * ics = (ode_model->ics != NULL) ? ode_model->ics : &params[num_params - num_species];

  // Allocate simulated data
  double * simdata;
  size_t lds = (num_timepoints + 1u) & ~1u;
  if ((simdata = malloc(lds * num_species * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate simulated data", GMCMC_ENOMEM);

  // Solve the system of equations using the function specified in the ODE model
  int error;
  if ((error = cvodes_solve(ode_model->rhs,
                            num_timepoints, num_species, num_params,
                            timepoints, ics, params, &ode_model->options,
                            simdata, NULL, lds)) != 0) {
    free(simdata);
    GMCMC_ERROR("Failed to solve system of ODEs", error);
  }

  // Allocate the log likelihood
  double * ll;
  if ((ll = malloc(ode_model->observed * sizeof(double))) == NULL) {
    free(simdata);
    GMCMC_ERROR("Failed to allocate log likelihood", GMCMC_ENOMEM);
  }

  // The covariance matrix for observed species j is diagonal with noisecov[j]
  // repeated along the diagonal
  const double * noisecov = (const double *)gmcmc_dataset_get_auxdata(dataset);
  for (size_t j = 0; j < ode_model->observed; j++) {
    // Subtract the real data from the simulated data so that it has zero mean
    const double * data = gmcmc_dataset_get_data(dataset, j);
    for (size_t i = 0; i < num_timepoints; i++)
      simdata[j * lds + i] -= data[i];

    // Calculate an element of the log likelihood using the optimised PDF
    if ((error = gmcmc_mvn_logpdf0(num_timepoints, &simdata[j * lds], noisecov[j], &ll[j])) != 0) {
      free(ll);
      free(simdata);
      GMCMC_ERROR("Failed to calculate log normal PDF", GMCMC_ENOMEM);
    }
  }

  *likelihood = sum(ode_model->observed, ll);

  free(simdata);
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
  const double * gradient_ll = serdata;
  const double * gradient_log_prior = &gradient_ll[ldfi];
  const double * FI = &gradient_log_prior[ldfi];
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
static int ode_likelihood_simp_mmala(const gmcmc_dataset * dataset, const gmcmc_model * model,
                                     const double * params,
                                     double * likelihood, void ** serdata, size_t * size) {
  const size_t num_params = gmcmc_model_get_num_params(model);

  // Get a pointer to the ODE model-specific data
  const gmcmc_ode_model * ode_model = (gmcmc_ode_model *)gmcmc_model_get_modelspecific(model);
  const unsigned int num_species = ode_model->observed + ode_model->unobserved;

  // Get the timepoints
  const size_t num_timepoints = gmcmc_dataset_get_num_timepoints(dataset);
  const double * timepoints = gmcmc_dataset_get_timepoints(dataset);

  // Get initial conditions
  const double * ics = (ode_model->ics != NULL) ? ode_model->ics : &params[num_params - num_species];

  // Allocate simulated data
  double * simdata;
  size_t lds = (num_timepoints + 1u) & ~1u;
  if ((simdata = malloc(lds * num_species * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate simulated data", GMCMC_ENOMEM);

  // Allocate sensitivities
  double * sensitivities;
  if ((sensitivities = malloc(lds * num_species * num_params * sizeof(double))) == NULL) {
    free(simdata);
    GMCMC_ERROR("Failed to allocate sensitivities", GMCMC_ENOMEM);
  }

  // Solve the system of equations using the function specified in the ODE model
  int error;
  if ((error = cvodes_solve(ode_model->rhs,
                            num_timepoints, num_species, num_params,
                            timepoints, ics, params, &ode_model->options,
                            simdata, sensitivities, lds)) != 0) {
    free(simdata);
    free(sensitivities);
    GMCMC_ERROR("Failed to solve system of ODEs", error);
  }

  // Allocate the log likelihood
  double * ll;
  if ((ll = malloc(ode_model->observed * sizeof(double))) == NULL) {
    free(simdata);
    free(sensitivities);
    GMCMC_ERROR("Failed to allocate log likelihood", GMCMC_ENOMEM);
  }

  // The covariance matrix for observed species j is diagonal with noisecov[j]
  // repeated along the diagonal
  const double * noisecov = (const double *)gmcmc_dataset_get_auxdata(dataset);
  for (size_t j = 0; j < ode_model->observed; j++) {
    // Subtract the real data from the simulated data so that it has zero mean
    const double * data = gmcmc_dataset_get_data(dataset, j);
    for (size_t i = 0; i < num_timepoints; i++)
      simdata[j * lds + i] -= data[i];

    // Calculate an element of the log likelihood using the optimised PDF
    if ((error = gmcmc_mvn_logpdf0(num_timepoints, &simdata[j * lds], noisecov[j], &ll[j])) != 0) {
      free(ll);
      free(simdata);
      free(sensitivities);
      GMCMC_ERROR("Failed to calculate log normal PDF", GMCMC_ENOMEM);
    }
  }

  *likelihood = sum(ode_model->observed, ll);

  free(ll);

  // Calculate the gradient of the log-likelihood
  size_t ldfi = (num_params + 1u) & ~1u;
  *size = (num_params + 3) * ldfi;
  if ((*serdata = calloc(*size, sizeof(double))) == NULL) {
    free(simdata);
    free(sensitivities);
    GMCMC_ERROR("Failed to allocate gradient structure", GMCMC_ENOMEM);
  }
  *size *= sizeof(double);

  // Unpack serialised data structure
  double * gradient_ll = *serdata;            // Length num_params
  double * gradient_log_prior = &gradient_ll[ldfi];     // Length num_params (start on aligned offset)
  double * FI = &gradient_log_prior[ldfi];              // Length num_params * ldfi
  double * hessian_log_prior = &FI[num_params * ldfi];

  // Calculate gradients for each of the parameters i.e. d(LL)/d(Parameter)
  for (size_t j = 0; j < num_params; j++) {
    const double * sens_j = &sensitivities[j * num_species * lds];      // Sensitivities of parameter j

    // Calculate the gradient of the log-likelihood
    for (size_t i = 0; i < ode_model->observed; i++)
      gradient_ll[j] -= cblas_ddot(num_timepoints, &simdata[i * lds], 1, &sens_j[i * lds], 1) / noisecov[i];

    // TODO: Add log transformation if necessary


    // Calculate gradient of the log prior
    const gmcmc_distribution * prior = gmcmc_model_get_prior(model, j);
    gradient_log_prior[j] = gmcmc_distribution_pdf_1st_order(prior, params[j]);

    // Calculate the Hessian of the log prior
    hessian_log_prior[j] = gmcmc_distribution_pdf_2nd_order(prior, params[j]);

    // Calculate metric tensor
    for (size_t i = j; i < num_params; i++) {
      const double * sens_i = &sensitivities[i * num_species * lds];    // Sensitivities of parameter i
      for (size_t k = 0; k < ode_model->observed; k++)
        FI[j * ldfi + i] += cblas_ddot(num_timepoints, &sens_i[k * lds], 1, &sens_j[k * lds], 1) / noisecov[k];

      // TODO: Add log transformation if necessary

      FI[i * ldfi + j] = FI[j * ldfi + i];
    }
  }

  free(simdata);
  free(sensitivities);

  return 0;
}
const gmcmc_likelihood_function gmcmc_ode_likelihood_simp_mmala = &ode_likelihood_simp_mmala;

/**
 * Creates an ODE model-specific data object.
 *
 * @param [out] ode_model   the ODE model
 * @param [in]  observed    the number of observed species in the model
 * @param [in]  unobserved  the number of unobserved species in the model
 * @param [in]  rhs         function to evaluate the right-hand side of a system
 *                            of ODEs
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if rhs is NULL,
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_ode_model_create(gmcmc_ode_model ** ode_model, unsigned int observed,
                           unsigned int unobserved, gmcmc_ode_rhs rhs) {
  if (rhs == NULL)
    GMCMC_ERROR("rhs is NULL", GMCMC_EINVAL);

  if ((*ode_model = malloc(sizeof(gmcmc_ode_model))) == NULL)
    GMCMC_ERROR("Unable to allocate ODE model", GMCMC_ENOMEM);

  (*ode_model)->observed = observed;
  (*ode_model)->unobserved = unobserved;
  (*ode_model)->rhs = rhs;
  (*ode_model)->ics = NULL;
  (*ode_model)->options.abstol = 1.0e-06;
  (*ode_model)->options.reltol = 1.0e-06;

  return 0;
}

/**
 * Destroys the ODE model-specific data.
 *
 * @param [in] ode_model  the ODE model-specific data object to destroy
 */
void gmcmc_ode_model_destroy(gmcmc_ode_model * ode_model) {
  if (ode_model != NULL)
    free(ode_model->ics);
  free(ode_model);
}

/**
 * Gets a pointer to the initial conditions of the system of ODEs.  If the
 * initial conditions are to be inferred then they will be stored in the end of
 * the parameter vector in the model and this function will return NULL.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return a pointer to the initial conditions, or NULL if they are being
 *           inferred as part of the model.
 */
const double * gmcmc_ode_model_get_initial_conditions(const gmcmc_ode_model * ode_model) {
  return ode_model->ics;
}

/**
 * Sets the initial conditions for the system of ODEs.  If the initial
 * conditions are to be inferred then set them to NULL here and append the
 * initial conditions to the end of the parameter vector in the model along with
 * associated prior distributions for each one.
 *
 * @param [in] ode_model  the ODE model
 * @param [in] ics        the initial conditions (may be NULL)
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if ics is not NULL and the initial conditions could not
 *                        be copied into the model.
 */
int gmcmc_ode_model_set_initial_conditions(gmcmc_ode_model * ode_model, const double * ics) {
  if (ics == NULL) {
    free(ode_model->ics);
    ode_model->ics = NULL;
  }
  else {
    double * new_ics = malloc((ode_model->observed + ode_model->unobserved) * sizeof(double));
    if (new_ics == NULL)
      GMCMC_ERROR("Failed to allocate new initial conditions", GMCMC_ENOMEM);
    memcpy(new_ics, ics, (ode_model->observed + ode_model->unobserved) * sizeof(double));
    free(ode_model->ics);
    ode_model->ics = new_ics;
  }
  return 0;
}

/**
 * Gets the integration tolerances used by the ODE solver.
 *
 * @param [in]  ode_model  the ODE model
 * @param [out] abstol     the absolute tolerance
 * @param [out] reltol     the relative tolerance
 */
void gmcmc_ode_model_get_tolerances(const gmcmc_ode_model * ode_model,
                                    double * abstol, double * reltol) {
  *abstol = ode_model->options.abstol;
  *reltol = ode_model->options.reltol;
}

/**
 * Sets the integration tolerances used by the ODE solver.
 *
 * @param [in] ode_model  the ODE model
 * @param [in] abstol     the absolute tolerance
 * @param [in] reltol     the relative tolerance
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if either tolerance is less than or equal to zero.
 */
int gmcmc_ode_model_set_tolerances(gmcmc_ode_model * ode_model,
                                   double abstol, double reltol) {
  if (islessequal(abstol, 0.0) || islessequal(reltol, 0.0))
    GMCMC_ERROR("Absolute and relative integrator tolerances cannot be less than"
                " or equal to zero", GMCMC_EINVAL);
  ode_model->options.abstol = abstol;
  ode_model->options.reltol = reltol;
  return 0;
}

/**
 * Gets the number of observed species in the ODE model.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the number of observed species in the ODE model.
 */
unsigned int gmcmc_ode_model_get_num_observed(const gmcmc_ode_model * ode_model) {
  return ode_model->observed;
}

/**
 * Gets the number of unobserved species in the ODE model.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the number of unobserved species in the ODE model.
 */
unsigned int gmcmc_ode_model_get_num_unobserved(const gmcmc_ode_model * ode_model) {
  return ode_model->unobserved;
}

/**
 * Evaluates the ODE right-hand side at a particular timepoint.
 *
 * @param [in]  ode_model  the ODE model
 * @param [in]  t       the current timepoint
 * @param [in]  y       current values of the time-dependent variables
 * @param [out] ydot    values of the time-dependent variables at time t
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
int gmcmc_ode_model_rhs(const gmcmc_ode_model * ode_model, double t,
                        const double * y, double * yout, const double * params) {
  return ode_model->rhs(t, y, yout, params);
}
