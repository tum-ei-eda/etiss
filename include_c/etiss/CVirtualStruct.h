/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include <stdint.h>

/**
    must return an array of zero terminated strings. the array must have a zero
   sentinel e.g. const char * const * array = { "field_1", "field_2", (const
   char*)0 // sentinel
    }

    the field names of this array must be prefixed with a '.' character. befor the dot character the following
   characters may be put to set flags of that field:

    'R' - field supports read access
    'W' - field supports write access
    'P' - private field (see etiss::copy() for it's implications)
    'L' - supports listening (VirtualStruct_setListenerCallback must be
   provided)

*/
typedef const char *const *(*VirtualStruct_names)(void *handle);
/**
    similar to above array but with human readable/alternative field names (see
   etiss::VirtualStruct)

    @attention this array MUST have the same size as the array returned by the corresponding VirtualStruct_names
   function

    Note: the array may contain 0 pointers or the function may return a 0 pointer. in that case the name will be used as
   the pretty name

    pretty names have no prefixes like the names from VirtualStruct_names
*/
typedef const char *const *(*VirtualStruct_prettyNames)(void *handle);

/**
    read the value of the field at the given index
*/
typedef uint64_t (*VirtualStruct_read)(void *handle, uint32_t index);
/**
    write the value of the field at the given index
*/
typedef void (*VirtualStruct_write)(void *handle, uint32_t index);

/**
    setter function to register the callback handle for listener supported fields. one handle per virtual struct not per
   field. variables with the same name in this function and the callback must have the same value
*/
typedef void (*VirtualStruct_setListenerCallback)(void *handle, void *callbackHandle,
                                                  void (*callback)(void *handle, void *callbackHandle, uint32_t index));
