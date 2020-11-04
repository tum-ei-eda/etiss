# Install script for directory: /home/anoushka/workspace/etiss/examples/bare_etiss_processor

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/anoushka/workspace/etiss/trial11/installed")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/examples/bare_etiss_processor" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/home/anoushka/workspace/etiss/trial11/examples/bare_etiss_processor/tobeinstalled/CMakeLists.txt"
    "/home/anoushka/workspace/etiss/trial11/examples/bare_etiss_processor/tobeinstalled/run.sh"
    "/home/anoushka/workspace/etiss/trial11/examples/bare_etiss_processor/tobeinstalled/run_helper.sh"
    "/home/anoushka/workspace/etiss/examples/bare_etiss_processor/get_metrics.py"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/examples/bare_etiss_processor" TYPE DIRECTORY FILES "/home/anoushka/workspace/etiss/examples/bare_etiss_processor/" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/[^/]*\\.cpp$" REGEX "/[^/]*\\.c$" REGEX "/[^/]*\\.S$" REGEX "/[^/]*\\.s$" REGEX "/[^/]*\\.ini$" REGEX "/README[^/]*$" REGEX "/code\\_or1k\\.bin$" REGEX "/code\\_ARMv6M\\.elf$" REGEX "/\\.svn$" EXCLUDE REGEX "/[^/]*\\.in$" EXCLUDE REGEX "/CMakeLists\\.txt$" EXCLUDE)
endif()

