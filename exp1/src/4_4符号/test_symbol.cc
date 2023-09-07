#include<iostream>
#include<vector>
#include<iomanip> //引入std::setprecision() 设置输出小数位数
// 有符号整数
// 无符号整数 不储存负数，能比有符号数储存更多的正数 但避免使用 只能保存非负整数的整数
//但是为了性能 无符号数常用在单片机上

int main()
{
    unsigned short a{65535 };
    std::cout << a << std::endl;
    a = 65534;
    //a = 65536;//编译不通过
    std::cout << a << std::endl;
    a = -1;
    std::cout << a << std::endl;//输出为65535 无符号整数的环绕行为


    std::vector<int> gz{1, 1, 12, 3, 4};
    //std::size_t被定义为无符号整型，通常用于表示对象的大小或长度
    // for (int i = 0; i < gz.size(); i++)
    // {
    //     std::cout << gz.at(i)<<" ";
    // }
    for (std::size_t i = 0; i < gz.size(); i++)
    {
        std::cout << gz.at(i)<<" ";
    }

    //浮点数
    int x{5};
    double y{9.0};
    float z{8.0f};
    std::cout << "x: " << x<<"\n";
    std::cout << "y: " << y<<"\n";
    std::cout << "z: " << z<<"\n";


    //小数输出位数
    std::cout << 3.333333333333333333333f << "\n";
    std::cout << std ::setprecision(17);
    std::cout << 3.333333333333333333333 << "\n";


    //bool型
    bool tt{false};
    std::cout << tt << "\n"; //打印为0
    std::cout<<std::boolalpha;
    std::cout << tt << "\n"; //打印为false
    //想要输入bool false true值 需要使用std::boolalpha
    std::cin >> std::boolalpha;
    bool yy{};
    std::cin >> yy;
    std::cout << "You entered: " << yy << '\n';
    std::cout << (yy == true) << "\n";
    return 0;
}
