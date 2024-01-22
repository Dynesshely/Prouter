#pragma once

#include <utility>
#include <map>
#include <algorithm>

#include <tabulate/tabulate.hpp>

class alg_lcs {
private:
    // Storage lcs string
    std::vector<std::string> results;

    // Two source strings and two pointers
    std::string str_a, str_b, *a = nullptr, *b = nullptr;

    // Calculation matrix and direction matrix
    int **calMatrix = nullptr, **dirMatrix = nullptr;

    // Width and height
    int w, h;

    bool traced = false;

    void init();

    void trace(int i, int m, int n);

public:
    alg_lcs &setValue(std::string a, std::string b);

    alg_lcs &run();

    alg_lcs &printLcsTo(std::ostream &stream, bool withMatrices = false);

    std::vector<std::string> getResults();

    int getLcsLength();
};

#include "../../../src/algorithms/alg_lcs.cpp"
