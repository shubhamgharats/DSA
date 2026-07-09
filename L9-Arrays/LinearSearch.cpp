#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
for(int i=0;i<size;i++){
 if(arr[i]==key){
    return 1;
 }

}
return 0;
}
int main(){

    int arr[10]={5,-2,4,6,11,5,6,-9,-4,1};

    // Wheather 1 is present or not

cout<<"Enter the key: ";
int key;
cin>>key;

bool found = search(arr,10,key);

if(found){
    cout<<"Key is present "<<endl;
}
else{
    cout<<"Key is not present "<<endl;

}

return 0;
}