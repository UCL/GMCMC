#include <gmcmc/gmcmc_ode.h>
#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>

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
   * Function to evaluate the sensitivities right-hand side.
   */
  gmcmc_ode_rhs_sens rhs_sens;

  /**
   * Fixed initial conditions for the system of ODEs.  Will be NULL if the
   * initial conditions are being inferred as part of the parameter vector in
   * the model.
   */
  double * ics;

  /**
   * ODE integrator options.
   */
  double abstol, reltol;
};

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
  (*ode_model)->rhs_sens = NULL;
  (*ode_model)->ics = NULL;
  (*ode_model)->abstol = 1.0e-06;
  (*ode_model)->reltol = 1.0e-06;

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
const double * gmcmc_ode_model_get_ics(const gmcmc_ode_model * ode_model) {
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
int gmcmc_ode_model_set_ics(gmcmc_ode_model * ode_model, const double * ics) {
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
  *abstol = ode_model->abstol;
  *reltol = ode_model->reltol;
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
  ode_model->abstol = abstol;
  ode_model->reltol = reltol;
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
 * Gets the function pointer used to compute the ODE right-hand side.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the function used to compute the ODE right-hand side.
 */
gmcmc_ode_rhs gmcmc_ode_model_get_rhs(const gmcmc_ode_model * ode_model) {
  return ode_model->rhs;
}

/**
 * Sets the function used to compute the sensitivity right-hand side.  If set to
 * NULL and sensitivity analysis is required then finite differences will be
 * used.
 *
 * @param [in] ode_model  the ODE model
 * @param [in] rhs_sens   the function used to compute the sensitivity
 *                          right-hand side
 */
void gmcmc_ode_model_set_rhs_sens(gmcmc_ode_model * ode_model,
                                  gmcmc_ode_rhs_sens rhs_sens) {
  ode_model->rhs_sens = rhs_sens;
}

/**
 * Gets the function pointer used to compute the sensitivity right-hand side.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the function used to compute the sensitivity right-hand side
 */
gmcmc_ode_rhs_sens gmcmc_ode_model_get_rhs_sens(const gmcmc_ode_model * ode_model) {
  return ode_model->rhs_sens;
}
