# Static vs Dynamic Memory Allocation in C++

## 1. Reference Variables

A **reference variable** is another name (alias) for an existing variable. Both variables refer to the **same memory location**.

```cpp
int i = 5;
int &j = i;

j++;
cout << i;   // Output: 6
```

### Why use references?

Without references (Pass by Value):

```cpp
void update(int x) {
    x++;
}

int main() {
    int i = 5;
    update(i);
    cout << i;    // 5
}
```

A **copy** of `i` is created, so changes do not affect the original variable.

With references (Pass by Reference):

```cpp
void update(int &x) {
    x++;
}

int main() {
    int i = 5;
    update(i);
    cout << i;    // 6
}
```

No copy is created. `x` and `i` refer to the same memory.

---

# Returning a Reference

```cpp
int& func(int a) {
    int num = a;
    int &ans = num;
    return ans;
}
```

❌ **Bad Practice**

`num` is a local variable stored on the stack. Once the function ends, it is destroyed, making the returned reference invalid (dangling reference).

---

# Static Memory Allocation (Stack)

Memory allocated during compilation is called **static memory allocation**.

Example:

```cpp
int arr[100];
```

Characteristics:

- Stored in **Stack Memory**
- Memory size is fixed at compile time
- Automatically released when it goes out of scope
- Very fast allocation and deallocation

---

# Variable Length Arrays (VLA)

```cpp
int n;
cin >> n;

int arr[n];
```

Although some compilers (like GCC) allow this, **it is not standard C++**.

Problems:

- Stack size is limited.
- A very large value of `n` may cause a stack overflow.
- Prefer dynamic allocation (or `std::vector`) when the size is known only at runtime.

---

# Dynamic Memory Allocation (Heap)

When memory size is known **only during program execution**, allocate memory on the **Heap** using the `new` keyword.

```cpp
int *p = new int;
char *c = new char;
```

Since heap memory has no variable name, we use a **pointer** to store its address.

---

## Dynamic Arrays

```cpp
int n;
cin >> n;

int *arr = new int[n];
```

The array is created in heap memory, and `arr` stores the address of its first element.

---

# Stack vs Heap

| Stack | Heap |
|-------|------|
| Static allocation | Dynamic allocation |
| Fast | Slightly slower |
| Automatically freed | Must be freed manually |
| Limited size | Much larger memory |
| Managed by compiler | Managed by programmer |

---

# Memory Leak

Stack memory is automatically released.

```cpp
while (true) {
    int x = 5;
}
```

Every iteration creates `x`, and it is automatically destroyed.

Heap memory is **not** released automatically.

```cpp
while (true) {
    int *p = new int;
}
```

Each iteration allocates new heap memory that is never freed.

Eventually, the program runs out of memory. This is called a **Memory Leak**.

---

# Freeing Heap Memory

Use the `delete` keyword.

### Single Variable

```cpp
int *p = new int;

delete p;
```

### Array

```cpp
int *arr = new int[n];

delete[] arr;
```

Always free dynamically allocated memory when it is no longer needed.

---

# Memory Usage Example

```cpp
int arr[50];
```

Memory used:

- `50 × 4 = 200` bytes (assuming `int` is 4 bytes)

```cpp
int *arr = new int[50];
```

Memory used:

- Array in heap: `50 × 4 = 200` bytes
- Pointer on stack: `8` bytes (on a 64-bit system)

**Total:** `208` bytes

---

# Summary

- **Reference variable:** Another name for the same memory location.
- **Pass by Reference:** No copy is created.
- **Stack Memory:** Fast, fixed-size, automatically managed.
- **Heap Memory:** Dynamic, larger, manually managed.
- Use `new` to allocate heap memory.
- Use `delete` or `delete[]` to free heap memory.
- Forgetting to free heap memory leads to **memory leaks**.