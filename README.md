GMCMC
=====

C library implementing Geometric Parallel Population MCMC.  

See http://www.hector.ac.uk/cse/distributedcse/reports/UniMCMC/.  

Dependencies:  
 Required:  
  BLAS, CBLAS, LAPACK and LAPACKE (available from netlib.org)  
  MPI (either openMPI (http://www.openmpi.org/) or MPICH (http://www.mpich.org/))  
  sundials-2.5.0 or greater (http://computation.llnl.gov/casc/sundials/main.html)  
  C compiler supporting C99 and openmp  
  GNU make 3.81 or greater  
  Either:  
   MATLAB (to read and write data stored in MATLAB files)  
   HDF5 (to read and write data stored in HDF5 files (http://www.hdfgroup.org/))  
 Optional:  
  CUnit (http://cunit.sourceforge.net/.  Only needed to compile tests.)  

To compile:  
Copy (or symbolically link) make.inc.example to make.inc and edit the paths  
within to point to where the libraries are installed on your system.  Type  
```make``` to compile ```libgmcmc.so``` which contains the parallel geometric population 
MCMC algorithm and associated models and prior distributions.  Type ```make hdf5```  
to compile a library defining functions to read/write data stored in HDF5 files.  
Type ```make matlab``` to compile a library defining functions to read/write data  
stored in MATLAB files.  Type ```make examples``` to compile the example programs  
and ```make test``` to compile the unit tests.  To run any of the example programs you  
will need to update your library path.  To remove the compiled object files,  
libraries and executables type ```make clean```.  

Directory structure:  
 data/     - datasets for example programs  
 examples/ - source files for example programs  
 gmcmc/    - header files  
 pbs/      - Portable Batch System scripts for running the examples  
 sge/      - Sun Grid Engine scripts for running the examples  
 src/      - source files for the libraries  
 test/     - source files for the CUnit tests  
