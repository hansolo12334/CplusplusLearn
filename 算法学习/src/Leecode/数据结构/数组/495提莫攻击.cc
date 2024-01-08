#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>

#include<string>
#include<math.h>
#include<limits.h>

using namespace std;


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totalTime = 0;
        for (int i = 0; i < timeSeries.size()-1;i++){
            if(timeSeries[i]+duration < timeSeries[i+1]){
                totalTime =totalTime +duration;
            }
            else{
                totalTime =totalTime+(timeSeries[i+1]-timeSeries[i]);
            }
        }
        totalTime=totalTime+duration;
        return totalTime;
    }
};


int main()
{
    vector<int> timeSeries{1,2};
    int duration = 2;
    Solution ss;
    cout << ss.findPoisonedDuration(timeSeries, duration) << '\n';
    return 0;
}
