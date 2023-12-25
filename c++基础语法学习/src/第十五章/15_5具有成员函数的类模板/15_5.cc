#include<iostream>




template<typename T>
class Pair
{
private:
    T m_first{};
    T m_second{};

public:
    Pair(T first,T second)
        : m_first{first}
        , m_second{second}
    {
    }

    bool isEqual(const Pair<T> &pair);
};


template<typename T>
bool Pair<T>::isEqual(const Pair<T> &pair)
{
    return m_first == pair.m_first && m_second == pair.m_second;
}


int main()
{
    Pair pair1{1, 2};
    std::cout << pair1.isEqual(Pair < int>{2, 1}) << '\n';
    return 0;
}
