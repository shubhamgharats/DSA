#include<iostream> //Solved using XOR.....
using namespace std;
int main(){
 int ans=0;
int size=5;
int arr[5]={1,3,1,2,3};
 for(int i=0;i<size;i++){
 ans= ans^arr[i];

 }
return ans;
cout<<ans;

}