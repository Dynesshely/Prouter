#include <iostream>

#include "./src/core/prouter.cpp"

int main() {

#define int pint

    auto tracer = prouter::traceLoop();

    int f[1000], i, j = 1;
    f[1] = 1;
    f[2] = 1;

    tracer.trace(&i).trace(&j);

    for (i = 1; i <= 7; ++i, tracer.loop()) {
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
        i = i;
        ++j;
        std::cout << f[i] << std::endl;
    }

    tracer.end();

    std::cout << std::endl << tracer.tableText() << std::endl;
}
