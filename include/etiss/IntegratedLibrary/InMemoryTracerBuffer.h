//
// Created by holaphei on 28/05/25.
//

#ifndef CJRTRACERBUFFER_H
#define CJRTRACERBUFFER_H

#include <fstream>
#include <sstream>
#include <string>
#include <mutex>

class InMemoryTracerBuffer {
public:
    static InMemoryTracerBuffer& instance(const std::string &output_path = "snapshot-activity.log");
    ~InMemoryTracerBuffer();

    void append(const std::string& s);
    void writeToDisk(const std::string& s);
    void setTrace(bool);
    bool isTracing() const;
    std::string str() const;

private:
    mutable std::mutex mutex_;
    std::ostringstream buffer_;
    bool traceActivated_ = false;
    std::ofstream outfile;

    /* immutable after construction */
    std::string output_path_;

    /* grows at run time inside callback() */
    std::string snapshot_content_;

    int         counter_ = 0;
};

extern "C" void InMemoryTracerBuffer_append_entry(const char* s);

#endif //CJRTRACERBUFFER_H
