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
