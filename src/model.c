#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * A model.
 */
struct gmcmc_model {
  double * params;                      /**< Initial parameter values (may be NULL) */
  gmcmc_distribution ** priors;         /**< A prior distribution for each parameter */
  size_t n;                             /**< Number of parameters in model */
  double stepsize;                      /**< Parameter stepsize (default 0.05) */
  double lower_stepsize, upper_stepsize;/**< Lower and upper bounds for adapting stepsize */
  size_t num_blocks;                    /**< Number of blocks to use to update parameters.  Will always be >= 1. */
  size_t * block_sizes;                 /**< The size of each block (length num_blocks) */
  size_t * blocks;                      /**< The fixed permutation of parameter indices to use as the blocks (may be NULL for random blocking) */
  void * modelspecific;                 /**< Model specific parameters and data (may be NULL) */
};

/**
 * Creates a model.
 *
 * @param [out] model       the model to create
 * @param [in]  n           the number of parameters in the model
 * @param [in]  priors      an array of prior distributions for each parameter
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to create a new model.
 */
int gmcmc_model_create(gmcmc_model ** model, size_t n, gmcmc_distribution ** priors) {
  // Allocate memory for the model
  if ((*model = calloc(1, sizeof(gmcmc_model))) == NULL)
    GMCMC_ERROR("Unable to allocate model", GMCMC_ENOMEM);

  // Allocate memory for the priors
  if (((*model)->priors = malloc(n * sizeof(gmcmc_distribution *))) == NULL) {
    free(*model);
    GMCMC_ERROR("Unable to allocate priors", GMCMC_ENOMEM);
  }

  // Create copies of all the priors passed in
  int error;
  for (size_t i = 0; i < n; i++) {
    if ((error = gmcmc_distribution_create_copy(&(*model)->priors[i], priors[i])) != 0) {
      for (size_t j = 0; j < i; j++)
        gmcmc_distribution_destroy((*model)->priors[j]);
      free(*model);
      GMCMC_ERROR("Unable to copy priors into model", error);
    }
  }

  // Set up default blocking
  (*model)->num_blocks = 1;
  if (((*model)->block_sizes = malloc(sizeof(size_t))) == NULL ||
      ((*model)->blocks = malloc(n * sizeof(size_t))) == NULL) {
    for (size_t j = 0; j < n; j++)
      gmcmc_distribution_destroy((*model)->priors[j]);
    free((*model)->block_sizes);
    free((*model)->blocks);
    free(*model);
    GMCMC_ERROR("Failed to allocate default blocking", GMCMC_ENOMEM);
  }
  (*model)->block_sizes[0] = n;
  for (size_t i = 0; i < n; i++)
    (*model)->blocks[i] = i;

  // Copy the rest of the parameters and set default values
//   (*model)->params = NULL; // calloc'ed
  (*model)->n = n;
  (*model)->stepsize = 0.05;
  (*model)->lower_stepsize = 0.0;
  (*model)->upper_stepsize = 1.0;
//   (*model)->modelspecific = NULL;  // calloc'ed

  return 0;
}

/**
 * Destroys a model.
 *
 * @param [in] model  the model to destroy.
 */
void gmcmc_model_destroy(gmcmc_model * model) {
  for (size_t i = 0; i < model->n; i++)
    gmcmc_distribution_destroy(model->priors[i]);
  free(model->priors);
  free(model->params);
  free(model->block_sizes);
  free(model->blocks);
  free(model);
}

/**
 * Gets the number of parameters in the model.
 *
 * @param [in] model  the model
 *
 * @return the number of parameters in the model.
 */
size_t gmcmc_model_get_num_params(const gmcmc_model * model) {
  return model->n;
}

/**
 * Sets the initial parameter values.
 *
 * @param [in,out] model   the model
 * @param [in]    params  the parameter values (may be NULL)
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to copy the initial
 *                        parameter values into the model.
 */
int gmcmc_model_set_params(gmcmc_model * model, const double * params) {
  free(model->params);
  if (params == NULL)
    model->params = NULL;
  else {
    if ((model->params = malloc(model->n * sizeof(double))) == NULL)
      GMCMC_ERROR("Unable to allocate model parameters", GMCMC_ENOMEM);
    memcpy(model->params, params, model->n * sizeof(double));
  }
  return 0;
}

/**
 * Gets a pointer to the initial parameter values.
 *
 * @param [in] model  the model
 *
 * @return a pointer to the initial parameter values.
 */
const double * gmcmc_model_get_params(const gmcmc_model * model) {
  return model->params;
}

/**
 * Gets a pointer to the priors for each parameter.
 *
 * @param [in] model  the model
 * @param [in] i      the parameter index
 *
 * @return the prior for the ith parameter or NULL if the i is out of range.
 */
const gmcmc_distribution * gmcmc_model_get_prior(const gmcmc_model * model, size_t i) {
  if (i > model->n)
    GMCMC_ERROR_VAL("Prior index is out of range", GMCMC_EINVAL, NULL);
  return model->priors[i];
}

/**
 * Sets the parameter stepsize.
 *
 * @param [in] model     the model
 * @param [in] stepsize  the stepsize
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if the stepsize is less than or equal to zero.
 */
int gmcmc_model_set_stepsize(gmcmc_model * model, double stepsize) {
  if (islessequal(stepsize, 0.0))
    GMCMC_ERROR("Invalid stepsize", GMCMC_EINVAL);
  model->stepsize = stepsize;
  return 0;
}

/**
 * Gets the parameter stepsize.
 *
 * @param [in] model  the model
 *
 * @return the parameter stepsize.
 */
double gmcmc_model_get_stepsize(const gmcmc_model * model) {
  return model->stepsize;
}

/**
 * Sets the upper and lower limits for adapting stepsizes.
 *
 * @param [in] model  the model
 * @param [in] lower  the lower bound for the stepsizes
 * @param [in] upper  the upper bound for the stepsizes
 *
 * @return 0 on success, GMCMC_EINVAL if lower is greater than upper.
 */
int gmcmc_model_set_stepsize_bounds(gmcmc_model * model, double lower, double upper) {
  if (isgreater(lower, upper))
    GMCMC_ERROR("Lower stepsize bound is greater than upper stepsize bound", GMCMC_EINVAL);
  model->lower_stepsize = lower;
  model->upper_stepsize = upper;
  return 0;
}

/**
 * Gets the upper and lower limits for adapting stepsizes.
 *
 * @param [in]  model  the model
 * @param [out] lower  the lower bound for the stepsizes
 * @param [out] upper  the upper bound for the stepsizes
 */
void gmcmc_model_get_stepsize_bounds(const gmcmc_model * model, double * lower, double * upper) {
  *lower = model->lower_stepsize;
  *upper = model->upper_stepsize;
}

/**
 * Sets up parameter blocking.
 *
 * @param [in]  model        the model
 * @param [in]  num_blocks   the number of blocks (>= 1)
 * @param [in]  block_sizes  the size of each block (length num_blocks)
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if block_sizes does not sum to the number of parameters or if num_blocks is zero,
 *         GMCMC_ENOMEM if the block sizes could not be allocated in the model.
 */
int gmcmc_model_set_blocking(gmcmc_model * model, size_t num_blocks,
                             const size_t * block_sizes) {
  if (num_blocks == 0)
    GMCMC_ERROR("num_blocks cannot be zero", GMCMC_EINVAL);

  size_t * new_block_sizes = NULL;

  // Check that the requested blocking is valid

  // The block sizes should sum to the number of parameters
  size_t sum = 0;
  for (size_t i = 0; i < num_blocks; i++)
    sum += block_sizes[i];
  if (sum != model->n)
    GMCMC_ERROR("Invalid block sizes", GMCMC_EINVAL);

  if ((new_block_sizes = malloc(num_blocks * sizeof(size_t))) == NULL)
    GMCMC_ERROR("Failed to allocate new block sizes", GMCMC_ENOMEM);
  memcpy(new_block_sizes, block_sizes, num_blocks * sizeof(size_t));

  // Update the blocks in the model
  free(model->block_sizes);
  model->num_blocks = num_blocks;
  model->block_sizes = new_block_sizes;

  return 0;
}

/**
 * Gets the number of blocks to use when updating parameters.
 *
 * @param [in] model  the model
 *
 * @return the number of parameter blocks.
 */
size_t gmcmc_model_get_num_blocks(const gmcmc_model * model) {
  return model->num_blocks;
}

/**
 * Gets the size of a parameter block.
 *
 * @param [in] model  the model
 * @param [in] i      the index of the block
 *
 * @return the number of parameters in block i, or zero if i is out of range.
 */
size_t gmcmc_model_get_block_size(const gmcmc_model * model, size_t i) {
  if (i >= model->num_blocks)
    GMCMC_ERROR_VAL("Block index is out of range", GMCMC_EINVAL, 0);
  return model->block_sizes[i];
}

/**
 * Compares two arguments of type size_t.  For use in qsort.
 */
static int comparator(const void * x, const void * y) {
  const size_t * a = (const size_t *)x;
  const size_t * b = (const size_t *)y;
  if (*a < *b)
    return -1;
  else if (*a > *b)
    return 1;
  else
    return 0;
}

/**
 * Sets the fixed permutation of parameter indices to use when blocking.
 *
 * @param [in]  model        the model
 * @param [in]  blocks       the indices of the parameters in each block (length
 *                             n, may be NULL for random blocking)
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if blocks is not a valid permutation of the parameter
 *                        indices,
 *         GMCMC_ENOMEM if the blocks could not be allocated in the model.
 */
int gmcmc_model_set_blocks(gmcmc_model * model, const size_t * blocks) {
  size_t * new_blocks = NULL;

  // The blocks should be a valid permutation of the parameter indices - this
  // is checked by sorting a copy of the blocks
  // Allocate an array for a copy of the new blocks
  if ((new_blocks = malloc(model->n * sizeof(size_t))) == NULL) {
    free(new_blocks);
    GMCMC_ERROR("Failed to allocate new block indices", GMCMC_ENOMEM);
  }
  // Copy the blocks into the new array
  memcpy(new_blocks, blocks, model->n * sizeof(size_t));

  // Sort the copy
  qsort(new_blocks, model->n, sizeof(size_t), comparator);
  // Check that for each parameter index i, the block index matches
  for (size_t i = 0; i < model->n; i++) {
    if (i != new_blocks[i]) {
      free(new_blocks);
      GMCMC_ERROR("Block indices are invalid", GMCMC_EINVAL);
    }
  }

  // Recopy the permutation of the blocks over the sorted blocks
  memcpy(new_blocks, blocks, model->n * sizeof(size_t));

  // Update the blocks in the model
  free(model->blocks);
  model->blocks = new_blocks;

  return 0;
}

/**
 * Gets the fixed permutation of parameter indices to use when blocking.
 *
 * @param [in] model  the model
 *
 * @return the permutation of parameter indices, or NULL for random blocking.
 */
const size_t * gmcmc_model_get_blocks(const gmcmc_model * model) {
  return model->blocks;
}

/**
 * Stores a pointer to any model-specific data and functions in the model.
 *
 * @param [in,out] model          the model
 * @param [in]     modelspecific  model-specific data and functions (may be NULL)
 */
void gmcmc_model_set_modelspecific(gmcmc_model * model, void * modelspecific) {
  model->modelspecific = modelspecific;
}

/**
 * Gets a pointer to the model-specific data and functions.
 *
 * @param [in] model  the model
 *
 * @return a pointer to the model-specific data and functions.
 */
const void * gmcmc_model_get_modelspecific(const gmcmc_model * model) {
  return model->modelspecific;
}
