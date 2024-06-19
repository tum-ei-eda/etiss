#include "etiss/IntegratedLibrary/MemMappedPeriph.h"
#include "etiss/jit/ReturnCode.h"

namespace etiss
{
namespace plugin
{

etiss_int32 dread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buf, etiss_uint32 len)
{
    auto customH = (MemMappedPeriph::CustomHandle *)handle;
    if (addr < customH->base || addr >= customH->end)
    {
        return customH->origSys->dread(customH->origSys->handle, cpu, addr, buf, len);
    }

    switch (len)
    {
    case 1:
        *buf = customH->mmp->read8(addr);
        break;
    case 2:
        *(etiss_uint16 *)buf = customH->mmp->read16(addr);
        break;
    case 4:
        *(etiss_uint32 *)buf = customH->mmp->read32(addr);
        break;
    case 8:
        *(etiss_uint64 *)buf = customH->mmp->read64(addr);
        break;
    default:
        etiss::log(etiss::WARNING, "Ignored access to MemMappedPeriph because of unusual size");
    }

    return ETISS_RETURNCODE_NOERROR;
}

etiss_int32 dwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buf, etiss_uint32 len)
{
    auto customH = (MemMappedPeriph::CustomHandle *)handle;
    if (addr < customH->base || addr >= customH->end)
    {
        return customH->origSys->dwrite(customH->origSys->handle, cpu, addr, buf, len);
    }

    switch (len)
    {
    case 1:
        customH->mmp->write8(addr, *buf);
        break;
    case 2:
        customH->mmp->write16(addr, *(etiss_uint16 *)buf);
        break;
    case 4:
        customH->mmp->write32(addr, *(etiss_uint32 *)buf);
        break;
    case 8:
        customH->mmp->write64(addr, *(etiss_uint64 *)buf);
        break;
    default:
        etiss::log(etiss::WARNING, "Ignored access to MemMappedPeriph because of unusual size");
    }

    return ETISS_RETURNCODE_NOERROR;
}

ETISS_System MemMappedPeriph::getWrapInfo(ETISS_System *origSystem)
{
    customHandle_.origSys = origSystem;
    customHandle_.mmp = this;

    auto mm = getMappedMem();
    customHandle_.base = mm.base;
    customHandle_.end = mm.base + mm.size;

    ETISS_System wrapInfo = {};
    wrapInfo.handle = &customHandle_;
    wrapInfo.dread = &dread;
    wrapInfo.dwrite = &dwrite;
    return wrapInfo;
}

} // namespace plugin
} // namespace etiss
