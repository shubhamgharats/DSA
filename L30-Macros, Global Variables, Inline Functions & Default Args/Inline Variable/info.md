# Inline Functions in C++

## What is an Inline Function?

An **inline function** is a function in which the compiler attempts to replace the function call with the actual function code during compilation.

It is mainly used for **small and frequently called functions** to reduce the overhead of function calls.

### Syntax

```cpp
inline int getMax(int& a, int& b) {
    return (a > b) ? a : b;
}
```

---

## Example

```cpp
#include <iostream>
using namespace std;

inline int getMax(int& a, int& b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 1, b = 2;

    int ans = getMax(a, b);
    cout << ans << endl;

    a = a + 3;
    b = b + 1;

    ans = getMax(a, b);
    cout << ans << endl;

    return 0;
}
```

---

## Why Do We Use Inline Functions?

Normally, when a function is called:

1. Control transfers from the calling function (`main()`) to the called function.
2. A new function stack frame is created.
3. After execution, control returns to the calling function.
4. This process takes a small amount of time and memory, known as **function call overhead**.

For functions that are called many times and contain only a few statements, this overhead can become unnecessary.

---

## How Inline Functions Work

When a function is declared as `inline`, the compiler **may replace the function call with the function body** during compilation.

For example,

```cpp
ans = getMax(a, b);
```

may be replaced by the compiler as:

```cpp
ans = (a > b) ? a : b;
```

This removes the need for a separate function call.

> **Note:** The `inline` keyword is only a **request** to the compiler. The compiler may choose to ignore it if inlining is not beneficial.

---

## Advantages

- Reduces function call overhead.
- Can improve performance for small, frequently used functions.
- Eliminates the overhead of creating a new function stack frame (if the function is actually inlined).
- Makes code execution slightly faster for simple operations.

---

## Disadvantages

- Increases the size of the executable if the function is inlined at many places (code bloat).
- Large functions should generally **not** be declared as inline.
- The compiler may ignore the `inline` request.

---

## When to Use Inline Functions

Use inline functions when:

- The function is very small (1–3 statements).
- The function is called frequently.
- Performance is more important than a slight increase in code size.

Avoid using inline functions for:

- Large functions.
- Recursive functions (usually not inlined).
- Functions with complex logic.

---

## Key Points

- `inline` is a request to the compiler, **not a command**.
- The compiler decides whether to inline the function.
- Inline functions reduce **function call overhead**.
- They are best suited for **small and frequently called functions**.
- Excessive use of inline functions can increase the program size.

---

## Summary

Inline functions are used to optimize small, frequently called functions by replacing function calls with the actual function code whenever the compiler decides it is beneficial. This can reduce function call overhead and improve performance, but using inline for large functions may increase the executable size without providing significant benefits.