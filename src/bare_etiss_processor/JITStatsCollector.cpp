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

// External function declarations (defined in src/JITStats.cpp, compiled into libETISS.so)
extern "C" {
    void getJITTranslationStats(uint64_t*, uint64_t*, uint64_t*, uint64_t*, uint64_t*, uint64_t*, uint64_t*, bool*,
                                uint64_t*, uint64_t*, uint64_t*,
                                uint64_t*, uint64_t*, uint64_t*);
    void getPerformanceStats(double*, double*, double*, double*, double*, double*);
}

// Helper function to format time in appropriate units
static std::string formatTime(uint64_t time_us)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(3);
    
    if (time_us >= 1000000) {
        // Show in seconds
        ss << (time_us / 1000000.0) << " s";
    } else if (time_us >= 1000) {
        // Show in milliseconds
        ss << (time_us / 1000.0) << " ms";
    } else {
        // Show in microseconds
        ss << time_us << " us";
    }
    return ss.str();
}

void JITStatsCollector::printStats()
{
    JITTranslationStats stats;
    getJITTranslationStats(
        &stats.fastJitBlocks,
        &stats.optimizingJitBlocks,
        &stats.cacheNextHits,
        &stats.cacheBranchHits,
        &stats.cacheMisses,
        &stats.blocksOptimized,
        &stats.blocksSwitched,
        &stats.fastJitEnabled,
        &stats.totalBlockExecutions,
        &stats.fastJitExecutions,
        &stats.optimizedExecutions,
        &stats.fastJitCompilationTime_us,
        &stats.optimizingJitCompilationTime_us,
        &stats.blockExecutionTime_us
    );
    
    PerformanceStats perfStats;
    getPerformanceStats(
        &perfStats.cpuTime_s,
        &perfStats.simulationTime_s,
        &perfStats.wallTime_s,
        &perfStats.cpuCycles,
        &perfStats.mipsEstimated,
        &perfStats.mipsCorrected
    );
    
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
    if (stats.fastJitEnabled) {
        ss << "  - Fast JIT (initial): " << stats.fastJitBlocks;
        if (totalBlocks > 0) {
            double pct = (100.0 * stats.fastJitBlocks) / totalBlocks;
            ss << " (" << pct << "%)";
        }
        ss << "\n";
    }
    ss << "  - Optimizing JIT (fallback): " << stats.optimizingJitBlocks;
    if (totalBlocks > 0) {
        double pct = (100.0 * stats.optimizingJitBlocks) / totalBlocks;
        ss << " (" << pct << "%)";
    }
    ss << "\n\n";
    
    // Timing Statistics
    ss << "Timing Statistics:\n";
    ss << "  Total compilation time: " << formatTime(totalCompilationTime_us) << "\n";
    if (stats.fastJitEnabled) {
        ss << "  - Fast JIT compilation: " << formatTime(stats.fastJitCompilationTime_us);
        if (stats.fastJitBlocks > 0) {
            double avgTime_us = (double)stats.fastJitCompilationTime_us / stats.fastJitBlocks;
            ss << " (avg: " << formatTime((uint64_t)avgTime_us) << "/block)";
        }
        ss << "\n";
    }
    ss << "  - Optimizing JIT compilation: " << formatTime(stats.optimizingJitCompilationTime_us);
    if (stats.blocksOptimized > 0) {
        double avgTime_us = (double)stats.optimizingJitCompilationTime_us / stats.blocksOptimized;
        ss << " (avg: " << formatTime((uint64_t)avgTime_us) << "/block)";
    }
    ss << "\n";
    ss << "  Block execution time: " << formatTime(stats.blockExecutionTime_us) << "\n";
    
    // Compilation vs Execution breakdown
    if (stats.blockExecutionTime_us > 0 || totalCompilationTime_us > 0) {
        uint64_t totalTime_us = totalCompilationTime_us + stats.blockExecutionTime_us;
        if (totalTime_us > 0) {
            double compPct = (100.0 * totalCompilationTime_us) / totalTime_us;
            double execPct = (100.0 * stats.blockExecutionTime_us) / totalTime_us;
            ss << "  Time breakdown: " << compPct << "% compilation, " << execPct << "% execution\n";
        }
    }
    
    // Compilation speedup from fast JIT
    if (stats.fastJitEnabled && stats.fastJitBlocks > 0 && stats.blocksOptimized > 0) {
        double avgFastTime = (double)stats.fastJitCompilationTime_us / stats.fastJitBlocks;
        double avgOptTime = (double)stats.optimizingJitCompilationTime_us / stats.blocksOptimized;
        if (avgFastTime > 0) {
            double speedup = avgOptTime / avgFastTime;
            ss << "  Fast JIT speedup: " << speedup << "x faster than optimizing JIT\n";
        }
    }
    ss << "\n";
    
    // Background Optimization
    if (stats.fastJitEnabled && stats.fastJitBlocks > 0) {
        ss << "Background Optimization:\n";
        ss << "  Blocks optimized: " << stats.blocksOptimized << " / " << stats.fastJitBlocks;
        double optimizationRate = (100.0 * stats.blocksOptimized) / stats.fastJitBlocks;
        ss << " (" << optimizationRate << "%)\n";
        
        ss << "  Blocks switched to optimized: " << stats.blocksSwitched;
        if (stats.blocksOptimized > 0) {
            double switchRate = (100.0 * stats.blocksSwitched) / stats.blocksOptimized;
            ss << " / " << stats.blocksOptimized << " (" << switchRate << "%)";
        }
        ss << "\n\n";
    }
    
    // Execution Statistics
    ss << "Execution Statistics:\n";
    ss << "  Total block executions: " << stats.totalBlockExecutions << "\n";
    if (stats.fastJitEnabled && stats.totalBlockExecutions > 0) {
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
    if (totalCacheLookups > 0) {
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
    } else {
        ss << "  (Cache statistics require -DETISS_TRANSLATOR_STAT=ON)\n";
    }
    ss << "\n";
    
    // Hybrid JIT Effectiveness Summary
    if (stats.fastJitEnabled && stats.totalBlockExecutions > 0) {
        ss << "Hybrid JIT Effectiveness:\n";
        double optCoverage = (100.0 * stats.optimizedExecutions) / stats.totalBlockExecutions;
        ss << "  Optimization coverage: " << optCoverage << "% of executions\n";
        
        if (stats.blocksOptimized > 0 && stats.fastJitExecutions > 0) {
            // Estimate average executions before optimization kicks in
            double avgExecBeforeOpt = (double)stats.fastJitExecutions / stats.blocksOptimized;
            ss << "  Avg executions before switch: ~" << (uint64_t)avgExecBeforeOpt << "\n";
        }
    }
    
    ss << "========================================\n";
    
    if (printOnScreen_) {
        std::cout << ss.str() << std::endl;
    }
    
    // Write to file
    std::ofstream outFile(outPath_);
    if (outFile.is_open()) {
        outFile << ss.str();
        outFile.close();
        if (!printOnScreen_) {
            std::cout << "JIT statistics written to: " << outPath_ << std::endl;
        }
    } else {
        etiss::log(etiss::WARNING, "Failed to write JIT statistics to file: " + outPath_);
    }
}
