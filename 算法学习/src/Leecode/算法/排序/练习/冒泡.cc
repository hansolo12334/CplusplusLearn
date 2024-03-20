#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);


int main()
{
    vector<int> vec{1, 5, 4, 8, 9, 6};

    int n = vec.size();
    for (int i = 0; i < n;i++){
        bool isSwap = false;
        for (int j = i+1; j < n - i;j++){
            if(vec[j]<vec[j-1]){
                swap(vec[j], vec[j-1]);
                isSwap = true;
            }
        }
        if(isSwap){
            break;
        }
    }

    printVector(vec);
    return 0;
}
