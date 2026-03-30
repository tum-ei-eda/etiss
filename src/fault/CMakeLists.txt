# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

### recurse into sub directories
unset(LOCAL_SUBDIRS)
FILE(GLOB LOCAL_SUBDIRS ./ *)
foreach(subdir ${LOCAL_SUBDIRS})
	if(IS_DIRECTORY ${subdir})
		add_subdirectory(${subdir})
	endif()
endforeach()


unset(LOCAL_SOURCE)
FILE(GLOB LOCAL_SOURCE *.cpp)

set(ETISS_SOURCE ${ETISS_SOURCE} ${LOCAL_SOURCE} PARENT_SCOPE)
