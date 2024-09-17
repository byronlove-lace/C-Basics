#include<iostream>
using namespace std;

// buffer test

int main()
{
        int x = 5;
        int y = 10;
        int z;

        cout << x << " plus " << y << " equals " << x + y << "\n"; // output stored in a buffer until it is flushed or a nl
        cout << "Please enter z: ";
        cin >> z; 

}
