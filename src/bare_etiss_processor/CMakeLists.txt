# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

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

configure_file(
    run_helper.sh.in
    "${ETISS_BINARY_DIR}/bin/run_helper.sh"
    @ONLY
)
configure_file(
    base.ini
    "${ETISS_BINARY_DIR}/examples/base.ini"
    COPYONLY
)
set_target_properties( bare_etiss_processor
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${ETISS_BINARY_DIR}/bin"
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
    PATTERN "*.xml"
)
