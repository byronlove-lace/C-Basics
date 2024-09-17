#include <iostream>
#include <vector>
#include <algorithm>



/*
void PrintValue(int val)
{
        std::cout << val << std::endl;
}
// Or we can just use a lambda!
*/

void ForEach(const std::vector<int>& values, void(*func)(int))
{
        for (int value : values)
        {
                func(value);
        }
}

void HelloWorld(size_t count)
{
        for (size_t i = 0; i < count; ++i)
        {
                std::cout << "Hello World" << std::endl;
        }
}

int main()
{

        // this won't work: HelloWorld returns void
        // auto function = HelloWorld();
        
        // This works
        // auto function = &HelloWorld;
        
        // This also works: implicit conversion
        // auto function = HelloWorld;

        // this is the type: void(*)();
        // void(*function)() = HelloWorld;

        // But that's fuckin weird. So do this (C):
        typedef void (*helloWorldFunction)(size_t);
        // Or this (C++)
        // using void (*helloWordFunction)(int);

        helloWorldFunction function = HelloWorld;

        function(8);

        /* USE CASE */

        std::vector<int> values = {1, 2, 3, 4, 5};
        // ForEach(values, PrintValue);
        // We can do this:
        // ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl;});
        // or assign to an auto
        // When we use a lambda, we're going to use variables from an enclosing function within the lamdba function.
        // [] lets us decide what and how we want to pass them into the lambda
        auto lamda = [](int value) {std::cout << "Value: " << value << std::endl;}

        // Needlessly complicated shit: mutable
        // int a = 5;
        // [=] = pass by value
        // auto lamda = [=](int value) mutable {a = 6; std::cout << "Value: " << value << std::endl;}

        ForEach(values, lamdba);

        /* we can use a lambda in place of a function pointer
         * Want to pass a func to an API to call that func in 
         * the future? Use a lamdba. 
         */
        

        /* OTHER USE CASE */ 
        auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3});
        std::cout << *it << std::endl;

}
