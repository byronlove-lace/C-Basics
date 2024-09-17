#include <string>
#include <iostream>


int main() 
{
	std::string check = " check     ";	
	check.erase(0, check.find_first_not_of(" \t\n\r\f\v"));
	check.erase(check.find_last_not_of(" \t\n\r\f\v"));
	std::cout << check << "this" <<	std::endl;
}
