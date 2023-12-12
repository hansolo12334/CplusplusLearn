#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<queue>


using namespace std;


unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);




vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> re{};

    while(left.size() && right.size())
    {
        if(left[0]<=right[0])
        {
            re.push_back(left[0]);
            left = vector<int>{left.begin() + 1, left.end()};
        }
        else
        {
            re.push_back(right[0]);
            right = vector<int>{right.begin() + 1, right.end()};
        }
    }
    while(left.size())
    {
        re.push_back(left[0]);
        left = vector<int>{left.begin() + 1, left.end()};
    }
    while(right.size())
    {
        re.push_back(right[0]);
        right = vector<int>{right.begin() + 1, right.end()};
    }

    return re;
}

vector<int> merge_sort(vector<int> input)
{
    if(input.size()<=1)
    {
        return input;
    }

    auto middle{floor(input.size() / 2)};

    vector<int> left{input.begin(), input.begin() + middle};
    vector<int> right{input.begin() + middle, input.end()};

    return merge(merge_sort(left), merge_sort(right));
}



int main()
{
    vector<int> input{};
    int size{10};
    input = generate_unifrom_random(1, 100, size);
    printVector(input);

    vector<int> re=merge_sort(input);

    printVector(re);


    return 0;
}
