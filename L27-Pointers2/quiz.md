# C++ Pointers Quiz

> **Instructions**
>
> - Try solving without running the code.
> - Write the output first, then verify.
> - Answers are at the end.

---

# Q1. Address Operator

```cpp
int a = 10;
int *p = &a;
```

What do the following print?

1. `p`
2. `&a`
3. `*p`
4. `&p`

---

# Q2. Pointer Arithmetic

```cpp
int arr[] = {10,20,30,40};
```

Find the output.

```cpp
cout << *arr << endl;
cout << *(arr+1) << endl;
cout << *(arr+3) << endl;
```

---

# Q3. Array Formula

Fill in the blank.

```cpp
arr[i] = ____________
```

Also write the alternative (rarely used) syntax.

---

# Q4. sizeof()

Assume:

- `int = 4 bytes`
- Pointer = `8 bytes`

```cpp
int arr[10];
int *p = arr;
```

Find:

1. `sizeof(arr)`
2. `sizeof(p)`
3. `sizeof(*p)`
4. `sizeof(&arr)`

---

# Q5. Character Array

```cpp
char ch[] = "Hello";

cout << ch;
```

What gets printed?

---

# Q6. Integer Array

```cpp
int arr[] = {1,2,3};

cout << arr;
```

What gets printed?

---

# Q7. Function Calls

```cpp
void update(int *p){
    p = p + 1;
}

int x = 5;
int *ptr = &x;

update(ptr);
```

Does `ptr` change after the function call?

---

# Q8. Value Update

```cpp
void update(int *p){
    *p = *p + 1;
}

int x = 5;

update(&x);
```

Final value of `x`?

---

# Q9. Arrays in Functions

```cpp
int sum(int arr[]){
    cout << sizeof(arr);
}
```

Why does this print `8` on a 64-bit system instead of the array size?

---

# Q10. Passing Part of an Array

```cpp
int arr[] = {1,2,3,4,5};

getSum(arr+2,3);
```

Which elements are passed?

---

# Q11. Pointer vs Array

Which one can be reassigned?

A)

```cpp
arr = arr + 1;
```

B)

```cpp
p = p + 1;
```

Explain why.

---

# Q12. Double Pointer

```cpp
int x = 5;
int *p = &x;
int **q = &p;
```

Find:

1. `*p`
2. `*q`
3. `**q`

---

# Q13. Triple Pointer

```cpp
int x = 5;
int *p = &x;
int **q = &p;
int ***z = &q;
```

Find:

1. `*z`
2. `**z`
3. `***z`

---

# Q14. update1()

```cpp
void update(int **ptr){
    ptr = ptr + 1;
}
```

What changes after calling this function?

---

# Q15. update2()

```cpp
void update(int **ptr){
    *ptr = *ptr + 1;
}
```

What changes?

---

# Q16. update3()

```cpp
void update(int **ptr){
    **ptr = **ptr + 1;
}
```

What changes?

---

# Q17. Symbol Table

Why is this invalid?

```cpp
int arr[5];

arr = arr + 1;
```

---

# Q18. Conceptual

Why must a pointer have a data type?

Give **two reasons**.

---

# Q19. Fill in the Blanks

```
Variable
   ↑
_________
   ↑
_________
   ↑
_________
```

---

# Q20. One-Line Definitions

Define:

1. Pointer
2. Double Pointer
3. Triple Pointer
4. Dereferencing
5. Pointer Arithmetic

---

# ---------------- ANSWERS ----------------

## A1

1. Address of `a`
2. Address of `a`
3. `10`
4. Address of pointer `p`

---

## A2

```
10
20
40
```

---

## A3

```cpp
*(arr+i)
```

Alternative:

```cpp
i[arr]
```

---

## A4

```
40
8
4
8
```

---

## A5

```
Hello
```

---

## A6

Address of first element.

---

## A7

No.

Only the local copy of the pointer changes.

---

## A8

```
6
```

---

## A9

Because arrays decay into pointers when passed to functions.

---

## A10

```
3
4
5
```

---

## A11

Only

```cpp
p = p + 1;
```

is valid.

Array names are constant addresses stored in the symbol table.

---

## A12

```
*p  -> 5
*q  -> address of x
**q -> 5
```

---

## A13

```
*z   -> address of p
**z  -> address of x
***z -> 5
```

---

## A14

Nothing.

Only the local copy of the double pointer changes.

---

## A15

Pointer `p` changes.

The value remains unchanged.

---

## A16

The value changes.

Example:

```
5 → 6
```

---

## A17

Because an array name is a fixed address stored in the symbol table and cannot be reassigned.

---

## A18

1. To know the type of data stored.
2. To know how many bytes to read/write from memory.

---

## A19

```
Variable
   ↑
Pointer
   ↑
Double Pointer
   ↑
Triple Pointer
```

---

## A20

- **Pointer:** Stores the address of a variable.
- **Double Pointer:** Stores the address of another pointer.
- **Triple Pointer:** Stores the address of a double pointer.
- **Dereferencing:** Accessing the value stored at an address using `*`.
- **Pointer Arithmetic:** Performing arithmetic operations (`+`, `-`) on pointers to move between memory locations.