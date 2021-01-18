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
