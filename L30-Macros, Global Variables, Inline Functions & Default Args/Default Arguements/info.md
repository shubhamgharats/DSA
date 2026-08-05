# Default Arguments in C++

## What are Default Arguments?

A **default argument** is a value assigned to a function parameter. If the caller does not provide a value for that parameter, the default value is used automatically.

### Syntax

```cpp
return_type function_name(parameters = default_value);
```

---

## Example

```cpp
#include <iostream>
using namespace std;

void print(int arr[], int n, int start = 0) {
    for (int i = start; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    int arr[5] = {1, 4, 6, 3, 5};
    int size = 5;

    print(arr, size);      // start = 0 (default)
    // print(arr, size, 2); // start = 2

    return 0;
}
```

---

## How It Works

Function declaration:

```cpp
void print(int arr[], int n, int start = 0);
```

Calling:

```cpp
print(arr, size);
```

is equivalent to:

```cpp
print(arr, size, 0);
```

If you explicitly pass a value:

```cpp
print(arr, size, 2);
```

then `start` becomes `2` instead of the default `0`.

---

## Rules for Default Arguments

- Default arguments must be specified from the **rightmost parameter**.
- Once a parameter has a default value, **all parameters to its right must also have default values**.

✔ Correct:

```cpp
void print(int arr[], int n, int start = 0);
```

❌ Incorrect:

```cpp
void print(int arr[], int n = 0, int start);
```

This is invalid because `start` has no default value after a parameter (`n`) that does.

---

## Key Points

- Default arguments make function parameters optional.
- They reduce the need for multiple overloaded functions.
- Default values are used only when the corresponding argument is omitted.
- Default arguments should generally be specified in the function declaration (or prototype), not repeatedly in both the declaration and definition.