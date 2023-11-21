#include<iostream>


//属性和动作的分离 在编程中，我们用变量表示属性，用函数表示动作

//属于类类型的函数称为成员函数

//成员变量和函数可以按任意顺序定义
class Foo
{
    public:
        auto add(){  //按任意顺序定义
            return x + y;
        }
        int x{};
        int y{};
        //成员函数可以被重载
        auto add(int x,int y){
            return x + y;
        }
};
//struct结构体可以像class一样使用成员函数 但是建议别用 使其保持聚合



int main()
{
    Foo f{};
    f.x = 1;
    f.y = 2;
    std::cout << f.add() << '\n';

    std::cout << f.add(2, 3) << '\n';//成员函数可以被重载

    return 0;
}
