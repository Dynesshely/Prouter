#include <prouter/includes.h>
#include "../doctest.h"

TEST_CASE("pint — variable tracing") {
    std::cout << "\n=== pint variable tracing ===\n";

    pint a(3);
    a = 4;
    a *= 2;

    std::cout << a.history() << std::endl;

    CHECK(a.getValue() == 8);
    CHECK(a.history() == "3 -> 4 -> 8");
    CHECK(a.historicalValuesCount() == 3);
}

TEST_CASE("pint — named variable") {
    pint x(10);
    x.named("counter");

    CHECK(x.name() == "counter");
    CHECK(*x.nameAddress() == "counter");
}

TEST_CASE("pint — arithmetic operators") {
    pint a(5);
    pint b(3);

    CHECK(a + b == 8);
    CHECK(a - b == 2);
    CHECK(a * b == 15);
    CHECK(a / b == 1);

    a += 2;
    CHECK(a.getValue() == 7);

    a -= 1;
    CHECK(a.getValue() == 6);

    a++;
    CHECK(a.getValue() == 7);

    a--;
    CHECK(a.getValue() == 6);
}

TEST_CASE("pint — comparison operators") {
    pint a(5);

    CHECK(a == 5);
    CHECK(a != 3);
    CHECK(a > 3);
    CHECK(a < 7);
    CHECK(a >= 5);
    CHECK(a <= 5);
}

TEST_CASE("pint — implicit int conversion") {
    pint a(42);
    int v = a;                      // operator int()
    CHECK(v == 42);
}
