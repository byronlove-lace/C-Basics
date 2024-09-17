#include <iostream>

using std::cout;
using std::endl;

class MyClass
{
        friend void double_x(MyClass &object); 
        // friend funciton declared | takes MyClass object 

        private: // class can access but not instances
                int x;

                void add(int n)
                {
                        x += n;
                }

        public:
                MyClass(int x)  : x(x) {}; // constructor for class 
                                           // accepts x and sets member variable x to parameter x
                void print()
                {
                        cout << "x: " << x << endl;
                }
};

int main()
{
        MyClass myobj(7);
        // myobj.add(10); // can't naturally be used as it is a private member of class
        double_x(myobj); // NOT a member func of MyClass
                         // friend allows access of var 
        myobj.print();
}

void double_x(MyClass &object)
{
        int current_x_val = object.x;
        object.add(current_x_val);
}
