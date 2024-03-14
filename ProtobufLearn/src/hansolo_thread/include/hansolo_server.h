#ifndef HANSOLO_SERVER_H
#define HANSOLO_SERVER_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

#include"wrap.h"

//通信的序列化信息
#include"coreConnection.pb.h"


#define MAXLINE 1000
#define SERV_PORT 8000



class hansolo_core
{
private:

    int m_current_clients{};

    struct sockaddr_in m_servaddr;
    struct sockaddr_in m_cliaddr;
    socklen_t m_cliaddr_len;

    int m_sockfd;

    char m_buf[MAXLINE];
    char m_str[INET_ADDRSTRLEN];

    int m_receive_size;

    test::hansoloClients m_clients{};
    test::hansoloClient m_client{};
    test::firstTouchResultToClient touchIsSuccess{};

    std::unordered_map<std::string,int> client_names{};


public:
    hansolo_core();
    ~hansolo_core();

    void init();

    void main_loop();

    void read_client_msg(char *buf,int length);

    bool read_twice_from_client();
    bool read_from_client();
};


#endif
