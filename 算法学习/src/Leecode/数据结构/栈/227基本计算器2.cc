#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution
{
public:
    int calculate(string s)
    {
        vector<int> stk;
        int n = s.length();
        string temp{};
        int center = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                if (!temp.empty())
                {
                    stk.push_back(stoi(temp));
                    temp.clear();
                }
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (!temp.empty())
                {
                    stk.push_back(stoi(temp));
                    temp.clear();
                }
                stk.push_back(s[i]);
            }
            else
            {
                temp += s[i];
                if (i + 1 >= n)
                {
                    stk.push_back(stoi(temp));
                }
            }

            if (stk.size()!=0 &&  center< (stk.size()-1) )
            {

                if (stk[center] == '/')
                {
                    stk[center + 1] = stk[center - 1] / stk[center + 1];
                    stk[center] = -1;
                    stk[center - 1] = -1;


                }
                else if (stk[center] == '*')
                {
                    stk[center + 1] = stk[center - 1] * stk[center + 1];
                    stk[center] = -1;
                    stk[center - 1] = -1;


                }
                center += 2;
            }
        }
        if (stk.size() < 3)
        {
            return stk[0];
        }

        // for (int i = 1; i < stk.size(); i += 2)
        // {
        //     if (stk[i] == '/')
        //     {
        //         stk[i + 1] = stk[i - 1] / stk[i + 1];
        //         stk[i] = -1;
        //         stk[i - 1] = -1;
        //     }
        //     else if (stk[i] == '*')
        //     {
        //         stk[i + 1] = stk[i - 1] * stk[i + 1];
        //         stk[i] = -1;
        //         stk[i - 1] = -1;
        //     }
        // }

        for (auto ss : stk)
        {
            cout << ss << ' ';
        }
        cout << '\n';

        int re = 0;
        int i = 0;
        while (stk[i] == -1)
        {
            i++;
        }
        re = stk[i];
        bool add = false;
        i++;
        for (; i < stk.size(); i++)
        {
            //符号
            if (i % 2 == 1 && stk[i] == '+')
            {
                add = true;
            }
            else if (i % 2 == 1 && stk[i] == '-')
            {
                add = false;
            }
            //数字
            if (i % 2 == 0 && stk[i] != -1)
            {
                if (add)
                {
                    re += stk[i];
                }
                else
                {
                    re -= stk[i];
                }
            }
        }
        return re;
    }
};


int main()
{
    string s{"161+6033/2/69-11*2-12*6+51*40"};
    Solution ss;
    cout << ss.calculate(s) << '\n';
    return 0;
}
