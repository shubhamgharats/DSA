#include<iostream>
using namespace std;
int main(){

    int arr[7]= {10,1,7,4,8,2,11};
    int n= 7;
    for(int i=0; i<n; i++){
        int temp = arr[i];
        int j = i - 1;  // j must be declared here
        while(j >= 0 && arr[j] > temp){
            // Shift
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; // Place temp in the correct position
    }

    // Optional: Print the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
