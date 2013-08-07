#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_popmcmc.h>
#include <stddef.h>
#include <stdio.h>

/**
 * Acceptance callback.
 *
 * @param [in] options     the MCMC options
 * @param [in] model       the model
 * @param [in] i           the iteration number
 * @param [in] acceptance  the acceptance ratios for each temperature
 * @param [in] exchange    the exchange ratios for each temerature
 * @param [in] stepsizes   the step sizes for each temperature
 */
void acceptance_monitor(const gmcmc_popmcmc_options *, const gmcmc_model *,
                        size_t, const double *,
                        const double *, const double *);

/**
 * Read the options for the population MCMC simulation from the command line
 * arguments.
 *
 * @param [in]  argc       the number of command line arguments
 * @param [in]  args       the command line arguments
 * @param [out] options    the options object to populate
 * @param [out] data_file  the dataset file name
 *
 * @return n = 0 if all the options and arguments were successfully parsed
 *         n < 0 if there was an unrecognised option at position n
 *         n > 0 if there was an invalid argument was given to option n.
 */
int parse_options(int argc, char * argv[], gmcmc_popmcmc_options * options, const char ** data_file);

void print_options(FILE *, const gmcmc_popmcmc_options *);
