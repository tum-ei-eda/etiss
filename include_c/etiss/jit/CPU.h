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

        @date July 24, 2014

        @version 0.1

*/
/**
        @file

        @brief contains the basic cpu state structure with a instruction pointer and time parameters. Take special care
   with alignment of structure members

        @detail

*/

#ifndef ETISS_INCLUDE_JIT_CPU_H_
#define ETISS_INCLUDE_JIT_CPU_H_

#include "etiss/jit/types.h"

#define ETISS_MAX_RESOURCES ((int)100)

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(push, 1) // NEVER ALLOW ALIGNMENT OF STRUCTURE MEMBERS
    /**
            @brief basic cpu state structure needed for execution of any cpu architecture.

            @detail <pre>
                    to use this structure for an architecture it should be customized like this:
                            #pragma pack(push, 1) // important!
                            struct YOUR_CPU {
                                    ETISS_CPU cpu;

                                    etiss_uint32 your_registers[16];

                                    [...]

                            };
                            #pragma pack(pop) // undo changes
                    now any pointer to YOUR_CPU can be directly casted to EITSS_CPU and back [YOUR_CPU ycpu; ETISS_CPU *
       cpu = (ETISS_CPU *) &ycpu; YOUR_CPU * ycpuPtr = (YOUR_CPU *) cpu;] it is guaranteed that the cpu pointer passed
       to generated code or functions of a CPUArch implementation was allocated by that CPUArch and can therefore be
       casted without additional checks.
                    </pre>
    */
    struct ETISS_CPU
    {

        etiss_uint64
            instructionPointer; ///< pointer to next instruction. NOTE: not neccessarily the instruction address (e.g
                                ///< instruction minimal size: 4; instruction pointer: 2  -> instruction address: 2*4)

        etiss_uint64 cpuTime_ps; ///< simulation time of cpu

        etiss_uint64 resourceUsages[ETISS_MAX_RESOURCES]; ///<how many cycles each resource is used

        const char *resources[ETISS_MAX_RESOURCES]; ///<names of resources

        etiss_uint64 cycles[ETISS_MAX_RESOURCES]; ///<how many cycles in each resource (including waiting)

        etiss_uint64 cpuCycleTime_ps; ///< frequency of the cpu. use to allign e.g. memory delays

        void *_etiss_private_handle_; ///< private helper handle for plugins

        etiss_uint32 mode; ///< instruction set mode of the processor

        etiss_uint32 exception; // currently active exception of the processor
        etiss_uint32 return_pending; // flags whether a return from the JIT code is needed
    };
#pragma pack(pop)

    typedef struct ETISS_CPU ETISS_CPU;

    extern void ETISS_signalChangedRegisterValue(ETISS_CPU *cpu,
                                                 const char *registerName); // implemented in CPUArch.cpp

#ifdef __cplusplus
}
#endif

#endif
