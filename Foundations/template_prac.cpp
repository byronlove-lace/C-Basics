#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define LEN 3

template <typename T> 
T (T Val1, T Val2, T Val3)
{
        T MaxVal = Val1;

        if (Val2 > MaxVal)
                MaxVal = Val2;

        if (Val3 > MaxVal)
                MaxVal = Val3;

        return MaxVal;
}

int main()
{
        srand((unsigned) time(NULL));

        double Darr[LEN] = {0};
        unsigned int UIarr[LEN] = {0};
        for (size_t i = 0; i < LEN; ++i)
        {
                UIarr[i] = rand() % 100;
                Darr[i] = (rand() % 100) * (0.53);
                // how to get random decimals
        }

        size_t count = 0;

        cout << "UIarr vals: \n";
        while (count < LEN)
        {
                cout << UIarr[count] << endl;
                ++count;
        }

        cout << "Max Val: " << GetMax(UIarr[0], UIarr[1], UIarr[2]) << endl;
        count = 0;

        cout << "\nDarr vals: \n";
        while (count < LEN)
        {
                cout << Darr[count] << endl;
                ++count;
        }
        cout << "Max Val: " << GetMax(Darr[0], Darr[1], Darr[2]) << endl;
}
