#include<iostream>

#include<gtest/gtest.h>


int add(int x,int y)
{
  return x + y;
}

TEST(TEST_ADD,UNSIGNED_INT_VALUE)
{
  int re = add(2, 3);
  EXPECT_EQ(re, 5);
  re = add(111, 222);
  EXPECT_NE(re, 111);
}

int main()
{
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}