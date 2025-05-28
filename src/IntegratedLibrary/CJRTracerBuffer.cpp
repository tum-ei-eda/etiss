//
// Created by holaphei on 28/05/25.
//


#include "etiss/IntegratedLibrary/CJRTracerBuffer.h"

CJRTracerBuffer& CJRTracerBuffer::instance() {
    static CJRTracerBuffer inst;
    return inst;
}

void CJRTracerBuffer::append(const std::string& s) {
    std::lock_guard<std::mutex> lock(mutex_);
    buffer_ << s;
}

std::string CJRTracerBuffer::str() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return buffer_.str();
}

extern "C" void CJRTracer_append_entry(const char* s) {
    CJRTracerBuffer::instance().append(s);
}
