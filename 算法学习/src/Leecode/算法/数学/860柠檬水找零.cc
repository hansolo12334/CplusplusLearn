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
    bool lemonadeChange(vector<int>& bills) {
        // unordered_map<int, int> map{{5, 0}, {10, 0}, {20, 0}};
        int nums_5=0;
        int nums_10=0;


        for (int i = 0; i < bills.size();i++){
            // map[bills[i]]++;
            if(bills[i]==5){
                nums_5++;
            }
            else if(bills[i]==10){
                nums_10++;
            }

            if(bills[i]!=5)
            {
                if(bills[i]==10 && nums_5>0){
                nums_5--;
                }
                else if(bills[i]==20 && nums_5>0 && nums_10>0)
                {
                    nums_5--;
                nums_10--;
                }
                else if(bills[i]==20 && nums_5>=3)
                {
                    nums_5 -= 3;
                }
                else{
                    return false;
                }
            }

        }

        // if ((5 * nums_5 + 10 * nums_10 + 20 * nums_20) == 5 * bills.size())
        // {
        //     return true;
        // }
        return true;
    }
};



int main()
{
    vector<int> bills{5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    Solution s;
    cout << s.lemonadeChange(bills) << '\n';
    return 0;
}
