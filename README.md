# About

Prouter is a library that allows you to trace your code and visualize your algorithm.

# Usages

## Includes

```c++
#include <prouter/prouterIncludes.h>
```

and you'd better do like this:

```c++
#include <prouter/prouterIncludes.h>

int main() {

#include <prouter/prouterPredefine.h>
......
```

## Trace a var

```c++
#include <prouter/prouterIncludes.h>
#include <prouter/prouterPredefine.h>

double a = 3.0;
a = 4.0;
a *= 2.0;

std::cout << a.history() << std::endl;
```

Output:

```text
3.000000 -> 4.000000 -> 8.000000
```

## Trace a loop

```c++
#include <prouter/prouterPredefine.h>

auto tracer = prouter::traceLoop().named("loop 1");

int f[1000], i = 1, fc;
f[1] = 1;
f[2] = 1;

tracer.trace(&i.named("i"))
      .trace(&fc.named("fc"));

for (; i <= 10; ++i, tracer.loop()) {
    if (i >= 3)
        f[i] = f[i - 1] + f[i - 2];
    fc.setValue(f[i]);
}

tracer.end().printTo(std::cout);
```

Output:

```text
╔═══╦══════════╦══════════╗
║   ║ i        ║ fc       ║
╠═══╬══════════╬══════════╣
║ 0 ║ 1 -> 2   ║ 0 -> 1   ║
╠═══╬══════════╬══════════╣
║ 1 ║ 2 -> 3   ║ 1 -> 1   ║
╠═══╬══════════╬══════════╣
║ 2 ║ 3 -> 4   ║ 1 -> 2   ║
╠═══╬══════════╬══════════╣
║ 3 ║ 4 -> 5   ║ 2 -> 3   ║
╠═══╬══════════╬══════════╣
║ 4 ║ 5 -> 6   ║ 3 -> 5   ║
╠═══╬══════════╬══════════╣
║ 5 ║ 6 -> 7   ║ 5 -> 8   ║
╠═══╬══════════╬══════════╣
║ 6 ║ 7 -> 8   ║ 8 -> 13  ║
╠═══╬══════════╬══════════╣
║ 7 ║ 8 -> 9   ║ 13 -> 21 ║
╠═══╬══════════╬══════════╣
║ 8 ║ 9 -> 10  ║ 21 -> 34 ║
╠═══╬══════════╬══════════╣
║ 9 ║ 10 -> 11 ║ 34 -> 55 ║
╚═══╩══════════╩══════════╝
```
