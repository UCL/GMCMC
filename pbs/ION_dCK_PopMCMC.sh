#!/bin/sh
#
# PBS qsub script for Castillo Katz ion channel model using Metropolis Hastings
#
# Specify a maximum execution time of 2 hours
#PBS -l walltime=2:00:00
#
# Ask to run on 2 nodes, each with 8 cores, with 2GB RAM per node
# (i.e. 16 cores in total with 256mb RAM per core)
#PBS -l select=2:ncpus=8:mem=2gb
#

# Load MPI, Intel MKL and HDF5
module load mpi intel-suite hdf5

# Run the program using mpiexec (PBS requires absolute paths to the dataset and result files)
mpiexec ${HOME}/GMCMC/ION_dCK_PopMCMC --dataset=${HOME}/GMCMC/data/ION_dCK_0,5s.h5 ${HOME}/results/ION_dCK_PopMCMC_BurnIn.h5 ${HOME}/results/ION_dCK_PopMCMC_Posterior.h5
