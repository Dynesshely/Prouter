# About

Prouter is a library that allows you to trace your code and visualize your algorithm.

# Usages

## Includes

```c++
#include "./includes/includes.h"
```

and you'd better do like this:

```c++
#include "./includes/includes.h"

int main() {

#include "./includes/predefine.h"
    
......
```

## Trace a var

```c++
#include "./includes/predefine.h"

double a = 3.0;
a = 4.0;

std::cout << textBuilder::varChangeHistoryText(&a) << std::endl;
```

Output:

```text
3.000000 -> 4.000000
```

## Trace a loop

```c++
#include "./includes/predefine.h"

auto tracer = prouter::traceLoop();

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

tracer.end();

std::cout << std::endl << tracer.tableText() << std::endl;
```

Output:

```text
  | i      | fc     | 
0 | 1 -> 2 | 0 -> 1 | 
1 | 2 -> 3 | 1 -> 1 | 
2 | 3 -> 4 | 1 -> 2 | 
3 | 4 -> 5 | 2 -> 3 |
```
