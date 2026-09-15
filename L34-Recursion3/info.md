# Recursion – Sorting, String & Power Problems

## 1. Insertion Sort using Recursion

### Idea

Normally Insertion Sort loops over the array, picking one element at a time
and inserting it into its correct position among the already-sorted part on
its left. In the recursive version, the loop is replaced by the recursion
itself — each call handles **one element** and then hands off the rest.

### Function

```cpp
void insertionSort(int arr[], int size, int i)
{
    if (i >= size)
        return;

    int temp = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > temp)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;

    insertionSort(arr, size, i + 1);
}
```

### Recursive Thinking

- `i` is the index of the element currently being inserted.
- The `while` loop shifts every larger element one step right, then drops
  `temp` into the gap — this is identical to the iterative version's inner loop.
- The recursion only replaces the **outer loop**: instead of `for (i = 1; i < size; i++)`,
  each call processes index `i` and then calls itself with `i + 1`.

### Base Case

```cpp
if (i >= size)
    return;
```

Once `i` reaches the end of the array, every element has been inserted, so there's nothing left to do.

### Recursion Pattern

```text
Insert element at index i into the sorted left part
        ↓
Move to next index (i + 1)
        ↓
Repeat until i == size
```

---

## 2. Check if Palindrome using Recursion

### Idea

A string is a palindrome if it reads the same from both ends. Instead of
comparing all characters at once, compare **one pair at a time** — the
character at the front and its mirror at the back — and shrink inward.

### Function

```cpp
bool ifPalindrome(string &str, int i)
{
    if (i >= str.length() / 2)
        return true;

    if (str[i] != str[str.length() - i - 1])
        return false;

    return ifPalindrome(str, i + 1);
}
```

### Recursive Thinking

- `i` walks inward from the start; `str.length() - i - 1` is its mirror from the end.
- If a pair doesn't match, the whole string can't be a palindrome — return `false` immediately.
- If it matches, the outer pair is "trusted" and the same check is repeated on the next inner pair.

### Base Case

```cpp
if (i >= str.length() / 2)
    return true;
```

Once `i` passes the midpoint, every pair has already been checked and matched, so the string is a palindrome.

### Recursion Pattern

```text
Compare outer pair
        ↓
Mismatch? → false
        ↓
Match → move one step inward
        ↓
Reach the middle → true
```

---

## 3. Calculate Power (aᵇ) using Recursion — Optimized

### Idea

A naive recursive power function multiplies `a` by itself `b` times, needing
`b` recursive calls. This version instead uses the fact that:

```text
a^b = (a^(b/2))^2         if b is even
a^b = a * (a^(b/2))^2     if b is odd
```

By halving `b` at every step instead of decreasing it by 1, the number of
calls drops from `b` to roughly `log₂(b)`.

### Function

```cpp
int isPower(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int ans = isPower(a, b / 2);

    if (b % 2 == 0)
        return ans * ans;
    else
        return a * ans * ans;
}
```

### Recursive Thinking

- Each call solves the problem for **half the exponent**, then squares that result.
- If `b` was odd, integer division `b / 2` drops the extra 1, so one extra
  multiplication by `a` is needed to make up for it.

### Base Cases

```cpp
if (b == 0) return 1;   // a^0 is always 1
if (b == 1) return a;   // a^1 is just a
```

### Why This Is Faster

For `2^1024`:

```text
2^1024 → (2^512)^2 → (2^256)^2 → ... → (2^1)
```

This takes about **11 recursive calls** (since 2¹⁰ = 1024), instead of
**1024 iterations** a simple loop would need. Halving the exponent each time
is what makes this approach far more efficient than linear recursion or a
plain loop.

> Recursion tree for `isPower(3, 11)`: see `images/PowerEg1.png`.
> General halving idea illustrated in `images/PowerQuestionHint.png`.

### Recursion Pattern

```text
Halve the exponent
        ↓
Solve the smaller power
        ↓
Square the result
        ↓
Multiply by 'a' once more if the exponent was odd
```

---

## 4. Reverse a String using Recursion

Two different recursive approaches — same goal, different number of pointers.

### Version 1 — One Pointer

```cpp
void reverseString1(string &str, int i)
{
    if (i >= str.length() / 2)
        return;

    swap(str[i], str[str.length() - i - 1]);

    reverseString1(str, i + 1);
}
```

- Only `i` is tracked; the mirror index is computed as `str.length() - i - 1` each time.
- Swaps the front and back characters, then moves `i` one step inward.
- **Base case:** once `i` reaches the midpoint, every character has already been swapped.

### Version 2 — Two Pointers

```cpp
void reverseString2(string &str, int i, int j)
{
    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    reverseString2(str, i, j);
}
```

- `i` starts at the front, `j` starts at the back; they move toward each other every call.
- **Base case:** `i > j` means the pointers have crossed — the whole string has been reversed.

### Recursion Pattern (both versions)

```text
Swap the outer pair
        ↓
Move pointer(s) inward
        ↓
Repeat until pointers meet / cross
```

---

## 5. Selection Sort using Recursion

### Idea

Selection Sort repeatedly finds the **smallest remaining element** and swaps
it into its correct position at the front. The recursion replaces the outer
loop that moves through each position.

### Function

```cpp
void selctionSort(int arr[], int i, int size)
{
    if (i >= size - 1)
        return;

    int minIndex = i;

    for (int j = i + 1; j < size; j++)
    {
        if (arr[minIndex] > arr[j])
            minIndex = j;
    }

    swap(arr[minIndex], arr[i]);

    selctionSort(arr, i + 1, size);
}
```

### Recursive Thinking

- The inner `for` loop scans indices `i+1 … size-1` to find the smallest
  value — this part stays a loop even in the "recursive" version, since it's
  a simple linear scan, not the part being recursed on.
- After placing the smallest remaining element at index `i`, the recursion
  moves on to solve the same problem for the rest of the array (`i + 1` onward).

### Base Case

```cpp
if (i >= size - 1)
    return;
```

When only one element is left unsorted, it's already in its correct place — nothing more to compare.

### Recursion Pattern

```text
Find the minimum in the unsorted part
        ↓
Swap it to the front of that part
        ↓
Recurse on the rest (i + 1 onward)
```

---

## 6. Bubble Sort using Recursion

### Idea

Each full pass through the array "bubbles" the largest remaining element to
the end. The recursion replaces the outer loop that controls how many passes happen.

### Function

```cpp
void bubbleSort(int arr[], int size)
{
    if (size == 0 || size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    bubbleSort(arr, size - 1);
}
```

> **Fix:** the original loop condition was `i < size`, which reads `arr[i + 1]`
> when `i == size - 1` — one index past the end of the current pass, an
> out-of-bounds access. It should be `i < size - 1`.

### Recursive Thinking

- One full pass (the `for` loop) compares each adjacent pair and swaps them
  if out of order — this guarantees the largest element ends up at the last
  position of the current range.
- After a pass, that largest element is fixed in place, so the next
  recursive call only needs to consider a range **one element smaller**.

### Base Case

```cpp
if (size == 0 || size == 1)
    return;
```

An array with zero or one element needs no sorting.

### Recursion Pattern

```text
Run one pass (largest element bubbles to the end)
        ↓
Shrink the range by 1
        ↓
Repeat until only 1 element remains
```

---

## ⭐ Summary — How Each Problem Shrinks

| Problem         | How the problem becomes smaller                          |
| ---------------- | --------------------------------------------------------- |
| Insertion Sort   | Insert current element, move to next index                |
| Palindrome Check | Check outer pair, move inward                              |
| Power (aᵇ)       | Halve the exponent                                         |
| Reverse String   | Swap outer pair, move pointer(s) inward                    |
| Selection Sort   | Place the minimum, recurse on the remaining unsorted part  |
| Bubble Sort      | One full pass places the max at the end, shrink the range  |

### Two Families of Recursive Shrinking

- **Shrink by 1** (Insertion Sort, Selection Sort, Bubble Sort, Palindrome
  outer-in, Reverse String): each call peels off exactly one element or one
  pair, so the number of calls is proportional to the array/string size.
- **Shrink by half** (Power): each call halves the problem size, so the
  number of calls is proportional to `log₂(size)` — much faster for large inputs.

Recognizing which family a problem belongs to is a good way to predict how
many recursive calls it will take, and whether an optimization (like the
Power trick) is possible.