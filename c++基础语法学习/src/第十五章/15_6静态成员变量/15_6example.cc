#include <iostream>
#include <string>
#include<string_view>




class Something
{

private:
    static inline int s_idGenerator{1};
    int m_id{};

public:
    Something()
    {
        m_id = s_idGenerator++;
    }

    int getId()const{
        return m_id;
    }
};

int main()
{
    Something s1{};
    Something s2{};
    Something s3{};


    //对 每个 对象 都指定了唯一的id

    //当类需要使用查找表（例如，用于存储一组预先计算的值的数组）时，静态成员变量也很有用。
    // 通过将查找表设置为静态，所有对象只存在一个副本，而不是为每个实例化的对象创建一个副本。这可以节省大量内存

    std::cout << s1.getId() << '\n';
    std::cout << s2.getId() << '\n';
    std::cout << s3.getId() << '\n';

    return 0;
}
