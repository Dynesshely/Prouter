#pragma once

#include <vector>

#include "tabulate/table.hpp"

class tableSetter {
private:
    static std::vector<const std::string> tab_0;

    static std::vector<const std::string> tab_1;

    static std::vector<const std::string> tab_2;

    static std::vector<const std::string> tab_3;

    static std::vector<const std::string> tab_4;

    static std::vector<std::vector<const std::string> *> tabs;
public:
    static void format(tabulate::Table *table, int width, int height, int tabIndex);
};

#include "../../../src/utils/tableSetter.cpp"
