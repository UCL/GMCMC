#!/bin/bash
#$ -cwd
#$ -j y
# -S /bin/bash
export MPI_ROOT=/share/apps/openmpi-1.6
export MATLAB_ROOT=/share/apps/matlabR2013a
export MATLAB_ARCH=glnxa64
export LD_LIBRARY_PATH=${HOME}/lib64:${MPI_ROOT}/lib:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:/opt/gridengine/lib/lx26-amd64
mpirun -n ${NSLOTS} ./ION_dCK_PopMCMC results/ION_dCK
exit 0
