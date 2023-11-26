#include <iostream>

#include "../includes/core/includes.hpp"

int main() {

#define int pint

  int a = 10;
  a + 5;
  std::cout << a << std::endl;
  a += 10;
  a *= 2;
  a -= 30;
  a /= 2;
  std::cout << a << std::endl;
  ++a, a++;
  --a, a--;
  std::cout << a << std::endl;
}
