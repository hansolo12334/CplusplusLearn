#include<iostream>


//按照约定，全局变量在全局命名空间中文件顶部的包含下方声明
int g_x{3};


// Non-constant global variables
//int g_x;                 // defines non-initialized global variable (zero initialized by default)
//int g_x {};              // defines explicitly value-initialized global variable
//int g_x { 1 };           // defines explicitly initialized global variable

// Const global variables
//const int g_y;           // error: const variables must be initialized
const int g_y { 2 };     // defines initialized global const

// Constexpr global variables
//constexpr int g_y;       // error: constexpr variables must be initialized
//constexpr int g_y { 3 }; // defines initialized global constexpr



//在命名空间内声明的变量也是全局变量
namespace Goo //Goo在全局范围生命
{
    int g_x{2};//因此g_x也是全局的
}


//全局变量的命名 一般在前面加 g_
//在命名非常量全局变量时，请考虑使用“g”或“g_”前缀，
//以帮助将它们与局部变量和函数参数区分开来


int main()
{
    std::cout << g_x << ' ' << Goo::g_x << '\n';
    return 0;
}
