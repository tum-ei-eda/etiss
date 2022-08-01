PROJECT(semihost)

IF(WIN32)
	SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
ENDIF()

ADD_LIBRARY(${PROJECT_NAME} SHARED
    semihost.cpp
)


add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD VERBATIM
  COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include/jit/etiss/jit/
  COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:${PROJECT_NAME}>" ${CMAKE_BINARY_DIR}/include/jit/etiss/jit/
)

  
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ETISS)

INSTALL(FILES
    libsemihost.h
    DESTINATION include/jit/etiss/jit
)
InstallJitLib(${PROJECT_NAME})
