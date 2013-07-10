#include "acceptance.h"
#include <stdio.h>

void acceptance_monitor(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
                        GMCMC_ITERATION iteration, size_t i, const double * accepts,
                        const double * exchanges, const double * stepsizes) {
  (void)model;

  if (iteration == GMCMC_BURN_IN) {
    fprintf(stderr, "Burn in iteration: %zu of %zu\n\n", i, options->num_burn_in_samples);

    // Display summary information for each chain
    fputs("Parameter acceptance rates:\n", stderr);
    for (size_t j = 0; j < options->num_temperatures; j++)
      fprintf(stderr, "%15.6f", accepts[j]);
    fputs("\n\n", stderr);

    fputs("Parameter stepsizes:\n", stderr);
    for (size_t j = 0; j < options->num_temperatures; j++)
      fprintf(stderr, "%15.6f", stepsizes[j]);
    fputs("\n\n", stderr);

    // Display exchange rate
    fputs("Model parameter exchange ratios:\n", stderr);
    for (size_t j = 0; j < options->num_temperatures; j++)
      fprintf(stderr, "%15.6f", exchanges[j]);
    fputs("\n\n\n", stderr);
  }
  else
    fprintf(stderr, "Posterior iteration: %zu of %zu\n\n", i, options->num_posterior_samples);
}
