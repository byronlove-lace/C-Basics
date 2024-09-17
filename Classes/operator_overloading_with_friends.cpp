#include <iostream>

using std::cout;
using std::endl;

class Counter
{
        friend void set_to_zero(Counter &counter);
        friend Counter operator-(Counter const &c1, Counter const &c2);
        friend Counter operator*(int m, Counter const &c);

        private: 
                int count;

        public:
                // Constructor
                Counter(int count) : count(count) {}
                
        void print()
        {
                cout << count << endl;
        }

        void increment()
        {
                ++count;
        }

        Counter operator+(Counter const &counter)
        {
                Counter new_counter(count + counter.count); 
                return new_counter;
        }
        /* NB this assumes that the member function is being called for the left operand for the operation */ 
        
        /* Error: must have 0 or 1 argument 
        Counter operator*(int m, const &counter)
        {
                int new_count = m * counter.count;
                return Counter(new_count);
        }
        */
        Counter operator*(int m)
        {
                int new_count = count * m;
                return Counter(new_count);
        }
};

void set_to_zero(Counter &counter)
{
        counter.count = 0;
}

Counter operator-(Counter const &c1, Counter const &c2)
{
        Counter new_counter(c1.count - c2.count); 
        // OR int new_count = c1.count - c2.count;
        // return Counter(new_count)
        return new_counter;
}

// This will only work if: int * Counter
Counter operator*(int m, Counter const &c)
{
        int multiplied_count = m * c.count;
        return Counter(multiplied_count);
}

int main()
{
        Counter counter1(7);
        Counter counter2(3);

        counter1.increment();
        counter1.print();
        counter2.print();

        Counter counter3 = counter1 + counter2;
        counter3.print();

        set_to_zero(counter3);
        counter3.print();

        counter3 = counter1 - counter2;
        counter3.print();

        counter3 = counter3 * 5;
        counter3.print();

        return 0;
}

