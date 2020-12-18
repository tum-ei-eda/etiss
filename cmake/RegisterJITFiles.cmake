
MACRO(RegisterJITFiles Files)
    FOREACH(File ${Files})
        STRING(REPLACE "," ";" FilePair ${File})
        LIST(GET FilePair 0 TargetFile)
        LIST(GET FilePair -1 ExistingFile)
        GET_FILENAME_COMPONENT(TargetPath ${TargetFile} DIRECTORY)
        GET_FILENAME_COMPONENT(TargetFile ${TargetFile} NAME)
        INSTALL(FILES "${ExistingFile}" DESTINATION "include/jit/${TargetPath}" RENAME ${TargetFile})

        # mimicing installation in build tree as well
        # NOTE: pluginexport hasn't been generated yet so will be copied later
        if (NOT "${ExistingFile}" STREQUAL "${ETISS_BINARY_DIR}/include/etiss/pluginexport.h")
          file(COPY "${ExistingFile}" DESTINATION "${ETISS_BINARY_DIR}/include/jit/${TargetPath}")
        endif()
    ENDFOREACH()
ENDMACRO()

MACRO(RegisterJITFileArch Arch)
    INSTALL(FILES "${CMAKE_CURRENT_LIST_DIR}/${Arch}.h" DESTINATION "include/jit/Arch/${Arch}")

    # mimicing installation in build tree as well
    file(COPY "${CMAKE_CURRENT_LIST_DIR}/${Arch}.h" DESTINATION "${ETISS_BINARY_DIR}/include/jit/Arch/${Arch}")
ENDMACRO()
