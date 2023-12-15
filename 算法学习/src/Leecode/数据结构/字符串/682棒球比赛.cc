#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;


class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> nums{};

        int numsSize{1};
        nums.push_back(getNum(operations[0]));
        int re{nums[0]};


        for (int i = 1; i < operations.size(); i++)
        {
            if( operations[i]!="C" && operations[i]!="D" && operations[i]!="+")
            {
                numsSize++;
                nums.push_back(getNum(operations[i]));
                re += nums[numsSize - 1];
            }
            else if( operations[i]=="C")
            {
                re -= nums[numsSize - 1];
                numsSize--;
                nums.pop_back();
            }
            else if(operations[i]=="D")
            {
                numsSize++;
                nums.push_back(nums[nums.size() - 1] * 2);
                re += nums[numsSize - 1];
            }
            else if(operations[i]=="+")
            {
                numsSize++;
                nums.push_back( nums[nums.size() - 1] + nums[nums.size() - 2] );
                re += nums[numsSize - 1];
            }
        }


        return re;
    }



    //字符串转数字最快的办法是 ： stoi()

    int getNum(string s)
    {
        int re{0};
        int temp{1};
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                re +=temp*(s[i] - 48);
                temp *= 10;
            }
        }
        return s[0] == '-' ? -re : re;
    }
};


int main()
{
    vector<string> ops{"1"};
    Solution ss;
    cout << ss.calPoints(ops) << '\n';
    return 0;
}
