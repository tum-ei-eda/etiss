/*
        @copyright
        <pre>
        Copyright 2018 Infineon Technologies AG
        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.
        </pre>
        @author Chair of Electronic Design Automation, TUM
        @version 0.1
*/

#if ETISS_TRANSLATOR_STAT

#include <mutex>
#include <cstdint>
#include <atomic>

// Statistics structure - matches what JITStatsCollector uses
struct JITTranslationStats {
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
    // Timing statistics (in microseconds, except blockExecutionTime which is nanoseconds to avoid precision loss)
    uint64_t fastJitCompilationTime_us;
    uint64_t optimizingJitCompilationTime_us;
    uint64_t translationTime_us;
    uint64_t blockExecutionTime_ns; // Changed from us to ns
    uint64_t systemTime_ns;
    uint64_t blockLookupTime_ns; // Time spent looking up blocks in cache
    uint64_t totalTime_ns; // Total simulation loop time
    // Performance metrics (from CPUCore)
    double cpuTime_s;
    double simulationTime_s;
    double wallTime_s;
    double cpuCycles;
    double mipsEstimated;
    double mipsCorrected;
};

// Global stats storage (thread-safe access)
static JITTranslationStats g_jitStats = {0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
static std::mutex g_jitStatsMutex;

// Atomic accumulator for block execution time (updated frequently from hot path)
static std::atomic<uint64_t> g_blockExecutionTime_ns{0};
static std::atomic<uint64_t> g_systemTime_ns{0};
static std::atomic<uint64_t> g_blockLookupTime_ns{0};
std::atomic<uint64_t> g_totalTime_ns{0};
 // Changed to ns

// Function to add block execution time (called from CPUCore after each block)
extern "C" void addBlockExecutionTime(uint64_t time_ns) // Changed input to ns
{
    g_blockExecutionTime_ns.fetch_add(time_ns, std::memory_order_relaxed);
}

extern "C" void addSystemTime(uint64_t time_ns)
{
    g_systemTime_ns.fetch_add(time_ns, std::memory_order_relaxed);
}

extern "C" void addBlockLookupTime(uint64_t time_ns)
{
    g_blockLookupTime_ns.fetch_add(time_ns, std::memory_order_relaxed);
}

// Function to update stats (called from Translation.cpp destructor)
extern "C" void updateJITTranslationStats(
    uint64_t fastJit, uint64_t optJit, uint64_t next, 
    uint64_t branch, uint64_t miss, uint64_t optimized, 
    uint64_t switched, bool fastEnabled,
    uint64_t totalExec, uint64_t fastExec, uint64_t optExec,
    uint64_t fastJitCompTime_us, uint64_t optJitCompTime_us, uint64_t translationTime_us, uint64_t blockExecTime_ns) // Changed to ns
{
    std::lock_guard<std::mutex> lock(g_jitStatsMutex);
    g_jitStats.fastJitBlocks = fastJit;
    g_jitStats.optimizingJitBlocks = optJit;
    g_jitStats.cacheNextHits = next;
    g_jitStats.cacheBranchHits = branch;
    g_jitStats.cacheMisses = miss;
    g_jitStats.blocksOptimized = optimized;
    g_jitStats.blocksSwitched = switched;
    g_jitStats.fastJitEnabled = fastEnabled;
    g_jitStats.totalBlockExecutions = totalExec;
    g_jitStats.fastJitExecutions = fastExec;
    g_jitStats.optimizedExecutions = optExec;
    g_jitStats.fastJitCompilationTime_us = fastJitCompTime_us;
    g_jitStats.optimizingJitCompilationTime_us = optJitCompTime_us;
    g_jitStats.translationTime_us = translationTime_us;
    // Use the atomic accumulator for execution time if passed value is 0
    // (Translation doesn't have execution time, CPUCore updates it via addBlockExecutionTime)
    g_jitStats.blockExecutionTime_ns = (blockExecTime_ns > 0) ? blockExecTime_ns : g_blockExecutionTime_ns.load();
    g_jitStats.systemTime_ns = g_systemTime_ns.load();
    g_jitStats.blockLookupTime_ns = g_blockLookupTime_ns.load();
}

// Function to get stats (called from JITStatsCollector plugin)
extern "C" void getJITTranslationStats(
    uint64_t* fastJit, uint64_t* optJit, uint64_t* next, 
    uint64_t* branch, uint64_t* miss, uint64_t* optimized, 
    uint64_t* switched, bool* fastEnabled,
    uint64_t* totalExec, uint64_t* fastExec, uint64_t* optExec,
    uint64_t *fastJitCompTime_us, uint64_t *optJitCompTime_us, uint64_t *translationTime_us, uint64_t *blockExecTime_ns, uint64_t *systemTime_ns, uint64_t *blockLookupTime_ns)
{
    std::lock_guard<std::mutex> lock(g_jitStatsMutex);
    if (fastJit) *fastJit = g_jitStats.fastJitBlocks;
    if (optJit) *optJit = g_jitStats.optimizingJitBlocks;
    if (next) *next = g_jitStats.cacheNextHits;
    if (branch) *branch = g_jitStats.cacheBranchHits;
    if (miss) *miss = g_jitStats.cacheMisses;
    if (optimized) *optimized = g_jitStats.blocksOptimized;
    if (switched) *switched = g_jitStats.blocksSwitched;
    if (fastEnabled) *fastEnabled = g_jitStats.fastJitEnabled;
    if (totalExec) *totalExec = g_jitStats.totalBlockExecutions;
    if (fastExec) *fastExec = g_jitStats.fastJitExecutions;
    if (optExec) *optExec = g_jitStats.optimizedExecutions;
    if (fastJitCompTime_us) *fastJitCompTime_us = g_jitStats.fastJitCompilationTime_us;
    if (optJitCompTime_us) *optJitCompTime_us = g_jitStats.optimizingJitCompilationTime_us;
    if (translationTime_us) *translationTime_us = g_jitStats.translationTime_us;
    if (blockExecTime_ns) *blockExecTime_ns = g_jitStats.blockExecutionTime_ns;
    if (systemTime_ns) *systemTime_ns = g_jitStats.systemTime_ns;
    if (blockLookupTime_ns) *blockLookupTime_ns = g_jitStats.blockLookupTime_ns;
}

// Function to update performance metrics (called from CPUCore after simulation)
extern "C" void updatePerformanceStats(
    double cpuTime_s, double simulationTime_s, double wallTime_s,
    double cpuCycles, double mipsEstimated, double mipsCorrected)
{
    std::lock_guard<std::mutex> lock(g_jitStatsMutex);
    g_jitStats.cpuTime_s = cpuTime_s;
    g_jitStats.simulationTime_s = simulationTime_s;
    g_jitStats.wallTime_s = wallTime_s;
    g_jitStats.cpuCycles = cpuCycles;
    g_jitStats.mipsEstimated = mipsEstimated;
    g_jitStats.mipsCorrected = mipsCorrected;
}

// Function to get performance metrics (called from JITStatsCollector plugin)
extern "C" void getPerformanceStats(
    double* cpuTime_s, double* simulationTime_s, double* wallTime_s,
    double* cpuCycles, double* mipsEstimated, double* mipsCorrected)
{
    std::lock_guard<std::mutex> lock(g_jitStatsMutex);
    if (cpuTime_s) *cpuTime_s = g_jitStats.cpuTime_s;
    if (simulationTime_s) *simulationTime_s = g_jitStats.simulationTime_s;
    if (wallTime_s) *wallTime_s = g_jitStats.wallTime_s;
    if (cpuCycles) *cpuCycles = g_jitStats.cpuCycles;
    if (mipsEstimated) *mipsEstimated = g_jitStats.mipsEstimated;
    if (mipsCorrected) *mipsCorrected = g_jitStats.mipsCorrected;
}

#endif // ETISS_TRANSLATOR_STAT
