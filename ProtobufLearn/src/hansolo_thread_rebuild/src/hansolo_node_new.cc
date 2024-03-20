#include"hansolo_node_new.h"

ABSL_FLAG(std::string, target, "localhost:50051", "服务端地址");

hansolo_node::hansolo_node(std::string node_name)
     :  m_node_name{node_name}
{

    stub_ = Register::NewStub(grpc::CreateChannel(absl::GetFlag(FLAGS_target), grpc::InsecureChannelCredentials()));

    std::string reply =SayRegist(node_name);
    hDebug(Code::FG_GREEN) << reply;

    // signal(SIGINT, RegistOffline);
}

hansolo_node::~hansolo_node()
{

}
std::string hansolo_node::SayRegist(const std::string &user)
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
        hDebug(Code::FG_RED) << status.error_code() << ": " << status.error_message();
        return "RPC failed";
    }
}

int hansolo_node::RegistePublisher(const std::string topic)
{
    RegistePublisherRequest request;
    request.set_nodename(m_node_name);
    request.set_topicname(topic);

    RegistePublisherReply reply;

    ClientContext context;

    Status status = stub_->RegistePublisher(&context, request, &reply);

    if(status.ok()){
        std::string re{"从master注册 publiher成功! 端口为: "};
        re = re + std::to_string(reply.port());
        hDebug(Code::FG_GREEN) << re;
        return reply.port();
    }
    else{
        hDebug(Code::FG_RED) << status.error_code() << ": " << status.error_message();
        return -1;
    }
}

void hansolo_node::RegistOffline(int signum)
{
    hDebug(Code::FG_RED) << "中断信号 " << signum;

    OfflineRequest request;
    request.set_nodename(m_node_name);

    OfflineReply reply;

    ClientContext context;

    Status status = stub_->RegistOffline(&context, request, &reply);

    if(status.ok()){

        hDebug(Code::FG_RED) << "下线 " << signum;
    }
}


// template<typename T>
// HansoloPublisher hansolo_node::create_publisher(std::string topic_name)


// HansoloPublisher hansolo_node::_init_tcp(int port,std::string topic_name)
// {
//     // hansolo_tcp_thread *my_tcp = new hansolo_tcp_thread{port,m_node_name,topic_name};
//     HansoloPublisher pub{m_node_name,topic_name,port};
//     m_pubs.push_back(pub);
//     return pub;
// }
