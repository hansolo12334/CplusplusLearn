#include<array>
#include<iostream>
#include<algorithm>
#include<string>
#include<string_view>
#include<vector>



//匹配字符串
bool findContants(std::string_view str)
{
                                        //不等于末尾
    return (str.find("han") != std::string_view::npos);
}

//排序规则

bool smaller(int a,int b)
{
    return a < b;
}

//某种规则
void timeTwoToAll(int &i)
{
    i = 2 * i;
}

int main()
{
    // std::find() 按值查找元素
    std::array<int, 5> a{1, 2, 3, 2, 5};

    auto found{std::find(a.begin(), a.end(), 2)};

    if(found!=a.end())
    {
        std::cout << *found << '\n';
    }


    // std::find_if 查找某个条件匹配的元素 可以设定某种规则 如模糊匹配
    std::array<std::string, 3> a_s{"hansolo", "hans", "sss"};

    auto foundS{std::find_if(a_s.begin(), a_s.end(), findContants)};

    if(foundS!=a_s.end())
    {
        std::cout << *foundS << '\n';
    }


    // std::count std::count_if  来统计出现的次数
    auto foundCount{std::count_if(a_s.begin(), a_s.end(), findContants)};
    auto foundCount1{std::count(a_s.begin(), a_s.end(), "hansolo")};

    std::cout << "find hansolo time: " << findContants << '\n';
    std::cout << "find han time :" << foundCount << '\n';


    // std::sort 自定义排序
    std::array sortVec{1, 3, 4, 3, 2};

    std::sort(sortVec.begin(), sortVec.end(), smaller);
    for(auto it : sortVec)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';


    std::sort(sortVec.begin(), sortVec.end(), std::greater<int>{});
    for(auto it : sortVec)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';



    //std::for_each 来对容器的所有元素执行某些操作
    std::vector<int> vec{1, 2, 3, 4};
    std::for_each(vec.begin(), vec.end(), timeTwoToAll);

    for(auto v:vec)
    {
        std::cout << v << ' ';
    }
    std::cout << '\n';

    return 0;
}
