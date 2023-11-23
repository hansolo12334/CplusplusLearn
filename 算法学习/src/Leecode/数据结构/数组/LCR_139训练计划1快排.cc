#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {

        int pb{0};
        auto pe{actions.size()-1};

        while(pb<pe)
        {
            while(pb<pe &&  actions[pb]%2==1)
            {
                pb++;
            }
            while(pb<pe && actions[pe]%2==0)
            {
                pe=pe-1;
            }

            //交换
            int temp{actions[pb]};
            actions[pb] = actions[pe];

            actions[pe] = temp;

        }
        return actions;
    }
};

int main()
{
    std::vector<int> actions{1, 2, 3, 4, 5};
    Solution s;

    std::vector re{s.trainingPlan(actions)};
    for(int ss:re)
    {
        std::cout << ss << ' ';
    }
    std::cout << '\n';
    return 0;
}
