#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;

int row=1;
    int count=1;

while(row<=n){
    count=row;
    int space=row-1;
    //Print Space
    while(space){
        cout<<"  ";
        space--;
    }
    int col=1;
    while(col<=n-row+1){
        cout<<count<<" ";
        col++;
          count++;

    }
    
    //count=row+1;
    cout<<endl;
    row++;
}
return 0;
}