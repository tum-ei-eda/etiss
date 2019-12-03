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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @date June 24, 2018

        @version 0.1

*/
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

#ifdef ETISS_PLUGIN_IMPORTS
#define MM_EXPORT __declspec(dllimport)
#else
#define MM_EXPORT __declspec(dllexport)
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
