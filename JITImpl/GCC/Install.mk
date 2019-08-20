
DEBUG?=0
INSTALL_TARGET?=

all: install

libGCCJIT.so:
	make DEBUG=$(DEBUG)

.PHONY: install
install: libGCCJIT.so
	cp -ab libGCCJIT.so $(INSTALL_TARGET)/libGCCJIT.so
