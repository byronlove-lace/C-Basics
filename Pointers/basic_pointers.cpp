#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
        int *n = new int; // mem address for int is returned by new operator 
                          // assign to int pointer
                          // n was statically allocated (at compile time)
                          // unnamed var (new int) -- dynamically allocated at run time
                          // result is two vars 
        *n = 8; // dereference 

        int *o;
        o = new int;
        *o = 2;

        int sum = *n + *o;

        cout << "The sum of " << *n << " and " << *o << " is " << sum << endl;

        delete n;
        delete o;
        
        // dynamically allocate an array

        int SIZE; // statically allocated
        int *aPtr; // statically allocated
        int aSum;

        cout << "Enter the size of the array: ";
        cin >> SIZE;

        aPtr = new int[SIZE];

        for (size_t i = 0; i < (size_t) SIZE; ++i)
        {
                aPtr[i] = i * (2 * 2);
        }

        for (size_t i = 0; i < (size_t) SIZE; ++i)
        {
                aSum += aPtr[i];
        }

        delete []aPtr; // syntax for deallocating arrays delete []arrName;

        // 2D arrays

        int rows, cols;
        cout << "rows, cols:";
        cin >> rows;
        cols = rows;

        int **table = new int*[rows];

        for (int i = 0; i < rows; ++i)
        {
                table[i] = new int[cols];
        }

        table[1][2] = 88;

        for (int i = 0; i < rows; ++i)
        {
                delete[] table[i];
        }

        delete[] table;
        table = NULL; // returns pointer to NULL state 
}

