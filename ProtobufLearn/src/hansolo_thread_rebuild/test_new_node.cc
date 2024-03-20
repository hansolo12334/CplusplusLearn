#include<iostream>
#include"hansolo_node_new.h"

#include"hansolo_std_msg.h"



int main(int argc,char **argv)
{
    // absl::ParseCommandLine(argc, argv);

    hansolo_node client{"hansolo node"};

    sleep(1);

    HansoloPublisher<hansolo_stdMsg> pub= client.create_publisher<hansolo_stdMsg>("/test_node");

    while(1){

    }


    return 0;
}
