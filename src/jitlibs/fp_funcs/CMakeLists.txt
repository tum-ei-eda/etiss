PROJECT(dbtrise_fp_funcs)

ADD_LIBRARY(${PROJECT_NAME} STATIC fp_functions.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC softfloat)

INSTALL(FILES
    libdbtrise_fp_funcs.h
    DESTINATION include/jit/etiss/jit/fpu
)
InstallJitLib(${PROJECT_NAME})
