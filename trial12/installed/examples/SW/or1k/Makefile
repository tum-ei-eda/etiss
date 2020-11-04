#
#	Copyright 2018 Infineon Technologies AG
#
#	This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>
#
#	The initial version of this software has been created with the funding support by the German Federal
#	Ministry of Education and Research(BMBF) in the project EffektiV under grant 01IS13022.
#
#	Redistribution and use in source and binary forms, with or without modification, are permitted
#	provided that the following conditions are met:
#
#	1. Redistributions of source code must retain the above copyright notice, this list of conditions and
#	the following disclaimer.
#
# 	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
#	and the following disclaimer in the documentation and / or other materials provided with the distribution.
#
# 	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
# 	or promote products derived from this software without specific prior written permission.
#
#	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
#	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
#	PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
#	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO,
#	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#	HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING
#	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#	POSSIBILITY OF SUCH DAMAGE.
#
#
#	Author: Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#

# This Makefile is used by the ETISS SW-example and the systemC example,
# which has its own software.


TOOLBIN=/usr/local/research/projects/SystemDesign/tools/openrisc/ubuntu14/or1k-elf/bin

SOFTFLOAT?=0

ifeq ($(SOFTFLOAT),1)
	FLOATTYPE= -mhard-div -mhard-mul -mhard-float
else 
	FLOATTYPE= -mhard-div -mhard-mul -msoft-float 
endif


OR32CC=PATH=$(TOOLBIN):$(PATH) LD_LIBRARY_PATH=$(TOOLBIN)/../lib:$(LD_LIBRARY_PATH) $(TOOLBIN)/or1k-elf-gcc -std=c99 $(FLOATTYPE) 
OR32OBJCPY=PATH=$(TOOLBIN):$(PATH) LD_LIBRARY_PATH=$(TOOLBIN)/../lib:$(LD_LIBRARY_PATH) $(TOOLBIN)/or1k-elf-objcopy
OR32OBJDMP=PATH=$(TOOLBIN):$(PATH) LD_LIBRARY_PATH=$(TOOLBIN)/../lib:$(LD_LIBRARY_PATH) $(TOOLBIN)/or1k-elf-objdump
OR32RDELF=PATH=$(TOOLBIN):$(PATH) LD_LIBRARY_PATH=$(TOOLBIN)/../lib:$(LD_LIBRARY_PATH) $(TOOLBIN)/or1k-elf-readelf
OR32GDB=PATH=$(TOOLBIN):$(PATH) LD_LIBRARY_PATH=$(TOOLBIN)/../lib:$(LD_LIBRARY_PATH) $(TOOLBIN)/or1k-elf-gdb




DEBUG?=1

ifeq ($(DEBUG),0)
	DBGPARAM =
	OPTLEVEL?=-O3
else
	DBGPARAM =-g
	OPTLEVEL?=-O3
endif

# The following paths will be inserted by CMake while installing ETISS. 
# As they are absolute, it doesn't matter where the Makefile is executed,
# the only condition is that main.c lies in the same directory as this Makefile.

# The object and executable files will be put in the obj and build 
# subdirectories, respectively.

SW_DIR = /home/anoushka/workspace/etiss/trial12/installed/examples/SW/test_cases/
SW_DIR_OR1K = /home/anoushka/workspace/etiss/trial12/installed/examples/SW/or1k/

BUILD_DIR = ./build/
OBJECT_DIR = ./obj/
CFLAGS = $(DBGPARAM) $(OPTLEVEL) -I ${SW_DIR}

all: mkdirs ${BUILD_DIR}/code.elf ${BUILD_DIR}/code.bin ${BUILD_DIR}/code.txt ${BUILD_DIR}/code.disasm romram ${BUILD_DIR}/code.hex

mkdirs:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJECT_DIR)
	

${OBJECT_DIR}/board.o: ${SW_DIR_OR1K}/board.S
	$(OR32CC) $(CFLAGS) -c ${SW_DIR_OR1K}/board.S -o ${OBJECT_DIR}/board.o

TEST_OBJECTS = \
  ${OBJECT_DIR}/print_.o \
  ${OBJECT_DIR}/aes_.o \
  ${OBJECT_DIR}/edge_.o \
  ${OBJECT_DIR}/fir_.o \
  ${OBJECT_DIR}/iir_.o \
  ${OBJECT_DIR}/pi_.o \
  ${OBJECT_DIR}/heap_.o \
  ${OBJECT_DIR}/isort_.o \
  ${OBJECT_DIR}/jdct_.o \
  ${OBJECT_DIR}/test_.o \
  ${OBJECT_DIR}/end_.o

${BUILD_DIR}/code.elf: mkdirs ${OBJECT_DIR}/board.o ${OBJECT_DIR}/ ${TEST_OBJECTS} main.c
	$(OR32CC) $(CFLAGS) -T ${SW_DIR_OR1K}/link.ld main.c irq_tt.c -o ${BUILD_DIR}/code.elf ${OBJECT_DIR}/board.o ${TEST_OBJECTS}

${BUILD_DIR}/code.bin: ${BUILD_DIR}/code.elf
	$(OR32OBJCPY) ${BUILD_DIR}/code.elf --output-target=binary ${BUILD_DIR}/code.bin

${BUILD_DIR}/code.hex: ${BUILD_DIR}/code.bin
	hexdump ${BUILD_DIR}/code.bin > ${BUILD_DIR}/code.hex

${BUILD_DIR}/code.disasm: ${BUILD_DIR}/code.elf
	$(OR32OBJDMP) -S -D ${BUILD_DIR}/code.elf > ${BUILD_DIR}/code.disasm

${BUILD_DIR}/code.txt: ${BUILD_DIR}/code.bin
	$(OR32RDELF) -a ${BUILD_DIR}/code.elf > ${BUILD_DIR}/code.txt

# This generates a seperate file to go into rom and ram memory
# The offsets must corespond to the offsets in the linker script converted to decimal
# Example: linker script rom size 0x0080000 = count=524288 (copies beginning of hex file for rom)
# 	   linker script ram begins at 0x18000000 = skip=402653184 (copies everything starting from 0x18000000)
romram: ${BUILD_DIR}/code.bin	
	dd bs=1 count=524288 if=$(BUILD_DIR)/code.bin of=$(BUILD_DIR)/code.rom
	dd bs=1 skip=524288 if=$(BUILD_DIR)/code.bin of=$(BUILD_DIR)/code.ram



${OBJECT_DIR}/print_.o:
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/print_.o -c ${SW_DIR}/cust_print/cust_print.c

${OBJECT_DIR}/aes_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/aes_.o   -c ${SW_DIR}/aes/aes.c

${OBJECT_DIR}/edge_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/edge_.o  -c ${SW_DIR}/edge/edge.c

${OBJECT_DIR}/fir_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/fir_.o   -c ${SW_DIR}/fir/fir.c

${OBJECT_DIR}/iir_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/iir_.o   -c ${SW_DIR}/iir/iir.c

${OBJECT_DIR}/heap_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/heap_.o   -c ${SW_DIR}/heap/heap.c

${OBJECT_DIR}/isort_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/isort_.o -c ${SW_DIR}/isort/isort.c

${OBJECT_DIR}/jdct_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/jdct_.o  -c ${SW_DIR}/jdct/jdct.c

${OBJECT_DIR}/pi_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/pi_.o  -c ${SW_DIR}/pi/pi.c

${OBJECT_DIR}/test_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/test_.o  -c ${SW_DIR}/simple_tests/test.c

${OBJECT_DIR}/end_.o: ${OBJECT_DIR}/print_.o
	$(OR32CC) $(CFLAGS) -o ${OBJECT_DIR}/end_.o  -c ${SW_DIR}/endianness/endianness.c



clean:
	rm -rf ${OBJECT_DIR}
	rm -rf ${BUILD_DIR}
	
#gdb:
#	$(OR32GDB) --args ./code.elf
