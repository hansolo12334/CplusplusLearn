#include<iostream>
#include<algorithm>
#include<vector>



class Solution
{
public:
    Solution(){}

    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        if(n==2){
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        std::vector<int> dp(n,0);

        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            int j = i - 2;
            while(j>=0){
                dp[i] = std::max(dp[j] + nums[i], dp[i]);
                j--;
            }
        }

        return dp[n - 1] > dp[n - 2] ? dp[n - 1] : dp[n - 2];
    }

    int rob1(std::vector<int>& nums)
    {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(dp[0], nums[1]);

        for (int i = 2; i < n;i++){
            dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};



int main()
{
    std::vector<int> num{2, 1, 1, 2};
    Solution ss;
    std::cout << ss.rob1(num) << '\n';
    return 0;
}
