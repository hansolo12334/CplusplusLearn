#include<iostream>
#include<string>
#include<string_view>

class Ball
{
    private :
        const double m_r{};
        std::string m_color{};

    public :
        Ball(std::string_view color,double r)
            : m_r{r}
            , m_color{color}
            {

            }

        void print() const{
            std::cout << "Ball (" << m_color << ", " << m_r << ")\n";
        }
};

int main()
{
	Ball blue{ "blue", 10.0 };
	blue.print();

	Ball red{ "red", 12.0 };
	red.print();

	return 0;
}
