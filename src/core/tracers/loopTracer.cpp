void loopTracer::updateValue(int colIndex, int val) {
    if (rows.back()->pints.size() < colCount)
        rows.back()->pints.emplace_back(val);
    else
        rows.back()->pints[colIndex] = val;

    colLength[colIndex] = std::max(
        colLength[colIndex],
        textBuilder::actualWidth(
            rows.back()->pints[colIndex].history()
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

tabulate::Table loopTracer::table() {
    int totalRowsCount = (int) rows.size() + 1;
    int totalColsCount = (int) targets.size() + 1;
    tabulate::Table table;

    tabulate::Table::Row_t header;
    header.emplace_back("");
    for (auto &target: targets)
        header.emplace_back(target->name());
    table.add_row(header);

    for (auto &i: rows) {
        tabulate::Table::Row_t row;
        row.emplace_back(std::to_string(i->loopId));
        for (auto &pint: i->pints)
            row.emplace_back(pint.history());
        table.add_row(row);
    }

    tableSetter::format(&table, totalColsCount, totalRowsCount);

    return table;
}

loopTracer &loopTracer::print(std::ostream &stream) {
    table().print(stream);
    stream << std::endl;
    return *this;
}
