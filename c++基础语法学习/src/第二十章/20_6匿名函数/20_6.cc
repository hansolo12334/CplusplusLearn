#include<iostream>
#include<array>
#include<string_view>
#include<algorithm>
#include<functional>

//lambdas


bool constainNut(std::string_view str)
{
    return str.find("nut") != std::string_view::npos;
}

int main()
{
    constexpr std::array<std::string_view, 4> arr{"banana", "apple", "walnut", "lemon"};

    auto found{std::find_if(arr.begin(),arr.end(),constainNut)};

    if(found==arr.end())
    {
        std::cout << "nut not found\n";
    }
    else{
        std::cout << "found " << *found << '\n';
    }

    //现在改为匿名函数的写法
    auto found1{std::find_if(arr.begin(), arr.end(), [](std::string_view str){
        return str.find("nut") != std::string_view::npos;
    })};

    if(found1==arr.end())
    {
        std::cout << "nut not found\n";
    }
    else{
        std::cout << "lambda found " << *found1 << '\n';
    }


    std::array<int, 4> arrInt{2, 4, 6, 8};

    //我们也可以用一个 lambda 定义初始化一个 lambda 变量，然后稍后使用它
    auto isEven{[](int i) { return i % 2 == 0; }};

    bool found2{std::all_of(arrInt.begin(), arrInt.end(), isEven)};

    std::cout << "is arrInt all even? " << found2 << '\n';

    //lambda的储存方法
    // 1 使用函数指针储存
    double (*addNumbers1)(double, double){
        [](double a, double b) {
             return a + b;
            }
    };

    addNumbers1(1, 2);
    // 2 使用std::function储存

    //c++17前
    std::function<double(double, double)> addNumbers2{
        [](double x, double y) {
            return x + y;
        }
    };
    //c++ 17
    std::function addNumbers3{
        [](double x, double y) {
             return x + y;
        }
    };
    addNumbers2(2, 3);
    addNumbers3(3, 4);

    // 3 使用auto
    auto addNumbers4{
        [](double x, double y) {
             return x + y;
        }
    };
    addNumbers4(4, 5);
    return 0;
}
