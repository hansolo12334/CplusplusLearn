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
    int countOdds(int low, int high) {


        int re;
        if(low%2==0 && high%2==0){
            re = (high - low) == 2 ? 1 : (high - low) / 2;
        }
        else if(low%2==1&&high%2==1){
            re = 2 + ((high - low) == 2 ? 0 : ((high - low) / 2 - 1) ) ;
        }
        else if((low%2==0&& high%2==1) ||(low%2==1&&high%2==0)){
            re = 1 + ((high - low) == 1 ? 0 : (high - low) / 2);
        }
        // if(){
        //     re = 1 + (high - low) == 1 ? 0 : (high - low) / 2;
        // }
        return re;
    }

    //方法二
    int countOdds1(int low, int high) {
        return (low % 2 ==1 || high % 2 == 1) ? (1 + (high - low) / 2 ): (high - low) / 2;
    }
};

int main()
{
    int low = 3;
    int hight = 7;
    Solution ss;
    cout << ss.countOdds1(low, hight) << '\n';
    return 0;
}
