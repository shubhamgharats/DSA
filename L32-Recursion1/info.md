Yes. You want **exactly the same style as your original notes** — headings, definitions, explanation, code, recursive flow, and key points. No extra restructuring.

````md
# Example 3: Climbing Stairs

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb **1 step or 2 steps**.

The goal is to find the number of distinct ways to reach the top.

For example, if `n = 3`:

```text
1 + 1 + 1
1 + 2
2 + 1
````

Therefore, there are **3 distinct ways** to climb the staircase.

### Recursive Relation

At every step, there are two choices:

```text
Climb 1 step → ClimbStrairs(n - 1)
Climb 2 steps → ClimbStrairs(n - 2)
```

Therefore:

```text
f(n) = f(n - 1) + f(n - 2)
```

### Base Cases

If `n < 0`, the number of ways is `0` because the number of remaining steps cannot be negative.

```cpp
if(n < 0)
{
    return 0;
}
```

If `n == 0`, we have successfully reached the top.

```cpp
if(n == 0)
{
    return 1;
}
```

### Code

```cpp
#include<iostream>
using namespace std;

int ClimbStrairs(int n)
{
    // Base Case
    if(n < 0)
    {
        return 0;
    }

    if(n == 0)
    {
        return 1;
    }

    // Recursive Relation
    int ans = ClimbStrairs(n - 1) + ClimbStrairs(n - 2);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    int ans = ClimbStrairs(n);

    cout << ans << endl;

    return 0;
}
```

### Recursive Flow for `ClimbStrairs(3)`

```text
ClimbStrairs(3)

= ClimbStrairs(2) + ClimbStrairs(1)

= [ClimbStrairs(1) + ClimbStrairs(0)]
  + ClimbStrairs(1)

= [1 + 1] + 1

= 3
```

### Key Idea

> At every step, there are two choices: climb `1` step or climb `2` steps.

> The total number of ways is the sum of the ways obtained from both choices.

---

# Example 4: Fibonacci Number

### Fibonacci Series

The Fibonacci series is:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21...
```

Each number in the Fibonacci series is obtained by adding the previous two numbers.

Therefore:

```text
f(n) = f(n - 1) + f(n - 2)
```

### Base Cases

The first Fibonacci number is:

```text
f(0) = 0
```

The second Fibonacci number is:

```text
f(1) = 1
```

Therefore:

```cpp
if(n == 0)
{
    return 0;
}

if(n == 1)
{
    return 1;
}
```

### Recursive Relation

The current Fibonacci number is calculated using the previous two Fibonacci numbers.

```text
fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)
```

### Code

```cpp
#include<iostream>
using namespace std;

int fibonacci(int n)
{
    // Base Case
    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        return 1;
    }

    // Recursive Relation
    int ans = fibonacci(n - 1) + fibonacci(n - 2);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n);

    return 0;
}
```

### Recursive Flow for `fibonacci(5)`

```text
fibonacci(5)

= fibonacci(4) + fibonacci(3)

= [fibonacci(3) + fibonacci(2)]
  + [fibonacci(2) + fibonacci(1)]

= [2 + 1] + [1 + 1]

= 3 + 2

= 5
```

### Key Idea

> Fibonacci recursion uses the previous two Fibonacci numbers to calculate the current Fibonacci number.

> The recursive relation is `f(n) = f(n - 1) + f(n - 2)`.

---

# Example 5: Say Digits

### Problem

Print the digits of a number in word form.

For example:

```text
Input:

412

Output:

four one two
```

### Array

We store the names of digits from `0` to `9` in an array.

```cpp
string arr[10] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine"
};
```

### Getting the Last Digit

The `%` operator is used to extract the last digit of a number.

```cpp
int digit = n % 10;
```

For example:

```text
412 % 10 = 2
```

Therefore:

```text
digit = 2

arr[2] = "two"
```

### Removing the Last Digit

The `/` operator is used to remove the last digit.

```cpp
n = n / 10;
```

For example:

```text
412 / 10 = 41
41 / 10  = 4
4 / 10   = 0
```

### Base Case

When `n` becomes `0`, there are no more digits to process.

```cpp
if(n == 0)
{
    return;
}
```

### Recursive Relation

The function calls itself with the number after removing its last digit.

```cpp
SayDigit(n, arr);
```

### Important Concept

The recursive call is made **before processing/printing**.

```cpp
SayDigit(n, arr);

cout << arr[digit] << " ";
```

Therefore, the digits are printed while the recursive calls are returning.

### Code

```cpp
#include<iostream>
using namespace std;

void SayDigit(int n, string arr[])
{
    // Base Case
    if(n == 0)
    {
        return;
    }

    // Processing
    int digit = n % 10;
    n = n / 10;

    // Recursive Call
    SayDigit(n, arr);

    // Processing while returning
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    int n;
    cin >> n;

    SayDigit(n, arr);

    return 0;
}
```

### Recursive Flow for `SayDigit(412)`

```text
SayDigit(412)

digit = 2
n = 41
↓
SayDigit(41)

digit = 1
n = 4
↓
SayDigit(4)

digit = 4
n = 0
↓
SayDigit(0)

Base Case → return
```

Now the recursive calls start returning:

```text
SayDigit(4)   → print "four"
SayDigit(41)  → print "one"
SayDigit(412) → print "two"
```

Therefore:

```text
four one two
```

### Key Idea

> `% 10` extracts the last digit.

> `/ 10` removes the last digit.

> Since processing happens after the recursive call, the digits are printed in the correct order while recursion is unwinding.

---

# Example 6: Reach Home

### Problem

Move from a source position to a destination one step at a time.

For example:

```text
Source = 1
Destination = 10
```

The function keeps moving the source forward until it reaches the destination.

### Base Case

When the source reaches the destination, the recursion stops.

```cpp
if(src == dest)
{
    cout << "Reached Home" << endl;
    return;
}
```

### Processing

Move the source one step forward.

```cpp
src++;
```

### Recursive Relation

Call the function again with the updated source.

```cpp
reachHome(src, dest);
```

### Code

```cpp
#include<iostream>
using namespace std;

void reachHome(int src, int dest)
{
    cout << "Source: " << src << " Destination: " << dest << endl;

    // Base Case
    if(src == dest)
    {
        cout << "Reached Home" << endl;
        return;
    }

    // Processing
    src++;

    // Recursive Call
    reachHome(src, dest);
}

int main()
{
    int dest = 10;
    int src = 1;

    reachHome(src, dest);

    return 0;
}
```

### Recursive Flow

```text
reachHome(1, 10)
        ↓
reachHome(2, 10)
        ↓
reachHome(3, 10)
        ↓
       ...
        ↓
reachHome(10, 10)
        ↓
Reached Home
```

### Key Idea

> Each recursive call moves the source one step closer to the destination.

> The recursion stops when `src == dest`.

---

# Important Concepts Practiced

## 1. Base Case

The **Base Case** defines the condition where the recursive function stops calling itself.

Examples:

```cpp
if(n == 0)
{
    return;
}
```

```cpp
if(src == dest)
{
    return;
}
```

A proper base case is necessary to prevent infinite recursion.

---

## 2. Recursive Relation

The **Recursive Relation** defines how the current problem is reduced into a smaller similar problem.

Examples:

```text
ClimbStrairs(n - 1)
ClimbStrairs(n - 2)
```

```text
fibonacci(n - 1)
fibonacci(n - 2)
```

```text
SayDigit(n / 10)
```

```text
reachHome(src + 1, dest)
```

---

## 3. Processing Before Recursive Call

Example:

```cpp
cout << n << endl;

print(n - 1);
```

Here, processing happens **before** the recursive call.

The processing happens while the recursion is going down.

Example:

```text
5
4
3
2
1
```

This is commonly called **Tail Recursion** when the recursive call is the last operation.

---

## 4. Processing After Recursive Call

Example:

```cpp
print(n - 1);

cout << n << endl;
```

Here, processing happens **after** the recursive call.

The processing happens while the recursion is returning/unwinding.

Example:

```text
1
2
3
4
5
```

This is commonly called **Head Recursion**.

---

# Recursion Call Stack

Every recursive function call is stored in the **Call Stack**.

For example:

```text
SayDigit(412)
      ↓
SayDigit(41)
      ↓
SayDigit(4)
      ↓
SayDigit(0)
```

When the base case is reached, the functions start returning.

```text
SayDigit(4)
      ↓
SayDigit(41)
      ↓
SayDigit(412)
```

This process is called **unwinding of recursion**.

---

# Key Points

* **Recursion** is a programming technique in which a function calls itself.

* A large problem is solved by breaking it into smaller problems of the same type.

* Every recursive function should have a **Base Case**.

* The **Base Case** prevents infinite recursive calls.

* The **Recursive Relation** defines how the problem becomes smaller.

* Every recursive call should move closer to the **Base Case**.

* In **Climbing Stairs**, each call has two choices: climb `1` step or `2` steps.

* In **Fibonacci**, the current value is calculated using the previous two values.

* In **Say Digits**, `% 10` extracts the last digit and `/ 10` removes the last digit.

* In **Say Digits**, processing after the recursive call allows the digits to be printed in the correct order.

* In **Reach Home**, `src++` moves the source one step closer to the destination.

* **Processing before the recursive call** happens while going down.

* **Processing after the recursive call** happens while coming back up.

* If recursion never reaches its base case, the **Call Stack** can become full, causing a **Stack Overflow**.

```
```
