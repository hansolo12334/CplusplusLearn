#include<iostream>
#include<vector>


using namespace std;


int main()
{
    vector<char> ss{'1','2','4'};
    vector vv{1, 1, 1, 1};//类模板推导 CTAD
    cout << ssize(vv) << '\n';//c++20 返回有符号数
    auto s = ssize(vv); // long
    cout << size(vv) << '\n'; //c++17
    cout << vv.size() << '\n';


    cout << vv[7] << '\n'; //操作符 []不进行边界检查 会出错

    cout << vv.at(7) << '\n'; // 进行边界检查
    /*terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 7) >= this->size() (which is 4)*/
    return 0;
}
