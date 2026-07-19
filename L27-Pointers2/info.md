# Double Pointers in C++

## Why Do We Declare Pointers with a Data Type?

A pointer must have a specific data type because:

1. It tells the compiler **what type of data is stored** at the memory location.
2. It tells the compiler **how many bytes to read/write** from memory.

```cpp
int *p;
char *c;
float *f;
```

---

# Double Pointer

A **double pointer** stores the address of another pointer.

### Syntax

```cpp
int *p = &i;
int **q = &p;
```

Here,

```text
i  ←  p  ←  q
```

- `p` points to `i`
- `q` points to `p`

---

# Triple Pointer

A triple pointer stores the address of a double pointer.

```cpp
int ***z = &q;
```

```text
i  ←  p  ←  q  ←  z
```

---

# Dereferencing

```cpp
int i = 5;
int *p = &i;
int **q = &p;
int ***z = &q;
```

| Expression | Output |
|-----------|--------|
| `i` | 5 |
| `*p` | 5 |
| `**q` | 5 |
| `***z` | 5 |
| `p` | Address of `i` |
| `*q` | Address of `i` |
| `**z` | Address of `i` |
| `q` | Address of `p` |
| `*z` | Address of `p` |
| `z` | Address of `q` |

---

# Relationship

```text
Variable (i)
     ↑
 Pointer (p)
     ↑
Double Pointer (q)
     ↑
Triple Pointer (z)
```

Each `*` removes one level of indirection.

Example:

```cpp
*z      // q
**z     // p
***z    // i (value)
```

---

# Updating Through Double Pointer

## 1. Changing the Double Pointer

```cpp
void update1(int **ptr){
    ptr = ptr + 1;
}
```

- Changes only the local copy.
- No effect on the original pointer.

---

## 2. Changing the Pointer

```cpp
void update2(int **ptr){
    *ptr = *ptr + 1;
}
```

- Changes the pointer (`p`).
- `p` now points to the next memory location.
- Value of `i` remains unchanged.

---

## 3. Changing the Value

```cpp
void update3(int **ptr){
    **ptr = **ptr + 1;
}
```

- Changes the value stored at `i`.

Example:

```text
Before : i = 5
After  : i = 6
```

---

# Quick Revision

- `int *p` → Pointer to an integer.
- `int **q` → Pointer to a pointer.
- `int ***z` → Pointer to a double pointer.
- `*` removes one level of indirection.
- `*p` → Value of `i`.
- `**q` → Value of `i`.
- `***z` → Value of `i`.
- `update1()` → No change.
- `update2()` → Changes the pointer.
- `update3()` → Changes the value.