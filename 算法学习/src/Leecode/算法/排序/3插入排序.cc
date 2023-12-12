#include<iostream>
#include<vector>
#include<random>
using namespace std;


unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);




void insert_sort(vector<int> &input)
{
    size_t len{input.size()};
    int preIndex, current;
    for (int i = 1; i < len;i++)
    {
        preIndex = i - 1;
        current = input[i];

        //把这个元素插入到前面的序列中 插到比自己大的左边
        while(preIndex>=0 && input[preIndex]>current)
        {
            input[preIndex + 1]=input[preIndex];
            preIndex--;
        }
        input[preIndex + 1] = current;
    }
}


int main()
{
    vector<int> input{};
    int size{10};
    input = generate_unifrom_random(1, 100, size);
    printVector(input);

    insert_sort(input);

    printVector(input);


    return 0;
}
