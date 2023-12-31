#pragma once

#include <string>
#include <vector>

#include <tabulate/table.hpp>

#include <prouter/core/pint.h>
#include <prouter/utils/tableSetter.h>
#include <prouter/core/tracers/arrayTracer.h>
#include <prouter/utils/textBuilder.h>

struct loopRow {
    int loopId{};
    std::vector<pint> pints;
};

class loopTracer {
private:
    int colCount = 0;
    int arrColCount = 0;

    std::vector<pint *> targets;
    std::vector<loopRow *> rows;
    std::vector<int> colLength;
    std::vector<arrayTracer *> arrays;

    std::string tracerName;

    void updateValue(int colIndex, int val);

public:
    loopTracer();

    loopTracer &trace(pint *v);

    loopTracer &trace(pint *target, int len, int offset = 0);

    template<typename T>
    loopTracer &trace(pnum<T> *target, int len, int offset = 0);

    loopTracer &loop();

    loopTracer &end();

    loopTracer &named(std::string str);

    tabulate::Table table();

    loopTracer &printTo(std::ostream &stream);

    ~loopTracer() {
        for (auto &array: arrays) {
            array->dispose();
        }
    }
};

#include "../../../../src/core/tracers/loopTracer.cpp"
