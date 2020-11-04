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

#include <fstream>
#include <iostream>

#include "etiss/ETISS.h"

/**
 * @brief A simple logger dedicated to print PC trace. Most accurate
 *        when Translation::MaxBlockSize in ETISS.int is set to 1.
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
        : terminateAddr_(terminateAddr), printOnScreen_(printOnScreen), terminateHit_(terminateHit), CoroutinePlugin()
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
