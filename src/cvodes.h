#ifndef CVODES_H
#define CVODES_H

#include <gmcmc/gmcmc_ode_model.h>

/**
 * CVODES integrator options.
 */
typedef struct {
  double abstol, reltol;        /**< Absolute and relative tolerances */
} cvodes_options;

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
 * @param [in]  timepoints      the timepoints at which data is to be returned
 * @param [in]  params          parameters
 * @param [in]  options         options for the integrator
 * @param [out] simdata         contains the state values for each species at
 *                                each timepoint in column-major order.  If
 *                                options.xdotcalc is true then the rhs will be
 *                                evaluated once at time = 0 and simdata need
 *                                only be 1 * num_species.
 * @param [out] sensitivities   sensitivities of each parameter with respect to
 *                                each independent variable.  The sensitivity of
 *                                parameter j with respect to variable k at
 *                                timepoint i is stored at (j * num_ics + k) * lds + i
 *                                Set to NULL if sensitivities are not to be
 *                                calculated.
 * @param [in]  lds             leading dimension of simdata and sensitivities
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there was not enough memory to create the solver,
 *         GMCMC_ELINAL if the solver failed to integrate the system of ODEs.
 */
int cvodes_solve(gmcmc_ode_rhs, gmcmc_ode_rhs_sens, size_t, size_t, size_t,
                 const double *, const double *, const cvodes_options *,
                 double *, double *, size_t);

#endif
