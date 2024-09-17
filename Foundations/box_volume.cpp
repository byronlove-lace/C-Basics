#include<iostream>
using namespace std;

int BoxVol(int Len = 1, int Width = 1, int Height = 1);

int main()
{
        cout << "The default box volume is : " << BoxVol() << endl;

        cout << "The box volume with length 10 is : " << BoxVol(10) << endl;

        cout << "The box volume with length 10 is : " << BoxVol(10, 5) << endl;

        cout << "The box volume with length 10 and width 5 is : " << BoxVol(10, 5) << endl;

        cout << "The box volume with length 10, width 5 and height 2 is : " << BoxVol(10, 5, 2) << endl;
}

int BoxVol(int Len, int Width, int Height) // Note: don't include defaults in def unless prototype is omitted
{
        return Len * Width * Height;
}
