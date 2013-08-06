#ifndef GMCMC_ODE_MODEL_H
#define GMCMC_ODE_MODEL_H

#include <gmcmc/gmcmc_model.h>
#include <stdbool.h>

/**
 * ODE model-specific data.
 *
 * In addition to data common to all models, ODE models have a number of
 * observed and unobserved species and a right hand side function representing
 * a system of ODEs to solve for the likelihood function.
 */
typedef struct gmcmc_ode_model gmcmc_ode_model;

/**
 * ODE model proposal function using Metropolis-Hastings.
 */
extern const gmcmc_proposal_function gmcmc_ode_proposal_mh;

/**
 * ODE model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_ode_likelihood_mh;

/**
 * ODE model proposal function using Simplified M-MALA.
 */
extern const gmcmc_proposal_function gmcmc_ode_proposal_simp_mmala;

/**
 * ODE model proposal function using Simplified M-MALA (truncated).
 */
extern const gmcmc_proposal_function gmcmc_ode_proposal_simp_mmala_trunc;

/**
 * ODE model likelihood function using Simplified M-MALA.
 */
extern const gmcmc_likelihood_function gmcmc_ode_likelihood_simp_mmala;

/**
 * This function computes the ODE right-hand side for a given value of the
 * independent variable t and state vector y.
 *
 * @param [in]  t       the current value of the independent variable
 * @param [in]  y       the current value of the dependent variable vector, y(t)
 * @param [out] yout    the output vector f(t,y)
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
typedef int (*gmcmc_ode_rhs)(double, const double *, double *, const double *);

/**
 *  This function computes the sensitivity right-hand side for all sensitivity
 * equations at once. It must compute the vectors (df/dy)s_i(t) + (df/dp_i) and
 * store them in ySdot[i].
 *
 * @param [in]  t      is the current value of the independent variable
 * @param [in]  y      is the current value of the state vector, y(t)
 * @param [in]  ydot   is the current value of the right-hand side of the state
 *                      equations
 * @param [in]  yS     contains the current values of the sensitivity vectors
 * @param [out] ySdot  is the output of CVSensRhsFn. On exit it must contain the
 *                       sensitivity right-hand side vectors
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
typedef int (*gmcmc_ode_rhs_sens)(double, const double *, const double *,
                                  const double **, double **, const double *);

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
int gmcmc_ode_model_create(gmcmc_ode_model **, unsigned int, unsigned int,
                           gmcmc_ode_rhs);

/**
 * Destroys the ODE model-specific data.
 *
 * @param [in] ode_model  the ODE model-specific data object to destroy
 */
void gmcmc_ode_model_destroy(gmcmc_ode_model *);

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
const double * gmcmc_ode_model_get_initial_conditions(const gmcmc_ode_model *);

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
int gmcmc_ode_model_set_initial_conditions(gmcmc_ode_model *, const double *);

/**
 * Gets the integration tolerances used by the ODE solver.
 *
 * @param [in]  ode_model  the ODE model
 * @param [out] abstol     the absolute tolerance
 * @param [out] reltol     the relative tolerance
 */
void gmcmc_ode_model_get_tolerances(const gmcmc_ode_model *, double *, double *);

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
int gmcmc_ode_model_set_tolerances(gmcmc_ode_model *, double, double);

/**
 * Gets the number of observed species in the ODE model.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the number of observed species in the ODE model.
 */
unsigned int gmcmc_ode_model_get_num_observed(const gmcmc_ode_model *);

/**
 * Gets the number of unobserved species in the ODE model.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the number of unobserved species in the ODE model.
 */
unsigned int gmcmc_ode_model_get_num_unobserved(const gmcmc_ode_model *);

/**
 * This function computes the ODE right-hand side for a given value of the
 * independent variable t and state vector y.
 *
 * @param [in] ode_model  the ODE model
 * @param [in]  t         the current value of the independent variable
 * @param [in]  y         the current value of the dependent variable vector, y(t)
 * @param [out] yout      the output vector f(t,y)
 * @param [in]  params    function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
int gmcmc_ode_model_rhs(const gmcmc_ode_model *, double, const double *,
                        double *, const double *);

/**
 * Sets the function used to compute the sensitivity right-hand side.  If set to
 * NULL and sensitivity analysis is required then finite differences will be
 * used.
 *
 * @param [in] ode_model  the ODE model
 * @param [in] rhs_sens   the function used to compute the sensitivity
 *                          right-hand side
 */
void gmcmc_ode_model_set_rhs_sens(gmcmc_ode_model *, gmcmc_ode_rhs_sens);

/**
 *  This function computes the sensitivity right-hand side for all sensitivity
 * equations at once. It must compute the vectors (df/dy)s_i(t) + (df/dp_i) and
 * store them in ySdot[i].
 *
 * @param [in] ode_model  the ODE model
 * @param [in]  t      is the current value of the independent variable
 * @param [in]  y      is the current value of the state vector, y(t)
 * @param [in]  ydot   is the current value of the right-hand side of the state
 *                      equations
 * @param [in]  yS     contains the current values of the sensitivity vectors
 * @param [out] ySdot  is the output of CVSensRhsFn. On exit it must contain the
 *                       sensitivity right-hand side vectors
 * @param [in]  params  function parameters
 *
 * @return = 0 on success,
 *         > 0 if the current values in y are invalid,
 *         < 0 if one of the parameter values is incorrect.
 */
int gmcmc_ode_model_rhs_sens(const gmcmc_ode_model *, double, const double *,
                             const double *, const double **, double **,
                             const double *);

#endif /* GMCMC_ODE_MODEL_H */
