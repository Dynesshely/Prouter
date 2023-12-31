#pragma once

#include <prouter/core/pnum.h>

class textBuilder {
private:
public:
    static std::string meetLength(std::string str, int len, char c);

    static std::string *meetLength(std::string *str, int len, char c);

    static std::string buildText(char c, int repeat);

    static std::string buildText(std::string s, int repeat);

    static int actualWidth(const std::string &str);

    static int actualSize(size_t s);

    static std::vector<std::string> splitByLines(const std::string& str);
};

#include "../../../src/utils/textBuilder.cpp"
