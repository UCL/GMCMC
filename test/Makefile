include ../make.inc
CPPFLAGS = -I..
LDFLAGS = -L..
LDLIBS = -lgmcmc -lgmcmc_hdf5 -lcunit -lm

VPATH = . ../gmcmc

.PHONY: all clean

TESTS = test_ion_model test_ode_model test_eye_model test_rng test_uniform test_normal test_lognormal test_gamma test_mvn

all: $(TESTS)

clean:
	rm -f $(TESTS)

../libgmcmc.so:
	cd .. && $(MAKE) libgmcmc.so

../libgmcmc_hdf5.so: ../libgmcmc.so
	cd ../src/hdf5 && $(MAKE) ../../libgmcmc_hdf5.so

test_ion_model: test_ion_model.c test_castillo_katz.c test_castillo_katz_main.c gmcmc_errno.h gmcmc_ion.h gmcmc_likelihood.h gmcmc_proposal.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_ode_model: test_ode_model.c test_fitzhugh_mh.c test_fitzhugh_mh_main.c test_fitzhugh_simp_mmala.c test_fitzhugh_simp_mmala_main.c gmcmc_errno.h gmcmc_ode.h gmcmc_likelihood.h gmcmc_proposal.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_eye_model: test_eye_model.c test_eye.c test_eye_main.c gmcmc_errno.h gmcmc_eye.h gmcmc_likelihood.h gmcmc_proposal.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_rng: test_rng.c gmcmc_rng.h gmcmc_errno.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_uniform: test_uniform.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_normal: test_normal.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_lognormal: test_lognormal.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_gamma: test_gamma.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)

test_mvn: LDLIBS += $(LAPACK_LDLIBS)
test_mvn: test_mvn.c ../src/mvn.c gmcmc_rng.h gmcmc_errno.h ../libgmcmc.so ../libgmcmc_hdf5.so
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)
