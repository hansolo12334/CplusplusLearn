#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
public:
    Solution()
    {

    }

    void reOrderArray(std::vector<int> &arr)
    {
        int head = 0;
        int tail = arr.size() - 1;
        while(head<tail){
            while(head<tail && arr[head]%2==1){ //是奇数就跳过
                head++;
            }
            while(head<tail && arr[tail]%2==0){ //是偶数就跳过
                tail--;
            }
            std::swap(arr[head], arr[tail]);
        }

    }


    void reOrderArray1(std::vector<int> &arr)
    { //保持奇数偶数相对位置不变
        int n_size{0};
        for (auto ar : arr)
        {
            if(ar%2==1){
                n_size++;
            }
        }

        int head = 0;
        int tail = n_size;
        std::vector<int> backarr = arr;
        for (int i = 0; i < arr.size(); i++)
        {
            if(backarr[i]%2==1){
                arr[head] = backarr[i];
                head++;
            }
            else{
                arr[tail] = backarr[i];
                tail++;
            }
        }
    }
};

int main()
{
    std::vector<int> input{1,2,3,4,5};
    Solution ss;
    ss.reOrderArray1(input);
    for(auto in:input){
        std::cout << in << ' ';
    }
    std::cout << '\n';
    return 0;
}
