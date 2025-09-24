// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
