// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief plugins for extensions to code translation and instruction execution

        @detail

*/

#ifndef ETISS_INCLUDE_PLUGIN_H_
#define ETISS_INCLUDE_PLUGIN_H_

#include <sstream>
#include <string>

#include "etiss/ClassDefs.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

#include "etiss/CodePart.h"

namespace etiss
{

/**
        @brief base plugin class that provides access to different plugin functions if present
        @see InterruptListenerPlugin
        @see CoroutinePlugin
        @see SystemWrapperPlugin
        @see RegisterDevicePlugin
*/
class Plugin : public etiss::ToString
{
    friend class InterruptListenerPlugin;
    friend class TranslationPlugin;
    friend class CoroutinePlugin;
    friend class SystemWrapperPlugin;
    friend class RegisterDevicePlugin;
    friend class CPUCore;

  protected:
    Plugin(unsigned type = 0);

  public:
    virtual ~Plugin();

  public:
    static const unsigned INTERRUPTLISTENER = 1 << 0; ///< access to translated code
    static const unsigned COROUTINE = 1 << 1;         ///< callback after execution of each translated block
    static const unsigned SYSTEMWRAPPER = 1 << 2;     ///< can wrap/change ETISS_System structure at execution start
    static const unsigned REGISTERDEVICE =
        1 << 3; ///< gets noticed of changes to special registers (e.g. mmu register etc. [depends on architecture])
    static const unsigned TRANSLATION =
        1 << 4; ///< access to translated code during translation phase or when instruction tree is built
  public:
    /**
            @return an integer that has the appropriate bits set for its implemented plugin types
       (Plugin::INTERRUPTLISTENER,Plugin::COROUTINE,Plugin::SYSTEMWRAPPER,Plugin::REGISTERDEVICE)
    */
    inline unsigned getType() { return type_; }
    /**
            @return a pointer to an implemented InterruptListenerPlugin
    */
    inline InterruptListenerPlugin *getInterruptListenerPlugin() { return tplugin_; }
    /**
            @return a pointer to an implemented CoroutinePlugin
    */
    inline CoroutinePlugin *getCoroutinePlugin() { return cplugin_; }
    /**
            @return a pointer to an implemented SystemWrapperPlugin
    */
    inline SystemWrapperPlugin *getSystemWrapperPlugin() { return splugin_; }
    /**
            @return a pointer to an implemented RegisterDevicePlugin
    */
    inline RegisterDevicePlugin *getRegisterDevicePlugin() { return rplugin_; }

    /**
            @return a pointer to an implemented RegisterDevicePlugin
    */
    inline TranslationPlugin *getTranslationPlugin() { return trplugin_; }
    /**
            @return a plugin name consisting of the value returned by Plugin::_getPluginName and a list of implemented
       interfaces
    */
    inline std::string getPluginName() const
    {
        if (name_.length() <= 0)
        {
            std::stringstream ss;
            bool fe = true;
            ss << _getPluginName();
            ss << "{";
            if (type_ & INTERRUPTLISTENER)
            {
                ss << (fe ? "" : ",") << "INTERRUPTLISTENER";
                fe = false;
            }
            if (type_ & COROUTINE)
            {
                ss << (fe ? "" : ",") << "COROUTINE";
                fe = false;
            }
            if (type_ & SYSTEMWRAPPER)
            {
                ss << (fe ? "" : ",") << "SYSTEMWRAPPER";
                fe = false;
            }
            if (type_ & REGISTERDEVICE)
            {
                ss << (fe ? "" : ",") << "REGISTERDEVICE";
                fe = false;
            }
            if (type_ & TRANSLATION)
            {
                ss << (fe ? "" : ",") << "TRANSLATION";
            }
            ss << "}";
            name_ = ss.str();
        }
        return name_;
    }

    /**
     * @note Every Plugin is assigned to an CPUCore. When the CPUCore is destructed
     *       this Function can be used to get the CoreName again. Especially for
     *       needed for Core Specific Configurations
     * @return Name of the Core which was last assigned to this Plugin
     */
    const std::string &getLastAssignedCoreName() { return lastAssignedCoreName_; }

    inline std::string toString() const { return getPluginName(); }

  protected:
    virtual std::string _getPluginName() const = 0;

  protected:
    /**
            @brief this function is called before the plugin is used in the cpu execution loop
       (etiss::CPUCore::execute). Only exception is the SystemWrapperPlugin whose SystemWrapperPlugin::wrap function is
       called BEFORE Plugin::init
    */
    virtual void init(ETISS_CPU *cpu, ETISS_System *system, CPUArch *arch);
    /**
            @brief this function is called after cpu execution loop (etiss::CPUCore::execute) finished. Only the
       SystemWrapperPlugin::unwrap function is called AFTER Plugin::cleanup
    */
    virtual void cleanup();
    ETISS_CPU
    *plugin_cpu_; ///< holds a pointer to the cpu structure. will be set before init call and after cleanup call
    ETISS_System *plugin_system_; ///< holds a pointer to the system structure. will be set before init call and after
                                  ///< cleanup call
    CPUArch
        *plugin_arch_; ///< holds a pointer to the CPUArch instance. will be set before init call and after cleanup call
    CPUCore *plugin_core_; ///< holds a pointer to the associated CPUCore instance. this pointer is valid as long a
                           ///< plugin is associtated with a cpu core. use with caution since this pointer may change in
                           ///< a non threadsafe manner.

    void setCorrespondingCPUCoreName(std::string name) { lastAssignedCoreName_ = name; }
    /**
        called as soon a plugin has been added to its CPUCore.
        this method explicitly allows to configure/manipulate the cpu core and doesn't run into deadlock if a
       synchronized CPUCore function is called.
    */
    virtual inline void addedToCPUCore(etiss::CPUCore *core) {}
    /**
        called as soon a plugin has been removed from its CPUCore. similar to addedToCPUCore() it is possible to modify
       the CPUCore
    */
    virtual inline void removedFromCPUCore(etiss::CPUCore *core) {}

  private:
    unsigned type_;
    mutable std::string name_; ///< contains a name that is build from the return value of getPluginName_() + the
                               ///< implemented interfaces of a plugin
    InterruptListenerPlugin *tplugin_;
    SystemWrapperPlugin *splugin_;
    CoroutinePlugin *cplugin_;
    RegisterDevicePlugin *rplugin_;
    TranslationPlugin *trplugin_;
    std::string lastAssignedCoreName_;
};

/**
        @brief
        @deprecated
*/
class InterruptListenerPlugin : virtual public Plugin
{
  public:
    InterruptListenerPlugin();
    virtual ~InterruptListenerPlugin();
    /**
            gets called whenever an external write to the interrrupt vector takes place
            @return true if the interrupt bit is handled by this plugin and may not be passed on to the cpu
    */
    virtual bool interruptWrite(unsigned bit, bool value) = 0;
};

/**
            @brief allows to add code to the translation of instructions

            There can be one member variable used.
            During translation a pointer of type void, which can be cast to any type, to the member variable can be
   obtained by the code returned by ::getPointerCode() as string

            This code accesses the variable plugin_pointers in the translated code, which is a parameter that holds the
   a list of "this pointers" to all translation plugins, it seems the "this pointers" always point to the member
   variable (???)

            The function ::TranslationPlugin::getPluginHandle returns the "this pointer",
            It is used in Translation::init to fill the list of all translation plugins

    */

class TranslationPlugin : virtual public Plugin
{
    friend class etiss::Translation;

  public:
    TranslationPlugin();
    virtual ~TranslationPlugin();
    /// called to add instructions to the instruction set
    virtual void initInstrSet(etiss::instr::ModedInstructionSet &) const;
    /// called after all instructions have been added to allow last changes
    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const;
    /// called before instructions are translated for the code block
    virtual void initCodeBlock(etiss::CodeBlock &) const;
    /// called after all instructions have been translated for the code block
    virtual void finalizeCodeBlock(etiss::CodeBlock &) const;
    /// called to get the handle that is available in translated code via getPoinerCode(). [default: this]
    virtual void *getPluginHandle();

  protected:
    /**
            returns a C code expression that allows to get or assign a pointer to the variable assigned to this
       translation plugin. this function may only be called from within member functions of this class pointerCode is
       set in Translation::init
    */
    std::string getPointerCode() const;

  private:
    std::string pointerCode;
};

/**
        @brief this plugin will be called before a block is executed. it may make the same modifications as a block of
   translated code and returned codes are also handled the same way as those returned by a translated block.

        @detail this plugin is especially important for interrupt handlers, timer implementations or possible memory
   management units
*/
class CoroutinePlugin : virtual public Plugin
{
  public:
    CoroutinePlugin();
    virtual ~CoroutinePlugin();
    /**
            @brief called before a block and may act in the same way as a block
    */
    virtual etiss::int32 execute() = 0;
    /**
@brief called when the simulation ends but before any deinitialization is done
@param code the code that will be returned by etiss::CPUCore::execute().
*/
    virtual void executionEnd(int32_t code);
    /**
     * \brief indicates if the plugin will do something in execution loop. Important for Plugins
     *        which have an flag that must be set to execute.
     */
    virtual bool isActive() { return true; }
};

/**
        @brief this plugin allows to wrap the ETISS_System interface

        @detail e.g. etiss::plugin::gdb::Server uses this interface to gain access to data read/writes for breakpoint
   hits
*/
class SystemWrapperPlugin : virtual public Plugin
{
  public:
    SystemWrapperPlugin();
    virtual ~SystemWrapperPlugin();
    /**
            @brief change/wrap the passed system structure. the returned value will be used as the current system
                    this function will be called BEFORE etiss::Plugin::init
    */
    virtual ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system) = 0;
    /**
            @brief undo wrap function call
                    this function will be called AFTER etiss::Plugin::cleanup
    */
    virtual ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system) = 0;
};

/**
        @brief RegisterDevicePlugin::changedRegister is called if a supported register has been changed. support for
   this has to be provided by the CPUArch implementation
        @see etiss::CPUArchRegListenerInterface
*/
class RegisterDevicePlugin : virtual public Plugin
{
  public:
    RegisterDevicePlugin();
    virtual ~RegisterDevicePlugin();
    /**
            @brief called when an observable register has been changed
            @see etiss::CPUArchRegListenerInterface
    */
    virtual void changedRegister(const char *name) = 0;
};

} // namespace etiss

#endif
