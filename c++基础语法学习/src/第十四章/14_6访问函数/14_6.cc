#include<iostream>

// access functions 访问函数
// 有时候我想检索和更改私有变量 怎么办


//访问函数: 访问器 getter 返回私有成员变量值的函数
//         赋值器 setter 设置私有成员变量值的函数
//访问函数和赋值函数的命名 最好以 get /set 为开头 调用起来清晰方便

class Date
{
    private :
        int m_year{2023};
        int m_month{11};
        int m_day{22};

    public :
        void print() const {
            std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
        }
        int getYear() const{  //getter
            return m_year;
        }
        int getMonth() const{ //getter
            return m_month;
        }
        int getDay() const{  //getter
            return m_day;
        }
        void setYear(int year) { //setter
            m_year = year;
        }

        void setMonth(int month){ //setter
            m_month=month;
        }
        void setDay(int day){ //setter
            m_day = day;
        }
};


int main()
{
    Date today;
    today.print();
    //想要获取 改变私有的日期 怎么办?

    //获取
    std::cout << today.getYear() << '\n';

    //修改
    today.setYear(2024);
    today.setMonth(12);
    today.print();


    return 0;
}
