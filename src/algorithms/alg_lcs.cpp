void alg_lcs::init() {
    if (str_a.length() > str_b.length())
        a = &str_b, b = &str_a;
    else
        a = &str_a, b = &str_b;

    w = (int) (b->length());
    h = (int) (a->length());

    calMatrix = new int *[h + 1];
    dirMatrix = new int *[h + 1];

    for (auto i = 0; i <= h; ++i)
        calMatrix[i] = new int[w + 1], dirMatrix[i] = new int[w + 1];

    for (auto i = 0; i <= h; ++i) {
        calMatrix[i][0] = 0;
        memset(dirMatrix[i], 0, w + 1);
    }
    for (auto j = 1; j <= w; ++j)
        calMatrix[0][j] = 0;
}

void alg_lcs::trace(int i, int m, int n) {
    if (m == 0 || n == 0)
        return;
    switch (dirMatrix[m][n]) {
        case 1:
            trace(i, m - 1, n - 1);
            results[i].push_back((*a)[m - 1]);
            break;
        case 2:
            trace(i, m - 1, n);
            break;
        case 3:
            trace(i, m, n - 1);
            break;
    }
}

alg_lcs &alg_lcs::setValue(std::string sa, std::string sb) {
    str_a = std::move(sa), str_b = std::move(sb);
    init();
    return static_cast<alg_lcs &>(*this);
}

alg_lcs &alg_lcs::run() {
    for (auto i = 1; i <= h; ++i)
        for (auto j = 1; j <= w; ++j) {
            auto same = (*a)[i - 1] == (*b)[j - 1];
            calMatrix[i][j] = (
                same ? calMatrix[i - 1][j - 1] + 1 :
                std::max(
                    calMatrix[i][j - 1], calMatrix[i - 1][j]
                )
            );
            dirMatrix[i][j] = same ? 1 : (
                calMatrix[i - 1][j] >= calMatrix[i][j - 1] ? 2 : 3
            );
        }

    for (auto i = 0; i < w; ++i)
        results.emplace_back("");

    for (int j = w; j >= 1; --j)
        trace(w - j, h, w - (w - j));

    return static_cast<alg_lcs &>(*this);
}

alg_lcs &alg_lcs::printLcsTo(std::ostream &stream) {
    for (const auto &s: results)
        if (s.length() == results[0].length())
            stream << "len: " << results[0].length() << "\tlcs: " << s << std::endl;

    return static_cast<alg_lcs &>(*this);
}

std::vector<std::string> alg_lcs::getResults() { return results; }

int alg_lcs::getLcsLength() { return results[0].length(); }
