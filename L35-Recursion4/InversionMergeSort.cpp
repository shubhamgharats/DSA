// Inversion Count using recursion + Merge Sort

#include <iostream>
using namespace std;

long long merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int k = start;

    for (int i = 0; i < len1; i++)
        first[i] = arr[k++];

    k = mid + 1;

    for (int i = 0; i < len2; i++)
        second[i] = arr[k++];

    int index1 = 0;
    int index2 = 0;
    int mainArrayIndex = start;

    long long count = 0;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];

            // All remaining elements in first are greater
            count += len1 - index1;
        }
    }

    while (index1 < len1)
        arr[mainArrayIndex++] = first[index1++];

    while (index2 < len2)
        arr[mainArrayIndex++] = second[index2++];

    delete[] first;
    delete[] second;

    return count;
}

long long mergeSort(int arr[], int start, int end)
{
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;

    long long count = 0;

    // Inversions in left half
    count += mergeSort(arr, start, mid);

    // Inversions in right half
    count += mergeSort(arr, mid + 1, end);

    // Inversions between left and right halves
    count += merge(arr, start, end);

    return count;
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    long long count = mergeSort(arr, 0, size - 1);

    cout << "Inversion Count: " << count << endl;

    return 0;
}