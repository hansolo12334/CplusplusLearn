#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;

// 0 : 48  9:57
class Solution
{
public:
    string fractionToDecimal1(int numerator, int denominator)
    {
        string re_s;
        string re_b;
        //如果相除小于1 则 结果只有小数部分
        if (numerator / denominator < 1)
        {
            re_s = getSmaller(numerator % denominator ,denominator);
            re_s = "0." + re_s;
        }
        // 有整数  可能有小数部分
        else
        {
            re_b = getBigger(numerator / denominator);
            re_s = getSmaller(numerator % denominator ,denominator);
            if(!re_s.empty()){
                return re_b + '.' + re_s;
            }
            return re_b;
            // string re_s = getSmaller(numerator, denominator);
        }
        return re_s;
    }


    string getBigger(int num)
    {
        string re;
        if (num >= 10)
        {
            while (num != 0)
            {
                int temp = num - (num / 10) * 10;
                re = static_cast<char>(temp + 48) + re;
                num = num / 10;
            }
        }
        else
        {
            re += static_cast<char>(num + 48);
        }
        return re;
    }


    string getSmaller(int num, int denominator)
    {
        if(num==0){
            return {};
        }
        string re;
        unordered_map<int, string> map;
        string slice{};
        vector<int> nums{};
        while (num != 0)
        {
            slice.clear();
            int cunti = 0;
            while (num < denominator)
            {
                num *= 10;
                nums.push_back(num);
                if (cunti > 0)
                {
                    slice += '0';
                }
                cunti++;
            }

            int r = num / denominator;

            // nums.push_back(num);
            cout << num << '\n';

            if (r >= 10)
            {
                while (r != 0)
                {
                    int temp = r - (r / 10) * 10;

                    slice = static_cast<char>(temp + 48) + slice;
                    r = r / 10;
                }
            }
            else
            {
                slice += static_cast<char>(r + 48);
            }
            cout << slice << '\n';

            //如果除数是 不是偶数 则可能进入循环 是偶数一定能除尽
            if( !slice.empty())
            {
                if (map.find(num)!=map.end())
                {
                    int i = 0;
                    for (; i < nums.size(); i++)
                    {
                        if(nums[i]==num){
                            break;
                        }
                    }
                    string rre{};
                    if (i == 0)
                    {
                        for (int m = 0; m < nums.size() - 1;m++){
                            rre += map[nums[m]];
                        }
                        return '('+rre+')';
                    }

                    for (int j = 0; j < i;j++){
                        rre += map[nums[j]];
                    }

                    rre += '(';
                    for (int k = i; k < nums.size()-1; k++)
                    {
                        rre += map[nums[k]];
                    }
                    rre += ')';
                    return rre;
                }
                map[num] = slice;
                re += slice;
            }

            num %= denominator;
        }
        return re;
    }




    string fractionToDecimal(int numerator, int denominator)
    {

        string re_b{};
        string re_s{};
        int wei = 0;
        int first = 0;
        unordered_map<int, int> map;


        if (numerator < denominator)
        {
            re_b += '0';
        }
        while (numerator != 0)
        {
            int conti = 0;
            while (numerator < denominator)
            {
                numerator *= 10;
                if (first == 0)
                {
                    re_b += '.';
                    wei++;
                }
                else if (conti > 0)
                {
                    if (wei == 1)
                    {
                        map['0']++;
                        if (map['0'] >= 2)
                        {
                            return re_b + '(' + re_s + ')';
                        }
                    }
                    re_s += '0';
                }
                first++;
                conti++;
            }

            int r = numerator / denominator;
            if (r >= 10)
            {
                while (r != 0)
                {
                    int temp = r - (r / 10) * 10;

                    if (first == 0)
                    {
                        re_b = static_cast<char>(temp + 48) + re_b;
                    }
                    else
                    {
                        if (wei == 1)
                        {
                            map[temp]++;
                            if (map[temp] >= 2)
                            {
                                return re_b + '(' + re_s + ')';
                            }
                        }
                        re_s = static_cast<char>(temp + 48) + re_s;
                    }
                    r = r / 10;
                }
            }
            else
            {
                if (first == 0)
                {
                    re_b += static_cast<char>(r + 48);
                }
                else
                {
                    if (wei == 1)
                    {
                        map[r]++;
                        if (map[r] >= 2)
                        {
                            return re_b + '(' + re_s + ')';
                        }
                    }
                    re_s += static_cast<char>(r + 48);
                }
            }
            numerator %= denominator;
        }

        return re_b + re_s;
    }
};


int main()
{
    int numerator = 4;
    int denominator = 333;
    Solution s;
    cout << s.fractionToDecimal1(numerator, denominator) << '\n';
    return 0;
}
