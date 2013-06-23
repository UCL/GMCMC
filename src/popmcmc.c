#include <gmcmc/gmcmc_popmcmc.h>
#include <gmcmc/gmcmc_errno.h>
#include <gmcmc/gmcmc_likelihood.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

/**
 * MCMC simulation options.
 */
// typedef struct {
//   const char * outputID;                /**< Output file base name */
//   bool save_burn_in;                    /**< Whether or not to save samples from burn-in */
//   unsigned int num_temps;               /**< Number of temperatures for population MCMC */
//   const double * temperatures;          /**< Population MCMC temperature scale */
//   unsigned long num_burn_in_samples;    /**< Number of samples required to burn-in the sampler */
//   unsigned long num_posterior_samples;  /**< Number of posterior samples to simulate after burn-in */
//   unsigned long posterior_save_size;    /**< How often to write the posterior samples to file */
//   double adapt_rate;                    /**< Step size adapt rate */
//   double upper;                         /**< Upper bound for step size */
//   double lower;                         /**< Lower bound for step size */
// } gmcmc_popmcmc_options;

typedef struct {
  double temperature;           /**< Chain temperature */
  double stepsize;              /**< Parameter step size */ // TODO: stepsize will be an array with blocking
  size_t accepted_mutation;     /**< Number of samples accepted into the chain */ // TODO: accepted_mutation will be an array with blocking
  size_t attempted_mutation;    /**< Number of total sample proposals */ // TODO: attempted_mutation will be an array with blocking
  size_t accepted_exchange;     /**< Number of chain swaps accepted */ // TODO: accepted_exchange will be an array with blocking
  size_t attempted_exchange;    /**< Number of chain swaps proposed */ // TODO: attempted_exchange will be an array with blocking
  double * params;              /**< Parameter vectors for all iterations */
  double * log_prior;           /**< Log prior vectors for each parameter vector */
  double * log_likelihood;      /**< Log likelihood values for each parameter vector */
  void * chainspecific;         /**< Chain specific stuff (like gradient, metric tensor) */
  size_t n;                     /**< Size of chain specific stuff */
} gmcmc_chain;

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

  // Handle MPI errors ourselves
  MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
  // TODO: save and restore caller's MPI error handler

  // Work out how many chains this process is responsible for
  int size, rank;
  if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS)
    GMCMC_ERROR("Failed to get MPI communicator size", GMCMC_EIPC);
  if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS)
    GMCMC_ERROR("Failed to get MPI process rank", GMCMC_EIPC);

  /*
   * Initialise chains
   */

  size_t num_chains = options->num_temps / size;        // Approx (underestimate) no. of chains in this process
  if (rank < options->num_temps % size)                 // correct amount
    num_chains++;
  gmcmc_chain * chains; // Chains private to this process
  if ((chains = calloc(num_chains, sizeof(gmcmc_chain))) == NULL)
    GMCMC_ERROR("Unable to allocate chain state", GMCMC_ENOMEM);

  // Get starting parameters from model
  size_t num_params = gmcmc_model_get_num_params(model);
  const double * initial_params = gmcmc_model_get_params(model);
  size_t ld = (num_params + 1u) & ~1u;

  // Initialise each chain in the population
  // Initialise only the chains that this process uses
  for (size_t i = rank, j = 0; i < options->num_temps; i += size, j++) {
    // In this loop, i is the global index into the temperature scale, etc.
    // while j is the (local) index into the chains array for this process

    // Allocate space to store the parameters, log prior and likelihood
    if ((chains[j].params = malloc(options->posterior_save_size * ld * sizeof(double))) == NULL ||
        (chains[j].log_prior = malloc(options->posterior_save_size * ld * sizeof(double))) == NULL ||
        (chains[j].log_likelihood = malloc(options->posterior_save_size * ld * sizeof(double))) == NULL) {
      for (size_t k = 0; k < j; k++) {
        free(chains[k].params);
        free(chains[k].log_prior);
        free(chains[k].log_likelhood);
      }
      GMCMC_ERROR("Unable to allocate chain parameters", GMCMC_ENOMEM);
    }

    // Set up starting parameters
    if (initial_params == NULL) {
      // Randomly sample from prior
      for (size_t k = 0; k < num_params; k++)
        chains[j].params[k] = gmcmc_distribution_sample(gmcmc_model_get_prior(model, k), rng);
    }
    else {
      // Use given parameters
      memcpy(chains[j].params, initial_params, num_params * sizeof(double));
    }

    // Set up chain temperature
    chains[j].temperature = options->temperatures[i];

    // Set up starting parameter stepsize
    // TODO: this will involve a malloc and memcpy with blocking
    chains[j].stepsize = gmcmc_model_get_stepsize(model);

    // Set up proposal counters
    chains[j].accepted_mutation = 0;    // TODO: accepted_mutation will be an array with blocking
    chains[j].attempted_mutation = 0;   // TODO: attempted_mutation will be an array with blocking
    chains[j].accepted_exchange = 0;
    chains[j].attempted_exchange = 0;

    // Evaluate model at initial parameters to get log prior and likelihood
    int error;
    // p(M,\theta,...)
    if ((error = gmcmc_model_prior(model, chains[j].params, num_params, chains[j].log_prior)) != 0) {
      for (size_t k = 0; k < j; k++) {
        free(chains[k].params);
        free(chains[k].log_prior);
        free(chains[k].log_likelhood);
      }
      GMCMC_ERROR("Error evaluating prior", error);
    }
    // p(D|M,\theta,...)
    if ((error = gmcmc_model_likelihood(data, model, chains[j].params, num_params, &chains[j].likelihood, &chains[j].chainspecific)) != 0) {
      for (size_t k = 0; k < j; k++) {
        free(chains[k].params);
        free(chains[k].log_prior);
        free(chains[k].log_likelhood);
      }
      GMCMC_ERROR("Error evaluating likelihood", error);
    }
  }     // End of initialisation

  // Allocate temporaries for proposal mean and covariance
  double * mean = NULL, * covariance = NULL;
  size_t ldc = (num_params + 1u) & ~1u;
  if ((mean = malloc(num_params * sizeof(double))) == NULL ||
      (covariance = malloc(num_params * ldc * sizeof(double))) == NULL) {
    for (size_t j = 0; j < num_chains; j++) {
      free(chains[j].params);
      free(chains[j].log_prior);
      free(chains[j].log_likelhood);
    }
    free(mean);
    free(covariance);
  }

  // Main loop
  const size_t num_samples = options->num_burn_in_samples + options->num_posterior_samples;
  for (size_t i = 0; i < num_samples; i++) {

    // Update each chain in the population
    for (size_t j = 0; j < num_chains; j++) {

      /*
       * MCMC update of parameter values
       */

      // Check if sampling from prior
      if (chains[j].temperature == 0.0) {

        // Sample new values directly from the prior
        for (size_t k = 0; k < num_params; k++)
          chains[j].params[(i + 1) * ld + k] = gmcmc_distribution_sample(gmcmc_model_get_prior(model, k), rng);

        // Calculate the log prior
        if ((error = gmcmc_model_prior(model, &chains[j].params[(i + 1) * ld], num_params, &chains[j].log_prior[(i + 1) * ld])) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelhood);
          }
          free(mean);
          free(covariance);
          GMCMC_ERROR("Error evaluating prior", error);
        }

        // Evaluate the model at new parameters to get LL, gradient, metric etc.
        // At this point all we want is the log likelihood of the current
        // parameters - i.e. we are not using the extra info (gradient, metric)
        // to inform the proposals.  We therefore pass in NULL to save
        // calculating them
        double likelihood;
        if ((error = gmcmc_model_likelihood(data, model, &chains[j].params[(i + 1) * ld], num_params, &likelihood, NULL)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelhood);
          }
          free(mean);
          free(covariance);
          GMCMC_ERROR("Error evaluating likelihood", error);
        }
      }
      else {

        // TODO: Blocking loop

        // Sample new parameter values using chosen sampler

        // Increment counter
        chains[j].attempted_mutation++;

        // Calculate the geometry based on the current parameter values
        double likelihood;
        if ((error = gmcmc_model_likelihood(data, model, &chains[j].params[i * ld], num_params, &likelihood, NULL)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelhood);
          }
          free(mean);
          free(covariance);
          GMCMC_ERROR("Error evaluating likelihood", error);
        }

        // Calculate the proposal mean and covariance based on the current parameter values, likelihood and geometry
        if ((error = gmcmc_model_propose(likelihood, chains[j].chainspecific, num_params, &chains[j].params[i], chains[j].temperature, chains[j].stepsize, mean, covariance, ldc)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelhood);
          }
          free(mean);
          free(covariance);
          GMCMC_ERROR("Error calculating proposal mean and covariance", error);
        }

        // Propose new parameters
        // params ~N(0,1)
        for (size_t k = 0; k < num_params; k++)
          chains[j].params[(i + 1) * ld + k] = gmcmc_distribution_sample(stdnorm, rng);
        // covariance = chol(covariance)
        int info = 0;
        dpotrf_("L", (const int *)&num_params, covariance, (const int *)&ldc, &info);
        if (info != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelhood);
          }
          free(mean);
          free(covariance);
          GMCMC_ERROR("Proposal covariance matrix is not positive definite", error);
        }
        // mean = params * covariance + mean (i.e. mean now contains the parameters)
        cblas_dgemv(CblasColMajor, CblasNoTrans, num_params, num_params, 1.0, covariance, ldc, &chains[j].params[(i + 1) * ld], 1, 1.0, mean, 1);
        // copy mean into params
        memcpy(&chains[j].params[(i + 1) * ld], mean, num_params * sizeof(double));

        // Evaluate the model at new parameters to get LL, gradient, metric etc. %%%


                [Chain{ChainNum}, Success] = Model.Func_Evaluate(Model, Chain{ChainNum});

      }
    }
  }

  return 0;
}

static int gmcmc_model_prior(const gmcmc_model * model, const double * params, size_t n, double * log_prior) {
  // Calculate the prior of each parameter
  for (int i = 0; i < n; i++) {
    double p = gmcmc_distribution_pdf(gmcmc_model_get_prior(model, i), params[i]);
    if (islessequal(p, 0.0))
      GMCMC_ERROR("Proposed parameter values lie outside prior", GMCMC_EPRIOR);
    log_prior[i] = log(p);
  }
  return 0;
}
