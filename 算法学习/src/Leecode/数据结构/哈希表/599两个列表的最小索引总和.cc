#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        for (int i = 0; i < list1.size();i++)
        {
            map1[list1[i]] =i ;
        }
        int minSize = INT_MAX;
        vector<string> re;
        for (int i = 0; i < list2.size(); i++)
        {
            if(map1.find(list2[i])!=map1.end())
            {
                if((map1[list2[i]]+i) <= minSize)
                {
                    if((map1[list2[i]]+i) < minSize)
                    {
                        re.clear();
                        re.push_back(list2[i]);
                    }
                    else{
                        re.push_back(list2[i]);
                    }
                    minSize = map1[list2[i]] + i;
                }
                else{
                    break;
                }
            }
        }
        return re;
    }
};



int main()
{
    vector<string> list1{"happy","sad","good"};
    vector<string> list2{"sad","happy","good"};
    Solution ss;
    vector<string> re = ss.findRestaurant(list1, list2);
    for(auto r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
