#include"Date.hh"
#include<iostream>

Date::Date(int year,int month,int day)
    : m_year{year}
    , m_month{month}
    , m_day{day}
{
    std::cout << "构造函数!\n";
}


Date::~Date()
{

}


void Date::print()const
{
    std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
}
