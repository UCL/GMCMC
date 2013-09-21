#include <gmcmc/gmcmc_eye.h>
#include <gmcmc/gmcmc_errno.h>

#include <stdlib.h>
#include <string.h>

/**
 * Stochastic eye model-specific data.
 *
 * A stochastic eye model has an array of vectors for each stimuli, each
 * containing times in milliseconds at which a photon is detected at that
 * stimuli.
 */
struct gmcmc_eye_model {
  unsigned int ** stimuli;
  size_t * num_stimuli;
  size_t num_photoreceptors;
  size_t offset, length;
  gmcmc_prng64 * rng;
};

/**
 * Creates a stochastic eye model-specific data object.
 *
 * @param [out] eye_model           the stochastic eye model
 * @param [in]  stimuli             the integer times in milliseconds that a
 *                                    photon is detected by a photoreceptor
 * @param [in]  num_stimuli         the number of times in each stimuli vector
 * @param [in]  num_photoreceptors  the number of photoreceptors
 * @param [in]  offset              the first timepoint to use when comparing
 *                                    the simulated data to the real data
 * @param [in]  length              the number of timepoints to use when comparing
 *                                    the simulated data to the real data
 * @param [in]  rng                 an RNG to use for the stochastic simulation
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if stimuli or num_stimuli is NULL, or
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_eye_model_create(gmcmc_eye_model ** eye_model, const char * ph_data,
                           size_t offset, size_t length, const gmcmc_prng64 * rng) {
  if (rng == NULL)
    GMCMC_ERROR("rng is NULL", GMCMC_EINVAL);

  if ((*eye_model = malloc(sizeof(gmcmc_eye_model))) == NULL)
    GMCMC_ERROR("Failed to allocate memory for stochastic eye model", GMCMC_ENOMEM);

  // Open the PH data file
  FILE * file;
  if ((file = fopen(ph_data, "r")) == NULL) {
    free(*eye_model);
    GMCMC_ERROR("Failed to open ph_data file", GMCMC_EIO);
  }

  (*eye_model)->num_photoreceptors = 0;
  (*eye_model)->num_stimuli = NULL;
  (*eye_model)->stimuli = NULL;

  const size_t max_length = 100;
  char line[max_length];
  while (fgets(line, max_length, file) != NULL) {
    // Increment the number of photoreceptors
    size_t i = (*eye_model)->num_photoreceptors;
    (*eye_model)->num_photoreceptors++;

    // Increase the size of the num_stimuli and stimuli arrays
    size_t * num_stimuli;
    if ((num_stimuli = realloc((*eye_model)->num_stimuli, (*eye_model)->num_photoreceptors * sizeof(size_t))) == NULL) {
      for (size_t i = 0; i < (*eye_model)->num_photoreceptors; i++)
        free((*eye_model)->stimuli[i]);
      free((*eye_model)->stimuli);
      free((*eye_model)->num_stimuli);
      free(*eye_model);
      GMCMC_ERROR("Failed to reallocate memory for number of stimuli", GMCMC_ENOMEM);
    }
    (*eye_model)->num_stimuli = num_stimuli;
    num_stimuli[i] = 0;

    unsigned int ** stimuli;
    if ((stimuli = realloc((*eye_model)->stimuli, (*eye_model)->num_photoreceptors * sizeof(unsigned int *))) == NULL) {
      for (size_t i = 0; i < (*eye_model)->num_photoreceptors; i++)
        free((*eye_model)->stimuli[i]);
      free((*eye_model)->stimuli);
      free((*eye_model)->num_stimuli);
      free(*eye_model);
      GMCMC_ERROR("Failed to reallocate memory for stimuli vectors", GMCMC_ENOMEM);
    }
    (*eye_model)->stimuli = stimuli;
    stimuli[i] = NULL;

    if (strncmp("\n", line, 1) != 0) {
      char * ptr = strtok(line, "\t");
      while (ptr != NULL) {
        // Increment the number of stimuli for this photoreceptor
        size_t j = num_stimuli[i];
        num_stimuli[i]++;

        // Increase the size of the stimuli array for this photoreceptor
        unsigned int * stimuli_i;
        if ((stimuli_i = realloc(stimuli[i], num_stimuli[i] * sizeof(unsigned int))) == NULL) {
          for (size_t i = 0; i < (*eye_model)->num_photoreceptors; i++)
            free((*eye_model)->stimuli[i]);
          free((*eye_model)->stimuli);
          free((*eye_model)->num_stimuli);
          free(*eye_model);
          GMCMC_ERROR("Failed to reallocate memory for stimuli", GMCMC_ENOMEM);
        }
        (*eye_model)->stimuli[i] = stimuli_i;

        if (sscanf(ptr, "%u", &stimuli_i[j]) != 1) {
          for (size_t i = 0; i < (*eye_model)->num_photoreceptors; i++)
            free((*eye_model)->stimuli[i]);
          free((*eye_model)->stimuli);
          free((*eye_model)->num_stimuli);
          free(*eye_model);
          GMCMC_ERROR("Failed to parse stimuli timepoint", GMCMC_ENOMEM);
        }

        ptr = strtok(NULL, "\t");
      }
    }
  }
  fclose(file);

  int error;
  if ((error = gmcmc_prng64_create_copy(&(*eye_model)->rng, rng)) != 0) {
    for (size_t j = 0; j < (*eye_model)->num_photoreceptors; j++)
      free((*eye_model)->stimuli[j]);
    free((*eye_model)->stimuli);
    free((*eye_model)->num_stimuli);
    free((*eye_model)->rng);
    free(*eye_model);
    GMCMC_ERROR("Failed to copy RNG", error);
  }

  (*eye_model)->offset = offset;
  (*eye_model)->length = length;

  return 0;
}

/**
 * Destroys the stochastic eye model-specific data.
 *
 * @param [in] eye_model  the stochastic eye model-specific data object to
 *                        destroy
 */
void gmcmc_eye_model_destroy(gmcmc_eye_model * eye_model) {
  if (eye_model == NULL)
    return;
  for (size_t i = 0; i < eye_model->num_photoreceptors; i++)
    free(eye_model->stimuli[i]);
  free(eye_model->stimuli);
  free(eye_model->num_stimuli);
  gmcmc_prng64_destroy(eye_model->rng);
  free(eye_model);
}

/**
 * Gets the number of photoreceptors in the model.
 *
 * @param [in] eye_model  the model
 *
 * @return the number of photoreceptors in the model.
 */
size_t gmcmc_eye_model_num_photoreceptors(const gmcmc_eye_model * eye_model) {
  return eye_model->num_photoreceptors;
}

/**
 * Gets the number of photon stimuli for a particular photoreceptor.
 *
 * @param [in] eye_model  the model
 * @param [in] i          the index of the photoreceptor
 *
 * @return the number of photon stimuli, or 0 if i is out of range.
 */
size_t gmcmc_eye_model_num_stimuli(const gmcmc_eye_model * eye_model, size_t i) {
  if (i >= eye_model->num_photoreceptors)
    GMCMC_ERROR_VAL("i is out of range", GMCMC_EINVAL, 0);
  return eye_model->num_stimuli[i];
}

/**
 * Gets a pointer to the stimuli timepoints (in milliseconds) for a particular
 * photoreceptor.
 *
 * @param [in] eye_model  the model
 * @param [in] i          the index of the photoreceptor
 *
 * @return a pointer to the stimuli timepoints, or NULL if i is out of range.
 */
const unsigned int * gmcmc_eye_model_stimuli(const gmcmc_eye_model * eye_model, size_t i) {
  if (i >= eye_model->num_photoreceptors)
    GMCMC_ERROR_VAL("i is out of range", GMCMC_EINVAL, 0);
  return eye_model->stimuli[i];
}


/**
 * Gets the index of the first timepoint to use when comparing data generated
 * from the model to real data.
 *
 * @param [in] eye_model  the model
 *
 * @return the index of the first timepoint to use when comparing data from the
 *           model.
 */
size_t gmcmc_eye_model_offset(const gmcmc_eye_model * eye_model) {
  return eye_model->offset;
}

/**
 * Gets the number of timepoints to use when comparing data generated from the
 * model to real data.
 *
 * @param [in] eye_model  the model
 *
 * @return the number of timepoints to use when comparing data from the model.
 */
size_t gmcmc_eye_model_length(const gmcmc_eye_model * eye_model) {
  return eye_model->length;
}

/**
 * Gets a pointer to the random number generator to use when simulating data from
 * the model.
 *
 * @param [in] eye_model  the model
 *
 * @return a pointer to the RNG.
 */
const gmcmc_prng64 * gmcmc_eye_model_rng(const gmcmc_eye_model * eye_model) {
  return eye_model->rng;
}
