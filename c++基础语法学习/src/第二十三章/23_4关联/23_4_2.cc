


/*
有时，对象可能与同一类型的其他对象有关系。这称为反身关联
反身关联 的一个很好的例子是大学课程与其先决条件（也是大学课程）之间的关系。
*/

#include <string>
#include <string_view>

class Course
{
private:
    std::string m_name{};
    const Course* m_prerequisite{};

public:
    Course(std::string_view name, const Course* prerequisite = nullptr):
        m_name{ name }, m_prerequisite{ prerequisite }
    {
    }

};
// 这可能会导致一连串的关联（一门课程有一个先决条件，它有一个先决条件，等等......
