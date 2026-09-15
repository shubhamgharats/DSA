// Selction Sort using Recursion

#include <iostream>
using namespace std;

void selctionSort(int arr[], int i, int size)
{

    // Base Case
    if (i >= size - 1)
    {
        return;
    }

    // Processing
    int minIndex = i;

    for (int j = i + 1; j < size; j++)
    {
        if (arr[minIndex] > arr[j])
        {
            minIndex = j;
        }
    }

    swap(arr[minIndex], arr[i]);

    // Recursive Call
    selctionSort(arr, i + 1, size);
}
int main()
{

    int arr[5] = {76, 47, 28, 94, 3};

    int size = 5;

    selctionSort(arr, 0, 5);

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}