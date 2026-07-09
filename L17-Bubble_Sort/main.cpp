#include<iostream>
using namespace std;
int main(){

    int arr[7]={4,3,76,43,24,52,41};
    int n=7;

    for(int i=0; i<n-1;i++){
        // For Round_1 to Round_(n-1)

        for(int j=0; j<n-1-i;j++){
          if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
          }
        }
    }

        // Print sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    
return 0;
}