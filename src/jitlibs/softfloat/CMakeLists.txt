PROJECT(softfloat)

##################### SOFTFLOAT JIT LIBRARY #####################

ADD_LIBRARY(${PROJECT_NAME} SHARED
    fp_functions.cpp
)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC berkeley-softfloat)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD VERBATIM
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ETISS_BINARY_DIR}/include/jit/etiss/jit/
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:${PROJECT_NAME}>" ${ETISS_BINARY_DIR}/include/jit/etiss/jit/
)

INSTALL(FILES
    libsoftfloat.h
    DESTINATION include/jit/etiss/jit
)
InstallJitLib(${PROJECT_NAME})
