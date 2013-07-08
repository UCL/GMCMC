/*
 * gmcmc_popmcmc.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_POPMCMC_H
#define GMCMC_POPMCMC_H

#include <gmcmc/gmcmc_model.h>
#include <gmcmc/gmcmc_dataset.h>

/**
 * Iteration type.
 */
typedef enum {
  GMCMC_BURN_IN,
  GMCMC_POSTERIOR
} GMCMC_ITERATION;

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
   * How often to adapt the step sizes.  Set to 1 for every iteration.
   */
  unsigned int adapt_rate;

  /**
   * Upper bound for step sizes.
   */
  double upper_step_size;

  /**
   * Lower bound for step sizes.
   */
  double lower_step_size;

  /**
   * If this function is not NULL it is called every adapt_rate iterations to
   * report the current mutation and exchange acceptance ratios for each chain
   * along with the current step size.  The step size only changes during the
   * burn in stage.
   *
   * @param [in] options    the simulation options
   * @param [in] model      the model
   * @param [in] iteration  whether this is a burn in or posterior iteration
   * @param [in] i          the current iteration
   * @param [in] mutation   the mutation acceptance ratios for each temperature
   * @param [in] exchange   the exchange acceptance ratios for each temperature
   * @param [in] stepsize   the new step sizes for each temperature
   */
  void (*acceptance)(const struct gmcmc_popmcmc_options *, const gmcmc_model *,
                     GMCMC_ITERATION, size_t, const double *, const double *,
                     const double *);
  /**
  * Stores a sample in a global array that is later written to a Matlab file.
  *
  * @param [in] options         the MCMC options
  * @param [in] model           the model
  * @param [in] iteration       whether the current iteration is from burn in
  *                               (GMCMC_BURN_IN) or posterior (GMCMC_POSTERIOR)
  * @param [in] i               the current iteration number
  * @param [in] j               the index on the temperature scale
  * @param [in] params          the current parameter values
  * @param [in] log_prior       the log prior of the sample
  * @param [in] log_likelihood  the log likelihood of the sample
  *
  * @return zero on success, non-zero on failure.
  */
  int (*write)(const struct gmcmc_popmcmc_options *, const gmcmc_model *,
               GMCMC_ITERATION, size_t, size_t, const double *, const double *,
               double);

} gmcmc_popmcmc_options;

/**
 * Performs a population MCMC simulation sequentially using a single CPU thread.
 *
 * @param [in] options  MCMC options struct
 * @param [in] model    the model to use in the simulation
 * @param [in] data     the data to use in the simulation
 * @param [in] rng      a parallel RNG to use
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc(const gmcmc_popmcmc_options *, const gmcmc_model *,
                  const gmcmc_dataset *, const gmcmc_prng64 *);

/**
 * Performs a population MCMC simulation in parallel using OpenMP to update all
 * the chains in parallel.
 *
 * @param [in] options  MCMC options struct
 * @param [in] model    the model to use in the simulation
 * @param [in] data     the data to use in the simulation
 * @param [in] rng      a parallel RNG to use
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc_omp(const gmcmc_popmcmc_options *, const gmcmc_model *,
                      const gmcmc_dataset *, const gmcmc_prng64 *);

/**
 * Performs a population MCMC simulation in parallel using MPI to update all
 * the chains in parallel.  All callback functions are executed on the node
 * with rank 0.
 *
 * @param [in] options  MCMC options struct
 * @param [in] model    the model to use in the simulation
 * @param [in] data     the data to use in the simulation
 * @param [in] rng      a parallel RNG to use
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc_mpi(const gmcmc_popmcmc_options *, const gmcmc_model *,
                      const gmcmc_dataset *, const gmcmc_prng64 *);

#endif /* GMCMC_POPMCMC_H */
