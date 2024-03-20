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

#include"colormod.h"

#include"hansolo_tcp.h"

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

    hansolo::hansoloClients m_clients{};
    hansolo::hansoloClient m_client{};
    hansolo::firstTouchResultToClient touchIsSuccess{};
    hansolo::publisherCreateReqFromClient pubReqFromClient{};
    hansolo::publisherCreateAnsToClient pubAnsToClient{};
    std::unordered_map<std::string, int> client_names{};

    hansolo_tcp m_tcp;

    //为client 分配的端口起始值
    int m_start_portId = 4321;
    int m_current_select_port = 0;

    struct client_items
    {
        std::string client_name;
        //  pair 自己发布的 话题名称  端口名称
        std::vector<std::pair<std::string,int>> publish_topics{};
        //  pair : 订阅的话题名称 发布该话题名称的节点名字
        std::vector<std::pair<std::string,std::string>> subscribe_topics{};
    };
    std::vector<client_items> m_all_clients{};

    //记录每次的请求种类
    enum RequstType
    {
        createNode,
        createPublisher,
        createSubscriber,
        noneType,
    };


    RequstType m_current_reqType = noneType;


    void init();
    void main_loop();

    //将客户端数据解析为protobuf
    bool read_client_msg(char *buf,int length);
    //读取客户端(若数据太大 读取两次)
    bool read_twice_from_client();
    //一次性读取客户端数据
    bool read_from_client();

    //为客户端请求的publisher分配端口
    int selectPortForClienPublishReq();


public:
    hansolo_core();
    ~hansolo_core();
};



#endif
