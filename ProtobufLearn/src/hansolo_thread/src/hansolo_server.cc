#include"hansolo_server.h"



hansolo_core::hansolo_core()
{
    init();
    main_loop();
}

hansolo_core::~hansolo_core()
{

}

void hansolo_core::init()
{
    m_sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&m_servaddr, sizeof(m_servaddr));
    m_servaddr.sin_family = AF_INET;
    m_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_servaddr.sin_port = htons(SERV_PORT);

    Bind(m_sockfd, (struct sockaddr *)&m_servaddr, sizeof(m_servaddr));

    printf("Accepting connections ...\n");
}

void hansolo_core::read_client_msg(char *buf,int length)
{
    std::string message;
    message = std::string(buf, length);
    if(!m_client.ParseFromString(message))
    {
        std::cout << "序列化失败!\n";
        return;
    }
    std::cout <<"node name: "<< m_client.clientname()<<" ip address: "<<m_client.ip_address() <<" port: "<< m_client.port() << std::endl;
}

bool hansolo_core::read_from_client()
{
    m_cliaddr_len = sizeof(m_cliaddr);
    m_receive_size = recvfrom(m_sockfd, m_buf, MAXLINE, 0, (struct sockaddr *)&m_cliaddr, &m_cliaddr_len);
    if (m_receive_size == -1){
        perror("recvfrom error");
        return false;
    }

    printf("received from %s at PORT %d\n",
            inet_ntop(AF_INET, &m_cliaddr.sin_addr, m_str, sizeof(m_str)),
            ntohs(m_cliaddr.sin_port));
    read_client_msg(m_buf, m_receive_size);


    touchIsSuccess.set_clientname(m_client.clientname());
    touchIsSuccess.set_success(true);

    if(client_names.find(m_client.clientname())!=client_names.end()){
        std::cout << "错误! 节点名称冲突! :" << m_client.clientname() << std::endl;
        touchIsSuccess.set_success(false);
    }


    std::string temp{};
    if(!touchIsSuccess.SerializeToString(&temp)){
        perror("序列化失败");
        return false;
    }

    m_receive_size = sendto(m_sockfd, temp.c_str(), temp.length(), 0, (struct sockaddr *)&m_cliaddr, sizeof(m_cliaddr));
    if (m_receive_size == -1){
        perr_exit("sendto error");
    }

    client_names[m_client.clientname()]++;
    return true;

}

/// @brief 一次接收两帧客户端的消息 第一帧是数据长度 第二帧是实际数据
bool hansolo_core::read_twice_from_client()
{
    //读取发送来的两帧数据 第一帧是真实数据的长度信息
    //第二帧是真实数据

    char buffer_header[sizeof(size_t)] = {0};
    m_receive_size =recvfrom(m_sockfd, buffer_header, sizeof(size_t), 0, (struct sockaddr *)&m_cliaddr, &m_cliaddr_len);

    if (m_receive_size== -1)
    {
        std::cout << "读取数据长度失败\n";
        return false;
    }
    std::cout << "in!\n";
    size_t msg_size;
    memcpy(&msg_size, buffer_header, sizeof(size_t)); // sizeof(size_t) => 8

    char *buffer_msg = (char *)malloc(msg_size * sizeof(char));
    memset(buffer_msg, '\0', sizeof(char) * msg_size);

    int length = 0;

    m_cliaddr_len = sizeof(m_cliaddr);

    for (length = 0; msg_size != 0; length += m_receive_size)
    {
        m_receive_size =recvfrom(m_sockfd, buffer_msg + length, msg_size, 0, (struct sockaddr *)&m_cliaddr, &m_cliaddr_len);
        msg_size -= m_receive_size;
    }
    // std::cout << "数据长度为 "<<sizeof(buffer_msg) << std::endl;
    //错误 这样打印出来的永远是8 因为sizeof(buffer_msg)得到的是指针的大小 xx
    printf("received from %s at PORT %d\n",
               inet_ntop(AF_INET, &m_cliaddr.sin_addr, m_str, sizeof(m_str)),
               ntohs(m_cliaddr.sin_port));

    read_client_msg(buffer_msg,length);



    //向客户端发送成功确认通知
    touchIsSuccess.set_clientname(m_client.clientname());
    touchIsSuccess.set_success(true);

    if(client_names.find(m_client.clientname())!=client_names.end()){
        std::cout << "错误! 节点名称冲突! :" << m_client.clientname() << std::endl;
        touchIsSuccess.set_success(false);
    }


    std::string temp{};
    if(!touchIsSuccess.SerializeToString(&temp)){
        perror("序列化失败");
        return false;
    }

    m_receive_size = sendto(m_sockfd, temp.c_str(), temp.length(), 0, (struct sockaddr *)&m_cliaddr, sizeof(m_cliaddr));
    if (m_receive_size == -1){
        perr_exit("sendto error");
    }

    client_names[m_client.clientname()]++;
    return true;
    // touchIsSuccess
}
void hansolo_core::main_loop()
{
    while(1)
    {

        read_from_client();

    }
}
