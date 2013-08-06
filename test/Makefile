include ../make.inc
CPPFLAGS = -I..
LDFLAGS = -L.. $(SUNDIALS_LDFLAGS) $(MATLAB_LDFLAGS)
LDLIBS = -lgmcmc -lgmcmc_matlab -lcunit $(SUNDIALS_LDLIBS) $(MATLAB_LDLIBS)

VPATH = . ../gmcmc

.PHONY: all clean

TESTS = test_ion_model test_ode_model test_rng test_uniform test_normal test_lognormal test_gamma test_mvn

all: $(TESTS)

clean:
	rm -f $(TESTS)

test_ion_model: test_ion_model.c test_castillo_katz.c test_castillo_katz_main.c gmcmc_errno.h gmcmc_ion_model.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_ode_model: test_ode_model.c test_fitzhugh_mh.c test_fitzhugh_mh_main.c test_fitzhugh_simp_mmala.c test_fitzhugh_simp_mmala_main.c gmcmc_errno.h gmcmc_ode_model.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_rng: test_rng.c gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_uniform: test_uniform.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_normal: test_normal.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_lognormal: test_lognormal.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_gamma: test_gamma.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_mvn: test_mvn.c ../src/mvn.c gmcmc_rng.h gmcmc_errno.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)
