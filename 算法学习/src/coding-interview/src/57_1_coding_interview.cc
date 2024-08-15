#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
public:
    Solution()
    {

    }
    std::vector<int> sumSNum(std::vector<int> & input,int sum)
    {
        std::sort(input.begin(), input.end());
        int tail = input.size() - 1;
        int head = 0;
        while(input[tail]>sum){
            tail--;
        }

        while(head<tail){
            if(input[head]+input[tail]==sum){
                return {input[head], input[tail]};
            }
            else if(input[head]+input[tail]>sum){
                tail--;
            }
            else if(input[head]+input[tail]<sum){
                head++;
            }
        }
        return {};
    }
};

int main()
{
    std::vector<int> input{1, 2, 3, 4};
    int sum = 7;

    Solution ss;
    auto re = ss.sumSNum(input, sum);
    for(auto r:re){
        std::cout << r << ' ';
    }
    std::cout << '\n';
    return 0;
}
