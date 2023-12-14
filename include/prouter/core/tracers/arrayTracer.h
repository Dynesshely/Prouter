#pragma once

#include <prouter/core/pint.h>
#include <prouter/core/pnum.h>

class arrayTracer {
private:
    pint *begin;
    int length;
    std::vector<std::string> historicalValues;

    void recordHistory() {
        std::string text;
        text += "[";
        for (int i = 0; i < length; ++i) {
            text += std::to_string(*(begin + i));
            if (i < length - 1)
                text += ", ";
        }
        text += "]";
        historicalValues.push_back(text);
    }

public:
    arrayTracer trace(pint *target, int len) {
        begin = target, length = len;
        for (int i = 0; i < length; ++i)
            (begin + i)->onChanged(
                [this](int val) {
                    recordHistory();
                }
            );
        return *this;
    }

    arrayTracer dispose() {
        for (int i = 0; i < length; ++i)
            (begin + i)->onChanged(nullptr);
        return *this;
    }

    std::string history() {
        std::string text;
        for (const auto &i: historicalValues)
            text += i + "\n";
        return text;
    }
};

#include "../../../../src/core/tracers/arrayTracer.cpp"
