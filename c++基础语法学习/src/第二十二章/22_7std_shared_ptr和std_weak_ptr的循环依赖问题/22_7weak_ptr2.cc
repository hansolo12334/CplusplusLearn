#include<iostream>
#include<string>
#include<utility>// std::move()

#include<memory> //std::unique_ptr


//考虑以下情况：一个普通的“哑”指针保存了某个对象的地址，然后该对象被销毁。这样的指针是悬空的，取消引用指针将导致未定义的行为。
// 不幸的是，我们无法确定持有非空地址的指针是否悬空。
// 这是愚蠢的指针很危险的很大一部分原因。
// 由于 std::weak_ptr 不会使拥有的资源保持活动状态，因此 std::weak_ptr 同样可能指向已被 std::shared_ptr 解除分配的资源。然而，std::weak_ptr 有一个巧妙的技巧——因为它可以访问一个对象的引用计数，所以它可以确定它是否指向一个有效的对象！
// 如果引用计数不为零，则资源仍然有效。如果引用计数为零，则资源已被销毁。
//测试 std::weak_ptr 是否有效的最简单方法是使用 expired() 成员函数，如果 std::weak_ptr 指向无效对象， 该函数则返回false或 true


class Resource
{
public:
	Resource() { std::cerr << "Resource acquired\n"; }
	~Resource() { std::cerr << "Resource destroyed\n"; }
};

// Returns a std::weak_ptr to an invalid object
std::weak_ptr<Resource> getWeakPtr()
{
	auto ptr{ std::make_shared<Resource>() };
	return std::weak_ptr<Resource>{ ptr };
} // ptr goes out of scope, Resource destroyed

// Returns a dumb pointer to an invalid object
Resource* getDumbPtr()
{
	auto ptr{ std::make_unique<Resource>() };
	return ptr.get();
} // ptr goes out of scope, Resource destroyed

int main()
{
	auto dumb{ getDumbPtr() };
	std::cout << "Our dumb ptr is: " << ((dumb == nullptr) ? "nullptr\n" : "non-null\n");

	auto weak{ getWeakPtr() };
	std::cout << "Our weak ptr is: " << ((weak.expired()) ? "expired\n" : "valid\n");

	return 0;
}
