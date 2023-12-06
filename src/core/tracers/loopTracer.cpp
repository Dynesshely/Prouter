#include "../utils/textBuilder.cpp"
#include "../utils/typeProcessor.cpp"

void loopTracer::updateValue(int colIndex, int val) {
    if (rows.back()->pints.size() < colCount)
        rows.back()->pints.emplace_back(val);
    else
        rows.back()->pints[colIndex] = val;

    colLength[colIndex] = std::max(
        colLength[colIndex],
        textBuilder::actualWidth(
            textBuilder::varChangeHistoryText(
                &(rows.back()->pints[colIndex])
            )
        )
    );
}

loopTracer::loopTracer() {
    rows.push_back(new loopRow());
    rows[0]->loopId = 0;
}

loopTracer &loopTracer::trace(pint *v) {
    targets.push_back(v);
    colLength.push_back(
        textBuilder::actualWidth(
            std::to_string(v->getValue())
        )
    );

    auto currentCol = colCount++;

    updateValue(currentCol, v->getValue());

    v->onChanged(
        [this, currentCol](int val) {
            updateValue(currentCol, val);
        }
    );
    return *this;
}

loopTracer &loopTracer::loop() {
    auto row = new loopRow();
    row->loopId = (int) rows.size();
    for (auto &item: rows.back()->pints) {
        row->pints.emplace_back(item.getValue());
    }
    rows.push_back(row);
    return *this;
}

loopTracer &loopTracer::end() {
    rows.pop_back();

    for (auto &target: targets)
        target->onChanged(nullptr);

    return *this;
}

loopTracer &loopTracer::named(std::string str) {
    tracerName = std::move(str);
    return *this;
}

std::string loopTracer::tableText() {
    std::string text;

    auto firstColLen = typeProcessor::actualSize(rows.size() - 1);
    auto maxRowLen = 0;

    class textUtil {
        std::string *t;
        std::vector<int> colIndex;
    public:
        textUtil(std::string *src) {
            t = src;
        }

        void colAt(int index) {
            colIndex.push_back(index);
        }

        void appendLine(std::string s) {
            *t += s;
            *t += "\n";
        }

        void firstBar(int len) {
            *t += "╔";
            *t += textBuilder::buildText("═", len - 3);
            *t += "╗";
            *t += "\n";
        }

        void endBar(int len) {
            *t += "╚";
            *t += textBuilder::buildText("═", len - 3);
            *t += "╝";
            *t += "\n";
        }

        void middleSep(int len) {
            std::string s = "╬";
            std::string tmp;
            tmp += "╠";
            tmp += textBuilder::buildText("═", len - 3);
            tmp += "╣";
            tmp += "\n";
            *t += tmp;
        }

        void title(const std::string &te, int len) {
            firstBar(len);
            *t += "║";
            auto tlen = textBuilder::actualWidth(te);
            auto presl = ((len - tlen) / 2) - 2;
            *t += textBuilder::buildText(' ', presl);
            *t += te;
            *t += textBuilder::buildText(' ', len - tlen - presl - 3);
            *t += "║";
            *t += "\n";
            middleSep(len);
//            *t += "╠";
//            *t += textBuilder::buildText("═", len - 3);
//            *t += "╣";
//            *t += "\n";
        }
    };

    std::string firstRow;
    textUtil util(&text);

    {
        firstRow += "║ ";
        int cursor = 3;
        firstRow += textBuilder::buildText(
            ' ',
            textBuilder::actualWidth(
                std::to_string(firstColLen)
            )
        );
        cursor += textBuilder::actualWidth(std::to_string(firstColLen)) + 4;
        firstRow += " ║ ";
        util.colAt(cursor);
        for (int i = 0; i < colCount; ++i) {
            firstRow += textBuilder::meetLength(
                targets[i]->name(),
                colLength[i],
                ' '
            );
            firstRow += " ║ ";
            cursor += 4 + textBuilder::actualWidth(targets[i]->name());
            util.colAt(cursor);
        }
    }

    maxRowLen = textBuilder::actualWidth(firstRow) - 4 - 2 * colCount;

    util.title(tracerName, maxRowLen);

    util.appendLine(firstRow);

    for (auto &row: rows) {
        text += "║ " + std::to_string(row->loopId) + " ║ ";

        for (int j = 0; j < row->pints.size(); ++j) {
            text += textBuilder::meetLength(
                textBuilder::varChangeHistoryText(&(row->pints[j])),
                colLength[j],
                ' '
            );
            text += " ║ ";
        }

        text += "\n";
    }

    util.endBar(maxRowLen);

    return text;
}
