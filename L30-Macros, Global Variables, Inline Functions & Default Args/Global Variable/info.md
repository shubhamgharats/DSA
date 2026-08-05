# Global Variables and Reference Variables in C++

## Variable Scope

The **scope** of a variable determines where it can be accessed in a program.

There are two common types of variables:

- **Local Variables**
- **Global Variables**

---

# Local Variables

A local variable is declared **inside a function or block**.

- It can only be accessed within that function or block.
- Different functions can have local variables with the same name because each has its own scope.

### Example

```cpp
#include <iostream>
using namespace std;

void a() {
    int A = 5;
    cout << "Value of A inside function: " << A << endl;
}

int main() {
    a();

    int A = 50;
    cout << "Value of A inside main: " << A << endl;

    return 0;
}
```

### Output

```
Value of A inside function: 5
Value of A inside main: 50
```

Although both variables are named `A`, they are **different variables** because they belong to different scopes.

---

# Global Variables

A global variable is declared **outside all functions**.

It can be accessed by every function in the same source file.

### Example

```cpp
#include <iostream>
using namespace std;

int score = 15;   // Global variable

void a() {
    int A = 5;

    cout << "Value of A inside function: " << A << endl;
    cout << "Value of score inside function: " << score << endl;
}

int main() {

    a();

    int A = 50;

    cout << "Value of A inside main: " << A << endl;
    cout << "Value of score inside main: " << score << endl;

    return 0;
}
```

### Output

```
Value of A inside function: 5
Value of score inside function: 15
Value of A inside main: 50
Value of score inside main: 15
```

Since `score` is a global variable, both `main()` and `a()` can access it.

---

# Problems with Global Variables

Although global variables make data accessible throughout the program, they are generally **considered bad practice**.

### Reasons

- Any function can modify the variable.
- It becomes difficult to track where the value changes.
- Makes debugging harder.
- Reduces code readability and maintainability.
- Creates unwanted dependencies between functions.

For these reasons, global variables should be used only when truly necessary.

---

# Reference Variables

A **reference variable** is another name (alias) for an existing variable.

It does **not** create a new variable or allocate new memory.

### Syntax

```cpp
datatype &referenceName = existingVariable;
```

### Example

```cpp
#include <iostream>
using namespace std;

int main() {

    int score = 15;

    int &marks = score;

    cout << score << endl;
    cout << marks << endl;

    marks = 25;

    cout << score << endl;
    cout << marks << endl;

    return 0;
}
```

### Output

```
15
15
25
25
```

Both `score` and `marks` refer to the **same memory location**.

---

# Sharing Variables Using References

Instead of using a global variable, it is often better to **pass a variable by reference** when multiple functions need to modify it.

### Example

```cpp
#include <iostream>
using namespace std;

void increaseScore(int &score) {
    score += 10;
}

int main() {

    int score = 15;

    increaseScore(score);

    cout << "Score = " << score << endl;

    return 0;
}
```

### Output

```
Score = 25
```

Here, the function modifies the original variable without using a global variable.

---

# Global Variable vs Reference Variable

| Global Variable | Reference Variable |
|-----------------|-------------------|
| Accessible from any function | Refers to an existing variable |
| Can be modified by any function | Only accessible where the reference exists |
| Makes code harder to maintain | Makes code safer and easier to understand |
| Generally discouraged | Commonly used when passing arguments to functions |

---

# Key Points

- Local variables exist only within their scope.
- Global variables can be accessed by all functions.
- Avoid global variables whenever possible because they make programs harder to maintain.
- A reference variable is an alias for another variable.
- To share or modify a variable across functions, prefer **passing it by reference** instead of using global variables.