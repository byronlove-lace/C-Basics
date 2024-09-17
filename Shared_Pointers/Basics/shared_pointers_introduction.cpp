#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <atomic>

using std::cout;
using std::endl;

// Forward References
void AdvancedSharedPointer();
void FileExample();

class Base
{
        virtual void speak()
        {
                cout << "I'm a Base" << endl;
        }

        virtual ~Base()
        {
               cout << "Base destroyed." << endl; 
        }

};

class Derived : public Base
{
        public:
                void speak() override
                {
                        cout << "I'm a Derived." << endl;
                }
                
                ~Derived() override
                {
                        cout << "Derived destroyed." << endl;
                }
};

void custom_deleter(Base *ptr)
{
        cout << "Custom deleter called." << endl;
        delete ptr;
}

int main()
{
        // Creating a shared_ptr and initializing it with a new object
        std::shared_ptr<Base> sp1 = std::make_shared<Base>();
        sp1->speak();

        // Creating a shared_ptr with a custom deleter
        std::shared_ptr<Base> sp2(new Derived, custom_deleter);
        sp2->speak();

        // Creating a shared_ptr from another shared_ptr (copying)
        std::shared_ptr<Base> sp3 = sp1;
        sp3->speak();

        // Reseting a shared_ptr
        sp3.reset(new Derived);
        sp3->speak();
}
