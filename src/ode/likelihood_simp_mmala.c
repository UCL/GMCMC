#include <gmcmc/gmcmc_ode.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_geometry.h>
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
 *
 * @param [in]  dataset     dataset
 * @param [in]  model       model to evaluate
 * @param [in]  params      current parameter values to evaluate the model
 * @param [in]  n           number of parameters in the current block
 * @param [in]  block       indices of the parameters in the current block (may
 *                            be NULL if there is no blocking)
 * @param [out] likelihood  likelihood value
 * @param [out] geometry    geometry for the current parameter block (may be
 *                            NULL if no geometry is required by the current
 *                            stage of the algorithm)
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate temporary
 *                        variables,
 *         GMCMC_ELINAL if there was an unrecoverable error in an external
 *                        linear algebra routine.
 */
static int ode_likelihood_simp_mmala(const void * dataset, const gmcmc_model * model,
                             const double * params, size_t n, const size_t * block,
                             double * likelihood, void ** geometry) {
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

  // Allocate simulated data
  double * simdata;
  size_t lds = (num_timepoints + 1u) & ~1u;
  if ((simdata = malloc(lds * num_species * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate simulated data", GMCMC_ENOMEM);

  // Allocate sensitivities for the parameters in the current block
  double * sensitivities;
  if ((sensitivities = malloc(lds * num_species * n * sizeof(double))) == NULL) {
    free(simdata);
    GMCMC_ERROR("Failed to allocate sensitivities", GMCMC_ENOMEM);
  }

  // Copy sensitivity initial conditions into sensitivities
  const double * ics = gmcmc_ode_model_get_ics(ode_model);
  if (ics == NULL) {
    // Initial conditions are being inferred as part of the parameter vector
    const size_t num_real_params = num_params - num_species;
    ics = &params[num_real_params];

    // For each parameter (or initial condition) in the block
    for (size_t i = 0; i < n; i++) {
      if (block[i] < num_real_params) {
        // parameter in block is a real parameter
        for (size_t j = 0; j < num_species; j++)
          sensitivities[(i * num_species + j) * lds] = 0.0;
      }
      else {
        // parameter in block is an initial condition
        for (size_t j = 0; j < num_species; j++)
          sensitivities[(i * num_species + j) * lds] = (block[i] == j) ? 1.0 : 0.0;
      }
    }
  }
  else {
    // Initial conditions are fixed
    for (size_t j = 0; j < n * num_species; j++)
      sensitivities[j * lds] = 0.0;
  }

  // Copy initial conditions into simulated data
  for (size_t j = 0; j < num_species; j++)
    simdata[j * lds] = ics[j];

  // Solve the system of equations using the function specified in the ODE model
  cvodes_options options;
  gmcmc_ode_model_get_tolerances(ode_model, &options.abstol, &options.reltol);
  int error;
  if ((error = cvodes_solve(gmcmc_ode_model_get_rhs(ode_model),
                            gmcmc_ode_model_get_rhs_sens(ode_model),
                            num_timepoints, num_species, num_params, n,
                            timepoints, params, block, &options,
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

  // Calculate the geometry only if required
  if (geometry != NULL) {
    // Calculate the gradient of the log-likelihood
    gmcmc_geometry_simp_mmala * g;
    if ((*geometry = g = calloc(1, sizeof(gmcmc_geometry_simp_mmala))) == NULL) {
      free(simdata);
      free(sensitivities);
      GMCMC_ERROR("Failed to allocate gradient structure", GMCMC_ENOMEM);
    }
    if ((g->gradient_log_prior = malloc(n * sizeof(double))) == NULL ||
        (g->gradient_log_likelihood = malloc(n * sizeof(double))) == NULL ||
        (g->hessian_log_prior = malloc(n * sizeof(double))) == NULL ||
        (g->FI = malloc((g->ldfi = (n + 1u) & ~1u) * n * sizeof(double))) == NULL) {
      free(g->gradient_log_prior);
      free(g->gradient_log_likelihood);
      free(g->hessian_log_prior);
      free(g->FI);
      free(g);
      free(simdata);
      free(sensitivities);
      GMCMC_ERROR("Failed to allocate gradient vectors", GMCMC_ENOMEM);
    }

    // Calculate gradients for each of the parameters in the block i.e. d(LL)/d(Parameter)
    for (size_t j = 0; j < n; j++) {
      const double * sens_j = &sensitivities[j * num_species * lds];      // Sensitivities of parameter block[j]

      // Calculate the gradient of the log-likelihood
      for (size_t i = 0; i < num_observed; i++) {
        double noisecov = gmcmc_ode_dataset_noisecov(dataset, i);
        g->gradient_log_likelihood[j] -= cblas_ddot(num_timepoints, &simdata[i * lds], 1, &sens_j[i * lds], 1) / noisecov;
      }

      // Calculate gradient of the log prior
      const gmcmc_distribution * prior = gmcmc_model_get_prior(model, block[j]);
      g->gradient_log_prior[j] = gmcmc_distribution_log_pdf_1st_order(prior, params[block[j]]);

      // Calculate the Hessian of the log prior
      g->hessian_log_prior[j] = gmcmc_distribution_log_pdf_2nd_order(prior, params[block[j]]);

      // Calculate metric tensor
      for (size_t i = j; i < n; i++) {
        const double * sens_i = &sensitivities[i * num_species * lds];    // Sensitivities of parameter i
        for (size_t k = 0; k < num_observed; k++) {
          double noisecov = gmcmc_ode_dataset_noisecov(dataset, k);
          g->FI[j * g->ldfi + i] += cblas_ddot(num_timepoints, &sens_i[k * lds], 1, &sens_j[k * lds], 1) / noisecov;
        }

        g->FI[i * g->ldfi + j] = g->FI[j * g->ldfi + i];
      }
    }
  }

  free(simdata);
  free(sensitivities);

  return 0;
}
const gmcmc_likelihood_function gmcmc_ode_likelihood_simp_mmala = &ode_likelihood_simp_mmala;
