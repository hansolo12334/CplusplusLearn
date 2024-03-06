#include<iostream>
#include<string>
#include<utility>// std::move()

#include<memory> //std::unique_ptr


//std::shared_ptr 旨在解决需要多个智能指针共同拥有资源的情况

//std::shared_ptr 专为需要多个智能指针共同管理同一资源的情况而设计。
// 当管理资源的最后一个std::shared_ptr被销毁时，资源将被解除分配


class Resource
{
public:
    Resource(){
        std::cout << "构造\n";
    }
    ~Resource(){
        std::cout << "销毁\n";
    }
};


int main()
{

    //使用 std::make_shared 比 std::shared_ptr更简单 更安全
    // 而且make_shared更高性能

    auto ptr1{std::make_shared<Resource>()};
    {
        auto ptr2{ptr1};

        std::cout << "ptr2 在此处销毁\n";
    }

    std::cout << "ptr1 在此处销毁\n";

    std::unique_ptr<Resource> res{new Resource()};

    std::shared_ptr<Resource> res1{std::move(res)};

    return 0;
}
