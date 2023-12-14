void arrayTracer::recordHistory() {
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

arrayTracer &arrayTracer::trace(pint *target, int len) {
    begin = target, length = len;
    for (int i = 0; i < length; ++i)
        (begin + i)->onChanged(
            [this](int val) {
                recordHistory();
            }
        );
    return *this;
}

arrayTracer &arrayTracer::dispose() {
    for (int i = 0; i < length; ++i)
        (begin + i)->onChanged(nullptr);
    return *this;
}

std::string arrayTracer::history() {
    std::string text;
    for (auto &i: historicalValues)
        text += i + "\n";
    return text;
}
