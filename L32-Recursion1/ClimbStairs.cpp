// You are climbing a staircase. It 
// takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. 
// In how many distinct ways can you climb to the top?

#include<iostream>
using namespace std;

int ClimbStrairs(int n){
    //Base Case
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }

    // Recursive Call
    int ans = ClimbStrairs(n-1)+ ClimbStrairs(n-2);


    return ans;
}
int main(){

    


    return 0;
}