#pragma once

#include "../core/pnum.h"

class textBuilder {
private:
public:
    static std::string varChangeHistoryText(pint *v);

    template<typename T>
    static std::string varChangeHistoryText(pnum<T> *v) {
        std::string text;
        for (int k = 0; k < v->historicalValuesCount(); ++k) {
            text += std::to_string((*v)[k]);

            if (k < v->historicalValuesCount() - 1)
                text += " -> ";
        }
        return text;
    }

    static std::string meetLength(std::string str, int len, char c);

    static std::string *meetLength(std::string *str, int len, char c);

    static std::string buildText(char c, int repeat);

    static std::string buildText(std::string s, int repeat);

    static int actualWidth(const std::string &str);

    static int actualSize(size_t s);
};

#include "../../src/utils/textBuilder.cpp"
