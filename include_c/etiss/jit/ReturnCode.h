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

        @brief contains exception/return codes used to control execution of an etiss::CPUCore

        @detail any return code defined with the defineReturnCode(NAME,VALUE,MSG) macro is available in C++ under the
   name etiss::RETURNCODE::NAME and ETISS_RETURNCODE_NAME and in C under the name ETISS_RETURNCODE_NAME. In C++ the
   return code names and messages are accessible via the maps returned by etiss::RETURNCODE::getErrorMessages and
   etiss::RETURNCODE::getErrorNames

*/
#ifndef ETISS_INCLUDE_RETURNCODE_H_
#define ETISS_INCLUDE_RETURNCODE_H_

#include "etiss/jit/types.h"

#ifdef __cplusplus

#include "etiss/Misc.h" // etiss::log(2)
#include <map>

namespace etiss
{

namespace RETURNCODE
{
/**
        @brief function to access error message map. implemented in ETISS.cpp
        @see ETISS.cpp
*/
extern std::map<etiss::int32, const char *> &getErrorMessages();
/**
        @brief function to access error name map. implemented in ETISS.cpp
        @see ETISS.cpp
*/
extern std::map<etiss::int32, const char *> &getErrorNames();

extern int32_t setTemporary(const std::string &msg);

} // namespace RETURNCODE

} // namespace etiss

#endif

/// sets the message of a temporary return code and returns the returncode. use for custom messages. message may be
/// overwritten if all other temporary return codes are used
extern int32_t etiss_returncode_setTemporary(const char *msg);

#ifndef etiss_toString
#define etiss__toString_(X) #X
#define etiss_toString(X) etiss__toString_(X)
#endif
#ifndef etiss_merge2
#define etiss__merge2_(X, Y) X##Y
#define etiss_merge2(X, Y) etiss__merge2_(X, Y)
#endif

/**
        define RETURNCODE definition template for easy use with c and c++
*/
#ifdef __cplusplus
#ifdef ETISS_RETURNCODE_REGISTRATION_BODY

#define defineReturnCodeClass_(UNIQUENUMBER, NAME, VALUE, MSG)                                                   \
    static class ReturnCodeRegistration_##UNIQUENUMBER                                                           \
    {                                                                                                            \
      public:                                                                                                    \
        ReturnCodeRegistration_##UNIQUENUMBER()                                                                  \
        {                                                                                                        \
            auto entry = etiss::RETURNCODE::getErrorNames().find(VALUE);                                         \
            if (entry != etiss::RETURNCODE::getErrorNames().end())                                               \
            {                                                                                                    \
                if (std::string(entry->second) != etiss_toString(NAME))                                          \
                {                                                                                                \
                    std::stringstream ss;                                                                        \
                    ss << "Duplicated RETURNCODE " << VALUE << ": ";                                             \
                    ss << etiss::RETURNCODE::getErrorNames().find(VALUE)->second << "," << etiss_toString(NAME); \
                    etiss::log(etiss::ERROR, ss.str());                                                          \
                }                                                                                                \
            }                                                                                                    \
            etiss::RETURNCODE::getErrorMessages()[VALUE] = MSG;                                                  \
            etiss::RETURNCODE::getErrorNames()[VALUE] = etiss_toString(NAME);                                    \
        }                                                                                                        \
    } returnCodeRegistration_##UNIQUENUMBER;

#define defineReturnCodeClass(UNIQUENUMBER, NAME, VALUE, MSG) defineReturnCodeClass_(UNIQUENUMBER, NAME, VALUE, MSG)

#define defineReturnCode(NAME, VALUE, MSG)                                  \
    namespace etiss                                                         \
    {                                                                       \
    namespace RETURNCODE                                                    \
    {                                                                       \
    static const etiss::int32 NAME = VALUE;                                 \
    }                                                                       \
    }                                                                       \
    static const etiss_int32 etiss_merge2(ETISS_RETURNCODE_, NAME) = VALUE; \
    defineReturnCodeClass(__COUNTER__, NAME, VALUE, MSG)
#else
#define defineReturnCode(NAME, VALUE, MSG)                    \
    static const etiss_int32 ETISS_RETURNCODE_##NAME = VALUE; \
    namespace etiss                                           \
    {                                                         \
    namespace RETURNCODE                                      \
    {                                                         \
    static const etiss::int32 NAME = VALUE;                   \
    }                                                         \
    }
#endif
#else
#define defineReturnCode(NAME, VALUE, MSG) static const etiss_int32 ETISS_RETURNCODE_##NAME = VALUE;
#endif

// winerror.h defines this.
#ifdef NOERROR
#undef NOERROR
#endif

//////////////////// definition of global (cpu architecture independent) return codes

defineReturnCode(NOERROR, 0, "No error.") defineReturnCode(GENERALERROR, -1, "General error.")

    defineReturnCode(RELOADBLOCKS, -2, "Clear cached translated blocks.")
        defineReturnCode(RELOADCURRENTBLOCK, -3, "Clear the cached block that returned this code.")
    // defineReturnCode(RELOADRANGE,-4,"clear cached translated blocks in a range")

    defineReturnCode(DBUS_READ_ERROR, -5, "Data bus read error.") defineReturnCode(DBUS_WRITE_ERROR, -6,
                                                                                   "Data bus write error.")
        defineReturnCode(IBUS_READ_ERROR, -7,
                         "Instruction bus read error.") defineReturnCode(IBUS_WRITE_ERROR, -8,
                                                                         "Instruction bus write error.")

            defineReturnCode(INTERRUPT, -9, "Signal an interrupt.") defineReturnCode(RESET, -10, "Reset signal.")

                defineReturnCode(ILLEGALINSTRUCTION, -11,
                                 "Illegal instruction.") defineReturnCode(ILLEGALJUMP, -12, "Illegal jump address.")
                    defineReturnCode(INSTR_PAGEFAULT, -13, "Instruction page fault.") defineReturnCode(
                        LOAD_PAGEFAULT, -14, "Load page fault.") defineReturnCode(STORE_PAGEFAULT, -15,
                                                                                  "Store page fault.")

                        defineReturnCode(GDBNOERROR, -16,
                                         "Has the same effect as NOERROR but allows exiting a block where NOERROR "
                                         "would have continued block execution.")

                            defineReturnCode(SYSCALL, -17, "System call") defineReturnCode(
                                PAGEFAULT, -18, "Virtual memory tranlation fault.") defineReturnCode(BREAKPOINT, -19,
                                                                                                     "Break point.")

                                defineReturnCode(CPUFINISHED, 1 << 31,
                                                 "Finished cpu execution. This is the proper way to exit from "
                                                 "etiss::CPUCore::execute.")
                                    defineReturnCode(CPUTERMINATED, 0x80000001,
                                                     "Terminates cpu execution. this is the proper way to force an "
                                                     "exit from etiss::CPUCore::execute (e.g. by a debugger).")

                                        defineReturnCode(JITERROR, -32, "Error in JIT.")
                                            defineReturnCode(JITCOMPILATIONERROR, -33, "Error in JIT compilation.")
                                                defineReturnCode(ARCHERROR, -34, "Error in architecture.")
                                                    defineReturnCode(EMULATIONNOTSUPPORTED, -35,
                                                                     "Emulation is not supported.")

                                                        defineReturnCode(INVALIDSYSTEM, -36,
                                                                         "An ETISS_System structure doesn't contain "
                                                                         "the neccessary function pointers.")

                                                            defineReturnCode(TEMPORARY0, -128,
                                                                             "") defineReturnCode(TEMPORARY1, -129, "")
                                                                defineReturnCode(TEMPORARY2, -130, "")
                                                                    defineReturnCode(TEMPORARY3, -131, "")
                                                                        defineReturnCode(TEMPORARY4, -132, "")
                                                                            defineReturnCode(TEMPORARY5, -133, "")
                                                                                defineReturnCode(TEMPORARY6, -134, "")
                                                                                    defineReturnCode(TEMPORARY7, -135,
                                                                                                     "")
#define ETISS_RETURNCODE_TEMPORARY_COUNT 8

#endif
