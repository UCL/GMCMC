#include <gmcmc/gmcmc_ode.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <math.h>

#include "../mvn.c"
#include "cvodes.c"

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
 * ODE model likelihood function using Metropolis-Hastings.
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
static int ode_likelihood_mh(const void * dataset, const gmcmc_model * model,
                             const double * params, size_t n, const size_t * block,
                             double * likelihood, void ** geometry) {
  // Metropolis-Hastings likelihood functions don't calculate geometry
  (void)geometry;
  (void)n;
  (void)block;

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
  const double * timepoints = gmcmc_ode_dataset_timepoints(ode_dataset, 0);     // Assume all timepoints are the same (for now)

  // Get initial conditions
  const double * ics = (gmcmc_ode_model_get_ics(ode_model) != NULL) ?
                        gmcmc_ode_model_get_ics(ode_model) :
                        &params[num_params - num_species];

  // Allocate simulated data
  double * simdata;
  size_t lds = (num_timepoints + 1u) & ~1u;
  if ((simdata = malloc(lds * num_species * sizeof(double))) == NULL)
    GMCMC_ERROR("Failed to allocate simulated data", GMCMC_ENOMEM);

  // Copy initial conditions into simulated data
  for (size_t j = 0; j < num_species; j++)
    simdata[j * lds] = ics[j];

  // Solve the system of equations using the function specified in the ODE model
  cvodes_options options;
  gmcmc_ode_model_get_tolerances(ode_model, &options.abstol, &options.reltol);
  int error;
  if ((error = cvodes_solve(gmcmc_ode_model_get_rhs(ode_model), NULL,
                            num_timepoints, num_species, num_params, 0,
                            timepoints, params, NULL, &options, simdata, NULL, lds)) != 0) {
    free(simdata);
    GMCMC_WARNING("Failed to solve system of ODEs", error);
  }

  // Allocate the log likelihood
  double * ll;
  if ((ll = malloc(num_observed * sizeof(double))) == NULL) {
    free(simdata);
    GMCMC_ERROR("Failed to allocate log likelihood", GMCMC_ENOMEM);
  }

  // The covariance matrix for num_observed species j is diagonal with noisecov[j]
  // repeated along the diagonal
  for (size_t j = 0; j < num_observed; j++) {
    // Calculate an element of the log likelihood using the optimised PDF
    const double * data = gmcmc_ode_dataset_data(ode_dataset, j);
    double noisecov = gmcmc_ode_dataset_noisecov(ode_dataset, j);
    if ((error = gmcmc_mvn_logpdfs(num_timepoints, &simdata[j * lds], data, noisecov, &ll[j])) != 0) {
      free(ll);
      free(simdata);
      GMCMC_ERROR("Failed to calculate log normal PDF", error);
    }
  }

  *likelihood = sum(num_observed, ll);

  free(simdata);
  free(ll);

  return 0;
}
const gmcmc_likelihood_function gmcmc_ode_likelihood_mh = &ode_likelihood_mh;
