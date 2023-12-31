void arrayTracer::recordHistory() {
    if (pint_begin == nullptr) return;

    std::string text;
    text += "[";
    for (int i = 0; i < pint_length; ++i) {
        text += std::to_string(*(pint_begin + i));
        if (i < pint_length - 1)
            text += ", ";
    }
    text += "]";
    historicalValues.push_back(text);
}

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

std::string arrayTracer::name() {
    return tracerName;
}

arrayTracer &arrayTracer::named(std::string str) {
    tracerName = std::move(str);
    return static_cast<arrayTracer &>(*this);
}

arrayTracer &arrayTracer::trace(pint *target, int len) {
    if (typeSelected)
        throw std::logic_error("You can only apply trace target once on each tracer.");
    else typeSelected = true;

    pint_begin = target, pint_length = len;

    recordOriginalValue<int>(nullptr);

    for (int i = 0; i < pint_length; ++i) {
        (pint_begin + i)->onChanged(
            [this](int val) {
                recordHistory();
            }
        );
    }

    return static_cast<arrayTracer &>(*this);
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

arrayTracer &arrayTracer::dispose() {
    for (int i = 0; i < pint_length; ++i)
        (pint_begin + i)->onChanged(nullptr);
    return static_cast<arrayTracer &>(*this);
}


template<typename T>
arrayTracer &arrayTracer::dispose(pnum<T> *target) {
    for (int i = 0; i < pnum_length; ++i)
        (target + i)->onChanged(nullptr);
    return static_cast<arrayTracer &>(*this);
}

tabulate::Table arrayTracer::table() {
    tabulate::Table table;

    table.add_row({tracerName});

    for (auto &historicalValue: historicalValues)
        table.add_row({historicalValue});

    table[0].format().font_align(tabulate::FontAlign::center);

    tableSetter::format(&table, 1, (int) historicalValues.size() + 1);

    return table;
}

arrayTracer &arrayTracer::printTo(std::ostream &stream, bool useTable) {
    if (useTable) {
        table().print(stream);
        stream << std::endl << std::endl;
    } else stream << history() << std::endl;
    return static_cast<arrayTracer &>(*this);
}

std::string arrayTracer::history() {
    std::string text;
    for (auto &i: historicalValues)
        text += i + "\n";
    return text;
}

std::string arrayTracer::history(int index) {
    int i = index - loop_offset;

    if (i < 0)
        return originalValue;
    else if (i >= historicalValues.size())
        return historicalValues.back();
    else
        return historicalValues[i];
}

arrayTracer &arrayTracer::offset(int offset) {
    loop_offset = offset;

    return static_cast<arrayTracer &>(*this);
}
