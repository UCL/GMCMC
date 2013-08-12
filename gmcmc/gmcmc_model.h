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
#include <gmcmc/gmcmc_dataset.h>

/**
 * A model.
 */
typedef struct gmcmc_model gmcmc_model;

/**
 * Calculates the proposal mean vector and covariance matrix based on the
 * likelihood.
 *
 * @param [in]  n            size of the parameter vector
 * @param [in]  params       parameter vector
 * @param [in]  likelihood   likelihood value
 * @param [in]  temperature  chain temperature
 * @param [in]  stepsize     parameter step size
 * @param [in]  serdata      serialised data output from the likelihood function
 * @param [out] mean         mean vector
 * @param [out] covariance   covariance matrix
 * @param [in]  ldc          leading dimension of the covariance matrix
 *
 * @return 0 on success, non-zero on error.
 */
typedef int (*gmcmc_proposal_function)(size_t, const double *, double, double, double, const void *, double *, double *, size_t);

/**
 * Calculates the likelihood of the data given the model and parameters.
 *
 * @param [in]  data        the data
 * @param [in]  model       the model to evaluate
 * @param [in]  params      the current parameter values to evaluate the model
 * @param [in]  n           the number of parameters in the model
 * @param [out] likelihood  the log likelihood
 * @param [out] serdata     serialised data to be passed to the proposal function
 * @param [out] size        size of serialised data object, in bytes
 *
 * @return 0 on success, non-zero on error.
 */
typedef int (*gmcmc_likelihood_function)(const gmcmc_dataset *, const gmcmc_model *, const double *, double *, void **, size_t *);

/**
 * Creates a model.
 *
 * @param [out] model       the model to create
 * @param [in]  n           the number of parameters in the model
 * @param [in]  priors      an array of prior distributions for each parameter
 * @param [in]  proposal    a function to calculate the proposal mean and variance
 * @param [in]  likelihood  a function to calculate the likelihood
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_model_create(gmcmc_model **, size_t, gmcmc_distribution **,
                       gmcmc_proposal_function, gmcmc_likelihood_function);

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
 * @return 0 on success, non-zero on error.
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
 * @return the prior for the parameter or NULL if the i is out of range.
 */
const gmcmc_distribution * gmcmc_model_get_prior(const gmcmc_model *, size_t);

/**
 * Calculates the proposal mean vector and covariance matrix based on the
 * likelihood.
 *
 * @param [in]  model        the model
 * @param [in]  params       parameter vector
 * @param [in]  likelihood   likelihood value
 * @param [in]  temperature  chain temperature
 * @param [in]  stepsize     parameter step size
 * @param [in]  serdata      serialised data output from the likelihood function
 * @param [out] mean         mean vector
 * @param [out] covariance   covariance matrix
 * @param [in]  ldc          leading dimension of the covariance matrix
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_proposal(const gmcmc_model *, const double *, double, double, double, const void *, double *, double *, size_t);

/**
 * Calculates the likelihood of the data given the model and parameters.
 *
 * @param [in]  data        the data
 * @param [in]  model       the model to evaluate
 * @param [in]  params      the current parameter values to evaluate the model
 * @param [out] likelihood  the log likelihood
 * @param [out] serdata     serialised data to be passed to the proposal function
 * @param [out] size        size of serialised data object, in bytes
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_likelihood(const gmcmc_dataset *, const gmcmc_model *, const double *, double *, void **, size_t *);

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
 * Stores a pointer to any model-specific data and functions in the model.
 *
 * @param [in,out] model          the model
 * @param [in]    modelspecific  model-specific data and functions (may be NULL)
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
