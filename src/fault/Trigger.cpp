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

#ifndef NO_ETISS
#include "etiss/fault/Trigger.h"
#include "etiss/Misc.h"
#include "etiss/fault/Injector.h"
#else
#include "fault/Injector.h"
#include "fault/Trigger.h"
#endif

#include <iostream>

namespace etiss
{

namespace fault
{

void Trigger::ensure(Type type) const
{
    if (type_ != type)
    {
        etiss::log(etiss::FATALERROR, std::string("etiss::fault::Trigger::ensure: Type mismatch type=") +
                                          std::to_string(type) + " type_=" + std::to_string(type_));
        throw "called function of different trigger type";
    }
}

Trigger::Trigger() : type_(NOP)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Trigger::Trigger() : type_ (NOP)"));
}
Trigger::Trigger(const Trigger &sub, uint64_t count)
    : type_(META_COUNTER), sub_(new Trigger(sub)), param1_(count), param2_(0)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Trigger::Trigger() : type_ (META_COUNTER)"));
}
Trigger::Trigger(const InjectorAddress &target_injector, const std::string &field, uint64_t value)
    : type_(VARIABLEVALUE), field_(field), inj_(target_injector), fieldptr_(0), param1_(value)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Trigger::Trigger() : type_ (VARIABLEVALUE)"));
}
Trigger::Trigger(const InjectorAddress &target_injector, uint64_t time_ps, bool relative)
    : type_(relative ? TIMERELATIVE : TIME), inj_(target_injector), param1_(time_ps), param2_(0)
{
    relative ? etiss::log(etiss::VERBOSE, std::string("etiss::fault::Trigger::Trigger() : type_ (TIMERELATIVE)"))
             : etiss::log(etiss::VERBOSE, std::string("etiss::fault::Trigger::Trigger() : type_ (TIME)"));
}

Trigger::Trigger(const Trigger &cpy) : type_(NOP)
{
    *this = cpy;
}
Trigger &Trigger::operator=(const Trigger &cpy)
{
    if (type_ == META_COUNTER)
        delete sub_;
    if (type_ == VARIABLEVALUE)
    {
        if (inj_.isResolved() && fieldptr_)
        {
            inj_.getInjector()->freeFastFieldAccessPtr(fieldptr_);
        }
    }
    type_ = cpy.type_;
    switch (type_)
    {
    case META_COUNTER:
        sub_ = new Trigger(*cpy.sub_);
        param1_ = cpy.param1_;
        param2_ = cpy.param2_;
        break;
    case VARIABLEVALUE:
        field_ = cpy.field_;
        inj_ = cpy.inj_;
        fieldptr_ = 0;
        param1_ = cpy.param1_;
        break;
    case TIME:
        inj_ = cpy.inj_;
        param1_ = cpy.param1_;
        param2_ = cpy.param2_;
        break;
    case NOP:
        break;
    }
    return *this;
}

#if CXX0X_UP_SUPPORTED
Trigger::Trigger(Trigger &&cpy) : type_(NOP)
{
    operator=(cpy);
}
Trigger &Trigger::operator=(Trigger &&cpy)
{
    operator=((const Trigger &)cpy);
    return *this;
}
#endif

Trigger::~Trigger()
{
    if (type_ == META_COUNTER)
        delete sub_;
    if (type_ == VARIABLEVALUE)
    {
        if (inj_.isResolved() && fieldptr_)
        {
            inj_.getInjector()->freeFastFieldAccessPtr(fieldptr_);
        }
    }
}

bool Trigger::fired(uint64_t time_ps, etiss::fault::Injector *target_injector)
{
    etiss::log(etiss::VERBOSE, std::string("etiss::fault::Trigger::fired(time_ps=") + std::to_string(time_ps) +
                                   std::string(", Injector*)"));
    // std::cout << "Trigger::fired called at " << time_ps << " ps" << std::endl;
    switch (type_)
    {
    case META_COUNTER:
        if (sub_->fired(time_ps, target_injector))
        {
            ++param2_; // increase count
            if (param1_ == param2_)
            {
                return true; // count reached -> fire event
            }
        }
        break;
    case VARIABLEVALUE:
    {
        if (fieldptr_ == 0)
        {
            std::string errmsg;
            fieldptr_ = target_injector->fastFieldAccessPtr(field_, errmsg);
            if (fieldptr_ == 0)
            {
#ifdef NO_ETISS
                std::cout << "Trigger::fired: Failed to get field" << std::endl;
#else
                etiss::log(etiss::ERROR, "Trigger::fired: Failed to get field", *this);
#endif
                return false;
            }
        }
        uint64_t val = 0;
        std::string errmsg;
        if (inj_.getInjector())
        {
            if (!inj_.getInjector()->readField(fieldptr_, val, errmsg))
            {
#ifdef NO_ETISS
                std::cout << "Trigger::fired: Failed to read field: " << errmsg << std::endl;
#else
                etiss::log(etiss::ERROR, "Trigger::fired: Failed to get field", *this, errmsg);
#endif
                return false;
            }
        }
        else
        {
#ifdef NO_ETISS
            std::cout << "Trigger::fired: Failed get injector: " << inj_.getInjectorPath() << std::endl;
#else
            etiss::log(etiss::ERROR, "Trigger::fired: Failed get injector", *this, inj_);
#endif
        }
        return val == param1_;
    }
    break;
    case TIME:
        /* TODO: Why doing it like this ? this would always fire after time_ps has reached */
        // Possibly because might be called not exaclty but later than excact trigger time, then late triggering should
        // be done

        // if (time_ps >= param1_ && param2_ <= time_ps)
        if (param1_ <= time_ps && param2_ == 0) // testing alternative param2_ says if trigger has already fired
        {
            /// TODO decide how to handle the case of multiple trigger checks at the same simulation time

            // param2_ = time_ps+1;
            param2_ = 1; // testing alternative: param2_ says if trigger has already fired
            return true;
        }
        // param2_ = time_ps;
        // testing alternative param2_ says if trigger has already fired

        // DO NOT DO IT LIKE THIS, MIGHT NOT BE CALLED EXACTLY WITH TIME OF TRIGGER
        // if (time_ps == param1_)
        // return true;
        break;
    case NOP:
        break;
    }

    return false;
}

void Trigger::resolveTime(uint64_t time)
{
    etiss::log(etiss::VERBOSE,
               std::string("etiss::fault::Trigger::resolveTime(time=") + std::to_string(time) + std::string(")"));
    if (type_ == TIMERELATIVE)
    {
        type_ = TIME;
        param1_ = param1_ + time;
    }
    else if (type_ == META_COUNTER)
    {
        return getSubTrigger().resolveTime(time);
    }
}
bool Trigger::isResolved() const
{
    if (type_ == META_COUNTER)
    {
        return getSubTrigger().isResolved();
    }
    return type_ != TIMERELATIVE;
}

uint64_t Trigger::getTriggerCount() const
{
    ensure(META_COUNTER);
    return param1_;
}
Trigger &Trigger::getSubTrigger()
{
    ensure(META_COUNTER);
    return *sub_;
}
const Trigger &Trigger::getSubTrigger() const
{
    ensure(META_COUNTER);
    return *sub_;
}
uint64_t Trigger::getTriggerTime() const
{
    if (type_ == META_COUNTER)
    {
        return getSubTrigger().getTriggerTime();
    }
    try
    {
        ensure(TIME);
    }
    catch (char const *)
    {
        ensure(TIMERELATIVE);
    }
    return param1_;
}
const InjectorAddress &Trigger::getInjectorAddress() const
{
    return inj_;
}
const Injector_ptr &Trigger::getInjector() const
{
    if (type_ == META_COUNTER)
    {
        return sub_->getInjector();
    }
    else
    {
        return inj_.getInjector();
    }
}
bool Trigger::isNOP() const
{
    if (type_ == META_COUNTER)
    {
        return sub_->isNOP();
    }
    else
    {
        return type_ == NOP;
    }
}
const std::string &Trigger::getTriggerField() const
{
    // std::cout << "Trigger::getTriggerField() called" << std::endl;
    if (type_ == META_COUNTER)
    {
        return getSubTrigger().getTriggerField();
    }
    ensure(VARIABLEVALUE);
    return field_;
}
const uint64_t &Trigger::getTriggerFieldValue() const
{
    // std::cout << "Trigger::getTriggerFieldValue() called" << std::endl;
    if (type_ == META_COUNTER)
    {
        return getSubTrigger().getTriggerFieldValue();
    }
    ensure(VARIABLEVALUE);
    return param1_;
}
Trigger::Type Trigger::getType() const
{
    return type_;
}

std::string Trigger::toString() const
{
    std::stringstream ss;
    ss << "Trigger {";
    switch (type_)
    {
    case META_COUNTER:
        ss << " type=META_COUNTER triggerCount=" << +param1_ << " currentCount=" << +param2_;
        break;
    case VARIABLEVALUE:
        ss << " type=VARIABLEVALUE field=" << field_ << " triggerValue=" << +param1_;
        break;
    case TIME:
        ss << " type=TIME triggerTime=" << +param1_;
        break;
    case NOP:
        ss << " type=NOP";
        break;
    }
    ss << "}";
    return ss.str();
}

#if ETISS_FAULT_XML
namespace xml
{
template <>
bool parse<etiss::fault::Trigger *>(pugi::xml_node node, etiss::fault::Trigger *&f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::parse<etiss::fault::Trigger*>") +
                                   std::string("(node, Trigger*&, Diagnostics)"));
    f = 0;
    std::string type;
    if (!parse_attr(node, "type", type, diag))
    {
        return false;
    }

    if (type == "META_COUNTER")
    {
        uint64_t count;
        if (!parse<uint64_t>(findSingleNode(node, "count", diag), count, diag))
        {
            return false;
        }
        etiss::fault::Trigger *sub = 0;
        if ((!parse<etiss::fault::Trigger *>(findSingleNode(node, "trigger", diag), sub, diag)) || (sub == 0))
        {
            diag.unexpectedNode(node, "Failed to parse sub trigger");
            return false;
        }
        f = new etiss::fault::Trigger(*sub, count);
        delete sub;
        return true;
    }

    if (type == "VARIABLEVALUE")
    {
        uint64_t value;
        if (!parse_hex(findSingleNode(node, "value", diag), value, diag))
        {
            return false;
        }
        std::string field;
        if (!parse<std::string>(findSingleNode(node, "field", diag), field, diag))
        {
            return false;
        }
        setCoreName(field);
        etiss::fault::InjectorAddress injector;
        if (!parse<etiss::fault::InjectorAddress>(findSingleNode(node, "injector", diag), injector, diag))
        {
            return false;
        }
        f = new Trigger(injector, field, value);
        return true;
    }

    if (type == "TIME")
    {
        uint64_t count;
        if (!parse<uint64_t>(findSingleNode(node, "time_ps", diag), count, diag))
        {
            return false; /// TODO support other time formats/better nodes e.g. <time
                          /// unit="ps"> 1234 </time>
        }
        etiss::fault::InjectorAddress injector;
        if (!parse<etiss::fault::InjectorAddress>(findSingleNode(node, "injector", diag), injector, diag))
        {
            return false;
        }
        f = new Trigger(injector, count);
        return true;
    }

    if (type == "TIMERELATIVE")
    {
        uint64_t count;
        if (!parse<uint64_t>(findSingleNode(node, "time_ps", diag), count, diag))
        {
            return false; /// TODO support other time formats/better nodes e.g. <time
                          /// unit="ps"> 1234 </time>
        }
        etiss::fault::InjectorAddress injector;
        if (!parse<etiss::fault::InjectorAddress>(findSingleNode(node, "injector", diag), injector, diag))
        {
            return false;
        }
        f = new Trigger(injector, count, true);
        std::cout << "Injector2: " << f->getInjectorAddress().getInjectorPath() << std::endl;
        return true;
    }

    return false;
}
template <>
bool write<const etiss::fault::Trigger *>(pugi::xml_node node, const etiss::fault::Trigger *const &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::write<etiss::fault::Trigger*>") +
                                   std::string("(node, Trigger*&, Diagnostics)"));
    if (f == 0)
        return false;
    return write<etiss::fault::Trigger>(node, *f, diag);
}

template <>
bool parse<etiss::fault::Trigger>(pugi::xml_node node, etiss::fault::Trigger &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::parse<etiss::fault::Trigger>") +
                                   std::string("(node, Trigger&, Diagnostics)"));
    etiss::fault::Trigger *t = 0;
    if (!parse<etiss::fault::Trigger *>(node, t, diag))
        return false;
    f = *t;
    delete t;
    return true;
}
template <>
bool write<etiss::fault::Trigger>(pugi::xml_node node, const etiss::fault::Trigger &f, Diagnostics &diag)
{
    etiss::log(etiss::VERBOSE, std::string("Called etiss::fault::xml::write<etiss::fault::Trigger>") +
                                   std::string("(node, Trigger&, Diagnostics)"));
    // std::cout << "write<etiss::fault::Trigger> called " << std::endl;
    switch (f.getType())
    {
    case etiss::fault::Trigger::META_COUNTER:
    {
        write_attr<std::string>(node, "type", "META_COUNTER", diag);
        write<uint64_t>(node.append_child("count"), f.getTriggerCount(), diag);
        write<etiss::fault::Trigger>(node.append_child("trigger"), f.getSubTrigger(), diag);
    }
        return true;
    case etiss::fault::Trigger::VARIABLEVALUE:
    {
        write_attr<std::string>(node, "type", "VARIABLEVALUE", diag);
        write<std::string>(node.append_child("field"), f.getTriggerField(), diag);
        write<uint64_t>(node.append_child("count"), f.getTriggerFieldValue(), diag);
        Injector_ptr ptr = f.getInjector();
        if (!ptr)
        {
            diag.errors.push_back("A fault trigger has no target_injector. failed to "
                                  "get path of trigger");
            return false;
        }
        write<std::string>(node.append_child("injector"), ptr->getInjectorPath(), diag);
    }
        return true;
    case etiss::fault::Trigger::TIME:
    case etiss::fault::Trigger::TIMERELATIVE:
    {
        write_attr<std::string>(node, "type",
                                (f.getType() == etiss::fault::Trigger::TIMERELATIVE) ? "TIMERELATIVE" : "TIME", diag);
        write<uint64_t>(node.append_child("time_ps"), f.getTriggerTime(), diag);
        Injector_ptr ptr = f.getInjector();
        if (!ptr)
        {
            diag.errors.push_back("A fault trigger has no target_injector. failed to "
                                  "get path of trigger");
            return false;
        }
        write<std::string>(node.append_child("injector"), ptr->getInjectorPath(), diag);
    }
        return true;
    case etiss::fault::Trigger::NOP:
    {
        write_attr<std::string>(node, "type", "NOP", diag);
    }
        return true;
    }

    diag.errors.push_back("etiss::fault::xml::write<etiss::fault::Trigger> "
                          "encountered an unknown type of trigger");

    return false;
}

} // namespace xml
#endif

} // namespace fault

} // namespace etiss
