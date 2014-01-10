#!/bin/sh
#
# PBS qsub script for Locke ODE model using Simplified mMALA
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
mpiexec ${HOME}/GMCMC/Locke_Benchmark_MH --dataset ${HOME}/GMCMC/data/Locke_Benchmark_Data.mat ${HOME}/GMCMC/results/Locke_Simp_mMALA_BurnIn.h5 ${HOME}/GMCMC/results/Locke_Simp_mMALA_Posterior.h5

exit 0
