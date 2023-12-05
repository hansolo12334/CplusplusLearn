#include<iostream>


//为了让构造函数初始化成员，我们使用成员初始值设定项列表（通常称为“成员初始化列表”）来实现。
// 不要将其与名称相似的“初始值设定项列表”混淆，后者用于使用值列表初始化聚合





//成员初始值设定项列表中的成员变量应按照在类中定义的顺序列出
class Foo
{
    private:
        int m_x{};
        int m_y{};
    public:

        Foo(int x, int y)
            : m_x{x}
            , m_y{y}
        {
            // m_x = x;
            // m_y = y;
            // 错误! 首选使用成员初始值设定项列表来初始化成员，而不是在构造函数主体中赋值

            std::cout << "Foo(" << x << ", " << y << ") 构造\n";
        }

        void print() const{
            std::cout<<"Foo(" << m_x << ", " << m_y << ")\n";
        }

};



int main()
{
    Foo foo{6, 7};
    foo.print();
    return 0;
}
