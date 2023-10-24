#include<iostream>




// 在C++中，use 是为现有数据类型创建别名的关键字。
// 要创建这样的类型别名，我们使用 using 关键字，后跟类型别名的名称，后跟等号和现有数据类型
//现代C++中，约定是命名您自己定义的类型别名（或任何其他类型），以大写字母开头，不使用后缀。大写字母有助于区分类型名称与变量和函数的名称（以小写字母开头），并防止它们之间的命名冲突。而不是 hansolo_t x
int fuc(double,char)
{
    return 1;
}
int main()
{
    using Hansolo = double;

    Hansolo d{3.3};
    std::cout << ((typeid(d) == typeid(double)) ? "true" : "false") << ' ' << d << '\n';

    typedef long MM; //旧方法 别名在后！
    using MM = long; //现代c++

    //typedef int (*FcnType)(double, char);  //旧方法 typedefs 的语法对于更复杂的类型可能会变得丑陋
    using FcnType = int (*)(double, char); //现代c++

    FcnType sss; //sss 的类型是 int (*)(double, char)
    sss = fuc;//sss指向fuc函数
    std::cout << sss(1.1, 'c') << '\n';

    // 在上面的 typedef 定义中，新类型 （ FcnType ） 的名称隐藏在定义的中间，
    // 而在类型别名中，新类型的名称和定义的其余部分用等号分隔。


    return 0;
}

//使用类型别名使复杂类型更易于阅读
//类型别名的作用域
//在头文件中:
/*
#ifndef MYTYPES_H
#define MYTYPES_H

    using Miles = long;
    using Speed = long;

#endif

#included 这种方式的类型别名将被导入到全局命名空间中，从而具有全局范围
*/
