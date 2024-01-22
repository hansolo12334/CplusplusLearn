#include<iostream>
#include<string>



int main()
{
    //void 指针，也称为泛型指针，是一种特殊类型的指针，可以指向任何数据类型的对象！void 指针的声明方式与普通指针类似

    void *voidPtr{};


    struct Han
    {
        int age;
        std::string name;
    };

    float fValue{1.22};
    Han solo{};


    voidPtr = &solo;
    voidPtr = &fValue;

    // std::cout << *voidPtr << '\n';  出错
    //需要先转换 才能用
    float *floatPtr = static_cast<float *>(voidPtr);
    std::cout << *floatPtr << '\n';

    return 0;
}
