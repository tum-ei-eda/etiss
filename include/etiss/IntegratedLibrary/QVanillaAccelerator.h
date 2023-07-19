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

        QVanillaAccelerator(uint64_t addr=0x70000000) : regIf{}, base_addr{addr} { }

        void write32(uint64_t addr, uint32_t val);

        uint32 read32(uint64_t addr);

        MappedMemory getMappedMem() const {
            MappedMemory mm;
            mm.base = base_addr;
            mm.size = sizeof(RegIF);
            return mm;
        }

    private:

        typedef struct regs 
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
        } regs_t;

        union RegIF
        {
            regs_t regs;
            uint32_t arr[sizeof(regs_t)/sizeof(uint32_t)];
        };
        RegIF regIf;
        
    protected:
        uint64_t base_addr;
        std::string _getPluginName() const;

};

} // namespace plugin

} // namespace etiss

#endif