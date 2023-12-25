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
    double myPow(double x, int n) {
        long long N = n;
        if(N>=0)
        {
            return quick_mi(x, N);
        }
        else
        {
            return 1.0/quick_mi(x, -N);
        }
    }

    double quick_mi(double x,long long N)
    {
       if(N==0)
       {
           return 1.0;
       }
       double y = quick_mi(x, N / 2);
       return N % 2 == 0 ? y * y : y * y * x;
    }
};



int main()
{
    double x{2.00000};
    int n{10};

    Solution s;
    cout << s.myPow(x, n) << '\n';
    return 0;
}
