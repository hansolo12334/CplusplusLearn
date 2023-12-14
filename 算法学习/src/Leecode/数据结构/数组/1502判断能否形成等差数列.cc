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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int gap{INT_MIN};
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            for (size_t j = i + 1; j < arr.size();j++)
            {
                if(arr[i]>arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }

        }
        gap = arr[0] - arr[1];
        for (size_t i = 1; i < arr.size()-1;i++)
        {
            if(gap!=(arr[i]-arr[i+1]))
            {
                return false;
            }
        }
         return true;
    }
    bool canMakeArithmeticProgression1(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (size_t i = 1; i < arr.size()-1;i++)
        {
            if(arr[i-1]+arr[i+1]!= arr[i]*2)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> arr{1,2,4};
    Solution s;
    cout << s.canMakeArithmeticProgression1(arr) << '\n';
    return 0;
}
