

#ifndef ETISS_PLUGIN_MEMMAPPEDPERIPH_H
#define ETISS_PLUGIN_MEMMAPPEDPERIPH_H

#include "etiss/IntegratedLibrary/SelectiveSysWrapper.h"

namespace etiss
{

namespace plugin
{

static inline etiss_uint8 unimpl_read()
{
    etiss::log(etiss::WARNING, "Unimplemented MemMappedPeriph read");
    return 0;
}
static inline void unimpl_write()
{
    etiss::log(etiss::WARNING, "Unimplemented MemMappedPeriph write");
}

/// @brief Represents a memory region that is associated with a MemMappedPeriph.
struct MappedMemory
{
    uintptr_t base = 0;
    size_t size = 0;
};

/// @brief SystemWrapperPlugin to redirect data reads and writes to custom callbacks.
class MemMappedPeriph : public etiss::plugin::SelectiveSysWrapper
{
  public:
    struct CustomHandle
    {
        ETISS_System *origSys = nullptr;
        MemMappedPeriph *mmp = nullptr;
        etiss_uint64 base = 0;
        etiss_uint64 end = 0;
    };

  public:
    /**
     * @brief Defines in which memory region to map this peripheral.
     */
    virtual MappedMemory getMappedMem() const = 0;

    virtual etiss_uint8 read8(etiss_uint64 addr) { return unimpl_read(); }
    virtual etiss_uint16 read16(etiss_uint64 addr) { return unimpl_read(); }
    virtual etiss_uint32 read32(etiss_uint64 addr) { return unimpl_read(); }
    virtual etiss_uint64 read64(etiss_uint64 addr) { return unimpl_read(); }
    virtual void write8(etiss_uint64 addr, etiss_uint8 val) { unimpl_write(); }
    virtual void write16(etiss_uint64 addr, etiss_uint16 val) { unimpl_write(); }
    virtual void write32(etiss_uint64 addr, etiss_uint32 val) { unimpl_write(); }
    virtual void write64(etiss_uint64 addr, etiss_uint64 val) { unimpl_write(); }

    ETISS_System getWrapInfo(ETISS_System *origSystem) final;
    

  private:
    CustomHandle customHandle_;
};

} // namespace plugin

} // namespace etiss

#endif
