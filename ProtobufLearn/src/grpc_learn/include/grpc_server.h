#ifndef GRPC_SERVER_H
#define GRPC_SERVER_H

#include"absl/flags/flag.h"
#include"absl/flags/parse.h"
#include"absl/strings/str_format.h"

#include<grpcpp/ext/proto_server_reflection_plugin.h>
#include<grpcpp/grpcpp.h>
#include<grpcpp/health_check_service_interface.h>


#include<iostream>
#include<string>
#include<map>
#include<memory>

#include"hansoloCores.grpc.pb.h"

using grpc::CallbackServerContext;
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerUnaryReactor;
using grpc::Status;
// using hansolo_thread::Greeter;
// using hansolo_thread::HelloReply;
// using hansolo_thread::HelloRequest;

using hansolo_thread::Register;
using hansolo_thread::RegistReply;
using hansolo_thread::RegistRequest;

using hansolo_thread::RegistePublisherReply;
using hansolo_thread::RegistePublisherRequest;

//          参数类型，参数名， 默认值， 备注。
ABSL_FLAG(uint16_t, port, 50051, "用于服务端的端口");

// final 修饰类 不能被继承，也没有子类。
// class grpc_server final : public Register::Service
// {

// private:
//     int m_port{4321};

// public:

//     Status SayRegist(ServerContext* context,const RegistRequest *request,RegistReply* reply) override
//     {
//         std::string prefix{"master: "};
//         reply->set_nodename(request->nodename());
//         reply->set_registstatus(true);
//         return Status::OK;
//     }
// };

class grpc_server final : public Register::CallbackService
{

private:
    int m_port{4321};

public:
    ServerUnaryReactor* SayRegist(CallbackServerContext*context,const RegistRequest*request,RegistReply*reply) override{

        std::string prefix{"master: "};
        reply->set_nodename(request->nodename());
        std::cout << "节点 " << request->nodename() << " 申请注册\n";
        ServerUnaryReactor *reactor = context->DefaultReactor();
        reactor->Finish(Status::OK);
        return reactor;
    }

    // Status SayRegist(ServerContext* context,const RegistRequest *request,RegistReply* reply) override
    // {
    //     std::string prefix{"master: "};
    //     reply->set_nodename(request->nodename());
    //     reply->set_registstatus(true);
    //     return Status::OK;
    // }
    ServerUnaryReactor* RegistePublisher(CallbackServerContext*context,const RegistePublisherRequest *request, RegistePublisherReply *reply) override{
        reply->set_nodename(request->nodename());
        reply->set_topicname(request->topicname());
        reply->set_port(m_port);
        m_port++;
        std::cout << "节点 " << request->nodename() << " 申请注册 publisher端口\n";
        ServerUnaryReactor *reactor = context->DefaultReactor();
        reactor->Finish(Status::OK);
        return reactor;
    }
};

#endif
