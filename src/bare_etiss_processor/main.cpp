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

#include "TracePrinter.h"
#include "etiss/SimpleMemSystem.h"
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
    //std::list<std::string> iniFiles;
    // iniFiles.push_back("../ETISS.ini"); // will be loaded within the run.sh
    // iniFiles.push_back("additional.ini");
    etiss::Initializer initializer(argc, argv); //add &iniFiles as the first argument if .ini files are loaded explicitly here
    std::cout << "=== Finished setting up configurations ===" << std::endl << std::endl;

    std::cout << "=== Setting up test system ===" << std::endl;
    std::cout << "  Setting up Memory" << std::endl;

    etiss::SimpleMemSystem dsys;
    dsys.init_memory();

    if (!etiss::cfg().isSet("arch.cpu")) {
        std::cout << "  CPU architecture was not set anywhere! Please set it manually using the arch.cpu configuration option!";
        return 3;
    }

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
    std::string CPUArchName = etiss::cfg().get<std::string>("arch.cpu", "");
    etiss::uint64 sa = etiss::cfg().get<uint64_t>("vp.entry_point", dsys.get_startaddr());
	std::cout << "  CPU start address: 0x" << std::hex << sa << std::dec << std::endl;
    std::shared_ptr<etiss::CPUCore> cpu = etiss::CPUCore::create(CPUArchName, "core0");
    if (!cpu)
    {
        etiss::log(etiss::FATALERROR, "  Failed to create CPU core!");
    }

    // disable timer plugin
    cpu->setTimer(false);

    // reset CPU with a manual start address
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
    if (etiss::cfg().get<bool>("etiss.log_pc", false)) {
      etiss::cfg().set<int>("etiss.max_block_size", 1);
      cpu->addPlugin(std::shared_ptr<etiss::Plugin>(new TracePrinter(0x88888)));
    }

    std::cout << "=== Setting up plug-ins ===" << std::endl << std::endl;

    // Simulation start
    std::cout << std::endl << "=== Simulation start ===" << std::endl;
    //float startTime = (float)clock() / CLOCKS_PER_SEC; // TESTING
    // run cpu with the SimpleMemSystem (in other cases that "system" is most likely a
    // bus that connects the cpu to memory,periphery,etc)
    etiss_int32 exception = cpu->execute(dsys);
    //float endTime = (float)clock() / CLOCKS_PER_SEC;
    std::cout << "=== Simulation end ===" << std::endl << std::endl;


    // print the exception code returned by the cpu core
    std::cout << "CPU0 exited with exception: 0x" << std::hex << exception << std::dec << ": "
              << etiss::RETURNCODE::getErrorMessages()[exception] << std::endl;


    switch(exception){
        case etiss::RETURNCODE::CPUFINISHED:
        case etiss::RETURNCODE::NOERROR:
        case etiss::RETURNCODE::CPUTERMINATED:
        return 0;
        break;
        case etiss::RETURNCODE::DBUS_READ_ERROR:
        case etiss::RETURNCODE::DBUS_WRITE_ERROR:
        case etiss::RETURNCODE::IBUS_READ_ERROR:
        case etiss::RETURNCODE::IBUS_WRITE_ERROR:
        case etiss::RETURNCODE::INTERRUPT:
        case etiss::RETURNCODE::RESET:
        case etiss::RETURNCODE::ILLEGALINSTRUCTION:
        case etiss::RETURNCODE::ILLEGALJUMP:
        case etiss::RETURNCODE::INSTR_PAGEFAULT:
        case etiss::RETURNCODE::LOAD_PAGEFAULT:
        case etiss::RETURNCODE::STORE_PAGEFAULT:
        case etiss::RETURNCODE::GDBNOERROR:
        case etiss::RETURNCODE::SYSCALL:
        case etiss::RETURNCODE::PAGEFAULT:
        return 1;
        break;
        case etiss::RETURNCODE::JITERROR:
        case etiss::RETURNCODE::JITCOMPILATIONERROR:
        return 2;
        break;
        case etiss::RETURNCODE::GENERALERROR:
        case etiss::RETURNCODE::RELOADBLOCKS:
        case etiss::RETURNCODE::RELOADCURRENTBLOCK:
        case etiss::RETURNCODE::BREAKPOINT:
        case etiss::RETURNCODE::ARCHERROR:
        case etiss::RETURNCODE::EMULATIONNOTSUPPORTED:
        case etiss::RETURNCODE::INVALIDSYSTEM:
        return 3;
        break;
        default:
        return -1;
        break;
    }
}


