#include <iostream>
using namespace std;

int power(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }

    // Recursive relation
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