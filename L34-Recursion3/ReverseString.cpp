// Reverse a string using Recursion

#include <iostream>
using namespace std;

// Using only one pointer
void reverseString1(string &str, int i)
{

    // Base Case
    if (i >= str.length() / 2)
    {
        return;
    }

    // Processing
    swap(str[i], str[str.length() - i - 1]);

    // Recursive Call
    reverseString1(str, i + 1);
}

// Using 2 pointers
void reverseString2(string &str, int i, int j)
{

    cout << "Call recieved for " << str << endl;

    // Base Case
    if (i > j)
    {
        return;
    }

    // Processing
    swap(str[i], str[j]);
    i++;
    j--;

    // Recursive Call
    reverseString2(str, i, j);
}

int main()
{

    string name = "Rohan";

    reverseString2(name, 0, name.length() - 1);
    cout << endl;
    cout << name << endl;

    return 0;
}