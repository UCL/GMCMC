#include <gmcmc/gmcmc_ode.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <math.h>

#include "cvodes.c"
#include "../mvn.c"

/**
 * Computes the sum of x.
 *
 * @param [in] n  the length of x
 * @param [in] x  a vector to sum
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
 * ODE model likelihood function using Simplified M-MALA.
 */
static int ode_likelihood_simp_mmala(const void * dataset, const gmcmc_model * model,
                                     const double * params,
                                     double * likelihood, void ** serdata, size_t * size) {
  *likelihood = -INFINITY;

  const size_t num_params = gmcmc_model_get_num_params(model);

  // Get a pointer to the ODE model-specific data
  const gmcmc_ode_model * ode_model = (const gmcmc_ode_model *)gmcmc_model_get_modelspecific(model);
  const gmcmc_ode_dataset * ode_dataset = (const gmcmc_ode_dataset *)dataset;

  // Get the number of observed and unobserved species
  const unsigned int num_observed = gmcmc_ode_model_get_num_observed(ode_model);
  const unsigned int num_unobserved = gmcmc_ode_model_get_num_unobserved(ode_model);
  const unsigned int num_species = num_observed + num_unobserved;

  // Get the timepoints
  const size_t num_timepoints = gmcmc_ode_dataset_num_timepoints(ode_dataset);
  const double * timepoints = gmcmc_ode_dataset_timepoints(ode_dataset);

  // Get initial conditions
  const double * ics = (gmcmc_ode_model_get_ics(ode_model) != NULL) ?
                        gmcmc_ode_model_get_ics(ode_model) :
                        &params[num_params - num_species];

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

  // Copy initial conditions into simulated data
  for (size_t j = 0; j < num_species; j++)
    simdata[j * lds] = ics[j];

  // Copy sensitivity initial conditions into sensitivities
  if (gmcmc_ode_model_get_ics(ode_model) == NULL) {
    // Initial conditions are being inferred as part of the parameter vector
    size_t num_real_params = num_params - num_species;
    for (size_t j = 0; j < num_real_params * num_species; j++)
      sensitivities[j * lds] = 0.0;
    double * sensitivities_ics = &sensitivities[num_real_params * num_species * lds];
    for (size_t j = 0; j < num_species; j++) {
      for (size_t i = 0; i < num_species; i++)
        sensitivities_ics[(j * num_species + i) * lds] = (i == j) ? 1.0 : 0.0;
    }
  }
  else {
    // Initial conditions are fixed
    for (size_t j = 0; j < num_params * num_species; j++)
      sensitivities[j * lds] = 0.0;
  }

  // Solve the system of equations using the function specified in the ODE model
  cvodes_options options;
  gmcmc_ode_model_get_tolerances(ode_model, &options.abstol, &options.reltol);
  int error;
  if ((error = cvodes_solve(gmcmc_ode_model_get_rhs(ode_model),
                            gmcmc_ode_model_get_rhs_sens(ode_model),
                            num_timepoints, num_species, num_params,
                            timepoints, params, &options,
                            simdata, sensitivities, lds)) != 0) {
    free(sensitivities);
    free(simdata);
    GMCMC_WARNING("Failed to solve system of ODEs", error);
  }

  // Allocate the log likelihood
  double * ll;
  if ((ll = malloc(num_observed * sizeof(double))) == NULL) {
    free(simdata);
    free(sensitivities);
    GMCMC_ERROR("Failed to allocate log likelihood", GMCMC_ENOMEM);
  }

  // The covariance matrix for observed species j is diagonal with noisecov[j]
  // repeated along the diagonal
  for (size_t j = 0; j < num_observed; j++) {
    // Subtract the real data from the simulated data so that it has zero mean
    const double * data = gmcmc_ode_dataset_data(dataset, j);
    for (size_t i = 0; i < num_timepoints; i++)
      simdata[j * lds + i] -= data[i];

    // Calculate an element of the log likelihood using the optimised PDF
    double noisecov = gmcmc_ode_dataset_noisecov(dataset, j);
    if ((error = gmcmc_mvn_logpdfs(num_timepoints, &simdata[j * lds], NULL, noisecov, &ll[j])) != 0) {
      free(ll);
      free(simdata);
      free(sensitivities);
      GMCMC_ERROR("Failed to calculate log normal PDF", error);
    }
  }

  *likelihood = sum(num_observed, ll);

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
    for (size_t i = 0; i < num_observed; i++) {
      double noisecov = gmcmc_ode_dataset_noisecov(dataset, i);
      gradient_ll[j] -= cblas_ddot(num_timepoints, &simdata[i * lds], 1, &sens_j[i * lds], 1) / noisecov;
    }

    // Calculate gradient of the log prior
    const gmcmc_distribution * prior = gmcmc_model_get_prior(model, j);
    gradient_log_prior[j] = gmcmc_distribution_log_pdf_1st_order(prior, params[j]);

    // Calculate the Hessian of the log prior
    hessian_log_prior[j] = gmcmc_distribution_log_pdf_2nd_order(prior, params[j]);

    // Calculate metric tensor
    for (size_t i = j; i < num_params; i++) {
      const double * sens_i = &sensitivities[i * num_species * lds];    // Sensitivities of parameter i
      for (size_t k = 0; k < num_observed; k++) {
        double noisecov = gmcmc_ode_dataset_noisecov(dataset, k);
        FI[j * ldfi + i] += cblas_ddot(num_timepoints, &sens_i[k * lds], 1, &sens_j[k * lds], 1) / noisecov;
      }

      FI[i * ldfi + j] = FI[j * ldfi + i];
    }
  }

  free(simdata);
  free(sensitivities);

  return 0;
}
const gmcmc_likelihood_function gmcmc_ode_likelihood_simp_mmala = &ode_likelihood_simp_mmala;
