// Bubble Sort using Recursion

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
    // Base Case
    if(size ==0 || size==1){
        return ;
    }

    //Processing
    // 1case solved - Lergest element will be moved to end
    for(int i =0; i<size;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }

    // Recurive Call
    bubbleSort(arr, size-1);
}
int main(){

    int arr[5] = {4,2,9,5,12};

    bubbleSort(arr, 5);


    for(int i=0;i<5; i++){
        cout<< arr[i]<<" ";
    }
return 0;
}