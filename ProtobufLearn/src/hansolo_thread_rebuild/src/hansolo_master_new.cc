#include"hansolo_master_new.h"
#include<iostream>



ServerUnaryReactor* hansolo_master::SayRegist(CallbackServerContext*context,const RegistRequest*request,RegistReply*reply){

    std::string prefix{"master: "};
    reply->set_nodename(request->nodename());

    //记录
    node_items node;
    node.node_name = request->nodename();
    m_all_nodes.push_back(node);

    hDebug(Color::FG_GREEN)  << "节点 " << request->nodename() << " 申请注册";
    ServerUnaryReactor *reactor = context->DefaultReactor();
    reactor->Finish(Status::OK);
    return reactor;
}

ServerUnaryReactor* hansolo_master::RegistePublisher(CallbackServerContext*context,const RegistePublisherRequest *request, RegistePublisherReply *reply){
    reply->set_nodename(request->nodename());
    reply->set_topicname(request->topicname());
    reply->set_port(m_port);

    //记录节点的申请发布的话题名称和端口
    for (int i = 0; i < m_all_nodes.size();i++){
        if(m_all_nodes[i].node_name==request->nodename()){
            std::pair<std::string, int> pr{request->topicname(), m_port};
            m_all_nodes[i].publish_topics.push_back(pr);
            break;
        }
    }

    m_port++;
    hDebug(Color::FG_GREEN) << "节点 " << request->nodename() << " 申请注册 publisher端口";
    ServerUnaryReactor *reactor = context->DefaultReactor();
    reactor->Finish(Status::OK);
    return reactor;
}


ServerUnaryReactor *hansolo_master::RegistOffline(CallbackServerContext *context,
                                         const OfflineRequest *request,
                                         OfflineReply *reply)
{
    reply->set_nodename(request->nodename());
    reply->set_status(true);

    auto find= std::find_if(m_all_nodes.begin(), m_all_nodes.end(), [=](const node_items &items) {
        if(items.node_name==request->nodename())
        {
            return true;
        }
        else{
            return false;
        }
    });
    if(find!=m_all_nodes.end()){
        hDebug(Color::FG_GREEN) << "节点 " << request->nodename() << " 下线";
        m_all_nodes.erase(find);
    }

    ServerUnaryReactor *reactor = context->DefaultReactor();
    reactor->Finish(Status::OK);
    return reactor;
}
