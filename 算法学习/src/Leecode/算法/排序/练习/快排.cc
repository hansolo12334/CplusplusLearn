#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned int getRandomDeviceValue();
std::vector<int> generate_unifrom_random(int min, int max, int size);
void printVector(std::vector<int> &v);


//计算一次 把 大于pivot的数放右边，小于pivot的数放左边
int get_mid(vector<int> &vec,int l,int r)
{
    int pivot = vec[l];
    while (l < r)
    {
        while(l<r && vec[r]>=pivot){
            r--;
        }
        vec[l] = vec[r];

        while(l<r &&vec[l]<=pivot){
            l++;
        }
        vec[r] = vec[l];
    }
    vec[l] = pivot;
    return l;
}

void quick_sort(vector<int> &vec,int l,int r)
{
    if(l<r){
        int mid=get_mid(vec, l, r);

        quick_sort(vec, l, mid - 1);
        quick_sort(vec, mid + 1, r);
    }
}


class Fun{
    public:
    virtual void func() {} // Add the definition for the func function.
};
class FF : public Fun{
    public:
        virtual void func();
};

void FF::func()
{
    std::cout << "aaa\n";
}

int main()
{
    vector<int> vec{7, 5, 4, 8, 9, 6};

    quick_sort(vec, 0, vec.size() - 1);
    printVector(vec);

    FF aa;
    FF *bb = new FF{};
    bb->func();
    aa.func();
}
