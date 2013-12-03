#ifndef GMCMC_ION_H
#define GMCMC_ION_H

#include <gmcmc/gmcmc_likelihood.h>

/**
 * Ion channel model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_ion_likelihood_mh;

/**
 * Ion channel model-specific data.
 *
 * In addition to data common to all models, ion channel models have a Q matrix
 * which details the transitions between open and closed states.
 */
typedef struct gmcmc_ion_model gmcmc_ion_model;

/**
 * Ion channel dataset type.
 */
typedef struct {
  void (*destroy)(void *);                      /** Destructor function */
  size_t (*num_timepoints)(const void *);       /** Returns the number of timepoints in the dataset */
  const double * (*timepoints)(const void *);   /** Returns a pointer to the timepoints */
  const double * (*data)(const void *);         /** Returns a pointer to the data */
} gmcmc_ion_dataset_type;

/**
 * Ion channel dataset.
 */
typedef struct {
  const gmcmc_ion_dataset_type * type;  /** Pointer to function table */
  void * data;                          /** Pointer to implementation */
} gmcmc_ion_dataset;

/**
 * Function type that populates the Q matrix based on the current parameter
 * values.  The size of the parameter vector and number of open and closed
 * states are expected to be known in the model.  A Q matrix of the correct size
 * for the model is allocated based on the number of open and closed states and
 * is initialised to zero before calling this function.
 *
 * The Q matrix is expected to have the closed states in the upper left and open
 * states in the lower right.
 *
 * @param [in]  params  current parameter values
 * @param [out] Q       Q matrix to populate
 * @param [in]  ldq     leading dimension of the Q matrix
 */
typedef void (*gmcmc_ion_calculate_Q_matrix)(const double *, double *, size_t);

/**
 * Creates an ion channel model-specific data object.
 *
 * @param [out] ion_model           the ion channel model
 * @param [in]  closed              number of closed states in the model
 * @param [in]  open                number of open states in the model
 * @param [in]  calculate_Q_matrix  a function to calculate the Q matrix based
 *                                    on the current parameter values.
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if calculate_Q_matrix is NULL, or
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_ion_model_create(gmcmc_ion_model **, unsigned int, unsigned int,
                           gmcmc_ion_calculate_Q_matrix);

/**
 * Destroys the ion channel model-specific data.
 *
 * @param [in] ion_model  the ion channel model-specific data object to destroy
 */
void gmcmc_ion_model_destroy(gmcmc_ion_model *);

/**
 * Gets the number of closed states in the model.
 *
 * @param [in] ion_model  the ion channel model
 *
 * @return the number of closed states in the model.
 */
unsigned int gmcmc_ion_model_get_num_closed_states(const gmcmc_ion_model *);

/**
 * Gets the number of open states in the model.
 *
 * @param [in] ion_model  the ion channel model
 *
 * @return the number of open states in the model.
 */
unsigned int gmcmc_ion_model_get_num_open_states(const gmcmc_ion_model *);

/**
 * Calculates the Q matrix for an ion channel model.
 *
 * @param [in]  ion_model  the ion channel model
 * @param [in]  params     the parameter values to use to calculate the Q matrix
 * @param [out] Q          the Q matrix
 * @param [in]  ldq        leading dimension of the Q matrix
 */
void gmcmc_ion_model_calculate_Q_matrix(const gmcmc_ion_model *, const double *,
                                        double *, size_t);

/**
 * Destroys an ion channel dataset.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_ion_dataset_destroy(gmcmc_ion_dataset *);

/**
 * Gets the number of timepoints in the dataset.
 *
 * @param [in] dataset  the dataset
 *
 * @return the number of timepoints in the dataset.
 */
static inline size_t gmcmc_ion_dataset_num_timepoints(const gmcmc_ion_dataset * dataset) {
  return dataset->type->num_timepoints(dataset->data);
}

/**
 * Gets a pointer to the timepoints.
 *
 * @param [in] dataset  the dataset
 *
 * @return a pointer to the timepoints.
 */
static inline const double * gmcmc_ion_dataset_timepoints(const gmcmc_ion_dataset * dataset) {
  return dataset->type->timepoints(dataset->data);
}

/**
 * Gets a pointer to the data.
 *
 * @param [in] dataset  the dataset
 *
 * @return a pointer to the data.
 */
static inline const double * gmcmc_ion_dataset_data(const gmcmc_ion_dataset * dataset) {
  return dataset->type->data(dataset->data);
}

/**
 * Loads an ion channel dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "TimePoints" containing strictly increasing
 * timepoints and a vector of data points named "Data".
 * The dimensionality of the timepoints must match that of the data.
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the Matlab .mat file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid ion channel
 *                        data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_ion_dataset_load_matlab(gmcmc_ion_dataset **, const char *);

/**
 * Loads an ion channel dataset from an HDF5 file.  The file must contain a
 * 1-by-n dataset of native double values named "TimePoints" and a corresponding
 * dataset of the same dimensions and type named "Data".
 *
 * @param [out] dataset     the dataset object to load data into
 * @param [in]  filename    the name of the HDF .h5 file containing the data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the HDF5 file does not contain valid ion channel
 *                        data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_ion_dataset_load_hdf5(gmcmc_ion_dataset **, const char *);

#endif /* GMCMC_ION_H */
