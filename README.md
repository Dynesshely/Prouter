# About

Prouter is a library that allows you to trace your code and visualize your algorithm.

# Usages

## Includes

```c++
#include <prouter/includes.h>
```

and you'd better include `predefine.h` after main function like this:

```c++
#include <prouter/includes.h>

int main() {

#include <prouter/predefine.h>
......
```

## Trace a var

```c++
double a = 3.0;
a = 4.0;
a *= 2.0;

std::cout << a.history() << std::endl;
```

Output:

```text
3.000000 -> 4.000000 -> 8.000000
```

## Trace an array

```c++
auto arrTracer = prouter::traceArray();

int arr[10] = {0};

arrTracer.trace(arr, 10);

for (int i = 0; i < 10; ++i)
    arr[i] = i;

std::cout << arrTracer.history() << std::endl;
```

Output:

```text
[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
[0, 1, 2, 0, 0, 0, 0, 0, 0, 0]
[0, 1, 2, 3, 0, 0, 0, 0, 0, 0]
[0, 1, 2, 3, 4, 0, 0, 0, 0, 0]
[0, 1, 2, 3, 4, 5, 0, 0, 0, 0]
[0, 1, 2, 3, 4, 5, 6, 0, 0, 0]
[0, 1, 2, 3, 4, 5, 6, 7, 0, 0]
[0, 1, 2, 3, 4, 5, 6, 7, 8, 0]
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

## Trace a loop

```c++
auto loopTracer = prouter::traceLoop().named("loop 1");

int f[1000], i = 1, fc;
f[1] = 1;
f[2] = 1;

loopTracer.trace(&i.named("i"))
          .trace(&fc.named("fc"));

for (; i <= 10; ++i, loopTracer.loop()) {
    if (i >= 3)
        f[i] = f[i - 1] + f[i - 2];
    fc.setValue(f[i]);
}

loopTracer.end().printTo(std::cout);
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
