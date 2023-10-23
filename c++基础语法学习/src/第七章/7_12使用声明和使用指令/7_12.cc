#include<iostream>

/*
 使用声明 using namespace xx;
 减少重复 std:: 键入的一种方法是使用 using-声明语句。using 声明允许我们使用非限定名称（没有作用域）作为限定名称的别名
*/

// 切勿在头文件的全局命名空间中使用它们!!!

int main()
{
    using std::cout;
    cout << "使用using std::cout更安全 ; 而不是using namespace std;\n";

    {
        //声明 using 语句后，无法取消它或将其替换为声明范围内的其他 using 语句
        //能做的最好的事情就是从一开始就使用块范围规则有意限制 using-语句的范围
        using namespace std;
        cout << "using namespace std; 不安全，容易和别的名称冲突。\n";

    }



    return 0;
}
