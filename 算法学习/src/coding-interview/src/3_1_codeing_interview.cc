#include<iostream>
#include<vector>
#include<algorithm>




class Solution
{
public:
    int duplicateInArray(std::vector<int> &input)
    {
        auto size{input.size()};
        for (int num : input)
        {
            if(num<0|| num>size){
                return -1;
            }
        }

        for (int i = 0; i < size - 1;++i)
        {
            while(i!=input[i]){
                if(input[i]==input[input[i]]){
                    return input[i];
                }
                std::swap(input[i], input[input[i]]);
            }
        }
        return -1;
    }
};


int main()
{
    std::vector<int> input{2, 3, 5, 4, 3, 2, 6, 7};

    Solution ss;

    int re=ss.duplicateInArray(input);

    std::cout << re << '\n';

    for(auto in : input){
        std::cout << in << ' ';
    }
    std::cout << '\n';

    return 0;
}
