# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

MACRO(ETISSPlugin ProjName)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ETISS)
    TARGET_COMPILE_DEFINITIONS(${PROJECT_NAME} PRIVATE ETISS_EXPORTS ETISS_PLUGIN_IMPORTS)
    IF(ETISS_BINARY_DIR)
        set_target_properties(${ProjName} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${ETISS_BINARY_DIR}/lib/plugins/)
    ENDIF()

    INSTALL(TARGETS ${ProjName}
        RUNTIME DESTINATION lib/plugins
        LIBRARY DESTINATION lib/plugins
        ARCHIVE DESTINATION lib/plugins
    )
    INSTALL(CODE
        "FILE(APPEND
            \"${CMAKE_INSTALL_PREFIX}/lib/plugins/list.txt\"
            \"${ProjName},\${CMAKE_INSTALL_PREFIX}/lib/plugins,${ProjName}\\n\"
        )"
    )

    # mimicing installation in build tree as well
    IF(ETISS_BINARY_DIR)
        file(APPEND ${ETISS_BINARY_DIR}/lib/plugins/list.txt
        "${ProjName},${ETISS_BINARY_DIR}/lib/plugins,${ProjName}\n")
    ENDIF()
ENDMACRO()

MACRO(ETISSPluginArchName ProjName ArchName)
    ETISSPlugin(${ProjName})
    RegisterJITFileArch(${ArchName})
ENDMACRO()

MACRO(ETISSPluginArch ProjName)
    ETISSPluginArchName(${ProjName} ${ProjName})
    get_property(jitlibs GLOBAL PROPERTY etiss_jitlibs)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC "${jitlibs}")
ENDMACRO()
