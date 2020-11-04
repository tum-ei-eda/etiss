# Install script for directory: /home/anoushka/workspace/etiss/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/anoushka/workspace/etiss/tryflags/installed")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/examples" TYPE DIRECTORY FILES "/home/anoushka/workspace/etiss/examples/" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/[^/]*\\.cpp$" REGEX "/[^/]*\\.c$" REGEX "/[^/]*\\.S$" REGEX "/[^/]*\\.s$" REGEX "/[^/]*\\.ld$" REGEX "/[^/]*\\.py$" REGEX "/[^/]*\\.pl$" REGEX "/[^/]*\\.pm$" REGEX "/[^/]*\\.pod\\.html$" REGEX "/[^/]*LICENCE[^/]*$" REGEX "/[^/]*\\.m$" REGEX "/README[^/]*$" REGEX "/[^/]*\\.ini$" REGEX "/Makefile$" REGEX "/[^/]*\\.config$" REGEX "/\\.svn$" EXCLUDE REGEX "/[^/]*\\.in$" EXCLUDE REGEX "/CMakeLists\\.txt$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/anoushka/workspace/etiss/tryflags/examples/bare_etiss_processor/cmake_install.cmake")
  include("/home/anoushka/workspace/etiss/tryflags/examples/SW/cmake_install.cmake")

endif()

