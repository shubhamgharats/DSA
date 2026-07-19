# Arrays & Pointers in C++

## 1. Array Address

- The name of an array stores the address of its first element.

```cpp
int arr[5] = {1,2,3,4,5};

arr      // Address of arr[0]
&arr     // Address of entire array
&arr[0]  // Address of first element
```

> `arr` and `&arr[0]` have the same address value.

---

## 2. Pointer Arithmetic

```cpp
*arr        // First element
*(arr+1)    // Second element
*(arr+2)    // Third element
```

### Formula

```cpp
arr[i] == *(arr + i)
```

Also valid (but rarely used):

```cpp
i[arr] == *(i + arr)
```

---

## 3. Address of Elements

```cpp
&arr[0]
&arr[1]
&arr[2]
```

Each address differs by `sizeof(data type)` bytes.

---

## 4. sizeof() with Arrays and Pointers

```cpp
int arr[10];
```

| Expression | Meaning |
|-----------|---------|
| `sizeof(arr)` | Size of entire array |
| `sizeof(*arr)` | Size of one element |
| `sizeof(&arr)` | Size of array address |
| `sizeof(ptr)` | Size of pointer |
| `sizeof(*ptr)` | Size of value pointed to |
| `sizeof(&ptr)` | Size of pointer's address |

**Example (64-bit system)**

```cpp
sizeof(arr)   = 40 bytes
sizeof(ptr)   = 8 bytes
sizeof(*ptr)  = 4 bytes
```

---

# Character Array vs Integer Array

## Integer Array

```cpp
cout << arr;
```

Prints the **address**.

---

## Character Array

```cpp
char ch[] = "abcd";
cout << ch;
```

Prints the **entire string** until the null character (`'\0'`).

---

## Character Pointer

```cpp
char *c = ch;
cout << c;
```

Prints:

```
abcd
```

---

## Integer Pointer

```cpp
int *p = arr;
cout << p;
```

Prints the **memory address**.

---

# Passing Pointer to Functions

## Print Address

```cpp
void print1(int *p){
    cout << p;
}
```

Prints the address.

---

## Print Value

```cpp
void print2(int *p){
    cout << *p;
}
```

Prints the value.

---

# Updating a Pointer

## Changing Pointer

```cpp
void update1(int *p){
    p = p + 1;
}
```

- Changes only the local copy.
- Original pointer remains unchanged.

---

## Changing Value

```cpp
void update2(int *p){
    *p = *p + 1;
}
```

- Modifies the value stored at the address.
- Original variable changes.

---

# Arrays Passed to Functions

```cpp
int getSum(int arr[], int n)
```

Actually becomes:

```cpp
int getSum(int *arr, int n)
```

So,

```cpp
sizeof(arr)
```

inside the function gives the **pointer size (8 bytes)**, **not** the array size.

---

# Passing Part of an Array

```cpp
getSum(arr + 3, 2);
```

Starts from index `3`.

Example:

```cpp
{1,2,3,4,5}

arr+3
 ↓
4 5
```

Sum = `9`

---

# Pointer vs Array

| Array | Pointer |
|-------|---------|
| Fixed-size collection | Variable storing an address |
| Cannot be reassigned | Can point elsewhere |
| `sizeof(array)` = total array size | `sizeof(pointer)` = pointer size |
| Array name acts like constant pointer | Pointer value can change |

---

# Symbol Table

A **symbol table** is maintained by the compiler.

It stores information about identifiers such as:
- Variable name
- Data type
- Scope
- Memory address

### Important

- The **array name** is stored in the symbol table.
- Since it represents a fixed memory location, it **cannot be reassigned**.

```cpp
int arr[5];

arr = arr + 1;   // ❌ Invalid
```

But a pointer can be changed:

```cpp
int *p = arr;

p = p + 1;       // ✅ Valid
```

---

# Quick Revision

- `arr` → Address of first element.
- `arr[i] == *(arr+i)`
- `sizeof(array)` → Total array size.
- `sizeof(pointer)` → Pointer size (usually 8 bytes).
- `char[]` prints the string.
- `int[]` prints the address.
- Arrays passed to functions become pointers.
- `p = p + 1` changes the pointer.
- `*p = *p + 1` changes the value.
- Array names cannot be reassigned; pointers can.
```