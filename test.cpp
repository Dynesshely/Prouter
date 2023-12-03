#include <iostream>

#include "./src/core/prouter.cpp"

int main() {

#define int pint

    auto tracer = prouter::traceLoop();

    int f[1000], i = 1, j = 1, fc;
    f[1] = 1;
    f[2] = 1;

    tracer.trace(&i.named("i"))
          .trace(&j.named("j"))
          .trace(&fc.named("fc"));

    for (; i <= 4; ++i, tracer.loop()) {
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
        j -= 1;
        ++j;
        fc.setValue(f[i]);
    }

    tracer.end();

    std::cout << std::endl << tracer.tableText() << std::endl;
}
