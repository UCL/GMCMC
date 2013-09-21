#ifndef GMCMC_EYE_H
#define GMCMC_EYE_H

#include <gmcmc/gmcmc_likelihood.h>

/**
 * Stochastic eye model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_eye_likelihood_mh;

/**
 * Stochastic eye model-specific data.
 *
 * A stochastic eye model has an array of vectors for each stimuli, each
 * containing times in milliseconds at which a photon is detected at that
 * stimuli.
 */
typedef struct gmcmc_eye_model gmcmc_eye_model;

/**
 * Stochastic eye dataset type.
 */
typedef struct {
  void (*destroy)(void *);                      /** Destructor function */
  size_t (*num_timepoints)(const void *);       /** Returns the number of timepoints in the dataset */
  const double * (*data)(const void *);         /** Returns a pointer to the data vector */
  const double * (*noisevar)(const void *);     /** Returns a pointer to the variance vector */
} gmcmc_eye_dataset_type;

/**
 * Stochastic eye dataset.
 */
typedef struct {
  const gmcmc_eye_dataset_type * type;  /** Pointer to function table */
  void * data;                          /** Pointer to implementation */
} gmcmc_eye_dataset;

/**
 * Creates a stochastic eye model-specific data object.
 *
 * @param [out] eye_model  the stochastic eye model
 * @param [in]  ph_data    a text file containing the integer times in
 *                          milliseconds that a photon is detected by a
 *                           photoreceptor, tab-delimited, with one
 *                           photoreceptor per line.
 * @param [in]  offset              the first timepoint to use when comparing
 *                                    the simulated data to the real data
 * @param [in]  length              the number of timepoints to use when comparing
 *                                    the simulated data to the real data
 * @param [in]  rng                 an RNG to use for the stochastic simulation
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if the RNG is NULL, or
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_eye_model_create(gmcmc_eye_model **, const char *, size_t, size_t,
                           const gmcmc_prng64 *);

/**
 * Destroys the stochastic eye model-specific data.
 *
 * @param [in] eye_model  the stochastic eye model-specific data object to
 *                        destroy
 */
void gmcmc_eye_model_destroy(gmcmc_eye_model *);

/**
 * Gets the number of photoreceptors in the model.
 *
 * @param [in] eye_model  the model
 *
 * @return the number of photoreceptors in the model.
 */
size_t gmcmc_eye_model_num_photoreceptors(const gmcmc_eye_model *);

/**
 * Gets the number of photon stimuli for a particular photoreceptor.
 *
 * @param [in] eye_model  the model
 * @param [in] i          the index of the photoreceptor
 *
 * @return the number of photon stimuli, or 0 if i is out of range.
 */
size_t gmcmc_eye_model_num_stimuli(const gmcmc_eye_model *, size_t);

/**
 * Gets a pointer to the stimuli timepoints (in milliseconds) for a particular
 * photoreceptor.
 *
 * @param [in] eye_model  the model
 * @param [in] i          the index of the photoreceptor
 *
 * @return a pointer to the stimuli timepoints, or NULL if i is out of range.
 */
const unsigned int * gmcmc_eye_model_stimuli(const gmcmc_eye_model *, size_t);

/**
 * Gets the index of the first timepoint to use when comparing data generated
 * from the model to real data.
 *
 * @param [in] eye_model  the model
 *
 * @return the index of the first timepoint to use when comparing data from the
 *           model.
 */
size_t gmcmc_eye_model_offset(const gmcmc_eye_model *);

/**
 * Gets the number of timepoints to use when comparing data generated from the
 * model to real data.
 *
 * @param [in] eye_model  the model
 *
 * @return the number of timepoints to use when comparing data from the model.
 */
size_t gmcmc_eye_model_length(const gmcmc_eye_model *);

/**
 * Gets a pointer to the random number generator to use when simulating data from
 * the model.
 *
 * @param [in] eye_model  the model
 *
 * @return a pointer to the RNG.
 */
const gmcmc_prng64 * gmcmc_eye_model_rng(const gmcmc_eye_model *);

/**
 * Destroys a stochastic eye dataset.
 *
 * @param [in] dataset  the dataset to destroy.
 */
void gmcmc_eye_dataset_destroy(gmcmc_eye_dataset *);

/**
 * Gets the number of timepoints in the dataset.
 *
 * @param [in] dataset  the dataset
 *
 * @return the number of timepoints in the dataset.
 */
static inline size_t gmcmc_eye_dataset_num_timepoints(const gmcmc_eye_dataset * dataset) {
  return dataset->type->num_timepoints(dataset->data);
}

/**
 * Gets a pointer to the data vector.
 *
 * @param [in] dataset  the dataset
 *
 * @return a pointer to the data vector.
 */
static inline const double * gmcmc_eye_dataset_data(const gmcmc_eye_dataset * dataset) {
  return dataset->type->data(dataset->data);
}

/**
 * Gets a pointer to the variance vector.
 *
 * @param [in] dataset  the dataset
 *
 * @return a pointer to the variance vector.
 */
static inline const double * gmcmc_eye_dataset_noisevar(const gmcmc_eye_dataset * dataset) {
  return dataset->type->noisevar(dataset->data);
}

/**
 * Loads a stochastic eye dataset from a Matlab file.  The file must contain a
 * real-valued column vector named "Data_Mean" containing the data points and a
 * variance vector for the data named "Data_Var".
 * The dimensionality of the data must match that of the variance.
 *
 * @param [out] dataset         the dataset object to load data into
 * @param [in]  filename        the name of the Matlab .mat file containing the
 *                                data
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to allocate the dataset or
 *                        data vectors,
 *         GMCMC_EINVAL if the Matlab file does not contain valid stochastic eye
 *                        data,
 *         GMCMC_EIO    if there is an input/output error.
 */
int gmcmc_eye_dataset_load_matlab(gmcmc_eye_dataset **, const char *);

#endif
