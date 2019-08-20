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
#	Author: Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#	

### recurse into sub directories
unset(LOCAL_SUBDIRS)
FILE(GLOB LOCAL_SUBDIRS ${CMAKE_CURRENT_LIST_DIR}/*)
foreach(subdir ${LOCAL_SUBDIRS})
	if(IS_DIRECTORY ${subdir})
		add_subdirectory(${subdir})
	endif()
endforeach()


unset(LOCAL_SOURCE1)
unset(LOCAL_SOURCE2)
FILE(GLOB LOCAL_SOURCE1 RELATIVE ${ETISS_ROOT_DIR} *.h)
FILE(GLOB LOCAL_SOURCE2 RELATIVE ${ETISS_ROOT_DIR} *.hpp)

set(ETISS_HEADER ${ETISS_HEADER} ${LOCAL_SOURCE1} ${LOCAL_SOURCE2} PARENT_SCOPE)
