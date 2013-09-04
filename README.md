GMCMC
=====

C library implementing Geometric Parallel Population MCMC.

See http://www.hector.ac.uk/cse/distributedcse/reports/UniMCMC/.

Requirements:
 BLAS, LAPACK, CBLAS and LAPACKE (available from netlib.org)
 sundials-2.5.0 or greater (http://computation.llnl.gov/casc/sundials/main.html)
 openMPI-1.6 or greater (http://www.openmpi.org/)
 MATLAB
 CUnit (http://cunit.sourceforge.net/.  Optional, only needed to compile tests.)
 C compiler supporting C99 and openmp
 GNU make 3.81 or greater
 
To compile:
Copy (or symbolically link) make.inc.laptop to make.inc and edit the paths within to point to where the libraries are
installed on your system.  Type 'make' to compile the two libraries 'libgmcmc.so' which contains the parallel geometric
population MCMC algorithm and associated model and prior distributions; and 'libgmcmc_matlab.so' which contains
MATLAB-specific dataset implementations and a function to create MATLAB output files.  Type 'make examples' to compile the
example programs and 'make test' to compile the unit tests.  To run any of the example programs you will need to update
your library path.  To remove the compiled object files, libraries and executables type 'make clean'.

Directory structure:
 data/     - datasets for example programs
 examples/ - source files for example programs
 gmcmc/    - header files
 sge/      - Sun Grid Engine scripts for running the examples on the cluster
 src/      - source files for the libraries
 test/     - source files for the CUnit tests
