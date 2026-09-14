// Check if Palindrome using Recursion

#include <iostream>
using namespace std;

bool ifPalindrome(string &str, int i)
{
    // Base Case
    if (i >= str.length() / 2)
    {
        return true;
    }

    // If characters don't match
    if (str[i] != str[str.length() - i - 1])
    {
        return false;
    }
    else
    {

        // Recursive Call
        return ifPalindrome(str, i + 1);
    }
}

int main()
{
    string str = "madam";

    int ans = ifPalindrome(str, 0);

    if (ans)
    {
        cout << "Yes its a Palindrome" << endl;
    }
    else
    {
        cout << "No, its not a Palindrome" << endl;
    }

    return 0;
}