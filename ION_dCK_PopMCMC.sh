#!/bin/sh
#PBS -l walltime=0:05:00
#PBS -l select=2:ncpus=8:mem=512mb

module load hdf5 intel-suite

export LD_LIBRARY_PATH=${HOME}/lib64:/apps/openmpi/1.6.0/lib:${LD_LIBRARY_PATH}
export PATH=/apps/openmpi/1.6.0/bin:${PATH}

mpiexec ${HOME}/GMCMC/ION_dCK_PopMCMC -t16 --dataset=${HOME}/GMCMC/data/ION_dCK_0,5s.h5 ${HOME}/results/ION_dCK_PopMCMC_BurnIn.h5 ${HOME}/results/ION_dCK_PopMCMC_Posterior.h5
