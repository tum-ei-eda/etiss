# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

# simple CMakeLists.txt file that can be placed in folders to recurse into subfolders if
# the sub folder contains a CMakeLists.txt

FILE(GLOB LOCAL_SUBDIRS RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/*)
foreach(subdir ${LOCAL_SUBDIRS})
	if(IS_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/${subdir})
		if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${subdir}/CMakeLists.txt)
			add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/${subdir})
			message(STATUS "Including sub project ${subdir}.")
		else()
			message(WARNING "Directory ${subdir} is not added to the current build because it lacks a CMakeLists.txt")
		endif()
	endif()
endforeach()
