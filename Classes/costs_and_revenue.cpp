#include <iostream>

using std::cout;
using std::endl;

class Costs; // forward declaration to allow for friend declaration below 
             
class Revenue
{
        friend bool profit(Revenue rev, Costs cst);

        private:
                int revenue;

        public:
                Revenue(int revenue) : revenue(revenue) {}
                bool big_bank(Costs cstObj);
};

class Costs
{
        friend bool profit(Revenue rev, Costs cst);
        friend bool Revenue::big_bank(Costs cstObj);

        private:
                int costs;

        public:
                Costs(int costs) : costs(costs) {}
};

int main()
{
        Revenue revenue(10000);
        Costs costs(500);

        bool isProf = profit(revenue, costs);
        bool bigProf = revenue.big_bank(costs);

        if (isProf)
        {
                cout << "We made bank!" << endl;

                if (bigProf)
                        cout << "A lot of bank!" << endl;
                else 
                        cout << "A little bank!" << endl;
        }
        else
                cout << "We're losing money!" << endl;
}

bool profit(Revenue revObj, Costs cstObj)
{
        if (revObj.revenue > cstObj.costs)
                return true;
        else
                return false;
}

bool Revenue::big_bank(Costs cstObj)
{
        int netGain = revenue - cstObj.costs;
        if (netGain > 5000)
                return true;
        else 
                return false;
}
