// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <fstream>
#include <iostream>

#include "etiss/ETISS.h"

/**
 * @brief A simple logger dedicated to print PC trace. Most accurate
 *        when etiss.max_block_size in ETISS.ini is set to 1.
 *
 * @param terminateAddr: Terminate simulation when hit certain address
 *
 * @param [Optional] printOnScreen: Print PC on screen if true
 *
 * @param [Optional] terminateAddr:Terminate simulation only when hit
 *		       the address *terminateHit* times.
 *
 */
class TracePrinter : public etiss::CoroutinePlugin
{
  public:
    // ctor
    TracePrinter(etiss::uint32 terminateAddr, bool printOnScreen = false, char terminateHit = 1)
        : CoroutinePlugin(), printOnScreen_(printOnScreen), terminateAddr_(terminateAddr), terminateHit_(terminateHit)
    {
    }

    // dtor
    ~TracePrinter() { printLog(); }

    etiss::int32 execute()
    {
        if (printOnScreen_)
            std::cout << "[INFO] {TracePrinter} : PC = 0x" << std::hex << cpu_->instructionPointer << std::endl;

        pcTrace_ << "[INFO] {TracePrinter}: PC = 0x" << std::hex << cpu_->instructionPointer << std::endl;

        if (this->cpu_->instructionPointer == terminateAddr_)
        {
            if (++hitTimes_ == terminateHit_)
            {
                printLog();
                return etiss::RETURNCODE::CPUTERMINATED;
            }
        }
        return etiss::RETURNCODE::NOERROR;
    }
    std::string _getPluginName() const { return std::string("TracePrinter"); }

    void init(ETISS_CPU *cpu, ETISS_System *system, etiss::CPUArch *arch)
    {
        this->cpu_ = cpu;
        this->system_ = system;
        this->arch_ = arch;
    }

    void cleanup()
    {
        cpu_ = nullptr;
        system_ = nullptr;
        arch_ = nullptr;
    }

  private:
    ETISS_CPU *cpu_;
    ETISS_System *system_;
    etiss::CPUArch *arch_;

    std::stringstream pcTrace_;
    char hitTimes_ = 0;
    bool printOnScreen_;
    const etiss::uint32 terminateAddr_;
    const char terminateHit_;

    void printLog()
    {
        std::ofstream outPcTrace;
        outPcTrace.open("Trace.log");
        outPcTrace << pcTrace_.str();
        outPcTrace.close();
    }
};
