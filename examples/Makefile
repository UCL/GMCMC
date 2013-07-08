MATLAB_HOME = /opt/MATLAB/R2013a
MATLAB_ARCH = glnxa64
CC = gcc
CPPFLAGS = -I../ -I$(MATLAB_HOME)/extern/include
CFLAGS = -ggdb -std=c99 -pedantic -Wall -march=native -pipe
LDFLAGS = -L.. -L$(MATLAB_HOME)/bin/$(MATLAB_ARCH) \
          -Wl,-rpath-link,$(MATLAB_HOME)/bin/$(MATLAB_ARCH)
LDLIBS = -lgmcmc -lmx -lmex -lmat

VPATH = . .. ../gmcmc

.PHONY: all clean

all: ION_dCK_PopMCMC

clean:
	rm -f ION_dCK_PopMCMC

ION_dCK_PopMCMC: ION_dCK_PopMCMC.c gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ion_model.h gmcmc_popmcmc.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LDLIBS)
