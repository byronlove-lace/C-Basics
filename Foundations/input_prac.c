#include<iostream>
#include<limits>

using namespace std;

const size_t NAME_LEN = 255;

int main() 
{
        int Age = 0;
        char Name[NAME_LEN];

        cout << "Please input your age: ";
                cin >> Age;
        cout << "Please input your name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // cin.ignore(up-to-num-of-chars, 'or-this-char')
        cin.getline(Name, NAME_LEN); // without cin.ignore, \n is still in the buffer

}
