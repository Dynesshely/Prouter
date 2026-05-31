#include <prouter/includes.h>
#include "../doctest.h"

TEST_CASE("pnum<double> — tracing and history") {
    std::cout << "\n=== pnum<double> tracing ===\n";

    pnum<double> a(3.0);
    a = 4.0;
    a *= 2.0;

    std::cout << a.history() << std::endl;

    CHECK(a.getValue() == 8.0);
    CHECK(a.history() == "3.000000 -> 4.000000 -> 8.000000");
}

TEST_CASE("pnum<float> — arithmetic") {
    pnum<float> a(3.0f);

    a += 2.0f;
    CHECK(a.getValue() == 5.0f);

    a *= 2.0f;
    CHECK(a.getValue() == 10.0f);

    CHECK(a.historicalValuesCount() == 3);
}

TEST_CASE("pnum<double> — named") {
    pnum<double> x(1.5);
    x.named("weight");

    CHECK(x.name() == "weight");
}

TEST_CASE("pnum<double> — implicit conversion") {
    pnum<double> a(3.14);
    double v = a;
    CHECK(v == 3.14);
}
