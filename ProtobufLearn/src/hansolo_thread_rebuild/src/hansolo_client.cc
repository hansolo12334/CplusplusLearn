#include"hansolo_client.h"


hansolo_client::hansolo_client()
{
    m_sockfd=Socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&m_servaddr, sizeof(m_servaddr));
    m_servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, IP_ADDRESS, &m_servaddr.sin_addr);
    m_servaddr.sin_port = htons(SERV_PORT);
    // m_servaddr.sin_port = htons(m_port);
    // while(bind(m_sockfd,(struct sockaddr *)&m_servaddr, sizeof(m_servaddr))<0){
    //     Close(m_sockfd);
    //     std::cout << m_port << std::endl;
    //     m_port++;
    //     m_sockfd=Socket(AF_INET, SOCK_DGRAM, 0);
    //     bzero(&m_servaddr, sizeof(m_servaddr));
    //     m_servaddr.sin_family = AF_INET;
    //     inet_pton(AF_INET, IP_ADDRESS, &m_servaddr.sin_addr);
    //     m_servaddr.sin_port = htons(m_port);
    // }
}

hansolo_client::~hansolo_client()
{
    Close(m_sockfd);
}

bool hansolo_client::init_node(std::string node_name)
{
    m_node_name = node_name;
    m_client_info.set_ip_address(IP_ADDRESS);
    m_client_info.set_clientname(m_node_name);
    m_client_info.set_port(m_port);

    if(!touch_once_to_server(m_client_info)){
        return false;
    }
    return true;
}

/// @brief  向客户端发送数据 当数据很大时 一次发送两帧 第一帧是数据大小 第二帧是真实数据
/// @return 成功 失败
template <typename T>
bool hansolo_client::send_to_server_twice(T &protoData)
{
    std::string temp{};
    if(!protoData.SerializeToString(&temp)){
        perror("序列化失败");
        return false;
    }
     //不知道数据大小 先发送数据的长度
    size_t msg_size = temp.length();
    char header[sizeof(size_t)];
    memset(header, '\0', sizeof(size_t));
    memcpy(header, (char *)&msg_size, sizeof(size_t));
    if(sendto(m_sockfd, header, sizeof(size_t), 0, (struct sockaddr *)&m_servaddr, sizeof(m_servaddr))==-1)
    {
        perr_exit("sendto error");
        return false;
    }
    //发送真实数据
    m_receive_size = sendto(m_sockfd, temp.c_str(), msg_size, 0, (struct sockaddr *)&m_servaddr, sizeof(m_servaddr));
    if (m_receive_size == -1)
    {
        perr_exit("sendto error");
        return false;
    }
    return true;
}

/// @brief  向客户端一次性发送数据
/// @return 成功 失败
template <typename T>
bool hansolo_client::send_to_server_once(T &protoData)
{
    //发送真实数据
    std::string temp{};
    if(!protoData.SerializeToString(&temp)){
        perror("序列化失败");
        return false;
    }

    size_t msg_size = temp.length();
    m_receive_size = sendto(m_sockfd, temp.c_str(), msg_size, 0, (struct sockaddr *)&m_servaddr, sizeof(m_servaddr));
    if (m_receive_size == -1)
    {
        perr_exit("sendto error");
        return false;
    }
    return true;
}

template <typename T>
bool hansolo_client::touch_once_to_server(T &protoData)
{
    char m_buf[MAXLINE];

    if(!send_to_server_once(protoData)){
        return false;
    }
    std::cout << "发送成功\n";

    m_receive_size = recvfrom(m_sockfd, m_buf, MAXLINE, 0, NULL, 0);
    if (m_receive_size == -1){
        perr_exit("recvfrom error");
        return false;
    }

    std::string temp = std::string(m_buf, m_receive_size);
    hansolo::firstTouchResultToClient result{};
    hansolo::publisherCreateAnsToClient pubAns{};

    if (result.ParseFromString(temp))
    {
        if(result.success()==1 || result.success()==0){
            if(result.success()==1){
                std::cout << "和 master 接触成功！\n";
                protoData.Clear();
                result.Clear();
                return true;
            }
        }
    }
    if(pubAns.ParseFromString(temp))
    {
        if (pubAns.port() != 0 && pubAns.port() != 1)
        {
            std::cout << "从server获得分配的port: " << pubAns.port() << std::endl;
            tcp_port = pubAns.port();
            if(!init_tcp()){
                std::cout << "初始化tcp server失败\n";
            }
            protoData.Clear();
            pubAns.Clear();
            return true;
        }
    }

    // Write(STDOUT_FILENO, m_buf, m_receive_size);
    return false;
}

/// @brief 生成一个新的发布器 创建一个新的tcp服务器
/// @param topic_name
bool hansolo_client::create_publisher(std::string topic_name)
{
    pubReq.set_publish_name(topic_name);
    pubReq.set_clientname(m_node_name);
    if(!touch_once_to_server(pubReq)){
        return false;
    }
    return true;
}



bool hansolo_client::init_tcp()
{
    hansolo_tcp_thread *my_tcp = new hansolo_tcp_thread{tcp_port};
    my_tcps.push_back(my_tcp);
    my_tcp->server_start();

    return true;
}
