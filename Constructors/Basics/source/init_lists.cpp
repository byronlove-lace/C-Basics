#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Entity
{
        private:
                string mName;
        public:
                /*
                Entity()
                {
                       mName = "Unknown"; 
                }

                Entity(const string& newName)
                {
                       mName = newName; 
                }
                */

                Entity()
                        : mName("Unkown") {}
                
                Entity(const string& name)
                        : mName(name) {}
                        
                
                 
                const string& get_name() const { return mName; }
};

int main()
{
        Entity e1;
        cout << e1.get_name() << endl;

        Entity e2("JAH");
        cout << e2.get_name() << endl;

}
