//       1
//     1 2 1
//   1 2 3 2 1 
// 1 2 3 4 3 2 1

#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;

int row=1;
while(row<=n){
// Spaces(1st Triangle)
int space=n-row;
while(space){
cout<<"  ";
space--;
}

// 2nd Triangular part
int col=1;
while(col<=row){
cout<<col<<" ";
col++;
}


// 3rd Triangular part
int start=row-1;
while(start){
    
    cout<<start<<" ";
    start--;
    
}
cout<<endl;
row++;
}
return 0;
}