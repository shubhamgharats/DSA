#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }cout<<endl;
}

void swapAlternate(int arr[], int size){
    for(int i=0;i<size;i+=2){
       if(i+1< size){
        swap(arr[i],arr[i+1]);
       }
    }

}
int main(){
// 1 2 3 4 5 6 ---> 2 1 4 3 6 5

int even[8]={5,2,4,2,6,2,9,6};
int odd[5]={7,0,4,3,1};

swapAlternate(even,8);
printArray(even,8);

swapAlternate(odd,5);
printArray(odd,5);

return 0;
}