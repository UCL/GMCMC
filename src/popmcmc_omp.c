/**
 * Performs a population MCMC simulation in parallel using OpenMP.
 *
 * @param [in] options  MCMC options struct
 * @param [in] model    the model to use in the simulation
 * @param [in] data     the data to use in the simulation
 * @param [in] rngs     parallel RNGs to use (one per temperature)
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc_omp(const gmcmc_popmcmc_options * options,
                      const gmcmc_model * model, const gmcmc_dataset * data,
                      const gmcmc_prng64 ** rngs) {
  int error = 0;

  /*
   * Initialise chains
   */

  // Create an array big enough to hold all the chains in the simulation
  const size_t num_chains = options->num_temperatures;
  gmcmc_chain ** chains;
  if ((chains = calloc(num_chains, sizeof(gmcmc_chain *))) == NULL)     // Use calloc so they're all initialised to NULL
    GMCMC_ERROR("Unable to allocate chains", GMCMC_ENOMEM);

  // Initialise the chains
#pragma omp parallel for
  for (size_t j = 0; j < num_chains; j++) {
#pragma omp flush(error)
    if (error == 0) {
      int myerror = gmcmc_chain_create(&chains[j], model, data, options->temperatures[j], rngs[j]);
      if (myerror != 0) {
        error = myerror;
#pragma omp flush(error)
      }
    }
  }
  if (error != 0) {
    // Destroy any chains already created
    for (size_t k = 0; k < num_chains; k++)
      gmcmc_chain_destroy(chains[k]);
    free(chains);
    GMCMC_ERROR("Unable to initialise chains", error);
  }

  // Burn-in loop
  for (size_t i = 0; i < options->num_burn_in_samples; i++) {
    // Update each chain in the population in parallel
#pragma omp parallel for
    for (size_t j = 0; j < num_chains; j++) {
#pragma omp flush(error)
      if (error == 0) {
        int myerror = gmcmc_chain_update(chains[j], model, data, rngs[j]);
        if (myerror != 0) {
          error = myerror;
#pragma omp flush(error)
        }
      }
    }
    if (error != 0) {
      for (size_t k = 0; k < num_chains; k++)
        gmcmc_chain_destroy(chains[k]);
      free(chains);
      GMCMC_ERROR("Error updating chains", error);
    }


    // Exchange chains between temperatures
    gmcmc_chain_exchange(chains, num_chains, rngs[0]);

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
          if (mutations[j] < options->lower_acceptance_rate)
            chains[j]->stepsize *= 0.8;
          else if (mutations[j] > options->upper_acceptance_rate)
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
        options->acceptance(options, model, i, mutations,
                            exchanges, stepsizes);
    }

    // Write current samples to file
    if (options->write != NULL) {
      for (size_t j = 0; j < num_chains; j++) {
        if ((error = options->write(options, model, i, j,
                                    chains[j]->params, chains[j]->log_prior,
                                    chains[j]->log_likelihood)) != 0) {
          for (size_t k = 0; k < num_chains; k++)
            gmcmc_chain_destroy(chains[k]);
          free(chains);
          GMCMC_ERROR("Error writing chains", error);
        }
      }
    }

  }     // burn-in


  // Posterior
  for (size_t i = 0; i < options->num_posterior_samples; i++) {
    // Update each chain in the population in parallel
#pragma omp parallel for
    for (size_t j = 0; j < num_chains; j++) {
#pragma omp flush(error)
      if (error == 0) {
        int myerror = gmcmc_chain_update(chains[j], model, data, rngs[j]);
        if (myerror != 0) {
          error = myerror;
#pragma omp flush(error)
        }
      }
    }
    if (error != 0) {
      for (size_t k = 0; k < num_chains; k++)
        gmcmc_chain_destroy(chains[k]);
      free(chains);
      GMCMC_ERROR("Error updating chains", error);
    }


    // Exchange chains between temperatures
    gmcmc_chain_exchange(chains, num_chains, rngs[0]);

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
        options->acceptance(options, model, i + options->num_burn_in_samples, mutations,
                            exchanges, stepsizes);
    }

    // Write current sample to file
    if (options->write != NULL) {
      for (size_t j = 0; j < num_chains; j++) {
        if ((error = options->write(options, model, i + options->num_burn_in_samples, j,
                                    chains[j]->params, chains[j]->log_prior,
                                    chains[j]->log_likelihood)) != 0) {
          for (size_t k = 0; k < num_chains; k++)
            gmcmc_chain_destroy(chains[k]);
          free(chains);
          GMCMC_ERROR("Error writing chains", error);
        }
      }
    }

  }     // Posterior loop

  // Clean up
  for (size_t j = 0; j < num_chains; j++)
    gmcmc_chain_destroy(chains[j]);
  free(chains);

  return 0;
}
