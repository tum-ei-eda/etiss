/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/
#include "OR1KArch.h"
#include "OR1KTimer.h"
#include <iostream>
#include <sstream>

#include <ctime>
#include <limits>

#include "etiss/VirtualStruct.h"

using namespace etiss;

etiss::instr::InstructionClass OR32(0, "OR32", 32, ORBIS32_I, ORBIS32_II, ORFPX32);

etiss::instr::InstructionCollection Processor_OR1K("OR1K", OR32);

// hidden extension of cpu structure
struct OR1K_internal
{
    struct OR1K cpu;

    clock_t stopwatch_last;
};

// implement etiss library interface
extern "C"
{

    // implement version function
    ETISS_PLUGIN_EXPORT unsigned OR1KArch_etissversion() { return (ETISS_VERSION_MAJOR << 16) + (ETISS_VERSION_MINOR); }

    ETISS_PLUGIN_EXPORT unsigned OR1KArch_countCPUArch() { return 1; }
    ETISS_PLUGIN_EXPORT const char *OR1KArch_nameCPUArch(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "or1k";
        default:
            return 0;
        }
    }
    ETISS_PLUGIN_EXPORT etiss::CPUArch *OR1KArch_createCPUArch(unsigned index,
                                                               std::map<std::string, std::string> options)
    {

        OR1KArch *ret = new OR1KArch();

        Configuration cfg;
        cfg.config() = options;

        ret->ignore_sr_iee = cfg.get<bool>("arch.or1k.ignore_sr_iee", false);
        if (ret->ignore_sr_iee)
            etiss::log(etiss::INFO,
                       "An OR1K CPUArch instance has been configured to ignore the IEE flag of the SR register.");

        return ret;
    }

    ETISS_PLUGIN_EXPORT void OR1KArch_deleteCPUArch(etiss::CPUArch *o) { delete o; }

    /*      unsigned OR1KArch_countPlugin()
      {
          return 1;
      }
          ETISS_PLUGIN_EXPORT const char *  OR1KArch_namePlugin(unsigned index)
      {
          switch (index)
          {
          case 0:
              return "or1200::datasheettiming";
          default:
              return 0;
          }
      }
          ETISS_PLUGIN_EXPORT etiss::Plugin * OR1KArch_createPlugin(unsigned index, std::map<std::string, std::string>
      options)
      {

          Configuration cfg;
          cfg.config() = options;

          switch(index){
          case 0:
                          return getOR1200Timing(cfg);
                  default:
                          return 0;
          }

      }

          ETISS_PLUGIN_EXPORT void OR1KArch_deletePlugin(etiss::Plugin *o)
      {
          delete o;
      }
    */
    ETISS_PLUGIN_EXPORT void OR1K_printchar(char c) { std::cout << c; }
    ETISS_PLUGIN_EXPORT void OR1K_report(uint32_t c) { std::cout << "Reporting: " << c << std::endl; }
    ETISS_PLUGIN_EXPORT void OR1K_print(char *c) { std::cout << c; }
    ETISS_PLUGIN_EXPORT void OR1K_printtime(ETISS_CPU *cpu)
    {
        double time = 1000000000.0;
        time = cpu->cpuTime_ps / time;
        std::cout.precision(std::numeric_limits<double>::digits10);
        std::cout << "CPU time (ms): " << time << std::endl;
    }

    ETISS_PLUGIN_EXPORT etiss_uint32 OR1K_reset_stopwatch(ETISS_CPU *cpu)
    {
        OR1K_internal *c = (OR1K_internal *)cpu;
        clock_t cur = clock();
        clock_t ret = c->stopwatch_last;
        ret = ret * 1000000 / CLOCKS_PER_SEC;
        c->stopwatch_last = cur;
        return (etiss_uint32)ret;
    }
}

extern "C"
{

#define SPR_ID(group, index) (((group & 0x1F) << 11) | (index & 0x7FF))

    ETISS_PLUGIN_EXPORT etiss_uint32 OR1KArch_mfspr(OR1K *cpu, etiss_uint32 id)
    {

        // std::cout << "returning SPR[" << ((id>>11)&0x1F) << "][" << (id&0x07FF) << "]: "<<
        // cpu->SPR[(id>>11)&0x1F][id&0x07FF] << std::endl;
        return cpu->SPR[(id >> 11) & 0x1F][id & 0x07FF];
    }
    ETISS_PLUGIN_EXPORT void OR1KArch_mtspr(OR1K *cpu, etiss_uint32 id, etiss_uint32 value)
    {
        const char *ename = 0;
        switch ((id >> 11) & 0x1F)
        {
        case 0:
            switch (id & 0x07FF)
            {
            case 17: // SR
                if (!(cpu->SPR[0][17] & OR1K_SR_SM))
                { // prevent switching from user to supervisor mode
                    value = value & ~OR1K_SR_SM;
                }
                value |= OR1K_SR_FO; // ensure fixed bit
                break;
            }
            break;
        case 10: // timer
            switch (id & 0x07FF)
            {
            case 0:
                ename = "TTMR";
                // you cannot write to IP if it was 0 before.
                // It is allowed to write if it was 1 in order to clear the
                // interrupt.
                // Maybe we should allow it to be able to deboot from RTL.
                // if (!(cpu->SPR[10][0] & 0x10000000U))
                //{
                value = value & ~0x10000000U; // write 0 as it was before
                //}
                break;
            case 1:
                ename = "TTCR";
                break;
            }
            break;
        }
        cpu->SPR[(id >> 11) & 0x1F][id & 0x07FF] = value;
        if (ename)
            CPUArch::signalChangedRegisterValue((ETISS_CPU *)cpu, ename);
    }
}

OR1KArch::OR1KArch() : etiss::CPUArch("or32")
{

    reg32names.insert("PPC");
    reg32names.insert("NPC");
    reg32names.insert("SR");

    for (unsigned i = 0; i < 32; i++)
    {
        std::stringstream ss;
        ss << "R" << i;
        reg32names.insert(ss.str());
    }

    headers_.insert("Arch/OR1K/OR1K.h");
    headers_.insert("etiss/jit/fpu/softfloat.h");

    listenerSupportedRegisters_.insert("TTMR");
    listenerSupportedRegisters_.insert("TTCR");

    ignore_sr_iee = false;
}

ETISS_CPU *OR1KArch::newCPU()
{

    OR1K *ret = (OR1K *)new OR1K_internal(); // note: if the structure is instantiated exactly like this (and no changed
                                             // to the default constructor are made) then the struct is initialized to 0

    resetCPU((ETISS_CPU *)ret, 0);

    return (ETISS_CPU *)ret;
}

void OR1KArch::resetCPU(ETISS_CPU *uccpu, etiss::uint64 *startpointer)
{

    memset(uccpu, 0, sizeof(OR1K_internal));

    OR1K *cpu = ((OR1K *)uccpu);

    uccpu->cpuTime_ps = 0;
    uccpu->cpuCycleTime_ps = etiss::cfg(getLastAssignedCoreName())
                                 .get<uint32_t>("arch.cpu_cycle_time_ps", 10000); // original: 10000; // 100MHz

    cpu->R = cpu->GPR[0];

    cpu->SPR[0][17] = OR1K_SR_FO | OR1K_SR_SM;

    uccpu->mode = 0;

    cpu->VR = &(cpu->SPR[0][0]);
    cpu->UPR = &(cpu->SPR[0][1]);
    cpu->CPUCFGR = &(cpu->SPR[0][2]);
    cpu->DMMUCFGR = &(cpu->SPR[0][3]);
    cpu->IMMUCFGR = &(cpu->SPR[0][4]);
    cpu->DCCFGR = &(cpu->SPR[0][5]);
    cpu->ICCFGR = &(cpu->SPR[0][6]);
    cpu->DCFGR = &(cpu->SPR[0][7]);
    cpu->PCCFGR = &(cpu->SPR[0][8]);
    cpu->VR2 = &(cpu->SPR[0][9]);
    cpu->AVR = &(cpu->SPR[0][10]);
    cpu->EVBAR = &(cpu->SPR[0][11]);
    cpu->AECR = &(cpu->SPR[0][12]);
    cpu->AESR = &(cpu->SPR[0][13]);

    cpu->NPC = &(cpu->SPR[0][16]);
    cpu->SR = &(cpu->SPR[0][17]);
    cpu->PPC = &(cpu->SPR[0][18]);

    cpu->FPCSR = &(cpu->SPR[0][20]);
    cpu->ISR_8 = &(cpu->SPR[0][21]);

    cpu->EPCR_16 = &(cpu->SPR[0][32]);

    cpu->EEAR_16 = &(cpu->SPR[0][48]);

    cpu->ESR_16 = &(cpu->SPR[0][64]);

    cpu->GPR_512 = &(cpu->SPR[0][1024]);

    cpu->MACLO = &(cpu->SPR[5][1]);
    cpu->MACHI = &(cpu->SPR[5][2]);

    cpu->TTMR = &(cpu->SPR[10][0]);
    cpu->TTCR = &(cpu->SPR[10][1]);

    cpu->FPMADDHI = &(cpu->SPR[11][0]); //! index officially not defined as 0
    cpu->FPMADDLO = &(cpu->SPR[11][1]); //! index officially not defined as 1

    // init PC
    cpu->PC = &(uccpu->instructionPointer);

    uccpu->instructionPointer = 0x00000100;

    if (startpointer)
        uccpu->instructionPointer = *startpointer;

    cpu->SPR[0][18] = (etiss_uint32)(uccpu->instructionPointer);
    cpu->SPR[0][16] = (etiss_uint32)(uccpu->instructionPointer);
}

void OR1KArch::deleteCPU(ETISS_CPU *cpu)
{
    delete cpu;
}

void OR1KArch::deleteVirtualStruct(etiss::VirtualStruct *stru)
{
    delete stru;
}

const std::set<std::string> &OR1KArch::getListenerSupportedRegisters()
{
    return listenerSupportedRegisters_;
}

etiss::Plugin *OR1KArch::newTimer(ETISS_CPU *cpu)
{
    return new OR1KTimer();
}
void OR1KArch::deleteTimer(etiss::Plugin *timer)
{
    delete timer;
}

unsigned OR1KArch::getMaximumInstructionSizeInBytes()
{
    return 8; // due to delay slot
}
unsigned OR1KArch::getInstructionSizeInBytes()
{
    return 4;
}

void OR1KArch::initInstrSet(etiss::instr::ModedInstructionSet &mis) const
{

    bool ok = true;

    Processor_OR1K.addTo(mis, ok);

    if (!ok)
    {
        etiss_log(ERROR, "Failed to add instructions of the OR1K instruction set");
    }

    mis.foreach(
        [](etiss::instr::VariableInstructionSet &vis) {
            vis.foreach(
                [](etiss::instr::InstructionSet &is) {
                    is.getInvalid().addCallback(
                        [](etiss::instr::BitArray &ba, CodeSet &cs, etiss::instr::InstructionContext &ic) {
                            etiss_uint32 error_code = 0;
                            static etiss::instr::BitArrayRange R_error_code_0(31, 0);
                            error_code += R_error_code_0.read(ba) << 0;

                            std::stringstream ss;
                            ss << "\t\t//trap_entry 32\n";
                            ss << "\t\treturn " << std::to_string(error_code) << "U;";
                            //#if DEBUG
                            ss << " // @0x" << std::hex << ic.current_address_ << std::dec << ": " << ba;
                            //#endif
                            ss << "\n";
                            cs.append(CodePart::APPENDEDRETURNINGREQUIRED).code() = ss.str();
                            return true;
                        },
                        0);
                }
            );
        }
    );
}

void OR1KArch::initCodeBlock(etiss::CodeBlock &cb) const
{

    cb.fileglobalCode().insert("#include \"Arch/OR1K/OR1K.h\"\n");
    cb.fileglobalCode().insert("#include \"etiss/jit/fpu/softfloat.h\"\n");
}

const std::set<std::string> &OR1KArch::getHeaders() const
{
    return headers_;
}
etiss::int32 OR1KArch::handleException(etiss::int32 code, ETISS_CPU *cpu)
{

    // handle global known exceptions
    switch (code)
    {
    case RETURNCODE::RESET:
        cpu->instructionPointer = 0x100 + (*((OR1K *)cpu)->EVBAR >> 12);
        return RETURNCODE::NOERROR;
    }

    // translate exception
    if (code < 0) // ETISS return codes are negative
    {
        switch (code)
        {
        case RETURNCODE::DBUS_READ_ERROR:
        case RETURNCODE::DBUS_WRITE_ERROR:
        case RETURNCODE::IBUS_READ_ERROR:
        case RETURNCODE::IBUS_WRITE_ERROR:
            code = OR1K_BUSEXCEPTION;
            break;
        case RETURNCODE::INTERRUPT:
            code = OR1K_EXTERNALINTERRUPTEXCEPTION;
            break;
        case RETURNCODE::ILLEGALINSTRUCTION:
            code = OR1K_ILLEGALINSTRUCTIONEXCEPTION;
            etiss::log(etiss::INFO, "OR1K received illegal instruction!");
            break;
        case RETURNCODE::ILLEGALJUMP:
            *((OR1K *)cpu)->PC = (*((OR1K *)cpu)->PC) & ~(uint32_t)3;
            etiss::log(etiss::WARNING, "OR1K received illegal jump! Trying to ignore the lowest 2 PC bits!");
            return RETURNCODE::NOERROR;
        default:
            return code;
        }
    }
    // filter unknown
    // uint16 arg = code&0x0000FFFF; currently not used [-Werror=unused-variable]

    // code>>16 translate OR1K exception code to jump address
    // EVBAR is the exception vector base address register which contains an offset to the exception vector
    uint32 vec = ((code >> 16) & 0x0000FFFF) + (*((OR1K *)cpu)->EVBAR >> 12); // TODO: should be shifted by 13?

    /* Here only the following exceptions are performed:
       0x100 Reset,
       0x200 Bus Error,
       0x300 Data Page Fault,
       0x400 Instruction Page Fault,
       0x500 Tick Timer,
       0x600 Alignment,
       0x700 Illegal Instruction,
       0x800 External Interrupt,
       0x900 D-TLB Miss,
       0xA00 I-TLB Miss,
       0xB00 Range,
       0xC00 System Call,
       0xD00 Floating Point,
       0xE00 Trap
       All others will be return to ETISS*/
    if (((vec) >= 0x0F00) || ((vec & 0x0000FF00) != vec)) // TODO: shouldn't EVBAR be added after this?
    {
        std::cout << "Exception code returned: " << std::hex << code << std::dec << std::endl;
        return code;
    }

    if (((OR1K *)cpu)->exceptionDepth != 0)
    {
        // std::cout << "OR1K exception ignored: " << std::hex << vec << std::dec << " time_ps: " <<  (cpu->cpuTime_ps)
        // << std::endl; return RETURNCODE::NOERROR;
    }
    else
    {
        // std::cout << "OR1K exception occured: " << std::hex << vec << std::dec << " time_ps: " <<  (cpu->cpuTime_ps)
        // << std::endl;
    }

    // check if exception should be ignored
    switch (vec)
    {
    case 0x0500: // timer
        if (!ignore_sr_iee)
            if (!((*((OR1K *)cpu)->SR) & OR1K_SR_TEE))
                return RETURNCODE::NOERROR;
        break;
    case 0x0800: // interrupt
        // cpu->instructionPointer = vec;
        if (!((*((OR1K *)cpu)->SR) & OR1K_SR_IEE))
            return RETURNCODE::NOERROR;
        break;
    }

    if (*((OR1K *)cpu)->SR & OR1K_SR_EPH) // check for high exception vector starting at address 0xF0000000
        vec = vec | 0xF0000000;

    ((OR1K *)cpu)->exceptionDepth++;

    // trigger exception

    // store pc/sr
    ((OR1K *)cpu)->EPCR_16[0] = ((etiss::uint32) * ((OR1K *)cpu)->PC);
    ((OR1K *)cpu)->ESR_16[0] = *((OR1K *)cpu)->SR;
    // update sr
    uint32 flags = OR1K_SR_DME | OR1K_SR_IME | OR1K_SR_IEE | OR1K_SR_TEE;
    *((OR1K *)cpu)->SR = ((*((OR1K *)cpu)->SR) & (~flags)) | OR1K_SR_SM;
    // update pc
    *((OR1K *)cpu)->PC = (vec);

    return RETURNCODE::NOERROR;
}

etiss::InterruptVector *OR1KArch::createInterruptVector(ETISS_CPU *cpu)
{
    if (cpu == 0)
        return 0;
    std::vector<etiss::uint32 *> vec;
    vec.push_back(&(((OR1K *)cpu)->SPR[9][2]));
    std::vector<etiss::uint32 *> mask;
    mask.push_back(&(((OR1K *)cpu)->SPR[9][0]));
    return new MappedInterruptVector<etiss::uint32>(vec, mask);
}
void OR1KArch::deleteInterruptVector(etiss::InterruptVector *vec, ETISS_CPU *cpu)
{
    delete vec;
}
etiss::plugin::gdb::GDBCore &OR1KArch::getGDBCore()
{
    return gdbcore_;
}

static std::string getName(uint16_t sprid)
{
    std::stringstream ss;
    ss << "SPR[" << (sprid >> 11) << "][" << (sprid & 0x7FF) << "]";
    return ss.str();
}
static std::string getPrettyName(uint16_t sprid)
{

    static bool initialized = false;
    static std::map<uint16_t, std::string> pname_;
    if (!initialized)
    {
        initialized = true;

        pname_[(0 << 11) | 17] = "SR";
        pname_[(10 << 11) | 0] = "TTMR";
        pname_[(10 << 11) | 1] = "TTCR";
    }

    auto find = pname_.find(sprid);
    if (find == pname_.end())
        return "";
    return find->second;
}

static bool supportsListener(uint16_t sprid)
{

    if (sprid == ((10 << 11) | 0)) // ttmr
        return true;

    if (sprid == ((10 << 11) | 1)) // ttcr
        return true;

    return false; /// TODO add fields before this that are supported by OR1KArch_mtspr();
}

static int getSPRFlags(uint16_t sprid)
{

    int ret = etiss::VirtualStruct::Field::R | etiss::VirtualStruct::Field::W;

    if (supportsListener(sprid))
        ret |= etiss::VirtualStruct::Field::L;

    return ret;
}

namespace
{

/**
        simple field implementation. note: must use OR1KArch_mtspr instead of direct write access
*/
class SPRField : public etiss::VirtualStruct::Field
{
  private:
    const unsigned group_;
    const unsigned index_;
    const unsigned sprid_;

  public:
    SPRField(etiss::VirtualStruct &parent, uint16_t sprid)
        : Field(parent, getName(sprid), getPrettyName(sprid), getSPRFlags(sprid) | F, 4)
        , group_(sprid >> 11)
        , index_(sprid & 0x7FF)
        , sprid_(sprid)
    {
    }
    virtual ~SPRField() {}

  protected:
    virtual uint64_t _read() const { return (uint64_t)((OR1K *)parent_.structure_)->SPR[group_][index_]; }
    virtual void _write(uint64_t val)
    {
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        OR1KArch_mtspr((OR1K *)parent_.structure_, sprid_, (uint32_t)val);
    }
};

class GPRField : public etiss::VirtualStruct::Field
{
  private:
    const unsigned gprid_;

  public:
    GPRField(etiss::VirtualStruct &parent, unsigned gprid)
        : Field(parent, std::string("R") + etiss::toString(gprid), std::string("R") + etiss::toString(gprid), R | W | F,
                4)
        , gprid_(gprid)
    {
    }
    virtual ~GPRField() {}

  protected:
    virtual uint64_t _read() const { return (uint64_t)((OR1K *)parent_.structure_)->R[gprid_]; }
    virtual void _write(uint64_t val)
    {
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        ((OR1K *)parent_.structure_)->R[gprid_] = (uint32_t)val;
    }
};

} // namespace

class PPCField : public etiss::VirtualStruct::Field
{
  public:
    PPCField(etiss::VirtualStruct &parent) : Field(parent, std::string("PPC"), std::string("PPC"), R | W | F, 4) {}
    virtual ~PPCField() {}

  protected:
    virtual uint64_t _read() const { return (uint64_t) * (((OR1K *)parent_.structure_)->PPC); }
    virtual void _write(uint64_t val)
    {
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *(((OR1K *)parent_.structure_)->PPC) = (uint32_t)val;
    }
};

class NPCField : public etiss::VirtualStruct::Field
{
  public:
    NPCField(etiss::VirtualStruct &parent) : Field(parent, std::string("NPC"), std::string("NPC"), R | W | F, 4) {}
    virtual ~NPCField() {}

  protected:
    virtual uint64_t _read() const { return (uint64_t) * (((OR1K *)parent_.structure_)->NPC); }
    virtual void _write(uint64_t val)
    {
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *(((OR1K *)parent_.structure_)->NPC) = (uint32_t)val;
    }
};

class SRField : public etiss::VirtualStruct::Field
{
  public:
    SRField(etiss::VirtualStruct &parent) : Field(parent, std::string("SR"), std::string("SR_"), R | W | F, 4) {}
    virtual ~SRField() {}

  protected:
    virtual uint64_t _read() const { return (uint64_t) * (((OR1K *)parent_.structure_)->SR); }
    virtual void _write(uint64_t val)
    {
        etiss::log(etiss::VERBOSE, "write to ETISS cpu state", name_, val);
        *(((OR1K *)parent_.structure_)->SR) = (uint32_t)val;
    }
};

std::shared_ptr<etiss::VirtualStruct> OR1KArch::getVirtualStruct(ETISS_CPU *cpu)
{
    auto ret = etiss::VirtualStruct::allocate(cpu, [](VirtualStruct::Field *f) {
        // delete f;
    });

    for (uint32_t i = 0; i < (1 << 16); ++i)
    {

        ret->addField(new SPRField(*ret, (uint16_t)i));
    }

    for (unsigned i = 0; i < 32; ++i)
    {

        ret->addField(new GPRField(*ret, i));
    }

    ret->addField(new PPCField(*ret));
    ret->addField(new SRField(*ret));
    ret->addField(new NPCField(*ret));

    return ret;
}
