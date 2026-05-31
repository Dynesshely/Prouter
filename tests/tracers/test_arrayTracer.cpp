#include <prouter/includes.h>
#include "../doctest.h"

TEST_CASE("arrayTracer — pint array tracing") {
    std::cout << "\n=== arrayTracer pint array ===\n";

    auto tracer = prouter::traceArray().named("int arr tracer");

    pint arr[10] = {0};
    tracer.trace(arr, 10);

    for (int i = 0; i < 10; ++i)
        arr[i] = i;

    tracer.printTo(std::cout, true);
    tracer.dispose();

    // Last recorded history should reflect [0,1,2,...,9]
    std::string last = tracer.history(9);
    CHECK(last.find("0, 1, 2, 3, 4, 5, 6, 7, 8, 9") != std::string::npos);
}

TEST_CASE("arrayTracer — pnum<double> array tracing") {
    std::cout << "\n=== arrayTracer pnum<double> array ===\n";

    auto tracer = prouter::traceArray().named("num arr tracer");

    pnum<double> arr[10] = {0.0};
    tracer.trace(arr, 10);

    for (int i = 0; i < 10; ++i)
        arr[i] = i;

    std::cout << tracer.history() << std::endl;
    tracer.dispose(arr);

    // Check that historical values were recorded (10 iterations)
    std::string hist = tracer.history();
    CHECK(!hist.empty());
}

TEST_CASE("arrayTracer — default name") {
    auto tracer = prouter::traceArray();
    CHECK(tracer.name() == "default array tracer");
}

TEST_CASE("arrayTracer — custom name") {
    auto tracer = prouter::traceArray().named("my tracer");
    CHECK(tracer.name() == "my tracer");
}
