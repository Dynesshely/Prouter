#pragma once

#ifndef PROUTER_UTILS_CONSOLEUTILS_H
#define PROUTER_UTILS_CONSOLEUTILS_H

#include <iostream>

class consoleUtils {
public:
  static void eraseLines(int count, std::ostream &stream);
};

#endif
