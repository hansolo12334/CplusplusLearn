#include<iostream>


class Foo
{
    private:
        int m_x{};
        int m_y{};
    public:
        Foo(int x, int y)
        //构造函数是用于初始化类类型对象的特殊成员函数。
        //必须找到匹配的构造函数才能创建非聚合类类型对象。
        {
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
