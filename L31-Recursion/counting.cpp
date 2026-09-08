#include <iostream>
using namespace std;

// Head Version
int print(int n)
{

    // Base Case
    if (n == 0)
    {
        return 1;
    }

   

    // Recursive Relation
    print(n - 1);

    cout << n << endl;
}
int main()
{

    int n;
    cin >> n;

    print(n);
    return 0;
}