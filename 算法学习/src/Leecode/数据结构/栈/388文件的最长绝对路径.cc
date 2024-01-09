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
    int lengthLongestPath(string input)
    {
        int n = input.length();
        int pos = 0;
        int ans = 0;
        stack<int> st;
        while(pos<n){
            //检测当前文件的深度
            int depth = 1;
            while(pos<n && input[pos]=='\t'){
                pos++;
                depth++;
            }
            //统计当前文件名的长度
            int len = 0;
            bool isfile = false;
            while(pos<n && input[pos]!='\n'){
                if(input[pos]=='.'){
                    isfile = true;
                }
                len++;
                pos++;
            }

            //跳过换行符
            pos++;



            while (st.size() >= depth)
            {
                st.pop();
            }
            if(!st.empty()){
                len += st.top() + 1;
            }
            if(isfile){
                ans = max(ans, len);
            }
            else{
                st.emplace(len);
            }
        }
        return ans;
    }
};


int main()
{
    string input{"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"};
    Solution ss;
    cout << ss.lengthLongestPath(input) << '\n';
    return 0;
}
