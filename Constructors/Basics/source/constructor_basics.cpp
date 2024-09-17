#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Entity
{
        public:
                float x, y;
i               
                // Constructor
                Entity()
                {
                        x = 0.00;
                        y = 0.00;
                }

                Entity(float newX, float newY)
                {
                        x = newX;
                        y = newY;
                }

                // Methods
                void print()
                {
                        cout << x << ", " << y << endl;

                }

                void init()
                {
                        x = 0.00;
                        y = 0.00;
                }
}

int main()
{
        Entity e;
        cin.get();
}
