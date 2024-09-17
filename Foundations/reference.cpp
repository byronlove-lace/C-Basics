#include<iostream>
using namespace std;

int main()
{
        int x = 3;
        int &y = x; // y refers to (is an alias for) x
                    // y must be initialized 
        
        cout << "x = " << x << endl << "y = " << y << endl;
        y = 7;
        cout << "x = " << x << endl << "y = " << y << endl;
}
