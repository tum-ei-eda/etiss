PROJECT(softfloat)

# TODO: Add softfloat lib as external project
ADD_LIBRARY(${PROJECT_NAME}
    dummy.cpp
)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC .)

INSTALL(FILES
    softfloat_orig.h
    DESTINATION include/jit/etiss/jit/fpu
)
RegisterJITFiles("etiss/jit/fpu/libsoftfloat.a,${CMAKE_CURRENT_SOURCE_DIR}/softfloat.a")
