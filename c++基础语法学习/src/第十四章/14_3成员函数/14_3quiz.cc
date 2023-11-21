#include<iostream>
//Q1  创建一个包含两个整数的名为 struct 的 IntPair 结构。添加一个名为的成员函数 print ，该函数打印两个整数的值。
struct IntPair
{
    int first{};
    int second{};

    void print(){
        std::cout << "Pair(" << first << ', ' << second << ")\n";
    }

    bool isEqual(IntPair p)
    {
        return (p.second == second) && (p.first = first);
    }
};

//Q2 向 IntPair named isEqual 添加一个新的成员函数，该函数返回一个布尔值，指示一个 IntPair 函数是否等于另一个函数。


int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");


	return 0;
}
