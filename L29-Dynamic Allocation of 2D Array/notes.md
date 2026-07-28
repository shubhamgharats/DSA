Allocating 2D array in static memory 
int arr[5][5];

Alocating array in Dynamic memory
1D array its collection of blocks of int
int* arr = new int[n];

Allocating 2D array in Dynamuc memory
2D array is collection of 1D arrays(rows), so:
int** arr = new int*[n]

here there is  array of n size with int* as element
eg: int n[rows] = {int*, int*, int*.....}

and each int* point to an 1D array
eg: int arr[cols] = {1,2,5,4.....}

Now as the 2D array dynamic memory is in heap, it needs to be freed manually

first sub arrays should be freed and then the main array where pointers to other sub arrays are stored using loops


