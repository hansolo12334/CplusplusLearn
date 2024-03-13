
/*
符合聚合条件，整个对象及其部分必须具有以下关系:
 部件（成员）是对象（类）的一部分
 部件（成员）可以（如果需要）一次属于多个对象（类）
 部件（成员）的存在不受对象（类）的管理
 部件（成员）不知道对象（类）的存在

 像组合一样，聚合仍然是一种部分-整体关系，其中部分包含在整体中，并且是一种单向关系。
 但是，与合成不同的是，零件一次可以属于多个对象，并且整个对象不对零件的存在和寿命负责。
 创建聚合时，聚合不负责创建部件。当聚合被销毁时，聚合不负责销毁部件。
*/
//std::reference_wrapper


#include <functional> // std::reference_wrapper
#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::string tom{ "Tom" };
  std::string berta{ "Berta" };

  std::vector<std::reference_wrapper<std::string>> names{ tom, berta }; // 这些字符串以 引用的方式储存 不是 按值

  std::string jim{ "Jim" };

  names.emplace_back(jim);

  for (auto name : names)
  {
    // 使用 get()成员函数来获取 引用的字符串
    name.get() += " Beam";
  }

  std::cout << jim << '\n'; // 输出 Jim Beam

  return 0;
}
