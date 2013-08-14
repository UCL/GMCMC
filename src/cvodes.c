#include <cvodes/cvodes.h>
#include <cvodes/cvodes_dense.h>
#include <nvector/nvector_serial.h>

#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>

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
 * Wrapper round gmcmc_ode_rhs to make it match CVRhsFn.
 */
static int cvodes_rhs(realtype t, N_Vector y, N_Vector ydot, void * userdata) {
  cvodes_userdata * data = (cvodes_userdata *)userdata;
  return data->rhs(t, NV_DATA_S(y), NV_DATA_S(ydot), data->params);
}

/**
 * Wrapper round gmcmc_ode_rhs_sens to make it match CVSensRhsFn.
 */
static int cvodes_rhs_sens(int Ns, realtype t, N_Vector y, N_Vector ydot,
                           N_Vector * yS, N_Vector * ySdot, void * userdata,
                           N_Vector tmp1, N_Vector tmp2) {
  (void)tmp1;
  (void)tmp2;
  cvodes_userdata * data = (cvodes_userdata *)userdata;

  // Get the raw pointers from the sensitivity vectors
  if (!data->init) {
    for (int i = 0; i < Ns; i++) {
      data->yS[i] = NV_DATA_S(yS[i]);
      data->ySdot[i] = NV_DATA_S(ySdot[i]);
    }
    data->init = true;
  }

  return data->rhs_sens(t, NV_DATA_S(y), NV_DATA_S(ydot), data->yS, data->ySdot, data->params);
}

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
 * @return CV_SUCCESS on success,
 *         CV_MEM_FAIL  if there was not enough memory to create the solver,
 */
static int cvodes_solve(gmcmc_ode_rhs rhs, gmcmc_ode_rhs_sens rhs_sens,
                        size_t num_timepoints, size_t num_species, size_t num_params,
                        const double * timepoints, const double * params,
                        const cvodes_options * options,
                        double * simdata, double * sensitivities, size_t lds) {
  int error;

  // Set vector of initial values
  N_Vector y = N_VNew_Serial(num_species);
  for (size_t i = 0; i < num_species; i++)
    NV_Ith_S(y, i) = simdata[i * lds];

  // Create CVODES object
  void * cvode_mem;
  if ((cvode_mem = CVodeCreate(CV_BDF, CV_NEWTON)) == NULL)
    // Returns NULL if there is not enough memory to allocate the solver
    return CV_MEM_FAIL;

  // Initialise CVODES solver
  if ((error = CVodeInit(cvode_mem, cvodes_rhs, timepoints[0], y)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    return error;
  }

  // Set integration tolerances
  if ((error = CVodeSStolerances(cvode_mem, options->abstol, options->reltol)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    return error;
  }

  // Set optional inputs
  cvodes_userdata userdata = { rhs, rhs_sens, params, false, NULL, NULL };
  if ((error = CVodeSetUserData(cvode_mem, &userdata)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    return error;
  }

  // Attach linear solver module
  if ((error = CVDense(cvode_mem, num_species)) != CV_SUCCESS) {
    CVodeFree(&cvode_mem);
    return error;
  }

  N_Vector * yS = NULL;
  if (sensitivities != NULL) {
    // Set sensitivity initial conditions
    yS = N_VCloneVectorArray_Serial(num_params, y);
    for (size_t j = 0; j < num_params; j++) {
      for (size_t i = 0; i < num_species; i++)
        NV_Ith_S(yS[j], i) = sensitivities[(j * num_species + i) * lds];
    }

    // Activate sensitivity calculations
    if (rhs_sens == NULL) {
      // Use default finite differences
      if ((error = CVodeSensInit(cvode_mem, num_params, CV_SIMULTANEOUS, NULL, yS)) != CV_SUCCESS) {
        CVodeFree(&cvode_mem);
        return error;
      }
    }
    else {
      // Use supplied sensitivities function
      if ((error = CVodeSensInit(cvode_mem, num_params, CV_SIMULTANEOUS, cvodes_rhs_sens, yS)) != CV_SUCCESS) {
        CVodeFree(&cvode_mem);
        return error;
      }
    }

    // Set sensitivity tolerances
    if ((error = CVodeSensEEtolerances(cvode_mem)) != CV_SUCCESS) {
      CVodeFree(&cvode_mem);
      return error;
    }

    // Set sensitivity analysis optional inputs
    if ((error = CVodeSetSensParams(cvode_mem, (realtype *)params, NULL, NULL)) != CV_SUCCESS) {
      CVodeFree(&cvode_mem);
      return error;
    }

    if ((userdata.yS = malloc(num_params * sizeof(double *))) == NULL ||
        (userdata.ySdot = malloc(num_params * sizeof(double *))) == NULL) {
      free(userdata.yS);
      free(userdata.ySdot);
      CVodeFree(&cvode_mem);
      return error;
    }
  }

  // Advance solution in time
  realtype tret;
  for (size_t i = 1; i < num_timepoints; i++) {
    if ((error = CVode(cvode_mem, timepoints[i], y, &tret, CV_NORMAL)) != CV_SUCCESS) {
      free(userdata.yS);
      free(userdata.ySdot);
      CVodeFree(&cvode_mem);
      return error;
    }

    for (size_t j = 0; j < num_species; j++)
      simdata[j * lds + i] = NV_Ith_S(y, j);

    // Extract the sensitivity solution
    if (yS != NULL) {
      if ((error = CVodeGetSens(cvode_mem, &tret, yS)) != CV_SUCCESS) {
        free(userdata.yS);
        free(userdata.ySdot);
        CVodeFree(&cvode_mem);
        return error;
      }

      for (size_t j = 0; j < num_params; j++) {
        for (size_t k = 0; k < num_species; k++)
          sensitivities[(j * num_species + k) * lds + i] = NV_Ith_S(yS[j], k);
      }
    }
  }
  N_VDestroy(y);
  if (yS != NULL)
    N_VDestroyVectorArray_Serial(yS, num_params);

  free(userdata.yS);
  free(userdata.ySdot);

  // Free solver memory
  CVodeFree(&cvode_mem);

  return 0;
}
