#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;

int row=1;
int count=1;
while(row<=n){
    int space=n-row;
    //Print Space
    while(space){
        cout<<"  ";
        space--;
    }
    
    int col=1;
    while(col<=row){
        cout<<count<<" ";
        col++;
      
    }
    count++;
    cout<<endl;
    row++;
}
return 0;
}