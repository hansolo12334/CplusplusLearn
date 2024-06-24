#include<iostream>
#include<string>
#include<string_view>

#include<gtest/gtest.h>

using namespace std;

class Student
{
private:
  int m_id{};
  string m_name{};
  int m_age{};
  int m_score{};

public:
  Student(int id,string name)
   : m_id{id}
   , m_name{name}
   {

   }

   void SetAge(int age){
     m_age = age;
   }
   int getAge()const{
     return m_age;
   }
   void  SetScore(int s){
     m_score = s;
   }
   int GetScore()const{
     return m_score;
   }
   
};



class StudentTest: public testing::Test
{
protected:
  void SetUp()override{
    student = new Student{111,"hansolo"};
  }

  void TearDown() override{
    delete student;
  } 

  Student *student{nullptr};
};

//说明：该宏定义用来对 TestFixtureName 类进行多样测试。
TEST_F(StudentTest,SET_SCORE_TEST){
  student->SetScore(1000);
  int score = student->GetScore();
  ASSERT_EQ(score, 100) << "测试\n";
  ASSERT_EQ(score, 10000);
}

TEST_F(StudentTest,SET_AGE_TEST){
   student->SetAge(22);
  int age = student->getAge();
  ASSERT_EQ(age,22);
}



struct TestData{
  int a;
  int b;
  int re;
  char type;
  string str;
};

class CalculateTest: public  testing::TestWithParam<TestData>
{
protected:
  void checkdata(){
    int a = GetParam().a;
    int b = GetParam().b;
    int re = GetParam().re;
    string str = GetParam().str;
    switch (GetParam().type)
    {
    case '+':
      EXPECT_EQ(a + b, re);
      break;
    case '-':
      EXPECT_EQ(a - b, re);
      break;
    case '*':
      EXPECT_EQ(a * b, re);
      break;
    case '/':
      EXPECT_EQ(a / b, re);
      break;
    default:
      break;
    }
  }
};

// 说明：该宏定义用来参数化测试。
TEST_P(CalculateTest,Test)
{
  checkdata();
}

INSTANTIATE_TEST_SUITE_P(TestMyClassParams,
                          CalculateTest,
                          testing::Values(
                            TestData{100,200,300,'+',"sssss"},
                            TestData{200,200,0,'-',"Sssss"},
                            TestData{10,4,2,'/'},
                            TestData{4,5,20,'*',"hansolo"}
                          ));
int main()
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}