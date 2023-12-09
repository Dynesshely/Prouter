#pragma once

#include <string>
#include <vector>

#include <tabulate/table.hpp>

#include <prouter/core/pint.h>
#include <prouter/utils/textBuilder.h>
#include <prouter/utils/tableSetter.h>

struct loopRow {
    int loopId{};
    std::vector<pint> pints;
};

class loopTracer {
private:
    int colCount = 0;

    std::vector<pint *> targets;
    std::vector<loopRow *> rows;
    std::vector<int> colLength;

    std::string tracerName;

    void updateValue(int colIndex, int val);

public:
    loopTracer();

    loopTracer &trace(pint *v);

    loopTracer &loop();

    loopTracer &end();

    loopTracer &named(std::string str);

    tabulate::Table table();

    loopTracer &printTo(std::ostream &stream);
};

#include "../../../../src/core/tracers/loopTracer.cpp"
