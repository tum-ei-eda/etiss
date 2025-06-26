//
// Created by holaphei on 28/05/25.
//

#include "etiss/ETISS.h"
#include "etiss/IntegratedLibrary/InMemoryTracerBuffer.h"

InMemoryTracerBuffer & InMemoryTracerBuffer::instance(const std::string &output_path) {
    static InMemoryTracerBuffer inst;
    static bool initialized = false;

    if (!initialized) {
        // Remove old file if it exists
        if (std::ifstream(output_path)) {
            if (std::remove(output_path.c_str()) == 0) {
                etiss::log(etiss::INFO, "InMemoryTracerBuffer: Old output file '" + output_path + "' deleted at startup.");
            } else {
                etiss::log(etiss::WARNING, "InMemoryTracerBuffer: Failed to delete old output file '" + output_path + "'.");
            }
        }

        inst.outfile.open(output_path, std::ios::out | std::ios::trunc);
        if (!inst.outfile) {
            etiss::log(etiss::ERROR, "InstructionTracer: cannot open output file '" + output_path + '\'');
        }
        inst.output_path_ = output_path;
        initialized = true;
    }

    return inst;
}

InMemoryTracerBuffer::~InMemoryTracerBuffer()
{
    if (outfile.is_open()) {
        outfile.close();
    }
}

void InMemoryTracerBuffer::append(const std::string& s) {
    std::lock_guard<std::mutex> lock(mutex_);
    outfile << s;
}

void InMemoryTracerBuffer::setTrace(bool is_active)
{
    traceActivated_ = is_active;
}



bool InMemoryTracerBuffer::isTracing() const
{
    return traceActivated_;
}

std::string InMemoryTracerBuffer::str() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return buffer_.str();
}

void InMemoryTracerBuffer::writeToDisk(const std::string& s)
{
    std::lock_guard<std::mutex> guard(mutex_);
    std::cout << s.c_str();
    outfile << s;
}


extern "C" void InMemoryTracerBuffer_append_entry(const char* s) {
    InMemoryTracerBuffer::instance().writeToDisk(s);
}
