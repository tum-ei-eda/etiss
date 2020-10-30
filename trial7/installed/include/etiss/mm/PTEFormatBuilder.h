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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @date June 24, 2018

        @version 0.1

*/

#ifndef ETISS_INCLUDE_MM_PTEFORMATBUILDER_H_
#define ETISS_INCLUDE_MM_PTEFORMATBUILDER_H_

#include <iostream>
#include <map>
#include <memory>

#include "etiss/mm/PTEFormat.h"

namespace etiss
{
namespace mm
{

/**
 *	@brief Sigleton builder utility to build up customized PTE format
 */
class PTEFormatBuilder
{
  public:
    /**
     *	@brief Get the singleton instance
     */
    static PTEFormatBuilder &Instance()
    {
        static std::shared_ptr<PTEFormatBuilder> builder(new PTEFormatBuilder((PTEFormat::Instance())));
        return *builder;
    }

    /**
     *	@brief Add mandatory bit field, Physical Page Number (PPN), for PTE
     */
    PTEFormatBuilder &AddPPNBitField(uint32_t begin, uint32_t end)
    {
        format_.AddBitField("PPN", begin, end);
        return *this;
    }

    /**
     *	@brief Add mandatory bit field for page size offset (Not included in PTE neither
     *   		in PTE format)
     */
    PTEFormatBuilder &AddPageOffset(uint32_t begin, uint32_t end)
    {
        format_.AddBitField("PAGEOFFSET", begin, end);
        return *this;
    }

    /**
     *	@brief Add optional bit field for protection flag in PTE
     */
    PTEFormatBuilder &AddFlag(std::string name, uint32_t begin, uint32_t end)
    {
        format_.AddBitField(name, begin, end);
        return *this;
    }

    /**
     *	@brief Add optional bit field for protection flag in PTE
     */
    PTEFormatBuilder &AddFlag(std::string name, uint32_t pos)
    {
        format_.AddBitField(name, pos, pos);
        return *this;
    }

  private:
    PTEFormatBuilder(PTEFormat &format) : format_(format) {}

    PTEFormat &format_;

    friend class PTEFormat;
};

} // namespace mm
} // namespace etiss

#endif
