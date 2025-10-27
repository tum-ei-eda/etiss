// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/IntegratedLibrary/VirtualStructMemory.h"

namespace etiss
{
namespace plugin
{

VirtualStructMemory::VirtualStructMemory(
    const etiss::VirtualStruct &str, std::function<uint64_t(etiss::VirtualStruct::Field *, bool &dontMount)> mountPoint,
    bool littleendian)
    : mem_(str)
{

    startaddr_ = std::numeric_limits<uint64_t>::max();
    endaddr_ = 0;

    ((etiss::VirtualStruct *)&str)
        ->foreachField(
            [&](std::shared_ptr<VirtualStruct::Field> field)
            {
                references.push_back(field);
                etiss::VirtualStruct::Field *f = (field).get();

                bool dontMount = false;
                uint64_t addr = mountPoint(f, dontMount);

                if (dontMount)
                    return;

                if (addr < startaddr_)
                    startaddr_ = addr;

                if (endaddr_ < (addr + f->width_))
                    endaddr_ = addr + f->width_;

                for (size_t i = 0; i < f->width_; ++i)
                {
                    // auto m =
                    memmap_.insert(
                        std::make_pair(addr + i, std::make_pair(f, (littleendian ? i : (f->width_ - 1 - i)))));
                    // etiss::log(etiss::VERBOSE,"mapped:
                    // ",m.first->first,m.first->second.second,m.first->second.first->name_);
                }
            });
}

VirtualStructMemory::~VirtualStructMemory()
{
    // dtor
}

bool VirtualStructMemory::read(bool debug, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{

    for (unsigned i = 0; i < len; ++i)
    {
        auto find = memmap_.find(addr + i);
        if (find != memmap_.end())
        {
            etiss::VirtualStruct::Field *f = find->second.first;
            size_t off = find->second.second << 3;
            uint64_t fval = f->read();
            fval = fval >> off;
            buf[i] = (uint8_t)(fval & 0xFF);
        }
        else
        {
            buf[i] = 0;
        }
    }

    return true;
}
bool VirtualStructMemory::write(bool debug, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{

    for (unsigned i = 0; i < len; ++i)
    {
        auto find = memmap_.find(addr + i);
        if (find != memmap_.end())
        {
            etiss::VirtualStruct::Field *f = find->second.first;
            size_t off = find->second.second << 3;
            uint64_t fval = f->read();
            uint64_t mask = 0xFF;
            mask = mask << off;
            fval = fval & ~mask;
            // uint64_t fvaltest = (((uint64_t)(uint8_t)buf[i]) << off); // DNM DEBUG
            fval = fval | (((uint64_t)(uint8_t)buf[i]) << off);
            f->write(fval);
            {
                std::stringstream ss;
                ss << "write to field " << f->name_ << "{" << f->prettyname_ << "}: 0x" << std::hex << f->read()
                   << " (offset: 0x" << std::hex << find->second.second << ")" << std::endl;
                // DEBUG DNM
                // std::cout << "VirtualStructMemory::write: " << " write to field " << f->name_ << "{" <<
                // f->prettyname_ << "}: 0x" << std::hex << f->read() << " val=0x"<< fvaltest << "(offset: 0x" <<
                // std::hex << find->second.second << ")" << std::endl; etiss::log(etiss::VERBOSE,ss.str());
            }
        }
        else
        {
            // ignore
        }
    }

    return true;
}
std::set<etiss::VirtualStruct::Field *> VirtualStructMemory::getMappedFields()
{

    std::set<etiss::VirtualStruct::Field *> ret;

    for (auto iter = memmap_.begin(); iter != memmap_.end(); ++iter)
    {
        ret.insert(iter->second.first);
    }

    return ret;
}

} // namespace plugin
} // namespace etiss
