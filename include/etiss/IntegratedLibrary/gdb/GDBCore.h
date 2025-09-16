/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date September 2, 2014

        @version 0.1

*/
/**
        @file

        @brief

        @detail




*/
#ifndef ETISS_INCLUDE_GDB_GDBCORE_H_
#define ETISS_INCLUDE_GDB_GDBCORE_H_

#include "etiss/jit/CPU.h"
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
    virtual std::string getXMLContents(ETISS_CPU *cpu, std::string archName, std::string fname);

  public:
    static const unsigned INVALIDMAPPING = (unsigned)-1;
};

} // namespace gdb

} // namespace plugin
} // namespace etiss

#endif
