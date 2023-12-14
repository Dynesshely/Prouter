#pragma once

#include <prouter/core/pint.h>
#include <prouter/core/pnum.h>

class arrayTracer {
private:
    pint *begin;
    int length;
    std::vector<std::string> historicalValues;

    void recordHistory();

public:
    arrayTracer &trace(pint *target, int len);

    arrayTracer &dispose();

    std::string history();
};

#include "../../../../src/core/tracers/arrayTracer.cpp"
