//
// Created by holaphei on 28/05/25.
//

#ifndef CJRTRACERBUFFER_H
#define CJRTRACERBUFFER_H

#include <sstream>
#include <string>
#include <mutex>

class InMemoryTracerBuffer {
public:
    static InMemoryTracerBuffer& instance();

    void append(const std::string& s);
    void setTrace(bool);
    bool isTracing() const;
    std::string str() const;

private:
    mutable std::mutex mutex_;
    std::ostringstream buffer_;
    bool traceActivated_ = false;
};

extern "C" void InMemoryTracerBuffer_append_entry(const char* s);

#endif //CJRTRACERBUFFER_H
