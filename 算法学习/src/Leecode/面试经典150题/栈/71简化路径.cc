#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>
#include<map>
#include<unordered_set>


using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dicAndFile{};
        unordered_map<string, int> maps{{".", 1}, {"..", 2}};
        string re{};
        int i = 1;
        string temp{};
        string manu{};
        dicAndFile.push("/");

        while (i < path.size())
        {
            if( isCharacter(path[i]))
            {
                temp += path[i];
            }
            else
            {
                if(temp.length() && temp!="." && temp!=".."){
                    //cout << temp << '\n';
                    dicAndFile.push(temp);
                }
                // cout << temp << '\n';
                temp = {};
            }
            if(temp.length() && (i+1)==path.size()&& temp!="." && temp!=".."){
                //cout << temp << '\n';
                dicAndFile.push(temp);
                temp = {};
            }

            // ../
            if( (( (i+2)<path.size() && path[i]=='.' && path[i+1]=='.' && path[i+2]=='/') || (path[i]=='.' && path[i+1]=='.'&&(i+2)==path.size()  )) && temp!=".." && temp.size()<2)
            {
                if(dicAndFile.size()!=1){
                    //cout <<"pop! " << path[i]<<path[i+1]<<path[i+2] << '\n';
                    dicAndFile.pop();
                }

            }
            i++;
        }

        if(!dicAndFile.empty())
        {
            re = dicAndFile.top();
            dicAndFile.pop();
        }

        while(dicAndFile.size()>=2)
        {
            // cout << dicAndFile.top() << '\n';
            re = dicAndFile.top()+ "/"+ re;
            dicAndFile.pop();
        }
        if(!dicAndFile.empty()){
            re = dicAndFile.top() + re;
        }

        return re;
    }

    bool isCharacter(char s)
    {
        if((s<='z' && s>='a')|| (s>='A'&& s<='Z') || s=='_' || s=='.' || (s>='1'&& s<='9'))
        {
            return true;
        }
        return false;
    }

//方法二 官方解法
vector<string> split(const string &s,char delim)
{
    vector<string> ans;
    string cur{};
    for(char ch:s)
    {
        if(ch==delim){
            // ans.push_back(cur);
            ans.push_back(move(cur));
            cur.clear();
        }
        else{
            cur += ch;
        }
    }
    ans.push_back(move(cur));
    // ans.push_back(cur);
    return ans;
}


string simplifyPath1(string path) {
    vector<string> names = split(path,'/');
    vector<string> stack{};
    for(string &name:names)
    {
        if(name==".."){
            if(!stack.empty()){
                stack.pop_back();
            }
        }
        else if(!name.empty() && name!="."){
            stack.push_back(move(name));
        }
    }
    string ans{};
    if(stack.empty()){
        ans = "/";
    }
    else{
        for(string &name:stack){
            ans += "/" + move(name);
        }
    }
    return ans;
    }
};

int main()
{
    string path{"/../..ga/b/.f..d/..../e.baaeeh./.a"};
    Solution s;
    cout << s.simplifyPath1(path) << '\n';
    return 0;
}
// "/..ga/b/.f..d/..../e.baaeeh./.a"
