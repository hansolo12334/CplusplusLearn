#include<iostream>
#include<algorithm>
#include<vector>



class Solution
{
public:
    Solution(){}

    int maxProfile(std::vector<int> &input )
    {
        if(input.size()<=1){
            return 0;
        }
        int maxPro = input[1] - input[0];
        int minNum = input[0];
        for (int i = 2; i < input.size(); i++)
        {
            if(minNum>input[i-1]){
                minNum = input[i - 1];
            }
            if(input[i]-minNum>maxPro){
                maxPro = input[i] - minNum;
            }

        }
        return maxPro>0? maxPro :0;
    }
};

int main()
{
    Solution ss;
    std::vector<int> input{9, 11, 8, 5, 7, 12, 16, 14};

    std::cout << ss.maxProfile(input) << '\n';
    return 0;
}
