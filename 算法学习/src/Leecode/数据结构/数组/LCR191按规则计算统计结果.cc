#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        vector<int> re;
        int temp{1}, temp_without0{1};
        int zerosum{0};
        for (int a : arrayA)
        {
            if(a==0)
            {
                zerosum++;
            }
            else
            {
                temp_without0 *= a;
            }

            temp *= a;
        }
        for (int i = 0; i < arrayA.size();i++)
        {
            if(arrayA[i]==0 && zerosum>1)
            {
                re.push_back(0);
            }
            else if (arrayA[i]==0 && zerosum==1)
            {
                re.push_back(temp_without0);
            }
            else
            {
                re.push_back(temp / arrayA[i]);
            }

        }
        return re;
    }
};










int main()
{
    vector<int> in{2, 4, 6, 8, 10};
    Solution s;
    vector<int> re = s.statisticalResult(in);
    for(int r:re)
    {
        std::cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
