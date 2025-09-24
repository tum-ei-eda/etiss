// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
