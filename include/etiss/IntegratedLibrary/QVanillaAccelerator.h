#include "etiss/IntegratedLibrary/MemMappedPeriph.h"

#ifndef ETISS_PLUGIN_QVANILLAACCELERATOR_H
#define ETISS_PLUGIN_QVANILLAACCELERATOR_H

namespace etiss
{

namespace plugin
{

class QVanillaAccelerator: public etiss::plugin::MemMappedPeriph
{
    public:
        void write32(uint64_t addr, int32_t val);

        int32_t read32(uint64_t addr);

        MappedMemory getMappedMem() const {
            MappedMemory mm;
            mm.base = 0x70000000;
            mm.size = 0x34;
            return mm;
        }

    private:
        struct RegIF
        {
            uint32_t ifmap;   
            uint32_t weights;
            uint32_t bias; 
            uint32_t result;  
            int32_t oc;      
            int32_t iw;      
            int32_t ih;      
            int32_t ic;      
            int32_t kh;      
            int32_t kw; 
            int32_t i_zp;
            int32_t k_zp;
            int32_t control;
        };

        RegIF regIf;
        
    protected:
        std::string _getPluginName() const;

};

} // namespace plugin

} // namespace etiss

#endif