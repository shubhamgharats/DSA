#include<iostream>
using namespace std;
int main(){
int number[15]; //Declare

//accessing an array

cout<<"Value at 15th Index: "<< number[14]<<endl;

cout<<"Value at 20th index: "<< number[20]<<endl;


//cout<<endl<<"Everything is Fine"<< endl<<endl;

//Initialising an array
int second[3]={1,2,3};

//Accessing an element
cout<<"Value at 2nd Index "<<second[3]<<endl;

int third[15]={2,7};

//Print the array:
int n=15;
for(int i=0;i<n;i++){
    cout<< third[i]<<" ";
}


return 0;
}