#include<iostream>
using namespace std;

int score = 15;// Global variable

void a(){
    int A= 5;
    cout<<"Value of A inside function: "<<A<<endl;
    cout<<"Value of score inside function: "<<score<<endl;

}

int main(){
    a();
    int A= 50;
    cout<<"Value of A inside Main: "<<A<<endl;
    cout<<"Value of score inside Main: "<<score<<endl;
    cout<<"Value of score remains same as it is GLOBAL VARIABLE"<<endl;

return 0;
}