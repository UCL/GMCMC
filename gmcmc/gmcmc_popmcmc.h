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

#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_proposal.h>
#include <gmcmc/gmcmc_likelihood.h>

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
  * Stores a sample in a global array that is later written to a Matlab file.
  *
  * @param [in] options         the MCMC options
  * @param [in] model           the model
  * @param [in] i               the current iteration number
  * @param [in] j               the index on the temperature scale
  * @param [in] params          the current parameter values
  * @param [in] log_prior       the log prior of the sample
  * @param [in] log_likelihood  the log likelihood of the sample
  * @param [in] stepsize        the current stepsizes for each block
  *
  * @return zero on success, non-zero on failure.
  */
  int (*write)(const struct gmcmc_popmcmc_options *, const gmcmc_model *,
               size_t, size_t, const double *, const double *,
               double, const double *);

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
 * How often to save posterior samples.
 */
extern size_t gmcmc_matlab_save_size;

/**
 * Whether to save burn-in samples or not.
 */
extern bool gmcmc_matlab_save_burn_in;

/**
 * Where to write the samples to.
 */
extern const char * gmcmc_matlab_outputID;

/**
 * Stores a sample in a global array that is later written to a Matlab file.
 *
 * @param [in] options         the MCMC options
 * @param [in] model           the model
 * @param [in] i               the current iteration number
 * @param [in] j               the index on the temperature scale
 * @param [in] params          the current parameter values
 * @param [in] log_prior       the log prior of the sample
 * @param [in] log_likelihood  the log likelihood of the sample
 * @param [in] stepsize   the new step sizes for each temperature
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM  if there was not enough memory to create the Matlab
 *                         structure array,
 *         GMCMC_EIO     if there was an error writing the Matlab structure
 *                         array to a file.
 */
int gmcmc_matlab_popmcmc_write(const gmcmc_popmcmc_options *, const gmcmc_model *,
                               size_t, size_t,
                               const double *, const double *, double, const double *);

#endif /* GMCMC_POPMCMC_H */
