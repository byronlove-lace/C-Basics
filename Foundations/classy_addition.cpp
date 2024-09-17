
#include<iostream>
using namespace std;

class ADD
{
        public:
                int Add(int Num1, int Num2)
                {
                        return Num1 + Num2;
                }

                double Add(double Num1, double Num2)
                {
                        return Num1 + Num2;
                }
};

int main()
{
        int X = 5;
        int Y = 10;

        double D_X = 5.3;
        double D_Y = 25.5;

        ADD AddObj;

        cout << "This is an int: " << AddObj.Add(X, Y) << endl;
        cout << "This is a double: " <<  AddObj.Add(D_X, D_Y) << endl;
}
