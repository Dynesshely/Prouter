#include <iostream>

#include "./src/core/prouter.cpp"

int main() {

#define int pint
#define double pnum<double>

    auto tracer = prouter::traceLoop();

    int f[1000], i = 1, fc;
    f[1] = 1;
    f[2] = 1;

    tracer.trace(&i.named("i"))
          .trace(&fc.named("fc"));

    for (; i <= 4; ++i, tracer.loop()) {
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
        fc.setValue(f[i]);
    }

    tracer.end();

    std::cout << std::endl << tracer.tableText() << std::endl;

    double a = 3.0;
    a = 4.0;

    std::cout << textBuilder::varChangeHistoryText(&a) << std::endl;
}
