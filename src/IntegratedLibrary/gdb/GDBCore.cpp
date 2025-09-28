// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/gdb/GDBCore.h

        @detail

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <streambuf>
#include <boost/filesystem.hpp>

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include "etiss/Misc.h"

using namespace etiss::plugin::gdb;

GDBCore::~GDBCore() {}
std::string GDBCore::mapRegister(unsigned index)
{
    return "";
}
unsigned GDBCore::mapRegister(std::string name)
{
    return INVALIDMAPPING;
}
unsigned GDBCore::mappedRegisterCount()
{
    return 0;
}
bool GDBCore::isLittleEndian()
{
    return false;
}
etiss::uint64 GDBCore::getInstructionPointer(ETISS_CPU *cpu)
{
    return cpu->instructionPointer;
}


std::string getXMLDirectory(std::string archName) {
    std::string xmlDir = etiss::installDir() + "/xml/" + archName;
    return xmlDir;
}

std::string GDBCore::getXMLContents(ETISS_CPU *cpu, std::string archName, std::string fname)
{
    // std::vector<std::string> xmlFiles = getXMLFilePaths(archName);
    // TODO: use boost fs paths?
    std::string xmlFile = getXMLDirectory(archName) + "/" + fname;
    if (!boost::filesystem::exists(xmlFile)) {
        // TODO: log warning
        return "";
    }
    std::ifstream t(xmlFile);
    std::string xmlContent((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    return xmlContent;
}
