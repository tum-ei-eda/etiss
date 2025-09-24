// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/VirtualStruct.h"

namespace etiss
{

static void parseName(const char *cname, const int baseflags, unsigned &flags, std::string &name_)
{
    flags = 0;

    if (!cname)
        etiss::log(etiss::FATALERROR, "fix VirtualStruct::allocateFromC", ETISS_SRCLOC);

    std::string name(cname);
    size_t ppos = name.find('.');
    if (ppos == std::string::npos)
    {
        etiss::log(etiss::WARNING,
                   "etiss::VirtualStruct::allocateFromC encountered an invalid field name. flags cannot be parsed and "
                   "will be set to private. check the documentation of VirtualStruct_names for the propper syntax",
                   name);
        flags = etiss::VirtualStruct::Field::P;
        name_ = name;
        return;
    }
}

std::shared_ptr<VirtualStruct> VirtualStruct::allocateFromC(
    void *handle, VirtualStruct_names names, VirtualStruct_prettyNames prettyNames_optional,
    VirtualStruct_read read_recommended, VirtualStruct_write write_optional,
    VirtualStruct_setListenerCallback setListenerCallback_optional, std::function<void(void *handle)> cleanup)
{
    const int baseflags = (read_recommended ? etiss::VirtualStruct::Field::R : 0) |
                          (write_optional ? etiss::VirtualStruct::Field::W : 0) |
                          (setListenerCallback_optional ? etiss::VirtualStruct::Field::L : 0) |
                          etiss::VirtualStruct::Field::P;

    if (!names)
    {
        etiss::log(etiss::ERROR, "VirtualStruct::allocateFromC: names cannot be 0");
        return std::shared_ptr<VirtualStruct>();
    }

    bool handle_deleted = false;
    std::shared_ptr<VirtualStruct> ret = allocate(handle, [handle_deleted, handle, cleanup](Field *f) mutable {
        if (!handle_deleted)
        {
            handle_deleted = true;
            cleanup(handle);
        }
        delete f;
    });

    size_t apos = 0;
    const char *const *name_array = names(handle);
    // const char * const * pname_array = names(handle);

    while (name_array[apos] != 0)
    {
        unsigned flags;
        std::string name;
        parseName(name_array[apos], baseflags, flags, name);
        /// TODO
    }

    return ret;
}

} // namespace etiss
