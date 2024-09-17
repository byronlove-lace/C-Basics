#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

void OutputVector(const vector<int> &);
void InputVector(vector<int> &);

int main()
{
        vector<int> Integers1(7);
        vector<int> Integers2(10);

        // print Integers1 size and contents 
        cout <<"Size of vector integers1 is " << Integers1.size() 
                << "\nvector after initialization:" << endl;  
        OutputVector(Integers1); 

        // print Integers2 size and contents 
        cout <<"Size of vector integers2 is " << Integers2.size() 
                << "\nvector after initialization:" << endl;  
        OutputVector(Integers2); 
        
        cout << "\nEnter 17 integers:" << endl;
        InputVector(Integers1);
        InputVector(Integers2);

        cout << "\nEvaluating: Integers1 != Integers2" << endl;

        if (Integers1 != Integers2)
        {
                cout << "\nIntegers1 and Integers2 are not equal" << endl;
        }

        //create vector Integers3 using Integers1 as an initializer
        vector<int> Integers3(Integers1); // copy constructor


        cout << "\nSize of vector Integers3 is " << Integers3.size()
                << "\n vector after initialization is:" << endl;
        OutputVector(Integers3);

        // use overloaded assignment operator
        cout << "\n Assigning Integers2 to Integers1:" << endl;
        Integers1 = Integers2; // assign Integers2 to Integers1

        cout << "Integers1:" << endl;
        OutputVector(Integers1);
        cout << "Integers2:" << endl;
        OutputVector(Integers2);

        if (Integers1 == Integers2)
        {
                cout << "Integers1 and Integers2 are equal!" << endl;
        }

        // use square brackets to create rvalue
        cout << "\nIntegers1[5] is " << Integers1[5];
        Integers1[5] = 1000;
        // use square brackets to create lvalue 
        cout << "Itegers1:" << endl;
        OutputVector(Integers1);

        // attempt to use out-of-range index
        try
        {
                cout << "\nAttempt to display Integers1.at(15)" << endl;
                cout << Integers1.at(15) << endl; // Error: out of range
        }
        catch (out_of_range &ex)
        {
                cout << "An exception occured: " << ex.what() << endl;
        }
}

void OutputVector(const vector<int> &array)
{
        size_t i;

        for (i = 0; i < array.size(); ++i)
        {
                cout << setw(12) << array[i];

                if ((i + 1) % 4 == 0) // 4 numbers per row of output
                {
                        cout << endl;
                }
        }

        if (i % 4 != 0)
        {
                cout << endl;
        }
}

void InputVector(vector<int> &array)
{
        for (size_t i = 0; i < array.size(); ++i)
        {
                cin >> array[i];
        }
}

