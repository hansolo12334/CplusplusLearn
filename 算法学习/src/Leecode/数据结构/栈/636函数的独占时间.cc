#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

#include <limits.h>
#include <math.h>
#include <string>

using namespace std;


class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        stack<vector<int>> stk;


        vector<int> re(n, 0);

        stack<int> runningId{};

        int m = logs.size();
        int lastTime = 0;

        for (int i = 0; i < m; i++)
        {
            string index;
            string time;
            bool start = false;
            int j = 0;

            while (logs[i][j] != ':')
            {
                index += logs[i][j];
                j++;
            }
            j++;
            start = logs[i][j] == 's' ? true : false;
            while (logs[i][j] != ':')
            {
                j++;
            }
            j++;
            while (j < logs[i].size())
            {
                time += logs[i][j];
                j++;
            }

            int currentIdx = stoi(index);
            int currentTime = stoi(time);

            if (!stk.empty())
            {

                //如果前一个状态为end 新进入的状态为start
                if(stk.top()[1]==false && start==true)
                {
                    //不管前后是不是同一个程序 不过如果想要start一个程序 则该程序必然之前就停止了
                    //所以 这里的start的程序必然是和前一个状态的程序不同的

                    //在end-> start的时间段内，如果后台还有程序运行 则计算其运行时间
                    if(!runningId.empty() )
                    {
                        re[runningId.top()] += currentTime - lastTime - 1;
                    }
                    //如果没有后台程序运行 则跳过
                    //将 前一状态弹出 压入新状态 记录当前新运行的进程
                    // stk.pop();
                    stk.push({currentIdx, start, currentTime});
                    runningId.push(currentIdx);
                    lastTime = currentTime;
                }
                //如果前一个状态为end 新进入的状态也是end 则计算 end -> end 之间 后台程序的运行时间
                else if(stk.top()[1]==false && start==false)
                {
                    if(!runningId.empty())
                    {
                        re[runningId.top()] += currentTime - lastTime ;
                        runningId.pop();
                    }
                    // stk.pop();
                    stk.push({currentIdx, start, currentTime});

                    lastTime = currentTime;
                }
                //如果前一个状态是 start 而新进入的状态也是 start 则停止前一个状态 而且必然 这两个程序是相同的 是递归的
                else if(stk.top()[1]==true && start==true)
                {
                    re[stk.top()[0]] += currentTime - lastTime;
                    // stk.pop();
                    stk.push({currentIdx, start, currentTime});
                    runningId.push(currentIdx);
                    lastTime = currentTime;
                }
                //必然 前后是同一个程序 start->end
                else if(stk.top()[1]==true && start==false)
                {
                    re[stk.top()[0]] += currentTime - lastTime + 1;
                    // stk.pop();
                    stk.push({currentIdx, start, currentTime});
                    runningId.pop();
                    lastTime = currentTime;
                }
            }
            //第一次 stk为空 直接推入
            else
            {
                stk.push({currentIdx, start, currentTime});
                runningId.push(currentIdx);
                lastTime = currentTime;
            }
        }
        return re;
    }
};

int main()
{
    vector<string> logs{"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
    int n = 2;

    Solution ss;

    vector<int> re = ss.exclusiveTime(n, logs);
    for (auto r : re)
    {
        cout << r << '\n';
    }
    return 0;
}
