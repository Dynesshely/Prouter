#include <prouter/includes.h>
#include "../doctest.h"

TEST_CASE("pqueue — push / pop / clear with visual history") {
    std::cout << "\n=== pqueue<int> push/pop/clear history ===\n";

    auto *q = new pqueue<int>();
    q->push(3)
     .push(7)
     .pop()
     .push(16)
     .pop()
     .push(12)
     .push(244)
     .push(9)
     .pop()
     .pop()
     .clear();

    q->printHistoryTo(std::cout);

    CHECK(q->empty());
    CHECK(q->size() == 0);

    delete q;
}

TEST_CASE("pqueue — basic operations") {
    pqueue<int> q;

    CHECK(q.empty());

    q.push(1);
    CHECK(q.size() == 1);
    CHECK(q.front() == 1);
    CHECK(q.back() == 1);

    q.push(2);
    CHECK(q.size() == 2);
    CHECK(q.front() == 1);
    CHECK(q.back() == 2);

    q.pop();
    CHECK(q.size() == 1);
    CHECK(q.front() == 2);

    q.pop();
    CHECK(q.empty());
}

TEST_CASE("pqueue — pop on empty throws") {
    pqueue<int> q;
    CHECK_THROWS_AS(q.pop(), std::out_of_range);
}

TEST_CASE("pqueue — clear empty queue") {
    pqueue<int> q;
    q.clear();  // should not crash
    CHECK(q.empty());
}
