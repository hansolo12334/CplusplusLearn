#include"hansolo_server.h"

Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);
Color::Modifier red(Color::FG_RED);

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

bool hansolo_core::read_client_msg(char *buf,int length)
{
    std::string message;
    message = std::string(buf, length);
    if(m_client.ParseFromString(message))
    {
        if(m_client.port()!=0)
        {
            std::cout <<"node name: "<< m_client.clientname()<<" ip address: "<<m_client.ip_address() <<" port: "<< m_client.port() << std::endl;
            m_current_reqType = createNode;
            auto add = m_clients.add_clit();
            add->set_clientname(m_client.clientname());
            add->set_ip_address(m_client.ip_address());
            add->set_port(m_client.port());
            return true;
        }
    }
    if(pubReqFromClient.ParseFromString(message))
    {
        if(pubReqFromClient.publish_name()!="0")
        {
            std::cout << "node name: " << pubReqFromClient.clientname()<< " pub topic name: " << pubReqFromClient.publish_name() << std::endl;
            m_current_reqType = createPublisher;

            m_current_select_port=selectPortForClienPublishReq();
            std::cout << "create port " << m_current_select_port << std::endl;

            return true;
        }
    }
    return false;
}

bool hansolo_core::read_from_client()
{


    m_cliaddr_len = sizeof(m_cliaddr);
    m_receive_size = recvfrom(m_sockfd, m_buf, MAXLINE, 0, (struct sockaddr *)&m_cliaddr, &m_cliaddr_len);
    if (m_receive_size == -1){
        perror("recvfrom error");
        return false;
    }


    std::cout << green << "received from " << inet_ntop(AF_INET, &m_cliaddr.sin_addr, m_str, sizeof(m_str))
              << " at PORT " << ntohs(m_cliaddr.sin_port) <<def<< std::endl;


    // printf("\033[1;31m received from %s at PORT %d\033[0m\n",
    //        inet_ntop(AF_INET, &m_cliaddr.sin_addr, m_str, sizeof(m_str)),
    //        ntohs(m_cliaddr.sin_port));


    if(!read_client_msg(m_buf,m_receive_size)){
        return false;
    }


    std::string temp{};

    if(m_current_reqType==createNode){

        touchIsSuccess.set_clientname(m_client.clientname());
        touchIsSuccess.set_success(1);
        if(client_names.find(m_client.clientname())!=client_names.end())
        {
            std::cout <<red<< "错误! 节点名称冲突! :" << m_client.clientname() << def<<std::endl;
            touchIsSuccess.set_success(0);
        }
        if(!touchIsSuccess.SerializeToString(&temp))
        {
            perror("序列化失败");
            return false;
        }
    }

    if (m_current_reqType == createPublisher)
    {
        pubAnsToClient.set_port(m_current_select_port);
        pubAnsToClient.set_clientname(pubReqFromClient.clientname());
        if (!pubAnsToClient.SerializeToString(&temp))
        {
            perror("序列化失败");
            return false;
        }
    }

    m_receive_size = sendto(m_sockfd, temp.c_str(), temp.length(), 0, (struct sockaddr *)&m_cliaddr, sizeof(m_cliaddr));
    if (m_receive_size == -1){
        perr_exit("sendto error");
    }


    if(m_current_reqType==createNode){
        client_names[m_client.clientname()]++;
        m_client.Clear();
    }
    if(m_current_reqType==createPublisher){
        pubReqFromClient.Clear();
    }

    m_current_reqType = noneType;
    touchIsSuccess.Clear();
    pubAnsToClient.Clear();


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

    if(!read_client_msg(buffer_msg,length)){
        return false;
    }


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


int hansolo_core::selectPortForClienPublishReq()
{
   while(m_tcp.test_server_port(m_start_portId)==false){
       m_start_portId++;
   }
   m_tcp.tcp_close();
   int port = m_start_portId;
   return port;
}


void hansolo_core::main_loop()
{
    while(1)
    {
        read_from_client();

    }
}
