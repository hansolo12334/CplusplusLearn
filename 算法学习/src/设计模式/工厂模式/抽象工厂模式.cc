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



class Factory
{
public:
    virtual Product *CreateProduct() = 0;//纯虚函数
};


class ProductA: public Product
{
public:
    ProductA()
    {

    }

    void show() override
    {
        std::cout << "product A create\n";
    }
};


class ProductB: public Product
{
public:
    ProductB()
    {

    }

    void show() override
    {
        std::cout << "product B create\n";
    }
};


class FactorA: public Factory
{
public:
    Product *CreateProduct() override
    {
        Product *product_ = nullptr;
        product_ = new ProductA();

        return product_;
    }
};


class FactorB: public Factory
{
public:
    Product *CreateProduct() override
    {
        Product *product_ = nullptr;
        product_ = new ProductB();

        return product_;
    }
};


int main()
{
    Product *product_ = nullptr;

    auto MyFactorA = new FactorA();

    product_ = MyFactorA->CreateProduct();

    product_->show();

    delete product_;

    auto MyFactorB = new FactorB();

    product_ = MyFactorB->CreateProduct();

    product_->show();

    delete product_;

    return 0;
}
