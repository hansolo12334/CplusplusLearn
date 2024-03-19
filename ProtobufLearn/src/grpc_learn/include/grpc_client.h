#ifndef GRPC_CLIENT_H
#define GRPC_CLIENT_H

#include<memory>
#include<iostream>
#include<string>

#include"absl/flags/flag.h"
#include"absl/flags/parse.h"

#include<grpcpp/grpcpp.h>

#include"hansoloCores.grpc.pb.h"

// ABSL_FLAG(std::string, target, "localhost:50051", "服务端地址");

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using hansolo_thread::RegistReply;
using hansolo_thread::Register;
using hansolo_thread::RegistRequest;

using hansolo_thread::RegistePublisherReply;
using hansolo_thread::RegistePublisherRequest;

class grpc_client
{
public:
    grpc_client(std::shared_ptr<Channel> channel)
     : stub_{Register::NewStub(channel)}
     {}

     std::string SayRegist(const std::string &user);

     std::string RegistePublisher(const std::string &user, const std::string topic);

 private:
     std::unique_ptr<Register::Stub> stub_;
};


#endif
