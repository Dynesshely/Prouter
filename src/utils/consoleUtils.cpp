void consoleUtils::eraseLines(int count, std::ostream &stream) {
    if (count <= 0) return;

    stream << "\x1b[2K";
    for (int i = 1; i < count; ++i)
        stream << "\x1b[1A" << "\x1b[2K";
    stream << "\r";
}