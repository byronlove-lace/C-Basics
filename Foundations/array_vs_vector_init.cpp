#include <array>  // for std::array
#include <vector> // for std::vector

int main()
{
    std::array<int, 5> a {};  // a std::array of 5 ints
    std::vector<int> b(5);    // a std::vector of 5 ints (for comparison)
    std::vector<int> vec_nums {1, 2, 3, 4, 5}; // OR this way

    return 0;
}
