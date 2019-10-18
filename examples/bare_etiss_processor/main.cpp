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

#include "TracePrinter.h"
#include "etiss/DebugSystem.h"
#include "etiss/ETISS.h"

int main(int argc, const char *argv[])
{
    // by default etiss wil search for plugin libraries in its install path and
    // relative to the library using the file plugins/list.txt.
    // For loading configurations and ETISS internal plug-ins you can add a list
    // with .ini file to the Initializer. See ETISS.ini for more details. Ini
    // files and All configurations can be set with program arguments, too. E.g.:
    // ./main [-o<option> <value>] [-f[no]<flag>] [-i<additionalinifile>]
    // All arguments with this format will be evaluated by the Initializer.
    std::cout << "=== Setting up configurations ===" << std::endl;
    std::list<std::string> iniFiles;
    // iniFiles.push_back("../ETISS.ini"); // will be loaded within the run.sh
    // iniFiles.push_back("additional.ini");
    etiss::Initializer initializer(&iniFiles, argc, argv);
    std::cout << "=== Finished setting up configurations ===" << std::endl << std::endl;

    // if a custom library need to be added or etiss failed to find libraries then
    // they can be added manually. the library name must be given without the lib
    // prefix or the .so suffix:
    // etiss::loadLibrary("/path/to/library","LibraryName");

    // if a plugin library is not part of a shared library or the shared library
    // is already loaded then a plugin library can be added like this:
    // std::shared_ptr<etiss::LibraryInterface> mylib
    // = std::shared_ptr<etiss::LibraryInterface>(new MyLib());
    // etiss::addLibrary(mylib);

	uint32_t ROM_START = 0x0;
	uint32_t ROM_SIZE = 4096*1024;
	uint32_t RAM_SIZE = 1024*1024;
	
    std::cout << "=== Setting up test system ===" << std::endl;
    std::cout << "  Setting up Memory" << std::endl;
    etiss::DebugSystem dsys(ROM_START, ROM_SIZE, ROM_START+ROM_SIZE, RAM_SIZE);
    // load image to memory
    //  if(!dsys.load(0,etiss::cfg().get<std::string>("sw_binary","").c_str())){
    //    etiss::log(etiss::FATALERROR,"Could not load image file "
    //        + etiss::cfg().get<std::string>("sw_binary","")
    //        + std::string(" check the config sw_binary in ../ETISS.ini!"),
    //        ETISS_SRCLOC);
    //  }

    if (!dsys.loadRom(etiss::cfg().get<std::string>("sw_binary_rom", "").c_str()) ||
        !dsys.loadRam(etiss::cfg().get<std::string>("sw_binary_ram", "").c_str()))
    {
        etiss::log(etiss::FATALERROR, "ram/rom not loaded properly\n");
    }

    // can be used to write a small assembler programm beginning at address 0
    if (false)
    {
        std::list<etiss::uint32> instructions;
        {
            instructions.push_back(0x80b584b0); //	push	{r7, lr},	sub	sp, #16
        }
        // write instructions into debug system
        unsigned pos = 0;
        for (auto it_instr : instructions)
        {
            etiss::uint8 buf[4];
            buf[0] = it_instr >> 24;
            buf[1] = it_instr >> 16;
            buf[2] = it_instr >> 8;
            buf[3] = it_instr;
            dsys.dbg_write(pos, buf, 4);
            pos += 4;
        }
    }

    std::cout << "  Setting up CPUCore" << std::endl;
    // create a cpu core named core0 with the or1k architecture
    std::string CPUArchName = etiss::cfg().get<std::string>("CPUArch", "");
    etiss::uint64 startAddress = 0x0;
    switch ((char)CPUArchName.c_str()[0])
    {
    case (char)'o':
        startAddress = 0x100;
        break;
    case (char)'A':
        startAddress = 0x68;
        break;
    // TODO: For RISCV, MSTATUS register has to be configured in advance to
    // support interrupt.
    case (char)'R':
        startAddress = 0x80;
        break;
    }

    std::shared_ptr<etiss::CPUCore> cpu = etiss::CPUCore::create(CPUArchName, "core0");
    if (!cpu)
    {
        etiss::log(etiss::ERROR, "failed to create cpu core");
        return -1;
    }

    // disable timer plugin
    cpu->setTimer(false);

    // reset CPU with a manual start address
    etiss::uint64 sa = startAddress; // Where should PC pointer at beginning is
                                     // dependent layout of boot code
    cpu->reset(&sa);

    // add the virtual structure of the cpu to the VirtualStruct root. This allows
    // to access the field of the cpu from a global context. See
    // etiss::VirtualStruct::getVirtualStruct() and
    // etiss::VirtualStruct::getResolvedField(). In this case e.g. the
    // instructionPointer can be read from a global context by calling
    // etiss::VirtualStruct::root()->getResolvedField("core0.instructionPointer")
    // ->read().
    etiss::VirtualStruct::root()->mountStruct("core0", cpu->getStruct());
    std::cout << "=== Finished Setting up test system ===" << std::endl << std::endl;

    std::cout << "=== Setting up plug-ins ===" << std::endl;
    initializer.loadIniPlugins(cpu);
    initializer.loadIniJIT(cpu);
    // here own developped plug-ins can be added with:
    // cpu->addPlugin(std::shared_ptr<etiss::Plugin>(new TracePrinter(0x88888)));
    std::cout << "=== Setting up plug-ins ===" << std::endl << std::endl;

    // Simulation start
    std::cout << std::endl << "=== Simulation start ===" << std::endl;
    // run cpu with the DebugSystem (in other cases that "system" is most likely a
    // bus that connects the cpu to memory,periphery,etc)
    etiss_int32 exception = cpu->execute(dsys);
    std::cout << "=== Simulation end ===" << std::endl << std::endl;

    // print the exception code returned by the cpu core
    std::cout << "CPU0 exited with exception: 0x" << std::hex << exception << std::dec << ": "
              << etiss::RETURNCODE::getErrorMessages()[exception] << std::endl;
}
