#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <map>
#include <math.h>
#include <set>
#include <string>
#include <unordered_set>


using namespace std;


class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small)
        : m_big{big}
        , m_medium{medium}
        , m_small{small}
    {
    }

    bool addCar(int carType) {
        switch (carType)
        {
        case 3:
            if(m_small>0){
                    m_small--;
                    return true;
            }
            else{
                return false;
            }
            break;

        case 2:
            if(m_medium>0){
                    m_medium--;
                    return true;
            }
            else{
                return false;
            }
            break;
        case 1:
            if(m_big>0){
                    m_big--;
                    return true;
            }
            else{
                return false;
            }
            break;
        }
    }

private:
    int m_big{};
    int m_medium{};
    int m_small{};
};


int main()
{
    vector<string> vec{"ParkingSystem", "addCar", "addCar", "addCar", "addCar"};
    vector<vector<int>> operators{{1, 1, 0}, {1}, {2}, {3}, {1}};
    ParkingSystem p(1,1,0);
    for (int i = 1; i < vec.size();i++){
        p.addCar(operators[i][0]);
    }

    return 0;
}
