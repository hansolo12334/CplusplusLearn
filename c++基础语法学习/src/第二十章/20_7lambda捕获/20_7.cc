#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>



int main()
{
    std::array<std::string_view,5> arr{"apple","walnuts","banana"};

    std::string search{"nut"};

    //                                                 捕获
    auto find = std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
        // search = "bb";// 会报错 search为const类型 无法修改
        return str.find(search) != std::string_view::npos;
    });

    //为了允许修改捕获的变量，我们可以将 lambda 标记为 mutable ：
    auto find1 = std::find_if(arr.begin(), arr.end(), [search](std::string_view str) mutable {
        search = "na";
        return str.find(search) != std::string_view::npos;
    });
    std::cout << "search " << search << '\n';// 输出不是na 而是nut
    //由于捕获的变量是 lambda 对象的成员，因此它们的值会在对 lambda 的多次调用中持久化

    //通过引用捕获
    auto find2 = std::find_if(arr.begin(), arr.end(), [&search](std::string_view str) mutable {
        search = "na";
        return str.find(search) != std::string_view::npos;
    });
    std::cout << "search& " << search << '\n';




    //捕获多个变量 默认捕获
    // 使用 = (按值捕获)  或&(按引用捕获)
    auto find3 = std::find_if(arr.begin(), arr.end(), [&](std::string_view str) mutable {
        std::cout << arr.at(1) << '\n';
        search = "ap";
        return str.find(search) != std::string_view::npos;
    });
    std::cout << "search  & " << search << '\n';

    // 可以混合 使用
    /*
    [=,&search](){}
    [&,search](){}
    [search,&arr,find1](){}
    */









    if(find!=arr.end())
    {
        std::cout<<"found " << *find << '\n';
    }


    if(find1!=arr.end())
    {
        std::cout<<"found1 " << *find1 << '\n';
    }

    return 0;
}
