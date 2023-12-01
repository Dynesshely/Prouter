class textBuilder {
private:
public:
    static std::string varChangeHistoryText(pint *v) {
        std::string text;
        for (int k = 0; k < v->historicalValuesCount(); ++k) {
            text += std::to_string(v[k]);

            if (k < v->historicalValuesCount() - 1)
                text += " -> ";
        }
        return text;
    }

    static std::string *meetLength(std::string *str, int len, char c) {
        auto currentLen = (int) str->length();
        if (currentLen < len)
            (*str) += buildText(c, len - currentLen);
        return str;
    }

    static std::string buildText(char c, int repeat) {
        std::string text;
        for (int i = 0; i < repeat; ++i)
            text += c;
        return text;
    }
};
