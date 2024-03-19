#include<iostream>
#include"grpc_server.h"

void RunServer(uint16_t port)
{
    std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
    grpc_server service;


    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());

    std::cout << "服务端 在端口 " << server_address << " 监听\n";

    server->Wait();
}

int main(int argc,char **argv)
{
    // absl::ParseCommandLine(argc, argv);
    RunServer(absl::GetFlag(FLAGS_port));
}
