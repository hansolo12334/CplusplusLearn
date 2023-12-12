#include<iostream>
#include<vector>
#include<random>
#include<cmath>
using namespace std;


unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);




void shell_sort(vector<int> &input)
{
    size_t len{input.size()};
    int current{};
    int gap{1};
    int preIndex{};
    while (gap < len / 3)
    {
        gap = gap * 3 + 1;
    }
    //循环对所有增量序列排序这里如果序列长度为10，
    // 则第一次 gap=4 有四个增量序列 下标分别为
    // 1 4 7
    // 2 5 8
    // 3 6 9
    // 10
    // 第二次 gap=floor(gap/3)(不保留小数)=1 有一个增量序列 下标为
    // 1 2 3 4 5 6 7 8 9 10
    // 对以上两组增量序列 对每个增量序列分别进行插入排序
    for (gap; gap > 0;gap=floor(gap/3))
    {

        for (int i = gap; i < len;i++)
        {
            current=input[i]; //当前位置 最终目的是把当前位置的数插入到前面
            preIndex = i - gap; //前一个位置
            // cout <<"preIndex: "<< preIndex << '\n';
            // int j{};
            // for (j = i - gap; j >= 0 && input[j] > temp; j -= gap)
            // {
            //     input[j + gap] = input[j];
            // }
            while(preIndex>=0 && input[preIndex]>current)
            {
                // 将比自己大的数据都向前挪
                input[preIndex + gap] = input[preIndex];
                preIndex -= gap;
            }
            input[preIndex + gap] = current;//将当前位置数据插入到比自己大的数的左边
        }
        cout << "间隔为 " << gap << ":\n";
        printVector(input);
    }
}


int main()
{
    vector<int> input{};
    int size{10};
    input = generate_unifrom_random(1, 100, size);
    printVector(input);

    shell_sort(input);

    printVector(input);


    return 0;
}
