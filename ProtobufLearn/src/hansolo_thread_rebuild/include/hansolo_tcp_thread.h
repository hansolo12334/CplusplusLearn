#ifndef HANSOLO_TCP_THREAD_H
#define HANSOLO_TCP_THREAD_H

#include"hansolo_tcp.h"

#include<thread>
#include<iostream>
#include<vector>
#include<chrono>
#include<future>




class hansolo_tcp_thread
{
private:
    int m_a;

    std::mutex mu;
    bool m_stopE = false;
    bool m_pause = false;
    std::condition_variable m_cv;

    hansolo_tcp *my_tcp{nullptr};

    int m_prot{};

public:
    hansolo_tcp_thread(int port);
    ~hansolo_tcp_thread();


    void server_update(int port);
    void server_start();
    void end();
    void pause();
    void resume();
};


#endif
