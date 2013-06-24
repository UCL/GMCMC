CC = gcc
CPPFLAGS = -I..
CFLAGS = -std=c99 -pedantic -Wall -march=native -O2 -pipe
LDFLAGS = -L.. -L /opt/MATLAB/R2013a/bin/glnxa64 -Wl,-rpath-link,/opt/MATLAB/R2013a/bin/glnxa64
LDLIBS = -lgmcmc -lmpi -lmx -lmex -lmat -lstdc++ -lpthread -lreflapack -lcblas -lblas -lm

VPATH = . .. ../gmcmc

.PHONY: all clean

all: ION_dCK_PopMCMC

clean:
	rm -f ION_dCK_PopMCMC

ION_dCK_PopMCMC: ION_dCK_PopMCMC.c gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ion_model.h gmcmc_popmcmc.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LDLIBS)
