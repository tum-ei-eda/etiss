// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
