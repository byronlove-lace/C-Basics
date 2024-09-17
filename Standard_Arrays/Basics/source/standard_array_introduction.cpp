#include <iostream>
#include <array>

using std::array;
using std::cout;
using std::endl;

template <size_t N>
void print_array(const array<int, N>& data);

int main()
{
        array<int, 5> data = {1, 2, 3, 4, 5};

        print_array(data);
}

template <size_t N>
void print_array(const array<int, N>& data)
{
        for (size_t i = 0; i < data.size(); ++i)
        {
                cout << data[i] << endl;
        }
}
