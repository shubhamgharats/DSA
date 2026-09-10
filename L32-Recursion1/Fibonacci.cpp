// Fibonacci Series: 0,1,1,2,3,5,8,13,21.......

#include <iostream>
using namespace std;

int fibonacci(int n)
{

    // Base Case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

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