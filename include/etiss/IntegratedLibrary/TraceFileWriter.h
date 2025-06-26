#ifndef TRACEFILEWRITER_H
#define TRACEFILEWRITER_H

#include <fstream>
#include <mutex>
#include <string>
#include <cstdio>  // For std::remove

struct StateSnapshotEntry {
    uint32_t type;        // 1 for state snapshot
    uint32_t pc;
    uint32_t sp;
    uint32_t x[32];
    uint64_t f[32];
    char instruction[16];  // Fixed size
};

struct DWriteEntry {
    uint32_t type;        // 2 for dwrite
    uint32_t pc;
    uint64_t addr;
    uint32_t length;
    uint8_t data[64];      // Max length
};

class TraceFileWriter {
public:
    static TraceFileWriter& instance(const std::string& output_path = "trace.bin");

    void writeStateSnapshot(const StateSnapshotEntry& entry);
    void writeDWrite(const DWriteEntry& entry);
    void setTracing(bool active);
    bool isTracing() const;

private:
    TraceFileWriter() = default;
    ~TraceFileWriter();

    TraceFileWriter(const TraceFileWriter&) = delete;
    TraceFileWriter& operator=(const TraceFileWriter&) = delete;

    void openFile(const std::string& output_path);

    std::ofstream outfile_;
    std::mutex mutex_;
    bool trace_active_ = false;
};

#endif // TRACEFILEWRITER_H
