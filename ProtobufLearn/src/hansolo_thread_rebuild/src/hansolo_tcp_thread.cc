#include <iostream>
#include <thread>
#include "hansolo_tcp_thread.h"


hansolo_tcp_thread::hansolo_tcp_thread(int port,std::string node_name,std::string topic_name)
    : m_prot{port}
    , m_node_name{node_name}
    , m_topic_name{topic_name}
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
    hDebug(Color::FG_BLUE) << m_node_name <<' '<<m_topic_name << " publisher启动";
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
        // my_tcp->tcp_server_update_once();
        if(sendData.length()>0){
            my_tcp->tcp_server_update_once_send_msg(sendData);
        }
        sendData.clear();
    }
}
