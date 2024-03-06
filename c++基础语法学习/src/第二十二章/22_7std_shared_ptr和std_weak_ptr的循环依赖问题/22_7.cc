#include<iostream>
#include<string>
#include<utility>// std::move()

#include<memory> //std::unique_ptr



class Person
{
	std::string m_name;
	std::shared_ptr<Person> m_partner; // initially created empty

public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';

		return true;
	}
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") }; // create a Person named "Lucy"
	auto ricky { std::make_shared<Person>("Ricky") }; // create a Person named "Ricky"

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

	return 0;

    /*
    最终输出为:
        Lucy created
        Ricky created
        Lucy is now partnered with Ricky

    并没有销毁 Lucy和Ricky 这是为什么?

    循环引用
    循环引用（也称为循环引用或循环引用）是一系列引用，其中每个对象引用下一个对象，最后一个对象引用回第一个对象，从而导致引用循环。引用不需要是实际的 C++ 引用 -- 它们可以是指针、唯一 ID 或任何其他标识特定对象的方法

    */
}
