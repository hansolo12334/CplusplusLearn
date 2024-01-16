#include<iostream>
#include<thread>



// 确保线程是能够 join的
class thread_guard
{
private:
    std::thread &m_t;

public:
    explicit thread_guard(std::thread &t)
        : m_t{t}
        {
        }

    ~thread_guard()
    {
        if(m_t.joinable())
        {
            m_t.join();
        }
    }


    //拷贝构造函数和 拷贝赋值操作 标记为 delete是为了不让编译器自动生成
    // 自动对 class对象进行拷贝或赋值时危险的
    thread_guard(thread_guard const &) = delete;
    thread_guard &operator=(thread_guard const &) = delete;
};



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
        for (int j = 0; j < 5;j++)
        {
            std::cout << m_i << '\n';
        }
    }
};


void f()
{
    int local_state = 0;
    func my_func{local_state};
    std::thread t1(my_func);
    thread_guard my_guard(t1);

    // 拷贝和赋值的操作 标记为 delete 效果如下：

    // 复制
    // thread_guard my_guard1 = my_guard1;//这里就会报错 （它是已删除的函数）

    // 复制
    // thread_guard my_guard_copy(t1);
    // my_guard_copy = my_guard;//无法引用 函数 "thread_guard::operator=(const thread_guard &)" (已声明 所在行数:30) -- 它是已删除的函数C


    for (int i = 0; i < 5; i++)
    {
        std::cout << "do things in f() thread\n";
    }

    //在 } 末尾 my_guard被销毁 此时才将 my_func 引入原始线程 因此
    // 打印 do things in f() thread 在 my_func之前
}

int main()
{
    f();
    for (int i = 0; i < 5; i++)
    {
        std::cout << "do things in main thread\n";
    }

    return 0;
}
