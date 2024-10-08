#include<iostream>
#include<string>
#include<utility>// std::move()

#include<memory> //std::unique_ptr

//在适当的情况下，将以下程序从使用普通指针转换为使用 std::unique_ptr:



class Fraction
{
private:
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.m_numerator << '/' << f1.m_denominator;
		return out;
	}
};

void printFraction(const Fraction* ptr)
{
	if (ptr)
		std::cout << *ptr << '\n';
	else
		std::cout << "No fraction\n";
}

// int main()
// {
// 	auto* ptr{ new Fraction{ 3, 5 } };


//     printFraction(ptr);

// 	delete ptr;

// 	return 0;
// }

int main()
{
	// auto* ptr{ new Fraction{ 3, 5 } };
    auto ptr{std::make_unique<Fraction>(3, 5)};

    printFraction(ptr.get());

	// delete ptr;

	return 0;
}
