#include <prouter/includes.h>
#include "../doctest.h"

TEST_CASE("pstack — push / pop / clear with visual history") {
    std::cout << "\n=== pstack<int> push/pop/clear history ===\n";

    auto *s = new pstack<int>();
    s->push(4)
     .push(8)
     .push(2)
     .pop()
     .push(9)
     .pop()
     .push(3)
     .pop()
     .push(1)
     .pop()
     .clear();

    s->printHistoryTo(std::cout);

    CHECK(s->empty());
    CHECK(s->size() == 0);

    delete s;
}

TEST_CASE("pstack — basic operations") {
    auto *s = new pstack<int>();

    CHECK(s->empty());

    s->push(10);
    CHECK(s->size() == 1);
    CHECK(s->top() == 10);

    s->push(20);
    CHECK(s->size() == 2);
    CHECK(s->top() == 20);

    s->pop();
    CHECK(s->size() == 1);
    CHECK(s->top() == 10);

    s->pop();
    CHECK(s->empty());

    delete s;
}

TEST_CASE("pstack — pop on empty throws") {
    pstack<int> s;
    CHECK_THROWS_AS(s.pop(), std::out_of_range);
}

TEST_CASE("pstack — clear records history") {
    pstack<int> s;
    s.push(1).push(2).push(3).clear();

    CHECK(s.empty());
}
