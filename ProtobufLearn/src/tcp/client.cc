#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <chrono>
#include <ctime>
#include<fstream>

#include "AddressBook.pb.h"

#define PORT 8080

using namespace std;

void listBook(string filePath,test::AddressBook &my_addressBook)
{
  // cout << "输入文件路径: ";
  // string filePath;
  // cin >> filePath;
  fstream input(filePath, ios::in | ios::binary);
  
  if (!my_addressBook.ParseFromIstream(&input))
  {
    cerr << "读取文件失败\n";
    return;
  }
}

void sendMsg(int sock,string &msg)
{
  
  size_t msg_size = msg.length();
  char header[sizeof(size_t)];
  memset(header,'\0',sizeof(size_t));// 八位 全部填充为 0
  memcpy(header, (char *)&msg_size, sizeof(size_t));
  send(sock, header, sizeof(size_t), 0);
  send(sock, msg.c_str(), msg_size, 0);
  std::cout << "msg send!\n";
}

int main()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;



  int sock = 0;
  struct sockaddr_in serv_addr;

  if((sock=socket(AF_INET,SOCK_STREAM,0))<0){
    perror("创建socket失败");
    exit(EXIT_FAILURE);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);


  if(inet_pton(AF_INET,"0.0.0.0",&serv_addr.sin_addr)<=0){
    perror("无效地址/或地址不支持");
    exit(EXIT_FAILURE);
  }
  if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0){
    perror("连接失败");
     exit(EXIT_FAILURE);
  }

  test::AddressBook my_addressBook;
  listBook("test.txt", my_addressBook);

  std::string addressBookStr{};
  if(!my_addressBook.SerializeToString(&addressBookStr)){
    perror("序列化失败");
    exit(EXIT_FAILURE);
  }
  cout << addressBookStr<<'\n';
  sendMsg(sock, addressBookStr);
  return 0;
}