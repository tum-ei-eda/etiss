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
#	Author: Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#

project(bare_etiss_processor)

# Set relative rpath to mimic runtime link behavior of windows (libs loadable from current dir)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")

add_executable(bare_etiss_processor main.cpp)
target_link_libraries(bare_etiss_processor ETISS)

set(ETISS_DIR ${CMAKE_INSTALL_PREFIX} )
configure_file(
    run_helper.sh.in
    "${PROJECT_BINARY_DIR}/tobeinstalled/run_helper.sh"
    @ONLY
)

set(ETISS_DIR ${CMAKE_BINARY_DIR})
configure_file(
    run_helper.sh.in
    "${CMAKE_BINARY_DIR}/bin/run_helper.sh"
    @ONLY
)
configure_file(
    base.ini
    "${CMAKE_BINARY_DIR}/examples/base.ini"
    COPYONLY
)
set_target_properties( bare_etiss_processor
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
 )

install(TARGETS bare_etiss_processor DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/tobeinstalled/run_helper.sh"
    DESTINATION bin
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
    DESTINATION examples
    FILES_MATCHING
    PATTERN "*.ini"
)