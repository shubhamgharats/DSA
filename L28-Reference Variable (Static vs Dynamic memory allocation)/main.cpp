#include<iostream>
using namespace std;

void update1(int n){
    n++;
}

void update2(int &n){//Reference variable
    n++;
}

int main(){

int n=5;

cout<<"Before: "<<n<<endl;
update1(n);
cout<<"After(Not using reference variable): "<<n<<endl;

update2(n);
cout<<"After(Using reference variable): "<<n<<endl;

return 0;
}