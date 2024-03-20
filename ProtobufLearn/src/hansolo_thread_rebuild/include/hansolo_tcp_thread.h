#ifndef HANSOLO_TCP_THREAD_H
#define HANSOLO_TCP_THREAD_H

#include"hansolo_tcp.h"

#include<thread>
#include<iostream>
#include<vector>
#include<chrono>
#include<future>

#include"colormod.h"


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
    std::string m_node_name;
    std::string m_topic_name;

public:
    hansolo_tcp_thread(int port,std::string node_name,std::string topic_name);
    ~hansolo_tcp_thread();

    std::string sendData{};

    void server_update(int port);
    void server_start();
    void end();
    void pause();
    void resume();
};


#endif
