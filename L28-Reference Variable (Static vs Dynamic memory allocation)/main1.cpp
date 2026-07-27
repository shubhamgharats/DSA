// BAD Practices and errors
#include<iostream>
using namespace std;

int& func1(int a){
    int num = a;
    int& ans = num;
    return ans;
}

int* func2(int a){
    int* ptr = &a;
    return ptr;
}

int main(){
 func1(5);
 func2(6);
return 0;
}