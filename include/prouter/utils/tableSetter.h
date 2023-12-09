#pragma once

#include <vector>

#include "tabulate/table.hpp"

class tableSetter {
private:
    int tabIndex = 3;

    std::vector<std::vector<std::string> *> tabs{
        &tab_0, &tab_1, &tab_2, &tab_3, &tab_4
    };

    std::vector<std::string> tab_0{
        "┌", "┬", "┐",
        "├", "┼", "┤",
        "└", "┴", "┘",
        "┌", "─", "┐",
        "│", "┼", "│",
        "└", "─", "┘",
    };

    std::vector<std::string> tab_1{
        "┏", "┳", "┓",
        "┣", "╋", "┫",
        "┗", "┻", "┛",
        "┏", "━", "┓",
        "┃", "╋", "┃",
        "┗", "━", "┛",
    };

    std::vector<std::string> tab_2{
        "┎", "┰", "┒",
        "┠", "╂", "┨",
        "┖", "┸", "┚",
        "┍", "┯", "┑",
        "┝", "┿", "┥",
        "┕", "┷", "┙",
    };

    std::vector<std::string> tab_3{
        "╔", "╦", "╗",
        "╠", "╬", "╣",
        "╚", "╩", "╝",
        "╔", "═", "╗",
        "║", "╬", "║",
        "╚", "═", "╝",
    };

    std::vector<std::string> tab_4{
        "╓", "╥", "╖",
        "╟", "╫", "╢",
        "╙", "╨", "╜",
        "╒", "╤", "╕",
        "╞", "╪", "╡",
        "╘", "╧", "╛",
    };
public:
    tableSetter();


};
