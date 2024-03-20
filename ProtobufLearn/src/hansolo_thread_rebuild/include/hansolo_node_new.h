#ifndef HANSOLO_NODE_H
#define HANSOLO_NODE_H

#include<memory>
#include<iostream>
#include<string>

#include<signal.h>

#include"absl/flags/flag.h"
#include"absl/flags/parse.h"

#include<grpcpp/grpcpp.h>


#include"hansolo_tcp_thread.h"

#include"colormod.h"
#include"hansolo_publisher.h"


#include"coreConnection.grpc.pb.h"


//msg
#include"hansolo_std_msg.h"

using Color::Code;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hansolo::RegistReply;
using hansolo::Register;
using hansolo::RegistRequest;

using hansolo::RegistePublisherReply;
using hansolo::RegistePublisherRequest;

using hansolo::OfflineReply;
using hansolo::OfflineRequest;

class hansolo_node
{
public:
    hansolo_node(std::string node_name);
    ~hansolo_node();




    std::string SayRegist(const std::string &user);


    int RegistePublisher(const std::string topic);

    void RegistOffline(int signum);

    template<typename T>
    HansoloPublisher<T> create_publisher(std::string topic_name)
    {
        int port = RegistePublisher(topic_name);

        HansoloPublisher<T> pub{m_node_name,topic_name,port};
        return pub;
    }

    // static hansolo_node* instancePtr;
private:
    std::unique_ptr<Register::Stub> stub_;


    // std::vector<HansoloPublisher> m_pubs{};
    std::string m_node_name{};



};


#endif
