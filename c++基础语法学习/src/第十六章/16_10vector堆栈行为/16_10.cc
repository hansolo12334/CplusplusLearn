#include <iostream>
#include <vector>
#include<string_view>

//避免使用 std::vector<bool>

class Hansolo
{
private:
    int m_age{};
    int m_id{};

public:
    Hansolo(int age,int id)
        : m_age{age}
        , m_id{id}
    {}
};


int main()
{
    std::vector<Hansolo> hansolos;

    Hansolo h1{22, 1};

    hansolos.push_back(h1);

    hansolos.push_back({23, 2});

    hansolos.emplace_back(23, 3);// emplace_back不需要创建临时对象 {23,2} 节省不必要的复制操作

    return 0;
}
