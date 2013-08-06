# Common settings to all Makefiles

# Compiler
# GCC
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -march=native -O2 -pipe
# ICC
# CC = icc
# CFLAGS = -std=c99 -Wall -Wextra -xHost -O2

# BLAS/CBLAS/LAPACK
# Reference
# LAPACK_CPPFLAGS = -I/usr/include/cblas
# LAPACK_LDFLAGS =
# LAPACK_LDLIBS = -lreflapack -lrefblas -lrefcblas

# MKL
# LAPACK_CPPFLAGS = -I/opt/intel/composerxe-2013_update4.5.192/mkl/include -DMKL_ILP64
# LAPACK_LDFLAGS = -L/opt/intel/composerxe-2013_update4.5.192/mkl/lib/intel64
# LAPACK_LDLIBS = -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core

# ATLAS
LAPACK_CPPFLAGS = -I/usr/include/atlas
LAPACK_LDFLAGS =
LAPACK_LDLIBS = -lptlapack -lptf77blas -lptcblas


# MPI
# OpenMPI
MPI_CPPFLAGS =
MPI_LDFLAGS =
MPI_LDLIBS = -lmpi -ldl -lhwloc -Wl,--export-dynamic -lrt -lnsl -lutil -lm -lhwloc -ldl


# OPENMP
# GNU
OMP_CPPFLAGS =
OMP_LDFLAGS =
OMP_LDLIBS = -lgomp

# Intel
# OMP_CPPFLAGS =
# OMP_LDFLAGS = -L/opt/intel/composerxe-2013_update4.5.192/compiler/lib/intel64
# OMP_LDLIBS = -liomp5


# SUNDIALS
SUNDIALS_CPPFLAGS = -I$(HOME)/sundials-2.5.0/include
SUNDIALS_LDFLAGS = -L$(HOME)/sundials-2.5.0/lib
SUNDIALS_LDLIBS = -lsundials_cvodes -lsundials_nvecserial


# MATLAB
MATLAB_CPPFLAGS = -I/opt/MATLAB/R2013a/extern/include
MATLAB_LDFLAGS = -L/opt/MATLAB/R2013a/bin/glnxa64 -Wl,-rpath-link,/opt/MATLAB/R2013a/bin/glnxa64
MATLAB_LDLIBS = -lmx -lmex -lmat