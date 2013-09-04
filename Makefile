include make.inc
PREFIX ?= /usr
CPPFLAGS = -I. -I.. $(MPI_CPPFLAGS)
LDFLAGS = -L. $(MPI_LDFLAGS)
LDLIBS = -lgmcmc -lgmcmc_matlab $(MPI_LDLIBS)

VPATH = . examples gmcmc

.PHONY: all examples test clean install

LIBS = libgmcmc.so libgmcmc_matlab.so

ION_examples = ION_dCK_PopMCMC ION_FiveState_Balanced_PopMCMC ION_FiveState_PopMCMC

ODE_examples = FitzHugh_Benchmark_MH FitzHugh_Benchmark_Simp_mMALA \
               Locke_Benchmark_MH Locke_Benchmark_Simp_mMALA

all: $(LIBS)

examples: $(ION_examples) $(ODE_examples)

test: $(LIBS)
	cd test && $(MAKE)

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean
	rm -f examples/common.o $(addprefix examples/,$(addsuffix .o,$(ION_examples) $(ODE_examples))) $(ION_examples) $(ODE_examples)

install: $(LIBS) $(ION_examples) $(ODE_examples)
	$(foreach lib,$(LIBS),)
	$(foreach bin,$(ION_examples) $(ODE_examples),)

libgmcmc.so:
	cd src && $(MAKE) ../libgmcmc.so

libgmcmc_matlab.so: libgmcmc.so
	cd src/matlab && $(MAKE) ../../libgmcmc_matlab.so

examples/common.o: common.h
$(addprefix examples/,$(addsuffix .o,$(ION_examples))): gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ion_model.h gmcmc_popmcmc.h gmcmc_matlab.h common.h
$(addprefix examples/,$(addsuffix .o,$(ODE_examples))): gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ode_model.h gmcmc_popmcmc.h gmcmc_matlab.h common.h

define make_example
$(1): examples/$(1).o examples/common.o $(LIBS)
endef
$(foreach exe,$(ION_examples) $(ODE_examples),$(eval $(call make_example,$(exe))))

$(ION_examples) $(ODE_examples):
	$(CC) -o $(@) $(filter %.o,$(^)) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)
