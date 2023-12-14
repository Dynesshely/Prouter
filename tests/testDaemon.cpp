#include <iostream>

#include <prouter/prouterIncludes.h>

int main() {

#include <prouter/prouterPredefine.h>

    std::cout << std::endl;

    double a = 3.0;
    a = 4.0;
    a *= 2.0;

    std::cout << a.history() << std::endl;

    std::cout << std::endl;

    auto arrTracer = prouter::traceArray();

    int arr[10] = {0};

    arrTracer.trace(arr, 10);

    for (int i = 0; i < 10; ++i)
        arr[i] = i;

    std::cout << arrTracer.history() << std::endl;

    std::cout << std::endl;

    auto loopTracer = prouter::traceLoop().named("loop 1");

    int f[1000], i = 1, fc;
    f[1] = 1;
    f[2] = 1;

    loopTracer.trace(&i.named("i"))
              .trace(&fc.named("fc"));

    for (; i <= 10; ++i, loopTracer.loop()) {
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
        fc.setValue(f[i]);
    }

    loopTracer.end().printTo(std::cout);

    std::cout << std::endl;
}
