#include<iostream>
#include<pthread.h>
#include<algorithm>


class SingleInstance
{
public:
    static SingleInstance * GetInstance()
    {
        if(ins==nullptr)
        {
            pthread_mutex_lock(&mutex);

            if(ins==nullptr)
            {
                ins = new SingleInstance();
            }
            pthread_mutex_unlock(&mutex);
        }
        return ins;
    }

    ~SingleInstance()
    {

    }

    static pthread_mutex_t mutex;


private:
    SingleInstance()
    {
        std::cout << "SingleInstance() 懒汉\n";
    }

    SingleInstance(const SingleInstance &other)
    {

    }

    SingleInstance& operator=(const SingleInstance &other)
    {
        return *this;
    }

    static SingleInstance *ins;


};

pthread_mutex_t SingleInstance::mutex;
SingleInstance *SingleInstance::ins = nullptr;


int main()
{
    SingleInstance *ins=SingleInstance::GetInstance();

    std::cout << ins << '\n';
    delete ins;

    return 0;
}
