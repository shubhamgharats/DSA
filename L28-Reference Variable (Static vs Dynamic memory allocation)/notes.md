// Static and Dynamic  Memory allocation


reference variable: same memory , different variable

int i=5;
int &j = i; //Reference variable

why? - In pass by value, we declare int i =5 in main() which we pass to update(){i++;} function where copy of i is created and incremented by one, but in main() function main 5 only

but using reference variable, both variable point to same memory location


int& func(int a){
    int num = a;
    int& ans = num;
    return ans;
}

return of reference: is a bad practice , because ans here is a local variable and will die out of the function

int n ;
cin>>n;
int arr[n] 
//Giving size of arr after compiling program is bad practice because program starts withh assigned memory(Stack and Heap), where stack memory is smaller and Heap memory is bigger, but if before copilation only you mention amount of memory needed, then program bring greater stack memory than usual or else Program will crash.
// Give bigger size , but dont pass size after compilation
// like int arr[1000]
// So stack is static memory allocation

// But still you want to give input after compilation, it can be done by accessing the Heap memory which is empty
//Heap memory can be accessed using new keyword and return its address from heap
// new int

// But in Heap you cant name a variable, so here's were we use pointer
int* i = new int
char* i = new char
//So, Heap memory becomes dynamic memory allocation
//Total 8(pointer)+1(var)= 9bytes


// so , array in heap memory
int* arr = new int[5];

diffrence between Static and dynamic memory location
for int ar[50] --> memory 200(50 x4) , memory 208(50 x4 +8)


int* p = new int; is very dangerous

becaue imagine a while loop
while(true){
    int i =5;
}
allocated i stack free's atomatically after exiting loop

while(true){
    int* p = new int;
}
in this after exiting the stack memory gets free but , heap memory dosent free automatically, and keeps on adding memory blocks untill its full and crashes

so in c++ heap memory needs to be freed manually

therefore static memory gets rleased automatically, while dynmaic needs to be done manually

it can be done by delete keyword:

int* i = new int;
delete i

//array deletion
int* arr = new int[n]
delete []arr;


