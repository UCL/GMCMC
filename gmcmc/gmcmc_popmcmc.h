/*
 * gmcmc_popmcmc.h
 *
 * Contains declarations of functions to perform population MCMC on GMCMC models.
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_POPMCMC_H
#define GMCMC_POPMCMC_H

#include <stdbool.h>
#include <stdlib.h>

#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_proposal.h>
#include <gmcmc/gmcmc_likelihood.h>

/**
 * Type that writes the samples to file.
 */
typedef struct gmcmc_filewriter_type {
  /**
   * Destructor function pointer.  Closes file (if not already closed) and frees
   * memory/other resources used by filewriter object.
   */
  void (*destroy)();

  /**
   * Closes the filewriter.  After calling this function, write will return an
   * error.
   */
  int (*close)();

  /**
   * Writes a sample to the file.  The samples may be stored in an intermediate
   * buffer before writing.
   *
   * @param [in]  state           filewriter object state
   * @param [in]  i               iteration index
   * @param [in]  j               temperature index
   * @param [in]  params          parameter values for the current iteration
   * @param [in]  log_prior       log prior for the parameter values
   * @param [in]  log_likelihood  log likelihood for the parameter values
   * @param [in]  stepsizes       stepsizes for each block
   *
   * @return 0 on success, GMCMC_EIO on error.
   */
  int (*write)(void *, size_t, size_t, const double *, const double *, double, const double *);
} gmcmc_filewriter_type;

typedef struct gmcmc_filewriter {
  const gmcmc_filewriter_type * type;
  void * state;
} gmcmc_filewriter;

static inline void gmcmc_filewriter_destroy(gmcmc_filewriter * fw) {
  if (fw != NULL)
    fw->type->destroy(fw->state);
  free(fw);
}

static inline int gmcmc_filewriter_close(gmcmc_filewriter * fw) {
  return fw->type->close(fw->state);
}

static inline int gmcmc_filewriter_write(gmcmc_filewriter * fw, size_t i, size_t j,
                                         const double * params, const double * log_prior,
                                         double log_likelihood, const double * stepsizes) {
  return fw->type->write(fw->state, i, j, params, log_prior, log_likelihood, stepsizes);
}

/**
 * MCMC simulation options.
 */
typedef struct gmcmc_popmcmc_options {
  /**
   * The number of posterior samples to simulate after burn in.
   */
  size_t num_posterior_samples;

  /**
   * The number of samples required to burn in the sampler.
   */
  size_t num_burn_in_samples;

  /**
   * The temperature scale for the population MCMC algorithm.  One Markov chain
   * is run in each temperature.
   */
  const double * temperatures;

  /**
   * The number of temperatures in the temperature scale.
   */
  unsigned int num_temperatures;

  /**
   * How often to adapt the step sizes based on the upper and lower acceptance
   * rate bounds.  Set to 1 for every iteration.
   */
  unsigned int adapt_rate;

  /**
   * Upper bound for acceptance ratios.
   */
  double upper_acceptance_rate;

  /**
   * Lower bound for acceptance ratios.
   */
  double lower_acceptance_rate;

  /**
   * If this function is not NULL it is called every adapt_rate iterations to
   * report the current mutation and exchange acceptance ratios for each chain
   * along with the current step size.  The step size only changes during the
   * burn in stage.
   *
   * @param [in] options    the simulation options
   * @param [in] model      the model
   * @param [in] i          the current iteration
   * @param [in] mutation   the mutation acceptance ratios for each temperature
   * @param [in] exchange   the exchange acceptance ratios for each temperature
   * @param [in] stepsize   the new step sizes for each temperature
   */
  void (*acceptance)(const struct gmcmc_popmcmc_options *, const gmcmc_model *,
                     size_t, const double *, const double *,
                     const double *);

  /**
   * Filewriter for burn-in samples (may be NULL).
   */
  gmcmc_filewriter * burn_in_writer;

  /**
   * Filewriter for posterior samples (not NULL).
   */
  gmcmc_filewriter * posterior_writer;

} gmcmc_popmcmc_options;

/**
 * Performs a population MCMC simulation in parallel using MPI.  All callback
 * functions are executed on the node with rank 0.
 *
 * @param [in] model       the model
 * @param [in] dataset     the dataset for the model
 * @param [in] likelihood  likelihood function
 * @param [in] proposal    proposal function
 * @param [in] options     MCMC options struct
 * @param [in] rng         parallel RNG to use
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc_mpi(const gmcmc_model *, const void *, gmcmc_likelihood_function,
                      gmcmc_proposal_function, const gmcmc_popmcmc_options *, const gmcmc_prng64 *);

/**
 * Performs a population MCMC simulation in a single thread without the need to
 * use MPI.  This is mainly for debugging purposes.
 *
 * @param [in] model       the model
 * @param [in] dataset     the dataset for the model
 * @param [in] likelihood  likelihood function
 * @param [in] proposal    proposal function
 * @param [in] options     MCMC options struct
 * @param [in] rng         parallel RNG to use
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc_seq(const gmcmc_model *, const void *,
                      gmcmc_likelihood_function, gmcmc_proposal_function,
                      const gmcmc_popmcmc_options *, const gmcmc_prng64 *);

/**
 * Creates a filewriter object that stores samples in MATLAB files.
 *
 * @param [out]  writer            the filewriter object to create,
 * @param [in]   name              the base filename for the files written,
 * @param [in]   num_params        the length of the parameter vectors to write,
 * @param [in]   num_temperatures  the number of temperatures in the temperature scale,
 * @param [in]   save_size         the number of samples to save to each file
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to create the filewriter object.
 */
int gmcmc_filewriter_create_matlab(gmcmc_filewriter **, const char *, size_t, size_t, size_t);

/**
 * Creates a filewriter object that stores samples in HDF5 files.
 *
 * @param [out]  writer            the filewriter object to create,
 * @param [in]   name              the base filename for the files written,
 * @param [in]   num_params        the length of the parameter vectors to write,
 * @param [in]   num_blocks        the number of parameter blocks,
 * @param [in]   num_temperatures  the number of temperatures in the temperature scale,
 * @param [in]   num_iterations    the number of iterations to store in the file
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if there is not enough memory to create the filewriter object,
 *         GMCMC_EIO    if there was an error initialising the file structures.
 */
int gmcmc_filewriter_create_hdf5(gmcmc_filewriter **, const char *, size_t, size_t, size_t, size_t);

#endif /* GMCMC_POPMCMC_H */
