// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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

        etiss_uint64 nextPc;

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
