MATLAB_HOME = /opt/MATLAB/R2013a
CC = gcc
CPPFLAGS = -I.. -I$(MATLAB_HOME)/extern/include
CFLAGS = -std=c99 -pedantic -Wall -Wextra -march=native -O2 -pipe
LDLIBS = -lcunit -lblas -lcblas -lreflapack -lm

.PHONY: all clean

all: test_ion_model

clean:
	rm -f test_ion_model

test_ion_model: test_ion_model.c ../src/ion_model.c ../src/errno.o ../src/model.o ../src/distribution.o
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $(@) $(<) $(filter %.o,$(^)) $(LDFLAGS) $(LOADLIBES) $(LDLIBS)
