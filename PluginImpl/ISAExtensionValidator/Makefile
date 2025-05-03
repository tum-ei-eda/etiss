DEBUG?=1
 
CC=gcc
 
ifeq ($(DEBUG),0)
	DBGPARAM =
	OPTLEVEL?=-O3
else
	DBGPARAM =-g
	OPTLEVEL?=
endif
 
ETISS_FOLDER=../..
 
CFLAGS=-std=c++0x -c -MMD -Wall -Werror -fPIC $(OPTLEVEL) $(DBGPARAM) -DDEBUG=$(DEBUG) -I$(ETISS_FOLDER)/include -I$(ETISS_FOLDER)/include_c
 
 
all : libISAExtensionValidator.so
 
ISAExtensionValidator.o : ISAExtensionValidator.cpp
	$(CC) $(CFLAGS) ISAExtensionValidator.cpp
 
ISAExtensionValidatorPluginLib.o: ISAExtensionValidatorPluginLib.cpp
	$(CC) $(CFLAGS) ISAExtensionValidatorPluginLib.cpp
 
-include ./*.d
 
libISAExtensionValidator.so : ISAExtensionValidator.o ISAExtensionValidatorPluginLib.o 
	$(CC) -std=c++0x -shared -g -L$(ETISS_FOLDER) -dl -o libISAExtensionValidator.so ISAExtensionValidator.o ISAExtensionValidatorPluginLib.o 
 
clean :
	rm -f *o
	rm -f libISAExtensionValidator.so