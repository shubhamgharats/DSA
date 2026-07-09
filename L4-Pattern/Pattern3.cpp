#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int i =1;

while(i<=n){
    int j=1;
                                        //i is row
    while(j<=i){                        //j is col
      cout<<"* ";
        j++;
     
        }
    cout<<endl;
    
    i++;
}
return 0;
}