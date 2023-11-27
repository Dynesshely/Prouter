#include <iostream>

#include "../includes/includes.hpp"

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

  std::cout << std::endl;

  for (int i = 0; i < a.historicalValuesCount(); ++i) {
    std::cout << i[i] << ": " << a[i] << std::endl;
  }

  std::cout << std::endl;

  int f[1000];
  f[1] = 1;
  f[2] = 1;

  for (int i = 3; i <= 7; ++i) {
    f[i] = f[i - 1] + f[i - 2];
    std::cout << f[i] << std::endl;
  }
}
