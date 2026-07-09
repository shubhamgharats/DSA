#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    vector<int> arr = {1, 4, 3, 9, 7, 5, 18, 90};

    selectionSort(arr, arr.size());

    // optional: print sorted array
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
