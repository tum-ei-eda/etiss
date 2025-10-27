// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <sstream>
#include "etiss/ETISS.h"
#include "etiss/mm/PageFaultVector.h"
#include "etiss/ETISS.h"
#include "etiss/mm/MMU.h"
#include <sstream>

namespace etiss
{
namespace mm
{

PAGE_FAULT(0, NOERROR)
PAGE_FAULT(1, PTEOVERLAP)
PAGE_FAULT(2, TLBMISS)
PAGE_FAULT(3, PTENOTEXISTED)
PAGE_FAULT(4, TLBISFULL)
PAGE_FAULT(5, PROTECTIONVIALATION)

std::string PAGE_FAULT_MSG[MAX_PAGE_FAULT_NUM] = { "no error occurs",
                                                   "page table entry already existed",
                                                   "TLB miss",
                                                   "evict a non-existed PTE",
                                                   "TLB is already full",
                                                   "TLB is already full" };

static int32_t page_fault_ni_(int32_t fault, MMU *mmu, uint64_t, MM_ACCESS)
{
    if (fault)
    {
        std::stringstream msg;
        msg << "Fault message: [" << PAGE_FAULT_MSG[fault] << "]";
        msg << "Corresponding handler not registered yet. " << std::endl;
        DUMP_MMU(mmu);
        etiss::log(etiss::FATALERROR, msg.str());
    }
    return NOERROR;
}

handler_ptr page_fault_handler[MAX_PAGE_FAULT_NUM] = {
    page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_,
    page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_,
    page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_, page_fault_ni_,
};

} // namespace mm
} // namespace etiss
