/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "etiss/VirtualStruct.h"

namespace etiss
{

VirtualStruct::Field::Listener::~Listener() {}

VirtualStruct::Field::Field(VirtualStruct &parent, const std::string &name, const std::string &prettyname, int flags,
                            size_t width, size_t bitwidth)
    : parent_(parent)
    , name_(name)
    , prettyname_(prettyname)
    , flags_(flags)
    , width_(width)
    , bitwidth_((bitwidth == 0) ? width * 8 : bitwidth_)
    , accessMode_(VirtualStruct::Field::VIRTUAL)
{
}

VirtualStruct::Field::Field(VirtualStruct &parent, const std::string &name, const std::string &prettyname, int flags,
                            size_t width, bool virtual_enabled, std::function<uint64_t()> lread,
                            std::function<void(uint64_t)> lwrite, size_t bitwidth)
    : parent_(parent)
    , name_(name)
    , prettyname_(prettyname)
    , flags_(flags)
    , width_(width)
    , bitwidth_((bitwidth == 0) ? width * 8 : bitwidth_)
    , accessMode_(virtual_enabled ? VirtualStruct::Field::PREFER_LAMBDA : VirtualStruct::Field::LAMBDA)
    , lread(lread)
    , lwrite(lwrite)
{
}

VirtualStruct::Field::~Field() {}

uint64_t VirtualStruct::Field::read() const
{

    if (!(flags_ & R))
        std::runtime_error("VirtualStruct::Field::write called but the write flag is not set");

    uint64_t ret;
    switch (accessMode_)
    {
    case LAMBDA:
        if (lread)
        {
            ret = lread();
        }
        else
        {
            throw std::runtime_error(
                "VirtualStruct is configured to use lambda expressions but no read function was provided.");
        }
        break;
    case PREFER_LAMBDA:
        if (lread)
        {
            ret = lread();
            break;
        }
    case VIRTUAL:
        ret = _read();
        break;
    default:
        throw std::runtime_error("invalid enum value");
    }
    // call listeners

    return ret;
}
void VirtualStruct::Field::write(uint64_t val)
{

    if (!(flags_ & W))
        throw std::runtime_error("VirtualStruct::Field::write called but the write flag is not set");

    if (accessMode_ == LAMBDA && !lwrite) // throw error before calling listeners
        throw std::runtime_error(
            "VirtualStruct is configured to use lambda expressions but no read function was provided.");

    switch (accessMode_)
    {
    case LAMBDA:
        if (lwrite)
        {
            lwrite(val);
        }
        else
        {
            // throw std::runtime_error("VirtualStruct is configured to use lambda expressions but no read function was
            // provided."); moved to start of function
        }
        break;
    case PREFER_LAMBDA:
        if (lwrite)
        {
            lwrite(val);
            break;
        }
    case VIRTUAL:
        _write(val);
        break;
    }

    signalWrite();
}

void VirtualStruct::Field::signalWrite()
{
    for (auto l : listeners)
    {
        if (l.first)
        {
            l.first->write(*this, read());
        }
    }
}

bool VirtualStruct::Field::applyBitflip(unsigned position, uint64_t fault_id)
{
    if (!(flags_ & F))
        return false;

    switch (accessMode_)
    {
    case LAMBDA:
    case PREFER_LAMBDA:
    case VIRTUAL:
        return _applyBitflip(position, fault_id);
    }
    return false;
}

bool VirtualStruct::Field::applyAction(const etiss::fault::Fault &f, const etiss::fault::Action &a,
                                       std::string &errormsg)
{
    if (!(flags_ & A))
    {
        errormsg = "field doesn't support advanced action handling";
        return false;
    }
    return _applyAction(f, a, errormsg);
}

uint64_t VirtualStruct::Field::_read() const
{
    throw std::runtime_error("VirtualStruct::Field::_read called but not implemented");
}
void VirtualStruct::Field::_write(uint64_t)
{
    throw std::runtime_error("VirtualStruct::Field::_write called but not implemented");
}
bool VirtualStruct::Field::_applyBitflip(unsigned position, uint64_t fault_id)
{
    if (!(flags_ & F))
        return false;
    if (lapplyBitflip)
        return lapplyBitflip(position, fault_id);
    if ((flags_ & RW) != RW)
        return false;
    uint64_t val = read();
    uint64_t errval = ((uint64_t)1) << position;
    errval = val ^ errval;
    write(errval);
    std::stringstream ss;
    ss << "Injected bitflip in " << name_ << " 0x" << std::hex << val << "->0x" << errval << std::dec;
    etiss::log(etiss::INFO, ss.str());
    return true;
}
bool VirtualStruct::Field::_applyAction(const etiss::fault::Fault &f, const etiss::fault::Action &a,
                                        std::string &errormsg)
{
    return false;
}

bool VirtualStruct::Field::addListener(Listener *listener, std::shared_ptr<Listener> ref)
{
    if (!(flags_ & Field::L))
        return false;
    listeners.insert(std::pair<Listener *, std::shared_ptr<Listener>>(listener, ref));
    return true;
}
void VirtualStruct::Field::removeListener(Listener *listener, std::shared_ptr<Listener> ref)
{
    listeners.erase(std::pair<Listener *, std::shared_ptr<Listener>>(listener, ref));
}

VirtualStruct::VirtualStruct(void *structure, std::function<void(Field *)> dtor)
    : structure_(structure), dtor_(dtor), closed(false)
{
}
VirtualStruct::~VirtualStruct()
{
    close(); // VSSync is locked in close. IF THIS CHANGES VSSync MUST BE INSTANTIATED HERE
    for (auto iter = fields_.begin(); iter != fields_.end(); ++iter)
    {
        if (*iter)
        {
            if ((*iter)->delete_)
            {
                std::function<void(Field *)> del_ = (*iter)->delete_;
                del_(*iter);
            }
            else
            {
                if (dtor_)
                {
                    dtor_(*iter);
                }
                else
                {
                    etiss::log(etiss::ERROR, "The delete function passed to etiss::VirtualStruct is null. This will "
                                             "likely result in a memory leak.");
                }
            }
        }
    }
}

bool VirtualStruct::addField(VirtualStruct::Field *f, bool noerrorprint)
{

    if (f == 0)
    {
        if (!noerrorprint)
            etiss::log(etiss::VERBOSE, "NULL pointer passed to etiss::VirtualStruct::addField", ETISS_SRCLOC);
        return false;
    }

    if (f->name_.empty())
    {
        if (!noerrorprint)
            etiss::log(etiss::ERROR, "Failed to add an field to etiss::VirtualStruct due to empty name", f->name_,
                       f->prettyname_, ETISS_SRCLOC);
        return false;
    }
    if (fieldNames_.find(f->name_) != fieldNames_.end())
    {
        if (!noerrorprint)
            etiss::log(etiss::ERROR, "Failed to add an field to etiss::VirtualStruct due to duplicated name", f->name_,
                       f->prettyname_, ETISS_SRCLOC);
        return false;
    }
    if ((!f->prettyname_.empty()) && (fieldPrettyNames_.find(f->prettyname_) != fieldPrettyNames_.end()))
    {
        if (!noerrorprint)
            etiss::log(etiss::ERROR, "Failed to add an field to etiss::VirtualStruct due to duplicated prettyname",
                       f->name_, f->prettyname_, ETISS_SRCLOC);
        return false;
    }

    fields_.push_back(f);
    fieldNames_.insert(std::make_pair(f->name_, f));
    if (!f->prettyname_.empty())
        fieldPrettyNames_.insert(std::make_pair(f->prettyname_, f));
    return true;
}

std::shared_ptr<VirtualStruct::Field> VirtualStruct::findName(const std::string &name) const
{
    VSSync lock;
    if (closed)
        return 0;

    auto find = fieldNames_.find(name);
    if (find != fieldNames_.end())
    {
        std::shared_ptr<const VirtualStruct> pref = shared_from_this();
        return std::shared_ptr<VirtualStruct::Field>(find->second, [pref](VirtualStruct::Field *) {});
    }
    return std::shared_ptr<VirtualStruct::Field>();
}
std::shared_ptr<VirtualStruct::Field> VirtualStruct::findPrettyName(const std::string &name) const
{
    VSSync lock;
    if (closed)
        return 0;
    auto find = fieldPrettyNames_.find(name);
    if (find != fieldPrettyNames_.end())
    {
        std::shared_ptr<const VirtualStruct> pref = shared_from_this();
        return std::shared_ptr<VirtualStruct::Field>(find->second, [pref](VirtualStruct::Field *) {});
    }
    return 0;
}
void VirtualStruct::foreachField(const std::function<void(std::shared_ptr<Field>)> &func)
{
    VSSync lock;
    if (closed)
        return;
    std::shared_ptr<const VirtualStruct> pref = shared_from_this();
    for (Field *f : fields_)
    {
        func(std::shared_ptr<Field>(f, [pref](VirtualStruct::Field *) {}));
    }
}
bool VirtualStruct::acceleratedTrigger(const etiss::fault::Trigger &t, int32_t fault_id)
{
    if (acceleratedTrigger_)
    {
        return acceleratedTrigger_(t, fault_id);
    }
    else
    {
    }
    return false;
}
bool VirtualStruct::mountStruct(const std::string &name, std::shared_ptr<VirtualStruct> vs)
{
    if (!vs)
        return false;
    VSSync lock;
    // check for existing
    {
        auto find = subStructs_.find(name);
        if (find != subStructs_.end())
        {
            if (find->second.lock())
            {
                return false;
            }
        }
    }
    if (vs->parent_) // already mounted elsewere
        return false;
    vs->parent_ = shared_from_this();
    subStructs_.insert(std::pair<std::string, std::weak_ptr<VirtualStruct>>(name, vs));
    return true;
}
std::shared_ptr<VirtualStruct> VirtualStruct::findStruct(const std::string &name)
{
    VSSync lock;
    auto find = subStructs_.find(name);
    if (find != subStructs_.end())
        return find->second.lock();
    return std::shared_ptr<VirtualStruct>();
}
void VirtualStruct::foreachStruct(const std::function<void(const std::string &name, VirtualStruct &vs)> &func)
{
    VSSync lock;
    for (auto e : subStructs_)
    {
        auto sp = e.second.lock();
        auto p = sp.get();
        if (p)
        {
            func(e.first, *p);
        }
    }
}

void VirtualStruct::close()
{
    VSSync lock;
    closed = true;
    // dont't delete fields here.
}
bool VirtualStruct::isClosed()
{
    VSSync lock;
    return closed;
}

std::list<std::string> VirtualStruct::listFields()
{
    std::list<std::string> ret;
    foreachField([&ret](std::shared_ptr<Field> f) {
        if (f)
            ret.push_back(f->name_);
    });
    return ret;
}
std::list<std::string> VirtualStruct::listSubInjectors()
{
    std::list<std::string> ret;
    foreachStruct([&ret](const std::string &name, VirtualStruct &vs) { ret.push_back(name); });
    return ret;
}

std::shared_ptr<etiss::fault::Injector> VirtualStruct::getSubInjector(const std::string &name)
{
    return findStruct(name);
}
std::shared_ptr<etiss::fault::Injector> VirtualStruct::getParentInjector()
{
    return parent_;
}

void *VirtualStruct::fastFieldAccessPtr(const std::string &name, std::string &errormsg)
{
    VSSync lock;
    {
        auto iter = fieldNames_.find(name);
        if (iter != fieldNames_.end())
            return iter->second;
    }
    {
        auto iter = fieldPrettyNames_.find(name);
        if (iter != fieldPrettyNames_.end())
            return iter->second;
    }
    return 0;
}
bool VirtualStruct::readField(void *fastfieldaccessptr, uint64_t &val, std::string &errormsg)
{
    Field *f = (Field *)fastfieldaccessptr;
    if (!f)
    {
        errormsg = "No such field";
        return false;
    }
    if (!(f->flags_ & Field::R))
    {
        errormsg = "No read access";
        return false;
    }
    val = f->read();
    return true;
}
bool VirtualStruct::applyAction(const etiss::fault::Fault &fault, const etiss::fault::Action &action,
                                std::string &errormsg)
{
    switch (action.getType())
    {
    case etiss::fault::Action::COMMAND: // handle command
    {
        if (!applyCustomAction)
        {
            errormsg = getInjectorPath() +
                       ": VirtualStruct::applyCustomAction function not set. cannot handle custom actions.";
            return false;
        }
        else
        {
            return applyCustomAction(fault, action, errormsg);
        }
    }
        return false;
    case etiss::fault::Action::BITFLIP: // handle bitflip
    {
        Field *f;
        auto find = fieldNames_.find(action.getTargetField());
        if (find == fieldNames_.end())
        {
            find = fieldPrettyNames_.find(action.getTargetField());
            if (find == fieldPrettyNames_.end())
            {
                f = 0;
            }
            else
            {
                f = find->second;
            }
        }
        else
        {
            f = find->second;
        }

        if (!f)
        {
            errormsg = std::string("No such field: ") + getInjectorPath() + "." + action.getTargetField();
            return false;
        }
        if (f->flags_ & Field::A)
        {
            return f->applyAction(fault, action, errormsg);
        }
        else if (f->flags_ & Field::F)
        {
            return f->applyBitflip(action.getTargetBit(), fault.id_);
        }
    }
        return false;
    }
    return false;
}

VSSync::VSSync()
{
    mutex().lock();
}
VSSync::~VSSync()
{
    mutex().unlock();
}
std::recursive_mutex &VSSync::mutex()
{
    static std::recursive_mutex mu;
    return mu;
}

void copy(VirtualStruct &dst, VirtualStruct &src, std::list<std::shared_ptr<VirtualStruct::Field>> &notPresent,
          std::list<std::shared_ptr<VirtualStruct::Field>> &notWriteable,
          std::list<std::shared_ptr<VirtualStruct::Field>> unknown, bool pretend,
          std::list<std::shared_ptr<VirtualStruct::Field>> *src_private,
          std::list<std::shared_ptr<VirtualStruct::Field>> *dst_private)
{

    []() {}();

    std::set<std::shared_ptr<VirtualStruct::Field>> dst_known;

    src.foreachField([&](std::shared_ptr<VirtualStruct::Field> srcf) {
        if (srcf->flags_ & VirtualStruct::Field::P)
        {
            if (src_private)
                src_private->push_back(srcf);
            return;
        }

        auto dstf = dst.findName(srcf->name_);
        if (dstf == 0)
        {
            notPresent.push_back(srcf);
            return;
        }

        if (dstf->flags_ & VirtualStruct::Field::P)
        {
            notPresent.push_back(srcf);
            return;
        }

        dst_known.insert(dstf);

        if (!(dstf->flags_ & VirtualStruct::Field::W))
        {
            notWriteable.push_back(dstf);
            return;
        }

        if (!pretend)
            dstf->write(srcf->read()); // copy value
    });

    dst.foreachField([&](std::shared_ptr<VirtualStruct::Field> dstf) {
        if (dst_known.find(dstf) == dst_known.end())
        {
            if (dstf->flags_ & VirtualStruct::Field::P)
            {
                if (dst_private)
                {
                    dst_private->push_back(dstf);
                }
            }
            else
            {
                unknown.push_back(dstf);
            }
        }
    });
}

std::shared_ptr<VirtualStruct> VirtualStruct::allocate(void *structure, std::function<void(Field *)> delete_)
{
    VirtualStruct *ret = new VirtualStruct(structure, delete_);

    return std::shared_ptr<VirtualStruct>(ret, [](VirtualStruct *vs) { delete vs; });
}

std::shared_ptr<VirtualStruct> VirtualStruct::root()
{
    static std::shared_ptr<VirtualStruct> r = allocate(0, [](Field *) {});
    return r;
}

std::shared_ptr<VirtualStruct> VirtualStruct::getVirtualStruct(const std::string &path)
{
    if (path.empty())
        return shared_from_this();
    std::shared_ptr<VirtualStruct> ret;
    if (path.find_first_of(".") != std::string::npos)
    {
        // error
        return ret;
    }
    auto pp1 = path.find("::");

    if (pp1 == 0) // absolute path
    {
        auto ptr = parent_;
        auto prev = shared_from_this();
        while (ptr)
        {
            prev = ptr;
            ptr = ptr->parent_;
        }
        return prev->getVirtualStruct(path.substr(pp1 + 2));
    }

    {
        VSSync lock;
        auto find = subStructs_.find((pp1 == std::string::npos) ? path : path.substr(0, pp1));
        if (find != subStructs_.end())
        {
            ret = find->second.lock();
        }
    }

    if (!ret)
        return ret;

    if (pp1 == std::string::npos)
    {
        return ret;
    }
    else
    {
        return ret->getVirtualStruct(path.substr(pp1 + 2));
    }
}

std::shared_ptr<etiss::fault::Injector> etiss::fault::Injector::get(const std::string &path)
{
    return std::shared_ptr<etiss::fault::Injector>(VirtualStruct::root()->getVirtualStruct(path));
}

std::shared_ptr<VirtualStruct::Field> VirtualStruct::getResolvedField(const std::string &path)
{
    auto pp1 = path.find_first_of(".");
    if (pp1 == std::string::npos) // if no point exists the this is not a path
        return std::shared_ptr<VirtualStruct::Field>();

    auto m = getVirtualStruct(path.substr(0, pp1));
    if (!m)
        return std::shared_ptr<VirtualStruct::Field>();

    auto ret = m->findName(path.substr(pp1 + 1));
    if (!ret)
        ret = m->findPrettyName(path.substr(pp1 + 1));

    return ret;
}

} // namespace etiss
