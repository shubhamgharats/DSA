#include<iostream>
using namespace std;

void reverseArray(int arr[],int size){
    int start=0, end= size-1;
   
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int main(){
int arr[5]={1,2,3,4,5};
int brr[4]={2,5,4,9};

reverseArray(arr,5);
reverseArray(brr,4);

printArray(arr,5);
printArray(brr,4);
return 0;
}