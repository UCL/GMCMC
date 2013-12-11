static int gmcmc_chain_mpi_send(const gmcmc_chain *, int, int, MPI_Comm);
static int gmcmc_chain_mpi_recv(gmcmc_chain *, int, int, MPI_Comm);

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
int gmcmc_popmcmc_mpi(const gmcmc_model * model, const void * data,
                      gmcmc_likelihood_function likelihood,
                      gmcmc_proposal_function proposal,
                      const gmcmc_popmcmc_options * options, const gmcmc_prng64 * rng) {
  int error;

  // Get the total number of processes and the rank of this one
  int size, rank;
  if (MPI_Comm_size(MPI_COMM_WORLD, &size) != MPI_SUCCESS)
    GMCMC_ERROR("Failed to get MPI communicator size", GMCMC_EIPC);
  if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS)
    GMCMC_ERROR("Failed to get MPI process rank", GMCMC_EIPC);


  /*
   * Initialise chains
   */

  const size_t num_chains = options->num_temperatures;  // Number of chains in the simulation
  const size_t num_local_chains = (num_chains / size) + ((unsigned int)rank < num_chains % size);     // Number of chains on each slave node
  const size_t num_blocks = gmcmc_model_get_num_blocks(model);

  gmcmc_chain ** chains;
  double * mutations = NULL, * stepsizes = NULL, * exchanges = NULL;
  if (rank == 0) {
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

      // Only initialise the chains this node is responsible for updating
      if (j % size == 0) {
        if ((error = gmcmc_chain_init(chains[j], model, data, likelihood, rng)) != 0) {
          // Destroy any chains already created
          for (size_t k = 0; k < j; k++)
            gmcmc_chain_free(chains[j]);
          free(chains);
          GMCMC_ERROR("Failed to initialise chain", GMCMC_ENOMEM);
        }
      }
    }

    if ((mutations = malloc(num_chains * num_blocks * sizeof(double))) == NULL ||
        (stepsizes = malloc(num_chains * num_blocks * sizeof(double))) == NULL ||
        (exchanges = malloc(num_chains * sizeof(double))) == NULL) {
      for (size_t k = 0; k < num_chains; k++)
        gmcmc_chain_free(chains[k]);
      free(chains);
      GMCMC_ERROR("Failed to allocate memory for acceptance ratios", GMCMC_ENOMEM);
    }
  }
  else {
    // Create an array only for the chains on each node
    if ((chains = malloc(num_local_chains * sizeof(gmcmc_chain *))) == NULL)
      GMCMC_ERROR("Unable to allocate chains array", GMCMC_ENOMEM);

    for (size_t i = rank, j = 0; j < num_local_chains; j++, i += size) {
      // Allocate each chain
      if ((error = gmcmc_chain_alloc(&chains[j], options->temperatures[i], model)) != 0) {
        // Destroy any chains already created
        for (size_t k = 0; k < j; k++)
          gmcmc_chain_free(chains[j]);
        free(chains);
        GMCMC_ERROR("Unable to allocate chain", GMCMC_ENOMEM);
      }

      // Only initialise the chains this node is responsible for updating
      if ((error = gmcmc_chain_init(chains[j], model, data, likelihood, rng)) != 0) {
        // Destroy any chains already created
        for (size_t k = 0; k < j; k++)
          gmcmc_chain_free(chains[j]);
        free(chains);
        GMCMC_ERROR("Failed to initialise chain", GMCMC_ENOMEM);
      }
    }
  }


  /*
   * Burn-in loop
   */
  for (size_t i = 0; i < options->num_burn_in_samples; i++) {
    // On the master process
    if (rank == 0) {
      // Update each chain
      for (size_t j = 0; j < num_chains; j += size) {
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

      // Receive all chains from other processes
      for (size_t j = 0; j < num_chains; j++) {
        // If the chain is not already on this node
        if (j % size != (unsigned int)rank) {
          // Receive it from the other node
          if ((error = gmcmc_chain_mpi_recv(chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_free(chains[k]);
            free(chains);
            free(mutations);
            free(exchanges);
            free(stepsizes);
            GMCMC_ERROR("Error receiving chains", error);
          }
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

      // Copy chains back onto other nodes
      for (size_t j = 0; j < num_chains; j++) {
        // If chain does not belong on this node
        if (j % size != (unsigned int)rank) {
          // Send it to the other node
          if ((error = gmcmc_chain_mpi_send(chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_free(chains[k]);
            free(chains);
            free(mutations);
            free(exchanges);
            free(stepsizes);
            GMCMC_ERROR("Error sending chains", error);
          }
        }
      }
    }   // rank == 0
    else {
      // Update each chain in the population in parallel
      for (size_t j = 0; j < num_local_chains; j++) {
        if ((error = gmcmc_chain_update(chains[j], model, data, likelihood, proposal, rng)) != 0) {
          for (size_t k = 0; k < num_local_chains; k++)
            gmcmc_chain_free(chains[k]);
          free(chains);
          GMCMC_ERROR("Error updating chains", error);
        }
      }

      // Send the chains to process 0 to exchange them and adapt the step sizes
      int tag = rank;
      for (size_t j = 0; j < num_local_chains; j++, tag += size) {
        if ((error = gmcmc_chain_mpi_send(chains[j], 0, tag, MPI_COMM_WORLD)) != 0) {
          for (size_t k = 0; k < num_local_chains; k++)
            gmcmc_chain_free(chains[k]);
          free(chains);
          GMCMC_ERROR("Error sending chains", error);
        }
      }

      // Receive the chains back from node 0
      tag = rank;
      for (size_t j = 0; j < num_local_chains; j++, tag += size) {
        if ((error = gmcmc_chain_mpi_recv(chains[j], 0, tag, MPI_COMM_WORLD)) != 0) {
          for (size_t k = 0; k < num_local_chains; k++)
            gmcmc_chain_free(chains[k]);
          free(chains);
          GMCMC_ERROR("Error receiving chains", error);
        }
      }
    }   // rank != 0


  }     // burn-in

  if (rank == 0) {
    if (options->burn_in_writer != NULL) {
      if ((error = gmcmc_filewriter_close(options->burn_in_writer)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_free(chains[k]);
        free(chains);
        free(mutations);
        free(exchanges);
        free(stepsizes);
        GMCMC_ERROR("Error closing burn-in file", error);
      }
    }
  }

  // Posterior
  for (size_t i = 0; i < options->num_posterior_samples; i++) {
    // On the master process
    if (rank == 0) {
      // Update each chain
      for (size_t j = 0; j < num_chains; j += size) {
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

      // Receive all chains from other processes
      for (size_t j = 0; j < num_chains; j++) {
        // If the chain is not already on this node
        if (j % size != (unsigned int)rank) {
          // Receive it from the other node
          if ((error = gmcmc_chain_mpi_recv(chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_free(chains[k]);
            free(chains);
            free(mutations);
            free(exchanges);
            free(stepsizes);
            GMCMC_ERROR("Error receiving chains", error);
          }
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

      // Copy chains back onto other nodes
      for (size_t j = 0; j < num_chains; j++) {
        // If chain does not belong on this node
        if (j % size != (unsigned int)rank) {
          // Send it to the other node
          if ((error = gmcmc_chain_mpi_send(chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_free(chains[k]);
            free(chains);
            free(mutations);
            free(exchanges);
            free(stepsizes);
            GMCMC_ERROR("Error sending chains", error);
          }
        }
      }
    }   // rank == 0
    else {
      // Update each chain in the population in parallel
      for (size_t j = 0; j < num_local_chains; j++) {
        if ((error = gmcmc_chain_update(chains[j], model, data, likelihood, proposal, rng)) != 0) {
          for (size_t k = 0; k < num_local_chains; k++)
            gmcmc_chain_free(chains[k]);
          free(chains);
          GMCMC_ERROR("Error updating chains", error);
        }
      }

      // Send the chains to process 0 to exchange them and adapt the step sizes
      int tag = rank;
      for (size_t j = 0; j < num_local_chains; j++, tag += size) {
        if ((error = gmcmc_chain_mpi_send(chains[j], 0, tag, MPI_COMM_WORLD)) != 0) {
          for (size_t k = 0; k < num_local_chains; k++)
            gmcmc_chain_free(chains[k]);
          free(chains);
          GMCMC_ERROR("Error sending chains", error);
        }
      }

      // Receive the chains back from node 0
      tag = rank;
      for (size_t j = 0; j < num_local_chains; j++, tag += size) {
        if ((error = gmcmc_chain_mpi_recv(chains[j], 0, tag, MPI_COMM_WORLD)) != 0) {
          for (size_t k = 0; k < num_local_chains; k++)
            gmcmc_chain_free(chains[k]);
          free(chains);
          GMCMC_ERROR("Error receiving chains", error);
        }
      }
    }   // rank != 0


  }     // Posterior loop

  // Clean up
  if (rank == 0) {
    free(mutations);
    free(exchanges);
    free(stepsizes);
    for (size_t j = 0; j < num_chains; j++)
      gmcmc_chain_free(chains[j]);
    if ((error = gmcmc_filewriter_close(options->posterior_writer)) != 0) {
      free(chains);
      GMCMC_ERROR("Error closing posterior file", error);
    }
  }
  else {
    for (size_t j = 0; j < num_local_chains; j++)
      gmcmc_chain_free(chains[j]);
  }
  free(chains);

  return 0;
}

/**
 * Sends a chain over MPI.
 *
 * @param [in] chain  the chain to send
 * @param [in] dest   the rank of the destination node
 * @param [in] tag    the index of the chain
 * @param [in] comm   the MPI communicator
 *
 * @return 0 on success,
 *         GMCMC_EIPC if parts of the chain could not be sent.
 */
static int gmcmc_chain_mpi_send(const gmcmc_chain * chain, int dest, int tag, MPI_Comm comm) {
  // Send every field of the chain struct in the same order as they are received
  int error;

  if ((error = MPI_Send(chain->stepsize, chain->num_blocks, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending chain step size", GMCMC_EIPC);

#if MPI_VERSION < 2
  if ((error = MPI_Send(chain->accepted_mutation, chain->num_blocks * 8, MPI_BYTE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending accepted mutation", GMCMC_EIPC);

  if ((error = MPI_Send(chain->attempted_mutation, chain->num_blocks * 8, MPI_BYTE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending attempted mutation", GMCMC_EIPC);
#else
  if ((error = MPI_Send(chain->accepted_mutation, chain->num_blocks, MPI_UINT64_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending accepted mutation", GMCMC_EIPC);

  if ((error = MPI_Send(chain->attempted_mutation, chain->num_blocks, MPI_UINT64_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending attempted mutation", GMCMC_EIPC);
#endif

  if ((error = MPI_Send(chain->params, chain->num_params, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending parameter values", GMCMC_EIPC);

  if ((error = MPI_Send(chain->log_prior, chain->num_params, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending log prior", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->log_likelihood, 1, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending log likelihood", GMCMC_EIPC);

  return 0;
}

/**
 * Receives a chain over MPI.
 *
 * @param [in] chain   a pointer to the chain to copy into
 * @param [in] source  the rank of the node to copy the chain from
 * @param [in] tag     the index of the chain
 * @param [in] comm    the MPI communicator
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if the chain (or parts of it) needed to be allocated
 *                        and it failed,
 *         GMCMC_EIPC   if parts of the chain could not be received.
 */
static int gmcmc_chain_mpi_recv(gmcmc_chain * chain, int source, int tag, MPI_Comm comm) {
  // Receive every field of the chain struct in the same order as they are sent
  int error;

  if ((error = MPI_Recv(chain->stepsize, chain->num_blocks, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving chain step size", GMCMC_EIPC);

#if MPI_VERSION < 2
  if ((error = MPI_Recv(chain->accepted_mutation, chain->num_blocks * 8, MPI_BYTE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving accepted mutation", GMCMC_EIPC);

  if ((error = MPI_Recv(chain->attempted_mutation, chain->num_blocks * 8, MPI_BYTE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving attempted mutation", GMCMC_EIPC);
#else
  if ((error = MPI_Recv(chain->accepted_mutation, chain->num_blocks, MPI_UINT64_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving accepted mutation", GMCMC_EIPC);

  if ((error = MPI_Recv(chain->attempted_mutation, chain->num_blocks, MPI_UINT64_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving attempted mutation", GMCMC_EIPC);
#endif

  if ((error = MPI_Recv(chain->params, chain->num_params, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving parameter values", GMCMC_EIPC);

  if ((error = MPI_Recv(chain->log_prior, chain->num_params, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving log prior", GMCMC_EIPC);

  if ((error = MPI_Recv(&chain->log_likelihood, 1, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving log likelihood", GMCMC_EIPC);

  return 0;
}
