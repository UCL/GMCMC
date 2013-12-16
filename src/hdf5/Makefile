include ../../make.inc
CPPFLAGS = -I$(CURDIR)/../.. $(HDF5_CPPFLAGS)
CFLAGS += -fPIC
LDFLAGS = -L$(CURDIR)/../.. $(HDF5_LDFLAGS) -Wl,--export-dynamic -Wl,-soname=libgmcmc_hdf5.so -Wl,--no-undefined
LDLIBS =  -lgmcmc $(HDF5_LDLIBS)
OBJS = ion_dataset.o ode_dataset.o eye_dataset.o filewriter.o

VPATH = . ../../gmcmc

.PHONY: all clean

all: ../../libgmcmc_hdf5.so

clean:
	rm -f $(OBJS) ../../libgmcmc_hdf5.so

../../libgmcmc_hdf5.so: $(OBJS) ../../libgmcmc.so
	$(CC) $(LDFLAGS) -shared $(^) -o $(@) $(LOADLIBES) $(LDLIBS)

../../libgmcmc.so:
	cd .. && $(MAKE)

ion_dataset.o: gmcmc_ion.h gmcmc_likelihood.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h hdf5_read.c
ode_dataset.o: gmcmc_ode.h gmcmc_likelihood.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h hdf5_read.c
eye_dataset.o: gmcmc_eye.h gmcmc_likelihood.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h hdf5_read.c
filewriter.o: gmcmc_popmcmc.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h
