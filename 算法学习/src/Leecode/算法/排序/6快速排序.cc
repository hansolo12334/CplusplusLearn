#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<queue>


using namespace std;


unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);






void quick_sort(vector<int> &input,int l,int r)
{
    if(l+1>=r)
    {
        return;
    }
    int first = l;
    int last = r - 1;
    int key = input[first];
    while(first<last)
    {
        while(first<last&& input[last]>=key)
        {
            last--;
        }
        input[first] = input[last];
        while (first<last && input[first]<=key)
        {
            first++;
        }
        input[last] = input[first];
    }
    input[first] = key;

    quick_sort(input, l, first);
    quick_sort(input, first+1, r);
}

    int main()
    {
        vector<int> input{};
        int size{10};
        input = generate_unifrom_random(1, 100, size);
        printVector(input);

        quick_sort(input, 0, input.size());

        printVector(input);


        return 0;
}
