#!/bin/bash
#$ -l h_vmem=1G,tmem=1G
#$ -cwd
#$ -j y
#$ -S /bin/bash
export MPI_ROOT=/share/apps/openmpi-1.6
export MATLAB_ROOT=/share/apps/matlabR2013a
export MATLAB_ARCH=glnxa64
export PATH=${HOME}/bin:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:${MPI_ROOT}/bin:${PATH}
export LD_LIBRARY_PATH=${HOME}/lib64:${MPI_ROOT}/lib:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:/opt/gridengine/lib/lx26-amd64


${MPI_ROOT}/bin/mpirun -n ${NSLOTS} ./Eye_all_MH ${INPUT_DATA} ${DATASET} --num_temperatures=100 --num_burnin_samples=5000 --num_posterior_samples=50000 results/${OUTPUT_FMT}_${NSLOTS}
exit 0
