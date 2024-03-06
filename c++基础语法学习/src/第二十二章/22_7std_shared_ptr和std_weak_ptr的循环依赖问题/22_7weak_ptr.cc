#include<iostream>
#include<string>
#include<utility>// std::move()

#include<memory> //std::unique_ptr


//std::weak_ptr 旨在解决上述“周期性所有权”问题。
// std::weak_ptr 是一个观察者——它可以观察和访问与 std::shared_ptr（或其他 std::weak_ptrs）相同的对象，
// 但它不被视为所有者。请记住，当 std::shared 指针超出范围时，
// 它只考虑其他 std::shared_ptr 是否共同拥有该对象。std::weak_ptr 不算数！

class Person
{
	std::string m_name;
	// std::shared_ptr<Person> m_partner; //将 shared_ptr换成weak_ptr
    std::weak_ptr<Person> m_partner;

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

    const std::shared_ptr<Person> getPartner() const{
        return m_partner.lock(); //使用lock()将weak_ptr转为shared_ptr
    }
    const std::string &getName() const{
        return m_name;
    }
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") }; // create a Person named "Lucy"
	auto ricky { std::make_shared<Person>("Ricky") }; // create a Person named "Ricky"

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

    std::cout << "Now " << lucy->getName() << " 's friend is " << lucy->getPartner()->getName() << '\n';
    return 0;

    /*
        将 m_partner改为 std::weak_ptr后 输出为

        Lucy created
        Ricky created
        Lucy is now partnered with Ricky
        Ricky destroyed
        Lucy destroyed

    */
}
