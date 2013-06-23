#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>

/**
 * A model.
 */
struct gmcmc_model {
  double * params;                      /**< Initial parameter values (may be NULL) */
  gmcmc_distribution ** priors;         /**< A prior distribution for each parameter */
  gmcmc_proposal_function proposal;     /**< Proposal function */
  gmcmc_likelihood_function likelihood; /**< Likelihood function */
  size_t n;                             /**< Number of parameters in model */
  double stepsize;                      /**< Parameter stepsize (default 0.05) */
  void * modelspecific;                 /**< Model specific parameters and data (may be NULL) */
};

/**
 * Creates a model.
 *
 * @param [out] model       the model to create
 * @param [in]  n           the number of parameters in the model
 * @param [in]  priors      an array of prior distributions for each parameter
 * @param [in]  proposal    a function to calculate the proposal mean and variance
 * @param [in]  likelihood  a function to calculate the likelihood
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there was not enough memory to allocate another model.
 */
int gmcmc_model_create(gmcmc_model ** model, size_t n, gmcmc_distribution ** priors,
                       gmcmc_proposal_function proposal, gmcmc_likelihood_function likelihood) {
  if ((*model = malloc(sizeof(gmcmc_model))) == NULL)
    GMCMC_ERROR("Unable to allocate model", GMCMC_ENOMEM);

  if (((*model)->priors = malloc(n * sizeof(gmcmc_distribution *))) == NULL) {
    free(*model);
    GMCMC_ERROR("Unable to allocate priors", GMCMC_ENOMEM);
  }

  int error;
  for (size_t i = 0; i < n; i++) {
    if ((error = gmcmc_distribution_create_copy(&(*model)->priors[i], priors[i])) != 0) {
      free((*model)->params);
      for (size_t j = 0; j < i; j++)
        gmcmc_distribution_destroy((*model)->priors[i]);
      free(*model);
      GMCMC_ERROR("Unable to copy priors into model", error);
    }
  }

  (*model)->params = NULL;
  (*model)->proposal = proposal;
  (*model)->likelihood = likelihood;
  (*model)->n = n;
  (*model)->stepsize = 0.05;
  (*model)->modelspecific = NULL;

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
 *         GMCMC_ENOMEM if there is not enough memory to copy the parameters
 *                        into the model.
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
 * @return the prior for the parameter or NULL if the i is out of range.
 */
const gmcmc_distribution * gmcmc_model_get_prior(const gmcmc_model * model, size_t i) {
  if (i > model->n)
    return NULL;
  return model->priors[i];
}

// int gmcmc_model_set_blocking(gmcmc_model *, int **, const int *, int);
// int gmcmc_model_get_block(const gmcmc_model *, int **, int *, int);

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
