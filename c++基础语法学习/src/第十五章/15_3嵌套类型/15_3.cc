#include<iostream>
#include<string>
#include<string_view>

//在类类型的顶部定义任何嵌套类型。


class Fruit
{
//在类的顶部定义 嵌套类型 FruitType
// 这里重命名为Type
public:
    enum Type
    {
        apple,
        banana,
        cherry
    };
// 类类型还可以包含嵌套的 typedef 或类型别名
    using hansolo_string=std::string;

//类甚至可以嵌套 类里面有类
    class inTheClass
    {
        private:
            int m_test{};

        public:
            inTheClass(int test)
                : m_test{test}
                {

                }
            int getTest(){
                return m_test;
            }
    };

private:
    Type m_type{};
    hansolo_string m_fruitName{"apple"};
    int m_percentageEaten{0};

public:
    Fruit(Type type)
        : m_type{type}
        {

        }

    Type getfruitType()
    {
        return m_type;
    }
    int getPercentageEaten(){
        return m_percentageEaten;
    }
    bool isCherry()
    {
        //可以看到 在类内 成员访问 cherry
        // 不需要范围限定符Fruit::
        return m_type == cherry;
    }
    hansolo_string getFruitName()const{
        return m_fruitName;
    }
};



int main()
{
    //而在类外 访问cherry需要使用范围限定符 Fruit::
    // 但是不用使用完整的 Fruit::Type::
    //由于类本身现在充当作用域区域，因此使用作用域枚举器也有些多余。
    //更改为无作用域的枚举意味着我们可以访问枚举器，
    //Fruit::apple 而不是在枚举器有作用域的情况下
    //使用更长的时间 Fruit::Type::apple 。

    Fruit my_fruit{Fruit::cherry};
    // Fruit my_fruit{Fruit::Type::cherry};

    std::cout << my_fruit.getPercentageEaten() << ' ' << my_fruit.isCherry() << '\n';

    std::cout << my_fruit.getFruitName() << '\n';

//类甚至可以嵌套 类里面有类
    Fruit::inTheClass test{1};
    std::cout<<test.getTest()<<'\n';
    return 0;
}
