#include "etiss/IntegratedLibrary/TraceFileWriter.h"
#include "etiss/ETISS.h"

TraceFileWriter& TraceFileWriter::instance(const std::string& output_path) {
    static TraceFileWriter inst;
    static bool initialized = false;

    if (!initialized) {
        inst.openFile(output_path);
        initialized = true;
    }


    return inst;
}

void TraceFileWriter::openFile(const std::string& output_path) {
    // Delete old file if it exists
    if (std::ifstream(output_path)) {
        if (std::remove(output_path.c_str()) == 0) {
            etiss::log(etiss::INFO, "TraceFileWriter: Old output file '" + output_path + "' deleted at startup.");
        } else {
            etiss::log(etiss::WARNING, "TraceFileWriter: Failed to delete old output file '" + output_path + "'.");
        }
    }

    outfile_.open(output_path, std::ios::binary | std::ios::out | std::ios::trunc);
    if (!outfile_) {
        etiss::log(etiss::ERROR, "TraceFileWriter: Cannot open output file '" + output_path + '\'');
    }
}

TraceFileWriter::~TraceFileWriter() {
    if (outfile_.is_open()) {
        outfile_.close();
    }
}

void TraceFileWriter::writeStateSnapshot(const StateSnapshotEntry& entry) {
    if (!trace_active_) return;

    std::lock_guard<std::mutex> lock(mutex_);
    outfile_.write(reinterpret_cast<const char*>(&entry), sizeof(entry));
}

void TraceFileWriter::writeDWrite(const DWriteEntry& entry) {
    if (!trace_active_) return;

    std::lock_guard<std::mutex> lock(mutex_);
    outfile_.write(reinterpret_cast<const char*>(&entry), sizeof(entry));
}

void TraceFileWriter::activateTrace() {
    etiss::log(etiss::INFO, "TraceFileWriter: Trace activated.");
    trace_active_ = true;
}

void TraceFileWriter::deactivateTrace() {
    etiss::log(etiss::INFO, "TraceFileWriter: Trace deactivated.");
    trace_active_ = false;
}

bool TraceFileWriter::isTracing() const {
    return trace_active_;
}
