#include<iostream>
#include<algorithm>
#include<string>



class Product
{
public:
    Product()
    {

    }

    virtual void show() = 0; //纯虚函数
};


class productA : public Product
{
public:
    productA()
    {

    }
    ~productA()
    {

    }


    void show() override
    {
        std::cout << "product A create!\n";
    }

};


class productB : public Product
{
public:
    productB()
    {

    }
    ~productB()
    {

    }


    void show() override
    {
        std::cout << "product B create!\n";
    }

};


class simpleFactory
{
public:
    simpleFactory()
    {

    }

    Product *product(const std::string str)
    {
        if(str=="productA")
        {
            return new productA();
        }
        if(str=="productB")
        {
            return new productB();
        }
        return nullptr;
    }
};



int main()
{
    simpleFactory obj;
    Product *pro;

    pro = obj.product("productA");

    pro->show();

    delete pro;


    pro = obj.product("productB");
    pro->show();

    delete pro;

    return 0;
}
