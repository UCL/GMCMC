CC = gcc
CPPFLAGS = -I../ -I/opt/MATLAB/R2013a/extern/include
CFLAGS = -std=c99 -pedantic -Wall -march=native -O2 -pipe -fPIC
LDFLAGS = -L /opt/MATLAB/R2013a/bin/glnxa64 -Wl,-rpath-link,/opt/MATLAB/R2013a/bin/glnxa64 -Wl,-soname=libgmcmc.so.1
LDLIBS =  -lmx -lmex -lmat -lstdc++ -lpthread -lm
OBJS = dataset/matlab.o \
       distribution/gamma.o distribution/lognormal.o distribution/normal.o distribution/uniform.o \
       rng/dcmt521.o rng/dcmt607.o rng/dcmt1279.o rng/dcmt2203.o rng/dcmt2281.o rng/dcmt3217.o rng/dcmt4253.o rng/dcmt4423.o rng/dcmt9689.o \
       errno.o dataset.o distribution.o rng.o model.o ion_model.o popmcmc.o

VPATH = . ../gmcmc

.PHONY: all clean

all: ../libgmcmc.so

clean:
	rm -f $(OBJS)

../libgmcmc.so: $(OBJS)
	$(CC) $(LDFLAGS) -shared -o $(@) $(^)

dataset/matlab.o: gmcmc_dataset.h gmcmc_errno.h
distribution/gamma.o: distribution/util.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/lognormal.o: distribution/util.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/normal.o: distribution/util.c gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
distribution/uniform.o: gmcmc_distribution.h gmcmc_rng.h gmcmc_errno.h
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
ion_model.o: gmcmc_ion_model.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_errno.h
popmcmc.o: gmcmc_popmcmc.h gmcmc_model.h gmcmc_distribution.h gmcmc_rng.h gmcmc_dataset.h gmcmc_errno.h
