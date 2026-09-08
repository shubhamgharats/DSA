# Recursion

## Definition

**Recursion** is a programming technique in which a function calls itself to solve a bigger problem by breaking it into smaller problems of the same type.

A recursive function mainly requires:

1. **Base Case** – Defines when the recursion should stop.
2. **Recursive Relation (R.R.)** – Defines how the problem is reduced into a smaller similar problem.

---

# Example 1: Power of a Number

Consider:

```text
2⁴ = 2 × 2 × 2 × 2
```

This can be written as:

```text
2ⁿ = 2 × 2ⁿ⁻¹
```

Therefore, the recursive relation is:

```text
f(n) = 2 × f(n - 1)
```

### Base Case

```text
2⁰ = 1
```

When `n = 0`, the function returns `1`.

### Code

```cpp
#include <iostream>
using namespace std;

int power(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }

    // Recursive Relation
    int smallProblem = power(n - 1);
    int bigProblem = 2 * smallProblem;

    return bigProblem;
}

int main()
{
    int n;
    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    return 0;
}
```

### Recursive Flow for `power(4)`

```text
power(4)
= 2 × power(3)
= 2 × 2 × power(2)
= 2 × 2 × 2 × power(1)
= 2 × 2 × 2 × 2 × power(0)
= 2 × 2 × 2 × 2 × 1
= 16
```

---

# Example 2: Factorial

The factorial of `5` is:

```text
5! = 5 × 4 × 3 × 2 × 1
```

This can be written as:

```text
5! = 5 × 4!
```

Therefore:

```text
n! = n × (n - 1)!
```

The recursive relation is:

```text
f(n) = n × f(n - 1)
```

### Base Case

```text
0! = 1
```

### Code

```cpp
#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }

    // Recursive Relation
    int smallProblem = factorial(n - 1);
    int bigProblem = n * smallProblem;

    return bigProblem;
}

int main()
{
    int n;
    cin >> n;

    int ans = factorial(n);

    cout << ans << endl;

    return 0;
}
```

### Recursive Flow for `factorial(5)`

```text
factorial(5)
= 5 × factorial(4)
= 5 × 4 × factorial(3)
= 5 × 4 × 3 × factorial(2)
= 5 × 4 × 3 × 2 × factorial(1)
= 5 × 4 × 3 × 2 × 1 × factorial(0)
= 120
```

---

# Important Components of Recursion

## 1. Base Case

The **base case** defines the condition where the recursive function stops calling itself.

Example:

```cpp
if (n == 0)
{
    return 1;
}
```

Without a proper base case, the function will continue calling itself.

For example:

```text
factorial(5)
→ factorial(4)
→ factorial(3)
→ factorial(2)
→ factorial(1)
→ factorial(0)
→ factorial(-1)
→ factorial(-2)
→ ...
```

Eventually, the **call stack becomes full**, causing a **stack overflow**.

---

## 2. Recursive Relation

The **recursive relation** reduces a bigger problem into a smaller problem of the same type.

Example for factorial:

```text
factorial(n) = n × factorial(n - 1)
```

Example for power:

```text
power(n) = 2 × power(n - 1)
```

---

# Types of Recursion

## 1. Head Recursion

**Head Recursion** is a type of recursion in which the recursive call occurs **before the processing**.

### Structure

```cpp
function()
{
    // Base Case

    // Recursive Relation

    // Processing
}
```

### Example

```cpp
#include <iostream>
using namespace std;

// Head Recursion
void print(int n)
{
    // Base Case
    if (n == 0)
    {
        return;
    }

    // Recursive Relation
    print(n - 1);

    // Processing
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;

    print(n);

    return 0;
}
```

### Output for `n = 5`

```text
1
2
3
4
5
```

The recursive calls first reach the base case. The processing happens while the function calls return.

---

## 2. Tail Recursion

**Tail Recursion** is a type of recursion in which the recursive call occurs **after the processing** and is the last operation of the function.

### Structure

```cpp
function()
{
    // Base Case

    // Processing

    // Recursive Relation
}
```

### Example

```cpp
#include <iostream>
using namespace std;

// Tail Recursion
void print(int n)
{
    // Base Case
    if (n == 0)
    {
        return;
    }

    // Processing
    cout << n << endl;

    // Recursive Relation
    print(n - 1);
}

int main()
{
    int n;
    cin >> n;

    print(n);

    return 0;
}
```

### Output for `n = 5`

```text
5
4
3
2
1
```

The processing happens before the recursive call, so the numbers are printed from `n` to `1`.

---

# Head Recursion vs Tail Recursion

| Head Recursion                                          | Tail Recursion                                           |
| ------------------------------------------------------- | -------------------------------------------------------- |
| Recursive call comes before processing                  | Processing comes before the recursive call               |
| Processing happens while returning from recursive calls | Processing happens before making the next recursive call |
| Example output: `1` to `n`                              | Example output: `n` to `1`                               |

---

# General Structure of Recursion

```cpp
returnType function(parameters)
{
    // Base Case
    if (condition)
    {
        return baseValue;
    }

    // Recursive Relation
    return operation(function(smallerProblem));
}
```

---

# Key Points

* **Recursion** is when a function calls itself.
* A large problem is solved by reducing it into smaller similar problems.
* Every recursive function should have a **Base Case**.
* The base case prevents infinite recursive calls.
* The **Recursive Relation** defines how the problem becomes smaller.
* Without a proper base case, recursive calls can eventually cause a **stack overflow**.
* In **Head Recursion**, the recursive call happens before processing.
* In **Tail Recursion**, processing happens before the recursive call.
