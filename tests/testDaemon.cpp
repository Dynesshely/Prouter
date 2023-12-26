#include <iostream>

#include <prouter/includes.h>

int main() {

#include <prouter/predefine.h>

    std::cout << std::endl;

    double a = 3.0;
    a = 4.0, a *= 2.0;

    std::cout << a.history() << std::endl << std::endl;


    auto int_arrTracer = prouter::traceArray().named("int arr tracer");

    int intarr[10] = {0};

    int_arrTracer.trace(intarr, 10);

    for (int i = 0; i < 10; ++i) intarr[i] = i;

    int_arrTracer.printTo(std::cout, true).dispose();


    auto num_arrTracer = prouter::traceArray().named("num arr tracer");

    double numarr[10] = {0};

    num_arrTracer.trace(numarr, 10);

    for (int i = 0; i < 10; ++i) numarr[i] = i;

    std::cout << num_arrTracer.history() << std::endl;

    num_arrTracer.dispose(numarr);


    auto loopTracer = prouter::traceLoop().named("loop 1");

    int f[13], i = 1, fc;
    f[1] = 1, f[2] = 1;

    loopTracer.trace(&i.named("i"))
              .trace(&fc.named("fc"))
              .trace(f, 13);

    for (; i <= 10; ++i, loopTracer.loop()) {
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
        fc.setValue(f[i]);
    }

    loopTracer.end().printTo(std::cout);
}
