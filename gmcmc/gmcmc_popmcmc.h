/*
 * gmcmc_popmcmc.h
 *
 *  Created on: 11 June 2013
 *      Author: Gary Macindoe
 */

#ifndef GMCMC_POPMCMC_H
#define GMCMC_POPMCMC_H

#include <gmcmc/gmcmc_model.h>

typedef struct {
  const char * outputID;
  bool save_burn_in;
  unsigned int num_temps;
  const double * temperatures;
  unsigned long num_burn_in_samples;
  unsigned long num_posterior_samples;
  unsigned long posterior_save_size;
  double adapt_rate;
  double upper;
  double lower;
} gmcmc_popmcmc_options;

int gmcmc_popmcmc_mpi(const gmcmc_popmcmc_options *, const gmcmc_model *, gmcmc_prng64 *);

#endif /* GMCMC_POPMCMC_H */
