#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

#include<queue>
#include<deque>


using namespace std;


// class Checkout {
// public:
//     Checkout() {
//         //maxPrice.push(INT_MIN);
//     }

//     int get_max() {
//         if(goods.empty())
//         {
//             return -1;
//         }
//         return *max_element(goods.begin(), goods.end());
//     }

//     void add(int value) {
//         goods.push_back(value);

//     }

//     int remove() {
//         if(goods.empty())
//         {
//             return -1;
//         }
//         int removedGoods{*goods.begin()};
//         vector<int> temp{goods.begin() + 1, goods.end()};
//         goods = temp;

//         return removedGoods;
//     }

// private :
//     vector<int> goods{};
// };

class Checkout {
public:
    Checkout() {
        //maxPrice.push(INT_MIN);
    }

    int get_max() {
        if(maxPrices.empty())
        {
            return -1;
        }
        else
        {
            return maxPrices.front();
        }

    }

    void add(int value) {
        goods.push(value);


        while(!maxPrices.empty() && maxPrices.back()<value) //maxPrices 尾部小于Value的值全部出队
        {
            maxPrices.pop_back();
        }
        maxPrices.push_back(value);
    }

    int remove() {
        if(goods.empty())
        {
            return -1;
        }
        int removedGoods{ goods.front()};

        goods.pop();
        if(maxPrices.front()==removedGoods)
        {
            maxPrices.pop_front();
        }
        return removedGoods;
    }

private :
    deque<int> maxPrices{};
    queue<int> goods{};

};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */


int main()
{
    Checkout* obj = new Checkout();
    vector<string> operators{"Checkout","remove","get_max"};
    vector<int> inputs{{}, {}, {}};

    for (int i = 1; i < operators.size();i++)
    {
        if(operators[i]=="add")
        {
            obj->add(inputs[i]);
        }
        if(operators[i]=="get_max")
        {
            cout << "get_max " << obj->get_max() << '\n';
        }
        if(operators[i]=="remove")
        {
            cout << "remove " << obj->remove() << '\n';
        }
    }

    return 0;
}
