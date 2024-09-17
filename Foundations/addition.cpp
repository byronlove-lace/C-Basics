#include<iostream>
// input ouput stream header
// any file that inputs from keyboard / outputs to screen

int main()
{
        // note empty parameter above equiv. (void) in C
        // doing this in C disables compile-time argument checking: bad code

        std::cout << "Enter first integer: "; // prompt user for data 
        int number1;
        std::cin >> number1; // read first integer from user into number1
        
        std::cout << "Enter second integer: "; 
        int number2;
        std::cin >> number2; 

        int sum = number1 + number2; // initialize sum with sum of two numbers
        std::cout << "Sum is " << sum << std::endl; // display the sum; endline
}

