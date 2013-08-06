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
  (void)Ns;
  (void)tmp1;
  (void)tmp2;
  cvodes_userdata * data = (cvodes_userdata *)userdata;
  return 0;//data->rhs_sens(t, NV_DATA_S(y), NV_DATA_S(ydot), data->params);
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
 * @return 0 on success,
 *         GMCMC_ENOMEM if there was not enough memory to create the solver,
 *         GMCMC_ELINAL if the solver failed to integrate the system of ODEs.
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
    GMCMC_ERROR("Failed to create CVODES solver", GMCMC_ENOMEM);

  // Initialise CVODES solver
  if ((error = CVodeInit(cvode_mem, cvodes_rhs, timepoints[0], y)) != 0) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to initialise CVODES solver", GMCMC_ELINAL);
  }

  // Set integration tolerances
  if ((error = CVodeSStolerances(cvode_mem, options->abstol, options->reltol)) != 0) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to set integration tolerances", GMCMC_ELINAL);
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
      if ((error = CVodeSensInit(cvode_mem, num_params, CV_SIMULTANEOUS, NULL, yS)) != 0) {
        CVodeFree(&cvode_mem);
        GMCMC_ERROR("Failed to activate sensitivity calculations", GMCMC_ELINAL);
      }
    }
    else {
      if ((error = CVodeSensInit(cvode_mem, num_params, CV_SIMULTANEOUS, cvodes_rhs_sens, yS)) != 0) {
        CVodeFree(&cvode_mem);
        GMCMC_ERROR("Failed to activate sensitivity calculations", GMCMC_ELINAL);
      }
    }

    // Set sensitivity tolerances
    realtype reltolS[num_params];
    for (size_t i = 0; i < num_params; i++)
      reltolS[i] = options->reltol;
    if ((error = CVodeSensSStolerances(cvode_mem, options->abstol, reltolS)) != 0) {
      CVodeFree(&cvode_mem);
      GMCMC_ERROR("Failed to set sensitivity tolerances", GMCMC_ELINAL);
    }

    // Set sensitivity analysis optional inputs
    if ((error = CVodeSetSensParams(cvode_mem, (realtype *)params, NULL, NULL)) != 0) {
      CVodeFree(&cvode_mem);
      GMCMC_ERROR("Failed to set sensitivity parameters", GMCMC_ELINAL);
    }
  }

  // Set optional inputs
  cvodes_userdata userdata = { rhs, rhs_sens, params };
  if ((error = CVodeSetUserData(cvode_mem, &userdata)) != 0) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to set userdata", GMCMC_ELINAL);
  }

  // Attach linear solver module
  if ((error = CVDense(cvode_mem, num_species)) != 0) {
    CVodeFree(&cvode_mem);
    GMCMC_ERROR("Failed to attach linear solver", GMCMC_ELINAL);
  }

  // Advance solution in time
  realtype tret;
  for (size_t i = 1; i < num_timepoints; i++) {
    if ((error = CVode(cvode_mem, timepoints[i], y, &tret, CV_NORMAL)) != 0) {
      CVodeFree(&cvode_mem);
      GMCMC_ERROR("Failed to advance solution", GMCMC_ELINAL);
    }

    for (size_t j = 0; j < num_species; j++)
      simdata[j * lds + i] = NV_Ith_S(y, j);

    // Extract the sensitivity solution
    if (yS != NULL && sensitivities != NULL) {
      if ((error = CVodeGetSens(cvode_mem, &tret, yS)) != 0) {
        CVodeFree(&cvode_mem);
        GMCMC_ERROR("Failed to extract sensitivities", GMCMC_ELINAL);
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

  // Free solver memory
  CVodeFree(&cvode_mem);

  return 0;
}
