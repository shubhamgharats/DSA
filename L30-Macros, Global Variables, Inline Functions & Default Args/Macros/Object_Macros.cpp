#include<iostream>
using namespace std;

#define PI 3.14 //Defining PI Macro

// Define a macro to calculate the square of a number
#define SQUARE(x) (x * x)

int main(){
    int r =5;
    double area = PI * r * r;
    cout<<"Area is: "<<area<<endl;

    int result = SQUARE(r); // Expands to: (n * n)
    cout << "Square of " << r << " is " << result;
return 0;
}