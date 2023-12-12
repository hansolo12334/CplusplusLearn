#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<queue>


using namespace std;


unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);






vector<int> quick_sort(vector<int> input)
{

}



int main()
{
    vector<int> input{};
    int size{10};
    input = generate_unifrom_random(1, 100, size);
    printVector(input);

    vector<int> re=quick_sort(input);

    printVector(re);


    return 0;
}
