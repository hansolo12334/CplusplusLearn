#include <iostream>
#include <thread>
#include "hansolo_tcp_thread.h"


hansolo_tcp_thread::hansolo_tcp_thread(int port)
    : m_prot{port}
    , my_tcp{new hansolo_tcp{}}
{

}

hansolo_tcp_thread::~hansolo_tcp_thread()
{

}


void hansolo_tcp_thread::server_start()
{
    std::thread t(&hansolo_tcp_thread::server_update, this,m_prot);
    t.detach();
}

void hansolo_tcp_thread::end()
{
    std::cout<<"sssssssssssssss end \n";
    m_stopE = true;
}

void hansolo_tcp_thread::pause()
{
    std::unique_lock<std::mutex> lock(mu);
    m_pause = true;
    m_cv.notify_one();
}

void hansolo_tcp_thread::resume()
{
    std::unique_lock<std::mutex> lock(mu);
    m_pause = false;
    m_cv.notify_one();
}


void hansolo_tcp_thread::server_update(int port)
{
    my_tcp->init_server_tcp(port);
    std::cout << "clinet 连接!\n";
    while (1)
    {
        if(!m_stopE)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::unique_lock<std::mutex> lock(mu);
            m_cv.wait(lock, [this] { return !m_pause; });
        }
        if(m_stopE)
        {
            break;
        }
        /////////

        char buf[128] = {0};

        int recv_len =my_tcp->tcp_blocking_recv(my_tcp->m_client_fd, buf, sizeof(buf));
        // int recv_len = my_tcp->tcp_nonblocking_recv(my_tcp->m_client_fd, buf, sizeof(buf), 0, 0);
        if (recv_len <= 0)
        {
            printf("clinet 退出!\n");
            my_tcp->tcp_close(my_tcp->m_client_fd);
            my_tcp->tcp_close(my_tcp->m_server_fd);
            my_tcp->init_server_tcp(port);
            std::cout << "clinet 连接!\n";
            continue;
            // exit(EXIT_FAILURE);
        }
        printf("recv : %s\n", buf);

        int send_len = my_tcp->tcp_send(my_tcp->m_client_fd, (uint8_t*)buf, strlen(buf));
        if (send_len <= 0)
        {
            printf("send error!\n");
            my_tcp->tcp_close(my_tcp->m_client_fd);
            my_tcp->tcp_close(my_tcp->m_server_fd);
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("send success! send: %s, send_len: %d\n", buf, send_len);
        }
    }
    my_tcp->tcp_close(my_tcp->m_server_fd);

}
