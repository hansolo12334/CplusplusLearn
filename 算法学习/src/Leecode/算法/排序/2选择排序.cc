#include<iostream>
#include<vector>
#include<random>

using namespace std;

unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);




void choice_sort(vector<int> &input)
{
    for (int i = 0; i <input.size()-1 ;i++)
    {
        for (int j = i + 1; j < input.size();j++)
        {
            if(input[i]>input[j])
            {
                swap(input[i], input[j]);
            }
        }
    }
}




int main()
{
    vector<int> input{};
    int size{10};
    input = generate_unifrom_random(1, 100, size);
    printVector(input);

    choice_sort(input);

    printVector(input);


    return 0;
}
