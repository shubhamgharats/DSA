#include<iostream>
using namespace std;

int main(){
    int arr[10] = {2,4,6,8,10,12,14,16,18,20};
    
    // Default address of array is equal to address of oth index element
    cout<< "Address of 1st memory block of array is: "<< arr<< endl;
    cout<< "Address of 1st memory block of array is: "<< &arr<< endl;
    cout<< "Address of 1st memory block of array is: "<< &arr[0]<< endl;

    // Address of 1th index and hence forth are different
    cout<< "Address of 2nd memory block of array is: "<< &arr[1]<< endl;
    cout<< "Address of 3rd memory block of array is: "<< &arr[2]<< endl;
    
    // Prints first value inside array
    cout<<"Answer of *arr: "<< *arr << endl;
    cout<<"Answer of *arr+1: "<< *arr+1 << endl;

    cout<<"Answer of *(arr+1): "<< *(arr+1) << endl;
    cout<<"Answer of *(arr+2): "<< *(arr+2) << endl;
    // From above two lines we obtain a formula: arr[i] = *(arr+i)
    // "arr[i] = *(arr+i)" can also be written as "i[arr] = *(i+arr)"

    
    // Size of a variable is 4 bytes
    // Size of a address is 8 bytes
    // Size of a array is (4 * no. of element) bytes
    int temp[10] = {1,3,5,7,9,11,13,15,17,19};
    cout<<"Size of array temp: "<<sizeof(temp)<<endl;
    cout<<"Size of varible or value in 1st block: "<<sizeof(*temp)<<endl;
    cout<<"Size of address of 1st block of array temp: "<<sizeof(&temp)<<endl;

    int *ptr = &temp[0];
    cout<<"Size of ptr: "<<sizeof(ptr)<<endl;
    cout<<"Size of *ptr: "<<sizeof(*ptr)<<endl;
    cout<<"Size of &ptr: "<<sizeof(&ptr)<<endl;
    
    // Int Array and Char Array work differently

    // cout<< Intarr<< endl -> Prints Address
    // cout<< CharArr<< endl -> Prints arrray content
    
    // Value of pointer printed for Int array is address
    // Value of pointer printed for Car array is array value
    int arr3[5] = {1,2,3,4,5};
    int *p = &arr3[0];
    char ch[5] = "abcd";
    char *c = &ch[0];
    cout<<"Value of char pointer c: "<<c<<" (Value)"<<endl;
    cout<<"Value of Int pointer p: "<<p<<" (Address)"<<endl;

    // In char while printing address, it keeps printing address 
    // of each character until it reaches null
    // So we recieve weird adddress for char array
    
    




return 0;
}