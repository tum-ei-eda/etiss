// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief Internal fault inside MMU and

        @detail

*/

#ifndef ETISS_INCLUDE_MM_PAGEFAULTVECTOR_H_
#define ETISS_INCLUDE_MM_PAGEFAULTVECTOR_H_
#include <iostream>

namespace etiss
{
namespace mm
{

enum MM_ACCESS
{
    R_ACCESS,
    W_ACCESS,
    X_ACCESS,
};

class MMU;
void DUMP_MMU(MMU *mmu);

typedef int32_t (*handler_ptr)(int32_t fault, MMU *mmu, uint64_t vma, MM_ACCESS access);

#define MAX_PAGE_FAULT_NUM 20

#ifndef PAGE_FAULT
#define PAGE_FAULT(val, fault) const int32_t fault = val;
#endif

#ifndef REGISTER_PAGE_FAULT_HANDLER
#define REGISTER_PAGE_FAULT_HANDLER(fault, handler) page_fault_handler[fault] = handler
#endif

#ifndef HANDLE_PAGE_FAULT
#define HANDLE_PAGE_FAULT(fault, mmu, vma, access) (*page_fault_handler[fault])(fault, mmu, vma, access)
#endif

#ifdef _WIN32
    #ifdef ETISS_PLUGIN_IMPORTS
    #define MM_EXPORT __declspec(dllimport)
    #else
    #define MM_EXPORT __declspec(dllexport)
    #endif
#else
    #define MM_EXPORT
#endif

extern MM_EXPORT const int32_t NOERROR;
extern MM_EXPORT const int32_t PTEOVERLAP;
extern MM_EXPORT const int32_t TLBMISS;
extern MM_EXPORT const int32_t PTENOTEXISTED;
extern MM_EXPORT const int32_t TLBISFULL;
extern MM_EXPORT const int32_t PROTECTIONVIALATION;

extern MM_EXPORT std::string PAGE_FAULT_MSG[];
extern MM_EXPORT handler_ptr page_fault_handler[];

} // namespace mm
} // namespace etiss

#endif
