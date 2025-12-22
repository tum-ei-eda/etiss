/*
        @copyright
        <pre>
        Copyright 2018 Infineon Technologies AG
        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.
        </pre>
        @author Chair of Electronic Design Automation, TUM
        @version 0.1
*/

#include "JITStatsCollector.h"
#include <cmath>
#include <chrono>
#include <iomanip>

#if ETISS_TRANSLATOR_STAT
#include <nlohmann/json.hpp>
using json = nlohmann::json;
#endif

// External function declarations (defined in src/JITStats.cpp, compiled into libETISS.so)
extern "C"
{
    void getJITTranslationStats(uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *,
                                bool *, uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *, uint64_t *);
    void getPerformanceStats(double *, double *, double *, double *, double *, double *);
}

// Helper function to format time in appropriate units
static std::string formatTime(uint64_t time_us)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);

    if (time_us >= 1000000)
    {
        // Show in seconds
        ss << (time_us / 1000000.0) << " s";
    }
    else if (time_us >= 1000)
    {
        // Show in milliseconds
        ss << (time_us / 1000.0) << " ms";
    }
    else
    {
        // Show in microseconds
        ss << time_us << " us";
    }
    return ss.str();
}

static std::string getCurrentFormatttedTimestamp()
{
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::gmtime(&time_t_now), "%Y-%m-%dT%H:%M:%SZ");
    return ss.str();
}

void JITStatsCollector::printStats()
{
    // Export JSON first if requested
    std::string json_path = etiss::cfg().get<std::string>("jit.stats.json_output", "");
    if (!json_path.empty())
    {
        exportJSON(json_path);
    }

    // Print human-readable output
    std::string humanReadable = generateHumanReadable();
    if (printOnScreen_)
    {
        std::cout << humanReadable << std::endl;
    }

    // Write to log file
    std::ofstream outFile(outPath_);
    if (outFile.is_open())
    {
        outFile << humanReadable;
        outFile.close();
        if (!printOnScreen_)
        {
            std::cout << "JIT statistics written to: " << outPath_ << std::endl;
        }
    }
    else
    {
        etiss::log(etiss::WARNING, "Failed to write JIT statistics to file: " + outPath_);
    }
}

std::string JITStatsCollector::generateHumanReadable()
{
    JITTranslationStats stats;
    getJITTranslationStats(&stats.fastJitBlocks, &stats.optimizingJitBlocks, &stats.cacheNextHits,
                           &stats.cacheBranchHits, &stats.cacheMisses, &stats.blocksOptimized, &stats.blocksSwitched,
                           &stats.fastJitEnabled, &stats.totalBlockExecutions, &stats.fastJitExecutions,
                           &stats.optimizedExecutions, &stats.fastJitCompilationTime_us,
                           &stats.optimizingJitCompilationTime_us, &stats.translationTime_us, &stats.blockExecutionTime_ns, &stats.systemTime_ns, &stats.blockLookupTime_ns);

    PerformanceStats perfStats;
    getPerformanceStats(&perfStats.cpuTime_s, &perfStats.simulationTime_s, &perfStats.wallTime_s, &perfStats.cpuCycles,
                        &perfStats.mipsEstimated, &perfStats.mipsCorrected);

    uint64_t totalBlocks = stats.fastJitBlocks + stats.optimizingJitBlocks;
    uint64_t totalCacheHits = stats.cacheNextHits + stats.cacheBranchHits;
    uint64_t totalCacheLookups = totalCacheHits + stats.cacheMisses;
    uint64_t totalCompilationTime_us = stats.fastJitCompilationTime_us + stats.optimizingJitCompilationTime_us;

    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    ss << "========================================\n";
    ss << "ETISS JIT Compilation Statistics\n";
    ss << "========================================\n\n";

    // Performance Summary
    ss << "Performance Summary:\n";
    ss << std::fixed << std::setprecision(4);
    ss << "  CPU Time (simulated): " << perfStats.cpuTime_s << " s\n";
    ss << "  Simulation Time: " << perfStats.simulationTime_s << " s\n";
    ss << "  Wallclock Time: " << perfStats.wallTime_s << " s\n";
    ss << std::scientific << std::setprecision(5);
    ss << "  CPU Cycles: " << perfStats.cpuCycles << "\n";
    ss << std::fixed << std::setprecision(3);
    ss << "  MIPS (estimated): " << perfStats.mipsEstimated << "\n";
    ss << "  MIPS (corrected): " << perfStats.mipsCorrected << "\n\n";

    ss << std::fixed << std::setprecision(2);
    ss << "JIT Configuration:\n";
    ss << "  Fast JIT enabled: " << (stats.fastJitEnabled ? "Yes" : "No") << "\n\n";

    // Compilation Statistics
    ss << "Compilation Statistics:\n";
    ss << "  Unique blocks compiled: " << totalBlocks << "\n";
    if (stats.fastJitEnabled)
    {
        ss << "  - Fast JIT (initial): " << stats.fastJitBlocks;
        if (totalBlocks > 0)
        {
            double pct = (100.0 * stats.fastJitBlocks) / totalBlocks;
            ss << " (" << pct << "%)";
        }
        ss << "\n";
    }
    ss << "  - Optimizing JIT (fallback): " << stats.optimizingJitBlocks;
    if (totalBlocks > 0)
    {
        double pct = (100.0 * stats.optimizingJitBlocks) / totalBlocks;
        ss << " (" << pct << "%)";
    }
    ss << "\n\n";

    // Timing Statistics
    ss << "Timing Statistics:\n";
    ss << "  Total compilation time: " << formatTime(totalCompilationTime_us) << "\n";
    if (stats.fastJitEnabled)
    {
        ss << "  - Fast JIT compilation: " << formatTime(stats.fastJitCompilationTime_us);
        if (stats.fastJitBlocks > 0)
        {
            double avgTime_us = (double)stats.fastJitCompilationTime_us / stats.fastJitBlocks;
            ss << " (avg: " << formatTime((uint64_t)avgTime_us) << "/block)";
        }
        ss << "\n";
    }
    ss << "  - Optimizing JIT compilation: " << formatTime(stats.optimizingJitCompilationTime_us);
    if (stats.blocksOptimized > 0)
    {
        double avgTime_us = (double)stats.optimizingJitCompilationTime_us / stats.blocksOptimized;
        ss << " (avg: " << formatTime((uint64_t)avgTime_us) << "/block)";
    }
    ss << "\n";
    ss << "  Block execution time: " << formatTime(stats.blockExecutionTime_ns / 1000) << "\n";
    ss << "  System sync time: " << formatTime(stats.systemTime_ns / 1000) << "\n";
    ss << "  Block lookup time: " << formatTime(stats.blockLookupTime_ns / 1000) << "\n";

    // Compilation vs Execution breakdown
    double compilationPct = 0.0, translationPct = 0.0, executionPct = 0.0, systemPct = 0.0, lookupPct = 0.0;
    uint64_t totalTime_us = totalCompilationTime_us + stats.translationTime_us + (stats.blockExecutionTime_ns / 1000) + (stats.systemTime_ns / 1000) + (stats.blockLookupTime_ns / 1000);
    if (totalTime_us > 0)
    {
        compilationPct = (100.0 * totalCompilationTime_us) / totalTime_us;
        translationPct = (100.0 * stats.translationTime_us) / totalTime_us;
        executionPct = (100.0 * (stats.blockExecutionTime_ns / 1000.0)) / totalTime_us;
        systemPct = (100.0 * (stats.systemTime_ns / 1000.0)) / totalTime_us;
        lookupPct = (100.0 * (stats.blockLookupTime_ns / 1000.0)) / totalTime_us;
        ss << "  Time breakdown: " << compilationPct << "% compilation, " << translationPct << "% translation, " 
           << executionPct << "% execution, " << systemPct << "% system, " << lookupPct << "% lookup\n";
    }

    // Compilation speedup from fast JIT
    if (stats.fastJitEnabled && stats.fastJitBlocks > 0 && stats.blocksOptimized > 0)
    {
        double avgFastTime = (double)stats.fastJitCompilationTime_us / stats.fastJitBlocks;
        double avgOptTime = (double)stats.optimizingJitCompilationTime_us / stats.blocksOptimized;
        if (avgFastTime > 0)
        {
            double speedup = avgOptTime / avgFastTime;
            ss << "  Fast JIT speedup: " << speedup << "x faster than optimizing JIT\n";
        }
    }
    ss << "\n";

    // Background Optimization
    if (stats.fastJitEnabled && stats.fastJitBlocks > 0)
    {
        ss << "Background Optimization:\n";
        ss << "  Blocks optimized: " << stats.blocksOptimized << " / " << stats.fastJitBlocks;
        double optimizationRate = (100.0 * stats.blocksOptimized) / stats.fastJitBlocks;
        ss << " (" << optimizationRate << "%)\n";

        ss << "  Blocks switched to optimized: " << stats.blocksSwitched;
        if (stats.blocksOptimized > 0)
        {
            double switchRate = (100.0 * stats.blocksSwitched) / stats.blocksOptimized;
            ss << " / " << stats.blocksOptimized << " (" << switchRate << "%)";
        }
        ss << "\n\n";
    }

    // Execution Statistics
    ss << "Execution Statistics:\n";
    ss << "  Total block executions: " << stats.totalBlockExecutions << "\n";
    if (stats.fastJitEnabled && stats.totalBlockExecutions > 0)
    {
        ss << "  - Using Fast JIT version: " << stats.fastJitExecutions;
        double fastPct = (100.0 * stats.fastJitExecutions) / stats.totalBlockExecutions;
        ss << " (" << fastPct << "%)\n";

        ss << "  - Using Optimized version: " << stats.optimizedExecutions;
        double optPct = (100.0 * stats.optimizedExecutions) / stats.totalBlockExecutions;
        ss << " (" << optPct << "%)\n";
    }
    ss << "\n";

    // Cache Performance
    ss << "Cache Performance:\n";
    ss << "  Total cache lookups: " << totalCacheLookups << "\n";
    if (totalCacheLookups > 0)
    {
        ss << "  - Sequential hits (next): " << stats.cacheNextHits;
        double pct = (100.0 * stats.cacheNextHits) / totalCacheLookups;
        ss << " (" << pct << "%)\n";

        ss << "  - Branch hits: " << stats.cacheBranchHits;
        pct = (100.0 * stats.cacheBranchHits) / totalCacheLookups;
        ss << " (" << pct << "%)\n";

        ss << "  - Misses (blockmap lookup): " << stats.cacheMisses;
        pct = (100.0 * stats.cacheMisses) / totalCacheLookups;
        ss << " (" << pct << "%)\n";

        double hitRate = (100.0 * totalCacheHits) / totalCacheLookups;
        ss << "  Cache hit rate: " << hitRate << "%\n";
    }
    else
    {
        ss << "  (Cache statistics require -DETISS_TRANSLATOR_STAT=ON)\n";
    }
    ss << "\n";

    // Hybrid JIT Effectiveness Summary
    if (stats.fastJitEnabled && stats.totalBlockExecutions > 0)
    {
        ss << "Hybrid JIT Effectiveness:\n";
        double optCoverage = (100.0 * stats.optimizedExecutions) / stats.totalBlockExecutions;
        ss << "  Optimization coverage: " << optCoverage << "% of executions\n";

        if (stats.blocksOptimized > 0 && stats.fastJitExecutions > 0)
        {
            // Estimate average executions before optimization kicks in
            double avgExecBeforeOpt = (double)stats.fastJitExecutions / stats.blocksOptimized;
            ss << "  Avg executions before switch: ~" << (uint64_t)avgExecBeforeOpt << "\n";
        }
    }

    ss << "========================================\n";

    return ss.str();
}

#if ETISS_TRANSLATOR_STAT
void JITStatsCollector::exportJSON(const std::string &path)
{
    // Collect all statistics
    JITTranslationStats stats;
    getJITTranslationStats(&stats.fastJitBlocks, &stats.optimizingJitBlocks, &stats.cacheNextHits,
                           &stats.cacheBranchHits, &stats.cacheMisses, &stats.blocksOptimized, &stats.blocksSwitched,
                           &stats.fastJitEnabled, &stats.totalBlockExecutions, &stats.fastJitExecutions,
                           &stats.optimizedExecutions, &stats.fastJitCompilationTime_us,
                           &stats.optimizingJitCompilationTime_us, &stats.translationTime_us, &stats.blockExecutionTime_ns, &stats.systemTime_ns, &stats.blockLookupTime_ns);

    PerformanceStats perfStats;
    getPerformanceStats(&perfStats.cpuTime_s, &perfStats.simulationTime_s, &perfStats.wallTime_s, &perfStats.cpuCycles,
                        &perfStats.mipsEstimated, &perfStats.mipsCorrected);

    // Calculate derived values
    uint64_t totalBlocks = stats.fastJitBlocks + stats.optimizingJitBlocks;
    uint64_t totalCacheHits = stats.cacheNextHits + stats.cacheBranchHits;
    uint64_t totalCacheLookups = totalCacheHits + stats.cacheMisses;
    uint64_t totalCompilationTime_us = stats.fastJitCompilationTime_us + stats.optimizingJitCompilationTime_us;

    double avgFastTime =
        (stats.fastJitBlocks > 0) ? (double)stats.fastJitCompilationTime_us / stats.fastJitBlocks / 1000.0 : 0.0;
    double avgOptTime = (stats.blocksOptimized > 0)
                            ? (double)stats.optimizingJitCompilationTime_us / stats.blocksOptimized / 1000.0
                            : 0.0;
    double speedup = (avgFastTime > 0) ? avgOptTime / avgFastTime : 0.0;

    double hitRate = (totalCacheLookups > 0) ? (100.0 * totalCacheHits) / totalCacheLookups : 0.0;

    double fastExecPct =
        (stats.totalBlockExecutions > 0) ? (100.0 * stats.fastJitExecutions) / stats.totalBlockExecutions : 0.0;
    double optExecPct =
        (stats.totalBlockExecutions > 0) ? (100.0 * stats.optimizedExecutions) / stats.totalBlockExecutions : 0.0;

    double compilationPct = 0.0, translationPct = 0.0, executionPct = 0.0, systemPct = 0.0, lookupPct = 0.0;
    uint64_t totalTime_us = totalCompilationTime_us + stats.translationTime_us + (stats.blockExecutionTime_ns / 1000) + (stats.systemTime_ns / 1000) + (stats.blockLookupTime_ns / 1000);
    if (totalTime_us > 0)
    {
        compilationPct = (100.0 * totalCompilationTime_us) / totalTime_us;
        translationPct = (100.0 * stats.translationTime_us) / totalTime_us;
        executionPct = (100.0 * (stats.blockExecutionTime_ns / 1000.0)) / totalTime_us;
        systemPct = (100.0 * (stats.systemTime_ns / 1000.0)) / totalTime_us;
        lookupPct = (100.0 * (stats.blockLookupTime_ns / 1000.0)) / totalTime_us;
    }

    double optimizationRate = (stats.fastJitBlocks > 0) ? (100.0 * stats.blocksOptimized) / stats.fastJitBlocks : 0.0;
    double switchRate = (stats.totalBlockExecutions > 0) ? (100.0 * stats.blocksSwitched) / stats.totalBlockExecutions : 0.0;

    uint64_t avgExecBeforeSwitch = (stats.blocksOptimized > 0 && stats.fastJitExecutions > 0)
                                       ? stats.fastJitExecutions / stats.blocksOptimized
                                       : 0;

    // Get metadata from ETISS config
    std::string jit_type = etiss::cfg().get<std::string>("jit.type", "unknown");
    std::string fast_jit = etiss::cfg().get<std::string>("jit.fast_type", "");
    int opt_threads = etiss::cfg().get<int>("jit.optimization_threads", 0);
    std::string gcc_opt = etiss::cfg().get<std::string>("jit.gcc.opt_level", "3");
    std::string llvm_opt = etiss::cfg().get<std::string>("jit.llvm.opt_level", "3");
    unsigned block_size = etiss::cfg().get<unsigned>("etiss.max_block_size", 100);

    // Build JSON object
    std::string timestampStr = getCurrentFormatttedTimestamp();
    json j = { { "timestamp", timestampStr },
          { "schema_version", "1.0" },
          { "metadata",
            { { "jit_type", etiss::cfg().get<std::string>("jit.type", "Unknown") },
              { "fast_jit_enabled", stats.fastJitEnabled },
              { "fast_jit_type", etiss::cfg().get<std::string>("jit.fast_type", "None") },
              { "block_size", etiss::cfg().get<int>("jit.block_size", 0) },
              { "optimization_threads", etiss::cfg().get<int>("jit.gcc.threads", 0) },
              { "gcc_opt_level", etiss::cfg().get<std::string>("jit.gcc.opt_level", "0") },
              { "llvm_opt_level", etiss::cfg().get<std::string>("jit.llvm.opt_level", "0") } } },
          { "compilation",
            { { "unique_blocks", stats.fastJitBlocks + stats.optimizingJitBlocks }, // Approx
              { "fast_jit_blocks", stats.fastJitBlocks },
              { "optimizing_jit_blocks", stats.optimizingJitBlocks },
              { "total_time_us", totalCompilationTime_us },
              { "total_time_s", totalCompilationTime_us / 1000000.0 },
              { "fast_jit_time_us", stats.fastJitCompilationTime_us },
              { "fast_jit_time_s", stats.fastJitCompilationTime_us / 1000000.0 },
              { "optimizing_jit_time_us", stats.optimizingJitCompilationTime_us },
              { "optimizing_jit_time_s", stats.optimizingJitCompilationTime_us / 1000000.0 },
              { "avg_fast_jit_time_ms", (stats.fastJitBlocks > 0)
                                            ? (double)stats.fastJitCompilationTime_us / stats.fastJitBlocks / 1000.0
                                            : 0.0 },
              { "avg_optimizing_jit_time_ms", (stats.optimizingJitBlocks > 0)
                                                  ? (double)stats.optimizingJitCompilationTime_us /
                                                        stats.optimizingJitBlocks / 1000.0
                                                  : 0.0 },
              { "fast_jit_speedup", speedup },
              { "compilation_percentage", compilationPct },
              { "translation_percentage", translationPct },
              { "execution_percentage", executionPct },
              { "system_percentage", systemPct },
              { "lookup_percentage", lookupPct },
              { "translation_time_us", stats.translationTime_us },
              { "translation_time_s", stats.translationTime_us / 1000000.0 } } },
          { "execution",
            { { "total_block_executions", stats.totalBlockExecutions },
              { "fast_jit_executions", stats.fastJitExecutions },
              { "optimized_executions", stats.optimizedExecutions },
              { "fast_jit_exec_percentage", fastExecPct },
              { "optimized_exec_percentage", optExecPct },
              { "block_execution_time_us", stats.blockExecutionTime_ns / 1000.0 },
              { "block_execution_time_ns", stats.blockExecutionTime_ns },
              { "block_execution_time_ms", stats.blockExecutionTime_ns / 1000000.0 },
              { "system_time_us", stats.systemTime_ns / 1000.0 },
              { "system_time_ns", stats.systemTime_ns },
              { "system_time_ms", stats.systemTime_ns / 1000000.0 },
              { "block_lookup_time_us", stats.blockLookupTime_ns / 1000.0 },
              { "block_lookup_time_ns", stats.blockLookupTime_ns },
              { "block_lookup_time_ms", stats.blockLookupTime_ns / 1000000.0 } } },
          { "optimization",
            { { "blocks_optimized", stats.blocksOptimized },
              { "blocks_switched", stats.blocksSwitched },
              { "optimization_success_rate", optimizationRate },
              { "switch_rate", switchRate },
              { "avg_executions_before_switch",
                (stats.blocksSwitched > 0) ? stats.fastJitExecutions / stats.blocksSwitched : 0 } } },
          { "cache",
            { { "total_hits", stats.cacheNextHits + stats.cacheBranchHits },
              { "sequential_hits", stats.cacheNextHits },
              { "branch_hits", stats.cacheBranchHits },
              { "misses", stats.cacheMisses },
              { "total_lookups", totalCacheLookups },
              { "hit_rate", hitRate },
              { "miss_rate", 100.0 - hitRate } } },
          { "performance",
            { { "wall_time_s", perfStats.wallTime_s },
              { "cpu_time_s", perfStats.cpuTime_s },
              { "simulation_time_s", perfStats.simulationTime_s },
              { "cpu_cycles", perfStats.cpuCycles },
              { "mips_estimated", perfStats.mipsEstimated },
              { "mips_corrected", perfStats.mipsCorrected } } } };

    // Write to file with pretty printing
    std::ofstream file(path);
    if (file.is_open())
    {
        file << std::setw(2) << j << std::endl;
        file.close();
    }
    else
    {
        etiss::log(etiss::ERROR, "Failed to write JIT statistics JSON to: " + path);
    }
}
#else
void JITStatsCollector::exportJSON(const std::string &path)
{
    // Stub implementation when ETISS_TRANSLATOR_STAT is disabled
    etiss::log(etiss::WARNING, "JSON export requested but ETISS_TRANSLATOR_STAT is disabled");
}
#endif
