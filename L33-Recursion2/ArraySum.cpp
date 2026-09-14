// Find sum of Array using Recursion

#include <iostream>
using namespace std;

int arraySum(int arr[], int size)
{
    // Base Case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    // Recursive Call
    int smallProblem = arraySum(arr + 1, size - 1);

    // Processing
    int sum = arr[0] + smallProblem;

    return sum;
}
int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    int ans = arraySum(arr, size);
    cout << ans << endl;
    return 0;
}