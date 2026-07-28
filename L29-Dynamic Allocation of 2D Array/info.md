# Dynamic 2D Array in C++

## Static 2D Array

In static memory allocation, the size of the array is fixed at compile time.

```cpp
int arr[5][5];
```

- Memory is allocated automatically.
- Size cannot be changed during runtime.
- Stored in stack memory.

---

# Dynamic 2D Array

Dynamic memory allocation allows us to create arrays during runtime using heap memory.

A 2D array can be considered as a collection of multiple 1D arrays (rows).

Example:

```
2D Array:

[ 1  2  3 ]
[ 4  5  6 ]
[ 7  8  9 ]

It is a collection of 3 rows (1D arrays)
```

---

## Creating Dynamic 1D Array

A normal 1D dynamic array is created using:

```cpp
int* arr = new int[n];
```

Here:

- `arr` stores the address of the first element.
- `n` represents the number of integer blocks allocated in heap memory.

---

# Creating Dynamic 2D Array

Since a 2D array is a collection of 1D arrays:

First create an array of pointers.

```cpp
int** arr = new int*[row];
```

### Explanation

`int**` means a pointer to a pointer.

It creates an array of `row` pointers:

```
arr
 |
 |---- int*
 |---- int*
 |---- int*
 |---- ...
```

Each pointer will store the address of one row.

Now allocate memory for each row:

```cpp
for(int i = 0; i < row; i++)
{
    arr[i] = new int[col];
}
```

After allocation:

```
arr
 |
 |----> [ ][ ][ ]  Row 0
 |
 |----> [ ][ ][ ]  Row 1
 |
 |----> [ ][ ][ ]  Row 2
```

Each row is a separate 1D array.

---

# Taking Input

Nested loops are used to access every element.

```cpp
for(int i = 0; i < row; i++)
{
    for(int j = 0; j < col; j++)
    {
        cin >> arr[i][j];
    }
}
```

- `i` represents the row index.
- `j` represents the column index.

---

# Printing Output

```cpp
for(int i = 0; i < row; i++)
{
    for(int j = 0; j < col; j++)
    {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
```

---

# Freeing Dynamic Memory

Dynamic arrays are created in **heap memory**, so they must be manually deleted.

A dynamic 2D array contains:

1. Individual row arrays
2. Main array containing row pointers

Therefore, deletion should happen in reverse order.

### Step 1: Delete Rows

```cpp
for(int i = 0; i < row; i++)
{
    delete [] arr[i];
}
```

### Step 2: Delete Pointer Array

```cpp
delete [] arr;
```

---

# Memory Deallocation Order

```
Create:

Array of pointers
        |
        |
   Row arrays


Delete:

1. Row arrays
2. Array of pointers
```

Deleting the main pointer array first will cause memory leaks because row addresses will be lost.

---

# Complete Dynamic 2D Array Flow

```
Take rows and columns

        ↓

Create array of row pointers

        ↓

Allocate memory for each row

        ↓

Store elements using arr[i][j]

        ↓

Print elements

        ↓

Delete rows

        ↓

Delete pointer array
```

---

# Key Points

- Static 2D array:
  ```cpp
  int arr[5][5];
  ```

- Dynamic 2D array:
  ```cpp
  int** arr = new int*[row];
  ```

- A dynamic 2D array is actually an array of pointers pointing to multiple 1D arrays.

- Heap memory does not get freed automatically, so use:
  ```cpp
  delete[]
  ```
  to release memory.