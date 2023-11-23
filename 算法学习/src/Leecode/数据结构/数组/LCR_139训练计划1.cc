#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        std::vector<int> ji{};
        std::vector<int> ou{};
        std::vector<int> re{};
        for (int act : actions)
        {
            if(act%2==1)
            {
                ji.push_back(act);
            }
            else
            {
                ou.push_back(act);
            }
        }
        re.insert(re.end(), ji.begin(), ji.end());
        re.insert(re.end(), ou.begin(), ou.end());
        return re;
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
