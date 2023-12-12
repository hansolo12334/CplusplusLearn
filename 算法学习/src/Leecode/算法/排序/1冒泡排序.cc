#include<iostream>
#include<vector>
#include<random>
using namespace std;


unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);

void bubble_sort(vector<int> &input)
{
    for (int i = input.size(); i >0 ;i--)
    {
        for (int j = 0; j < i-1; j++)
            if (input[j] > input[j + 1])
            {
                swap(input[j], input[j + 1]);
            }
    }
}




int main()
{
    vector<int> input{};
    int size{10};
    input = generate_unifrom_random(1, 100, size);
    printVector(input);

    bubble_sort(input);

    printVector(input);


    return 0;
}
