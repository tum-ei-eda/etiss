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

        @author Josef Weinzierl, Chair of Electronic Design Automation, TUM

        @date November 22, 2016

        @version 0.1

*/
/**
        @file

        @brief provides custom print functions

        @detail
*/

#include <inttypes.h>

#define TO_HEX(i) ((i) <= 9 ? '0' + (i) : 'A' - 10 + (i))

#define PRINT_CHAR(LOGGER_ADDR, VAL) *(volatile char *)(LOGGER_ADDR) = (VAL)

#define PRINT_INT16(LOGGER_ADDR, VAL) *(volatile int16_t *)(LOGGER_ADDR) = (VAL)

#define PRINT_INT32(LOGGER_ADDR, VAL) *(volatile int32_t *)(LOGGER_ADDR) = (VAL)

#define PRINT_INT64(LOGGER_ADDR, VAL) *(volatile int64_t *)(LOGGER_ADDR) = (VAL)

void custom_print_string(volatile char *logger_addr, char *string);

void custom_print_hex_int8(volatile char *logger_addr, int8_t val);

void custom_print_hex_int16(volatile char *logger_addr, int16_t val);

void custom_print_hex_int32(volatile char *logger_addr, int32_t val);

void custom_print_hex_int64(volatile char *logger_addr, int64_t val);

void custom_print_float(volatile char *logger_addr, float x);

void custom_print_test(volatile char *logger_addr);
