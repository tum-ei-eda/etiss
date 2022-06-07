/**
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
        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM
        @date July 29, 2014
        @version 0.1
*/
/**
        @file
        @brief implementation of etiss/CPUCore.h
        @detail
*/
#include "etiss/CPUCore.h"
#include "etiss/ETISS.h"

using namespace etiss;

/**
        @see etiss/CPUArch.h
*/
void CPUArchRegListenerInterface::signalChangedRegisterValue(ETISS_CPU *cpu, const char *registerName)
{
    CPUCore *core = (CPUCore *)cpu->_etiss_private_handle_;
    if (!core)
    {
        etiss::log(
            etiss::ERROR,
            "CPUArchRegListenerInterface::signalChangedRegisterValue() called from outside etiss::CPUCore::execute(). "
            "this should not happen and indicates a faultiy CPUArch (or Plugin) implementation. This function may have "
            "been called indirectly from ETISS_signalChangedRegisterValue()");
        return;
    }
    auto vs = core->getStruct();
    if (!vs)
    {
        etiss::log(etiss::ERROR, "CPUArchRegListenerInterface::signalChangedRegisterValue() called but CPUArch didn't "
                                 "provide a VirtualStruct.");
        return;
    }
    auto field = vs->findName(registerName);
    if (!field)
    {
        field = vs->findPrettyName(registerName);
        if (!field)
        {
            etiss::log(etiss::ERROR,
                       "CPUArchRegListenerInterface::signalChangedRegisterValue() called but the associated "
                       "VirtualStruct has not the specified field.",
                       registerName);
            return;
        }
    }
    if (!(field->flags_ & etiss::VirtualStruct::Field::L))
    {
        etiss::log(etiss::ERROR,
                   "CPUArchRegListenerInterface::signalChangedRegisterValue() called but the field of the associated "
                   "VirtualStruct doesn't have the listerner flags set (etiss::VirtualStruct::Field::L).",
                   registerName);
        return;
    }

    field->signalWrite();
}

CPUCore::InterruptVectorWrapper::InterruptVectorWrapper(CPUCore &parent) : parent_(parent) {}
void CPUCore::InterruptVectorWrapper::setBit(unsigned bit, bool state)
{
    bool consumed = false;
    // std::cout << "CPUCore::InterruptVectorWrapper::setBit called " << state << " " << bit << std::endl;
    // iterate through the plugins which have been registered at the cpu
    for (auto iter : parent_.plugins)
    {
        etiss::InterruptListenerPlugin *ilp = iter->getInterruptListenerPlugin();
        if (ilp)
            consumed |= ilp->interruptWrite(bit, state);
    }
    if (!consumed)
    {
        consumed_by_interruptlistener_ = false;
        // std::cout << "CPUCore::InterruptVectorWrapper::setBit NOT consumed by InterruptListenerPlugin" << std::endl;
        parent_.intvector_->setBit(bit, state);
    }
    else
    {
        consumed_by_interruptlistener_ = true;
        // std::cout << "CPUCore::InterruptVectorWrapper::setBit consumed by InterruptListenerPlugin" << std::endl;
    }
}
bool CPUCore::InterruptVectorWrapper::getBit(unsigned bit) const
{
    return parent_.intvector_->getBit(bit);
}
unsigned CPUCore::InterruptVectorWrapper::width() const
{
    return parent_.intvector_->width();
}
bool CPUCore::InterruptVectorWrapper::isActive() const
{
    return parent_.intvector_->isActive();
}
void CPUCore::InterruptVectorWrapper::clear()
{
    for (unsigned i = 0; i < width(); i++)
    {
        setBit(i, false);
    }
}

std::mutex CPUCore::instances_mu_;
std::list<std::weak_ptr<CPUCore>> CPUCore::instances_;

int currID = 0;
int CPUCore::getNextID()
{
    return currID;
}
CPUCore::CPUCore(std::shared_ptr<etiss::CPUArch> arch)
    : arch_(arch)
    , name_("core" + std::to_string(currID))
    , id_(currID++)
    , cpu_(arch->newCPU())
    , vcpu_(arch->getVirtualStruct(cpu_))
    , intvector_(arch->createInterruptVector(cpu_))
    , mmu_enabled_(false)
{
    arch_->resetCPU(cpu_, 0);
    timer_enabled_ = true;
    bcc_ = 1;
    exception_skip_count_ = 0;
    blockCacheLimit_ = -1;
    intwrapper_ = intvector_ ? new InterruptVectorWrapper(*this) : 0;
    blockCounter = 0;
#if ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER
    instrcounter = 0;
#endif

    if (cpu_)
    {
        if (vcpu_)
        {
            if (!vcpu_->findName("instructionPointer"))
            {
                ETISS_CPU *cpu = cpu_;
                vcpu_->addField((new etiss::VirtualStruct::Field(
                                     *vcpu_, "instructionPointer", "",
                                     etiss::VirtualStruct::Field::R | etiss::VirtualStruct::Field::P, 8, false,
                                     [cpu]() { return (uint64_t)cpu->instructionPointer; }, nullptr))
                                    ->setDeleteP(std::function<void(etiss::VirtualStruct::Field *)>(
                                        [](etiss::VirtualStruct::Field *f) { delete f; })));
            }
#if ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER
            if (!vcpu_->findName("instructionCounter"))
            {
                vcpu_->addField((new etiss::VirtualStruct::Field(
                                     *vcpu_, "instructionCounter", "",
                                     etiss::VirtualStruct::Field::R | etiss::VirtualStruct::Field::W |
                                         etiss::VirtualStruct::Field::P,
                                     8, false, [this]() { return (uint64_t)instrcounter; },
                                     [this](uint64_t v) { instrcounter = v; }))
                                    ->setDeleteP(std::function<void(etiss::VirtualStruct::Field *)>(
                                        [](etiss::VirtualStruct::Field *f) { delete f; })));
            }
#endif
        }
    }
}

void CPUCore::addPlugin(std::shared_ptr<etiss::Plugin> plugin)
{
    if (plugin.get() != 0)
    {
        {
            std::lock_guard<std::mutex> lock(mu_);
            // check if the plugin is already present
            for (const std::shared_ptr<etiss::Plugin> &p : plugins)
            {
                if (p.get() == plugin.get())
                {
                    etiss::log(etiss::WARNING, "cannot add the same plugin multiple times", *this, *(plugin.get()));
                    return;
                }
            }
            if (plugin->plugin_core_)
            {
                etiss::log(etiss::WARNING, "A plugin has been added to multiple cores. This could be a serve problem.",
                           *this, *(plugin.get()));
            }
            plugins.push_back(plugin);
        }
        plugin->plugin_core_ = this;
        plugin->setCorrespondingCPUCoreName(this->getName());
        plugin->addedToCPUCore(this);
    }
    else
    {
        etiss::log(etiss::WARNING, "etiss::CPUCore::addPlugin() called without passing a valid plugin pointer.", *this);
    }
}

void CPUCore::removePlugin(std::shared_ptr<etiss::Plugin> plugin)
{
    etiss::Plugin *p = plugin.get();
    bool removed = false;
    {
        std::lock_guard<std::mutex> lock(mu_);
        for (auto iter = plugins.begin(); iter != plugins.end();)
        {
            if (iter->get() == plugin.get())
            {
                plugins.erase(iter++);
                removed = true;
                break;
            }
            else
            {
                iter++;
            }
        }
    }
    if (removed)
    {
        p->plugin_core_ = nullptr;
        p->removedFromCPUCore(this);
    }
}

std::shared_ptr<CPUCore> CPUCore::create(std::string archname, std::string instancename,
                                         std::map<std::string, std::string> archoptions)
{

    etiss::forceInitialization();

    // get arch -> constructs arch with used arch library
    std::shared_ptr<etiss::CPUArch> arch = getCPUArch(archname, archoptions);

    if (arch.get() == 0)
    {
        etiss::log(etiss::FATALERROR, "Architecture not found.", archname);
        return 0;
    }

    // creat core
    std::shared_ptr<CPUCore> ret(new CPUCore(arch));

    {
        std::lock_guard<std::mutex> lock(instances_mu_);
        instances_.emplace_back(ret);
    }

    return ret;
}

std::list<std::string> CPUCore::list()
{
    std::list<std::string> ret;
    {
        std::lock_guard<std::mutex> lock(instances_mu_);
        for (auto iter = instances_.begin(); iter != instances_.end(); iter++)
        {
            auto ptr = iter->lock();
            if (ptr.get() != 0)
            {
                ret.push_back(ptr->getName() + " [" + ptr->getArch()->getArchName() + "," + ptr->getJITName() +
                              "]"); // "CORENAME [ARCHITECTURE,JIT]
            }
        }
    }
    return ret;
}

CPUCore::~CPUCore()
{
    arch_->deleteInterruptVector(intvector_, cpu_);
    if (vcpu_)
    {
        vcpu_->close();
        vcpu_.reset();
    }
    arch_->deleteCPU(cpu_);
    delete intwrapper_;
}

/**
        generates and compiles test code for the just in time compiler to check size of basic types
*/
static bool verifyJITSizeOf(std::string structname, etiss::int32 expected_size, etiss::JIT *jit,
                            std::string prefix = std::string())
{
    if (jit == 0)
        return false;
    // generate code
    std::string error;
    std::string code = std::string(prefix + "\n#include \"etiss/jit/CPU.h\"\n#include "
                                            "\"etiss/jit/System.h\"\n#include \"etiss/jit/ReturnCode.h\"\n "
                                            "#include \"etiss/jit/types.h\"\n#include "
                                            "\"etiss/jit/fpu/softfloat.h\"\n etiss_int32 get_size(){ return "
                                            "sizeof(") +
                       structname + ");}";

    std::set<std::string> headers;
    headers.insert(etiss::jitFiles());
    // compile
    void *handle = jit->translate(code, headers, std::set<std::string>(), std::set<std::string>(), error, true);
    if (handle == 0)
    {
        etiss::log(etiss::ERROR,
                   std::string("Failed to compile test code [") + code + "] to check struct size: " + error);
        return false;
    }
    // check size
    typedef etiss::int32 (*get_size)(void);
    get_size gs = (get_size)jit->getFunction(handle, "get_size", error);
    if (gs == 0)
    {
        jit->free(handle);
        etiss::log(etiss::ERROR,
                   std::string("Failed to get compiled function [get_size] to check struct size: ") + error);
        return false;
    }
    etiss::int32 r = gs();
    jit->free(handle);
    if (r != expected_size)
    {
        std::stringstream ss;
        ss << "Unexpected size of " << structname << ";";
        ss << " Expected: " << expected_size;
        ss << " Is: " << r;
        etiss::log(etiss::ERROR, ss.str());
        return false;
    }
    return true;
}
/**
        generates test code to check alignment of structures in the just in time compiler
*/
static bool verifyJITPragmaPack(etiss::JIT *jit)
{
    if (jit == 0)
        return false;
    std::string error;
    std::stringstream stru;
    etiss::int32 expected_size = 0;

    // add some types to test
    std::vector<const char *> types;
    std::vector<etiss::int32> typeslen;
    types.push_back("etiss_int8");
    typeslen.push_back(sizeof(etiss_int8));
    types.push_back("etiss_uint8");
    typeslen.push_back(sizeof(etiss_uint8));
    types.push_back("etiss_int16");
    typeslen.push_back(sizeof(etiss_int16));
    types.push_back("etiss_uint16");
    typeslen.push_back(sizeof(etiss_uint16));
    types.push_back("etiss_int32");
    typeslen.push_back(sizeof(etiss_int32));
    types.push_back("etiss_uint32");
    typeslen.push_back(sizeof(etiss_uint32));
    types.push_back("etiss_int64");
    typeslen.push_back(sizeof(etiss_int64));
    types.push_back("etiss_uint64");
    typeslen.push_back(sizeof(etiss_uint64));
    types.push_back("void*");
    typeslen.push_back(sizeof(void *));

    stru << "struct _etiss_test_struct {\n";
    // add eacht type followed by any other type to create different combinations
    for (size_t i = 0; i < types.size(); i++)
    {
        stru << types[i] << " var_" << i << ";\n";
        expected_size += typeslen[i];
        for (size_t j = 0; j < types.size(); j++)
        {
            if (j != i)
            {
                stru << types[j] << " var_" << i << "_" << j << ";\n";
                expected_size += typeslen[j];
            }
        }
    }

    stru << "};";

    std::string code = std::string("\n#include \"etiss/jit/types.h\"\n#pragma pack(push, 1)\n") + stru.str() +
                       "\n#pragma pack(pop)\n etiss_int32 get_size(){ return sizeof(struct "
                       "_etiss_test_struct);}";

    std::set<std::string> headers;
    headers.insert(etiss::jitFiles());
    // compile
    void *handle = jit->translate(code, headers, std::set<std::string>(), std::set<std::string>(), error, true);
    if (handle == 0)
    {
        etiss::log(etiss::ERROR,
                   std::string("Failed to compile test code [") + code + "] to check struct size: " + error);
        return false;
    }
    typedef etiss::int32 (*get_size)(void);
    // check size
    get_size gs = (get_size)jit->getFunction(handle, "get_size", error);
    if (gs == 0)
    {
        jit->free(handle);
        etiss::log(etiss::ERROR,
                   std::string("Failed to get compiled function [get_size] to check struct size: ") + error);
        return false;
    }
    etiss::int32 r = gs();
    jit->free(handle);
    if (r != expected_size)
    {
        std::stringstream ss;
        ss << "Unexpected size of test structure;";
        ss << " Expected: " << expected_size;
        ss << " Is: " << r;
        etiss::log(etiss::ERROR, ss.str());
        return false;
    }
    return true;
}

/**
        small helper function to handle exceptions. in most cases the exception is simply passed on to
   etiss::CPUArch::handleExcpetion()
*/
static void etiss_CPUCore_handleException(ETISS_CPU *cpu, etiss::int32 &code, BlockLink *&block_ptr,
                                          Translation &translator, CPUArch *arch)
{

#if DEBUG
    if (unlikely(code == RETURNCODE::NOERROR))
    {
        etiss::log(etiss::ERROR, "etiss_CPUCore_handleException may not be called with error code NOERROR");
    }
#endif

    switch (code)
    {
    case RETURNCODE::RELOADBLOCKS:
        block_ptr = 0; // doesn't hold a reference and thus might become invalid
        translator.unloadBlocks();
        code = RETURNCODE::NOERROR;
        return;
    case RETURNCODE::RELOADCURRENTBLOCK:
        if (block_ptr)
            block_ptr->valid = false; // invalidate but don't delete block
        block_ptr = 0;
        code = RETURNCODE::NOERROR;
        return;
    case RETURNCODE::GDBNOERROR:
        code = RETURNCODE::NOERROR;
        return;
    case RETURNCODE::CPUFINISHED:
        return;
    default:
        code = arch->handleException(code, cpu);
        return;
    }
}

class LegacyRegisterDevicePluginListener : public etiss::VirtualStruct::Field::Listener
{
  public:
    std::list<etiss::RegisterDevicePlugin *> plugins;
    LegacyRegisterDevicePluginListener(const std::list<etiss::RegisterDevicePlugin *> &plugins_) : plugins(plugins_) {}
    virtual ~LegacyRegisterDevicePluginListener() {}
    virtual void write(etiss::VirtualStruct::Field &field, uint64_t val)
    {
        std::string name = field.name_;
        const char *cname = name.c_str();
        for (auto plugin : plugins)
        {
            if (plugin)
            {
                plugin->changedRegister(cname);
            }
        }
    }
};

etiss::int32 CPUCore::execute(ETISS_System &_system)
{
    ETISS_System *system = &_system; // change to pointer for reassignments

    if (!ETISS_System_isvalid(system))
    { // check if required functions are present
        return RETURNCODE::INVALIDSYSTEM;
    }

    std::lock_guard<std::mutex> lock(mu_); // lock class fields from modification

    if (!arch_)
    {
        etiss::log(etiss::ERROR, "Could not find architecture!");
        return RETURNCODE::GENERALERROR;
    }

    if (!cpu_)
    {
        etiss::log(etiss::ERROR, "Could not find CPU struct!");
        return RETURNCODE::GENERALERROR;
    }

    cpu_->_etiss_private_handle_ =
        (void *)this; // init pointer to execute RegisterDevicePlugins. the value of tis pointer may be invalid/subject
                      // to change and may not be used by external code

    // get JIT instance
    std::shared_ptr<JIT> jiti = jit_; // copy jit because it may change
    if (!jiti)
    {
        etiss::log(etiss::ERROR, std::string("No JIT available to ") + name_);
        return RETURNCODE::JITERROR;
    }


    // verify jit
    if (etiss::cfg().get<bool>("jit.verify", true))
    {
        if (!verifyJITSizeOf("etiss_int64", sizeof(etiss_int64), jiti.get()))
            return RETURNCODE::JITCOMPILATIONERROR;
        if (!verifyJITSizeOf("etiss_int32", sizeof(etiss_int32), jiti.get()))
            return RETURNCODE::JITCOMPILATIONERROR;
        if (!verifyJITSizeOf("etiss_int16", sizeof(etiss_int16), jiti.get()))
            return RETURNCODE::JITCOMPILATIONERROR;
        if (!verifyJITSizeOf("etiss_int8", sizeof(etiss_int8), jiti.get()))
            return RETURNCODE::JITCOMPILATIONERROR;
        if (!verifyJITSizeOf("ETISS_CPU", sizeof(ETISS_CPU), jiti.get()))
            return RETURNCODE::JITCOMPILATIONERROR;
        if (!verifyJITPragmaPack(jiti.get()))
            return RETURNCODE::JITCOMPILATIONERROR;
        etiss::log(etiss::INFO, std::string("JIT compiler ") + jiti->getName() +
                                    " has passed the verification tests (tested by CPUCore " + name_ + ")");
    }
    // add default timer plugin from arch
    if (timer_enabled_)
    {
        Plugin *timerInstance = arch_->newTimer(cpu_);
        if (!timerInstance)
        {
            etiss::log(etiss::ERROR, "ERROR: default timer requested but not supported by architecture");
            return RETURNCODE::GENERALERROR;
        }
        else
        {
            etiss::log(etiss::INFO, "Add Timer Plugin: " + timerInstance->getPluginName());
            auto local_arch = arch_;
            plugins.push_back(std::shared_ptr<etiss::Plugin>(timerInstance, [local_arch](etiss::Plugin *p) {
                etiss::log(etiss::INFO, "Delete Timer Plugin.");
                local_arch->deleteTimer(p);
            }));
        }
    }

    // add MMU module from the arch
    {
        etiss::mm::MMU *new_mmu = arch_->newMMU(cpu_);
        if (new_mmu)
        {
            mmu_enabled_ = true;
            mmu_.reset(new_mmu);
            etiss::log(etiss::INFO, "Add MMU module: " + mmu_->GetName());
        }
    }

    if (mmu_enabled_)
    {
        plugins.push_back(std::make_shared<etiss::mm::DMMUWrapper>(mmu_));
    }

    // copy system wrapper plugins to list and update system (pre plugin init)
    std::list<SystemWrapperPlugin *> syswrappers;
    for (auto &plugin : plugins)
    {
        auto c = plugin->getSystemWrapperPlugin();
        if (c)
        {
            ETISS_System *wsys = c->wrap(cpu_, system);
            if (wsys)
            {
                syswrappers.push_front(c); // inverse order for easy iteration
                system = wsys;
            }
            else
            {
                std::stringstream stream;
                stream << "SystemWrapperPlugin \"" << c->getPluginName() << "\" failed to wrap ETISS_System instance";
                etiss::log(etiss::WARNING, stream.str());
            }
        }
    }

    // initialize plugins
    for (auto &p : plugins)
    {
        if (!p)
            etiss::log(etiss::FATALERROR, "Empty plugin");

        p->plugin_cpu_ = cpu_;
        p->plugin_system_ = system;
        p->plugin_arch_ = arch_.get();
        p->init(cpu_, system, arch_.get());

        std::stringstream m;
        m << "Init Plugin " << p->getPluginName();
        etiss::log(etiss::INFO, m.str());
    }

    // copy coroutine plugins to array
    std::vector<CoroutinePlugin *> cor_array;
    for (const auto &plugin : plugins)
    {
        auto c = plugin->getCoroutinePlugin();
        if (c)
            cor_array.push_back(c);
    }

    // create translation object
    Translation translation(arch_, jiti, plugins, *system, *cpu_);

    // Translation init returns a list of pluigins, at position 0 this is the arch plugin followed by all translation
    // plugins
    void **plugins_handle_ = translation.init();
    if (!plugins_handle_)
    {
        etiss::log(etiss::FATALERROR, "Failed to initialize translation");
    }

    // enable RegisterDevicePlugin listeneing by adding a listener to all fields of the VirtualStruct
    etiss::VirtualStruct::Field::Listener *listener = 0;
    {
        std::list<RegisterDevicePlugin *> regdevices;
        for (auto &plugin : plugins)
        {
            auto rdp = plugin->getRegisterDevicePlugin();
            if (rdp)
                regdevices.push_back(rdp);
        }
        if (!regdevices.empty())
        {
            etiss::log(
                etiss::INFO,
                "etiss::RegisterDevicePlugin is a legacy convenience plugin. it may become deprecated later on. "
                "consider using etiss::VirtualStruct::Field::Listener to directly listen only for relevant fields.");

            if (vcpu_)
            {
                listener = new LegacyRegisterDevicePluginListener(regdevices);

                vcpu_->foreachField([listener](std::shared_ptr<etiss::VirtualStruct::Field> f) {
                    f->addListener(listener);
                }); // add listener to all current field of struct

                // TODO: maybe later VirtualStruct will support a listener for added/removed fields. in that case the
                // lisener of this function should also be added to new fields
            }
            else
            {
                etiss::log(etiss::WARNING,
                           "etiss::RegisterDevicePlugin added to a CPUCore that doesn't have a VirtualStruct.", name_);
            }
        }
    }

    // start execution loop


    float startTime = (float)clock() / CLOCKS_PER_SEC; // TESTING

    BlockLink *blptr = 0; // pointer to the current block

    etiss::int32 exception = RETURNCODE::NOERROR;

    // sync time at the beginning (e.g. SystemC processes running at time 0)
    system->syncTime(system->handle, cpu_);

    // execution loop
    {
#if ETISS_DBG_ICOUNT_LIMIT > 0 && ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER
        while (likely(instrcounter < ETISS_DBG_ICOUNT_LIMIT))
        {
#else
        while (true)
        {
#endif

            // execute coroutines
            for (auto &cor_plugin : cor_array)
            {
                exception = cor_plugin->execute();
                if (unlikely(exception != RETURNCODE::NOERROR)) // check exception
                {
                    etiss_CPUCore_handleException(cpu_, exception, blptr, translation, arch_.get()); // handle exception
                    if (unlikely(exception != RETURNCODE::NOERROR)) // check if exception handling failed
                    {
                        goto loopexit; // return exception; terminate cpu
                    }
                }
            }
            //            std::cout << "blockCounter: " <<  blockCounter++ <<std::endl;
            //            std::cout << "instrcounter: " <<  instrcounter <<std::endl;
            for (unsigned bc = 0; bc < bcc_; bc++)
            {
                // if not block internal jump // NOTE: removed since tests showed that this decreases performance
                // if (!(blptr != 0 && blptr->valid && blptr->start<=cpu->instructionPointer && blptr->end >
                // cpu->instructionPointer)){
                // Transalte virtual address to physical address if MMU is enabled
                uint64_t pma = cpu_->instructionPointer;

                // remember pc and cpu time to check for loop to self instructions
                uint64_t old_pc = cpu_->instructionPointer;
                uint64_t old_time = cpu_->cpuTime_ps;

                if (mmu_enabled_)
                {
                    if (mmu_->cache_flush_pending)
                    {
                        // FIXME: When flush required, current instruction cache has to be cleared. However, the
                        // unloadBlocks is much too time-comsuming than expected. It should be optimized later on.
                        // translation.unloadBlocks(0,(uint64_t)((int64_t)-1));
                        mmu_->cache_flush_pending = false;
                        blptr = nullptr;
                    }

                    // If the exception could be handled by architecture, then continue translation
                    while ((exception = mmu_->Translate(cpu_->instructionPointer, &pma, etiss::mm::X_ACCESS)))
                    {
                        //	translation.unloadBlocks();
                        if ((exception = arch_->handleException(exception, cpu_)))
                            goto loopexit;
                        // Update pma, in case pc is redirected to physical address space
                        pma = cpu_->instructionPointer;
                    }
                }

                // FIXME: cpu->instructionPointer contains virtual address, getBlockFast should use physical address
                // instead to realize physical cache.
                blptr = translation.getBlockFast(
                    blptr, cpu_->instructionPointer); // IMPORTANT: no pointer reference is kept here. if the translator
                                                      // performs a cleanup then blptr must be set to 0
                //}

                if (unlikely(blptr == 0)) // if no block function pointer could be acquired
                {
                    if (false)
                    {
                        // emulation interface? switch jit?
                        exception = RETURNCODE::ARCHERROR;
                        goto loopexit;
                    }
                    else
                    {
                        std::stringstream stream;
                        stream << "CPU execution stopped: Cannot execute from instruction index " << std::hex
                               << cpu_->instructionPointer << std::dec << ": no translated code available" << std::endl;
                        etiss::log(etiss::WARNING, stream.str());
                        exception = RETURNCODE::JITCOMPILATIONERROR;
                        goto loopexit;
                    }
                }
                else
                {
                    // etiss::log(etiss::FATALERROR,"disabled etiss iss");
#if ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER
                    uint64 oldinstrptr = cpu_->instructionPointer; // TESTING
#endif
                    // plugins_handle_ has the pointer to all translation plugins,
                    // In the generated code these plugin handles are named "plugin_pointers" and can be used to access
                    // a variable of the plugin
                    exception = (*(blptr->execBlock))(cpu_, system, plugins_handle_);


                    // exit simulator when a loop to self instruction is encountered
                    if (!exception &&
                            old_time + cpu_->cpuCycleTime_ps == cpu_->cpuTime_ps &&
                            old_pc == cpu_->instructionPointer)
                    {
                        exception = RETURNCODE::CPUFINISHED;
                    }

#if ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER
                    instrcounter +=
                        blptr->end - oldinstrptr; // TESTING ///TODO handle early exception exit? ///BUG:
                                                  // InstructionPointer increases more than 1 per instruction!!!
//                    std::cout << "blocksize: " << etiss::toString(blptr->end-oldinstrptr) << std::endl;
#endif
                }

                // check for exception in executed block
                if (unlikely(exception != RETURNCODE::NOERROR))
                {
                    etiss_CPUCore_handleException(cpu_, exception, blptr, translation, arch_.get()); // handle exception
                    if (unlikely(exception != RETURNCODE::NOERROR)) // check if exception handling failed
                    {
                        goto loopexit; // exception; terminate cpu
                    }
                }
            }

            // sync time after block
            system->syncTime(system->handle, cpu_);
        }
    }

loopexit:

    float endTime = (float)clock() / CLOCKS_PER_SEC;


    // execute coroutines end
    for (auto &cor_plugin : cor_array)
    {
        cor_plugin->executionEnd(exception);
    }

    // Defining the statistics of measurement and printing them
    double cpu_time = cpu_->cpuTime_ps / 1.0E12;
    double simulation_time = endTime - startTime;
    double cpu_cycle = cpu_->cpuTime_ps / (float)cpu_->cpuCycleTime_ps;
    double mips = cpu_->cpuTime_ps / (float)cpu_->cpuCycleTime_ps / simulation_time / 1.0E6;
    std::cout << "CPU Time: " << (cpu_time) << "s    Simulation Time: " << (simulation_time) << "s"
              << std::endl;
    std::cout << "CPU Cycles (estimated): " << (cpu_cycle) << std::endl;
    std::cout << "MIPS (estimated): " << (mips) << std::endl;


    // declaring path of writing the json file contaiing performance metrics and the boolean which approves of writing the json output
    std::string valid_json_output_path = etiss::cfg().get<std::string>("vp.stats_file_path", "");
    bool output_json = etiss::cfg().isSet("vp.stats_file_path");

    if(output_json==true)
    {
        std::ofstream json_output(valid_json_output_path);
        json_output << "{\"mips\": " << mips << ", \"Simulation_Time\": " << simulation_time << ", \"CPU_Time\": " << cpu_time << ", \"CPU_cycle\": " << cpu_cycle << "}" << std::endl;
    }


    etiss_uint64 max = 0;
    for (int i = 0; i < ETISS_MAX_RESOURCES; i++)
    {
        if (cpu_->resources[i])
        {
            if (cpu_->cycles[i] > max)
            {
                max = cpu_->cycles[i];
            }
        }
    }
    if (max != 0)
    { // max=0: resource computation turned of
        std::cout << "CPU Cycles (with pipeline): " << max << std::endl;
    }
    for (int i = 0; i < ETISS_MAX_RESOURCES; i++)
    {
        if (cpu_->resources[i])
        {
            std::cout << "Resource Usage " << cpu_->resources[i] << ": " << cpu_->resourceUsages[i] << " cycles, "
                      << ((cpu_->resourceUsages[i] / (double)max) * 100) << "%" << std::endl;
        }
    }
#if ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER
    etiss::log(etiss::INFO, std::string("InstructionCounter: ") +
                                etiss::toString(instrcounter / ((double)cpu_->cpuTime_ps / 1000000.0)));
    etiss::log(etiss::INFO, std::string("MIPS (good estimation): ") +
                                etiss::toString(instrcounter / ((double)cpu_->cpuTime_ps / 1000000.0)));
#endif

    // cleanup plugins
    for (auto &p : plugins)
    {
        if (p)
        {
            p->cleanup();
            p->plugin_cpu_ = nullptr;
            p->plugin_system_ = nullptr;
            p->plugin_arch_ = nullptr;
        }
    }

    // undo system wrapping
    for (auto &syswrapper : syswrappers)
    {
        auto psys = syswrapper->unwrap(cpu_, system);
        if (psys)
        {
            system = psys;
        }
        else
        {
            std::stringstream stream;
            stream << "SERVE WARNING: SystemWrapperPlugin \"" << syswrapper->getPluginName()
                   << "\" failed to unwrap ETISS_System instance. Most likely results in a memory leak.";
            etiss::log(etiss::WARNING, stream.str());
            break;
        }
    }

    if (listener)
    {
        vcpu_->foreachField(
            [listener](std::shared_ptr<etiss::VirtualStruct::Field> f) { f->removeListener(listener); });

        delete listener;
    }

    return exception;
}
