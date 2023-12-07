#include <iostream>

#include "prouterIncludes.h"

int main() {

#include "prouterPredefine.h"

    auto tracer = prouter::traceLoop().named("loop 1");

    int f[1000], i = 1, fc;
    f[1] = 1;
    f[2] = 1;

    tracer.trace(&i.named("i"))
          .trace(&fc.named("fc"));

    for (; i <= 10; ++i, tracer.loop()) {
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
        fc.setValue(f[i]);
    }

    tracer.end();

    std::cout << std::endl << tracer.tableText() << std::endl;

    double a = 3.0;
    a = 4.0;
    a *= 2.0;

    std::cout << textBuilder::varChangeHistoryText(&a) << std::endl;
}
