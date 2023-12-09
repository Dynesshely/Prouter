// Default:
// ╔═══╦═══════╗
// ╠═══╣       ║
// ╠═══╬═══╦═══╣
// ╚═══╩═══╩═══╝

std::vector<const std::string> tableSetter::tab_0 = {
    "┌", "┬", "┐",
    "├", "┼", "┤",
    "└", "┴", "┘",
    "┌", "─", "┐",
    "│", "┼", "│",
    "└", "─", "┘",
};

std::vector<const std::string> tableSetter::tab_1 = {
    "┏", "┳", "┓",
    "┣", "╋", "┫",
    "┗", "┻", "┛",
    "┏", "━", "┓",
    "┃", "╋", "┃",
    "┗", "━", "┛",
};

std::vector<const std::string> tableSetter::tab_2 = {
    "┎", "┰", "┒",
    "┠", "╂", "┨",
    "┖", "┸", "┚",
    "┍", "┯", "┑",
    "┝", "┿", "┥",
    "┕", "┷", "┙",
};

std::vector<const std::string> tableSetter::tab_3 = {
    "╔", "╦", "╗",
    "╠", "╬", "╣",
    "╚", "╩", "╝",
    "╔", "═", "╗",
    "║", "╬", "║",
    "╚", "═", "╝",
};

std::vector<const std::string> tableSetter::tab_4 = {
    "╓", "╥", "╖",
    "╟", "╫", "╢",
    "╙", "╨", "╜",
    "╒", "╤", "╕",
    "╞", "╪", "╡",
    "╘", "╧", "╛",
};

std::vector<std::vector<const std::string> *> tableSetter::tabs = {
    &tab_0, &tab_1, &tab_2, &tab_3, &tab_4
};

void tableSetter::format(tabulate::Table *table, int width, int height, int tabIndex = 3) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            (*table)[i][j].format()
                          .corner_top_left((*tabs[tabIndex])[3])
                          .corner_top_right((*tabs[tabIndex])[5])
                          .corner_bottom_left((*tabs[tabIndex])[6])
                          .corner_bottom_right((*tabs[tabIndex])[8])
                          .border_top((*tabs[tabIndex])[10])
                          .border_bottom((*tabs[tabIndex])[16])
                          .border_left((*tabs[tabIndex])[12])
                          .border_right((*tabs[tabIndex])[14]);
            if (i == 0) {
                (*table)[i][j].format()
                              .corner_top_left((*tabs[tabIndex])[0])
                              .corner_top_right((*tabs[tabIndex])[2]);
            }
            if (j > 0) {
                (*table)[i][j].format()
                              .corner_top_left((*tabs[tabIndex])[13])
                              .corner_bottom_left((*tabs[tabIndex])[13]);

                if (i == 0)
                    (*table)[i][j].format()
                                  .corner_top_left((*tabs[tabIndex])[1]);
                if (i == height - 1)
                    (*table)[i][j].format()
                                  .corner_bottom_left((*tabs[tabIndex])[07]);
            }
        }
    }
}
