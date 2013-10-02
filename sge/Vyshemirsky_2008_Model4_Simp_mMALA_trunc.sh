#!/bin/bash
#$ -l h_vmem=2G,tmem=2G
#$ -l h_rt=8:00:00
#$ -R y
#$ -pe openmpi 20
#$ -l 10g=yes
#$ -cwd
#$ -j y
#$ -S /bin/bash
#$ -N V2008M4_Simp_mMALA_trunc
export MPI_ROOT=/share/apps/openmpi-1.6
export MATLAB_ROOT=/share/apps/matlabR2013a
export MATLAB_ARCH=glnxa64
export PATH=${HOME}/bin:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:${MPI_ROOT}/bin:${PATH}
export LD_LIBRARY_PATH=${HOME}/lib64:${MPI_ROOT}/lib:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:/opt/gridengine/lib/lx26-amd64


${MPI_ROOT}/bin/mpirun --mca btl_tcp_if_exclude lo,eth0 -n ${NSLOTS} ./Vyshemirsky_2008_Model4_Benchmark_1_Simp_mMALA_trunc results/Vyshemirsky_2008_Model4_Benchmark_1_Simp_mMALA_trunc_${NSLOTS}_${i}
exit 0
