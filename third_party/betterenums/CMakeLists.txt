####################################################################################################
# Copyright 2025 Chair of EDA, Technical University of Munich
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

FetchContent_Declare(betterenums_srcs
    GIT_REPOSITORY https://github.com/aantron/better-enums.git
    GIT_TAG 0.11.3
)
if(NOT betterenums_srcs_POPULATED)
    FetchContent_Populate(betterenums_srcs)
    FetchContent_GetProperties(betterenums_srcs)
endif()
add_library(betterenums INTERFACE)
set_target_properties(betterenums PROPERTIES
    PUBLIC_HEADER "${betterenums_srcs_SOURCE_DIR}/enum.h"
)
target_include_directories(betterenums INTERFACE
    $<BUILD_INTERFACE:${betterenums_srcs_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
install(TARGETS betterenums
    PUBLIC_HEADER DESTINATION include
)