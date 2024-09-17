#include<iostream>
using namespace std;

int squareByValue(int);
void squareByReference(int&);

int main()
{
        // demonstrate squareByValue
        int x = 2;

        cout << "x = " << x << " before squareByValue\n";
        cout << "Value returned by squareByValue: " << squareByValue(x) << endl;
        cout << "x = " << x << " after squareByValue.\n" << endl;

        // demo squareByReference 
        int z = 5;

        cout << "z = " << z << " before squareByReference\n";
        squareByReference(z);
        cout << "z = " << z << " after squareByReference." << endl;
}

int squareByValue(int num)
{
        return num *= num;
}

void squareByReference(int &num_ref)
{
        num_ref *= num_ref;
}

