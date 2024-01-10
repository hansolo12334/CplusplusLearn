#include <iostream>
#include <fstream>
#include <string>

#include "AddressBook.pb.h"

using namespace std;

void writeBook(test::AddressBook &my_addressBook)
{
  test::Person *p1 = my_addressBook.add_people();
  string name;
  cout << "输入姓名\n";
  // std::getline(cin, name);
  cin >> name;
  p1->set_name(name);
  int id;
  cout << "输入id\n";
  cin >> id;
  p1->set_id(id);
  string email;
  cout << "输入邮箱\n";
  cin >> email;
  p1->set_email(email);

  bool endPhoneInput = false;
  cout << "添加联系人电话 y or n\n";
  char opt;
  cin >> opt;
  if (opt == 'y')
  {
    endPhoneInput = false;
  }
  else
  {
    endPhoneInput = true;
  }

  while (!endPhoneInput)
  {
    test::Person_PhoneNumber *phone = p1->add_phones();
    cout << "选择电话类型:\nUNSPECIFIED 0\nMOBILE 1\nHOME 2\nWORK 3\n";
    int phonetyp = 0;
    cin >> phonetyp;
    switch (phonetyp)
    {
    case 0:
      phone->set_type(test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_UNSPECIFIED);
      break;
    case 1:
      phone->set_type(test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_MOBILE);
      break;
    case 2:
      phone->set_type(test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_HOME);
      break;
    case 3:
      phone->set_type(test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_WORK);
      break;
    default:
      break;
    }
    cout << "输入电话号码\n";
    string number{};
    cin >> number;
    phone->set_number(number);

    char opt;
    cout << "继续添加号码? y or n \n";
    cin >> opt;
    if (opt == 'y')
    {
      endPhoneInput = false;
    }
    else
    {
      endPhoneInput = true;
    }
  }
}

void listBook()
{
  cout << "输入文件路径: ";
  string filePath;
  cin >> filePath;
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

int main()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  test::AddressBook my_addressBook;

  // test::Person *p1= my_addressBook.add_people();

  // p1->set_email("2222@gmail.com");
  // p1->set_id(1);
  // p1->set_name("hansolo");

  // test::Person_PhoneNumber *phone = p1->add_phones();
  // phone->set_type(test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_WORK);
  // phone->set_number("22233344");

  // string outPutFileName{"test.txt"};
  // fstream output(outPutFileName, ios::out | ios::trunc | ios::binary);

  // if(!my_addressBook.SerializeToOstream(&output)){
  //   cerr << "写入文件失败\n";
  //   exit(-1);
  // }

  bool endinput = false;

  while (!endinput)
  {
    writeBook(my_addressBook);
    cout << "继续添加联系人? y or n\n";
    char opt;
    cin >> opt;
    if (opt == 'y')
    {
      endinput = false;
    }
    else if (opt == 'n')
    {
      endinput = true;
    }
    else
    {
      endinput = true;
    }
  }
  cout << "保存电话簿? y or n\n";
  char opt;
  cin >> opt;
  if (opt == 'y')
  {
    string outPutFileName{"test.txt"};
    fstream output(outPutFileName, ios::out | ios::trunc | ios::binary);

    if (!my_addressBook.SerializeToOstream(&output))
    {
      cerr << "写入文件失败\n";
      exit(-1);
    }
    cout << "保存成功!\n";
  }

  cout << "读取保存的文件? y or n\n";
  cin >> opt;
  if(opt=='y'){
    cout << "\n\n\n\n";
    listBook();
  }


  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();
  return 0;
}