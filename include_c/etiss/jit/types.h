// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file



        @brief type declarations for etiss and definition of the likely/unlikely macros.

        @detail current jit implementations (GCC/LLVM) don't require customization of this file.




*/
#ifndef ETISS_INCLUDE_TYPES_H_
#define ETISS_INCLUDE_TYPES_H_

// TODO: move to special header provided by compiler
//_________________________________________________________________
//#ifdef _MSC_VER
//#include "etiss/jit/msvc_stdint.h"
//#else
#include <stdint.h>
//#endif
//#include <stdbool.h> // removed since it may not be available

#ifdef __GNUC__
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif

//_________________________________________________________________

#define stream_code_info "\t{ File: " << __FILE__ << "\tLine: " << __LINE__ << "}"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef int8_t etiss_int8;
    typedef uint8_t etiss_uint8;

    typedef int16_t etiss_int16;
    typedef uint16_t etiss_uint16;

    typedef int32_t etiss_int32;
    typedef uint32_t etiss_uint32;

    typedef int64_t etiss_int64;
    typedef uint64_t etiss_uint64;

    typedef etiss_int64 etiss_intMax;
    typedef etiss_uint64 etiss_uintMax;

#ifdef __GNUC__
    typedef __int128_t etiss_int128;
    typedef __uint128_t etiss_uint128;
#endif

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace etiss
{

typedef etiss_int8 int8;
typedef etiss_uint8 uint8;

typedef etiss_int16 int16;
typedef etiss_uint16 uint16;

typedef etiss_int32 int32;
typedef etiss_uint32 uint32;

typedef etiss_int64 int64;
typedef etiss_uint64 uint64;

typedef etiss_intMax intMax;
typedef etiss_uintMax uintMax;

#ifdef __GNUC__
typedef __int128_t etiss_int128;
typedef __uint128_t etiss_uint128;
#endif

} // namespace etiss
#endif

#endif
