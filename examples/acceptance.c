#include "acceptance.h"
#include <stdio.h>

void acceptance_monitor(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
                        size_t i, const double * accepts,
                        const double * exchanges, const double * stepsizes) {
  (void)model;

  if (i < options->num_burn_in_samples) {
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
    fprintf(stderr, "Posterior iteration: %zu of %zu\n\n", i - options->num_burn_in_samples, options->num_posterior_samples);
}

int parse_options(int argc, char * argv[], gmcmc_popmcmc_options * options) {
  int help = 0;
  struct option long_options[] = {
    { "num_temperatures",      required_argument, NULL, 't' },
    { "num_burn_in_samples",   required_argument, NULL, 'b' },
    { "num_posterior_samples", required_argument, NULL, 'p' },
    { "adapt_rate",            required_argument, NULL, 'a' },
    { "upper_acceptance_rate", required_argument, NULL, 'u' },
    { "lower_acceptance_rate", required_argument, NULL, 'l' },
    { "dataset",               required_argument, NULL, 'd' },
    { "help",                  no_argument,      &help,  1  },
    { NULL, 0, NULL, 0 }
  };

  int c, option_index;
  opterr = 0;
  while ((c = getopt_long(argc, argv, "t:b:p:a:u:l:d:h", long_options, &option_index)) != -1) {
    switch (c) {
      case 'd':
        data_file = optarg;
        break;
      case 't':
        if (sscanf(optarg, "%u", options->num_temperatures) != 1) {
          fprintf(stderr, "Invalid number of temperatures samples: %s\n", optarg);
          return optind;
        }
        break;
      case 'b':
        if (sscanf(optarg, "%zu", options->num_burn_in_samples) != 1) {
          fprintf(stderr, "Invalid number of burn-in samples: %s\n", optarg);
          return optind;
        }
        break;
      case 'p':
        if (sscanf(optarg, "%zu", options->num_posterior_samples) != 1) {
          fprintf(stderr, "Invalid number of posterior samples: %s\n", optarg);
          return optind;
        }
        break;
      case 'a':
        if (sscanf(optarg, "%u", options->adapt_rate) != 1) {
          fprintf(stderr, "Invalid adapt rate: %s\n", optarg);
          return optind;
        }
        break;
      case 'u':
        if (sscanf(optarg, "%lf", options->upper_acceptance_rate) != 1) {
          fprintf(stderr, "Invalid upper bound on acceptance rates: %s\n", optarg);
          return optind;
        }
        break;
      case 'l':
        if (sscanf(optarg, "%lf", options->lower_acceptance_rate) != 1) {
          fprintf(stderr, "Invalid lower bound on acceptance rates: %s\n", optarg);
          return optind;
        }
        break;
      case 'h':
        help = 1;
        break;
      case '?':
        fprintf(stderr, "Unknown option: %s\n", optarg);
      default:
        fprintf(stdout, "Usage: %s [--dataset|-d=<dataset>] output\n", argv[0]);
        return -1;
    }
  }

  if (optind >= argc || help == 1) {
    fprintf(stdout, "Usage: %s [--dataset|-d=<dataset>] output\n", argv[0]);
    return -1;
  }
}
