#include <functional> // std::reference_wrapper
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
//更新 Department / Teacher 示例，以便 Department 可以处理多个教师。应执行以下代码：
// ...


class Teacher
{
private:
    std::string m_name{};

public:
    Teacher(std::string_view name) : m_name{name}
    {
    }

    const std::string &getName() const
    {
        return m_name;
    }
};

class Department
{
private:
    //   const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
    //   Department(const Teacher& teacher)
    //       : m_teacher{ teacher }
    //   {
    //   }

    void add(const Teacher &t)
    {
        m_teachers.emplace_back(t);
    }
    friend std::ostream &operator<<(std::ostream &out, const Department &d)
    {
        out << "Department ";
        for (const auto &ts : d.m_teachers)
        {
            out << ts.get().getName() << ' ';
        }
        out << '\n';
        return out;
    }
};


int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{"Bob"};
    Teacher t2{"Frank"};
    Teacher t3{"Beth"};

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}
