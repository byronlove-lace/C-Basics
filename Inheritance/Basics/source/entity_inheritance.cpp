#include <iostream>

using std::cout;
using std::endl;

class Entity
{
        public:
                float x, y;

                void move(float moveX, float newY)
                {
                        x += moveX;
                        y += moveY;
                }

};

// Player is both of Player and Entity type
class Player : public Entity
{
        public:
                const char* name;

                void print_name()
                {
                        cout << name << endl;                                       
                }
};

int main()
{
        // Player is a superset of Entity
        Player player;
}
