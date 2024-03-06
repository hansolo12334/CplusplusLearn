#include<iostream>
#include<string>
#include<utility>// std::move()


// std::move

template<typename T>
void swapMove(T &a,T &b)
{
    T temp{std::move(a)};
    a = std::move(b);
    // b = std::move(temp);
}

int main()
{
    std::string x{"abc"};
    std::string y{"de"};

    std::cout << "x " << x << '\n';
    std::cout << "y " << y << '\n';

    swapMove(x, y);

    std::cout << "x " << x << '\n';
    std::cout << "y " << y << '\n';// b的值被a窃取，发现b里面空了

    //std::move 在对元素数组进行排序时也很有用。许多排序算法（如选择排序和冒泡排序）通过交换元素对来工作。在前面，我们不得不求助于复制语义来进行交换。现在我们可以使用移动语义，这样效率更高

    return 0;
}
