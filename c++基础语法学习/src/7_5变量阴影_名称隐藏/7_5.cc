#include<iostream>


int apples{4};
//每个块定义自己的范围区域。那么，当我们在嵌套块中有一个变量与外部块中的变量同名时会发生什么？发生这种情况时，嵌套变量会将外部变量“隐藏”在它们都在范围内的区域中。这称为名称隐藏或阴影。


int main()
{//块外
    int apples{5};

    {//嵌套块
        std::cout << apples << '\n';

        int apples{0};

        //外部的块的apples暂时隐藏了

        apples = 10;//这个对应的是嵌套快内的apples
        std::cout << apples << '\n';

    //嵌套块apples销毁
    }
    std::cout << apples << '\n';//块外apples

    std::cout << ::apples << '\n';//全局的apples
    return 0;
}

//出于我们建议避免隐藏局部变量的原因相同，我们也建议避免隐藏全局变量。
//如果所有全局名称都使用“g_”前缀，则可以轻松避免这种情况
