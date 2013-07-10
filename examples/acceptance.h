#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_popmcmc.h>
#include <stddef.h>

/**
 * Acceptance callback.
 *
 * @param [in] options     the MCMC options
 * @param [in] model       the model
 * @param [in] iteration   whether the current iteration is from burn in
 *                           (GMCMC_BURN_IN) or posterior (GMCMC_POSTERIOR)
 * @param [in] i           the iteration number
 * @param [in] acceptance  the acceptance ratios for each temperature
 * @param [in] exchange    the exchange ratios for each temerature
 * @param [in] stepsizes   the step sizes for each temperature
 */
void acceptance_monitor(const gmcmc_popmcmc_options *, const gmcmc_model *,
                        GMCMC_ITERATION, size_t, const double *,
                        const double *, const double *);
