#include<iostream>


// 假设您正在编写一个程序，该程序需要跟踪苹果是红色、黄色还是绿色，或者衬衫是什么颜色（来自预设的颜色列表）。
// 如果只有基本类型可用，你会怎么做？
// 您可以使用某种隐式映射（0 = 红色，1 = 绿色，2 = 蓝色）将颜色存储为整数值：


// 方法1 使用magic number
// constexpr int red{0};
// constexpr int green{1};
//虽然这对于阅读来说更好一些，但程序员仍然需要推断出 appleColor 并且 shirtColor （类型 int 为 ）旨在保存颜色符号常量集（可能在其他地方定义，可能在单独的文件中）中定义的值之一。


// 2 枚举类型 类似bool类型 true false
/*
 枚举（也称为枚举类型或枚举）是一种复合数据类型，其值限制为一组命名的符号常量（称为枚举器）
 C++ 支持两种类型的枚举：无作用域枚举(unscoped enumerations )和作用域枚举( scoped enumerations)。

 因为枚举是程序定义的类型 所以每个枚举都需要完全定义，然后才能使用它（正向声明是不够的）。

*/
// 无作用域枚举 emum
enum Color
{
    red,
    green,
    blue,

}; //enum定义必须以;结尾

enum DaysOfWeek
{
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday,
};

// 枚举类型命名规则 和 枚举成员
// 枚举类型命名 以大写开头  枚举成员命名 小写

// 枚举类型 基本作用就是便于让人便于理解：

enum FileReadResult
{
    readSuccess,
    readErrorFileOpen,
    readErrorFileRead,
    readErrorFileParse,
};

bool openFile()
{
    return false;
}

FileReadResult readFileContents()
{
    if (!openFile())
    {
        return readErrorFileOpen;
    }
    return readSuccess;
}


//当用户需要在两个或多个选项之间进行选择时，枚举类型也可以提供有用的函数参数：
enum SortOrder
{
    alphabetical, //按字母顺序排序
    alphabeticalReverse, //按字母顺序逆序
    numerical, //按数字排序
};

void sortData(SortOrder order)
{
    using std::cout;
    switch (order)
    {
    case alphabetical:
    {
        cout << "alphabetical" << '\n';
        break;
    }

    case alphabeticalReverse:
    {
        cout << "alphabeticalReverse" << '\n';
        break;
    }

    case numerical:
    {
        cout << "numerical" << '\n';
        break;
    }

    default:
    {
        cout << "none of order" << '\n';
        break;
    }

    }
}


//由于枚举很小且复制成本低廉，因此可以按值传递（并返回）枚举。

// 枚举成员 名称不能在同一作用域内的 多个枚举中使用 会发生冲突
// 避免枚举器命名冲突
// 因此可以把枚举类型放在命名空间中或者类中:

namespace hanolo_contents
{
    enum Color
    {
        green,
        blue,
        red,
    };

} // namespace hanolo_contents


int main()
{
    // int appleColort{0}; //my apple is red
    // int shirtColor{green};  //my shirt is green
    Color apple{red};
    Color shirt{green};

    std::cout << shirt << '\n';

    std::cout << "readFileContents " << readFileContents() << '\n';

    //当用户需要在两个或多个选项之间进行选择时，枚举类型也可以提供有用的函数参数：
    SortOrder type{numerical};
    sortData(type);

    // 无作用域枚举还为其枚举器提供命名作用域区域（与命名空间充当其中声明的名称的命名作用域区域非常相似）。
    // 这意味着我们可以按如下方式访问无作用域枚举的枚举器：
    hanolo_contents::Color watermelon{hanolo_contents::Color::green};
    std::cout << "watermelon " << watermelon << '\n';

    std::cout << "hanolo_contents::blue "<<hanolo_contents::blue << '\n';//这也行？
    std::cout << "hanolo_contents::blue "<<hanolo_contents::Color::blue << '\n';

    //与枚举成员进行比较
    if(watermelon==hanolo_contents::Color::green)
    {
        std::cout << "watermelon is green!\n";
    }
    else
    {
        std::cout << "watermelon is not green!\n";
    }
}
