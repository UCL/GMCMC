include make.inc
PREFIX ?= /usr
CPPFLAGS = -I. -I.. $(MPI_CPPFLAGS)
LDFLAGS = -L. $(MPI_LDFLAGS)
# LDLIBS = -lgmcmc -lgmcmc_matlab $(MPI_LDLIBS) -lm
LDLIBS = -lgmcmc -lgmcmc_hdf5 $(MPI_LDLIBS) -lm

VPATH = . examples gmcmc

.PHONY: all examples test clean install

ION_examples = ION_dCK_PopMCMC ION_FiveState_Balanced_PopMCMC ION_FiveState_PopMCMC

ODE_examples = FitzHugh_Benchmark_MH FitzHugh_Benchmark_Simp_mMALA \
               Locke_Benchmark_MH Locke_Benchmark_Simp_mMALA \
               Vyshemirsky_2008_Model4_Benchmark_1_MH \
               Vyshemirsky_2008_Model4_Benchmark_1_Simp_mMALA \
               Vyshemirsky_2008_Model4_Benchmark_1_Simp_mMALA_trunc

EYE_examples = Eye_all_MH

all: libgmcmc.so

examples: $(ION_examples) $(ODE_examples) $(EYE_examples)

test:
	cd test && $(MAKE)

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean
	rm -f examples/common.o $(addprefix examples/,$(addsuffix .o,$(ION_examples) $(ODE_examples) $(EYE_examples))) $(ION_examples) $(ODE_examples) $(EYE_examples)

# install: $(LIBS) $(ION_examples) $(ODE_examples) $(EYE_examples)
# 	$(foreach lib,$(LIBS),cp $(lib) $(DESTDIR)$(libdir)/$(lib))
# 	$(foreach bin,$(ION_examples) $(ODE_examples) $(EYE_examples), cp $(bin) $(DESTDIR)$(bindir)/$(bin))

libgmcmc.so:
	cd src && $(MAKE) ../libgmcmc.so

libgmcmc_matlab.so: libgmcmc.so
	cd src/matlab && $(MAKE) ../../libgmcmc_matlab.so

libgmcmc_hdf5.so: libgmcmc.so
	cd src/hdf5 && $(MAKE) ../../libgmcmc_hdf5.so

examples/common.o: common.h gmcmc_popmcmc.h gmcmc_model.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_distribution.h gmcmc_rng.h
$(addprefix examples/,$(addsuffix .o,$(ION_examples))): gmcmc_ion.h gmcmc_model.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_distribution.h gmcmc_rng.h gmcmc_popmcmc.h common.h
$(addprefix examples/,$(addsuffix .o,$(ODE_examples))): gmcmc_ode.h gmcmc_model.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_distribution.h gmcmc_rng.h gmcmc_popmcmc.h common.h
$(addprefix examples/,$(addsuffix .o,$(EYE_examples))): gmcmc_eye.h gmcmc_model.h gmcmc_proposal.h gmcmc_likelihood.h gmcmc_distribution.h gmcmc_rng.h gmcmc_popmcmc.h common.h

define make_example
$(1): examples/$(1).o examples/common.o libgmcmc.so libgmcmc_hdf5.so
endef
$(foreach exe,$(ION_examples) $(ODE_examples) $(EYE_examples),$(eval $(call make_example,$(exe))))

$(ION_examples) $(ODE_examples) $(EYE_examples):
	$(CC) -o $(@) $(filter %.o,$(^)) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)
