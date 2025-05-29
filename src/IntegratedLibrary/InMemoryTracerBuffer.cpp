//
// Created by holaphei on 28/05/25.
//


#include "etiss/IntegratedLibrary/InMemoryTracerBuffer.h"

InMemoryTracerBuffer & InMemoryTracerBuffer::instance() {
    static InMemoryTracerBuffer inst;
    return inst;
}

void InMemoryTracerBuffer::append(const std::string& s) {
    std::lock_guard<std::mutex> lock(mutex_);
    buffer_ << s;
}

std::string InMemoryTracerBuffer::str() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return buffer_.str();
}

extern "C" void InMemoryTracerBuffer_append_entry(const char* s) {
    InMemoryTracerBuffer::instance().append(s);
}
