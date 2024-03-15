#include"hansolo_tcp_thread.h"
#include<thread>



void tcp_loop(hansolo_tcp *my_tcp)
{
    if(!my_tcp->init_server_tcp(4321)){
        std::cout << "error111\n";
    }


    while (1)
    {
        char buf[128] = {0};

        int recv_len =my_tcp->tcp_blocking_recv(my_tcp->m_client_fd, buf, sizeof(buf));
        if (recv_len <= 0)
        {
            printf("recv error!\n");
            my_tcp->tcp_close(my_tcp->m_client_fd);
            my_tcp->tcp_close(my_tcp->m_server_fd);
            exit(EXIT_FAILURE);
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


void tcp_loop1(hansolo_tcp *my_tcp)
{
     if(!my_tcp->init_server_tcp(4323)){
        std::cout << "erro222\n";
    }

    while (1)
    {
        char buf[128] = {0};

        int recv_len =my_tcp->tcp_blocking_recv(my_tcp->m_client_fd, buf, sizeof(buf));
        if (recv_len <= 0)
        {
            printf("recv error!\n");
            my_tcp->tcp_close(my_tcp->m_client_fd);
            my_tcp->tcp_close(my_tcp->m_server_fd);
            exit(EXIT_FAILURE);
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
int main()
{
    // hansolo_tcp *my_tcp{};
    // hansolo_tcp *my_tcp1{};
    // my_tcp = new hansolo_tcp{};
    // my_tcp1 = new hansolo_tcp{};

    // // my_tcp1->init_server_tcp(4322);

    // std::thread t1(tcp_loop, my_tcp);
    // // t1.detach();

    // std::thread t2(tcp_loop1, my_tcp1);
    // // t2.detach();

    // t1.join();
    // t2.join();

    std::vector<hansolo_tcp_thread *> my_tcps{};
    int port = 4321;
    for (int i = 0; i < 2; i++)
    {
        hansolo_tcp_thread *tcp = new hansolo_tcp_thread{port};
        port++;
        my_tcps.push_back(tcp);
        tcp->server_start();
    }

    while (1)
    {

    }
    return 0;
}
