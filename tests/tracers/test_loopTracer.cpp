#include <prouter/includes.h>
#include "../doctest.h"

TEST_CASE("loopTracer — Fibonacci loop tracing") {
    std::cout << "\n=== loopTracer Fibonacci ===\n";

    auto tracer = prouter::traceLoop().named("loop 1");

    pint f[13];
    pint i(1);
    pint fc(0);
    f[1] = 1, f[2] = 1;

    tracer.trace(&i.named("i"))
          .trace(&fc.named("fc"))
          .trace(f, 13, 2);

    for (; i <= 10; ++i, tracer.loop()) {
        if (i >= 3)
            f[i] = f[i - 1] + f[i - 2];
        fc.setValue(f[i]);
    }

    tracer.end().printTo(std::cout);

    // After loop, i should be 11, fc should be 55 (fib(10))
    CHECK(i.getValue() == 11);
    CHECK(fc.getValue() == 55);
    CHECK(f[10].getValue() == 55);
}

TEST_CASE("loopTracer — named") {
    auto tracer = prouter::traceLoop().named("test loop");
    CHECK(true);  // tracer construction succeeded
}
