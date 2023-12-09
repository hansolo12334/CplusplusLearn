#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>

using namespace std;


class Solution {
public:
    string pathEncryption(string path) {
        string re{};
        for (int i = 0; i < path.size(); i++)
        {
            if(path[i]!='.')
            {
                re += path[i];
            }
            else{
                re += ' ';
            }
        }


        return re;
    }
};



int main()
{
    string path{"a.aef.qerf.bb"};
    Solution s;
    std::cout << s.pathEncryption(path) << '\n';
    return 0;
}
