#include <iostream>
#include <vector>


using namespace std;


template <typename T>
void passByRef(const vector<T> &ve)
{
    cout << ve[0] << '\n';
}


template <typename T>
void passByRef1(const T &ve)
{
    cout << ve[0] << '\n';
}


void passByRef2(const auto &ve) //c++ 20
{
    cout << ve[0] << '\n';
}

int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    passByRef(v1);
    passByRef1(v1);
    passByRef2(v1);
    return 0;
}
