#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

#include<queue>

using namespace std;


class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        if(putIn.empty())
        {
            return true;
        }
        stack<int> simPutInt{};
        stack<int> simTakeOut{};

        int takeOutPointer{0};
        int putInPointer{0};

        while (takeOutPointer<= (takeOut.size()-1))
        {
            while((putInPointer)<=(putIn.size()-1))
            {
                simPutInt.push(putIn[putInPointer]);
                putInPointer++;

                if(simPutInt.top()==takeOut[takeOutPointer])
                {
                    break;
                }

            }


            int temp{simPutInt.top()};
            while(1)
            {

                if(simPutInt.top()==takeOut[takeOutPointer])
                {
                    temp = simPutInt.top();
                    simPutInt.pop();
                    if(simPutInt.empty())
                    {
                        break;
                    }
                    takeOutPointer++;
                }
                else
                {
                    takeOutPointer--;
                    simPutInt.push(temp);
                    break;
                }
            }

            if(!simPutInt.empty())
            {
                if (simPutInt.top() != takeOut[takeOutPointer] && (putInPointer >= (putIn.size() - 1)))
                {
                    return false;
                }
                simPutInt.pop();
            }
            // putInPointer--;

            takeOutPointer++;
        }
        return true;
    }


//解法二
    bool validateBookSequences1(vector<int>& putIn, vector<int>& takeOut) {
        stack<int> stk{};
        int i{0};
        for (int put : putIn)
        {
            stk.push(put);
            while(!stk.empty() && stk.top()==takeOut[i])
            {
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};



int main()
{
    vector<int> putIn{6,7,8,9,10,11};
    vector<int> takeOut{9,11,10,8,7,6};
    Solution s;
    std::cout << s.validateBookSequences(putIn, takeOut) << '\n';
    return 0;
}
