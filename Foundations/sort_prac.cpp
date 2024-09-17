#include<iostream>
#include<algorithm>
#include<array>
#include<vector>

using namespace std;

class Square
{
        public:
                int side;

                Square(int side) : side(side) {};

};

bool compare_squares(Square x, Square y)
{
        return x.side < y.side;
}

int main()
{

        int arr1[] = {9, 4, 5, 8, 7, 12, 2, 1, 4, 51};
        sort(arr1, arr1 + 9); // 1st arg: pointer to first element / 2nd arg: pointer arithmatic 

        /*
        for (size_t i = 0; i < 9; ++i)
        {
                cout << arr1[i] << endl;
        }
        */

        sort(arr1, arr1 + 9, greater<int>());

        /*
        for (size_t i = 0; i < 9; ++i)
        {
                cout << arr1[i] << endl;
        }
        */

        Square arr2[] = {Square(6), Square(9), Square(5), Square(2) , Square(4) , Square(3) , Square(10) , Square(8)};
        sort(arr2, arr2 + 8, compare_squares);


        for (size_t i = 0; i < 9; ++i)
        {
                cout << arr2[i].side << endl;
        }

        vector<int> vec_nums {1, 2, 3, 4, 5};
        int first_element = *vec_nums.begin();

        array<int, 13> neat_nums {11, 12, 43, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        sort(vec_nums.begin(), vec_nums.end());
        sort(neat_nums.begin(), neat_nums.end());

        

}
