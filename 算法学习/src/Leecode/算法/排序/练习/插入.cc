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

    for (int i = 0; i < n;i++){
        for (int j = i; j >0;j--){
            if(vec[j]<vec[j-1]){
                swap(vec[j], vec[j - 1]);
            }
        }
        // for (int j = i; j > 0 && vec[j] < vec[j - 1];j++){
        //     swap(vec[j], vec[j - 1]);
        // }
    }
    printVector(vec);
}
