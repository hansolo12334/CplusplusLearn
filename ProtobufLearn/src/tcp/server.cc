#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>


#include "AddressBook.pb.h"

#define PORT 8080

void readBuffer(int new_socket, std::string &msg)
{
  int valread;
  char buffer_header[sizeof(size_t)] = {0}; // buffer_header[8]= u 0 0 0 0 0 0 0 0
  // 客户端 第一次 发送来的是 数据的大小
  valread = read(new_socket, buffer_header, sizeof(size_t));

  size_t msg_size;
  memcpy(&msg_size, buffer_header, sizeof(size_t)); // sizeof(size_t) => 8

  char *buffer_msg = (char *)malloc(msg_size * sizeof(char));
  memset(buffer_msg, '\0', sizeof(char) * msg_size);
  int length = 0;
  for (length = 0; msg_size != 0; length += valread)
  {
    // 客户端第二次发送来的才是数据
    valread = read(new_socket, buffer_msg + length, msg_size);
    msg_size -= valread;
  }
  msg = std::string(buffer_msg, length);
  free(buffer_msg);
}



/// @brief  将字符串反序列化
/// @param newAddressBook  test::AddressBook类
/// @param message  获得的字符串
void showMsg(test::AddressBook &newAddressBook,std::string &message)
{

  if(!newAddressBook.ParseFromString(message)){
    perror("反序列化失败");
    exit(EXIT_FAILURE);
  }

   for (int i = 0; i < newAddressBook.people_size(); i++)
  {
    const test::Person &person = newAddressBook.people(i);
    std::cout << "姓名: " << person.name() << '\n';
    std::cout << "ID: " << person.id() << '\n';
    std::cout << "邮箱: " << person.email() << '\n';
    for (int j = 0; j < person.phones_size(); j++)
    {
      const test::Person_PhoneNumber &phone = person.phones(j);
      std::cout << "电话类型: ";
      switch (phone.type())
      {
      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_UNSPECIFIED:
      {
        std::cout << "UNSPECIFIED\n";
        break;
      }

      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_MOBILE:
      {
        std::cout << "MOBILE\n";
        break;
      }
      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_WORK:
      {
        std::cout << "WORK\n";
        break;
      }
      case test::Person_PhoneType::Person_PhoneType_PHONE_TYPE_HOME:
      {
        std::cout << "HOME\n";
        break;
      }
      }
      std::cout << "电话号码: " << phone.number() << '\n';
    }
  }
  std::cout << "\n\n\n\n\n";
}





int main()
{
  int server_fd;
  int new_socket;
  int opt = 1;

  struct sockaddr_in address;

  int addrlen = sizeof(address);

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
    perror("socket 失败");
    exit(EXIT_FAILURE);
  }

  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
  {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
  {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }
  std::cout << "服务启动 监听端口 " << PORT << "...\n";
  if (listen(server_fd, 3) < 0)
  {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  test::AddressBook newAddressBook;

  while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)))
  {
    if (new_socket < 0)
    {
      perror("accept error");
      exit(EXIT_FAILURE);
    }
    else
    {
      std::cout << "收到client!\n";
      std::string message;
      readBuffer(new_socket, message);
      std::cout << message << '\n';
      showMsg(newAddressBook, message);
    }
  }

  return 0;
}
