#include<iostream>


#define HANSOLO 30

//常量函数参数 通常不要使用const参数按值传递
void printInt(const int x)
{
    std::cout << x << "\n";
}
//也不要使用const返回类型
const int getValue()
{
    return 7;
}


int main()
{
    //常量变量 const 关键字
    const double gravity{9.8};
    //gravity = 10; //x 报错 表达式必须是可修改的左值
    //常量必须初始化 不能后赋值 否则报错
    //const double vel; //报错： 常量 变量 "vel" 需要初始值设定项
    int a{9};
    const int aa{a};    //可以从其他变量初始化

    printInt(2);

    //也不要使用const返回类型
    std::cout << getValue() << "\n";

    const int hansolo{30};


    //对于符号常量 更喜欢使用变量常量const xx而不是类似对象的宏 #define XXX xx
    //因为宏不方便调试 宏也可能与正常代码发生冲突
    std::cout << "符号常量 变量常量hansolo: " << hansolo << "\n";
    std::cout << "符号常量 宏 HANSOLO:" << HANSOLO << "\n";


    return 0;
}
