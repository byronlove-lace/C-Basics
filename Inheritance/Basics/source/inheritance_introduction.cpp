#include <iostream>

using std::cout;
using std::endl;
using std::string;

class MenuItem
{
        public: 
                string name;
                double calories;

                void print()
                {
                        cout << name << " (" << calories << " cal)" << endl;                        
                }
};

// inherits public atts/methods from MenuItem
class Drink : public MenuItem
{
        public:
                double litres;
                
                double cal_per_litre()
                {
                        return calories / litres;
                }
};

int main()
{
        MenuItem frenchFries;

        frenchFries.name = "French Fries";
        frenchFries.calories = 400;

        frenchFries.print();

        Drink hotChocolate;
        hotChocolate.name = "Hot Chocolate";
        hotChocolate.calories = 300;
        hotChocolate.litres = 1;

        hotChocolate.print();

        MenuItem* ptr = &hotChocolate;

        ptr->print();

        return 0;
}
