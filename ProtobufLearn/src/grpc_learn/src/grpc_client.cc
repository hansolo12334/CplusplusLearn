#include"grpc_client.h"

std::string grpc_client::SayRegist(const std::string &user)
{
    RegistRequest request;
    request.set_nodename(user);

    RegistReply reply;

    ClientContext context;

    Status status = stub_->SayRegist(&context, request, &reply);

    if(status.ok()){
        std::string re{"从master注册!"};
        return re;
    }
    else{
        std::cout << status.error_code() << ": " << status.error_message() << '\n';
        return "RPC failed";
    }
}

std::string grpc_client::RegistePublisher(const std::string &user, const std::string topic)
{
    RegistePublisherRequest request;
    request.set_nodename(user);
    request.set_topicname(topic);

    RegistePublisherReply reply;

    ClientContext context;

    Status status = stub_->RegistePublisher(&context, request, &reply);

    if(status.ok()){
        std::string re{"从master注册 publiher成功! 端口为: "};
        re = re + std::to_string(reply.port());
        return re;
    }
    else{
        std::cout << status.error_code() << ": " << status.error_message() << '\n';
        return "RPC failed";
    }
}
