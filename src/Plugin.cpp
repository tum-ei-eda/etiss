/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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
