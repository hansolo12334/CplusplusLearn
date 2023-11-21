#include<iostream>

template<typename T>
struct Triad
{
    T x{};
    T y{};
    T z{};
};
//CTAD类型推导指导 C++17
template <typename T>
Triad(T, T, T) -> Triad<T>;

template<typename T>
void print(const Triad<T> &t)
{
    std::cout << '[' << t.x << ", " << t.y << ", " << t.z << ']';
}


int main()
{
    Triad t1{ 1, 2, 3 };
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

    return 0;
}
