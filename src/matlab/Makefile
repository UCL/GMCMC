MATLAB_HOME = /opt/MATLAB/R2013a
MATLAB_ARCH = glnxa64
CC = gcc
CPPFLAGS = -I../.. -I$(MATLAB_HOME)/extern/include
CFLAGS = -std=c99 -pedantic -Wall -Wextra -march=native -O2 -pipe -fPIC
LDFLAGS = -L../.. -L$(MATLAB_HOME)/bin/$(MATLAB_ARCH) \
          -Wl,-rpath-link,$(MATLAB_HOME)/bin/$(MATLAB_ARCH) -Wl,--no-undefined \
          -Wl,-soname=libgmcmc_matlab.so -Wl,--export-dynamic
LDLIBS =  -lgmcmc -lmx -lmex -lmat -lm -lstdc++
OBJS = ion_dataset.o ode_dataset.o popmcmc_write.o

VPATH = . ../../gmcmc

.PHONY: all clean

all: ../../libgmcmc_matlab.so

clean:
	rm -f $(OBJS) ../../libgmcmc_matlab.so

../../libgmcmc_matlab.so: $(OBJS)
	$(CC) $(LDFLAGS) -shared $(^) -o $(@) $(LOADLIBES) $(LDLIBS)

ion_dataset.o: gmcmc_matlab.h gmcmc_dataset.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_popmcmc.h gmcmc_errno.h
ode_dataset.o: gmcmc_matlab.h gmcmc_dataset.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_popmcmc.h gmcmc_errno.h
popmcmc_write.o: gmcmc_matlab.h gmcmc_dataset.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_popmcmc.h gmcmc_errno.h
