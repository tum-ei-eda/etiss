// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
