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
    vector<int> plusOne(vector<int>& digits) {


        size_t digits_size{digits.size()};

        if( digits[digits_size - 1]+1 !=10)
        {
            digits[digits_size - 1] += 1;
            return digits;
        }
        if(digits.size()==1)
        {
            if((digits[0] + 1) == 10)
            {
                digits[0] = 1;
                digits.push_back(0);
            }

            return  digits;
        }

        digits[digits_size-1] = 0;
        int jinwei{1};
        for (size_t i = digits_size - 2; i > 0; i--)
        {
            digits[i] += jinwei;
            if (digits[i]-10>=0)
            {
                jinwei = 1;
                digits[i] -= 10;
            }
            else
            {
                jinwei = 0;
            }
        }
        digits[0]+=jinwei;
        if(digits[0]==10)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};


int main()
{
    vector<int> digits{8,9,9,9};
    Solution ss;
    ss.plusOne(digits);
    for (int d : digits)
    {
        cout << d << ' ';
    }
    cout << '\n';
    return 0;
}
