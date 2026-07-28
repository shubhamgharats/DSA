//  How to create a 2D dynamic arrray
//  how give and take input/output
//  how to free the dynamic heap memory
 #include<iostream>
 using namespace std;
 int main(){
 
    int row;
    int col;

    cout<<"Enter no. of rows: "<<endl;
    cin>>row;
    cout<<"Enter no. of cols: "<<endl;
    cin>>col;

    int** arr = new int*[row];
    // Creation od 2D array in dynamic memory
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    // Input
    cout<<"Enter "<<row*col<<" no. of elements: "<<endl;
    for(int i=0; i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

        // output
        cout<<"Following is your 2D array: "<<endl;
    for(int i=0; i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    //releasing memory od sub-arrays
    for(int i=0; i<row;i++){
        delete [] arr[i];
    }

    //releasing memory of main arrray where pointers to sub-array are stored
    delete []arr;

 return 0;
 }