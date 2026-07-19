#include<iostream>
using namespace std;
int main(){

    int i =5;
    int *p = &i;
    int **q = &p; // Double pointer
    int ***z = &q; // Triple pointer
    
    // practice
    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;
    cout<<q<<endl;
    cout<<*z<<endl;
    cout<<**z<<endl;
    cout<<***z<<endl;
    cout<<z<<endl;

    // understand logic
    cout<<"Print 5: "<<endl;
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**q<<endl;
    
    cout<<"Print i's address: "<<endl;
    cout<<&i<<endl;
    cout<<*q<<endl;
    cout<<p<<endl;
    cout<<**z<<endl;

    cout<<"Print pointer P's address: "<<endl;
    cout<<&p<<endl;
    cout<<*z<<endl;
    cout<<q<<endl;
    
    cout<<"Print pointer Q's address: "<<endl;
    cout<<&q<<endl;
    cout<<z<<endl;


return 0;
}