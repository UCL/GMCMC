#include <gmcmc/gmcmc_popmcmc.h>
#include <gmcmc/gmcmc_model.h>
#include <stddef.h>

/**
 * How often to save posterior samples.
 */
#define POSTERIOR_SAVE_SIZE 1000

/**
 * Where to write the samples to.
 */
extern const char * outputID;

/**
 * Stores a sample in a global array that is later written to a Matlab file.
 *
 * @param [in] options         the MCMC options
 * @param [in] model           the model
 * @param [in] iteration       whether the current iteration is from burn in
 *                               (GMCMC_BURN_IN) or posterior (GMCMC_POSTERIOR)
 * @param [in] i               the current iteration number
 * @param [in] j               the index on the temperature scale
 * @param [in] params          the current parameter values
 * @param [in] log_prior       the log prior of the sample
 * @param [in] log_likelihood  the log likelihood of the sample
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the Matlab
 *                         structure array,
 *         GMCMC_EIO     if there was an error writing the Matlab structure
 *                         array to a file.
 */
int write_matlab(const gmcmc_popmcmc_options *, const gmcmc_model *,
                 GMCMC_ITERATION, size_t, size_t,
                 const double *, const double *, double);
