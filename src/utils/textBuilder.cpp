std::string textBuilder::meetLength(std::string str, int len, char c) {
    if (str.length() < len) {
        std::string rst;
        for (char i: str)
            rst += i;
        for (int j = 0; j < len - str.length(); ++j)
            rst += c;
        return rst;
    }
    return str;
}

std::string *textBuilder::meetLength(std::string *str, int len, char c) {
    auto currentLen = (int) str->length();
    if (currentLen < len)
        (*str) += buildText(c, len - currentLen);
    return str;
}

std::string textBuilder::buildText(char c, int repeat) {
    std::string text;
    for (int i = 0; i < repeat; ++i)
        text += c;
    return text;
}

std::string textBuilder::buildText(std::string s, int repeat) {
    std::string text;
    for (int i = 0; i < repeat; ++i)
        text += s;
    return text;
}

int textBuilder::actualWidth(const std::string &str) {
    return (int) str.length();
}

int textBuilder::actualSize(size_t s) {
    return (int) s;
}