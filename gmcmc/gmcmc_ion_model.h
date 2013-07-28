#ifndef GMCMC_ION_MODEL_H
#define GMCMC_ION_MODEL_H

#include <gmcmc/gmcmc_model.h>

/**
 * Ion Channel model-specific data.
 *
 * In addition to data common to all models, ion channel models have a Q matrix
 * which details the transitions between open and closed states.
 */
typedef struct gmcmc_ion_model gmcmc_ion_model;

/**
 * Ion Channel model proposal function using Metropolis-Hastings.
 */
extern const gmcmc_proposal_function gmcmc_ion_proposal_mh;

/**
 * Ion Channel model likelihood function using Metropolis-Hastings.
 */
extern const gmcmc_likelihood_function gmcmc_ion_likelihood_mh;

/**
 * Creates an Ion Channel model-specific data object.
 *
 * @param [out] ion_model           the Ion Channel model
 * @param [in]  closed              the number of closed states in the model
 * @param [in]  open                the number of open states in the model
 * @param [in]  calculate_Q_matrix  a function to calculate the Q matrix based
 *                                    on the current parameter values.  The
 *                                    closed states are presumed to be stored in
 *                                    the top-left of the matrix and the open
 *                                    states in the bottom-right
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if calculate_Q_matrix is NULL, or
 *         GMCMC_ENOMEM if there is not enough memory to create the data object.
 */
int gmcmc_ion_model_create(gmcmc_ion_model **, unsigned int, unsigned int, void (*)(const double *, double *, size_t));

/**
 * Destroys the Ion Channel model-specific data.
 *
 * @param [in] ion_model  the Ion Channel model-specific data object to destroy
 */
void gmcmc_ion_model_destroy(gmcmc_ion_model *);

#endif /* GMCMC_ION_MODEL_H */
