#include <gmcmc/gmcmc_popmcmc.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <mpi.h>
#include "mvn.c"
#include "permute.c"

#include <sys/time.h>

/**
 * This structure contains information about each Markov Chain in the population.
 *
 * It is private to this file.
 */
typedef struct {
  double temperature;           /**< Chain temperature */
  double stepsize;              /**< Parameter step size */
  uint64_t accepted_mutation;   /**< Number of samples accepted */
  uint64_t attempted_mutation;  /**< Number of total sample proposals */
  uint64_t accepted_exchange;   /**< Number of chain swaps accepted */
  uint64_t attempted_exchange;  /**< Number of chain swaps proposed */
  uint32_t n;                   /**< Number of parameters */
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
  for (size_t i = 0; i < n; i++) {
    const gmcmc_distribution * prior = gmcmc_model_get_prior(model, i);
    log_prior[i] = gmcmc_distribution_log_pdf(prior, params[i]);
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
    free((*chain)->log_prior);
    free(*chain);
    GMCMC_ERROR("Error evaluating prior", error);
  }
  // p(D|M,\theta,...)
  if ((error = gmcmc_likelihood(data, model, (*chain)->params,
                                &(*chain)->log_likelihood,
                                &(*chain)->chainspecific, &(*chain)->size)) != 0) {
    free((*chain)->params);
    free((*chain)->log_prior);
    free(*chain);
    GMCMC_ERROR("Error evaluating likelihood", error);
  }

  // If the log likelihood or sum of the log prior are negative infinity then
  // attempt to resample initial values from the prior 5 times before quitting
  for (int i = 0; (isinf((*chain)->log_likelihood) == -1 ||
                   isinf(sum(num_params, (*chain)->log_prior)) == -1) && i < 5; i++) {
    // Free the invalid geometry
    free((*chain)->chainspecific);

    // Sample new values directly from the prior
    for (size_t k = 0; k < num_params; k++) {
      const gmcmc_distribution * prior = gmcmc_model_get_prior(model, k);
      (*chain)->params[k] = gmcmc_distribution_sample(prior, rng);
    }

    // Evaluate model at initial parameters to get log prior and likelihood
    // p(M,\theta,...)
    int error;
    if ((error = gmcmc_prior(model, (*chain)->params, num_params,
                            (*chain)->log_prior)) != 0) {
      free((*chain)->params);
      free((*chain)->log_prior);
      free(*chain);
      GMCMC_ERROR("Error evaluating prior", error);
    }
    // p(D|M,\theta,...)
    if ((error = gmcmc_likelihood(data, model, (*chain)->params,
                                  &(*chain)->log_likelihood,
                                  &(*chain)->chainspecific, &(*chain)->size)) != 0) {
      free((*chain)->params);
      free((*chain)->log_prior);
      free(*chain);
      GMCMC_ERROR("Error evaluating likelihood", error);
    }
  }

  if (isinf((*chain)->log_likelihood) == -1 || isinf(sum(num_params, (*chain)->log_prior)) == -1) {
    free((*chain)->params);
    free((*chain)->log_prior);
    free(*chain);
    GMCMC_ERROR("Starting parameters are invalid after 5 iterations", GMCMC_EINVAL);
  }

  return 0;
}

static inline void gmcmc_chain_destroy(gmcmc_chain * chain) {
  if (chain == NULL)
    return;
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
 * @param [in]     rng     random number generator
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if a vector of permuation indices could not be allocated.
 */
static int gmcmc_chain_exchange(gmcmc_chain **, size_t, const gmcmc_prng64 *);

#include "popmcmc_seq.c"
#include "popmcmc_omp.c"
#include "popmcmc_mpi.c"

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

  // Proposed samples
  double * params = NULL, * log_prior = NULL, log_likelihood;
  void * chainspecific = NULL;
  size_t size = 0;
  if ((params = malloc(num_params * sizeof(double))) == NULL ||
      (log_prior = malloc(num_params * sizeof(double))) == NULL) {
    free(params);
    free(log_prior);
    GMCMC_ERROR("Failed to allocate proposal and log prior", GMCMC_ENOMEM);
  }

  // Increment counter
  chain->attempted_mutation++;

  // Check if sampling from prior
  if (chain->temperature == 0.0) {

    // Sample new values directly from the prior
    for (size_t k = 0; k < num_params; k++) {
      const gmcmc_distribution * prior = gmcmc_model_get_prior(model, k);
      params[k] = gmcmc_distribution_sample(prior, rng);
    }

    // Calculate the log prior
    if ((error = gmcmc_prior(model, params, num_params, log_prior)) != 0)
      GMCMC_ERROR("Error evaluating prior", error);

    // Evaluate the model at new parameters to get LL, gradient, metric etc.
    if ((error = gmcmc_likelihood(data, model, params,
                                  &log_likelihood, &chainspecific,
                                  &size)) != 0) {
      free(params);
      free(log_prior);
      if (error < 0)    // fatal error
        GMCMC_ERROR("Error evaluating likelihood", error);
      return 0;         // non-fatal error (reject sample)
    }

    // accept proposal
    free(chain->params);
    free(chain->log_prior);
    free(chain->chainspecific);

    chain->params = params;
    chain->log_prior = log_prior;
    chain->log_likelihood = log_likelihood;
    chain->chainspecific = chainspecific;
    chain->size = size;

    chain->accepted_mutation++;
  }
  else {
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

    // Calculate the proposal mean and covariance based on the current
    // parameter values, likelihood and geometry
    if ((error = gmcmc_proposal(model, chain->params, chain->log_likelihood,
                                chain->temperature, chain->stepsize, chain->chainspecific,
                                mean, covariance, ldc)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error calculating proposal mean and covariance", error);
    }

    // Propose new parameters
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

    // Calculate the sum of the log prior of the proposed parameters now.  If it
    // is -Inf then the proposed parameters lie outside the prior, the
    // likelihood will evaluate to zero later on and the sample will be
    // rejected.  This saves calculating the MVN log PDF for the current and
    // proposed samples, proposal mean and covariance for the proposed
    // samples and the likelihood of the proposed parameters.
    double sum_log_prior_params = sum(num_params, log_prior);
    // If the sum of the log prior is zero reject the proposal now
    if (isinf(sum_log_prior_params) == -1) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      return 0;
    }

    // Calculate new given old
    double p_new_given_old;        // p(x'|x)

    if ((error = gmcmc_mvn_logpdf(num_params, params, mean, covariance, ldc, &p_new_given_old)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error evaluating multivariate normal log pdf", error);
    }

    // Calculate old given new
    double p_old_given_new;    // p(x|x')

    // Evaluate the model at new parameters to get new likelihood and geometry
    if ((error = gmcmc_likelihood(data, model, params,
                                  &log_likelihood, &chainspecific, &size)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      if (error < 0)    // Fatal error
        GMCMC_ERROR("Error evaluating likelihood", error);
      return 0;         // Non-fatal error (invalid parameters so reject)
    }

    // Calculate the mean and covariance based on the proposed parameter values,
    // likelihood and geometry
    if ((error = gmcmc_proposal(model, params, log_likelihood, chain->temperature,
                                chain->stepsize, chainspecific, mean,
                                covariance, ldc)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      if (error < 0)    // Fatal error
        GMCMC_ERROR("Error calculating mean and covariance", error);
      return 0;         // Non-fatal error (invalid parameters so reject)
    }


    if ((error = gmcmc_mvn_logpdf(num_params, chain->params, mean, covariance,
                                  ldc, &p_old_given_new)) != 0) {
      free(params);
      free(log_prior);
      free(mean);
      free(covariance);
      GMCMC_ERROR("Error evaluating multivariate normal log pdf", error);
    }

    // Accept or reject according to ratio
    double ratio = log_likelihood * chain->temperature +
                   sum_log_prior_params + p_old_given_new -
                   chain->log_likelihood * chain->temperature -
                   sum(num_params, chain->log_prior) - p_new_given_old;

    if (isgreater(ratio, 0.0) || log(1.0 - gmcmc_prng64_get_double(rng)) < min(0.0, ratio)) {   // = log(1.0) !!
      // Swap pointers rather than copy
      free(chain->params);
      chain->params = params;
      free(chain->log_prior);
      chain->log_prior = log_prior;
      chain->log_likelihood = log_likelihood;
      free(chain->chainspecific);
      chain->chainspecific = chainspecific;
      chain->size = size;
      chain->accepted_mutation++;        // accept proposal
    }
    else {
      // Proposed parameters rejected
      free(params);
      free(log_prior);
      free(chainspecific);
    }

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
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if a vector of permutation indices could not be allocated.
 */
static int gmcmc_chain_exchange(gmcmc_chain ** chains, size_t num_chains,
                                 const gmcmc_prng64 * rng) {
  // If there are less than 2 chains then we can't swap so return now
  if (num_chains < 2)
    return 0;

  // Run the exchange algorithm 3 times
  const size_t num_exchanges = 3;
  size_t * permutation = malloc((num_chains - 1) * sizeof(size_t));
  if (permutation == NULL)
    GMCMC_ERROR("Failed to allocate permutation vector", GMCMC_ENOMEM);

  // Serial exchange algorithm
  for (size_t l = 0; l < num_exchanges; l++) {
    // Generate a random permutation of [0, num_chains - 1]
    gmcmc_permute(num_chains - 1, permutation, rng);

    for (size_t i = 0; i < num_chains - 1; i++) {
      size_t j = permutation[i];

      // Attempt a swap between chain j and j + 1
      chains[j]->attempted_exchange++;
      chains[j + 1]->attempted_exchange++;

      // Calculate Metropolis-Hastings acceptance ratio (in log)
      double a = chains[j + 1]->log_likelihood * chains[j]->temperature +
                 chains[j]->log_likelihood * chains[j + 1]->temperature -
                 chains[j]->log_likelihood * chains[j]->temperature -
                 chains[j + 1]->log_likelihood * chains[j + 1]->temperature;

      if (isgreater(a, 0.0) || log(1.0 - gmcmc_prng64_get_double(rng)) < min(0.0, a)) {
        // Accept swap
        chains[j]->accepted_exchange++;
        chains[j + 1]->accepted_exchange++;

        // Rather than copy everything just swap the pointers
        // params
        double * params = chains[j]->params;
        chains[j]->params = chains[j + 1]->params;
        chains[j + 1]->params = params;
        // log_prior
        double * log_prior = chains[j]->log_prior;
        chains[j]->log_prior = chains[j + 1]->log_prior;
        chains[j + 1]->log_prior = log_prior;
        // log_likelihood
        double log_likelihood = chains[j]->log_likelihood;
        chains[j]->log_likelihood = chains[j + 1]->log_likelihood;
        chains[j + 1]->log_likelihood = log_likelihood;
        // chain-specific stuff (geometry, etc.)
        void * chainspecific = chains[j]->chainspecific;
        chains[j]->chainspecific = chains[j + 1]->chainspecific;
        chains[j + 1]->chainspecific = chainspecific;
      }
    }
  }

  free(permutation);

  return 0;
}
