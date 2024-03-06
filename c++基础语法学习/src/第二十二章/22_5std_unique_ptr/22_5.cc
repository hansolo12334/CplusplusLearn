#include<iostream>
#include<string>
#include<utility>// std::move()

#include<memory> //std::unique_ptr


//std::unique_ptr 应该完全拥有它所管理的对象，而不是与其他类共享该所有权

//避免滥用：
/* 不要让多个类管理同一资源
    Resource* res{ new Resource() };
    std::unique_ptr<Resource> res1{ res };
    std::unique_ptr<Resource> res2{ res };

   不要手动从 std::unique_ptr 下面删除资源
    Resource* res{ new Resource() };
    std::unique_ptr<Resource> res1{ res };
    delete res;

    ⚠ std::make_unique()  可防止上述两种情况无意中发生。

*/
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


void useResource(const Resource *res)
{
    if(res)
    {
        std::cout <<"use resource " << res << '\n';
    }
}
void passOwnership(std::unique_ptr<Resource> res)
{
    if(res){
        std::cout<<"res " << res << '\n';
    }

//运行到 此处 ptr销毁
}

int main()
{
    std::unique_ptr<Resource> res1{new Resource()};

    std::unique_ptr<Resource> res2;

    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    res2 = std::move(res1);

    std::cout << "------------------\n";


    std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
    std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

    // 使用 std::make_unique更好
    //使用 std::make_unique（） 而不是创建 std::unique_ptr 并使用新的自己。
    auto ptr{std::make_unique<Resource>()};

    useResource(ptr.get()); // get() 来获取Resource的指针

    passOwnership(std::move(ptr));

    std::cout << "end program\n";




    return 0;
}
