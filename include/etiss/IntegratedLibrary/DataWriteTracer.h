#ifndef ETISS_PLUGIN_DATAWRITETRACER_H_
#define ETISS_PLUGIN_DATAWRITETRACER_H_

#include "etiss/Plugin.h"
#include "etiss/IntegratedLibrary/SelectiveSysWrapper.h"

namespace etiss
{

namespace plugin
{

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
