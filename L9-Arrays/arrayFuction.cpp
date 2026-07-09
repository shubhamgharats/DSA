#include<iostream>
using namespace std;

void printArray(int arr[],int size)
{
    cout<<"Printing the Array: "<<endl;
    //Print the array
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;

    cout<<"PRINTING OF ARRAY DONE"<<endl;
    
}
int main(){
    int third[15]={1,2,3};
printArray(third,15);

int thirdSize= sizeof(third)/sizeof(int);

cout<<" Size of Third is: ";
return 0;
}