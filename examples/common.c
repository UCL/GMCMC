#include "common.h"
#include <stdio.h>
#include <string.h>
#include "gmcmc/gmcmc_errno.h"

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

static inline bool is_null(const struct option opt) {
  return (opt.name == NULL && opt.has_arg == 0 && opt.flag == NULL && opt.val == 0);
}

static inline size_t optlen(const struct option * opts) {
  size_t len = 0;
  while (!is_null(opts[len]))
    len++;
  return len;
}

int parse_options(int argc, char * argv[], gmcmc_popmcmc_options * options, const char ** data_file,
                  const char * ext_optstring, const struct option * ext_longopts,
                  int (*parse_extra)(int, const char *, void *), void (*print_extra)(FILE *), void * extra) {
  int help = 0;

  const char * std_optstring = "t:b:p:a:u:l:d:h";
  const struct option std_longopts[] = {
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

  char * optstring;
  if (ext_optstring != NULL) {
    const size_t stdlen = strlen(std_optstring), extlen = strlen(ext_optstring);
    if ((optstring = malloc((stdlen + extlen + 1) * sizeof(char))) == NULL)
      GMCMC_ERROR("Failed to allocate optstring", GMCMC_ENOMEM);
    memcpy(optstring, std_optstring, stdlen * sizeof(char));
    memcpy(&optstring[stdlen], ext_optstring, extlen * sizeof(char));
    optstring[stdlen + extlen - 1] = '\0';
  }
  else {
    const size_t stdlen = strlen(std_optstring);
    if ((optstring = malloc((stdlen + 1) * sizeof(char))) == NULL)
      GMCMC_ERROR("Failed to allocate optstring", GMCMC_ENOMEM);
    memcpy(optstring, std_optstring, stdlen * sizeof(char));
    optstring[stdlen - 1] = '\0';
  }

  struct option * longopts;
  if (ext_longopts != NULL) {
    const size_t stdlen = optlen(std_longopts), extlen = optlen(ext_longopts);
    if ((longopts = malloc((stdlen + extlen + 1) * sizeof(struct option))) == NULL) {
      free(optstring);
      GMCMC_ERROR("Failed to allocate options", GMCMC_ENOMEM);
    }
    memcpy(longopts, std_longopts, stdlen * sizeof(struct option));
    memcpy(&longopts[stdlen], ext_longopts, extlen * sizeof(struct option));
    longopts[stdlen + extlen - 1] = (struct option){ NULL, 0, NULL, 0 };
  }
  else {
    const size_t stdlen = optlen(std_longopts);
    if ((longopts = malloc((stdlen + 1) * sizeof(struct option))) == NULL) {
      free(optstring);
      GMCMC_ERROR("Failed to allocate options", GMCMC_ENOMEM);
    }
    memcpy(longopts, std_longopts, stdlen * sizeof(struct option));
    longopts[stdlen - 1] = (struct option){ NULL, 0, NULL, 0 };
  }

  int c, longindex;
  opterr = 0;
  while ((c = getopt_long(argc, argv, optstring, longopts, &longindex)) != -1) {
    switch (c) {
      case 'd':
        *data_file = optarg;
        break;
      case 't':
        if (sscanf(optarg, "%u", &options->num_temperatures) != 1) {
          fprintf(stderr, "Invalid number of temperatures: %s\n", optarg);
          free(optstring);
          free(longopts);
          return -optind;
        }
        break;
      case 'b':
        if (sscanf(optarg, "%zu", &options->num_burn_in_samples) != 1) {
          fprintf(stderr, "Invalid number of burn-in samples: %s\n", optarg);
          free(optstring);
          free(longopts);
          return -optind;
        }
        break;
      case 'p':
        if (sscanf(optarg, "%zu", &options->num_posterior_samples) != 1) {
          fprintf(stderr, "Invalid number of posterior samples: %s\n", optarg);
          free(optstring);
          free(longopts);
          return -optind;
        }
        break;
      case 'a':
        if (sscanf(optarg, "%u", &options->adapt_rate) != 1) {
          fprintf(stderr, "Invalid adapt rate: %s\n", optarg);
          free(optstring);
          free(longopts);
          return -optind;
        }
        break;
      case 'u':
        if (sscanf(optarg, "%lf", &options->upper_acceptance_rate) != 1) {
          fprintf(stderr, "Invalid upper limit: %s\n", optarg);
          free(optstring);
          free(longopts);
          return -optind;
        }
        break;
      case 'l':
        if (sscanf(optarg, "%lf", &options->lower_acceptance_rate) != 1) {
          fprintf(stderr, "Invalid lower limit: %s\n", optarg);
          free(optstring);
          free(longopts);
          return -optind;
        }
        break;
      case 'h':
        help = 1;
        break;
//       case '?':
//         fprintf(stderr, "Unknown option: %s\n", optarg);
//         return optind;
      default:
        if (parse_extra != NULL && parse_extra(c, optarg, extra) == '?') {
          fprintf(stderr, "Unknown option: %s\n", optarg);
          free(optstring);
          free(longopts);
          return optind;
        }
        else {
          fprintf(stdout, "Usage: %s [option1,option2,...optionN] [burn_in_file] posterior_file\n"
                          "where valid options are:\n"
                          "  --num_temperatures|-t=<n>       the number of temperatures to use\n"
                          "  --num_burn_in_samples|-b=<n>    the number of samples to discard as burn-in\n"
                          "  --num_posterior_samples|-p=<n>  the number of posterior samples to generate\n"
                          "  --adapt_rate|-a=<n>             how often to adapt the step sizes for parameter proposals\n"
                          "  --upper_acceptance_rate|-u=<z>  the upper limit on the acceptance rate (increase the step size when the acceptance rate is above this value)\n"
                          "  --lower_acceptance_rate|-l=<z>  the lower limit on the acceptance rate (reduce the step size when the acceptance rate is below this value)\n", argv[0]);
          if (print_extra != NULL)
            print_extra(stdout);
          free(optstring);
          free(longopts);
          return -1;
        }
    }
  }

  if (optind >= argc || help == 1) {
        fprintf(stdout, "Usage: %s [option1,option2,...optionN] [burn_in_file] posterior_file\n"
                        "where valid options are:\n"
                        "  --num_temperatures|-t=<n>       the number of temperatures to use\n"
                        "  --num_burn_in_samples|-b=<n>    the number of samples to discard as burn-in\n"
                        "  --num_posterior_samples|-p=<n>  the number of posterior samples to generate\n"
                        "  --adapt_rate|-a=<n>             how often to adapt the step sizes for parameter proposals\n"
                        "  --upper_acceptance_rate|-u=<z>  the upper limit on the acceptance rate (increase the step size when the acceptance rate is above this value)\n"
                        "  --lower_acceptance_rate|-l=<z>  the lower limit on the acceptance rate (reduce the step size when the acceptance rate is below this value)\n", argv[0]);
        if (print_extra != NULL)
          print_extra(stdout);
          free(optstring);
          free(longopts);
    return 1;
  }

  free(optstring);
  free(longopts);

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
