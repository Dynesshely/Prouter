#pragma once

#include <stack>

#include <tabulate/table.hpp>

template<typename T>
class pstack {
private:
    std::vector<T> internalStack;
    std::function<void(T)> onPushedFunc = nullptr;
    std::function<void()> onPoppedFunc = nullptr;
    std::vector<tabulate::Table> historicalValues;

    int maxDepth = 0, depth = 0;

    void recordHistory() {
        tabulate::Table table;

//        table.add_row({""});

        for (int i = 0; i < internalStack.size(); ++i)
            table.add_row({std::to_string(internalStack[i])});

        table.add_row({" "});

//        tableSetter::format(&table, 1, internalStack.size());

        historicalValues.push_back(table);
    }

    std::string getFullHistory() {
        std::vector<std::string> lines;

        auto maxHeight = maxDepth + (maxDepth - 1) * 3 + 2;

        lines.reserve(maxHeight);
        for (int i = 0; i < maxHeight; ++i)
            lines.emplace_back("");

        for (int i = 0; i < historicalValues.size(); ++i) {
            auto tmp = historicalValues[i].str();
            auto tmp_lines = textBuilder::splitByLines(tmp);
            auto max_width = 0;

            for (int j = 0; j < maxHeight; ++j) {
                if (j < tmp_lines.size()) {
                    lines[j] += tmp_lines[j];
                    max_width = std::max(max_width, (int) tmp_lines[j].length());
                } else
                    lines[j] += textBuilder::buildText(' ', max_width);
            }

            if (i != historicalValues.size() - 1)
                for (int j = 0; j < maxHeight; ++j) {
                    if (j == maxHeight / 2)
                        lines[j] += "    -->    ";
                    else
                        lines[j] += "           ";
                }
        }

        std::reverse(lines.begin(), lines.end());

        std::string rst;

        for (const auto &line: lines)
            rst += line + "\n";

        return rst;
    }

public:
    pstack() = default;

    bool empty() const {
        return internalStack.empty();
    }

    size_t size() const {
        return internalStack.size();
    }

    pstack &push(T t) {
        internalStack.push_back(t);
        recordHistory();
        ++depth;
        maxDepth = std::max(maxDepth, depth);

        if (onPushedFunc != nullptr)
            onPushedFunc(t);

        return static_cast<pstack &>(*this);
    }

    pstack &pop() {
        if (internalStack.empty())
            throw std::out_of_range("Stack is empty");

        internalStack.pop_back();
        recordHistory();
        --depth;

        if (onPoppedFunc != nullptr)
            onPoppedFunc();

        return static_cast<pstack &>(*this);
    }

    T &top() {
        if (internalStack.empty())
            throw std::out_of_range("Stack is empty");
        return internalStack.back();
    }

    const T &top() const {
        if (internalStack.empty())
            throw std::out_of_range("Stack is empty");
        return internalStack.back();
    }

    pstack &onPushed(std::function<void(T)> func) {
        onPushedFunc = func;
        return static_cast<pstack &>(*this);
    }

    pstack &onPopped(std::function<void()> func) {
        onPoppedFunc = func;
        return static_cast<pstack &>(*this);
    }

    pstack &clear() {
        internalStack.clear();
        recordHistory();
        return static_cast<pstack &>(*this);
    }

    pstack &printHistoryTo(std::ostream &stream) {
        stream << getFullHistory() << std::endl;
        return static_cast<pstack &>(*this);
    }
};

#include "../../../../src/core/structures/pstack.cpp"
