// Insertion Sort using Recursion

#include <iostream>
using namespace std;

void insertionSort(int arr[], int size, int i)
{

    // Base Case
    if (i >= size)
    {
        return;
    }

    // Processing
    int temp = arr[i];
    int j = i - 1; // j must be declared here
    while (j >= 0 && arr[j] > temp)
    {
        // Shift
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp; // Place temp in the correct position

    // Recursive Call
    insertionSort(arr, size, i + 1);
}

int main()
{

    int arr[5] = {76, 47, 28, 94, 3};

    int size = 5;

    insertionSort(arr, 5, 0);

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}