#ifndef GMCMC_ION_MODEL_H
#define GMCMC_ION_MODEL_H

#include <gmcmc/gmcmc_model.h>

/**
 * Ion channel model-specific data.
 *
 * In addition to data common to all models, ion channel models have a Q matrix
 * which details the transitions between open and closed states.
 */
typedef struct gmcmc_ion_model gmcmc_ion_model;

/**
 * Ion channel model proposal function using Metropolis-Hastings.
 */
extern const gmcmc_proposal_function gmcmc_ion_proposal_mh;

/**
 * Ion channel model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_ion_likelihood_mh;

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

#endif /* GMCMC_ION_MODEL_H */
