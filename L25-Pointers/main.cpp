#include<iostream>
using namespace std;
int main(){
int i =5;
int *ptr = &i;

cout<< i<< endl;
cout<< *ptr<< endl;
cout<< &i<< endl;
cout<< ptr<< endl;

double d= 4.3;
double *p2 = &d;

cout<<d<< endl;
cout<< *p2<< endl;
cout<< &d<< endl;
cout<< p2<< endl;

return 0;
}