#
#	Copyright 2018 Infineon Technologies AG
#
#	This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>
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
#	Author: Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#

import sys
import os
from os import listdir
from os.path import isfile, isdir, join, relpath,abspath
import argparse



def genCPPFile(hasArch,hasJIT,hasPlugin,hasFiles,libname):
	file = ""
	file = file + '#define ETISS_LIBNAME ' + libname + '\n'
	if hasArch:
		file = file + '#include \"etiss/helper/CPUArchLibrary.h\"\n'
	if hasJIT:
		file = file + '#include \"etiss/helper/JITLibrary.h\"\n'
	if hasPlugin:
		file = file + '#include \"etiss/helper/PluginLibrary.h\"\n'
	file = file + '#include \"etiss/Misc.h\"\n\n\n'
	file = file + "// PLACE INCLUDES HERE\n\n"
	file = file + 'extern \"C\" {\n'
	file = file + '	unsigned ' + libname + '_etissversion(){ \n'
	file = file + '		return ETISS_LIBRARYIF_VERSION;\n'
	file = file + '	}\n'
	if hasArch:
		file = file + '	unsigned ' + libname + '_countCPUArch(){ \n'
		file = file + '		return 0; ///TODO set number of provided etiss::CPUArch implementations\n'
		file = file + '	}\n'
		file = file + '	const char * ' + libname + '_nameCPUArch(unsigned index){ \n'
		file = file + '		switch (index){ ///TODO return name of a etiss::CPUArch implementation at the given index\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return "CPUArch at index 0";\n'
		file = file + '		default:\n'
		file = file + '			return "";\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	etiss::CPUArch * ' + libname + '_createCPUArch(unsigned index,std::map<std::string,std::string> options){ \n'
		file = file + '		etiss::Configuration config; config.config() = options; // load the options into a config object for easy access\n'
		file = file + '		switch (index){ ///TODO return a new instance of a etiss::CPUArch implementation at the given index\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return new CustomCPUArchImplementation(config.get<bool>("someBooleanOption"));\n'
		file = file + '		default:\n'
		file = file + '			return 0;\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	void ' + libname + '_deleteCPUArch(etiss::CPUArch * ptr){ \n'
		file = file + '		delete ptr; ///TODO check if this works, but in most cases there should be no problem\n'
		file = file + '	}\n\n\n'
	if hasJIT:
		file = file + '	unsigned ' + libname + '_countJIT(){ \n'
		file = file + '		return 0; ///TODO set number of provided etiss::JIT implementations\n'
		file = file + '	}\n'
		file = file + '	const char * ' + libname + '_nameJIT(unsigned index){ \n'
		file = file + '		switch (index){ ///TODO return name of a etiss::JIT implementation at the given index\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return "JIT at index 0";\n'
		file = file + '		default:\n'
		file = file + '			return "";\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	etiss::JIT * ' + libname + '_createJIT(unsigned index,std::map<std::string,std::string> options){ \n'
		file = file + '		etiss::Configuration config; config.config() = options; // load the options into a config object for easy access\n'
		file = file + '		switch (index){ ///TODO return a new instance of a etiss::JIT implementation at the given index\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return new CustomJITImplementation(config.get<bool>("someBooleanOption"));\n'
		file = file + '		default:\n'
		file = file + '			return 0;\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	void ' + libname + '_deleteJIT(etiss::JIT * ptr){ \n'
		file = file + '		delete ptr; ///TODO check if this works, but in most cases there should be no problem\n'
		file = file + '	}\n\n\n'
	if hasPlugin:
		file = file + '	unsigned ' + libname + '_countPlugin(){ \n'
		file = file + '		return 0; ///TODO set number of provided etiss::Plugin implementations\n'
		file = file + '	}\n'
		file = file + '	const char * ' + libname + '_namePlugin(unsigned index){ \n'
		file = file + '		switch (index){ ///TODO return name of a etiss::Plugin implementation at the given index\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return "Plugin at index 0";\n'
		file = file + '		default:\n'
		file = file + '			return "";\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	etiss::Plugin * ' + libname + '_createPlugin(unsigned index,std::map<std::string,std::string> options){ \n'
		file = file + '		etiss::Configuration config; config.config() = options; // load the options into a config object for easy access\n'
		file = file + '		switch (index){ ///TODO return a new instance of a etiss::Plugin implementation at the given index\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return new CustomPluginImplementation(config.get<bool>("someBooleanOption"));\n'
		file = file + '		default:\n'
		file = file + '			return 0;\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	void ' + libname + '_deletePlugin(etiss::Plugin * ptr){ \n'
		file = file + '		delete ptr; ///TODO check if this works, but in most cases there should be no problem\n'
		file = file + '	}\n\n\n'
	if hasFiles:
		file = file + '	unsigned ' + libname + '_getFileCount(){ \n'
		file = file + '		return 0; ///TODO set number file required to be copied\n'
		file = file + '	}\n'
		file = file + '	const char * ' + libname + '_getFileName(unsigned index){ \n'
		file = file + '		switch (index){ ///TODO return target file name (relative to etiss::cfg.get<std::string>("etiss_workdir"))\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return "somefile.txt";\n'
		file = file + '		default:\n'
		file = file + '			return "";\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	const char * ' + libname + '_getFileData(unsigned index){ \n'
		file = file + '		switch (index){ ///TODO return a pointer to the data\n'
		file = file + '		//case 0:\n'
		file = file + '		//	return "test data string";\n'
		file = file + '		default:\n'
		file = file + '			return 0;\n'
		file = file + '		}\n'
		file = file + '	}\n'
		file = file + '	int ' + libname + '_getFileSize(int index){ \n'
		file = file + '		return -1; ///TODO if the char arrays are all zero terminated string then -1 may be retured. otherwise the length must be returned\n'
		file = file + '	}\n\n\n'
	file = file + '} // extern C\n'
	return file

def genMakefile(libname,etissfolder):
	file = ''
	file = file + '\n'
	file = file + '\n\nDEBUG?=1\n\n'
	file = file + 'ifeq ($(DEBUG),0)\n'
	file = file + '	DBGPARAM= \n'
	file = file + '	OPTLEVEL?= -O3 \n'
	file = file + 'else\n'
	file = file + '	DBGPARAM= -g \n'
	file = file + '	OPTLEVEL?= \n'
	file = file + 'endif\n\n'
	file = file + '\n\n# Change path as needed\nETISS_FOLDER=' + etissfolder + '\n\n'
	file = file + '\n\nCFLAGS=-std=c++0x -c -MMD -Wall -Werror -fPIC $(OPTLEVEL) $(DBGPARAM) -DDEBUG=$(DEBUG) -Iinclude -I$(ETISS_FOLDER)/include -I$(ETISS_FOLDER)/include_c\n\n'
	file = file + 'all: lib' + libname + '.so\n'
	file = file + '\n'
	file = file + 'SOURCEFILES=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*/*.cpp)\n'
	file = file + 'OBJECTFILES=$(SOURCEFILES:src/%.cpp=build/%.o)\n'
	file = file + '\n'
	file = file + '\n'
	file = file + 'build/%.o: src/%.cpp\n'
	file = file + '	@mkdir -p $(dir $@)\n'
	file = file + '	gcc $(CFLAGS) -o $@ $<\n'
	file = file + '\n'
	file = file + '\n'
	file = file + 'lib' + libname + '.o : lib' + libname + '.cpp\n'
	file = file + '	gcc $(CFLAGS) -o $@ $<\n'
	file = file + '\n'
	file = file + '\n'
	file = file + '-include *.d'
	file = file + '-include build/*.d'
	file = file + '-include build/*/*.d'
	file = file + '-include build/*/*/*.d'
	file = file + '-include build/*/*/*/*.d'
	file = file + '\n'
	file = file + '\n'
	file = file + 'lib' + libname + '.so : $(OBJECTFILES) lib' + libname + '.o\n'
	file = file + '	gcc -std=c++0x -shared -g -o lib' + libname + '.so lib' + libname + '.o $(OBJECTFILES) -Wl,--version-script=' + libname + 'ABI.cfg\n'
	file = file + '\n'
	return file

def genABI(libname):
	file = ''
	file = file + '{\n'
	file = file + 'global: \n'
	file = file + '	' + libname + '_countCPUArch;\n'
	file = file + '	' + libname + '_nameCPUArch;\n'
	file = file + '	' + libname + '_createCPUArch;\n'
	file = file + '	' + libname + '_deleteCPUArch;\n'
	file = file + '	' + libname + '_countJIT;\n'
	file = file + '	' + libname + '_nameJIT;\n'
	file = file + '	' + libname + '_createJIT;\n'
	file = file + '	' + libname + '_deleteJIT;\n'
	file = file + '	' + libname + '_countPlugin;\n'
	file = file + '	' + libname + '_namePlugin;\n'
	file = file + '	' + libname + '_createPlugin;\n'
	file = file + '	' + libname + '_deletePlugin;\n'
	file = file + '	' + libname + '_etissversion;\n'
	file = file + '	' + libname + '_getFileCount;\n'
	file = file + '	' + libname + '_getFileName;\n'
	file = file + '	' + libname + '_getFileData;\n'
	file = file + '	' + libname + '_getFileSize;\n'
	file = file + 'local: *;\n'
	file = file + '};\n'
	file = file + '\n'
	return file



parser = argparse.ArgumentParser()

parser.add_argument('-a','--hasArch', action='store_true',help='library will provide CPUArch implementations')
parser.add_argument('-j','--hasJIT', action='store_true',help='library will provide JIT implementations')
parser.add_argument('-p','--hasPlugin', action='store_true',help='library will provide Plugin implementations')
parser.add_argument('-f','--hasFiles', action='store_true',help='library need some files copied to the working directory')
parser.add_argument('-e','--etissFolder',type=str, action='store',default='../..',help='etiss folder (used for include paths) e.g. /SOMEPATH/ETISS/trunk (default: ../..)')
parser.add_argument('libname',type=str,metavar=('libname'),help='name of the library e.g. myplugin (-> libmyplugin.so)')

args = parser.parse_args()

with open('lib' + args.libname + '.cpp', 'w+') as f:
	f.write(genCPPFile(args.hasArch,args.hasJIT,args.hasPlugin,args.hasFiles,args.libname))

with open('Makefile', 'w+') as f:
	f.write(genMakefile(args.libname,args.etissFolder))

with open( args.libname + 'ABI.cfg', 'w+') as f:
	f.write(genABI(args.libname))

if not os.path.exists('include'):
    os.makedirs('include')
if not os.path.exists('src'):
    os.makedirs('src')









