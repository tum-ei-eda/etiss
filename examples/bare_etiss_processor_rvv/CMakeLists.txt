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

project(bare_etiss_processor_rvv_example)


configure_file(
    CMakeLists.txt.in
    "${PROJECT_BINARY_DIR}/tobeinstalled/CMakeLists.txt"
    @ONLY
)
configure_file(
    run.sh.in
    "${PROJECT_BINARY_DIR}/tobeinstalled/run.sh"
    @ONLY
)
configure_file(
    run_helper.sh.in
    "${PROJECT_BINARY_DIR}/tobeinstalled/run_helper.sh"
    @ONLY
)

install(FILES
    "${PROJECT_BINARY_DIR}/tobeinstalled/CMakeLists.txt"
    "${PROJECT_BINARY_DIR}/tobeinstalled/run.sh"
    "${PROJECT_BINARY_DIR}/tobeinstalled/run_helper.sh"
    "get_metrics.py"
    DESTINATION examples/bare_etiss_processor_rvv
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/
    DESTINATION examples/bare_etiss_processor_rvv
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.cpp"
    PATTERN "*.c"
    PATTERN "*.S"
    PATTERN "*.s"
    PATTERN "*.ini"
    PATTERN "README*"
    PATTERN ".svn" EXCLUDE
    PATTERN "*.in" EXCLUDE
    PATTERN "CMakeLists.txt" EXCLUDE
)
