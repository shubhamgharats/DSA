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