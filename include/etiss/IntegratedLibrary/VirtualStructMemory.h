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

#ifndef ETISS_PLUGIN_VIRTUALSTRUCTMEMORY_H
#define ETISS_PLUGIN_VIRTUALSTRUCTMEMORY_H

#include "etiss/System.h"
#include "etiss/VirtualStruct.h"

namespace etiss
{
namespace plugin
{

/**
        allows to read/write to a virtual structure as if it is a memory. Any mapped field is addressed as little
   endian.
*/
class VirtualStructMemory : public SimpleSystem
{
  public:
    VirtualStructMemory(const etiss::VirtualStruct &str,
                        std::function<uint64_t(etiss::VirtualStruct::Field *, bool & /*dontMount*/)> mountPoint,
                        bool littleendian = true);
    virtual ~VirtualStructMemory();

    /**
        @attention all mapped fields are addressed as little endian
    */
    virtual bool read(bool debug, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    /**
        @attention all mapped fields are addressed as little endian
    */
    virtual bool write(bool debug, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);

    const etiss::VirtualStruct &mem_;

	typedef std::map<uint64_t, std::pair<etiss::VirtualStruct::Field * /*field*/, size_t /*offset*/>> mapping_t;
    /**
        returns the internal mapping
    */
    inline const mapping_t &getMapping()
    {
        return memmap_;
    }
    std::set<etiss::VirtualStruct::Field *> getMappedFields();

    inline uint64_t startAddr() { return startaddr_; }
    inline uint64_t endAddr() { return endaddr_; }

  protected:
  private:
    uint64_t startaddr_;
    /// excluded
    uint64_t endaddr_;
    mapping_t memmap_;
    std::list<std::shared_ptr<VirtualStruct::Field>> references;
};

} // namespace plugin
} // namespace etiss

#endif // ETISS_PLUGIN_VIRTUALSTRUCTMEMORY_H
