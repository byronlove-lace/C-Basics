#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Entity
{
        public:
                string get_name()
                {
                        return "Entity";
                }
};

class Player : public Entity
{
        private:
                string mName;

        public:
                // Constructor
                Player(const string& name)
                        :mName(name) {}
        
                // Overloaded Methods
                string get_name() 
                {
                        return mName;
                }
};

int main()
{
        Entity* e = new Entity();
        cout << e->get_name() << endl;
        delete e;

        Player* p = new Player("JAH");
        cout << p->get_name() << endl;
        delete p;
}
