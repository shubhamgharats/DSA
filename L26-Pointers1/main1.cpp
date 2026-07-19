#include<iostream>
using namespace std;

void print1(int *p){
    cout<<p<<endl;
}

void print2(int *p){
    cout<<*p<<endl;
}

void update1(int *p){
   p=p+1; 
}

void update2(int *p){
   *p=*p+1; 
}

int getSum(int arr[], int n){
    
    cout <<endl <<"Size: "<< sizeof(arr)<< endl;
    // Prints 8, means the argument "int arr[]" is not a complete array, 
    // but is a pointer which is passed
    // Benefits: U can pass only a part of array instead of complete array
    // eg: getSum(arr+3,size) ---> it points ptr to block of index 0+3

    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;

        
}


int main(){
    int value = 5;
    int *p = &value;

    print1(p);
    print2(p);

    update1(p);
    print1(p);
    print2(p);

    // Even calling update() and passing p+1 the value dosen't change
    // It only changes inside update() function
    // But if you pass *p=*p+1 the value changes

    update2(p);
    print1(p);
    print2(p);

    int arr[5]={1,2,3,4,5};


    cout<<"Sum is "<<getSum(arr,5)<<endl;
    cout<<"Sum of arr except first 3 elements"<<getSum(arr+3,2);



    return 0;
}