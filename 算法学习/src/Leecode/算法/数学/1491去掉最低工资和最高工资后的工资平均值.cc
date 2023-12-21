#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>
#include<set>

using namespace std;


class Solution {
public:
    double average(vector<int>& salary) {
        int size = salary.size();
        int minevera{salary[0]};
        int maxevera{0};
        double re;
        for (int i = 0; i < salary.size(); i++)
        {
            re += salary[i];
            if ( minevera > salary[i])
            {
                minevera = salary[i];
            }
            if(maxevera<salary[i]){
                maxevera = salary[i];
            }
        }
        return (re - maxevera - minevera) / (size - 2);
    }
};



int main()
{
    vector<int> salary{1000,2000,3000};
    Solution s;
    cout << s.average(salary) << '\n';
    return 0;
}
