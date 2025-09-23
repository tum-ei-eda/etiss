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

####################################################################################################
# ELFIO (used for loading cross compiled ELFs to ETISS Memory Systems)
# Makes CMake target "elfio::elfio" aka "elfio" available
add_subdirectory(elfio)

####################################################################################################
# SimpleIni (used for loading cross compiled ELFs to ETISS Memory Systems)
# Makes CMake target "simpleini" aka "elfio" available
add_subdirectory(simpleini)

####################################################################################################
# (berkeley) softfloat (used for floating point support in JIT code)
# Makes CMake target berkeley-softfloat
add_subdirectory(softfloat)

####################################################################################################
# pugixml (used in fault injection plugins)
# Makes CMake target pugixml available
add_subdirectory(pugixml)

####################################################################################################
# tcc (used in JITImpl)
# Makes CMake target TinyCC and tcc available (only UNIX)
add_subdirectory(tcc)

####################################################################################################
# betternums (used in fault injection plugins)
# Makes CMake target betterenums available
add_subdirectory(betterenums)