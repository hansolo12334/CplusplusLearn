#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <set>
#include <string>



using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        string re;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int jinwei{0};
        while (i>= 0 || j>= 0)
        {
            int wei = 0;
            int x = (i>=0 &&a[i] == 49  ) ? 1 : 0;
            int y = (j>=0 &&b[j] == 49  )  ? 1 : 0;

            wei = x + y+jinwei;
            if(wei==3){
                wei = 1;
            }
            else if(wei==2){
                wei = 0;
                jinwei = 1;
            }
            else if(wei==1){
                jinwei = 0;
            }

            re = (wei == 1 ? '1' : '0') + re;

            i--;
            j--;
        }

        return jinwei==1 ? '1'+re :re;
    }


};


int main()
{
    string a{"1010"};
    string b{"1011"};
    Solution ss;
    cout << ss.addBinary(a, b) << '\n';
}
