#pragma once

#include <tabulate/table.hpp>

#include <prouter/core/pint.h>
#include <prouter/core/pnum.h>

class arrayTracer {
private:
    pint *pint_begin = nullptr;
    int pint_length = 0, pnum_length = 0, loop_offset = 0;
    bool typeSelected = false;
    std::vector<std::string> historicalValues;
    std::string tracerName = "default array tracer";
    std::string originalValue = "";

    void recordHistory();

    template<typename T>
    void recordHistory(pnum<T> *target);

    template<typename T>
    void recordOriginalValue(pnum<T> *target_pnum);

public:
    std::string name();

    arrayTracer &named(std::string str);

    arrayTracer &trace(pint *target, int len);

    template<typename T>
    arrayTracer &trace(pnum<T> *target, int len);

    arrayTracer &dispose();

    template<typename T>
    arrayTracer &dispose(pnum<T> *target);

    tabulate::Table table();

    arrayTracer &printTo(std::ostream &stream, bool useTable = false);

    std::string history();

    std::string history(int index);

    arrayTracer &offset(int offset);
};

#include "../../../../src/core/tracers/arrayTracer.cpp"
