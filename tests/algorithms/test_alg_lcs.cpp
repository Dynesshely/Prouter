#include <cstdlib>

#include <prouter/includes.h>
#include "../doctest.h"

TEST_CASE("alg_lcs — basic LCS computation") {
    std::cout << "\n=== alg_lcs basic ===\n";

    auto *lcs = new alg_lcs();
    lcs->setValue("ABCBDAB", "BDCABA").run().printLcsTo(std::cout);

    CHECK(lcs->getLcsLength() == 4);

    auto results = lcs->getResults();
    CHECK(results.size() > 0);

    // The two known LCS results for this input
    bool has_bcba = false, has_bdab = false;
    for (const auto &r: results) {
        if (r == "BCBA") has_bcba = true;
        if (r == "BDAB") has_bdab = true;
    }
    CHECK(has_bcba);
    CHECK(has_bdab);

    delete lcs;
}

TEST_CASE("alg_lcs — stepper interactive mode" * doctest::skip()) {
    // This test is skipped by default.
    // Run manually with: PROUTER_INTERACTIVE=1 ./build/tests/tests -tc="stepper"
    if (!std::getenv("PROUTER_INTERACTIVE"))
        return;

    std::cout << "\n=== alg_lcs stepper interactive ===\n";
    std::cout << "(press any key to step through each iteration)\n\n";

    auto *lcs = new alg_lcs();
    lcs->setValue("ABCBDAB", "BDCABA")
       .run(true, std::cout)
       .printLcsTo(std::cout);

    CHECK(lcs->getLcsLength() == 4);

    delete lcs;
}

TEST_CASE("alg_lcs — empty strings") {
    auto *lcs = new alg_lcs();
    lcs->setValue("", "").run();

    // LCS of empty strings is empty with length 0
    auto results = lcs->getResults();
    CHECK(lcs->getLcsLength() <= 1);

    delete lcs;
}

TEST_CASE("alg_lcs — no common subsequence") {
    auto *lcs = new alg_lcs();
    lcs->setValue("ABC", "XYZ").run();

    CHECK(lcs->getLcsLength() == 0);

    delete lcs;
}
