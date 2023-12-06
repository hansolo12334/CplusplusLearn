#include <iostream>

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    int x() const { return m_x; }
    int y() const{ return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

int main()
{   //有几种常见的方法可以创建临时类类型对象
    // Case 1: 传值
    IntPair p { 3, 4 };
    print(p);

    // Case 2: 构建临时的 Intpair 传递到函数
    print(IntPair { 5, 6 } );

    // Case 3: 隐式的将  { 7, 8 }转换为一个临时的 Intpair 传递到函数
    print( { 7, 8 } );

    return 0;
}
