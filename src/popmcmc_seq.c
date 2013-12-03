/**
 * Performs a population MCMC simulation in a single thread without the need to
 * use MPI.  This is mainly for debugging purposes.
 *
 * @param [in] options  MCMC options struct
 * @param [in] model    the model to use in the simulation
 * @param [in] data     the data to use in the simulation
 * @param [in] rng      a RNG to use
 *
 * @return 0 on success, non-zero on error.
 */
int gmcmc_popmcmc_seq(const gmcmc_model * model, const void * data,
                      gmcmc_likelihood_function likelihood,
                      gmcmc_proposal_function proposal,
                      const gmcmc_popmcmc_options * options, const gmcmc_prng64 * rng) {
  int error;


  /*
   * Initialise chains
   */

  const size_t num_chains = options->num_temperatures;  // Number of chains in the simulation
  const size_t num_blocks = gmcmc_model_get_num_blocks(model);

  gmcmc_chain ** chains;
  // Create an array big enough to hold all the chains in the simulation
  if ((chains = malloc(num_chains * sizeof(gmcmc_chain *))) == NULL)
    GMCMC_ERROR("Unable to allocate chains array", GMCMC_ENOMEM);

  for (size_t j = 0; j < num_chains; j++) {
    // Allocate each chain
    if ((error = gmcmc_chain_alloc(&chains[j], options->temperatures[j], model)) != 0) {
      // Destroy any chains already created
      for (size_t k = 0; k < j; k++)
        gmcmc_chain_free(chains[j]);
      free(chains);
      GMCMC_ERROR("Unable to allocate chain", GMCMC_ENOMEM);
    }

    // Initialise each chain
    if ((error = gmcmc_chain_init(chains[j], model, data, likelihood, rng)) != 0) {
      // Destroy any chains already created
      for (size_t k = 0; k < j; k++)
        gmcmc_chain_free(chains[j]);
      free(chains);
      GMCMC_ERROR("Failed to initialise chain", GMCMC_ENOMEM);
    }
  }

  double * mutations = NULL, * stepsizes = NULL, * exchanges = NULL;
  if ((mutations = malloc(num_chains * num_blocks * sizeof(double))) == NULL ||
      (stepsizes = malloc(num_chains * num_blocks * sizeof(double))) == NULL ||
      (exchanges = malloc(num_chains * sizeof(double))) == NULL) {
    for (size_t k = 0; k < num_chains; k++)
      gmcmc_chain_free(chains[k]);
    free(chains);
    GMCMC_ERROR("Failed to allocate memory for acceptance ratios", GMCMC_ENOMEM);
  }


  /*
   * Burn-in loop
   */
  for (size_t i = 0; i < options->num_burn_in_samples; i++) {
    // Update each chain
    for (size_t j = 0; j < num_chains; j++) {
      if ((error = gmcmc_chain_update(chains[j], model, data, likelihood, proposal, rng)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_free(chains[k]);
        free(chains);
        free(mutations);
        free(exchanges);
        free(stepsizes);
        GMCMC_ERROR("Error updating chains", error);
      }
    }

    // Exchange chains between temperatures
    if ((error = gmcmc_chain_exchange(chains, num_chains, rng)) != 0) {
      for (size_t k = 0; k < num_chains; k++)
        gmcmc_chain_free(chains[k]);
      free(chains);
      free(mutations);
      free(exchanges);
      free(stepsizes);
      GMCMC_ERROR("Error exchanging chains", error);
    }

    // Adjust parameter proposal widths
    if (i % options->adapt_rate == 0) {
      double lower_stepsize, upper_stepsize;
      gmcmc_model_get_stepsize_bounds(model, &lower_stepsize, &upper_stepsize);

      // For each chain in the population
      for (size_t j = 0; j < num_chains; j++) {
        // For each block in the chain
        for (size_t k = 0; k < num_blocks; k++) {
          // Adjust proposal width for parameter value inference
          mutations[j * num_blocks + k] = chains[j]->accepted_mutation[k] /
                                          (double)chains[j]->attempted_mutation[k];

          // Don't update chain 0 unless it is the only chain
          if (j > 0 || options->num_temperatures == 1) {
            if (mutations[j * num_blocks + k] < options->lower_acceptance_rate)
              chains[j]->stepsize[k] = fmax(chains[j]->stepsize[k] * 0.8, lower_stepsize);
            else if (mutations[j * num_blocks + k] > options->upper_acceptance_rate)
              chains[j]->stepsize[k] = fmin(chains[j]->stepsize[k] * 1.2, upper_stepsize);
          }
          stepsizes[j * num_blocks + k] = chains[j]->stepsize[k];


          // Reset counters
          chains[j]->accepted_mutation[k] = 0;
          chains[j]->attempted_mutation[k] = 0;
        }

        exchanges[j] = chains[j]->accepted_exchange /
                        (double)chains[j]->attempted_exchange;
      }

      if (options->acceptance != NULL)
        options->acceptance(options, model, i, mutations,
                            exchanges, stepsizes);
    }

    // Write current samples to file
    if (options->burn_in_writer != NULL) {
      for (size_t j = 0; j < num_chains; j++) {
        if ((error = gmcmc_filewriter_write(options->burn_in_writer, i, j,
                                            chains[j]->params, chains[j]->log_prior,
                                            chains[j]->log_likelihood, chains[j]->stepsize)) != 0) {
          for (size_t k = 0; k < num_chains; k++)
            gmcmc_chain_free(chains[k]);
          free(chains);
          free(mutations);
          free(exchanges);
          free(stepsizes);
          GMCMC_ERROR("Error writing chains", error);
        }
      }
    }

  }     // burn-in

  // Posterior
  for (size_t i = 0; i < options->num_posterior_samples; i++) {

    // Update each chain
    for (size_t j = 0; j < num_chains; j++) {
      if ((error = gmcmc_chain_update(chains[j], model, data, likelihood, proposal, rng)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_free(chains[k]);
        free(chains);
        free(mutations);
        free(exchanges);
        free(stepsizes);
        GMCMC_ERROR("Error updating chains", error);
      }
    }

    // Exchange chains between temperatures
    if ((error = gmcmc_chain_exchange(chains, num_chains, rng)) != 0) {
      for (size_t k = 0; k < num_chains; k++)
        gmcmc_chain_free(chains[k]);
      free(chains);
      free(mutations);
      free(exchanges);
      free(stepsizes);
      GMCMC_ERROR("Error exchanging chains", error);
    }

    // Adjust parameter proposal widths
    if (i % options->adapt_rate == 0) {
      double lower_stepsize, upper_stepsize;
      gmcmc_model_get_stepsize_bounds(model, &lower_stepsize, &upper_stepsize);

      // For each chain in the population
      for (size_t j = 0; j < num_chains; j++) {
        // For each block in the chain
        for (size_t k = 0; k < num_blocks; k++) {
          // Adjust proposal width for parameter value inference
          mutations[j * num_blocks + k] = chains[j]->accepted_mutation[k] /
                                          (double)chains[j]->attempted_mutation[k];

          stepsizes[j * num_blocks + k] = chains[j]->stepsize[k];


          // Reset counters
          chains[j]->accepted_mutation[k] = 0;
          chains[j]->attempted_mutation[k] = 0;
        }

        exchanges[j] = chains[j]->accepted_exchange /
                        (double)chains[j]->attempted_exchange;
      }

      if (options->acceptance != NULL)
        options->acceptance(options, model, options->num_burn_in_samples + i, mutations,
                            exchanges, stepsizes);
    }

    // Write current samples to file
    for (size_t j = 0; j < num_chains; j++) {
      if ((error = gmcmc_filewriter_write(options->posterior_writer, i, j,
                                          chains[j]->params, chains[j]->log_prior,
                                          chains[j]->log_likelihood, chains[j]->stepsize)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_free(chains[k]);
        free(chains);
        free(mutations);
        free(exchanges);
        free(stepsizes);
        GMCMC_ERROR("Error writing chains", error);
      }
    }


  }     // Posterior loop

  // Clean up
  free(mutations);
  free(exchanges);
  free(stepsizes);
  for (size_t j = 0; j < num_chains; j++)
    gmcmc_chain_free(chains[j]);
  free(chains);
  if ((error = gmcmc_filewriter_close(options->posterior_writer)) != 0)
    GMCMC_ERROR("Error closing posterior file", error);

  return 0;
}
