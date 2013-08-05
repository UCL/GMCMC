CC = gcc
CPPFLAGS = -I.. -I$(HOME)/sundials-2.5.0/include
CFLAGS = -std=c99 -pedantic -Wall -Wextra -ggdb -O0 -pipe -fPIC -fopenmp -pthread
# CFLAGS = -std=c99 -pedantic -Wall -Wextra -march=native -O2 -pipe -fPIC -fopenmp -pthread
LDFLAGS = -L$(HOME)/sundials-2.5.0/lib -Wl,--export-dynamic -Wl,-soname=libgmcmc.so
LDLIBS = -lmpi -ldl -lhwloc -lrt -lnsl -lutil -lm -lhwloc -ldl -lpthread \
         -lsundials_cvodes -lsundials_nvecserial \
         -lptlapack -lptf77blas -lptcblas -lgomp
OBJS = distribution/gamma.o distribution/lognormal.o distribution/normal.o distribution/uniform.o \
       rng/mt19937.o rng/mt19937-64.o rng/dcmt521.o rng/dcmt607.o rng/dcmt1279.o rng/dcmt2203.o rng/dcmt2281.o rng/dcmt3217.o rng/dcmt4253.o rng/dcmt4423.o rng/dcmt9689.o \
       errno.o dataset.o distribution.o rng.o model.o ion_model.o ode_model.o popmcmc.o

VPATH = . ../gmcmc

.PHONY: all clean

all: ../libgmcmc.so ../libgmcmc_matlab.so

clean:
	cd matlab && $(MAKE) clean
	rm -f $(OBJS) ../libgmcmc.so

../libgmcmc.so: $(OBJS)
	$(CC) $(LDFLAGS) -shared $(^) -o $(@) $(LOADLIBES) $(LDLIBS)

../libgmcmc_matlab.so: ../libgmcmc.so
	cd matlab && $(MAKE)

distribution/gamma.o: distribution/randn.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/lognormal.o: distribution/randn.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/normal.o: distribution/randn.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/uniform.o: gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
rng/mt19937.o: rng/dcmt.c gmcmc_rng.h
rng/mt19937-64.o: gmcmc_rng.h
rng/dcmt512.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt607.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt1279.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt2203.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt2281.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt3217.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt4253.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt4423.o: rng/dcmt.c gmcmc_rng.h
rng/dcmt9689.o: rng/dcmt.c gmcmc_rng.h
errno.o: gmcmc_errno.h
dataset.o: gmcmc_dataset.h
distribution.o: gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
rng.o: gmcmc_rng.h gmcmc_errno.h
model.o: gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_errno.h
ion_model.o: clapack.h gmcmc_ion_model.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_errno.h
ode_model.o: clapack.h gmcmc_ode_model.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_errno.h
popmcmc.o: popmcmc_seq.c popmcmc_omp.c popmcmc_mpi.c mvn.c clapack.h distribution/randn.c gmcmc_popmcmc.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_errno.h
