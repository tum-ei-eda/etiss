PROJECT(resources)

ADD_LIBRARY(${PROJECT_NAME} STATIC resources.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ETISS)

INSTALL(FILES
    libresources.h
    DESTINATION include/jit/etiss/jit
)
InstallJitLib(${PROJECT_NAME})
