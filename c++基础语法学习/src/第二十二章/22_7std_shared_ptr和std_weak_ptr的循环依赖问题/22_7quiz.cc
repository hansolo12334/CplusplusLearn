#include <iostream>
#include <memory> // for std::shared_ptr


//修复“还原情况”一节中介绍的程序，以便正确解除分配资源。请勿更改 中的 main() 代码。


class Resource
{
public:
	// std::shared_ptr<Resource> m_ptr {}; // initially created empty
    std::weak_ptr<Resource> m_ptr{};

    Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1 { std::make_shared<Resource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

	return 0;
}
