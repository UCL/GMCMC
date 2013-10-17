/*
 * gmcmc_model.h
 *
 * Defines a GMCMC model with proposal and likelihood functions.
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_MODEL_H
#define GMCMC_MODEL_H

#include <gmcmc/gmcmc_distribution.h>

/**
 * A model.
 */
typedef struct gmcmc_model gmcmc_model;

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
int gmcmc_model_create(gmcmc_model **, size_t, gmcmc_distribution **);

/**
 * Destroys a model.
 *
 * @param [in] model  the model to destroy.
 */
void gmcmc_model_destroy(gmcmc_model *);

/**
 * Gets the number of parameters in the model.
 *
 * @param [in] model  the model
 *
 * @return the number of parameters in the model.
 */
size_t gmcmc_model_get_num_params(const gmcmc_model *);

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
int gmcmc_model_set_params(gmcmc_model *, const double *);

/**
 * Gets a pointer to the initial parameter values.
 *
 * @param [in] model  the model
 *
 * @return a pointer to the initial parameter values.
 */
const double * gmcmc_model_get_params(const gmcmc_model *);

/**
 * Gets a pointer to the priors for each parameter.
 *
 * @param [in] model  the model
 * @param [in] i      the parameter index
 *
 * @return the prior for the ith parameter or NULL if the i is out of range.
 */
const gmcmc_distribution * gmcmc_model_get_prior(const gmcmc_model *, size_t);

/**
 * Sets the parameter stepsize.
 *
 * @param [in] model     the model
 * @param [in] stepsize  the stepsize
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if the stepsize is less than or equal to zero.
 */
int gmcmc_model_set_stepsize(gmcmc_model *, double);

/**
 * Gets the parameter stepsize.
 *
 * @param [in] model  the model
 *
 * @return the parameter stepsize.
 */
double gmcmc_model_get_stepsize(const gmcmc_model *);

/**
 * Sets the upper and lower limits for adapting stepsizes.
 *
 * @param [in] model  the model
 * @param [in] lower  the lower bound for the stepsizes
 * @param [in] upper  the upper bound for the stepsizes
 *
 * @return 0 on success, GMCMC_EINVAL if lower is greater than upper.
 */
int gmcmc_model_set_stepsize_bounds(gmcmc_model *, double, double);

/**
 * Gets the upper and lower limits for adapting stepsizes.
 *
 * @param [in]  model  the model
 * @param [out] lower  the lower bound for the stepsizes
 * @param [out] upper  the upper bound for the stepsizes
 */
void gmcmc_model_get_stepsize_bounds(const gmcmc_model *, double *, double *);

/**
 * Sets up parameter blocking.
 *
 * @param [in]  model        the model
 * @param [in]  num_blocks   the number of blocks (zero for no blocking)
 * @param [in]  block_sizes  the size of each block (length num_blocks, may be
 *                             NULL if num_blocks is zero)
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if block_sizes does not sum to the number of parameters,
 *         GMCMC_ENOMEM if the block sizes could not be allocated in the model.
 */
int gmcmc_model_set_blocking(gmcmc_model *, size_t, const size_t *);

/**
 * Gets the number of blocks to use when updating parameters.  If zero, the
 * parameters are to be updated together in one block.
 *
 * @param [in] model  the model
 *
 * @return the number of parameter blocks.
 */
size_t gmcmc_model_get_num_blocks(const gmcmc_model *);

/**
 * Gets the size of a parameter block.
 *
 * @param [in] model  the model
 * @param [in] i      the index of the block
 *
 * @return the number of parameters in block i, or zero if i is out of range.
 */
size_t gmcmc_model_get_block_size(const gmcmc_model *, size_t);

/**
 * Sets the fixed permutation of parameter indices to use when blocking.
 *
 * @param [in]  model        the model
 * @param [in]  blocks       the indices of the parameters in each block (length
 *                             num_params, may be NULL for random blocking)
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if blocks is not a valid permutation of the parameter
 *                        indices,
 *         GMCMC_ENOMEM if the blocks could not be allocated in the model.
 */
int gmcmc_model_set_blocks(gmcmc_model *, const size_t *);

/**
 * Gets the fixed permutation of parameter indices to use when blocking.
 *
 * @param [in] model  the model
 *
 * @return the permutation of parameter indices, or NULL for random blocking.
 */
const size_t * gmcmc_model_get_blocks(const gmcmc_model *);

/**
 * Stores a pointer to any model-specific data and functions in the model.
 *
 * @param [in,out] model          the model
 * @param [in]     modelspecific  model-specific data and functions (may be NULL)
 */
void gmcmc_model_set_modelspecific(gmcmc_model *, void *);

/**
 * Gets a pointer to the model-specific data and functions.
 *
 * @param [in] model  the model
 *
 * @return a pointer to the model-specific data and functions.
 */
const void * gmcmc_model_get_modelspecific(const gmcmc_model *);

#endif /* GMCMC_MODEL_H */
