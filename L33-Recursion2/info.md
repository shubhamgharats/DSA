# Recursion – Array & Search Problems

## 1. Sum of Array using Recursion

### Idea

Instead of calculating the sum of the entire array at once, reduce the problem:

```text
sum of [1, 2, 3, 4, 5]

= 1 + sum of [2, 3, 4, 5]
= 1 + 2 + sum of [3, 4, 5]
= ...
```

Each recursive call solves a **smaller array**.

### Function

```cpp
int arraySum(int arr[], int size)
{
    if (size == 0)
        return 0;

    if (size == 1)
        return arr[0];

    int smallProblem = arraySum(arr + 1, size - 1);
    int sum = arr[0] + smallProblem;

    return sum;
}
```

### Important Concept

```cpp
arr + 1
```

moves the array pointer to the next element.

For:

```text
arr = [1, 2, 3, 4, 5]
```

the calls work like:

```text
arraySum(arr, 5)
       ↓
arraySum(arr+1, 4)
       ↓
arraySum(arr+2, 3)
       ↓
...
```

### Recursion Pattern

```text
Solve smaller array
        ↓
Add current element
```

### Base Case

When only one element remains:

```cpp
if (size == 1)
    return arr[0];
```

There is nothing more to recursively calculate.

---

## 2. Binary Search using Recursion

### Idea

Binary Search repeatedly cuts the search space in half.

For a sorted array:

```text
10  20  30  40  50
        ↑
       mid
```

If the target is greater than `arr[mid]`, search the **right half**.
If the target is smaller, search the **left half**.

### Function

```cpp
bool binarySearch(int n, int arr[], int start, int end)
{
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == n)
        return true;

    if (arr[mid] < n)
        return binarySearch(n, arr, mid + 1, end);
    else
        return binarySearch(n, arr, start, mid - 1);
}
```

> **Good practice:** pass the new bounds directly as function arguments
> (`mid + 1`, `mid - 1`) rather than assigning to `start`/`end` inside the
> call. This keeps each recursive call's range explicit and easy to trace.

### Recursive Thinking

For:

```text
10 20 30 40 50
target = 40
```

First:

```text
start = 0
end = 4
mid = 2

arr[2] = 30
```

Since `40 > 30`, ignore the left half:

```text
10 20 | 30 | 40 50
              ↑
         search here
```

Next call:

```cpp
binarySearch(n, arr, mid + 1, end);
```

### Base Case

```cpp
if (start > end)
    return false;
```

This means there is **no search space left**.

### Important

Binary Search requires the array to be **sorted**.

### Recursion Pattern

```text
Check middle
    ↓
Choose one half
    ↓
Repeat on smaller half
```

---

## 3. Check if Array is Sorted using Recursion

### Idea

An array is sorted if every adjacent pair is in the correct order.

Instead of checking the whole array:

```text
1 2 9 4 5
```

check only:

```text
arr[0] <= arr[1]
```

Then recursively check the remaining array.

### Function

```cpp
bool isSorted(int arr[], int size)
{
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    return isSorted(arr + 1, size - 1);
}
```

### Recursive Thinking

For:

```text
1 2 9 4 5
```

Check `1 <= 2` ✅, then move to `2 9 4 5`.
Check `2 <= 9` ✅, then move to `9 4 5`.
Check `9 <= 4` ❌.

Therefore: **array is NOT sorted.**

### Base Case

```cpp
if (size == 0 || size == 1)
    return true;
```

An array containing zero or one element is automatically sorted.

### Recursion Pattern

```text
Check current pair
        ↓
If valid → check remaining array
        ↓
Eventually reach size 1
        ↓
true
```

---

## 4. Linear Search using Recursion

### Idea

Linear Search checks elements one by one. Instead of using a loop, recursion performs the repetition.

### Function

```cpp
bool linearSearch(int n, int arr[], int size)
{
    if (size == 0)
        return false;

    if (arr[0] == n)
        return true;

    return linearSearch(n, arr + 1, size - 1);
}
```

### Recursive Thinking

For:

```text
1 7 5 3 2
target = 5
```

Check `1 == 5` ❌ → search `7 5 3 2`.
Check `7 == 5` ❌ → search `5 3 2`.
Check `5 == 5` ✅ → return `true`.

### Base Case

```cpp
if (size == 0)
    return false;
```

If the array has been completely searched and the element wasn't found, return `false`.

### Recursion Pattern

```text
Check current element
        ↓
Not found?
        ↓
Move to next element
        ↓
Repeat
```

---

## ⭐ What You Should Learn from These Problems

These four problems teach different ways recursion can reduce a problem:

| Problem       | How the problem becomes smaller        |
| ------------- | --------------------------------------- |
| Array Sum     | Remove first element                    |
| Linear Search | Remove first element                    |
| Sorted Array  | Check first pair, remove first element  |
| Binary Search | Keep only one half                      |

### The Common Recursion Structure

Almost every recursive problem can be thought of as:

```text
1. Base Case
       ↓
2. Process current problem
       ↓
3. Make problem smaller
       ↓
4. Recursive Call
       ↓
5. Return the result
```

### Key Patterns to Recognize

When you see:

```cpp
arr + 1
```

think: *"Move to the next element and solve the same problem on the remaining array."*

When you see:

```cpp
size - 1
```

think: *"The problem has become smaller by one."*

When you see:

```cpp
mid + 1
mid - 1
```

think: *"Discard one half and recursively solve the remaining half."*

---

## One Important C++ Detail

Since these functions return `bool`, prefer:

```cpp
return linearSearch(...);
```

instead of:

```cpp
bool ans = linearSearch(...);
return ans;
```

Both work, but the first is cleaner. For example:

```cpp
return isSorted(arr + 1, size - 1);
```

means: *"Whatever answer the smaller problem gives me, return that answer."*

This is one of the most important recursion concepts to understand.