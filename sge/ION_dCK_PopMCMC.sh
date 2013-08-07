#!/bin/bash
#$ -cwd
#$ -j y
# -S /bin/bash
export MPI_ROOT=/share/apps/openmpi-1.6
export MATLAB_ROOT=/share/apps/matlabR2013a
export MATLAB_ARCH=glnxa64
export PATH=${HOME}/bin:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:${MPI_ROOT}/bin:${PATH}
export LD_LIBRARY_PATH=${HOME}/lib64:${MPI_ROOT}/lib:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:${MATLAB_ROOT}/sys/os/${MATLAB_ARCH}:/opt/gridengine/lib/lx26-amd64
${MPI_ROOT}/bin/mpirun -n ${NSLOTS} ./ION_dCK_PopMCMC ${num_chains} ${num_samples} results/ION_dCK
exit 0
