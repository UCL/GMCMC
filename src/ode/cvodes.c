#include "cvodes.h"
#include <cvodes/cvodes.h>
#include <cvodes/cvodes_lapack.h>
#include <nvector/nvector_serial.h>

#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>

typedef struct {
  gmcmc_ode_rhs rhs;
  const double * params;
} cvodes_userdata;

/**
 * Wrapper round gmcmc_ode_rhs to make it match CVRhsFn.
 */
static int cvodes_rhs(realtype t, N_Vector y, N_Vector ydot, void * userdata) {
  cvodes_userdata * data = (cvodes_userdata *)userdata;
  return data->rhs(t, NV_DATA_S(y), NV_DATA_S(ydot), data->params);
}

/**
 * Solves an initial value problem using CVODES to integrate over a system of
 * ODEs with optional forward sensitivity analysis.  The initial conditions for
 * the system and for the sensitivity analysis are expected to be in the first
 * rows of simdata and sensitivities, respectively.
 *
 * @param [in]  rhs             the right-hand side of the system of ODEs
 * @param [in]  num_timepoints  the number of timepoints
 * @param [in]  num_species     the number of independent variables
 * @param [in]  num_sens        the number of parameters to compute sensitivities
 *                                for (set to zero to disable sensitivity
 *                                calculations)
 * @param [in]  timepoints      the timepoints at which data is to be returned
 * @param [in]  params          parameters
 * @param [in]  sensi           the indices of the parameters to compute the
 *                                sensitivities for (may be NULL to compute the
 *                                sensitivities for all parameters)
 * @param [in]  options         additional options for the integrator
 * @param [out] simdata         contains the state values for each species at
 *                                each timepoint in column-major order.
 * @param [out] sensitivities   sensitivities of each parameter in sensi
 *                                with respect to each independent variable.
 *                                The sensitivity of parameter j with respect to
 *                                variable k at timepoint i is stored at
 *                                (j * num_species + k) * lds + i.
 *                                May be NULL if sensitivities are not to be
 *                                calculated.
 * @param [in]  lds             leading dimension of simdata and sensitivities
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the solver,
 *         GMCMC_EINVAL  if there was an invalid argument to the function,
 *         GMCMC_ELINAL  if the solution could not be found.
 */
int cvodes_solve(gmcmc_ode_rhs rhs, size_t num_timepoints, size_t num_species, size_t num_params, size_t num_sens, const double * timepoints, const double * params, const size_t * sensi, const cvodes_options * options, double * simdata, double * sensitivities, size_t lds) {
  int error;

  // Set vector of initial values
  N_Vector y = N_VNew_Serial((long int)num_species);
  for (size_t j = 0; j < num_species; j++)
    NV_Ith_S(y, j) = simdata[j * lds];

  // Create CVODES object
  void * cvode_mem;
  if ((cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON)) == NULL)
    GMCMC_ERROR("Failed to allocate ODE solver", GMCMC_ENOMEM);

  // Initialise CVODES solver
  if ((error = CVodeInit(cvode_mem, cvodes_rhs, timepoints[0], y)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to initialise ODE solver", (error == CV_ILL_INPUT) ? GMCMC_EINVAL : GMCMC_ENOMEM);
  }

  // Set integration tolerances
  if ((error = CVodeSStolerances(cvode_mem, options->reltol, options->abstol)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to set ODE solver integration tolerances", (error == CV_ILL_INPUT) ? GMCMC_EINVAL : GMCMC_ENOMEM);
  }

  // Create a copy of the parameters in case CVODES modifies them
  realtype * sens_params;
  if ((sens_params = malloc(num_params * sizeof(realtype))) == NULL) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to allocate copy of parameter vector for sensitivity analysis", GMCMC_ENOMEM);
  }
  for (size_t i = 0; i < num_params; i++)
    sens_params[i] = (realtype)params[i];

  // Set optional inputs
  cvodes_userdata userdata = { rhs, sens_params };
  if ((error = CVodeSetUserData(cvode_mem, &userdata)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    free(sens_params);
    GMCMC_ERROR("Failed to set ODE solver user data", GMCMC_EINVAL);
  }

  // Attach linear solver module
  if ((error = CVLapackDense(cvode_mem, (int)num_species)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    free(sens_params);
    GMCMC_ERROR("Failed to attach ODE solver module", (error == CV_ILL_INPUT) ? GMCMC_EINVAL : GMCMC_ENOMEM);
  }

  N_Vector * yS = NULL;
  int * plist = NULL;
  if (num_sens > 0) {
    // Set sensitivity initial conditions
    yS = N_VCloneVectorArray_Serial((int)num_sens, y);
    for (size_t j = 0; j < num_sens; j++) {
      for (size_t i = 0; i < num_species; i++)
        NV_Ith_S(yS[j], i) = sensitivities[(j * num_species + i) * lds];
    }

    // Activate sensitivity calculations
    // Use default finite differences
    if ((error = CVodeSensInit(cvode_mem, (int)num_sens, CV_SIMULTANEOUS, NULL, yS)) != CV_SUCCESS) {
      CVodeFree(&cvode_mem);
      free(sens_params);
      GMCMC_ERROR("Failed to activate ODE solver sensitivity calculations", (error == CV_ILL_INPUT) ? GMCMC_EINVAL : GMCMC_ENOMEM);
    }

    // Set sensitivity tolerances
    if ((error = CVodeSensEEtolerances(cvode_mem)) != CV_SUCCESS) {
      CVodeFree(&cvode_mem);
      free(sens_params);
      GMCMC_ERROR("Failed to set ODE solver sensitivity tolerances", (error == CV_ILL_INPUT) ? GMCMC_EINVAL : GMCMC_ENOMEM);
    }

    if (sensi != NULL) {
      if ((plist = malloc(num_sens * sizeof(int))) == NULL) {
        CVodeFree(&cvode_mem);
      free(sens_params);
        GMCMC_ERROR("Failed to allocate sensitivity parameter list", GMCMC_ENOMEM);
      }
      for (size_t i = 0; i < num_sens; i++)
        plist[i] = (int)sensi[i];
    }

    // Set sensitivity analysis optional inputs
    if ((error = CVodeSetSensParams(cvode_mem, sens_params, NULL, plist)) != CV_SUCCESS) {
      CVodeFree(&cvode_mem);
      free(plist);
      free(sens_params);
      GMCMC_ERROR("Failed to set ODE solver sensitivity parameters", (error == CV_ILL_INPUT) ? GMCMC_EINVAL : GMCMC_ENOMEM);
    }
  }

  // Advance solution in time
  realtype tret;
  for (size_t i = 1; i < num_timepoints; i++) {
    if ((error = CVode(cvode_mem, timepoints[i], y, &tret, CV_NORMAL)) != CV_SUCCESS) {
      free(plist);
      free(sens_params);
      CVodeFree(&cvode_mem);
      GMCMC_ERROR("Failed to advance ODE solution", GMCMC_ELINAL);
    }

    for (size_t j = 0; j < num_species; j++)
      simdata[j * lds + i] = NV_Ith_S(y, j);

    // Extract the sensitivity solution
    if (yS != NULL) {
      if ((error = CVodeGetSens(cvode_mem, &tret, yS)) != CV_SUCCESS) {
        free(plist);
        free(sens_params);
        CVodeFree(&cvode_mem);
        GMCMC_ERROR("Failed to extract ODE sensitivity solution", GMCMC_ELINAL);
      }

      for (size_t j = 0; j < num_sens; j++) {
        for (size_t k = 0; k < num_species; k++)
          sensitivities[(j * num_species + k) * lds + i] = NV_Ith_S(yS[j], k);
      }
    }
  }
  N_VDestroy(y);
  if (yS != NULL)
    N_VDestroyVectorArray_Serial(yS, (int)num_sens);

  free(plist);
  free(sens_params);

  // Free solver memory
  CVodeFree(&cvode_mem);

  return 0;
}
