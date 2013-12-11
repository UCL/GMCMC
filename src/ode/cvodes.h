#ifndef CVODES_H
#define CVODES_H

#include <gmcmc/gmcmc_ode.h>
#include <stdbool.h>

/**
 * CVODES integrator options.
 */
typedef struct {
  double abstol, reltol;        /**< Absolute and relative tolerances */
} cvodes_options;

typedef struct {
  gmcmc_ode_rhs rhs;
  gmcmc_ode_rhs_sens rhs_sens;
  const double * params;
  bool init;
  const double ** yS;
  double ** ySdot;       // temporary vectors for rearranging sensitivity data
} cvodes_userdata;

/**
 * Solves an initial value problem using CVODES to integrate over a system of
 * ODEs with optional forward sensitivity analysis.  The initial conditions for
 * the system and for the sensitivity analysis are expected to be in the first
 * rows of simdata and sensitivities, respectively.
 *
 * @param [in]  rhs             the right-hand side of the system of ODEs
 * @param [in]  rhs_sens        the sensitivities right-hand side
 * @param [in]  num_timepoints  the number of timepoints
 * @param [in]  num_species     the number of independent variables
 * @param [in]  num_params      the number of parameters
 * @param [in]  num_sens        the number of parameters to compute sensitivities
 *                                for (set to zero to disable sensitivity
 *                                calculations)
 * @param [in]  timepoints      the timepoints at which data is to be returned
 * @param [in]  params          parameters
 * @param [in]  sens_params     the indices of the parameters to compute the
 *                                sensitivities for (may be NULL to compute the
 *                                sensitivities for all parameters)
 * @param [in]  options         options for the integrator
 * @param [out] simdata         contains the state values for each species at
 *                                each timepoint in column-major order.  If
 *                                options.xdotcalc is true then the rhs will be
 *                                evaluated once at time = 0 and simdata need
 *                                only be 1 * num_species.
 * @param [out] sensitivities   sensitivities of each parameter in sens_params
 *                                with respect to each independent variable.
 *                                The sensitivity of parameter j with respect to
 *                                variable k at timepoint i is stored at
 *                                (j * num_ics + k) * lds + i.
 *                                May be NULL if sensitivities are not to be
 *                                calculated.
 * @param [in]  lds             leading dimension of simdata and sensitivities
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the solver,
 *         GMCMC_EINVAL  if there was an invalid argument to the function,
 *         GMCMC_ELINAL  if the solution could not be found.
 */
int cvodes_solve(gmcmc_ode_rhs, gmcmc_ode_rhs_sens,
                        size_t, size_t, size_t, size_t,
                        const double *, const double *, const size_t *,
                        const cvodes_options *,
                        double *, double *, size_t);

#endif  /** CVODES_H */
