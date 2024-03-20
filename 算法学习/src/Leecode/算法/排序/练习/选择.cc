#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);


int main()
{
    vector<int> vec{1, 5, 2, 8, 9, 6};

    int n = vec.size();

    for (int i = 0; i < n-1;i++){
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if(vec[minIdx]>vec[j]){
                minIdx = j;
            }
        }
        swap(vec[i], vec[minIdx]);
    }
    printVector(vec);
    return 0;
}
