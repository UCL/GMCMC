#include <gmcmc/gmcmc_ion.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>

/**
 * Ion Channel model-specific data.
 *
 * In addition to data common to all models, ion channel models have a Q matrix
 * which details the transitions between open and closed states.
 */
struct gmcmc_ion_model {
  /**
   * Number of closed and open states in the model.
   */
  unsigned int closed, open;

  /**
   * Function to update the Q matrix based on the current parameter values.
   */
  gmcmc_ion_calculate_Q_matrix calculate_Q_matrix;
};

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
int gmcmc_ion_model_create(gmcmc_ion_model ** ion_model,
                           unsigned int closed, unsigned int open,
                           gmcmc_ion_calculate_Q_matrix calculate_Q_matrix) {
  if (calculate_Q_matrix == NULL)
    GMCMC_ERROR("calculate_Q_matrix is NULL", GMCMC_EINVAL);

  if ((*ion_model = malloc(sizeof(gmcmc_ion_model))) == NULL)
    GMCMC_ERROR("Unable to allocate Ion Channel model", GMCMC_ENOMEM);

  (*ion_model)->closed = closed;
  (*ion_model)->open = open;
  (*ion_model)->calculate_Q_matrix = calculate_Q_matrix;

  return 0;
}

/**
 * Destroys the Ion Channel model-specific data.
 *
 * @param [in] ion_model  the Ion Channel model-specific data object to destroy
 */
void gmcmc_ion_model_destroy(gmcmc_ion_model * ion_model) {
  free(ion_model);
}

/**
 * Gets the number of closed states in the model.
 *
 * @param [in] ion_model  the ion channel model
 *
 * @return the number of closed states in the model.
 */
unsigned int gmcmc_ion_model_get_num_closed_states(const gmcmc_ion_model * ion_model) {
  return ion_model->closed;
}

/**
 * Gets the number of open states in the model.
 *
 * @param [in] ion_model  the ion channel model
 *
 * @return the number of open states in the model.
 */
unsigned int gmcmc_ion_model_get_num_open_states(const gmcmc_ion_model * ion_model) {
  return ion_model->open;
}

/**
 * Calculates the Q matrix for an ion channel model.
 *
 * @param [in]  ion_model  the ion channel model
 * @param [in]  params     the parameter values to use to calculate the Q matrix
 * @param [out] Q          the Q matrix
 * @param [in]  ldq        leading dimension of the Q matrix
 */
void gmcmc_ion_model_calculate_Q_matrix(const gmcmc_ion_model * ion_model,
                                        const double * params, double * Q,
                                        size_t ldq) {
  ion_model->calculate_Q_matrix(params, Q, ldq);
}
