# C++ Pointers Interview Quiz

> Difficulty: ⭐⭐☆☆☆ (Beginner–Intermediate)
>
> Try to answer without running the code.

---

# Q1. Output Prediction

```cpp
int x = 10;
int *p = &x;

cout << *p << endl;
cout << p << endl;
```

What is printed?

---

# Q2. Output Prediction

```cpp
int arr[] = {5, 10, 15, 20};

cout << *(arr + 2);
```

A. 10

B. 15

C. 20

D. Address of arr[2]

---

# Q3. What is the output?

```cpp
int arr[] = {1,2,3};

cout << arr[1] << endl;
cout << *(arr+1);
```

A. Different outputs

B. Same outputs

C. Compilation Error

D. Garbage Value

---

# Q4. Pointer Arithmetic

```cpp
int arr[] = {10,20,30,40};

int *p = arr;

p++;

cout << *p;
```

Output?

---

# Q5. Find the Error

```cpp
int arr[5];

arr = arr + 1;
```

Why is this invalid?

---

# Q6. What does this print?

```cpp
char ch[] = "Code";

cout << ch;
```

A. Address

B. C

C. Code

D. Garbage

---

# Q7. What does this print?

```cpp
int arr[] = {1,2,3};

cout << arr;
```

A. 1

B. Address

C. 123

D. Garbage

---

# Q8. Predict the Output

```cpp
void update(int *p){
    *p = *p + 5;
}

int x = 10;

update(&x);

cout << x;
```

---

# Q9. Predict the Output

```cpp
void update(int *p){
    p++;
}

int x = 10;
int *ptr = &x;

update(ptr);

cout << *ptr;
```

Output?

---

# Q10. Arrays in Functions

```cpp
void fun(int arr[]){
    cout << sizeof(arr);
}
```

What does `sizeof(arr)` return on a 64-bit machine?

A. 40

B. 8

C. 4

D. Depends on array size

---

# Q11. Double Pointer

```cpp
int x = 7;

int *p = &x;

int **q = &p;

cout << **q;
```

Output?

---

# Q12. Triple Pointer

```cpp
int x = 5;

int *p = &x;

int **q = &p;

int ***z = &q;

cout << ***z;
```

Output?

---

# Q13. Predict the Output

```cpp
int x = 5;

int *p = &x;

int **q = &p;

**q = 20;

cout << x;
```

---

# Q14. What Changes?

```cpp
void update(int **ptr){
    *ptr = *ptr + 1;
}
```

Which one changes?

A. Value

B. Pointer

C. Double Pointer

D. Nothing

---

# Q15. Predict the Output

```cpp
int arr[] = {2,4,6,8};

cout << arr[2] << endl;

cout << *(2 + arr);
```

---

# Q16. Complete the Statement

```
arr[i] = ____________
```

---

# Q17. Which is TRUE?

A.

```cpp
sizeof(array) == sizeof(pointer)
```

B.

Array names can be reassigned.

C.

Pointers can be reassigned.

D.

`arr` stores the last element.

---

# Q18. Which Statement is FALSE?

A. Pointer stores an address.

B. Double pointer stores address of another pointer.

C. Triple pointer stores value directly.

D. Arrays decay into pointers when passed to functions.

---

# Q19. Spot the Bug

```cpp
int *p;

cout << *p;
```

Why is this dangerous?

---

# Q20. Interview Coding Question

Without using `arr[i]`, print every element of the array.

```cpp
int arr[] = {1,2,3,4,5};
```

Use only pointer arithmetic.

---

# Answers

| Q | Answer |
|---|--------|
| 1 | `10` then address of `x` |
| 2 | **B** |
| 3 | **B** |
| 4 | `20` |
| 5 | Array names cannot be reassigned |
| 6 | **C** |
| 7 | **B** |
| 8 | `15` |
| 9 | `10` |
| 10 | **B (8 bytes)** |
| 11 | `7` |
| 12 | `5` |
| 13 | `20` |
| 14 | **B** |
| 15 | `6` and `6` |
| 16 | `*(arr+i)` |
| 17 | **C** |
| 18 | **C** |
| 19 | Wild pointer (uninitialized pointer) |
| 20 | ```cpp
for(int *p = arr; p < arr + 5; p++)
    cout << *p << " ";
``` |