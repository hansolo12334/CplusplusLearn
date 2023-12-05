#include<iostream>



//具有默认参数的构造函数
class Foo
{
    private :
        int m_x{};
        int m_y{};
    public :
        Foo() = default; //重载构造函数
            // {
            //     std::cout << "构造！\n";
            // }
        Foo(int x,int y)//默认参数
            : m_x{x}
            , m_y{y}
            {
                std::cout << "Foo(" << x << ", " << y << ")\n";
            }
        Foo(int x)
            : m_x{x}
            {
                std::cout << "Foo(" << x << ", " << ")\n";
            }

};



class Goo
{
    private :
        int m_x{};
        int m_y{};
    //隐式默认构造函数
    //如果没有用户声明的构造函数 则编译器将生成一个公共默认构造函数
    /*
    public :
        Goo()
        {

        }*/
    public :
         Goo(int x=0,int y=1)//默认参数
            : m_x{x}
            , m_y{y}
            {
                std::cout << "Foo(" << x << ", " << y << ")\n";
            }
};


int main()
{
    Foo foo1{1};
   // Foo foo2{3, 4};

    return 0;
}
