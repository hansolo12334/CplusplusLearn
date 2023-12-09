#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>

using namespace std;


class Solution {
public:
    string dynamicPassword(string password, int target) {
        return string{password.begin() + target, password.end()}+string{password.begin(), password.begin() + target} ;
    }


     string dynamicPassword1(string password, int target) {
         reversePassword(password,0,password.size()-1);
         reversePassword(password, password.size()-target, password.size() - 1);
         reversePassword(password, 0,  password.size()-target-1);

         return password;
     }

     void reversePassword(string &password,int begin,int end)
     {
        while(begin<end)
        {
            swap(password[begin], password[end]);
            begin++;
            end--;
        }
     }
};









int main()
{
    string password{"s3cur1tyC0d3"};
    int target{4};
    Solution s;
    cout << s.dynamicPassword1(password, target) << '\n';
    return 0;
}
