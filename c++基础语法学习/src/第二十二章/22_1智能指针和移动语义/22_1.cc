#include<iostream>


//如果我们不是让我们的复制构造函数和赋值运算符复制指针（“复制语义”），
// 而是将指针的所有权从源对象转移/移动到目标对象，会怎样？
// 这是移动语义背后的核心思想。
// 移动语义意味着类将转移对象的所有权，而不是制作副本。

template<typename T>
class Auto_ptr2
{
    T *m_ptr;

public:
    Auto_ptr2(T *ptr=nullptr)
        : m_ptr(ptr)
    {}

    ~Auto_ptr2()
    {
        delete m_ptr;
    }

    //实现 移动语义
    Auto_ptr2(Auto_ptr2 &a)
    {
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }

    Auto_ptr2 &operator=(Auto_ptr2 &a)
    {
        if(&a==this)
        {
            return *this;
        }
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }

    T& operator*() const{
        return *m_ptr;
    }
    T* operator->()const{
        return m_ptr;
    }
    bool isNull() const{
        return m_ptr == nullptr;
    }
};


class Resource
{
public:
    Resource(){
        std::cout << "Resource 建立\n";
    }
    ~Resource(){
        std::cout << "Resource 销毁\n";
    }
};

int main()
{
    Auto_ptr2<Resource> res1 = new Resource();
    Auto_ptr2<Resource> res2;

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    res2 = res1;//res1被释放!

    std::cout << "转移-----------\n";
    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
}
