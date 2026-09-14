// Linear Search using Recursion

#include<iostream>
using namespace std;

bool linearSearch(int n, int arr[], int size){
    //Base Case
    if(size == 0){
        return false;
    }
        if(arr[0]== n){
        return true;
    }

    // Recursive Call
    int ans = linearSearch(n,arr+1,size-1);

    
    return ans;





}
int main(){
 
    int n = 10;

    int arr[5] ={1,7,5,3,2};

    int size = 5;

    int ans = linearSearch(n,arr, size);

    if(ans){
        cout<<n<<" is present in array!";
    }else{
        cout<<n<<" is NOT present in array!";
    }
return 0;
}