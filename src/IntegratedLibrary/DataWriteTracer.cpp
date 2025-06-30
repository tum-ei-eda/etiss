//
// Created by holaphei on 30/06/25.
//


#include "etiss/IntegratedLibrary/DataWriteTracer.h"
#include "etiss/IntegratedLibrary/TraceFileWriter.h" // Assuming this is where TraceFileWriter and DWriteEntry are defined
#include <cstring>

namespace etiss
{

namespace plugin
{

etiss_int32 dataWriteTracerLog(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buf, etiss_uint32 len)
{
    auto customH = (DataWriteTracer::CustomHandle *)handle;

    // Only trace if address matches the configured mask and value
    if ((addr & customH->mask) == customH->addr)
    {
        if (TraceFileWriter::instance().isTracing())
        {
            static std::ofstream trace_file("trace.bin", std::ios::binary | std::ios::app);
            auto &writer = TraceFileWriter::instance();

            DWriteEntry entry{};
            entry.type = 2;  // Mark as data write
            entry.pc = cpu->instructionPointer;
            entry.addr = addr;
            entry.length = len > 64 ? 64 : len;  // Clamp max length
            memcpy(entry.data, buf, entry.length);

            writer.writeDWrite(entry);
        }

    }

    // If address does not match, forward the write untouched
    return customH->origSys->dwrite(customH->origSys->handle, cpu, addr, buf, len);
}

DataWriteTracer::DataWriteTracer(uint64_t addr_value, uint64_t addr_mask)
{
    customHandle_.addr = addr_value & addr_mask;
    customHandle_.mask = addr_mask;
    if (customHandle_.addr == 0 && customHandle_.mask == 0)
    {
        etiss::log(etiss::WARNING, "DataWriteTracer instantiated with mask and address set to 0. Will trace all writes.");
    }
}

ETISS_System DataWriteTracer::getWrapInfo(ETISS_System *origSystem)
{
    customHandle_.origSys = origSystem;

    ETISS_System wrapInfo = {};
    wrapInfo.handle = &customHandle_;
    wrapInfo.dwrite = &dataWriteTracerLog;
    return wrapInfo;
}

} // namespace plugin

} // namespace etiss
