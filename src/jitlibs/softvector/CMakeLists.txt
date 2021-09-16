SET(ETISS_PREFIX ${PROJECT_SOURCE_DIR})

PROJECT(etiss_softvector)

SET(TARGET_PLATFORM_NAME "riscv")

include(FetchContent)
FetchContent_Declare(softvector_srcs
    GIT_REPOSITORY https://github.com/tum-ei-eda/softvector.git
    GIT_TAG master
)

if(NOT softvector_srcs_POPULATED)
    FetchContent_Populate(softvector_srcs)
    FetchContent_GetProperties(softvector_srcs)
    set(EXTERNAL_INSTALL_LOCATION ${softvector_srcs_SOURCE_DIR})
    INSTALL(
        FILES ${softvector_srcs_SOURCE_DIR}/include/target/${TARGET_PLATFORM_NAME}/softvector.h
        DESTINATION include/jit/etiss/jit)
    SET(SOFTVECTOR_BUILD_DOC OFF)
endif()

ADD_SUBDIRECTORY(${softvector_srcs_SOURCE_DIR} ${softvector_srcs_BINARY_DIR})

##################### SOFTVECTOR JIT LIBRARY #####################

ADD_LIBRARY(${PROJECT_NAME} SHARED
    etiss_softvector.cpp
)

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
    ${ETISS_PREFIX}/include_c
    ${softvector_srcs_SOURCE_DIR}/include/target/${TARGET_PLATFORM_NAME}
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC softvector)

INSTALL(FILES
    libsoftvector.h
    DESTINATION include/jit/etiss/jit
)
InstallJitLib(${PROJECT_NAME})
InstallJitLib(softvector)
