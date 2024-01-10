#include<iostream>
#include<string>
#include<fstream>

#include "test.pb.h"

using namespace std;

int main()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  test::msgs::Person person1;
  person1.set_age(2222);
  person1.set_id(3333);
  person1.set_name("hansolo");

  person1.add_my_vector(2);
  person1.add_my_vector(3);

  string outPutFileName{"test.txt"};

  fstream output(outPutFileName, ios::out | ios::trunc | ios::binary);

  if(!person1.SerializeToOstream(&output)){
    cerr << "写入文件失败\n";
    exit(-1);
  }
  
  return 0;
}