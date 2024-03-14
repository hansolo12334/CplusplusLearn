#ifndef HANSOLO_SERVER_H
#define HANSOLO_SERVER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include<iostream>
#include<string>

#include"wrap.h"

//通信的序列化信息
#include"coreConnection.pb.h"

#define MAXLINE 80
#define SERV_PORT 8000
#define IP_ADDRESS "127.0.0.1"



class hansolo_client
{
private:
    struct sockaddr_in m_servaddr;
    int m_sockfd{};
    int m_receive_size{};
    char m_buf[MAXLINE];
    char m_str[INET_ADDRSTRLEN];
    socklen_t m_servaddr_len;

    std::string m_node_name{};
    int m_port = 8002;
    std::string m_ip_address{};

    test::hansoloClient m_client_info{};



    template <typename T>
    bool send_to_server_twice(T &protoData);
    template <typename T>
    bool send_to_server_once(T &protoData);
    bool touch_once_to_server();

public:
    hansolo_client();
    ~hansolo_client();


    void init_node(std::string node_name);

    void create_publisher(std::string topic_name);
};


#endif
