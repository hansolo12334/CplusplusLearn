#include "hansolo_tcp.h"



hansolo_tcp::hansolo_tcp()
{

}
hansolo_tcp::~hansolo_tcp()
{

}

bool hansolo_tcp::test_server_port(int port)
{
    // std::cout<<"==================tcp server==================\n";
    m_server_fd = tcp_init(NULL, port);

    if (m_server_fd < 0)
    {
        perror("tcp_init error!");
        return false;
    }
    return true;
}

int hansolo_tcp::tcp_init(const char* ip, int port)
{
    int optval = 1;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        return -1;
    }

    /* 解除端口占用 */
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
    {
    perror("setsockopt\n");
    return -1;
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(struct sockaddr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (NULL == ip)
    {
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else
    {
        server_addr.sin_addr.s_addr = inet_addr(ip);
    }

    if (bind(server_fd, (struct sockaddr*)&server_addr,sizeof(struct sockaddr)) < 0)
    {
        perror("bind");
        close(server_fd);
        return -1;
    }

    if(listen(server_fd, MAX_CONNECT_NUM) < 0)
    {
        perror("listen");
        close(server_fd);
        return -1;
    }

    return server_fd;
}



int hansolo_tcp::tcp_accept(int server_fd)
{
    struct sockaddr_in client_addr = {0};
    int addrlen = sizeof(struct sockaddr);

    int new_fd = accept(server_fd, (struct sockaddr*) &client_addr,(socklen_t *)&addrlen);

    if(new_fd < 0)
    {
        perror("accept");
        close(server_fd);
        return -1;
    }

    return new_fd;
}

int hansolo_tcp::tcp_connect(const char *ip, int port)
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(struct sockaddr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("connect");
        close(server_fd);
        return -1;
    }

    return server_fd;
}

int hansolo_tcp::tcp_nonblocking_recv(int conn_sockfd, void *rx_buf, int buf_len, int timeval_sec, int timeval_usec)
{
 fd_set readset;
 struct timeval timeout = {0, 0};
 int maxfd = 0;
 int fp0 = 0;
 int recv_bytes = 0;
 int ret = 0;

 timeout.tv_sec = timeval_sec;
 timeout.tv_usec = timeval_usec;
 FD_ZERO(&readset);
 FD_SET(conn_sockfd, &readset);

 maxfd = conn_sockfd > fp0 ? (conn_sockfd+1) : (fp0+1);

 ret = select(maxfd, &readset, NULL, NULL, &timeout);
 if (ret > 0)
    {
  if (FD_ISSET(conn_sockfd, &readset))
        {
   if ((recv_bytes = recv(conn_sockfd, rx_buf, buf_len, MSG_DONTWAIT))== -1)
            {
    perror("recv");
    return -1;
   }
  }
 }
    else
    {
  return -1;
 }

 return recv_bytes;
}

int hansolo_tcp::tcp_blocking_recv(int conn_sockfd, void *rx_buf, uint16_t buf_len)
{
    return recv(conn_sockfd, rx_buf, buf_len, 0);
}

int hansolo_tcp::tcp_send(int conn_sockfd, uint8_t *tx_buf, uint16_t buf_len)
{
    return send(conn_sockfd, tx_buf, buf_len, 0);
}

void hansolo_tcp::tcp_close(int sockfd)
{
    close(sockfd);
}


void hansolo_tcp::tcp_close()
{
    close(m_server_fd);
}


bool hansolo_tcp::init_server_tcp(int port)
{
    std::cout<<"==================tcp server==================\n";
    m_server_fd = tcp_init(NULL, port);

    if (m_server_fd < 0)
    {
        perror("tcp_init error!");
        return false;
    }

    m_client_fd = tcp_accept(m_server_fd);

    if (m_client_fd < 0)
    {
        perror("tcp_accept error!\n");
        return false;
    }

    m_port = port;

    return true;
}

bool hansolo_tcp::init_client_tcp()
{
    return true;
}
