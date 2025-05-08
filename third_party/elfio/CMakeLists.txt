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

FetchContent_Declare(elfio_srcs
    GIT_REPOSITORY https://github.com/serge1/ELFIO.git
    GIT_TAG Release_3.11
)
if(NOT elfio_srcs_POPULATED)
    FetchContent_Populate(elfio_srcs)
    FetchContent_GetProperties(elfio_srcs)
endif()
add_subdirectory(${elfio_srcs_SOURCE_DIR} ${elfio_srcs_BINARY_DIR} EXCLUDE_FROM_ALL)
