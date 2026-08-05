# C++ Macros

## What is a Macro?

A **macro** is a preprocessor directive defined using the `#define` directive. It replaces code or values **before the compilation process begins**.

Macros are commonly used to:
- Define constant values
- Create reusable code snippets
- Perform conditional compilation
- Access predefined compiler information

---

## Preprocessor Directives

Preprocessor directives are instructions processed **before the actual compilation** of the program.

They always begin with the `#` symbol.

Example:

```cpp
#include <iostream>
```

The `#include` directive tells the preprocessor to include the contents of the `<iostream>` header file into the source code before compilation.

---

## `#define`

The `#define` directive is used to define macros.

### Why use `#define`?

Suppose you use the value of π (`3.14`) in multiple places:

```cpp
double area = 3.14 * r * r;
double circumference = 2 * 3.14 * r;
```

If the value ever needs to be changed, you would have to modify every occurrence manually.

A better approach is:

```cpp
#define PI 3.14
```

Now you can write:

```cpp
double area = PI * r * r;
double circumference = 2 * PI * r;
```

If the value changes, you only need to update the macro definition.

**Note:** Macros are simple text replacements performed by the preprocessor. They do **not** allocate memory like variables.

---

# Types of Macros in C++

## 1. Object-Like Macros

Object-like macros define constant values.

### Example

```cpp
#include <iostream>
using namespace std;

#define PI 3.14

int main() {
    int r = 5;
    double area = PI * r * r;

    cout << "Area is: " << area << endl;

    return 0;
}
```

---

## 2. Function-Like Macros

These macros accept parameters and resemble functions, but they are simply text replacements.

### Example

```cpp
#include <iostream>
using namespace std;

#define SQUARE(x) ((x) * (x))

int main() {
    int n = 5;

    cout << "Square of " << n << " is " << SQUARE(n);

    return 0;
}
```

### Why use extra parentheses?

Writing the macro as:

```cpp
#define SQUARE(x) ((x) * (x))
```

prevents unexpected results due to operator precedence.

For example:

```cpp
SQUARE(2 + 3)
```

expands to:

```cpp
((2 + 3) * (2 + 3))
```

which correctly evaluates to:

```
25
```

---

## 3. Conditional Macros (Conditional Compilation)

Conditional macros allow certain parts of the code to be compiled only when a condition is satisfied.

The most commonly used directives are:

- `#ifdef`
- `#ifndef`
- `#else`
- `#endif`

### Example

```cpp
#include <iostream>

#define DEBUG

int main() {
    int x = 5, y = 10;
    int sum = x + y;

#ifdef DEBUG
    std::cout << "[DEBUG] x = " << x << std::endl;
    std::cout << "[DEBUG] y = " << y << std::endl;
    std::cout << "[DEBUG] sum = " << sum << std::endl;
#endif

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
```

### Output (when `DEBUG` is defined)

```
[DEBUG] x = 5
[DEBUG] y = 10
[DEBUG] sum = 15
Sum: 15
```

If `DEBUG` is **not** defined, only the following line is compiled:

```
Sum: 15
```

This technique is commonly used for **debugging** without affecting the final (release) version of the program.

---

## 4. Predefined Macros

Predefined macros are built into the C++ compiler.

You do not need to define them yourself.

Some commonly used predefined macros are:

| Macro | Description |
|--------|-------------|
| `__LINE__` | Current line number in the source file |
| `__FILE__` | Name of the current source file |
| `__DATE__` | Date on which the program was compiled |
| `__TIME__` | Time at which the program was compiled |

### Example

```cpp
#include <iostream>
using namespace std;

int main() {

    cout << "This is line " << __LINE__
         << " in file " << __FILE__ << endl;

    cout << "Compiled on " << __DATE__ << endl;
    cout << "Compiled at " << __TIME__ << endl;

    return 0;
}
```

### Sample Output

```
This is line 8 in file main.cpp
Compiled on Aug 5 2026
Compiled at 19:45:18
```

---

# Advantages of Macros

- Reduce code duplication
- Improve code readability
- Easy to update constant values
- No runtime overhead (text replacement happens before compilation)
- Useful for debugging and conditional compilation

---

# Disadvantages of Macros

- No type checking
- Difficult to debug because they are expanded before compilation
- Can produce unexpected results if not written carefully
- Function-like macros are generally less safe than inline functions

---

# Summary

- Macros are created using the `#define` directive.
- They are processed by the **preprocessor** before compilation.
- Macros perform **text replacement**, not variable storage.
- Four common types of macros are:
  1. Object-like macros
  2. Function-like macros
  3. Conditional macros
  4. Predefined macros