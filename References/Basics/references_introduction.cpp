#include <iostream>

using std::cout;
using std::endl;

void add_to_int(int &r);

int main()
{
        int x = 0;
        int &refX = x; // alias to x, the reference

        ++refX;

        add_to_int(refX);
        add_to_int(x);

        cout << refX << endl;
        cout << x << endl;
}

void add_to_int(int &r)
{
        r += 5;
}
