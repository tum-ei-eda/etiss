// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief

        @detail




*/
#ifndef ETISS_INCLUDE_GDB_GDBCORE_H_
#define ETISS_INCLUDE_GDB_GDBCORE_H_

#include "etiss/Misc.h"
#include <string>

namespace etiss
{

namespace plugin
{

namespace gdb
{

/**
        @brief provides to architecture dependent registers as defined by gdb

        @detail gdb requires a predefined archtecture specific list of registers. Information about this list is
   provided by this class
*/
class GDBCore
{
  public:
    virtual ~GDBCore();
    /**
            @brief the returned string identifies the register at the given index as defined by gdb. the returned string
       must match the get/setRegisterXX() functions of etiss::CPUArch
    */
    virtual std::string mapRegister(unsigned index);
    /**
            @brief returns the index of the given register name in the list of registers as defined by gdb. max return
       INVALIDMAPPING if the passed name is not in the list
    */
    virtual unsigned mapRegister(std::string name);
    /**
            @brief returns the number of registers in the gdb defined register list
    */
    virtual unsigned mappedRegisterCount();
    /**
            @brief returns true if the values are expected to be little endian
    */
    virtual bool isLittleEndian();
    /**
            @brief allows to calculate the index of the instruction to be executed for breakpoint checks. returns
       cpu->instructionPointer by default.
            @detail the OR1K architecture uses this to account for an invalid instruction pointer in case of a delay
       slot instruction
    */
    virtual etiss::uint64 getInstructionPointer(ETISS_CPU *cpu);

  public:
    static const unsigned INVALIDMAPPING = (unsigned)-1;
};

} // namespace gdb

} // namespace plugin
} // namespace etiss

#endif
