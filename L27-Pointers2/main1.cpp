#include<iostream>
using namespace std;

void update1(int **ptr){
    // No changes will be made
    ptr=ptr+1;
}

void update2(int **ptr){
    // Value inside block pointed by ptr will increment by 1(4bytes)
    *ptr=*ptr+1;
}


void update3(int **ptr){
    // Value inside block pointed by ptr will increment by 1(4bytes)
    **ptr=**ptr+1;
}


int main(){

    int i =5;
    int *p = &i;
    int **q = &p; // Double pointer
    int ***z = &q; // Triple pointer

    cout << endl << endl;
    cout <<"update1() reults: "<<endl;
    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << q << endl;
    update1(q);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << q << endl;

    cout << endl << endl;
    cout <<"update2() reults: "<<endl;
    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << q << endl;
    update2(q);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << q << endl;

    // Reset p because update2() changed it
    p = &i;


    cout << endl << endl;
    cout <<"update3() reults: "<<endl;
    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << q << endl;
    update3(q);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << q << endl;

    cout << endl << endl;
    

   

return 0;
}