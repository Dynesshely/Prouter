#pragma once

#include <prouter/core/tracers/loopTracer.h>
#include <prouter/core/tracers/arrayTracer.h>

class prouter {
private:
public:
    static loopTracer traceLoop();

    static arrayTracer traceArray();
};

#include "../../../src/core/prouter.cpp"
