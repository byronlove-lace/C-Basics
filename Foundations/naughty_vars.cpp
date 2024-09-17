#include<iostream>
using namespace std;

const int number = 7;

int main()
{
        double number = 10.5; 
        cout << "Local number: " << number << "\nGlobal number: " << ::number << endl;
}
