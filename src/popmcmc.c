#include <gmcmc/gmcmc_popmcmc.h>
#include <gmcmc/gmcmc_errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cblas.h>
#include <mpi.h>
#include "distribution/util.c"

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
  void * chainspecific;         /**< Chain specific stuff for current sample (like gradient, metric tensor) serialised so it can be sent over MPI */
  size_t size;                  /**< Size of chain specific stuff */
} gmcmc_chain;

#define M_LOG2PI 1.83787706640935
static int gmcmc_mvn_sample(size_t, const double *, double *, size_t, const gmcmc_prng64 *, double *);
static int gmcmc_mvn_logpdf(size_t, const double *, const double *, double *, size_t, double *);
static int gmcmc_model_prior(const gmcmc_model *, const double *, size_t, double *);

extern void dpotrf_(const char *, const long *, double *, const long *, long *);
static inline long clapack_dpotrf(enum CBLAS_UPLO uplo, long n, double * A, long lda) {
  long info = 0;
  if (uplo == CblasUpper)
    dpotrf_("Upper", &n, A, &lda, &info);
  else
    dpotrf_("Lower", &n, A, &lda, &info);
  return info;
}

extern void dpotri_(const char *, const long *, double *, const long *, long *);
static inline long clapack_dpotri(enum CBLAS_UPLO uplo, long n, double * A, long lda) {
  long info = 0;
  if (uplo == CblasUpper)
    dpotri_("Upper", &n, A, &lda, &info);
  else
    dpotri_("Lower", &n, A, &lda, &info);
  return info;
}

static inline double sum(size_t n, const double * x) {
  double res = 0.0;
  for (size_t i = 0; i < n; i++)
    res += x[i];
  return res;
}

static inline double min(double a, double b) {
  return isless(a, b) ? a : b;
}

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

  int error;

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

    // Allocate space to store the parameters, log prior and log likelihood
    if ((chains[j].params = malloc(options->posterior_save_size * ld * sizeof(double))) == NULL ||
        (chains[j].log_prior = malloc(options->posterior_save_size * ld * sizeof(double))) == NULL ||
        (chains[j].log_likelihood = malloc(options->posterior_save_size * sizeof(double))) == NULL) {
      for (size_t k = 0; k <= j; k++) {
        free(chains[k].params);
        free(chains[k].log_prior);
        free(chains[k].log_likelihood);
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
    // calloc() above sets all these to zero
//     chains[j].accepted_mutation = 0;    // TODO: accepted_mutation will be an array with blocking
//     chains[j].attempted_mutation = 0;   // TODO: attempted_mutation will be an array with blocking
//     chains[j].accepted_exchange = 0;
//     chains[j].attempted_exchange = 0;

    // Evaluate model at initial parameters to get log prior and likelihood
    // p(M,\theta,...)
    if ((error = gmcmc_model_prior(model, chains[j].params, num_params, chains[j].log_prior)) != 0) {
      for (size_t k = 0; k < j; k++) {
        free(chains[k].params);
        free(chains[k].log_prior);
        free(chains[k].log_likelihood);
      }
      GMCMC_ERROR("Error evaluating prior", error);
    }
    // p(D|M,\theta,...)
    if ((error = gmcmc_model_likelihood(data, model, chains[j].params, num_params, &chains[j].log_likelihood[i], &chains[j].chainspecific, &chains[j].size)) != 0) {
      for (size_t k = 0; k < j; k++) {
        free(chains[k].params);
        free(chains[k].log_prior);
        free(chains[k].log_likelihood);
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
      free(chains[j].log_likelihood);
      free(chains[j].chainspecific);
    }
    free(mean);
    free(covariance);
    GMCMC_ERROR("Unable to allocate proposal mean and covariance", GMCMC_ENOMEM);
  }

  // Create a standard normal distribution for proposals
  gmcmc_distribution * stdnorm;
  if ((error = gmcmc_distribution_create_normal(&stdnorm, 0.0, 1.0)) != 0) {
    for (size_t j = 0; j < num_chains; j++) {
      free(chains[j].params);
      free(chains[j].log_prior);
      free(chains[j].log_likelihood);
      free(chains[j].chainspecific);
    }
    free(mean);
    free(covariance);
    GMCMC_ERROR("Unable to create proposal distribution", error);
  }

  // Main loop
  const size_t num_samples = options->num_burn_in_samples + options->num_posterior_samples;
  for (size_t i = 1; i < num_samples; i++) {
    // Current sample is chains[j].params[i * ld]
    // Previous sample is chains[j].params[(i - 1) * ld]

    // Update each chain in the population
    for (size_t j = 0; j < num_chains; j++) {

      /*
       * MCMC update of parameter values
       */

      // Check if sampling from prior
      if (chains[j].temperature == 0.0) {

        // Don't need any geometry here
        free(chains[j].chainspecific);

        // Sample new values directly from the prior
        for (size_t k = 0; k < num_params; k++)
          chains[j].params[i * ld + k] = gmcmc_distribution_sample(gmcmc_model_get_prior(model, k), rng);

        // Calculate the log prior
        if ((error = gmcmc_model_prior(model, &chains[j].params[i * ld], num_params, &chains[j].log_prior[i * ld])) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error evaluating prior", error);
        }

        // Evaluate the model at new parameters to get LL, gradient, metric etc.
        if ((error = gmcmc_model_likelihood(data, model, &chains[j].params[i * ld], num_params, &chains[j].log_likelihood[i], &chains[j].chainspecific, &chains[j].size)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error evaluating likelihood", error);
        }
      }
      else {

        // TODO: Blocking loop

        // Sample new parameter values using chosen sampler

        // Increment counter
        chains[j].attempted_mutation++;

        // Calculate the proposal mean and covariance based on the previous parameter values, likelihood and geometry
        if ((error = gmcmc_model_proposal(model, chains[j].log_likelihood[i - 1], chains[j].chainspecific, &chains[j].params[(i - 1) * ld], num_params, chains[j].temperature, chains[j].stepsize, mean, covariance, ldc)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
            free(chains[j].chainspecific);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error calculating proposal mean and covariance", error);
        }
        free(chains[j].chainspecific);

        // Propose new parameters
        if ((error = gmcmc_mvn_sample(num_params, mean, covariance, ldc, rng, &chains[j].params[i * ld])) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error with proposal", error);
        }

        // Evaluate prior
        if ((error = gmcmc_model_prior(model, &chains[j].params[i * ld], num_params, &chains[j].log_prior[i * ld])) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error evaluating prior", error);
        }
        // Evaluate the model at new parameters to get LL, gradient, metric etc.
        if ((error = gmcmc_model_likelihood(data, model, &chains[j].params[i * ld], num_params, &chains[j].log_likelihood[i], &chains[j].chainspecific, &chains[j].size)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error evaluating likelihood", error);
        }

        // TODO: Prior and likelihood evaluation non-fatal errors


        // Calculate new given old
        // Prob_NewGivenOld = Normal_LogPDF(Chain{ChainNum}.Paras(CurrentBlock)', Proposal_Mean', Proposal_Covariance);
        double pxtx;    // p(xt|x)
        if ((error = gmcmc_mvn_logpdf(num_params, &chains[j].params[i * ld], mean, covariance, ldc, &pxtx)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error evaluating multivariate normal log pdf", error);
        }

        // TODO: what is this?
//         %%% Calculate mean, covariance of proposal and propose new parameters %%%
//
//         [Proposal_Mean, Proposal_Covariance] = Model.Func_Proposal(Model, Chain{ChainNum});

        // Calculate old given new
        // Prob_OldGivenNew = Normal_LogPDF(OldChain.Paras(CurrentBlock)', Proposal_Mean', Proposal_Covariance);
        double pxxt;    // p(x|xt)
        if ((error = gmcmc_mvn_logpdf(num_params, &chains[j].params[(i - 1) * ld], mean, covariance, ldc, &pxxt)) != 0) {
          for (size_t j = 0; j < num_chains; j++) {
            free(chains[j].params);
            free(chains[j].log_prior);
            free(chains[j].log_likelihood);
          }
          free(mean);
          free(covariance);
          gmcmc_distribution_destroy(stdnorm);
          GMCMC_ERROR("Error evaluating multivariate normal log pdf", error);
        }

        // Accept or reject according to ratio
        // Ratio = Chain{ChainNum}.LL*Chain{ChainNum}.Temp + sum(Chain{ChainNum}.LogPrior(CurrentBlock)) + Prob_OldGivenNew - OldChain.LL*Chain{ChainNum}.Temp - sum(OldChain.LogPrior(CurrentBlock)) - Prob_NewGivenOld;
        double ratio = chains[j].log_likelihood[i] * chains[j].temperature +
                       sum(num_params, &chains[j].log_prior[i * ld]) + pxxt -
                       chains[j].log_likelihood[i - 1] * chains[j].temperature -
                       sum(num_params, &chains[j].log_prior[(i - 1) * ld]) - pxtx;

        if (ratio > 0.0 || log(gmcmc_prng64_get_double(rng)) < min(0.0, ratio))    // = log(1.0) !!
          chains[j].accepted_mutation++;        // accept proposal
        else
          memcpy(&chains[j].params[i * ld], &chains[j].params[(i - 1) * ld], num_params * sizeof(double));      // Move rejected so use previous chain values

      } // if not sampling from prior (temperature > 0.0)
    }   // end chain loop
  }     // end main loop

  return 0;
}

/**
 * Generates a multivariate normal random vector.  The covariance matrix is
 * overwritten with its Cholesky decomposition on output.
 *
 * @param [in]     n           the dimensionality of the distribution
 * @param [in]     mean        the mean vector (length n)
 * @param [in,out] covariance  the covariance matrix (n-by-n, positive-definite,
 *                               overwritten with Cholesky decomposition on output)
 * @param [in]     ldc         leading dimension of the covariance matrix (ldc >= n)
 * @param [in,out] rng         a random number generator
 * @param [out]    x           the random vector (length n)
 *
 * @return 0 on success,
 *         GMCMC_EINVAL if ldc < n,
 *         GMCMC_ENOMEM if there is not enough memory to allocate a temporary vector,
 *         GMCMC_ELINAL if the covariance matrix is not positive definite.
 */
static int gmcmc_mvn_sample(size_t n, const double * mean, double * covariance,
                            size_t ldc, const gmcmc_prng64 * rng, double * x) {
  if (ldc < n)
    GMCMC_ERROR("Invalid leading dimension", GMCMC_EINVAL);

  // Quick return
  if (n == 0)
    return 0;

  double * z = malloc(n * sizeof(double));
  if (z == NULL)
    GMCMC_ERROR("Unable to allocate standard normal vector", GMCMC_ENOMEM);

  // z = ~N(0,1)
  for (size_t i = 0; i < n; i++)
    z[i] = gmcmc_randn(rng);

  // Calculate the Cholesky decomposition of the covariance matrix
  long info = clapack_dpotrf(CblasLower, n, covariance, ldc);
  if (info != 0) {
    free(z);
    GMCMC_ERROR("Proposal covariance matrix is not positive definite", GMCMC_ELINAL);
  }

  // Use memcpy and BLAS DGEMV (matrix-vector product y = Ax + y) to compute
  // x = Az + mean
  memcpy(x, mean, n * sizeof(double));
  cblas_dgemv(CblasColMajor, CblasNoTrans, n, n, 1.0, covariance, ldc, z, 1, 1.0, x, 1);

  free(z);

  return 0;
}

/**
 * Calculates the log of the determinant of a matrix from its Cholesky
 * decomposition.
 *
 * @param [in] n    the size of the matrix
 * @param [in] C    the Cholesky decomposition of a matrix (n by n)
 * @param [in] ldc  the leading dimension of C (ldc >= n)
 *
 * @return the log determinant.
 */
static double log_det(size_t n, const double * C, size_t ldc) {
  if (n == 0)
    return -INFINITY;

  // sum(log(diag(chol(Covar))))
  double sum = 0.0;
  for (size_t i = 0; i < n; i++)
    sum += log(C[i * ldc + i]);

  // TODO: shouldn't this be 2.0*sum?
  return sum;
}

/**
 * Calculates the log of the PDF of the multivariate normal distribution at x.
 *
 * @param [in]     n                the dimensionality of the distribution
 * @param [in]     x                the random vector (length n)
 * @param [in]     mean             the mean of the distribution (length n)
 * @param [in,out] chol_covariance  the Cholesky decomposition of the covariance
 *                                    matrix (overwritten with the inverse on exit)
 * @param [in]     ldc              the leading dimension of the covariance matrix
 * @param [out]    res              the result
 *
 * @return
 */
static int gmcmc_mvn_logpdf(size_t n, const double * x, const double * mean, double * chol_covariance, size_t ldc, double * res) {
  if (n == 0) {
    *res = -INFINITY;
    return 0;
  }

  double * x_mu = malloc(n * sizeof(double));
  if (x_mu == NULL)
    GMCMC_ERROR("Unable to allocate temporary vector", GMCMC_ENOMEM);

  double * x_muTinv = malloc(n * sizeof(double));
  if (x_muTinv == NULL) {
    free(x_mu);
    GMCMC_ERROR("Unable to allocate temporary vector", GMCMC_ENOMEM);
  }

  // x_mu = x - mean
  for (size_t i = 0; i < n; i++)
    x_mu[i] = x[i] - mean[i];

  // Calculate the log determinant before overwriting the matrix with its inverse
  double ldet = log_det(n, chol_covariance, ldc);

  // Calculate the inverse from the Cholesky
  long info = clapack_dpotri(CblasLower, n, chol_covariance, ldc);
  if (info != 0) {
    free(x_mu);
    free(x_muTinv);
    GMCMC_ERROR("Proposal covariance matrix is singular", GMCMC_ELINAL);
  }

  // Use CBLAS DGEMV to compute mean = (x - mu)'*inv(covariance) = inv(covariance)'*(x - mu)
  cblas_dgemv(CblasColMajor, CblasTrans, n, n, 1.0, chol_covariance, ldc, x_mu, 1, 0.0, x_muTinv, 1);
  // Use CBLAS DDOT to compute (x - mu)'*inv(cov)*x_mu
  double p = cblas_ddot(n, x_muTinv, 1, x_mu, 1);

  free(x_mu);
  free(x_muTinv);

  // LogResult = -(k/2)*log(2*pi) - sum(log(diag(chol(Covar)))) -0.5*(( Diff'/Covar )*Diff);
  *res = -(n / 2.0) * M_LOG2PI - ldet - 0.5 * p;

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
