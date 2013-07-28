MATLAB_HOME = /opt/MATLAB/R2013a
MATLAB_ARCH = glnxa64
SUNDIALS_HOME = $(HOME)/sundials-2.5.0
CC = gcc
CPPFLAGS = -I. -I.. -I$(MATLAB_HOME)/extern/include -I$(SUNDIALS_HOME)/include
CFLAGS = -std=c99 -pedantic -Wall -Wextra -march=native -O2 -pipe
LDFLAGS = -L. -L$(MATLAB_HOME)/bin/$(MATLAB_ARCH) -L$(SUNDIALS_HOME)/lib \
          -Wl,-rpath-link,$(MATLAB_HOME)/bin/$(MATLAB_ARCH)
LDLIBS = -lgmcmc -lsundials_cvodes -lsundials_nvecserial -lmx -lmex -lmat

VPATH = . examples gmcmc

.PHONY: all examples test clean

ION_examples = ION_dCK_PopMCMC ION_FiveState_Balanced_PopMCMC ION_FiveState_PopMCMC

ODE_examples = FitzHugh_Benchmark_1_MH FitzHugh_Benchmark_1_Simp_mMALA \
               FitzHugh_Benchmark_2_MH FitzHugh_Benchmark_2_Simp_mMALA \
               FitzHugh_Benchmark_3_MH FitzHugh_Benchmark_3_Simp_mMALA \
               FitzHugh_Benchmark_4_MH FitzHugh_Benchmark_4_Simp_mMALA \
               FitzHugh_Benchmark_5_MH FitzHugh_Benchmark_5_Simp_mMALA \
               FitzHugh_Benchmark_6_MH FitzHugh_Benchmark_6_Simp_mMALA
#                Locke_Benchmark_1_MH Locke_Benchmark_1_Simp_mMALA \
#                ODE_FHN_MH_PopMCMC ODE_FHN_Simp_mMALA_ICs_PopMCMC ODE_FHN_Simp_mMALA_PopMCMC \
#                ODE_Roberta_MH_PopMCMC ODE_RobertaObs_MH_PopMCMC ODE_RobertaObs_Simp_mMALA_PopMCMC ODE_Roberta_Simp_mMALA_PopMCMC

all: libgmcmc.so

examples: $(ION_examples) $(ODE_examples)

test: libgmcmc.so
	cd test && $(MAKE)

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean
	rm -f examples/acceptance.o examples/matlab.o $(addprefix examples/,$(addsuffix .o,$(ION_examples) $(ODE_examples))) $(ION_examples) $(ODE_examples)

libgmcmc.so:
	cd src && $(MAKE)

examples/acceptance.o: acceptance.h
examples/matlab.o: matlab.h
$(addprefix examples/,$(addsuffix .o,$(ION_examples))): gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ion_model.h gmcmc_popmcmc.h acceptance.h matlab.h
$(addprefix examples/,$(addsuffix .o,$(ODE_examples))): gmcmc_errno.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_ode_model.h gmcmc_popmcmc.h acceptance.h matlab.h

define make_example =
$(1): examples/$(1).o examples/acceptance.o examples/matlab.o libgmcmc.so
endef
$(foreach exe,$(ION_examples) $(ODE_examples),$(eval $(call make_example,$(exe))))

$(ION_examples) $(ODE_examples):
	$(CC) -o $(@) $(filter %.o,$(^)) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)
