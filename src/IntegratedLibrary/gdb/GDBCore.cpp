// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/gdb/GDBCore.h

        @detail

*/

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include "etiss/jit/CPU.h"

using namespace etiss::plugin::gdb;

GDBCore::~GDBCore() {}
std::string GDBCore::mapRegister(unsigned index)
{
    return "";
}
unsigned GDBCore::mapRegister(std::string name)
{
    return INVALIDMAPPING;
}
unsigned GDBCore::mappedRegisterCount()
{
    return 0;
}
bool GDBCore::isLittleEndian()
{
    return false;
}
etiss::uint64 GDBCore::getInstructionPointer(ETISS_CPU *cpu)
{
    return cpu->instructionPointer;
}
