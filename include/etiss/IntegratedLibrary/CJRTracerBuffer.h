//
// Created by holaphei on 28/05/25.
//

#ifndef CJRTRACERBUFFER_H
#define CJRTRACERBUFFER_H

#include <sstream>
#include <string>
#include <mutex>

class CJRTracerBuffer {
public:
    static CJRTracerBuffer& instance();

    void append(const std::string& s);
    std::string str() const;

private:
    mutable std::mutex mutex_;
    std::ostringstream buffer_;
};

extern "C" void CJRTracer_append_entry(const char* s);

#endif //CJRTRACERBUFFER_H
