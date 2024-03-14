#include<iostream>
#include<string>

#include"hansolo_client.h"



int main()
{
    hansolo_client node;
    bool success{};
    success=node.init_node("node1");
    std::cout << (success == true ? "创建节点成功\n" : "创建节点失败\n");

    success = node.create_publisher("test_pub");
    std::cout << (success == true ? "创建话题成功\n" : "创建话题失败\n");

}
