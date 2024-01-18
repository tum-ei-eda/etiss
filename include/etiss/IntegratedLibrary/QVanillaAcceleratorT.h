#include "etiss/IntegratedLibrary/MemMappedPeriph.h"

#ifndef ETISS_PLUGIN_QVANILLAACCELERATORT_H
#define ETISS_PLUGIN_QVANILLAACCELERATORT_H

namespace etiss
{

namespace plugin
{

class QVanillaAcceleratorT: public etiss::plugin::MemMappedPeriph, public etiss::CoroutinePlugin
{
    public:

        QVanillaAcceleratorT(uint64_t addr=0x70002000) : regIf{}, base_addr{addr} { }

        void write32(uint64_t addr, uint32_t val);

        uint32 read32(uint64_t addr);

        MappedMemory getMappedMem() const {
            MappedMemory mm;
            mm.base = base_addr;
            mm.size = sizeof(RegIF);
            return mm;
        }

        etiss::int32 execute();

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
            uint32_t control;
            uint32_t status;
        } regs_t;

        union RegIF
        {
            regs_t regs;
            uint32_t arr[sizeof(regs_t)/sizeof(uint32_t)];
        };
        RegIF regIf;
        regs_t *p_regs = &regIf.regs;
        static const int64_t cycles_per_mac = 2; 
        etiss::uint64 target_cycles; 
        etiss::uint64 start_time_ = 0;
        bool myflag = false;
        int64_t count = 0;
        
    protected:
        uint64_t base_addr;
        std::string _getPluginName() const;

};

} // namespace plugin

} // namespace etiss

#endif