#include<iostream>
#include<string>
#include<string_view>



class Ball
{
    private :
        std::string m_color{"black"};
        double m_radius{10.0};

    public :
        //对应 Ball(radius)
        Ball(double radius)
            : Ball("black",radius)
            {}
        //对应 Ball(color) Ball() Ball(color,radius)
        Ball(std::string_view color="black",double radius=10.0)
            : m_color{color}
            , m_radius{radius}
            {
                std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
            }

};


int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
