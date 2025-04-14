#include<iostream>
#include<algorithm>



class SingleInstance
{
public:
    static SingleInstance *GetInstance()
    {
        static SingleInstance ins;
        return &ins;
    }
    ~SingleInstance() {}

private:
    SingleInstance()
    {
        std::cout << "SingleInstance() 饿汉 \n";
    }

    SingleInstance(const SingleInstance &other)
    {

    }

    SingleInstance &operator=(const SingleInstance &other)
    {
        return *this;
    }
};


int main()
{
    SingleInstance *ins = SingleInstance::GetInstance();



    std::cout << ins << '\n';
    return 0;
}
