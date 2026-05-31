#pragma once

#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <tabulate/table.hpp>

#include <prouter/core/pint.h>
#include <prouter/core/pnum.h>

class arrayTracer {
private:
    pint *pint_begin = nullptr;
    int pint_length = 0, pnum_length = 0, loop_offset = 0;
    bool typeSelected = false;
    std::vector<std::string> historicalValues;
    std::string tracerName = "default array tracer";
    std::string originalValue = "";

    void recordHistory();

    template<typename T>
    void recordHistory(pnum<T> *target);

    template<typename T>
    void recordOriginalValue(pnum<T> *target_pnum);

public:
    std::string name();

    arrayTracer &named(std::string str);

    arrayTracer &trace(pint *target, int len);

    template<typename T>
    arrayTracer &trace(pnum<T> *target, int len);

    arrayTracer &dispose();

    template<typename T>
    arrayTracer &dispose(pnum<T> *target);

    tabulate::Table table();

    arrayTracer &printTo(std::ostream &stream, bool useTable = false);

    std::string history();

    std::string history(int index);

    arrayTracer &offset(int offset);
};

// --- Template method implementations ---

template<typename T>
void arrayTracer::recordHistory(pnum<T> *target) {
    if (target == nullptr) return;

    std::string text;
    text += "[";
    for (int i = 0; i < pnum_length; ++i) {
        text += std::to_string(*(target + i));
        if (i < pnum_length - 1)
            text += ", ";
    }
    text += "]";
    historicalValues.push_back(text);
}

template<typename T>
void arrayTracer::recordOriginalValue(pnum<T> *target_pnum) {
    if (target_pnum == nullptr) {
        recordHistory();
    } else {
        recordHistory(target_pnum);
    }
    originalValue = historicalValues.front();
    historicalValues.pop_back();
}

template<typename T>
arrayTracer &arrayTracer::trace(pnum<T> *target, int len) {
    if (typeSelected)
        throw std::logic_error("You can only apply trace target once on each tracer.");
    else typeSelected = true;

    pnum_length = len;

    recordOriginalValue(target);

    for (int i = 0; i < pnum_length; ++i) {
        (target + i)->onChanged(
            [this, target](T val) {
                recordHistory(target);
            }
        );
    }

    return static_cast<arrayTracer &>(*this);
}

template<typename T>
arrayTracer &arrayTracer::dispose(pnum<T> *target) {
    for (int i = 0; i < pnum_length; ++i)
        (target + i)->onChanged(nullptr);
    return static_cast<arrayTracer &>(*this);
}

