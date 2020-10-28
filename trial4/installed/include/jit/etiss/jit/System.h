/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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

        @brief contains an interface for time synchronization and memory access

        @detail




*/

#ifndef ETISS_INCLUDE_JIT_SYSTEM_H_
#define ETISS_INCLUDE_JIT_SYSTEM_H_

#include "etiss/jit/CPU.h"
#include "etiss/jit/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

#pragma pack(push, 1) // NEVER ALLOW ALIGNMENT OF STRUCTURE MEMBERS
    /**
            @brief memory access and time synchronization functions. the "handle" parameter passed on a function call is
       always the "handle" variable of the structure.
            @detail to increase performance it is recommended to implement this structure directly. For convinience a
       etiss::System class is available (include/System.h) that can be extended and which will be automatically wrapped
       in an ETISS_System structure. NOTE: this structure must be packed {#pragma pack(push, 1)}
            @see include/SystemWrapper.h
            @see src/SystemWrapper.cpp
    */
    struct ETISS_System
    {

        /**
                @brief used to simulate an instruction fetch. instructions are fetched for translation with
           dbg_iread(4). this function is not used by default
        */
        etiss_int32 (*iread)(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length);
        /**
                @brief write instruction data over instruction bus
        */
        etiss_int32 (*iwrite)(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                              etiss_uint32 length);
        /**
                @brief read data
        */
        etiss_int32 (*dread)(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length);
        /**
                @brief write data
        */
        etiss_int32 (*dwrite)(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                              etiss_uint32 length);

        // debug access functions
        /**
                @brief direct debug read
        */
        etiss_int32 (*dbg_read)(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length);
        /**
                @brief direct debug write
        */
        etiss_int32 (*dbg_write)(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length);

        //        etiss_int32 (*dbg_print) (etiss_uint32 reg);
        /**
                @brief called after a block to synchronize the time
        */
        void (*syncTime)(void *handle, ETISS_CPU *cpu);

        void *handle; /**< @brief custom handle that will be passed to the functions of this structure */
    };
#pragma pack(pop)

    typedef struct ETISS_System ETISS_System;

    extern int ETISS_System_isvalid(ETISS_System *sys);

#ifdef __cplusplus
}
#endif

#endif
