#include<iostream>


//使用delete关键字删除函数 这会导致编译时报错

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char x)= delete;
// {
//     std::cout << x << '\n';
// }

void printInt(bool) = delete;



//一个有趣的用法 如果想一次性删除许多冗余的重载函数  可以这样做：

void printDouble(double x)
{
    std::cout << x << '\n';
}

//之前需要这样：一个一个删
// void printDouble(int x) = delete;
// void printDouble(bool x) = delete;

//现在只需要：
// 该函数模板优先于其他类型的参数
// 由于此函数模板已被删除，对它的调用将停止编译
template <typename T>
void printDouble(T x) = delete;






int main()
{
    printInt(2);
    //printInt ('a');//error: use of deleted function ‘void printInt(char)’

   // printDouble('a');//error: use of deleted function ‘void printDouble(T) [with T = char]’

}
