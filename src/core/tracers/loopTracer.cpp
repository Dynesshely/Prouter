#include "../pint.cpp"
#include "../utils/textBuilder.cpp"
#include <string>
#include <vector>

struct loopRow {
    int loopId{};
    std::vector<pint> pints;
};

class loopTracer {
private:
    int colCount = 0;

    std::vector<pint *> targets;
    std::vector<loopRow *> rows;
    std::vector<int> colLength;

    void updateValue(int colIndex, int val) {
        if (rows.back()->pints.size() < colCount)
            rows.back()->pints.emplace_back(val);
        else
            rows[rows.size() - 1]->pints[colIndex] = val;
    }

public:
    loopTracer() {
        rows.push_back(new loopRow());
        rows[0]->loopId = 0;
    }

    loopTracer &trace(pint *v) {
        targets.push_back(v);
        colLength.push_back((int) std::to_string(v->getValue()).length());

        auto currentCol = colCount++;

        updateValue(currentCol, v->getValue());

        v->onChanged([this, currentCol, v](int val) {
            updateValue(currentCol, val);
            colLength[currentCol] = std::max(colLength[currentCol],
                                             (int) (textBuilder::varChangeHistoryText(v).length() / sizeof(int) + 1));
        });
        return *this;
    }


    loopTracer &loop() {
        auto row = new loopRow();
        row->loopId = (int) rows.size();
        rows.push_back(row);
        return *this;
    }

    loopTracer &end() {
        rows.pop_back();

        for (auto &target: targets)
            target->onChanged(nullptr);

        return *this;
    }

    std::string tableText() {
        std::string text;

        text += textBuilder::buildText(' ', (int) (rows.size() / sizeof(int)));
        text += " | ";
        for (int i = 0; i < colCount; ++i) {
            text += *textBuilder::meetLength(targets[i]->nameAddress(), colLength[i], ' ');
            text += " | ";
        }
        text += "\n";

        for (auto &row: rows) {
            text += std::to_string(row->loopId) + " | ";

            for (int j = 0; j < row->pints.size(); ++j) {
                auto t = textBuilder::varChangeHistoryText(&row->pints[j]);
                text += *textBuilder::meetLength(&t, colLength[j], ' ');
                text += " | ";
            }

            text += "\n";
        }

        return text;
    }
};
