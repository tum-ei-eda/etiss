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

        @date July 23, 2014

        @version 0.1

*/
/**
        @file

        @brief defines main cpu core interface

*/

#ifndef ETISS_INCLUDE_CPUCORE_H_
#define ETISS_INCLUDE_CPUCORE_H_

#include "etiss/ClassDefs.h"
#include "etiss/Misc.h"
#include "etiss/LibraryInterface.h"
#include "etiss/JIT.h"
#include "etiss/CPUArch.h"
#include "etiss/Translation.h"
#include "etiss/System.h"
#include "etiss/InterruptHandler.h"
#include "etiss/InterruptEnable.h"
#include "etiss/Plugin.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/mm/MMU.h"
#include "etiss/mm/DMMUWrapper.h"
#include "etiss/mm/PageFaultVector.h"

#include <mutex>
#include <memory>
#include <list>

namespace etiss
{

// change this to enable an approximate instruction counter for processors. the instruction counter can be accessed via
// the VirtualStruct of the processor. the field is named "instructionCounter"
#define ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER 0

/**
 * @brief CPUCore is responsible for the simulation of a CPU core in ETISS.
 *
 * @details CPUCore is responsible for the simulation of a CPU core in ETISS. An
 * instance of CPUCore is always tied to a single CPU architecture. If plug-ins
 * should be active during the simulation they need to be added to the CPUCore
 * instance. Before the simulation can be start a JIT compilier must be present
 * if the default JIT plug-in should not be used (etiss::getDefaultJIT()). A
 * JIT plug-in must be specified with CPUCore::set(). To start the simulation of
 * a system model with a CPUCore instance call CPUCore::execute().
 *
 * @code
 *   etiss::Initializer initialzer(); // initialize ETISS
 *
 *   { // ensure that the object using ETISS are deleted before the shutdown of ETISS
 *
 *     // create CPU simulator instance for the or1k architecture
 *     std::shared_ptr<etiss:CPUCore> cpu = etiss::CPUCore::create("or1k", "core0");
 *
 *     cpu.set(etiss::getJIT("GCCJIT"); // set JIT plug-in to be used for the simulation
 *
 *     cpu.addPlugin(etiss::getPlugin("PrintInstruction")); // add a plug-in to the simulation
 *
 *     MySystemModel system(); // instance of the system model to be simulated
 *
 *     cpu.execute(system); // run the simulation
 *   }
 * @endcode
 *
 * @see ETISS_System
 * @see etiss::System
 */
class CPUCore : public VirtualStructSupport, public etiss::ToString
{
    friend class CPUArchRegListenerInterface;
    friend class InterruptVectorWrapper;

  private:
    /**
     * @brief Private constructor of CPUCore.
     *
     * @details To create a new instance of CPUCore use the CPUCore::create().
     *
     * @param name The name of the CPUCore instance.
     *
     * @param arch Pointer to the CPU architecture used by the CPU core simulator.
     */
    CPUCore(std::shared_ptr<etiss::CPUArch> arch);

    class InterruptVectorWrapper : public InterruptVector
    {
      private:
        std::list<etiss::InterruptListenerPlugin *> plugins_;

      public:
        CPUCore &parent_;
        InterruptVectorWrapper(CPUCore &parent);
        virtual void setBit(unsigned bit, bool state);
        virtual bool getBit(unsigned bit) const;
        virtual unsigned width() const;
        virtual bool isActive() const;
        virtual void clear();
    };

  public:
    ~CPUCore();
    /**
     * @brief Reset the CPU state.
     *
     * @note startindex != start address
     *
     * @todo Add explanation of start index.
     */
    inline void reset(etiss::uint64 *startindex) { arch_->resetCPU(cpu_, startindex); }

    /**
     * @brief Get the CPU state structure containing instruction pointer, frequency, etc.
     *
     * @return A pointer to the architecture specific cpu state structure
     */
    inline ETISS_CPU *getState() { return cpu_; }

    /**
     * @brief Get the virtual structure of this CPUCore instance.
     *
     * @details The virtual structure allows the to access the fields of the CPU
     * structure and sub structures (e.g. plug-ins) used by CPUCore.
     *
     * @return A pointer to the virtual structure.
     */
    virtual inline std::shared_ptr<VirtualStruct> getStruct() { return vcpu_; }

    /**
     * @brief Get the Memory Management Unit(MMU) of this CPUCore instance.
     *
     * @details MMU is responsible to translate virtual address to physical
     * address, which is essential to support multi-taking operationg systems,
     * such as Linux
     *
     * @return A shared pointer to the MMU
     */
    virtual inline std::shared_ptr<etiss::mm::MMU> getMMU() { return mmu_; }

    /**
     * @brief Get the interrupt vector of simulated CPU.
     *
     * @return A pointer to the interrupt vector of the simulated CPU.
     */
    inline etiss::InterruptVector *getInterruptVector() { return intwrapper_; }

    inline etiss::InterruptEnable *getInterruptEnable() { return intenable_; }

    /**
     * @brief Get the CPU architecture.
     *
     * @return A pointer to the CPU architecture.
     */
    inline std::shared_ptr<etiss::CPUArch> getArch() { return arch_; }

    /**
     * @brief Set the JIT plug-in used for execution.
     *
     * @details If no JIT plug-in is specified then the first loaded JIT plug-in
     * is used.
     *
     * @see etiss::loadJIT
     * @see etiss::getJIT
     * @see etiss::listJIT
     *
     * @param jit A pointer to the JIT plug-in, that should be used.
     */
    inline void set(std::shared_ptr<etiss::JIT> jit) { jit_ = jit; }

    /**
     * @brief Enable or disable the timer of the CPU.
     *
     * @note Has no effect if the architecture does not support a timer.
     *
     * @param on true to enable the timer / false to disable the timer
     */
    inline void setTimer(bool on)
    {
        std::lock_guard<std::mutex> lock(mu_);
        timer_enabled_ = on;
    }

    /**
     * @brief Adds a plug-in to the core simulator.
     *
     * @details See the different plug-in classes, for information on how the
     * plug-in influences the simulation.
     *
     * @attention The same plug-in may not be added multiple times.
     *
     * @see etiss::TransTranslatorPlugin
     * @see etiss::CoroutinePlugin
     * @see etiss::SystemWrapperPlugin
     *
     * @param plugin Pointer to the plug-in that shall be added.
     */
    void addPlugin(std::shared_ptr<etiss::Plugin> plugin);

    /**
     * @brief Remove a plug-in from the core simulator.
     *
     * @param plugin Pointer to the plug-in that shall be removed.
     */
    void removePlugin(std::shared_ptr<etiss::Plugin> plugin);

    /**
     *@brief Remove all plug-ins from the core simulator.
     */
    inline void removePlugins()
    {
        std::lock_guard<std::mutex> lock(mu_);
        plugins.clear();
    }

    /**
     * @brief Set the number of blocks jumps in between the coroutines are not
     * executed.
     */
    inline void setBlockChainCount(unsigned bcc) { bcc_ = bcc; }

    /**
     * @brief Start the simulation of the CPU core for the system model.
     *
     * @detail This method starts the simulation of the CPU core for the provided
     * system model. It uses the C-structure interface to access the system model.
     * This method is (like any other methods of this class) thread-safe.
     * However if any method of this class including this one is called while this
     * method is running, it will block until this method is finished returns.
     *
     * @return A return code as result of the simulation (ReturnCode.h)
     */
    etiss::int32 execute(ETISS_System &system);

    /**
     * @brief Start the simulation of the CPU core for the system model.
     *
     * @details This method works the same as execute(ETISS_System & system), but
     * uses the etiss::System interface to access the model.
     *
     * @see execute(ETISS_System & system)
     *
     * @return A return code as result of the simulation (ReturnCode.h)
     */
    inline etiss::int32 execute(etiss::System &system)
    {
        std::shared_ptr<ETISS_System> sys = etiss::wrap(&system);
        if (sys.get() == 0)
            return RETURNCODE::GENERALERROR;
        etiss::uint32 ret = execute(*(sys.get()));
        return ret;
    }

    /**
     * @brief Get the name of the CPUCore instance.
     *
     * @return The name string of the instance.
     */
    inline const std::string &getName() { return name_; }

    /**
     * @brief Get the ID of the CPUCore instance.
     *
     * @return The ID string of the instance.
     */
    inline const int &getID() { return id_; }

    /**
     * @brief Get the name of the JIT plug-in used by the CPUCore instance.
     *
     * @return Name string of the JIT plug-in;
     */
    inline std::string getJITName()
    {
        std::shared_ptr<etiss::JIT> jit = jit_;
        if (jit.get())
        {
            return jit->getName();
        }
        else
        {
            return "";
        }
    }

    /**
     * @brief Get a reference to the JIT plugin.
     */
    inline std::shared_ptr<etiss::JIT> getJIT() { return jit_; }

    /**
     * @brief Get a string representation of the object.
     */
    inline const std::string &toString() const { return name_; }

    /**
     * @brief returns the plugin with the given name.
     */
    inline std::shared_ptr<Plugin> getPlugin(std::string name)
    {
        for (auto iter : plugins)
        {
            // std::cout << "found plugin: " << iter->_getPluginName();
            if (iter->_getPluginName() == name)
                return iter;
        }
        return nullptr;
    };
    /**
     * @brief returns the list of all plugins.
     */
    inline std::list<std::shared_ptr<Plugin>> const *getPlugins() { return &plugins; };
  public:
    /**
     * @brief Create a CPUCore instance.
     *
     * @details This is the factory method to create a new CPUCore instance for a
     * specific CPU architecture.
     *
     * @param archname The name of a CPUArch plug-in. This plug-in must be present
     * in ETISS in order to create the CPUCore instance.
     *
     * @param instancename A descriptive name for the new instance.
     *
     * @param archoptions A key value map with options for the CPUArch plug-in.
     *
     * @return A pointer to the new instance or 0, if the given architecture is
     * not present
     */
    static std::shared_ptr<CPUCore> create(
        std::string archname,
        std::string instancename = "", /// obsolet: now defined by ID - "core[ID]"
        std::map<std::string, std::string> archoptions = std::map<std::string, std::string>());

    static int getNextID();

    /**
     * @brief returns a list of currently present CPU cores
     */
    static std::list<std::string> list();

  private:
    std::shared_ptr<etiss::CPUArch> arch_; /// cpu architecture of this cpu core. may never be 0 or changed
    std::string name_;                     /// name of the cpu core
    const int id_;                         /// ID of the cpu core
    ETISS_CPU *cpu_;                       /// cpu state structure allocated by arch_
    std::shared_ptr<etiss::VirtualStruct> vcpu_;
    etiss::InterruptVector *intvector_;  /// cpu interrupt vector derived from cpu_ and allocated by arch_
    InterruptVectorWrapper *intwrapper_; /// wrapped interrupt vector to allow interrupt listening
    etiss::InterruptEnable *intenable_;
    bool timer_enabled_; /// if true the a timer plugin allocated by arch_ will be added in CPUCore::execute
    std::shared_ptr<etiss::JIT>
        jit_;       /// JIT instance to use. may be 0 (etiss::getDefaultJIT() will be used in that case)
    std::mutex mu_; /// mutex to lock the configuration of this cpu core. etiss::CPUCore::execution holds this lock
                    /// during execution
    std::list<std::shared_ptr<Plugin>> plugins; /// list of all plugins
    unsigned bcc_;
    unsigned blockCounter;
    unsigned exception_skip_count_;
    int blockCacheLimit_; /// TODO: possibility to limit the cache size
    bool mmu_enabled_;
    std::shared_ptr<etiss::mm::MMU> mmu_;

  public:
    uint64_t instrcounter; /// this field is always present to maintain API compatibility but it is only used if
                           /// ETISS_CPUCORE_DBG_APPROXIMATE_INSTRUCTION_COUNTER is set to 1

  private:
    static std::mutex instances_mu_; /// mutext for access to a list of cpu core instances
    static std::list<std::weak_ptr<CPUCore>>
        instances_; /// list of weak references to currently present cpu cores (@see etiss::CPUCore::list)
};

} // namespace etiss

#endif
