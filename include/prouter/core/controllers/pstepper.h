#pragma once

#ifndef PROUTER_CORE_CONTROLLERS_PSTEPPER_H
#define PROUTER_CORE_CONTROLLERS_PSTEPPER_H

#include <cstdio>
#include <ostream>
#include <utility>

class pstepper {
public:
  explicit pstepper(bool enabled);

  pstepper &setTip(std::string tip);

  pstepper &wait();

private:
  std::string tip;

  bool enabled = false;

  pstepper &me() { return static_cast<pstepper &>(*this); }
};


#endif
