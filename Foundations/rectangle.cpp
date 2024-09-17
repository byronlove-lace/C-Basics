#include<iostream>
#include<limits>

using namespace std;

inline double DRectArea(double Len, double Width )
{
        return Len * Width;
}

double RectInputValidate();

int main()
{

        double DLen;
        double DWidth;

        cout << "This program calculates the area of a rectangle" << endl;
        cout << "Please enter the length of the rectangle: ";
        DLen = RectInputValidate();

        cout << "Please enter the width of the rectangle: ";
        DWidth = RectInputValidate();

        cout << "The area is " << DRectArea(DLen, DWidth) << endl;

}

double RectInputValidate()
{
        double Num;

        cin >> Num;

        while (true)
        {
                if (cin.fail())
                {
                        cin.clear(); // clears error state of the buffer
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        cout << "Please enter a number: ";
                        cin >> Num;
                }

                else
                {
                        break;
                }
        }

                return Num;
}
