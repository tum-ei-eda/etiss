#ifndef TRACEFILEWRITER_H
#define TRACEFILEWRITER_H

#include <fstream>
#include <mutex>
#include <string>
#include <cstdint>
#include <type_traits>

#pragma pack(push, 1)

struct StateSnapshotEntry {
    uint32_t type;        // 1 for state snapshot
    uint32_t pc;
    uint32_t sp;
    uint32_t x[32];
    uint64_t f[32];
    char instruction[16];  // Fixed size
};

#pragma pack(pop)

// Static size check
static_assert(sizeof(StateSnapshotEntry) == 412, "StateSnapshotEntry size must be 412 bytes");

#pragma pack(push, 1)

struct DWriteEntry {
    uint32_t type;        // 2 for dwrite
    uint32_t pc;
    uint64_t addr;
    uint32_t length;
    uint8_t data[64];     // Max length
};

#pragma pack(pop)

// Static size check
static_assert(sizeof(DWriteEntry) == 84, "DWriteEntry size must be 84 bytes");


class TraceFileWriter {
public:
    static TraceFileWriter& instance(const std::string& output_path = "trace.bin");

    void writeStateSnapshot(const StateSnapshotEntry& entry);
    void writeDWrite(const DWriteEntry& entry);

    // Trace control
    void activateTrace();
    void deactivateTrace();
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
