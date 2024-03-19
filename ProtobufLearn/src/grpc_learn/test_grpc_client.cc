#include<iostream>
#include"grpc_client.h"

ABSL_FLAG(std::string, target, "localhost:50051", "服务端地址");

int main(int argc,char **argv)
{
    // absl::ParseCommandLine(argc, argv);

    std::string target_str{absl::GetFlag(FLAGS_target)};

    grpc_client client{grpc::CreateChannel(target_str,grpc::InsecureChannelCredentials())};

    std::string user{"hansolo"};



    // while(true)
    // {
    std::string reply{client.SayRegist(user)};
    std::cout << "客户端收到! " << reply << std::endl;
    sleep(1);

    reply = client.RegistePublisher(user, "/test_node");
    std::cout << "客户端收到! " << reply << std::endl;

    // }


    return 0;
}
