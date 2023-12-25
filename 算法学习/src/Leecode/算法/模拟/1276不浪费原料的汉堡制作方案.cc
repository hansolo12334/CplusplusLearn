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
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices<2*cheeseSlices){
            return {};
        }
        int aa = tomatoSlices - 2 * cheeseSlices;
        if ((aa) % 2 == 0 && cheeseSlices>=aa/2)
        {
            return {aa / 2, cheeseSlices - aa / 2};
        }
        else if((aa)==0 &&(aa) % 2 !=0 )
        {
            return {};
        }

        return {};
    }
};




int main()
{
    int tomatoSlices = 2385088;
    int cheeseSlices = 164763;
    Solution s;
    vector<int> re = s.numOfBurgers(tomatoSlices, cheeseSlices);
    for(int r:re)
    {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}
