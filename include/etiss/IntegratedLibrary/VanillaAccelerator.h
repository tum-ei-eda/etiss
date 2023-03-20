#include "etiss/IntegratedLibrary/MemMappedPeriph.h"

#ifndef ETISS_PLUGIN_VANILLAACCELERATOR_H
#define ETISS_PLUGIN_VANILLAACCELERATOR_H

namespace etiss
{

namespace plugin
{

class VanillaAccelerator: public etiss::plugin::MemMappedPeriph
{
    public:
        void write32(uint64_t addr, uint32_t val);

        uint32_t read32(uint64_t addr);

        MappedMemory getMappedMem() const {
            MappedMemory mm;
            mm.base = 0x70000000;
            mm.size = 0x28;
            return mm;
        }

    private:
        struct RegIF
        {
            uint32_t ifmap;   
            uint32_t weights; 
            uint32_t result;  
            uint32_t oc;      
            uint32_t iw;      
            uint32_t ih;      
            uint32_t ic;      
            uint32_t kh;      
            uint32_t kw;  
            uint32_t control;
        };

        RegIF regIf;
        
    protected:
        std::string _getPluginName() const;

};

} // namespace plugin

} // namespace etiss

#endif