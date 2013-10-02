#!/bin/bash
#$ -l h_vmem=4G,tmem=4G
#$ -l h_rt=8:00:00
#$ -R y
#$ -pe openmpi 20
#$ -l 10g=yes
#$ -cwd
#$ -j y
#$ -S /bin/bash
#$ -N LightLevel_BG3
export MPI_ROOT=/share/apps/openmpi-1.6
export MATLAB_ROOT=/share/apps/matlabR2013a
export MATLAB_ARCH=glnxa64
export PATH=${HOME}/bin:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:${MPI_ROOT}/bin:${PATH}
export LD_LIBRARY_PATH=${HOME}/lib64:${MPI_ROOT}/lib:${MATLAB_ROOT}/bin/${MATLAB_ARCH}:/opt/gridengine/lib/lx26-amd64


${MPI_ROOT}/bin/mpirun --mca btl_tcp_if_exclude lo,eth0 -n ${NSLOTS} ./Eye_all_MH --num_temperatures=100 --num_burn_in_samples=5000 --num_posterior_samples=50000 --dataset data/Eye_Data/LightLevel/BG3_MacroC_30k_500Hz_BC.mat data/Eye_Data/LightLevel/BG3_WNlight_30k_500Hz_BC.txt results/LightLevel_BG3
exit 0
