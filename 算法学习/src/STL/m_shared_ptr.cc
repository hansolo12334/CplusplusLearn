#include<memory>
#include<iostream>
#include<string.h>
#include<mutex>



namespace hansolo
{

template<typename T>
class shared_ptr
{
private:
    int *m_ref_cnt;
    T *m_data;
    std::mutex *m_mtx;

public:
    shared_ptr(T *data=nullptr)
     : m_mtx(new std::mutex)
     , m_ref_cnt{new int(1)}
     , m_data{data}
    {
        std::cout << "引用计数加一\n";
    }

    shared_ptr(const shared_ptr<T> &sp)
        : m_mtx{sp.m_mtx}
        , m_ref_cnt{sp.m_ref_cnt}
        , m_data{sp.m_data}
    {
        add_ref_count();
    }

    shared_ptr(shared_ptr<T> &&sp)
        : m_data{sp.m_data}
        , m_ref_cnt{sp.m_ref_cnt}
        , m_mtx{sp.m_mtx}
    {
        sp.m_ref_cnt = nullptr;
        sp.m_data = nullptr;
        sp.m_mtx = nullptr;
    }

    ~shared_ptr()
    {
        release();
    }


    //拷贝赋值运算符重载
    shared_ptr<T> &operator=(const shared_ptr<T> &sp)
    {
        if(m_data!=sp.m_data){
            release();
            m_mtx = sp.m_mtx;
            m_ref_cnt = sp.m_ref_cnt;
            m_data = sp.m_data;
            add_ref_count();
        }
        return *this;
    }

    shared_ptr<T> &operator=(shared_ptr<T> &&sp)
    {
        if(m_data!=sp.m_data){
            // delete m_data;

            m_data = sp.m_data;

            sp.m_data = nullptr;
            sp.m_ref_cnt = nullptr;
            sp.m_mtx = nullptr;
        }
        return *this;
    }

    //解引用运算符重载
    T &operator*(){
        return *m_data;
    }
    //指针运算符重载
    T *operator->()
    {
        return m_data;
    }

    int use_count()const{
        if(m_ref_cnt==nullptr){
            return 0;
        }
        return *m_ref_cnt;
    }
    //获取原始指针对象
    T *get(){
        return m_data;
    }

private:
    void add_ref_count()
    {
        m_mtx->lock();
        ++(*m_ref_cnt);
        m_mtx->unlock();
        std::cout << "引用计数加一\n";
    }

    void release()
    {
        if(m_data==nullptr && m_ref_cnt==nullptr)
        {
            return;
        }

        bool flag = false;
        m_mtx->lock();
        (*m_ref_cnt)--;
        std::cout << "引用计数减一\n";
        if((*m_ref_cnt)==0){
            delete m_ref_cnt;
            delete m_data;
            m_ref_cnt = nullptr;
            m_data = nullptr;
            flag = true;
        }
        m_mtx->unlock();
        if(flag){
            delete m_mtx;
            m_mtx = nullptr;
        }
    }
};



}; // namespace hansolo

class Test
{
private:
    int m_data{};

public:
    Test(int data)
     :m_data{data}
    {

    }
     ~Test()
    {

    }
    int getData() const{
        return m_data;
    }
};

int main()
{

    // hansolo::shared_ptr<Test> test;
    int *t2 = new int[2];
    int *t3 = new int[3];
    // {
    //     Test *tt = new Test{33};
    //     hansolo::shared_ptr<Test> sptr{tt};
    //     test = sptr;
    // }

    hansolo::shared_ptr<int> ptr2{t2};

    // std::cout << test.get()->getData() << '\n';


    hansolo::shared_ptr<int> ptr3_move{t3};
    ptr3_move=std::move(ptr2);

    hansolo::shared_ptr<int> ptr4_move{std::move(ptr3_move)};
}
