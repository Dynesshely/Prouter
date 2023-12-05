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

std::string loopTracer::tableText() {
    std::string text;

    text += textBuilder::buildText(
        ' ',
        textBuilder::actualWidth(
            std::to_string(
                typeProcessor::actualSize(rows.size())
            )
        )
    );
    text += " | ";
    for (int i = 0; i < colCount; ++i) {
        text += textBuilder::meetLength(
            targets[i]->name(),
            colLength[i],
            ' '
        );
        text += " | ";
    }
    text += "\n";

    for (auto &row: rows) {
        text += std::to_string(row->loopId) + " | ";

        for (int j = 0; j < row->pints.size(); ++j) {
            text += textBuilder::meetLength(
                textBuilder::varChangeHistoryText(&(row->pints[j])),
                colLength[j],
                ' '
            );
            text += " | ";
        }

        text += "\n";
    }

    return text;
}
