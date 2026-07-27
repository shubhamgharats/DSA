// Declaring array size after compilation 
//using Dynamic memory allocation in heap

#include<iostream>
using namespace std;


int getSum(int *arr, int n){
    int sum =0;
    for(int i=0;i<n;i++){
        sum +=arr[i];
    }
    return sum;
}

int main(){
 int n;
 cout<<"Enter size of array: ";
 cin>>n;
 
 //variable size array
 int* arr = new int[n];

 // Input array elements
 for(int i=0; i<n;i++){
    cout<<"Enter " <<i<<"th Element: ";
    cin>> arr[i];
 }
int total = getSum(arr,n);
cout<<"Sum of array elements is: "<<total<<endl;
 
return 0;
}