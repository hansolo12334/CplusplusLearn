#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        auto maxIt = *max_element(documents.begin(), documents.end());

        vector<int> maps(maxIt+1, 0);
        int maxs{0};
        for (int i = 0; i < documents.size(); i++)
        {
            maps[documents[i]]++;
            if(maps[documents[i]]>maxs)
            {
                maxs = maps[documents[i]];
            }
            if(maxs>=2)
            {
                return documents[i];
            }
        }
        return -1;
    }


//解法二 哈希表
int findRepeatDocument1(vector<int>& documents) {
    unordered_map<int, int> map;
    for(int doc:documents)
    {

        if (map[doc] >=1 )
        {
            return doc;
        }
        else{
            map[doc]++;
        }

    }
    return -1;
}
};









int main()
{
    vector<int> in{2, 5, 3, 0, 5, 1};
    Solution s;

    std::cout << s.findRepeatDocument1(in) << '\n';
    return 0;
}
