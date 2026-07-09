#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int i=1;

while(i<=n){                
 int j = 1;
 while(j<=n){     // 111
    cout<<i;      // 222
    j++;          // 333
 }
 cout<<endl;
 i++;
}
return 0;
}