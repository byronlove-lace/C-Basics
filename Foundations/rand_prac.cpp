#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
        cout << "rand() is not a good way to get random numbers\n"
                "It gives your the same random numbers every time: " << rand() << endl;

        srand(99);
        cout << "\nusing srand() first is better because you can change the seed vale\n"
                "srand(99) will seed rand() with 99)\n" 
                "Doing this means rand() will give you this: " << rand()  // need << on next line if line ends with var
                << "\n But it will be the same every time too!" << endl;

        unsigned int x = time(NULL);
        srand(x);
        cout << "for a more appropriately random value, pass time(NULL) to srand(x)\n"
                "this will change the value every time: " << rand()
                << "\nand it can be used with modulus to generate nums in a specific range: " << 1 + rand() % 6 << endl;
                         
}

