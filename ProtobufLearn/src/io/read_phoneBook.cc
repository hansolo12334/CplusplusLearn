#include <iostream>
#include <fstream>
#include <string>

#include "AddressBook.pb.h"

using namespace std;



void listBook(string filePath)
{
  // cout << "输入文件路径: ";
  // string filePath;
  // cin >> filePath;
  fstream input(filePath, ios::in | ios::binary);
  test::AddressBook my_addressBook;
  if (!my_addressBook.ParseFromIstream(&input))
  {
    cerr << "读取文件失败\n";
    return;
  }
  for (int i = 0; i < my_addressBook.people_size(); i++)
  {
    const test::Person &person = my_addressBook.people(i);
    cout << "姓名: " << person.name() << '\n';
    cout << "ID: " << person.id() << '\n';
    cout << "邮箱: " << person.email() << '\n';
    for (int j = 0; j < person.phones_size(); j++)
    {
      const test::Person_PhoneNumber &phone = person.phones(j);
      cout << "电话类型: ";
      switch (phone.type())
      {
      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_UNSPECIFIED:
      {
        cout << "UNSPECIFIED\n";
        break;
      }

      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_MOBILE:
      {
        cout << "MOBILE\n";
        break;
      }
      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_WORK:
      {
        cout << "WORK\n";
        break;
      }
      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_HOME:
      {
        cout << "HOME\n";
        break;
      }
      }
      cout << "电话号码: " << phone.number() << '\n';
    }
  }
}


int main(int argc,char **argv)
{
  if (argc < 2)
  {
    cout << "输入有效参数 文件路径\n";
    exit(-1);
  }
  listBook(argv[1]);
  return 0;
}