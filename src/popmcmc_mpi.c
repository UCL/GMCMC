static int gmcmc_chain_mpi_send(const gmcmc_chain *, int, int, MPI_Comm);
static int gmcmc_chain_mpi_recv(gmcmc_chain **, int, int, MPI_Comm);

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

  // Create an array big enough to hold all the chains in the simulation
  const size_t num_chains = options->num_temperatures;
  gmcmc_chain ** chains;
  if ((chains = calloc(num_chains, sizeof(gmcmc_chain *))) == NULL)     // Use calloc so they're all initialised to NULL
    GMCMC_ERROR("Unable to allocate chains", GMCMC_ENOMEM);

  // Initialise only the chains needed on each node
  for (size_t j = rank; j < num_chains; j += size) {
    if ((error = gmcmc_chain_create(&chains[j], model, data, options->temperatures[j], rng)) != 0) {
      // Destroy any chains already created
      for (size_t k = rank; k < j; k += size)
        gmcmc_chain_destroy(chains[k]);
      free(chains);
      GMCMC_ERROR("Unable to initialise chains", error);
    }
  }

  // Burn-in loop
  for (size_t i = 0; i < options->num_burn_in_samples; i++) {
    // Update each chain in the population in parallel
    for (size_t j = rank; j < num_chains; j += size) {
      if ((error = gmcmc_chain_update(chains[j], model, data, rng)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_destroy(chains[k]);
        free(chains);
        GMCMC_ERROR("Error updating chains", error);
      }
    }

    // Copy all the chains onto node 0
    if (rank == 0) {
      // Loop through all the chains
      for (size_t j = 0; j < num_chains; j++) {
        if (j % size != (unsigned int)rank) { // If the chain is not already on this node
          // Receive it from another node (if it is NULL it will be allocated)
          if ((error = gmcmc_chain_mpi_recv(&chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error receiving chains", error);
          }
        }
      }
    }
    else {
      // Loop through all the chains that are on this node
      for (size_t j = rank; j < num_chains; j += size) {
        // Send the chain to node 0
        if ((error = gmcmc_chain_mpi_send(chains[j], 0, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error sending chains", error);
        }
      }
    }


    // Do the serial exchange and step size adjustment (and callbacks) on node 0
    if (rank == 0) {
      // Exchange chains between temperatures
      gmcmc_chain_exchange(chains, num_chains, rng);

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
    }

    // Copy chains back onto other nodes
    if (rank == 0) {
      // Loop through all the chains
      for (size_t j = 0; j < num_chains; j++) {
        if (j % size != (unsigned int)rank) { // If the chain is not already on this node
          // Send it to another node
          if ((error = gmcmc_chain_mpi_send(chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error sending chains", error);
          }
        }
      }
    }
    else {
      // Loop through all the chains that are on this node
      for (size_t j = rank; j < num_chains; j += size) {
        // Receive the chain from node 0
        if ((error = gmcmc_chain_mpi_recv(&chains[j], 0, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error receiving chains", error);
        }
      }
    }


  }     // burn-in

  // Posterior
  for (size_t i = 0; i < options->num_posterior_samples; i++) {
    // Update each chain in the population in parallel
    for (size_t j = rank; j < num_chains; j += size) {
      if ((error = gmcmc_chain_update(chains[j], model, data, rng)) != 0) {
        for (size_t k = 0; k < num_chains; k++)
          gmcmc_chain_destroy(chains[k]);
        free(chains);
        GMCMC_ERROR("Error updating chains", error);
      }
    }

    // Copy all the chains onto node 0
    if (rank == 0) {
      // Loop through all the chains
      for (size_t j = 0; j < num_chains; j++) {
        if (j % size != (unsigned int)rank) { // If the chain is not already on this node
          // Receive it from another node (if it is NULL it will be allocated)
          if ((error = gmcmc_chain_mpi_recv(&chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error receiving chains", error);
          }
        }
      }
    }
    else {
      // Loop through all the chains that are on this node
      for (size_t j = rank; j < num_chains; j += size) {
        // Send the chain to node 0
        if ((error = gmcmc_chain_mpi_send(chains[j], 0, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error sending chains", error);
        }
      }
    }


    if (rank == 0) {
      // Exchange chains between temperatures
      gmcmc_chain_exchange(chains, num_chains, rng);

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
    }

    // Copy chains back onto other nodes
    if (rank == 0) {
      // Loop through all the chains
      for (size_t j = 0; j < num_chains; j++) {
        if (j % size != (unsigned int)rank) { // If the chain is not already on this node
          // Send it to another node
          if ((error = gmcmc_chain_mpi_send(chains[j], j % size, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error sending chains", error);
          }
        }
      }
    }
    else {
      // Loop through all the chains that are on this node
      for (size_t j = rank; j < num_chains; j += size) {
        // Receive the chain from node 0
        if ((error = gmcmc_chain_mpi_recv(&chains[j], 0, j, MPI_COMM_WORLD)) != 0) {
            for (size_t k = 0; k < num_chains; k++)
              gmcmc_chain_destroy(chains[k]);
            free(chains);
            GMCMC_ERROR("Error receiving chains", error);
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
  if ((error = MPI_Send((void *)&chain->temperature, 1, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending chain temperature", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->stepsize, 1, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending chain step size", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->accepted_mutation, 1, MPI_UINT64_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending accepted mutation", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->attempted_mutation, 1, MPI_UINT64_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending attempted mutation", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->accepted_exchange, 1, MPI_UINT64_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending accepted exchange", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->attempted_exchange, 1, MPI_UINT64_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending attempted exchange", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->n, 1, MPI_UINT32_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending number of parameters", GMCMC_EIPC);

  if ((error = MPI_Send(chain->params, chain->n, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending parameter values", GMCMC_EIPC);

  if ((error = MPI_Send(chain->log_prior, chain->n, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending log prior", GMCMC_EIPC);

  if ((error = MPI_Send((void *)&chain->log_likelihood, 1, MPI_DOUBLE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending log likelihood", GMCMC_EIPC);

  uint64_t size = (uint64_t)chain->size;
  if ((error = MPI_Send(&size, 1, MPI_UINT64_T, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending chain specific data size", GMCMC_EIPC);

  if ((error = MPI_Send(chain->chainspecific, chain->size, MPI_BYTE, dest, tag, comm)) != 0)
    GMCMC_ERROR("Error sending chain specific data", GMCMC_EIPC);

  return 0;
}

/**
 * Receives a chain over MPI.
 *
 * @param [in] chain   a pointer to the chain to copy into.  If it is NULL it
 *                       will be allocated
 * @param [in] source  the rank of the node to copy the chain from
 * @param [in] tag     the index of the chain
 * @param [in] comm    the MPI communicator
 *
 * @return 0 on success,
 *         GMCMC_ENOMEM if the chain (or parts of it) needed to be (re)allocated
 *                        and it failed,
 *         GMCMC_EIPC   if parts of the chain could not be received.
 */
static int gmcmc_chain_mpi_recv(gmcmc_chain ** chain, int source, int tag, MPI_Comm comm) {
  if (*chain == NULL) {
    if ((*chain = calloc(1, sizeof(gmcmc_chain))) == NULL)      // calloc to initialise pointers to NULL
      GMCMC_ERROR("Failed to allocate chain", GMCMC_ENOMEM);
  }

  // Receive every field of the chain struct in the same order as they are sent
  int error;
  if ((error = MPI_Recv(&(*chain)->temperature, 1, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving chain temperature", GMCMC_EIPC);

  if ((error = MPI_Recv(&(*chain)->stepsize, 1, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving chain step size", GMCMC_EIPC);

  if ((error = MPI_Recv(&(*chain)->accepted_mutation, 1, MPI_UINT64_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving accepted mutation", GMCMC_EIPC);

  if ((error = MPI_Recv(&(*chain)->attempted_mutation, 1, MPI_UINT64_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving attempted mutation", GMCMC_EIPC);

  if ((error = MPI_Recv(&(*chain)->accepted_exchange, 1, MPI_UINT64_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving accepted exchange", GMCMC_EIPC);

  if ((error = MPI_Recv(&(*chain)->attempted_exchange, 1, MPI_UINT64_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving attempted exchange", GMCMC_EIPC);

  uint32_t n;
  if ((error = MPI_Recv(&n, 1, MPI_UINT32_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving number of parameters", GMCMC_EIPC);

  // If the parameter vector needs to be resized or allocated
  if (n != (*chain)->n || (*chain)->params == NULL || (*chain)->log_prior == NULL) {
    free((*chain)->params);
    free((*chain)->log_prior);

    (*chain)->n = n;
    if (((*chain)->params = malloc(n * sizeof(double))) == NULL)
      GMCMC_ERROR("Failed to allocate chain parameters", GMCMC_ENOMEM);
    if (((*chain)->log_prior = malloc(n * sizeof(double))) == NULL)
      GMCMC_ERROR("Failed to allocate chain log prior", GMCMC_ENOMEM);
  }

  if ((error = MPI_Recv((*chain)->params, n, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving parameter values", GMCMC_EIPC);

  if ((error = MPI_Recv((*chain)->log_prior, n, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving log prior", GMCMC_EIPC);

  if ((error = MPI_Recv(&(*chain)->log_likelihood, 1, MPI_DOUBLE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving log likelihood", GMCMC_EIPC);

  uint64_t size;
  if ((error = MPI_Recv(&size, 1, MPI_UINT64_T, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving chain specific data size", GMCMC_EIPC);

  // If the area for chain specific data needs to be resized
  if (size != (*chain)->size) {
    free((*chain)->chainspecific);

    if (((*chain)->chainspecific = malloc(size)) == NULL)
      GMCMC_ERROR("Failed to allocate chain specific data", GMCMC_ENOMEM);
    (*chain)->size = size;
  }

  if ((error = MPI_Recv((*chain)->chainspecific, size, MPI_BYTE, source, tag, comm, MPI_STATUS_IGNORE)) != 0)
    GMCMC_ERROR("Error receiving chain specific data", GMCMC_EIPC);

  return 0;
}
