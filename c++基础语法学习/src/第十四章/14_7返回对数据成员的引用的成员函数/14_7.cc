#include<iostream>
#include<string>

class Employee
{
    private :
        std::string m_name{};
    public :
        void setName(std::string_view name){
            m_name = name;
        }
        //按值返回数据成员的成本可能很高
        // std::string getName() const{
        //     return m_name;
        // }


        //通过左值引用返回数据成员
        // 成员函数还可以通过 （const） 左值引用返回数据成员
        const std::string &getName() const{
            return m_name;//按左值引用返回
        }
        //返回引用的成员函数应返回与要返回的数据成员类型相同的引用，以避免不必要的转换
        const auto &getName_new() const{ //可以使用auto推导但是更推荐显式的返回类型
            return m_name;//按左值引用返回
        }
        auto *getName_test(){
            return &m_name;
        }
};


int main()
{
    Employee hank{};
    hank.setName("Hank");
    std::cout << hank.getName() << '\n';
    std::cout << hank.getName_new() << '\n';

    auto *aa{hank.getName_test()};

    *aa = "rename!";
    std::cout << aa << '\n';

    std::cout << hank.getName() << '\n';
    std::cout << hank.getName_new() << '\n';
    return 0;
}
