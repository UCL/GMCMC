#include <gmcmc/gmcmc_popmcmc.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <mpi.h>
#include "mvn.c"

/**
 * This structure contains information about each Markov Chain in the population.
 *
 * It is private to this file.
 */
typedef struct {
  double temperature;           /**< Chain temperature */
  double stepsize;              /**< Parameter step size */                     // TODO: stepsize will be an array with blocking
  size_t accepted_mutation;     /**< Number of samples accepted */              // TODO: accepted_mutation will be an array with blocking
  size_t attempted_mutation;    /**< Number of total sample proposals */        // TODO: attempted_mutation will be an array with blocking
  size_t accepted_exchange;     /**< Number of chain swaps accepted */          // TODO: accepted_exchange will be an array with blocking
  size_t attempted_exchange;    /**< Number of chain swaps proposed */          // TODO: attempted_exchange will be an array with blocking
  size_t n;                     /**< Number of parameters */
  double * params;              /**< Parameter vector */
  double * log_prior;           /**< Log prior vector */
  double log_likelihood;        /**< Log likelihood value */
  void * chainspecific;         /**< Chain specific data for current sample */
  size_t size;                  /**< Size of chain specific data */
} gmcmc_chain;

/**
 * Sums an array handling infinite and not-a-number quantities correctly.
 *
 * @param [in] n  the number of elements in the array
 * @param [in] x  the array to sum
 *
 * @return the sum.
 */
static inline double sum(size_t n, const double * x) {
  double res = 0.0;
  for (size_t i = 0; i < n; i++) {
    // If x[i] is +inf, -inf or NaN then the answer will be (should be) +inf,
    // -inf or NaN respectively. (Adding +inf or -inf to anything results in NaN
    // which is incorrect.)
    if (!isfinite(x[i]))
      return x[i];
    res += x[i];
  }
  return res;
}

/**
 * Calculates the minimum of two double values, handling infinite and
 * not-a-number quantities correctly.
 *
 * @param [in] a  the first value
 * @param [in] b  the second value
 *
 * @return the minimum of the two values.
 */
static inline double min(double a, double b) {
  return isless(a, b) ? a : b;
}

/**
 * Calculates the log prior of the model given the parameters.
 *
 * P(M,\theta)
 *
 * @param [in]  model      the model
 * @param [in]  params     the current parameter values for the model
 * @param [in]  n          the number of parameter values
 * @param [out] log_prior  the log prior vector to populate (length n)
 *
 * @return GMCMC_SUCCESS on success,
 *         GMCMC_ERANGE if any of the prior PDFs returns a probability less than
 *                      zero.
 */
static inline int gmcmc_prior(const gmcmc_model * model, const double * params,
                       size_t n, double * log_prior) {
  // Calculate the prior of each parameter
  for (int i = 0; i < n; i++) {
    const gmcmc_distribution * prior = gmcmc_model_get_prior(model, i);
    double p = gmcmc_distribution_pdf(prior, params[i]);
    if (isless(p, 0.0))
      GMCMC_ERROR("Prior PDF returned less than zero", GMCMC_ERANGE);
    // Avoid pole error (log(0.0) = -INFINITY)
    log_prior[i] = (isgreater(p, 0.0)) ? log(p) : -INFINITY;
  }
  return 0;
}

/**
 * Creates a new chain object.
 *
 * @param [out] chain        a pointer to the chain to create
 * @param [in]  model        the model to create the chain for
 * @param [in]  data         the dataset
 * @param [in]  temperature  the temperature for the chain [0..1]
 * @param [in]  rng          a random number generator to initialise the chain
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to create a new chain
 */
static inline int gmcmc_chain_create(gmcmc_chain ** chain, const gmcmc_model * model,
                                     const gmcmc_dataset * data, double temperature,
                                     const gmcmc_prng64 * rng) {
  if ((*chain = malloc(sizeof(gmcmc_chain))) == NULL)
    GMCMC_ERROR("Unable to allocate memory for chain", GMCMC_ENOMEM);

  // Allocate memory for chain parameters and log prior
  const size_t num_params = gmcmc_model_get_num_params(model);
  if (((*chain)->params = malloc(num_params * sizeof(double))) == NULL) {
    free(*chain);
    GMCMC_ERROR("Unable to allocate memory for chain parameters", GMCMC_ENOMEM);
  }
  if (((*chain)->log_prior = malloc(num_params * sizeof(double))) == NULL) {
    free((*chain)->params);
    free(*chain);
    GMCMC_ERROR("Unable to allocate memory for chain log prior", GMCMC_ENOMEM);
  }

  // Set up starting parameters
  (*chain)->n = num_params;
  const double * initial_params = gmcmc_model_get_params(model);
  if (initial_params == NULL) {
    // Randomly sample from prior
    for (size_t j = 0; j < num_params; j++) {
      const gmcmc_distribution * prior = gmcmc_model_get_prior(model, j);
      (*chain)->params[j] = gmcmc_distribution_sample(prior, rng);
    }
  }
  else {
    // Use given parameters
    memcpy((*chain)->params, initial_params, num_params * sizeof(double));
  }

  // Set up chain temperature
  (*chain)->temperature = temperature;

  // Set up starting parameter stepsize
  (*chain)->stepsize = gmcmc_model_get_stepsize(model);

  // Initialise chainspecific stuff
  (*chain)->chainspecific = NULL;
  (*chain)->size = 0;

  // Set up proposal counters
  (*chain)->attempted_mutation = 0;
  (*chain)->accepted_mutation = 0;
  (*chain)->attempted_exchange = 0;
  (*chain)->accepted_exchange = 0;

  // Evaluate model at initial parameters to get log prior and likelihood
  // p(M,\theta,...)
  int error;
  if ((error = gmcmc_prior(model, (*chain)->params, num_params,
                           (*chain)->log_prior)) != 0) {
    free((*chain)->params);
    free(*chain);
    GMCMC_ERROR("Error evaluating prior", error);
  }
  // p(D|M,\theta,...)
  if ((error = gmcmc_likelihood(data, model, (*chain)->params, num_params,
                                &(*chain)->log_likelihood,
                                &(*chain)->chainspecific, &(*chain)->size)) != 0) {
    free((*chain)->params);
    free(*chain);
    GMCMC_ERROR("Error evaluating likelihood", error);
  }

  return 0;
}

static inline void gmcmc_chain_destroy(gmcmc_chain * chain) {
  free(chain->params);
  free(chain->log_prior);
  free(chain);
}

/**
 * Performs an MCMC update of the parameter values in a Markov chain.
 *
 * @param [in,out] chain  the chain to update
 * @param [in]     model  the model
 * @param [in]     data   the dataset
 * @param [in]     rng    the random number generator
 *
 * @return 0 on success
 */
static int gmcmc_chain_update(gmcmc_chain *, const gmcmc_model *,
                              const gmcmc_dataset *, const gmcmc_prng64 *);

/**
 * Exchanges parameter values and corresponding log prior and log likelihood
 * quantities between chains in adjacent temperatures according to the
 * Metropolis-Hastings ratio.
 *
 * @param [in,out] chains  an array of chains to swap
 * @param [in]     n       the number of chains in the array
 * @param [in]     rng     a random number generator for the MH step
 */
static void gmcmc_chain_exchange(gmcmc_chain **, size_t, const gmcmc_prng64 *);

/**
 * Performs a population MCMC simulation in parallel using MPI.
 *
 * @param [in] options  MCMC options struct
 * @param [in] model    the model to use in the simulation
 * @param [in] data     the data to use in the simulation
 * @param [in] rng      a parallel RNG to use
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc_mpi(const gmcmc_popmcmc_options * options,
                      const gmcmc_model * model, const gmcmc_dataset * data,
                      const gmcmc_prng64 * rng) {
  int error;

  // Get the total number of processes and the rank of this one
  int size, rank;
  if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS)
    GMCMC_ERROR("Failed to get MPI communicator size", GMCMC_EIPC);
  if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS)
    GMCMC_ERROR("Failed to get MPI process rank", GMCMC_EIPC);


  /*
   * Initialise chains
   */

  // Create an array big enough to hold all the chains in the simulation
  const size_t num_chains = options->num_temperatures;
  gmcmc_chain ** chains;
  if ((chains = calloc(num_chains, sizeof(gmcmc_chain *))) == NULL)     // Use calloc so they're all initialised to NULL
    GMCMC_ERROR("Unable to allocate chains", GMCMC_ENOMEM);

  // Initialise only the chains needed on each node
  for (size_t j = rank; j < num_chains; j += size) {
    if ((error = gmcmc_chain_create(&chains[j], model, data, options->temperatures[j], rng)) != 0) {
      // Destroy any chains already created
      for (size_t k = rank; k < j; k += size)
        gmcmc_chain_destroy(chains[k]);
      free(chains);
      GMCMC_ERROR("Unable to initialise chains", error);
    }
  }

  // Burn-in loop
  for (size_t i = 0; i < options->num_burn_in_samples; i++) {
    // Update each chain in the population in parallel
    for (size_t j = rank; j < num_chains; j += size) {
      if ((error = gmcmc_chain_update(chains[j], model, data, rng)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_destroy(chains[k]);
        free(chains);
        GMCMC_ERROR("Error updating chains", error);
      }
    }

    // TODO: Copy all the chains onto node 0


    // Do the serial exchange and step size adjustment (and callbacks) on node 0
    if (rank == 0) {
      // Exchange chains between temperatures
      gmcmc_chain_exchange(chains, num_chains, rng);

      // Adjust parameter proposal widths
      if (i % options->adapt_rate == 0) {
        double mutations[num_chains];
        double exchanges[num_chains];
        double stepsizes[num_chains];

        // For each population
        for (size_t j = 0; j < num_chains; j++) {
          // Adjust proposal width for parameter value inference
          mutations[j] = chains[j]->accepted_mutation /
                         (double)chains[j]->attempted_mutation;

          // Don't update chain 0 unless it is the only chain
          if (j > 0 || options->num_temperatures == 1) {
            if (mutations[j] < options->lower_step_size)
              chains[j]->stepsize *= 0.8;
            else if (mutations[j] > options->upper_step_size)
              chains[j]->stepsize *= 1.2;
          }
          stepsizes[j] = chains[j]->stepsize;

          exchanges[j] = chains[j]->accepted_exchange /
                         (double)chains[j]->attempted_exchange;

          // Reset counters
          chains[j]->accepted_mutation = 0;
          chains[j]->attempted_mutation = 0;
        }

        if (options->acceptance != NULL)
          options->acceptance(options, model, GMCMC_BURN_IN, i, mutations,
                              exchanges, stepsizes);
      }

      // Write current samples to file
      if (options->write != NULL) {
        for (size_t j = 0; j < num_chains; j++) {
          if ((error = options->write(i, j, chains[j]->params, chains[j]->log_prior, chains[j]->log_likelihood)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error writing chains", error);
          }
        }
      }
    }

    // TODO: Copy chains back onto other nodes


  }     // burn-in

  // Posterior
  for (size_t i = 0; i < options->num_posterior_samples; i++) {
    // Update each chain in the population in parallel
    for (size_t j = rank; j < num_chains; j += size) {
      if ((error = gmcmc_chain_update(chains[j], model, data, rng)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_destroy(chains[k]);
        free(chains);
        GMCMC_ERROR("Error updating chains", error);
      }
    }

    // TODO: Copy all the chains onto node 0


    if (rank == 0) {
      // Exchange chains between temperatures
      gmcmc_chain_exchange(chains, num_chains, rng);

      // Report acceptance ratios
      if (i % options->adapt_rate == 0) {
        double mutations[num_chains];
        double exchanges[num_chains];
        double stepsizes[num_chains];

        // For each population
        for (size_t j = 0; j < num_chains; j++) {
          // Adjust proposal width for parameter value inference
          mutations[j] = chains[j]->accepted_mutation /
                         (double)chains[j]->attempted_mutation;
          stepsizes[j] = chains[j]->stepsize;
          exchanges[j] = chains[j]->accepted_exchange /
                         (double)chains[j]->attempted_exchange;
        }

        if (options->acceptance != NULL)
          options->acceptance(options, model, GMCMC_POSTERIOR, i, mutations,
                              exchanges, stepsizes);
      }

      // Write current sample to file
      if (options->write != NULL) {
        for (size_t j = 0; j < num_chains; j++) {
          if ((error = options->write(i, j, chains[j]->params, chains[j]->log_prior, chains[j]->log_likelihood)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error writing chains", error);
          }
        }
      }
    }

    // TODO: Copy chains back onto other nodes

  }

  // Clean up
  for (size_t j = 0; j < num_chains; j++)
    gmcmc_chain_destroy(chains[j]);
  free(chains);

  return 0;
}

/**
 * MCMC update of parameter values.
 *
 * @param [in,out] chain  the chain
 * @param [in]     model  the model
 * @param [in]     data   the dataset
 * @param [in]     rng    the random number generator to use
 *
 * @return 0 on success
 */
static int gmcmc_chain_update(gmcmc_chain * chain, const gmcmc_model * model,
                              const gmcmc_dataset * data, const gmcmc_prng64 * rng) {

  int error;

  const size_t num_params = gmcmc_model_get_num_params(model);

  // Increment counter
  chain->attempted_mutation++;

  // Check if sampling from prior
  if (chain->temperature == 0.0) {

    // Don't need any geometry here
    free(chain->chainspecific);

    // Sample new values directly from the prior
    for (size_t k = 0; k < num_params; k++) {
      const gmcmc_distribution * prior = gmcmc_model_get_prior(model, k);
      chain->params[k] = gmcmc_distribution_sample(prior, rng);
    }

    // Calculate the log prior
    if ((error = gmcmc_prior(model, chain->params, num_params, chain->log_prior)) != 0)
      GMCMC_ERROR("Error evaluating prior", error);

    // Evaluate the model at new parameters to get LL, gradient, metric etc.
    if ((error = gmcmc_likelihood(data, model, chain->params, num_params,
                                  &chain->log_likelihood, &chain->chainspecific,
                                  &chain->size)) != 0)
      GMCMC_ERROR("Error evaluating likelihood", error);

    // accept proposal (always)
    chain->accepted_mutation++;
  }
  else {
    // Proposed samples
    double * params = NULL, * log_prior = NULL, log_likelihood;
    void * chainspecific;
    size_t size;
    if ((params = malloc(num_params * sizeof(double))) == NULL ||
        (log_prior = malloc(num_params * sizeof(double))) == NULL) {
      free(params);
      free(log_prior);
      GMCMC_ERROR("Failed to allocate proposal", GMCMC_ENOMEM);
    }

    // Allocate temporaries for proposal mean and covariance
    double * mean = NULL, * covariance = NULL;
    size_t ldc = (num_params + 1u) & ~1u;
    if ((mean = malloc(num_params * sizeof(double))) == NULL ||
        (covariance = malloc(num_params * ldc * sizeof(double))) == NULL) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Unable to allocate proposal mean and covariance", GMCMC_ENOMEM);
    }

    // TODO: Blocking loop

    // Calculate the proposal mean and covariance based on the previous
    // parameter values, likelihood and geometry
    if ((error = gmcmc_proposal(model, chain->log_likelihood, chain->chainspecific,
                                chain->params, num_params, chain->temperature,
                                chain->stepsize, mean, covariance, ldc)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error calculating proposal mean and covariance", error);
    }

    // Propose new parameters and get Cholesky of covariance
    if ((error = gmcmc_mvn_sample(num_params, mean, covariance, ldc, rng, params)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error with proposal", error);
    }

    // Evaluate prior of new sample
    if ((error = gmcmc_prior(model, params, num_params, log_prior)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error evaluating prior", error);
    }

    // Calculate new given old
    double pxtx;        // p(x'|x)

    // Converts Cholesky of covariance into inverse
    if ((error = gmcmc_mvn_logpdf(num_params, params, mean, covariance, ldc, &pxtx)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error evaluating multivariate normal log pdf", error);
    }

    // Calculate old given new
    double pxxt;    // p(x|x')

    // Evaluate the model at new parameters to get new likelihood and geometry
    if ((error = gmcmc_likelihood(data, model, params, num_params,
                                  &log_likelihood, &chainspecific, &size)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error evaluating likelihood", error);
    }

    // Calculate the mean and covariance based on the proposed parameter values,
    // likelihood and geometry
    if ((error = gmcmc_proposal(model, chain->log_likelihood,
                                chain->chainspecific, chain->params, num_params,
                                chain->temperature, chain->stepsize, mean,
                                covariance, ldc)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error calculating mean and covariance", error);
    }

    if ((error = gmcmc_mvn_logpdf(num_params, chain->params, mean, covariance,
                                  ldc, &pxxt)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error evaluating multivariate normal log pdf", error);
    }

    // Accept or reject according to ratio
    double ratio = log_likelihood * chain->temperature +
                   sum(num_params, log_prior) + pxxt -
                   chain->log_likelihood * chain->temperature -
                   sum(num_params, chain->log_prior) - pxtx;

    if (isgreater(ratio, 0.0) || log(1.0 - gmcmc_prng64_get_double(rng)) < min(0.0, ratio)) {   // = log(1.0) !!
      memcpy(chain->params, params, num_params * sizeof(double));
      memcpy(chain->log_prior, log_prior, num_params * sizeof(double));
      chain->log_likelihood = log_likelihood;
      chain->accepted_mutation++;        // accept proposal
    }

    free(params);
    free(log_prior);
    free(mean);
    free(covariance);
  } // if not sampling from prior (temperature > 0.0)

  return 0;
}

/**
 * Exchanges parameter vectors (and associated log priors, likelihoods and chain
 * specific stuff) between chains running in adjacent temperatures.
 *
 * @param [in,out] chains     chains specific to this process
 * @param [in]     num_temps  number of temperatures
 * @param [in]     rng        random number generator
 */
static void gmcmc_chain_exchange(gmcmc_chain ** chains, size_t num_chains,
                                 const gmcmc_prng64 * rng) {
  // If there are less than 2 chains then we can't swap so return now
  if (num_chains < 2)
    return;

  // Run the exchange algorithm 3 times
  const size_t num_exchanges = 3;

  // Serial exchange algorithm
  for (size_t l = 0; l < num_exchanges; l++) {
    for (size_t i = 0; i < num_chains - 1; i++) {
      // Attempt a swap between chain i and i + 1
      chains[i]->attempted_exchange++;
      chains[i + 1]->attempted_exchange++;

      // Calculate Metropolis-Hastings acceptance ratio (in log)
      double a = chains[i + 1]->log_likelihood * chains[i]->temperature +
                 chains[i]->log_likelihood * chains[i + 1]->temperature -
                 chains[i]->log_likelihood * chains[i]->temperature -
                 chains[i + 1]->log_likelihood * chains[i + 1]->temperature;

      if (isgreater(a, 0.0) || log(1.0 - gmcmc_prng64_get_double(rng)) < min(0.0, a)) {
        // Accept swap
        chains[i]->accepted_exchange++;
        chains[i + 1]->accepted_exchange++;

        // Rather than copy everything just swap the pointers
        // params
        double * params = chains[i]->params;
        chains[i]->params = chains[i + 1]->params;
        chains[i + 1]->params = params;
        // log_prior
        double * log_prior = chains[i]->log_prior;
        chains[i]->log_prior = chains[i + 1]->log_prior;
        chains[i + 1]->log_prior = log_prior;
        // log_likelihood
        double log_likelihood = chains[i]->log_likelihood;
        chains[i]->log_likelihood = chains[i + 1]->log_likelihood;
        chains[i + 1]->log_likelihood = log_likelihood;
        // chain-specific stuff (geometry, etc.)
        void * chainspecific = chains[i]->chainspecific;
        chains[i]->chainspecific = chains[i + 1]->chainspecific;
        chains[i + 1]->chainspecific = chainspecific;
      }
    }
  }
}
