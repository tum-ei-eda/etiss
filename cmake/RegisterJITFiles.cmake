
MACRO(RegisterJITFiles Files)
    FOREACH(File ${Files})
        STRING(REPLACE "," ";" FilePair ${File})
        LIST(GET FilePair 0 TargetFile)
        LIST(GET FilePair -1 ExistingFile)
        GET_FILENAME_COMPONENT(TargetPath ${TargetFile} DIRECTORY)
        INSTALL(FILES "${ExistingFile}" DESTINATION "include/jit/${TargetPath}")
    ENDFOREACH()
ENDMACRO()

MACRO(RegisterJITFileArch Arch)
    INSTALL(FILES "${CMAKE_CURRENT_LIST_DIR}/${Arch}.h" DESTINATION "include/jit/Arch/${Arch}")
ENDMACRO()
