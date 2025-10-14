// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <boost/program_options.hpp>
#include "TracePrinter.h"
#include "etiss/SimpleMemSystem.h"
#include "etiss/IntegratedLibrary/fault/MemoryManipulationSystem.h"
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
    // std::list<std::string> iniFiles;
    // iniFiles.push_back("../ETISS.ini"); // will be loaded within the run.sh
    // iniFiles.push_back("additional.ini");
    etiss::Initializer initializer(
        argc, argv); // add &iniFiles as the first argument if .ini files are loaded explicitly here
    bool quiet = etiss::cfg().get<bool>("vp.quiet", false);
    if (!quiet)
        std::cout << "=== Finished setting up configurations ===" << std::endl << std::endl;

    if (!quiet)
        std::cout << "=== Setting up test system ===" << std::endl;
    if (!quiet)
        std::cout << "  Setting up Memory" << std::endl;

    bool is_fault_injection = !(etiss::cfg().get<std::string>("faults.xml", "")).empty();

    std::shared_ptr<etiss::SimpleMemSystem> dsys;
    if (is_fault_injection)
    {
        dsys = std::make_shared<etiss::MemoryManipulationSystem>();
    }
    else
    {
        dsys = std::make_shared<etiss::SimpleMemSystem>();
    }
    dsys->init_memory();

    if (!etiss::cfg().isSet("arch.cpu"))
    {
        std::cout << "  CPU architecture was not set anywhere! Please set it manually using the arch.cpu configuration "
                     "option!";
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
            dsys->dbg_write(pos, buf, 4);
            pos += 4;
        }
    }

    if (!quiet)
        std::cout << "  Setting up CPUCore" << std::endl;
    // create a cpu core named core0 with the or1k architecture
    std::string CPUArchName = etiss::cfg().get<std::string>("arch.cpu", "");
    etiss::uint64 sa = etiss::cfg().get<uint64_t>("vp.entry_point", dsys->get_startaddr());
    if (!quiet)
        std::cout << "  CPU start address: 0x" << std::hex << sa << std::dec << std::endl;

    std::shared_ptr<etiss::CPUCore> cpu = etiss::CPUCore::create(CPUArchName, "core0");
    if (!cpu)
    {
        etiss::log(etiss::FATALERROR, "  Failed to create CPU core!");
    }

    // disable timer plugin
    cpu->setTimer(false);
    std::string progname = etiss::cfg().get<std::string>("vp.progname", "prog");
    std::string cmdline = etiss::cfg().get<std::string>("vp.cmdline", "");
    std::vector<std::string> args =
        boost::program_options::split_unix(progname + " " + cmdline);

    std::cout << "argc = " << args.size() << "\n";
    for (size_t i = 0; i < args.size(); i++) {
        std::cout << "argv[" << i << "] = " << args[i] << "\n";
    }
    int vp_argc = static_cast<int>(args.size());
    std::vector<char*> vp_argv;

    vp_argv.reserve(vp_argc + 1);
    for (auto &s : args) {
        vp_argv.push_back(const_cast<char*>(s.c_str()));
    }
    vp_argv.push_back(nullptr); // argv[argc] = NULL

    // reset CPU with a manual start address
    // cpu->reset(&sa, static_cast<ETISS_System*>(&(*dsys)), vp_argc, vp_argv.data());
    cpu->reset(&sa);

    // bind the cpu's VirtualStruct to etiss' root VirtualStruct and initialize faults
    // if those where specified in config/cmdline
    if (is_fault_injection)
    {
        dynamic_cast<etiss::MemoryManipulationSystem &>(*dsys).init_manipulation(cpu);

        etiss::initialize_virtualstruct(
            cpu,
            [](const etiss::fault::Fault &fault, const etiss::fault::Action &action, std::string &errormsg)
            {
                auto cmd = action.getCommand();
                std::cout << "custom command: " << cmd << std::endl;
                return true;
            });
    }
    else
    {
        etiss::initialize_virtualstruct(cpu);
    }
    if (!quiet)
        std::cout << "=== Finished Setting up test system ===" << std::endl << std::endl;

    if (!quiet)
        std::cout << "=== Setting up plug-ins ===" << std::endl;

    auto irq_handler = std::make_shared<etiss::InterruptHandler>(cpu->getInterruptVector(), cpu->getInterruptEnable(),
                                                                 cpu->getArch(), etiss::LEVEL_TRIGGERED, false);
    cpu->addPlugin(irq_handler);

    initializer.loadIniPlugins(cpu);
    initializer.loadIniJIT(cpu);
    // here own developped plug-ins can be added with:
    if (etiss::cfg().get<bool>("etiss.log_pc", false))
    {
        etiss::cfg().set<int>("etiss.max_block_size", 1);
        cpu->addPlugin(std::make_shared<TracePrinter>(0x88888));
    }

    if (!quiet)
        std::cout << "=== Setting up plug-ins ===" << std::endl << std::endl;

    // Simulation start
    if (!quiet)
        std::cout << std::endl << "=== Simulation start ===" << std::endl;
    // float startTime = (float)clock() / CLOCKS_PER_SEC; // TESTING
    //  run cpu with the SimpleMemSystem (in other cases that "system" is most likely a
    //  bus that connects the cpu to memory,periphery,etc)
    etiss_int32 exception = cpu->execute(*dsys, vp_argc, vp_argv.data());
    // float endTime = (float)clock() / CLOCKS_PER_SEC;
    if (!quiet)
        std::cout << "=== Simulation end ===" << std::endl << std::endl;

    // print the exception code returned by the cpu core
    if (!quiet)
        std::cout << "CPU0 exited with exception: 0x" << std::hex << exception << std::dec << ": "
                  << etiss::RETURNCODE::getErrorMessages()[exception] << std::endl;

    // Exit codes:
    //  0: Success
    //  1: System error?
    //  2: JIT error
    //  3: Other?
    //  4: CPU reports non-zero SW exit
    // -1: Unhandeled ETISS exception
    switch (exception)
    {
    case etiss::RETURNCODE::CPUFINISHED:
    {
        etiss_uint8 exit_status = cpu->getState()->exit_status & 0xff;  // UNIX exit codes are 0..255
        if (etiss::cfg().get<bool>("vp.print_exit_status", true))
        {
            std::cout << "CPU0 exit status: " << (etiss_uint32)exit_status << std::endl;
        }
        if (etiss::cfg().get<bool>("vp.check_exit_status", true))
        {
            if (etiss::cfg().get<bool>("vp.forward_exit_status", false))
            {
                return exit_status;
            }
            return exit_status != 0 ? 4 : 0;
        }
        return 0;
        break;
    }
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
