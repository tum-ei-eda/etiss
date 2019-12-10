/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

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

    ((etiss::VirtualStruct *)&str)->foreachField([&](std::shared_ptr<VirtualStruct::Field> field) {
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
            memmap_.insert(std::make_pair(addr + i, std::make_pair(f, (littleendian ? i : (f->width_ - 1 - i)))));
            // etiss::log(etiss::VERBOSE,"mapped: ",m.first->first,m.first->second.second,m.first->second.first->name_);
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
            uint64_t fvaltest = (((uint64_t)(uint8_t)buf[i]) << off); // DNM DEBUG
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
