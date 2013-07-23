MATLAB_HOME = /opt/MATLAB/R2013a
MATLAB_ARCH = glnxa64
CC = gcc
CPPFLAGS = -I.. -I$(MATLAB_HOME)/extern/include
CFLAGS = -std=c99 -pedantic -Wall -Wextra -ggdb -pipe
LDFLAGS = -L.. -L$(MATLAB_HOME)/bin/$(MATLAB_ARCH) \
          -Wl,-rpath-link,$(MATLAB_HOME)/bin/$(MATLAB_ARCH)
LDLIBS = -lgmcmc -lmx -lmex -lmat -lcunit

VPATH = . ../gmcmc

.PHONY: all clean

TESTS = test_ion_model test_rng test_uniform test_normal test_lognormal test_gamma test_mvn

all: $(TESTS)

clean:
	rm -f $(TESTS)

test_ion_model: test_ion_model.c test_castillo_katz_fn.c test_castillo_katz_main.c test_five_state_fn.c test_five_state_main.c gmcmc_errno.h gmcmc_ion_model.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_rng: test_rng.c gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_uniform: test_uniform.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_normal: test_normal.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_lognormal: test_lognormal.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_gamma: test_lognormal.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_mvn: test_mvn.c ../src/mvn.c ../src/distribution/randn.c ../src/errno.o gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(filter %.o,$(^)) -lreflapack -lcblas -lblas -lcunit
