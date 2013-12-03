#ifndef GMCMC_ODE_H
#define GMCMC_ODE_H

#include <gmcmc/gmcmc_likelihood.h>

/**
 * ODE model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_ode_likelihood_mh;

/**
 * ODE model likelihood function using Simplified M-MALA.
 */
extern const gmcmc_likelihood_function gmcmc_ode_likelihood_simp_mmala;

/**
 * ODE model-specific data.
 *
 * In addition to data common to all models, ODE models have a number of
 * observed and unobserved species and a right hand side function representing
 * a system of ODEs to solve for the likelihood function.
 */
typedef struct gmcmc_ode_model gmcmc_ode_model;

/**
 * ODE dataset type.
 */
typedef struct {
  void (*destroy)(void *);                              /** Destructor function */
  size_t (*num_timepoints)(const void *);               /** Returns the number of timepoints in the dataset */
  size_t (*num_time_series)(const void *);              /** Returns the number of time series in the dataset */
  size_t (*num_data_series)(const void *);              /** Returns the number of data series in the dataset */
  const double * (*timepoints)(const void *, size_t);   /** Returns a pointer to a timepoints series */
  const double * (*data)(const void *, size_t);         /** Returns a pointer to a data series */
  double (*noisecov)(const void *, size_t);             /** Returns the noise covariance for the series */
} gmcmc_ode_dataset_type;

/**
 * ODE dataset.
 */
typedef struct {
  const gmcmc_ode_dataset_type * type;  /** Pointer to function table */
  void * data;                          /** Pointer to implementation */
} gmcmc_ode_dataset;

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
const double * gmcmc_ode_model_get_ics(const gmcmc_ode_model *);

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
int gmcmc_ode_model_set_ics(gmcmc_ode_model *, const double *);

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
 * Gets the function pointer used to compute the ODE right-hand side.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the function used to compute the ODE right-hand side.
 */
gmcmc_ode_rhs gmcmc_ode_model_get_rhs(const gmcmc_ode_model *);

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
 * Gets the function pointer used to compute the sensitivity right-hand side.
 *
 * @param [in] ode_model  the ODE model
 *
 * @return the function used to compute the sensitivity right-hand side
 */
gmcmc_ode_rhs_sens gmcmc_ode_model_get_rhs_sens(const gmcmc_ode_model *);

/**
 * Destroys an ODE dataset.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_ode_dataset_destroy(gmcmc_ode_dataset *);

/**
 * Gets the number of timepoints in an ODE dataset.
 *
 * @param [in] dataset  the ODE dataset
 *
 * @return the number of timepoints in the dataset.
 */
static inline size_t gmcmc_ode_dataset_num_timepoints(const gmcmc_ode_dataset * dataset) {
  return dataset->type->num_timepoints(dataset->data);
}

/**
 * Gets the number of time series in an ODE dataset.  Each series has the same
 * length as the timepoints.
 *
 * @param [in] dataset  the ODE dataset
 *
 * @return the number of time series in the dataset.
 */
static inline size_t gmcmc_ode_dataset_get_num_time_series(const gmcmc_ode_dataset * dataset) {
  return dataset->type->num_time_series(dataset->data);
}

/**
 * Gets the number of data series in an ODE dataset.  Each series has the same
 * length as the timepoints.
 *
 * @param [in] dataset  the ODE dataset
 *
 * @return the number of data series in the dataset.
 */
static inline size_t gmcmc_ode_dataset_get_num_data_series(const gmcmc_ode_dataset * dataset) {
  return dataset->type->num_data_series(dataset->data);
}

/**
 * Gets the timepoints from an ODE dataset.
 *
 * @param [in] dataset  the dataset
 * @param [in] i        the index of the time series
 *
 * @return the timepoints, or NULL if i is out of range.
 */
static inline const double * gmcmc_ode_dataset_timepoints(const gmcmc_ode_dataset * dataset, size_t i) {
  return dataset->type->timepoints(dataset->data, i);
}

/**
 * Gets the data for a particular series from an ODE dataset.
 *
 * @param [in] dataset  the dataset
 * @param [in] i        the index of the data series
 *
 * @return the data, or NULL if i is out of range.
 */
static inline const double * gmcmc_ode_dataset_data(const gmcmc_ode_dataset * dataset, size_t i) {
  return dataset->type->data(dataset->data, i);
}

/**
 * Gets the noise covariance value for a particular series in an ODE dataset.
 *
 * @param [in] dataset  the dataset
 * @param [in] i        the index of the data series
 *
 * @return the noise covariance for the series.
 */
static inline double gmcmc_ode_dataset_noisecov(const gmcmc_ode_dataset * dataset, size_t i) {
  return dataset->type->noisecov(dataset->data, i);
}

/**
 * Loads an ODE dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "TimePoints" containing strictly increasing
 * timepoints, a matrix of data points named "Data" and a column vector of noise
 * covariances names "NoiseVariance".
 * The length of the timepoints vector must match the length of the noise
 * covariances and the number of rows in the data.
 * The noise covariances will be available via gmcmc_dataset_get_auxdata.
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the Matlab .mat file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid ODE data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_ode_dataset_load_matlab(gmcmc_ode_dataset **, const char *);

/**
 * Loads an ODE dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "TimePoints" containing strictly increasing
 * timepoints, a matrix of data points named "Data" and a column vector of noise
 * covariances names "NoiseVariance".
 * The length of the timepoints vector must match the length of the noise
 * covariances and the number of rows in the data.
 * The noise covariances will be available via gmcmc_dataset_get_auxdata.
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the Matlab .mat file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid ODE data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_ode_dataset_load_hdf5(gmcmc_ode_dataset **, const char *);

#endif /* GMCMC_ODE_H */
