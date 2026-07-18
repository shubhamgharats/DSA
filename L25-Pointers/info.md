# Pointers (C/C++) - Quick Notes

## What is a Pointer?
A **pointer** is a variable that stores the **memory address** of another variable.

---

## Basic Syntax

```cpp
int x = 10;
int *ptr = &x;
```

- `&` → **Address-of operator** (gets the address of a variable)
- `*` → **Dereference operator** (gets the value stored at the address)

Example:

```cpp
int x = 10;
int *ptr = &x;

cout << ptr;   // Address of x
cout << *ptr;  // 10
```

---

## Important Points

- A pointer is declared using the `*` operator.
- A pointer stores the **address** of a variable.
- A pointer should always be **initialized** before use.
- Pointer size depends on the system architecture:
  - **4 bytes** on 32-bit systems
  - **8 bytes** on 64-bit systems
- Pointer size is **independent of the data type**.

---

## Pointer Initialization

Correct:

```cpp
int x = 5;
int *ptr = &x;
```

Null pointer:

```cpp
int *ptr = nullptr;   // C++
```

or

```cpp
int *ptr = NULL;      // C (or older C++)
```

A null pointer points to **no valid memory location**.

---

## Wild Pointer

A pointer that is **declared but not initialized**.

```cpp
int *ptr;   // Wild pointer
```

Using it results in **undefined behavior**.

---

## Dangling Pointer

A pointer that points to memory that is **no longer valid**.

```cpp
int *ptr = new int(10);
delete ptr;

// ptr is now a dangling pointer
```

---

## Copying a Pointer

```cpp
int *q = ptr;
```

Both pointers now store the **same address**.

---

## Common Pointer Operators

| Operator | Purpose |
|----------|---------|
| `&` | Get address of a variable |
| `*` | Access value at the stored address |
| `->` | Access members using a structure/object pointer |

---

## Why Use Pointers?

- Pass variables to functions by reference
- Dynamic memory allocation
- Efficient handling of arrays and large data
- Used to build data structures like:
  - Linked Lists
  - Trees
  - Graphs
  - Stacks
  - Queues

---

## Remember

- Always initialize pointers before using them.
- `*ptr` means **access the value stored at the address held by `ptr`**.
- A pointer **always stores an address**, regardless of whether it points to an `int`, `float`, `double`, or any other type.