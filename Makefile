.PHONY: all test clean examples

all: libgmcmc.so examples #test

# test: libgmcmc.so
# 	cd test && $(MAKE)

clean:
	rm -f libgmcmc.so
	cd src && $(MAKE) clean
	cd examples && $(MAKE) clean
# 	cd test && $(MAKE) clean

libgmcmc.so:
	cd src && $(MAKE)
	ln -s src/libgmcmc.so libgmcmc.so

examples: libgmcmc.so
	cd examples && $(MAKE)
