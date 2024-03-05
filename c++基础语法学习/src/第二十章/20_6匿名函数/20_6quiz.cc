#include<iostream>
#include<array>
#include<string_view>
#include<algorithm>
#include<functional>


struct Student{
    std::string_view name{};
    int points{};

    Student(std::string_view n,int p)
    : name(n),
      points(p)
      {}
};


int main()
{
    std::array<Student, 8> arr{
    { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 }, // Dan has the most points (8).
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    auto best_student =
        std::max_element(arr.begin(), arr.end(), [](const Student p1,const  Student p2) { return p1.points < p2.points;
    }
    );
    std::cout << best_student->name << " is the best student\n";
}
