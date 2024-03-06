#include<iostream>
#include<string>
#include<utility>// std::move()

#include<memory> //std::unique_ptr


class Resource
{
public:
	std::shared_ptr<Resource> m_ptr {}; // initially created empty

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
	auto ptr1 { std::make_shared<Resource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it
    //程序输出为：
    // Resource acquired
    // 没有输出 Resource destroyed 为什么?
    // 当 ptr1 超出范围时，资源不会解除分配，
    // 因为资源的m_ptr正在共享资源。
    // 此时，释放资源的唯一方法是将m_ptr设置为其他内容（因此不再共享资源）。
    // 但是我们无法访问m_ptr因为 ptr1 超出了范围，所以我们不再有办法做到这一点。资源已成为内存泄漏
	return 0;
}
