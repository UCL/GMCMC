#!/bin/sh
#PBS -l walltime=0:05:00
#PBS -l select=2:ncpus=8:mem=512mb

module load mpi intel-suite hdf5
export LD_LIBRARY_PATH=${HOME}/lib64:${LD_LIBRARY_PATH}

mpiexec ${HOME}/GMCMC/FitzHugh_Benchmark_Simp_mMALA -t16 --dataset=${HOME}/GMCMC/data/FitzHugh_Benchmark_Data_1000.h5 ${HOME}/results/FitzHugh_Simp_mMALA_BurnIn.h5 ${HOME}/results/FitzHugh_Simp_mMALA_Posterior.h5
