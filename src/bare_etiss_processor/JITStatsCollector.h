/*
        @copyright
        <pre>
        Copyright 2018 Infineon Technologies AG
        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.
        </pre>
        @author Chair of Electronic Design Automation, TUM
        @version 0.1
*/

#ifndef JIT_STATS_COLLECTOR_H
#define JIT_STATS_COLLECTOR_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include "etiss/ETISS.h"
#include "etiss/Plugin.h"
#include "etiss/jit/ReturnCode.h"

// Statistics structure - matches what Translation exports
struct JITTranslationStats
{
    uint64_t fastJitBlocks;
    uint64_t optimizingJitBlocks;
    uint64_t cacheNextHits;
    uint64_t cacheBranchHits;
    uint64_t cacheMisses;
    uint64_t blocksOptimized;
    uint64_t blocksSwitched;
    bool fastJitEnabled;
    // Execution statistics
    uint64_t totalBlockExecutions;
    uint64_t fastJitExecutions;
    uint64_t optimizedExecutions;
    // Timing statistics (in microseconds)
    uint64_t fastJitCompilationTime_us;
    uint64_t optimizingJitCompilationTime_us;
    uint64_t blockExecutionTime_us;
};

// Performance metrics structure
struct PerformanceStats
{
    double cpuTime_s;
    double simulationTime_s;
    double wallTime_s;
    double cpuCycles;
    double mipsEstimated;
    double mipsCorrected;
};

/**
 * @brief Plugin to collect and report statistics about JIT compilation and block caching.
 *
 * Tracks:
 * - Fast JIT compilations
 * - Optimizing JIT compilations
 * - Cache hits (next, branch, miss)
 * - Blocks optimized in background
 * - Blocks that switched from fast to optimized version
 *
 * @param [Optional] print: Print stats on screen
 * @param [Optional] out_path: Location of final stats file
 */
class JITStatsCollector : public etiss::CoroutinePlugin
{
  public:
    // ctor
    JITStatsCollector(bool print = true, std::string out_path = "./JITStats.log")
        : printOnScreen_(print), outPath_(out_path)
    {
    }

    // dtor
    ~JITStatsCollector() { printStats(); }

    etiss::int32 execute() override
    {
        // This plugin just collects stats, doesn't need per-block execution
        return etiss::RETURNCODE::NOERROR;
    }

    std::string _getPluginName() const override { return std::string("JITStatsCollector"); }

    void init(ETISS_CPU *cpu, ETISS_System *system, etiss::CPUArch *arch) override
    {
        this->cpu_ = cpu;
        this->system_ = system;
        this->arch_ = arch;
    }

    void cleanup() override
    {
        cpu_ = nullptr;
        system_ = nullptr;
        arch_ = nullptr;
    }

    void executionEnd(int32_t code) override
    {
        // Don't print stats here - Translation destructor hasn't run yet to export final stats.
        // Stats will be printed in destructor after Translation exports final stats.
    }

  private:
    ETISS_CPU *cpu_ = nullptr;
    ETISS_System *system_ = nullptr;
    etiss::CPUArch *arch_ = nullptr;

    bool printOnScreen_;
    std::string outPath_;

    void printStats();
    void exportJSON(const std::string &path);
    std::string generateHumanReadable();
};

#endif // JIT_STATS_COLLECTOR_H
