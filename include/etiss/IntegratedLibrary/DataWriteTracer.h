#ifndef ETISS_PLUGIN_DATAWRITETRACER_H_
#define ETISS_PLUGIN_DATAWRITETRACER_H_

#include "etiss/Plugin.h"
#include "etiss/IntegratedLibrary/SelectiveSysWrapper.h"

namespace etiss
{

namespace plugin
{

/*
 * This is a plugin implementation of the data write tracing. Currently,
 * data writes are directly traced in System.cpp, which is effective, but
 * intrusive. This implementation works as well, but demands significantly
 * more resources (main memory, execution time).
 *
 * To activate this implementation, add DataWriteTracer plugin to
 * IntegratedLibrary as any other plugin and remove the current
 * implementation from System.cpp. Note that in this case two
 * plugins must be activated at runtime for ETISS-GTS to work.
 *
 */

class DataWriteTracer : public etiss::plugin::SelectiveSysWrapper
{
public:
    struct CustomHandle
    {
        uint64_t addr = 0;
        uint64_t mask = 0;
        ETISS_System *origSys = nullptr;
    };

    DataWriteTracer(uint64_t addr_value, uint64_t addr_mask);

    ETISS_System getWrapInfo(ETISS_System *origSystem) final;

protected:
    inline virtual std::string _getPluginName() const { return std::string("DataWriteTracer"); }

private:
    CustomHandle customHandle_;
};

} // namespace plugin

} // namespace etiss

#endif
