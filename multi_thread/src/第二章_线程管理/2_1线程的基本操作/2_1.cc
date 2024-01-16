#include<iostream>
#include<thread>


class func
{
private:
    int &m_i;

public:
    func(int i)
     : m_i{i}
     {

     }

    // 仿函数 可以让对象的行为看起来像一个函数
    //比如这里的 类 func 调用func（） 会运行以下函数
    void operator() () //第二个() 中可以有 无 参数
    {
        for (int j = 0; j < 10;j++)
        {
            std::cout << m_i << '\n';
        }
    }
};

/*
    join()   汇入
    detach() 分离
*/
int main()
{
    int i = 1;
    func my_func{i};
    std::thread t1{my_func};

    // t1.detach(); //不等待线程结束 继续执行主线程
    t1.join(); //等待线程结束 继续执行主线程 以确保子线程在主线程完成之前结束
    //一旦使用过一次join() 就无法再次汇入了 使用jionable 返回 false
    std::cout <<"t1.joinable() : "<< t1.joinable() << '\n';



    return 0;
}
