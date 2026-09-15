# Merge Sort & Inversion Count — Notes

## 1. `merge()` Function

```cpp
void merge(int *arr, int start, int end)
```

**Parameters**
| Param | Meaning |
|-------|---------|
| `arr` | original array |
| `start` | starting index |
| `end` | ending index |

> Assumes both halves `[start, mid]` and `[mid+1, end]` are **already sorted**, and combines them into one sorted range.

### Step-by-step

**Find the middle**
```cpp
int mid = start + (end - start) / 2;
```
Example: `start = 0, end = 3` → `mid = 1`
```
[10, 20 | 5, 15]
        ↑
       mid
```

**Find sizes of both halves**
```cpp
int len1 = mid - start + 1;   // size of first half
int len2 = end - mid;         // size of second half
```

**Create temporary arrays**
```cpp
int *first  = new int[len1];
int *second = new int[len2];
```

**Copy first half**
```cpp
int k = start;
for (int i = 0; i < len1; i++)
    first[i] = arr[k++];
```
`arr = [10, 20, 5, 15]` → `first = [10, 20]`

**Copy second half**
```cpp
k = mid + 1;
for (int i = 0; i < len2; i++)
    second[i] = arr[k++];
```
`second = [5, 15]`

**Three pointers**
```cpp
int index1 = 0;         // pointer into first[]
int index2 = 0;         // pointer into second[]
int mainArrayIndex = start;  // pointer into arr[]
```

**Merge — compare and place smaller element**
```cpp
while (index1 < len1 && index2 < len2)
{
    if (first[index1] < second[index2])
        arr[mainArrayIndex++] = first[index1++];
    else
        arr[mainArrayIndex++] = second[index2++];
}
```

**Copy leftovers** (only one of these runs)
```cpp
while (index1 < len1)
    arr[mainArrayIndex++] = first[index1++];

while (index2 < len2)
    arr[mainArrayIndex++] = second[index2++];
```

**Free memory**
```cpp
delete[] first;
delete[] second;
```

---

## 2. `MergeSort()` — Recursion

```cpp
void MergeSort(int *arr, int start, int end)
{
    if (start >= end) return;              // base case: 0 or 1 element

    int mid = start + (end - start) / 2;   // find middle

    MergeSort(arr, start, mid);            // sort left half
    MergeSort(arr, mid + 1, end);          // sort right half
    merge(arr, start, end);                // merge both halves
}
```

**One-line summary:**
> `MergeSort = Divide → Recursively Sort → Merge`

---

## 3. Inversion Count (using Merge Sort)

```cpp
long long merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = start;
    for (int i = 0; i < len1; i++) first[i] = arr[k++];

    k = mid + 1;
    for (int i = 0; i < len2; i++) second[i] = arr[k++];

    int index1 = 0, index2 = 0, mainArrayIndex = start;
    long long count = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
            count += len1 - index1;   // all remaining elements in `first` are inversions
        }
    }

    while (index1 < len1) arr[mainArrayIndex++] = first[index1++];
    while (index2 < len2) arr[mainArrayIndex++] = second[index2++];

    delete[] first;
    delete[] second;
    return count;
}

long long mergeSort(int arr[], int start, int end)
{
    if (start >= end) return 0;

    int mid = start + (end - start) / 2;
    long long count = 0;

    count += mergeSort(arr, start, mid);     // inversions in left half
    count += mergeSort(arr, mid + 1, end);   // inversions in right half
    count += merge(arr, start, end);         // inversions between halves

    return count;
}
```

### Explanation

An **inversion** is a pair `(i, j)` where `i < j` but `arr[i] > arr[j]` — i.e., an earlier element that is bigger than a later one.

Both halves passed into `merge()` are already sorted (thanks to recursion), so:

- While comparing `first[index1]` and `second[index2]`:
  - If `first[index1] <= second[index2]` → no inversion, just place it normally.
  - If `second[index2]` is smaller → it "jumps ahead" of everything remaining in `first`. Since `first` holds earlier-positioned elements and all of them (`first[index1]` onward) are still larger than `second[index2]`, **each one forms an inversion with it**.
  - That's why: `count += len1 - index1;` — this adds the count of all remaining elements in `first` in one shot, instead of checking them one by one.

`mergeSort()` then just adds up three sources of inversions:
1. Inversions inside the left half → `mergeSort(arr, start, mid)`
2. Inversions inside the right half → `mergeSort(arr, mid + 1, end)`
3. Inversions **between** the two halves → `merge(arr, start, end)`

This gives the total inversion count in **O(N log N)**, same complexity as merge sort itself.

---

## 4. Applications of Merge Sort

- Sorting large datasets
- **External sorting** (when data doesn't fit in memory)
- Solving problems like:
  - Inversion Counting
  - Count Smaller on Right
  - Surpasser Count
- Used internally in language sort libraries:
  - **TimSort** (Merge Sort variant) → Python, Java (Android), Swift
  - Preferred for non-primitive types due to **stability** (QuickSort isn't stable)
  - Java: `Arrays.sort` → QuickSort | `Collections.sort` → MergeSort
- Preferred algorithm for sorting **Linked Lists**
- Easily **parallelizable** — subarrays can be sorted independently, then merged
- The `merge()` step itself is reused to efficiently solve **union** and **intersection** of two sorted arrays

---

## 5. Advantages & Disadvantages

### ✅ Advantages
| Point | Explanation |
|-------|-------------|
| Stability | Maintains relative order of equal elements |
| Guaranteed worst case | O(N log N) even in the worst case |
| Simple to implement | Clean divide-and-conquer structure |
| Naturally parallel | Subarrays sort independently before merging |

### ❌ Disadvantages
| Point | Explanation |
|-------|-------------|
| Not in-place | Requires extra memory (`O(N)` auxiliary space) |
| Slower in practice than QuickSort | QuickSort is more cache-friendly (in-place) |