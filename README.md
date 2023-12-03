# About

Prouter is a library that allows you to trace your code and visualize your algorithm.

# Usages

## Trace a loop

```c++
#define int pint

auto tracer = prouter::traceLoop();

int f[1000], i = 1, fc;
f[1] = 1;
f[2] = 1;

tracer.trace(&i.named("i"))
      .trace(&fc.named("fc"));

for (; i <= 4; ++i, tracer.loop()) {
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
