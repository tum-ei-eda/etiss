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

#pass this parameter to put the object file into a custom location. e.g.: FAULT_XML_MODULE_BUILD="../build/" -> object files will be in "../build/fault/*.o"
# ATTENTION: folder MUST end with a seperator ( / )
FAULT_XML_MODULE_BUILD?=

FAULT_XML_MODULE_SOURCES=$(wildcard fault/*.cpp) $(wildcard fault/xml/*.cpp)
# use this to include the object files directly without using fault_xml_module.a
FAULT_XML_MODULE_OBJECTS=$(FAULT_XML_MODULE_SOURCES:%.cpp=$(FAULT_XML_MODULE_BUILD)%.o)

fault_xml_module_all: fault_xml_module.a

$(FAULT_XML_MODULE_BUILD)fault/%.o: fault/%.cpp
	mkdir -p $(dir $@)
	gcc -c -MMD -I./ -O2 -g1 -o $@ $<

-include $(FAULT_XML_MODULE_BUILD)fault/*.d
-include $(FAULT_XML_MODULE_BUILD)fault/xml/*.d

fault_xml_module.a: $(FAULT_XML_MODULE_OBJECTS)
	ar rcs fault_xml_module.a $(FAULT_XML_MODULE_OBJECTS)
	
clean:
	rm -f fault/*.o
	rm -f fault/xml/*.o
	rm -f fault/*.d
	rm -f fault/xml/*.d
