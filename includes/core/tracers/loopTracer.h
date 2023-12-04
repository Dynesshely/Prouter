#ifndef LOOPTRACER_H
#define LOOPTRACER_H

#include <string>
#include <vector>
#include "../pint.h"

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

    void updateValue(int colIndex, int val);

public:
    loopTracer();

    loopTracer &trace(pint *v);

    loopTracer &loop();

    loopTracer &end();

    std::string tableText();
};

#endif // LOOPTRACER_H
