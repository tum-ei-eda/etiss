// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implements etiss/Plugin.h

        @detail

*/

#include "etiss/Plugin.h"

using namespace etiss;

Plugin::Plugin(unsigned type)
    : plugin_cpu_(nullptr)
    , plugin_system_(nullptr)
    , plugin_arch_(nullptr)
    , plugin_core_(nullptr)
    , type_(type)
    , name_("")
    , tplugin_(0)
    , splugin_(0)
    , cplugin_(0)
    , rplugin_(0)
    , trplugin_(0)
    , lastAssignedCoreName_("")
{
}
Plugin::~Plugin() {}

void Plugin::init(ETISS_CPU *cpu, ETISS_System *system, CPUArch *arch) {}
void Plugin::cleanup() {}

InterruptListenerPlugin::InterruptListenerPlugin()
{
    this->type_ |= Plugin::INTERRUPTLISTENER;
    this->tplugin_ = this;
}

InterruptListenerPlugin::~InterruptListenerPlugin() {}

TranslationPlugin::TranslationPlugin()
{
    this->type_ |= Plugin::TRANSLATION;
    this->trplugin_ = this;
}
TranslationPlugin::~TranslationPlugin() {}
void TranslationPlugin::initInstrSet(etiss::instr::ModedInstructionSet &) const {}
void TranslationPlugin::finalizeInstrSet(etiss::instr::ModedInstructionSet &) const {}
void TranslationPlugin::initCodeBlock(etiss::CodeBlock &) const {}
void TranslationPlugin::finalizeCodeBlock(etiss::CodeBlock &) const {}

void *TranslationPlugin::getPluginHandle()
{
    return this;
}

std::string TranslationPlugin::getPointerCode() const
{
    return pointerCode;
}

CoroutinePlugin::CoroutinePlugin()
{
    this->type_ |= Plugin::COROUTINE;
    this->cplugin_ = this;
}
CoroutinePlugin::~CoroutinePlugin() {}
void CoroutinePlugin::executionEnd(int32_t code) {}

SystemWrapperPlugin::SystemWrapperPlugin()
{
    this->type_ |= Plugin::SYSTEMWRAPPER;
    this->splugin_ = this;
}
SystemWrapperPlugin::~SystemWrapperPlugin() {}

RegisterDevicePlugin::RegisterDevicePlugin()
{
    this->type_ |= Plugin::REGISTERDEVICE;
    this->rplugin_ = this;
}
RegisterDevicePlugin::~RegisterDevicePlugin() {}
