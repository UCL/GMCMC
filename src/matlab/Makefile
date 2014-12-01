include ../../make.inc
CPPFLAGS = -I$(CURDIR)/../.. $(MATLAB_CPPFLAGS)
CFLAGS += -fPIC
LDFLAGS = -L$(CURDIR)/../.. $(MATLAB_LDFLAGS) -Wl,--export-dynamic -Wl,-soname=libgmcmc_matlab.so -Wl,--no-undefined
LDLIBS =  -lgmcmc $(MATLAB_LDLIBS)
OBJS = ion_dataset.o ode_dataset.o eye_dataset.o popmcmc_write.o

VPATH = . ../../gmcmc

.PHONY: all clean

all: ../../libgmcmc_matlab.so

clean:
	rm -f $(OBJS) ../../libgmcmc_matlab.so

../../libgmcmc_matlab.so: $(OBJS) ../../libgmcmc.so
	$(CC) $(LDFLAGS) -shared $(^) -o $(@) $(LOADLIBES) $(LDLIBS)

../../libgmcmc.so:
	cd .. && $(MAKE)

ion_dataset.o: gmcmc_ion.h gmcmc_likelihood.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
ode_dataset.o: gmcmc_ode.h gmcmc_likelihood.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
eye_dataset.o: gmcmc_eye.h gmcmc_likelihood.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
popmcmc_write.o: gmcmc_popmcmc.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h
