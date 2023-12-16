
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

#include <deque>
#include <queue>


using namespace std;


class Solution {
public:
    char dismantlingAction(string arr) {
        if(arr.size()==1)
        {
            return arr[0];
        }
        if(arr.size()==0)
        {
            return ' ';
        }
        unordered_map<char, int> map{};
        for (int i = 0; i < arr.size();i++)
        {
            map[arr[i]]++;
        }
        for (int i = 0; i < arr.size();i++)
        {
            if(map[arr[i]]==1)
            {
                return arr[i];
            }
        }
        return ' ';
    }
};


int main()
{
    string arr{"ccdd"};
    Solution ss;
    cout << ss.dismantlingAction(arr) << '\n';
    return 0;
}
