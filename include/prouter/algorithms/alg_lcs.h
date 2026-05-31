#pragma once

#ifndef PROUTER_ALG_LCS_H
#define PROUTER_ALG_LCS_H

#include <iostream>
#include <string>
#include <vector>

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

    bool traced = false, finished = false, stepperUsed = false;

    void init();

    void trace(int i, int m, int n);

public:
    alg_lcs &setValue(std::string a, std::string b);

    alg_lcs &run(bool useStepper = false, std::ostream &stream = std::cout);

    alg_lcs &printLcsTo(std::ostream &stream, bool withMatrices = false);

    std::vector<std::string> getResults();

    int getLcsLength();

    ~alg_lcs();
};

#endif
