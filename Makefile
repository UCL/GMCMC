MATLAB_HOME = /opt/MATLAB/R2013a
MATLAB_ARCH = glnxa64
SUNDIALS_HOME = $(HOME)/sundials-2.5.0
CC = gcc
CPPFLAGS = -I. -I..
# CFLAGS = -std=c99 -pedantic -Wall -Wextra -ggdb -O0 -pipe
CFLAGS = -std=c99 -pedantic -Wall -Wextra -march=native -O2 -pipe
LDFLAGS = -L. -L$(MATLAB_HOME)/bin/$(MATLAB_ARCH) -L$(SUNDIALS_HOME)/lib \
          -Wl,-rpath-link,$(MATLAB_HOME)/bin/$(MATLAB_ARCH)
LDLIBS = -lgmcmc -lgmcmc_matlab -lsundials_cvodes -lsundials_nvecserial -lmx -lmex -lmat

VPATH = . examples gmcmc

.PHONY: all examples test clean

ION_examples = ION_dCK_PopMCMC ION_FiveState_Balanced_PopMCMC ION_FiveState_PopMCMC

ODE_examples = FitzHugh_Benchmark_MH FitzHugh_Benchmark_Simp_mMALA \
               Locke_Benchmark_MH Locke_Benchmark_Simp_mMALA

all: libgmcmc.so libgmcmc_matlab.so

examples: $(ION_examples) $(ODE_examples)

test: libgmcmc.so libgmcmc_matlab.so
	cd test && $(MAKE)

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean
	rm -f examples/acceptance.o $(addprefix examples/,$(addsuffix .o,$(ION_examples) $(ODE_examples))) $(ION_examples) $(ODE_examples)

libgmcmc.so:
	cd src && $(MAKE)

libgmcmc_matlab.so: libgmcmc.so
	cd src/matlab && $(MAKE)

examples/acceptance.o: acceptance.h
$(addprefix examples/,$(addsuffix .o,$(ION_examples))): gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ion_model.h gmcmc_popmcmc.h gmcmc_matlab.h acceptance.h
$(addprefix examples/,$(addsuffix .o,$(ODE_examples))): gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ode_model.h gmcmc_popmcmc.h gmcmc_matlab.h acceptance.h

define make_example =
$(1): examples/$(1).o examples/acceptance.o libgmcmc.so libgmcmc_matlab.so
endef
$(foreach exe,$(ION_examples) $(ODE_examples),$(eval $(call make_example,$(exe))))

$(ION_examples) $(ODE_examples):
	$(CC) -o $(@) $(filter %.o,$(^)) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)
