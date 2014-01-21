#include "common.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

static inline void print_help(FILE * stream, const char * exe) {
  fprintf(stream, "Usage: %s [option1,option2,...optionN] [burn_in_file] posterior_file\n"
                  "where valid options are:\n"
                  "  --num_temperatures|-t=<n>       the number of temperatures to use\n"
                  "  --num_burn_in_samples|-b=<n>    the number of samples to discard as burn-in\n"
                  "  --num_posterior_samples|-p=<n>  the number of posterior samples to generate\n"
                  "  --adapt_rate|-a=<n>             how often to adapt the step sizes for parameter proposals\n"
                  "  --upper_acceptance_rate|-u=<z>  the upper limit on the acceptance rate (increase the step size when the acceptance rate is above this value)\n"
                  "  --lower_acceptance_rate|-l=<z>  the lower limit on the acceptance rate (reduce the step size when the acceptance rate is below this value)\n"
                  "  --blocking=<blocking-spec>      defines parameter blocking.  <blocking spec> is of the form <blocking-type>:<blocks> where <blocking-type> is\n"
                  "                                    \"fixed\" or \"f\" for fixed blocking or \"random\" or \"r\" for random blocking.\n"
                  "                                    For fixed blocking <blocks> is a semicolon-terminated list of blocks where each block contains a\n"
                  "                                    comma-separated list of parameters in the block (e.g. --blocking=\"fixed:0,1;2,3;\" specifies two blocks with\n"
                  "                                    parameters 0 and 1 in the first block and parameters 2 and 3 in the second).\n"
                  "                                    For random blocking <blocks is a semicolon-terminated list of block sizes (e.g. --blocking=\"random:2;1;\"\n"
                  "                                    specifies two random blocks of containing two and one parameters respectively.\n"
                  "                                    In both cases the final terminating semicolon may be omitted.\n", exe);
}

static int parse_blocks(const char * arg, size_t * num_blocks, size_t ** block_sizes, size_t ** params) {
  // Number of blocks, block sizes and block indices
  size_t n = 0, * ns = NULL, * is = NULL;

  // Find the index of the first ':'
  const char * colon;
  for (colon = arg; *colon != '\0'; colon++) {
    if (*colon == ':')
      break;
  }
  if (colon == arg)     // argument starts with a colon
    GMCMC_ERROR("Invalid block specification", GMCMC_EINVAL);

  if (strncmp(arg, "random", (size_t)(colon - arg)) == 0) {       // matches "random" and "r"
    // args is of the form:
    //   "random:2;1;",
    //   "random:2;1",
    //   "r:2;1;", or
    //   "r:2;1"
    // for 2 random blocks of size 2 and 1.

    // Shift pointer past colon to first block spec
    arg = colon + 1;

    // For random blocking set blocks to NULL (which it is) and initialise
    // block_sizes to NULL and num_blocks to zero (which they are)

    // In this loop c is the current character and num is a pointer to the start of a block size
    const char * num = arg, * c = arg;
    do {
      // If the current character is a ';' or is the end of string and there is still a number to parse
      if (*c == ';' || (*c == '\0' && num < c)) {
        // Increment number of blocks and expand block size array
        size_t * nns;
        if ((nns = realloc(ns, ++n * sizeof(size_t))) == NULL) {
          free(ns);
          GMCMC_ERROR("Failed to reallocate block sizes", GMCMC_ENOMEM);
        }
        ns = nns;

        // Read block size into last entry (sscanf stops on the first non-numerical character)
        if (sscanf(num, "%zu", &ns[n - 1]) != 1) {
          free(ns);
          GMCMC_ERROR("Failed to parse block size", GMCMC_EINVAL);
        }

        // Move pointer to start of next number (one beyond the ';' just read)
        num = c + 1;
      }
      else if (!isdigit(*c) && *c != '\0') {
        free(ns);
        GMCMC_ERROR("Invalid characters in block specification", GMCMC_EINVAL);
      }
    } while (*c++ != '\0');
  }
  else if (strncmp(arg, "fixed", (size_t)(colon - arg)) == 0 || *colon == '\0') {        // matches "fixed", "f" and no colon
    // args is of the form:
    //   "fixed:1,2;3;",
    //   "fixed:1,2;3",
    //   "f:1,2;3;",
    //   "f:1,2;3",
    //   "1,2;3;", or
    //   "1,2;3"
    // for 2 fixed blocks - the first containing parameters 1 and 2 and the
    // second containing parameter 3

    // Shift pointer past colon (if there was one) to first block spec
    if (*colon != '\0')
      arg = colon + 1;

    // In this loop c is the current character, num is a pointer to the start of
    // a block parameter and i is the pointer to the last element of the block array
    const char * num = arg, * c = arg;
    size_t i = 0, m = 0;
    do {
      // If the current character is a ',', a ';' or is the end of string and there is still a number to parse
      if (*c == ',' || *c == ';' || (*c == '\0' && num < c)) {
        size_t * nis;
        if ((nis = realloc(is, ++i * sizeof(size_t))) == NULL) {
          free(is);
          free(ns);
          GMCMC_ERROR("Failed to reallocate blocks", GMCMC_ENOMEM);
        }
        is = nis;

        // Read the parameter index into the last position in the block index array
        if (sscanf(num, "%zu", &is[i - 1]) != 1) {
          free(is);
          free(ns);
          GMCMC_ERROR("Failed to parse block index", GMCMC_EINVAL);
        }

        // Move pointer to start of next number (one beyond the ';' just read)
        num = c + 1;

        m++;

        if (*c == ';' || *c == '\0') {
          // Increment number of blocks and expand block size array
          size_t * nns;
          if ((nns = realloc(ns, ++n * sizeof(size_t))) == NULL) {
            free(is);
            free(ns);
            GMCMC_ERROR("Failed to reallocate block sizes", GMCMC_ENOMEM);
          }
          ns = nns;
          ns[n - 1] = m;
          m = 0;
        }
      }
      else if (!isdigit(*c) && *c != '\0') {
        free(ns);
        GMCMC_ERROR("Invalid characters in block specification", GMCMC_EINVAL);
      }
    } while (*c++ != '\0');
  }
  else
    GMCMC_ERROR("Invalid blocking type", GMCMC_EINVAL);

  *num_blocks = n;
  *block_sizes = ns;
  *params = is;

  return 0;
}

int parse_options(int argc, char * argv[],
                  const char * ext_optstring, const struct option * ext_longopts,
                  int (*parse_extra)(int, const char *, void *),
                  void (*print_extra)(FILE *), void * extra,
                  gmcmc_popmcmc_options * options, const char ** data_file,
                  size_t * num_blocks, size_t ** block_sizes, size_t ** blocks) {
  int help = 0;

  const char * std_optstring = "t:b:p:a:u:l:d:h";
  const struct option std_longopts[] = {
    { "num_temperatures",      required_argument, NULL, 't' },
    { "num_burn_in_samples",   required_argument, NULL, 'b' },
    { "num_posterior_samples", required_argument, NULL, 'p' },
    { "adapt_rate",            required_argument, NULL, 'a' },
    { "upper_acceptance_rate", required_argument, NULL, 'u' },
    { "lower_acceptance_rate", required_argument, NULL, 'l' },
    { "blocking",              required_argument, NULL,  2  },
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
      case 2:
        if (parse_blocks(optarg, num_blocks, block_sizes, blocks) != 0) {
          fprintf(stderr, "Failed to parse parameter blocking from: %s\n", optarg);
          free(optstring);
          free(longopts);
          return -optind;
        }
        break;
      case 'h':
      case 1:
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
          print_help(stdout, argv[0]);
          if (print_extra != NULL)
            print_extra(stdout);
          free(optstring);
          free(longopts);
          return -1;
        }
    }
  }

  if (optind >= argc || help == 1) {
    print_help(stdout, argv[0]);
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

void print_blocks(FILE * stream, const size_t num_blocks, const size_t * block_sizes, const size_t * blocks) {
  fputs("Blocks:\n", stream);
  if (blocks == NULL) {
    for (size_t i = 0; i < num_blocks; i++)
      fprintf(stream, "        block %2zu: random %zu\n", i + 1, block_sizes[i]);
  }
  else {
    for (size_t i = 0; i < num_blocks; i++) {
      fprintf(stream, "        block %2zu:", i + 1);
      for (size_t j = 0; j < block_sizes[i]; j++) {
        fprintf(stream, " %2zu", *blocks++);
        if (j < block_sizes[i] - 1)
          fputs(",", stream);
      }
      fputs("\n", stream);
    }
  }
}

#ifdef TEST
#include <assert.h>

int main() {
  size_t num_blocks = 0, * block_sizes = NULL, * blocks = NULL;

  assert(parse_blocks("random:2;1;", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks == NULL);
  free(block_sizes);
  free(blocks);

  assert(parse_blocks("random:2;1", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks == NULL);
  free(block_sizes);
  free(blocks);

  assert(parse_blocks("r:2;1;", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks == NULL);
  free(block_sizes);
  free(blocks);

  assert(parse_blocks("r:2;1", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks == NULL);
  free(block_sizes);
  free(blocks);

  assert(parse_blocks("fixed:1,2;3;", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks[0] == 1);
  assert(blocks[1] == 2);
  assert(blocks[2] == 3);
  free(block_sizes);
  free(blocks);

  assert(parse_blocks("fixed:1,2;3", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks[0] == 1);
  assert(blocks[1] == 2);
  assert(blocks[2] == 3);
  free(block_sizes);
  free(blocks);

  assert(parse_blocks("f:1,2;3;", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks[0] == 1);
  assert(blocks[1] == 2);
  assert(blocks[2] == 3);
  free(block_sizes);
  free(blocks);

  assert(parse_blocks("f:1,2;3", &num_blocks, &block_sizes, &blocks) == 0);
  assert(num_blocks == 2);
  assert(block_sizes[0] == 2);
  assert(block_sizes[1] == 1);
  assert(blocks[0] == 1);
  assert(blocks[1] == 2);
  assert(blocks[2] == 3);
  free(block_sizes);
  free(blocks);
}

#endif
