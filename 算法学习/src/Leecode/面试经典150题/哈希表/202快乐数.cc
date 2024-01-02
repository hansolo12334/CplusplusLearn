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
//方法一 哈希表检测循环
    bool  isHappy(int n) {
        unordered_map<int, int> map{};
        while (1)
        {
            map[n]++;
            if(map[n]>=2)
            {
                break;
            }
            getSum(n);
            if (n == 1)
            {
                return true;
            }
        }
        return false;
    }

    void getSum(int &n)
    {
        int new_n{0};
        int divid{10};

        while (n)
        {
            new_n = new_n + ( n % divid) * ( n % divid);
            n = (n -  n % divid) / 10;
        }

        n = new_n;
    }

int getNext(int n)
{
    int new_n{0};
    int divid{10};

    while (n)
    {
        new_n = new_n + ( n % divid) * ( n % divid);
        n = (n -  n % divid) / 10;
    }

    return new_n;
}
//方法二 快慢指针
bool  isHappy1(int n) {
    int slow = n;
    int fast = getNext(n);
    while(fast!=1 && slow!=fast)
    {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}
};

int main()
{
    int n{68};//78
    Solution s;
    cout << s.isHappy1(n) << '\n';
    return 0;
}
