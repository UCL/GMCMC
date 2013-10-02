#!/bin/bash
#$ -l h_vmem=2G,tmem=2G
#$ -l h_rt=4:00:00
#$ -R y
#$ -l 10g=yes
#$ -cwd
#$ -j y
#$ -S /bin/bash
#$ -N FitzHugh_Simp_mMALA
export MPI_ROOT=/share/apps/openmpi-1.6
export MATLAB_ROOT=/share/apps/matlabR2013a
export MATLAB_ARCH=glnxa64
export PATH=${HOME}/bin:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:${MPI_ROOT}/bin:${PATH}
export LD_LIBRARY_PATH=${HOME}/lib64:${MPI_ROOT}/lib:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:/opt/gridengine/lib/lx26-amd64


${MPI_ROOT}/bin/mpirun --mca btl_tcp_if_exclude lo,eth0 -n ${NSLOTS} ./FitzHugh_Benchmark_Simp_mMALA --num_temperatures=50 --num_posterior_samples=20000 results/FitzHugh_Benchmark_Simp_mMALA_${NSLOTS}_${i}
exit 0
