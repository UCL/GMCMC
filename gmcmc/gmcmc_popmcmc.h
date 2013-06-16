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
 * MCMC simulation options.
 */
typedef struct {
  const char * outputID;                /**< Output file base name */
  bool save_burn_in;                    /**< Whether or not to save samples from burn-in */
  unsigned int num_temps;               /**< Number of temperatures for population MCMC */
  const double * temperatures;          /**< Population MCMC temperature scale */
  unsigned long num_burn_in_samples;    /**< Number of samples required to burn-in the sampler */
  unsigned long num_posterior_samples;  /**< Number of posterior samples to simulate after burn-in */
  unsigned long posterior_save_size;    /**< How often to write the posterior samples to file */
  double adapt_rate;                    /**< Step size adapt rate */
  double upper;                         /**< Upper bound for step size */
  double lower;                         /**< Lower bound for step size */
} gmcmc_popmcmc_options;

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
int gmcmc_popmcmc_mpi(const gmcmc_popmcmc_options *, const gmcmc_model *, const gmcmc_dataset *, const gmcmc_prng64 *);

#endif /* GMCMC_POPMCMC_H */
