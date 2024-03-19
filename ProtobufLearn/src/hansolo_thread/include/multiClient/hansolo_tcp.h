#ifndef HANSOLO_TCP_H
#define HANSOLO_TCP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#include<iostream>

#include "wrap.h"

#define MAXLINE 120
#define SERV_PORT 8000

class hansolo_tcp
{
private:




public:
    hansolo_tcp();
    ~hansolo_tcp();

    int maxi{};
    int maxfd{};
    int listenfd{};
    int connfd{};
    int sockfd{};
    int nready{};
    int client[FD_SETSIZE];

    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];

    ssize_t data_size{};
    fd_set rset, allset;

    socklen_t cliaddr_len;
    struct sockaddr_in  cliaddr, servaddr;


    bool init_server_tcp(int port);

    bool tcp_server_update_once();
};


#endif
