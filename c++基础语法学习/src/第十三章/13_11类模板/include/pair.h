#ifndef PAIR_H
#define PAIR_H



namespace hansolo
{
    template<typename T>
    struct pair
    {
        T first{};
        T second{};
    };


    template<typename T>
    constexpr T max(pair<T> p)
    {
        return (p.first < p.second ? p.second : p.first);
    }
} // namespace hansolo

#endif
