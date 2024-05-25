#pragma once

#include <iostream>
#include <utility>

class pstepper {
public:
    explicit pstepper(bool enabled);

    pstepper &setTip(std::string tip);

    pstepper &wait();

private:
    std::string tip;

    bool enabled = false;

    pstepper &me() {
        return static_cast<pstepper &>(*this);
    }
};

#include "../../../../src/core/controllers/pstepper.cpp"
