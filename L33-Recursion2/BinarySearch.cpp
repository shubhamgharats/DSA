// Binary Search using Recursion

#include <iostream>
using namespace std;

bool binarySearch(int n, int arr[], int start, int end)
{
    // Base Case
    if (start > end)
    {
        return false;
    }

    // Processing
    int mid = start + (end - start) / 2;

    if (arr[mid] == n)
    {
        return true;
    }

    // Recursive Call
    if (arr[mid] < n)
    {
        return binarySearch(n, arr, start = mid + 1, end);
    }
    else
    {
        return binarySearch(n, arr, start, end = mid - 1);
    }
}
int main()
{

    int arr[] = {10, 20, 30, 40, 50};

    int n = 40;

    int ans = binarySearch(n, arr, 0, 4);

    if (ans)
    {
        cout << n << " is present in array!";
    }
    else
    {
        cout << n << " is NOT present in array!";
    }

    return 0;
}