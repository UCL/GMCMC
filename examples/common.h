#include <gmcmc/gmcmc_popmcmc.h>
#include <stddef.h>
#include <stdio.h>
#include <getopt.h>

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
 * parse_extra is a function with the following signature:
 * int parse_extra(int c, const char *, void *)
 * where:
 *   c       is the option character,
 *   optarg  is the option argument,
 *   extra   is function state
 * It is expected to return 0 on success and '?' for an unrecognised option.
 *
 * @param [in]  argc       the number of command line arguments
 * @param [in]  args       the command line arguments
 * @param [out] options    the options object to populate
 * @param [out] data_file  the dataset file name
 * @param [in]  ext_optstring  extra single-character options to parse (may be NULL)
 * @param [in]  ext_longopts   extra long options to parse (may be NULL)
 * @param [in]  parse_extra    function to parse extra options (may be NULL)
 * @param [in]  print_extra    prints a description og the extra options to an
 *                               output stream (may be NULL)
 * @param [in]  extra          state for parse_extra (may be NULL)
 *
 * @return n = 0 if all the options and arguments were successfully parsed
 *         n < 0 if there was an unrecognised option at position n
 *         n > 0 if there was an invalid argument was given to option n.
 */
int parse_options(int, char **, gmcmc_popmcmc_options *, const char **,
                  const char *, const struct option *,
                  int (*)(int, const char *, void *), void (*)(FILE *), void *);

void print_options(FILE *, const gmcmc_popmcmc_options *);
