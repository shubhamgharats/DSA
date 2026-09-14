// Calculate Power a^b using Recursion

#include<iostream>
using namespace std;

int isPower( int a, int b){

    // Base Case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }

    // Recursive Call
    int ans = isPower(a,b/2);

    //If b is even
    if(b%2==0){
        return ans * ans;
    }else{
    // If b is odd
        return a * ans *ans;
    }
}
int main(){

    int a,b;
    cin >>a>>b;

    cout<<endl;

    cout<<"Answer is "<<isPower(a,b);

return 0;
}





