#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<math.h>




class Solution
{
public:
    Solution(){}

    std::string sort2MinNum(std::vector<int> &vec)
    {
        std::vector<std::string> s_vec{};
        for (int i = 0; i < vec.size();i++)
        {
            s_vec.push_back(std::to_string(vec[i]));
        }

        std::sort(s_vec.begin(), s_vec.end(), [&](std::string v_1, std::string v_2) { return std::stoi(v_1+v_2)<std::stoi(v_2+v_1);
         });

        std::string re;
        for (int i = 0; i < s_vec.size(); i++)
        {
            re += s_vec[i];
        }
        return re;
    }
};



int main()
{
    std::vector<int> vec{3, 32, 321};
    Solution ss;
    std::cout << ss.sort2MinNum(vec) << '\n';

    return 0;
}
