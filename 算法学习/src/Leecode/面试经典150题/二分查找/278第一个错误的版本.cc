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
    int firstBadVersion(int n) {
        int j = n;
        int i = 0;
        while(i<=j){
            int  mid =i+ (j - i) / 2;
            if(isBadVersion(mid)){
                j = mid-1;
            }
            else{
                i = mid + 1;
            }
        }
        return i;
    }
};


int main()
{
    int n = 5;
    int bad = 4;
    Solution s;
    cout << s.firstBadVersion(n) << '\n';
    return 0;
}
