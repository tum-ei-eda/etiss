####################################################################################################
# Copyright 2023 Chair of EDA, Technical University of Munich
#
# Licensed under the Apache License, Version 2.0 (the License);
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
####################################################################################################

cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(simpleini_srcs
    GIT_REPOSITORY https://github.com/brofield/simpleini.git
    GIT_TAG v4.19
)
if(NOT simpleini_srcs_POPULATED)
    FetchContent_Populate(simpleini_srcs)
    FetchContent_GetProperties(simpleini_srcs)
endif()

add_library(simpleini OBJECT
    "${simpleini_srcs_SOURCE_DIR}/ConvertUTF.c"
)
set_target_properties(simpleini PROPERTIES
    PUBLIC_HEADER "${simpleini_srcs_SOURCE_DIR}/SimpleIni.h;${simpleini_srcs_SOURCE_DIR}/ConvertUTF.h"
)
target_include_directories(simpleini PUBLIC
    $<BUILD_INTERFACE:${simpleini_srcs_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/simpleini>
)
install(TARGETS simpleini
    PUBLIC_HEADER DESTINATION include/simpleini
)
