#include "common.h"
#include <stdio.h>
#include <getopt.h>

void acceptance_monitor(const gmcmc_popmcmc_options * options, const gmcmc_model * model,
                        size_t i, const double * accepts,
                        const double * exchanges, const double * stepsizes) {
  const size_t num_blocks = gmcmc_model_get_num_blocks(model);

  if (i < options->num_burn_in_samples) {
    fprintf(stderr, "Burn in iteration: %zu of %zu\n\n", i, options->num_burn_in_samples);

    // Display summary information for each chain
    for (size_t j = 0; j < options->num_temperatures; j++) {
      fprintf(stderr, "Chain %zu:\nTemperature: %15.6f\n\n", j, options->temperatures[j]);

      fputs("Parameter acceptance rates:\n", stderr);
      for (size_t k = 0; k < num_blocks; k++)
        fprintf(stderr, "%15.6f", accepts[j * num_blocks + k]);
      fputs("\n\n", stderr);

      fputs("Parameter stepsizes:\n", stderr);
      for (size_t k = 0; k < num_blocks; k++)
        fprintf(stderr, "%15.6f", stepsizes[j * num_blocks + k]);
      fputs("\n\n", stderr);

      // Display exchange rate
      fputs("Model parameter exchange ratio:\n", stderr);
      fprintf(stderr, "%15.6f", exchanges[j]);
      fputs("\n\n\n", stderr);
    }
  }
  else
    fprintf(stderr, "Posterior iteration: %zu of %zu\n\n", i - options->num_burn_in_samples, options->num_posterior_samples);
}

int parse_options(int argc, char * argv[], gmcmc_popmcmc_options * options, const char ** data_file) {
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
        *data_file = optarg;
        break;
      case 't':
        if (sscanf(optarg, "%u", &options->num_temperatures) != 1) {
          fprintf(stderr, "Invalid number of temperatures: %s\n", optarg);
          return -optind;
        }
        break;
      case 'b':
        if (sscanf(optarg, "%zu", &options->num_burn_in_samples) != 1) {
          fprintf(stderr, "Invalid number of burn-in samples: %s\n", optarg);
          return -optind;
        }
        break;
      case 'p':
        if (sscanf(optarg, "%zu", &options->num_posterior_samples) != 1) {
          fprintf(stderr, "Invalid number of posterior samples: %s\n", optarg);
          return -optind;
        }
        break;
      case 'a':
        if (sscanf(optarg, "%u", &options->adapt_rate) != 1) {
          fprintf(stderr, "Invalid adapt rate: %s\n", optarg);
          return -optind;
        }
        break;
      case 'u':
        if (sscanf(optarg, "%lf", &options->upper_acceptance_rate) != 1) {
          fprintf(stderr, "Invalid upper limit: %s\n", optarg);
          return -optind;
        }
        break;
      case 'l':
        if (sscanf(optarg, "%lf", &options->lower_acceptance_rate) != 1) {
          fprintf(stderr, "Invalid lower limit: %s\n", optarg);
          return -optind;
        }
        break;
      case 'h':
        help = 1;
        break;
      case '?':
        fprintf(stderr, "Unknown option: %s\n", optarg);
        return optind;
      default:
        fprintf(stdout, "Usage: %s [option1,option2,...optionN] [burn_in_file] posterior_file\n"
                        "where valid options are:\n"
                        "  --num_temperatures|-t=<n>\tthe number of temperatures to use\n"
                        "  --num_burn_in_samples|-b=<n>\tthe number of samples to discard as burn-in\n"
                        "  --num_posterior_samples|-p=<n>\tthe number of posterior samples to generate\n"
                        "  --adapt_rate|-a=<n>\thow often to adapt the step sizes for parameter proposals\n"
                        "  --upper_acceptance_rate|-u=<z>\tthe upper limit on the acceptance rate (increase the step size when the acceptance rate is above this value)\n"
                        "  --lower_acceptance_rate|-l=<z>\tthe lower limit on the acceptance rate (reduce the step size when the acceptance rate is below this value)\n", argv[0]);
        return -1;
    }
  }

  if (optind >= argc || help == 1) {
        fprintf(stdout, "Usage: %s [option1,option2,...optionN] [burn_in_file] posterior_file\n"
                        "where valid options are:\n"
                        "  --num_temperatures|-t=<n>\tthe number of temperatures to use\n"
                        "  --num_burn_in_samples|-b=<n>\tthe number of samples to discard as burn-in\n"
                        "  --num_posterior_samples|-p=<n>\tthe number of posterior samples to generate\n"
                        "  --adapt_rate|-a=<n>\thow often to adapt the step sizes for parameter proposals\n"
                        "  --upper_acceptance_rate|-u=<z>\tthe upper limit on the acceptance rate (increase the step size when the acceptance rate is above this value)\n"
                        "  --lower_acceptance_rate|-l=<z>\tthe lower limit on the acceptance rate (reduce the step size when the acceptance rate is below this value)\n", argv[0]);
    return 1;
  }

  return 0;
}

void print_options(FILE * stream, const gmcmc_popmcmc_options * options) {
  fprintf(stream, "Number of temperatures: %u\n", options->num_temperatures);
  fputs("Temperature scale:", stream);
  for (unsigned int i = 0; i < options->num_temperatures; i++)
    fprintf(stream, "%15.6f", options->temperatures[i]);
  fputs("\n", stream);
  fprintf(stream, "Number of burn-in samples: %zu\n", options->num_burn_in_samples);
  fprintf(stream, "Number of posterior samples: %zu\n", options->num_posterior_samples);
  fprintf(stream, "Step size adapt rate: %u\n", options->adapt_rate);
  fprintf(stream, "Upper acceptance rate: %1.4f\n", options->upper_acceptance_rate);
  fprintf(stream, "Lower acceptance rate: %1.4f\n", options->lower_acceptance_rate);
}
