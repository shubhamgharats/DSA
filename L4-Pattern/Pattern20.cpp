#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int count=1;

 int row=1;
 while(row<=n){
    //Print Spaces
    int space=n-row;
    while(space){
        cout<<"  ";
        space--;
    }
// Print numbers
    int col=1;
    while(col<=row){
        cout<<count<<" ";
        col++;
        count++;
    }
    cout<<endl;
    row++;
 }
return 0;
}