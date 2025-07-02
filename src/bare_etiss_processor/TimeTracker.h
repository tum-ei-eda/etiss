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

#include <fstream>
#include <iostream>

#include "etiss/ETISS.h"

/**
 * @brief A simple logger dedicated to keep track of simulation time per block.
 *
 * @param [Optional] print: Print times on screen
 *
 * @param [Optional] out_path: Location of final log file
 *
 * @param [Optional] resolution: Only sample blocks after min number of instrs
 *
 */
class TimeTracker : public etiss::CoroutinePlugin
{
  public:
    // ctor
    TimeTracker(bool print = false, std::string out_path = "./TimeTracker.log", int resolution = 1000)
        : CoroutinePlugin(), printOnScreen_(print), outPath_(out_path), minDelta_(resolution)
    {
    }

    // dtor
    ~TimeTracker() { printLog(); }

    etiss::int32 execute()
    {
        etiss::uint64 instr_cnt = cpu_->cpuTime_ps / cpu_->cpuCycleTime_ps;
        etiss::uint64 delta = instr_cnt - instr_cnt_old_;
        if (delta < minDelta_) {
            return etiss::RETURNCODE::NOERROR;
        }
        struct timespec cur;
        clock_gettime(CLOCK_MONOTONIC, &cur);
        double wall_time = (cur.tv_sec - start.tv_sec) + (cur.tv_nsec - start.tv_nsec) / 1000000000.0;
        std::stringstream ss;
        ss << "" << instr_cnt << "," << std::setprecision(10) << wall_time << "\n";
        if (printOnScreen_) {
            std::stringstream ss2;
            ss2 << "Instr Count = " << instr_cnt << ", Wall Time = " << std::setprecision(10) << wall_time << std::endl;
            etiss::log(etiss::INFO, "{TimeTracker} : " + ss2.str());
        }

        outTrace_ << ss.str();
        instr_cnt_old_ = instr_cnt;

        return etiss::RETURNCODE::NOERROR;
    }
    std::string _getPluginName() const { return std::string("TracePrinter"); }

    void init(ETISS_CPU *cpu, ETISS_System *system, etiss::CPUArch *arch)
    {
        this->cpu_ = cpu;
        this->system_ = system;
        this->arch_ = arch;
        clock_gettime(CLOCK_MONOTONIC, &start);
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

    std::stringstream outTrace_;
    bool printOnScreen_;
    struct timespec start;
    std::string outPath_;
    etiss::uint64 minDelta_;
    etiss::uint64 instr_cnt_old_ = 0;

    void printLog()
    {
        std::ofstream outTrace;
        outTrace.open(outPath_);
        outTrace << "instr_cnt,time\n";
        outTrace << outTrace_.str();
        outTrace.close();
    }
};
