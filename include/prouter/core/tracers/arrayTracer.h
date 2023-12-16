#pragma once

#include <tabulate/table.hpp>

#include <prouter/core/pint.h>
#include <prouter/core/pnum.h>

class arrayTracer {
private:
    pint *pint_begin;
    int pint_length, pnum_length;
    bool typeSelected = false;
    std::vector<std::string> historicalValues;
    std::string tracerName;

    void recordHistory();

    template<typename T>
    void recordHistory(pnum<T> *target);

public:
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
};

#include "../../../../src/core/tracers/arrayTracer.cpp"
