#include<iostream>



template<typename T>
class Auto_ptr3
{
    T *m_ptr{};

public:
    Auto_ptr3(T *ptr=nullptr)
        : m_ptr{ptr}
    {}

    ~Auto_ptr3()
    {
        delete m_ptr;
    }

    //实现 移动语义
    // 拷贝构造函数 将a.m_ptr深拷贝到m_ptr
    Auto_ptr3(const Auto_ptr3 &a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    //复制语义
    Auto_ptr3 &operator=(const Auto_ptr3 &a)
    {
        if(&a==this)
        {
            return *this;
        }
        delete m_ptr;

        m_ptr = new T;
        *m_ptr = *a.m_ptr;
        return *this;
    }

    //移动语义 将 a.m_ptr 的所有权转移给 m_ptr
    Auto_ptr3 &operator=(Auto_ptr3 &&a)noexcept
    {
        if(&a==this){
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
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};


Auto_ptr3<Resource> generateResource()
{
    Auto_ptr3<Resource> res{new Resource};
    return res;
}

// 不要使用std::swap实现移动语义



int main()
{
    Auto_ptr3<Resource> mainRes;
    mainRes = generateResource();
    return 0;
}
