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
    return static_cast<loopTracer &>(*this);
}

loopTracer &loopTracer::trace(pint *target, int len, int offset) {
    auto *tracer = new arrayTracer();
    tracer->trace(target, len).offset(offset);
    arrays.push_back(tracer);
    ++arrColCount;
    return static_cast<loopTracer &>(*this);
}

template<typename T>
loopTracer &loopTracer::trace(pnum<T> *target, int len, int offset) {
    auto tracer = new arrayTracer();
    tracer->trace(target, len).offset(offset);
    arrays.push_back(tracer);
    ++arrColCount;
    return static_cast<loopTracer &>(*this);
}

loopTracer &loopTracer::loop() {
    auto row = new loopRow();
    row->loopId = (int) rows.size();
    for (auto &item: rows.back()->pints) {
        row->pints.emplace_back(item.getValue());
    }
    rows.push_back(row);
    return static_cast<loopTracer &>(*this);
}

loopTracer &loopTracer::end() {
    rows.pop_back();

    for (auto &target: targets)
        target->onChanged(nullptr);

    return static_cast<loopTracer &>(*this);
}

loopTracer &loopTracer::named(std::string str) {
    tracerName = std::move(str);
    return static_cast<loopTracer &>(*this);
}

tabulate::Table loopTracer::table() {
    int totalRowsCount = (int) rows.size() + 1;
    int totalColsCount = (int) targets.size() + arrColCount + 1;
    tabulate::Table table;

    tabulate::Table::Row_t header;
    header.emplace_back("");
    for (auto &target: targets)
        header.emplace_back(target->name());
    for (auto &arr: arrays)
        header.emplace_back(arr->name());
    table.add_row(header);

    for (int i = 0; i < rows.size(); ++i) {
        tabulate::Table::Row_t row;
        row.emplace_back(std::to_string(rows[i]->loopId));
        for (auto &pint: rows[i]->pints)
            row.emplace_back(pint.history());
        for (auto &arr: arrays)
            row.emplace_back(arr->history(i));
        table.add_row(row);
    }

    tableSetter::format(&table, totalColsCount, totalRowsCount);

    return table;
}

loopTracer &loopTracer::printTo(std::ostream &stream) {
    table().print(stream);
    stream << std::endl;
    return static_cast<loopTracer &>(*this);
}
