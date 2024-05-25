pstepper::pstepper(const bool enabled) {
    pstepper::enabled = enabled;
}


pstepper &pstepper::setTip(std::string tip) {
    pstepper::tip = std::move(tip);
    return pstepper::me();
}

pstepper &pstepper::wait() {
    if (pstepper::enabled) {
        std::cout << pstepper::tip;
        auto input = getchar();
    }
    return pstepper::me();
}
