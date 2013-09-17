include ../make.inc
CPPFLAGS = -I.. $(MPI_CPPFLAGS) $(SUNDIALS_CPPFLAGS) $(LAPACK_CPPFLAGS) $(OMP_CPPFLAGS)
CFLAGS += -fPIC -fopenmp -pthread
LDFLAGS = $(MPI_LDFLAGS) $(SUNDIALS_LDFLAGS) $(LAPACK_LDFLAGS) $(OMP_LDFLAGS) \
          -Wl,--export-dynamic -Wl,-soname=libgmcmc.so -Wl,--no-undefined
LDLIBS = $(MPI_LDLIBS) $(SUNDIALS_LDLIBS) $(LAPACK_LDLIBS) $(OMP_LDLIBS)
OBJS = distribution/distribution.o distribution/gamma.o distribution/lognormal.o distribution/normal.o distribution/uniform.o \
       rng/rng.o rng/mt19937.o rng/mt19937-64.o rng/dcmt521.o rng/dcmt607.o rng/dcmt1279.o rng/dcmt2203.o rng/dcmt2281.o rng/dcmt3217.o rng/dcmt4253.o rng/dcmt4423.o rng/dcmt9689.o \
       ion/dataset.o ion/model.o ion/likelihood_mh.o \
       ode/dataset.o ode/model.o ode/likelihood_mh.o ode/likelihood_simp_mmala.o \
       proposal_mh.o proposal_simp_mmala.o proposal_simp_mmala_trunc.o \
       errno.o model.o popmcmc.o

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

# Error handling
errno.o: gmcmc_errno.h

# RNGs
rng/rng.o: gmcmc_rng.h gmcmc_errno.h
rng/mt19937.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/mt19937-64.o: gmcmc_rng.h
rng/dcmt521.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt607.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt1279.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt2203.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt2281.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt3217.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt4253.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt4423.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h
rng/dcmt9689.o: rng/dcmt.c rng/dcmt.h gmcmc_rng.h

# Probability distributions
distribution/distribution.o: gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/gamma.o: distribution/randn.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/lognormal.o: distribution/randn.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/normal.o: distribution/randn.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/uniform.o: gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h

# Model
model.o: gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h

# Proposal functions
proposal_mh.o: gmcmc_proposal.h
proposal_simp_mmala.o: gmcmc_proposal.h gmcmc_errno.h
proposal_simp_mmala_trunc.o: gmcmc_proposal.h gmcmc_errno.h

# Ion model and likelihood functions
ion/dataset.o: gmcmc_ion.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h
ion/likelihood_mh.o: gmcmc_ion.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h
ion/model.o: gmcmc_ion.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h

# ODE model and likelihood functions
ode/dataset.o: gmcmc_ode.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h
ode/likelihood_mh.o: ode/cvodes.c mvn.c distribution/randn.c gmcmc_ode.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h
ode/likelihood_simp_mmala.o: ode/cvodes.c mvn.c distribution/randn.c gmcmc_ode.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h
ode/model.o: gmcmc_ode.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h

# Sampling algorithms
popmcmc.o: mvn.c distribution/randn.c permute.c popmcmc_mpi.c gmcmc_popmcmc.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_errno.h
