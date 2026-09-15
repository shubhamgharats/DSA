// Merge Sort using Recursion

#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values into first array
    int k = start;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    // Copy values into second array
    k = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // Merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;

    int mainArrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // Copy remaining elements from first
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    // Copy remaining elements from second
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void MergeSort(int *arr, int start, int end)
{
    // Base Case
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // Left Part Sort
    MergeSort(arr, start, mid);

    // Right Part Sort
    MergeSort(arr, mid + 1, end);

    // Merge
    merge(arr, start, end);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    int size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, size - 1);

    cout << "Sorted Array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}