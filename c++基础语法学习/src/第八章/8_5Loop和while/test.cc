#include<iostream>


//编写一个程序，打印出字母 a 到 z 及其 ASCII 代码。使用 char . 类型的循环变量。
void test1()
{
    char charactor{'a'};

    while (charactor<='z')
    {
        std::cout << charactor << ' ' << static_cast<int>(charactor) << '\n';
        charactor++;
    }

}



/*
反转嵌套循环示例，以便打印以下内容：
5 4 3 2 1
4 3 2 1
3 2 1
2 1
1
*/
void test2()
{
    int outer{5};
    while (outer>=0)
    {
        int inner{1};
        while (inner<=outer)
        {
            std::cout << inner << ' ';
            ++inner;
        }
        std::cout << '\n';
        --outer;
    }
}



/*
现在让数字像这样打印：

        1
      2 1
    3 2 1
  4 3 2 1
5 4 3 2 1
*/
void test3()
{
    int outer{1};
    while (outer<=5)
    {
        int inner{5};
        while (inner >0)
        {
            if(inner > outer)
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << inner << ' ';
            }

            --inner;
        }
        std::cout << '\n';
        ++outer;
    }

}


int main()
{
    test3();
    return 0;
}
