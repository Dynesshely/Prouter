#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include <tabulate/table.hpp>

template<typename T>
class pqueue {
private:
    std::vector<T> vec;
    std::vector<tabulate::Table> historicalValues;
    int start_index, end_index;

    void recordHistory() {
        tabulate::Table table;

        tabulate::Table::Row_t header;
        header.emplace_back("<-");
        for (int i = start_index; i <= end_index; ++i)
            header.emplace_back(std::to_string(vec[i]));
        if (empty())
            header.emplace_back("<empty queue>");
        header.emplace_back("<-");

        table.add_row(header);

        historicalValues.emplace_back(table);
    }

    std::string getFullHistory() {
        tabulate::Table table;

        for (int i = 0; i < historicalValues.size(); ++i) {
            auto id = tabulate::Table()
                .add_row({" "})
                .add_row({std::to_string(i)})
                .add_row({" "});
            id.format().font_align(tabulate::FontAlign::center).hide_border();
            table.add_row({id, historicalValues[i]});
        }

        table.format().font_align(tabulate::FontAlign::center).hide_border();

        return table.str();
    }

public:
    pqueue() : start_index(0), end_index(-1) {}

    bool empty() const {
        return start_index > end_index;
    }

    size_t size() const {
        return end_index - start_index + 1;
    }

    const T &front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return vec[start_index];
    }

    const T &back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return vec[end_index];
    }

    pqueue &push(const T &value) {
        vec.push_back(value);
        ++end_index;

        recordHistory();

        return static_cast<pqueue &>(*this);
    }

    pqueue &pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        ++start_index;

        recordHistory();

        return static_cast<pqueue &>(*this);
    }

    pqueue &clear() {
        if (!empty()) {
            start_index = end_index + 1;
            recordHistory();
        }

        return static_cast<pqueue &>(*this);
    }

    pqueue &printHistoryTo(std::ostream &stream) {
        stream << getFullHistory() << std::endl;
        return static_cast<pqueue &>(*this);
    }
};

#include "../../../../src/core/structures/pqueue.cpp"