.PHONY: all test clean examples

all: libgmcmc.so examples #test

# test: libgmcmc.so
# 	cd test && $(MAKE)

clean:
	cd src && $(MAKE) clean
	cd examples && $(MAKE) clean
# 	cd test && $(MAKE) clean
	rm -f libgmcmc.so

libgmcmc.so:
	cd src && $(MAKE)

examples: libgmcmc.so
	cd examples && $(MAKE)
