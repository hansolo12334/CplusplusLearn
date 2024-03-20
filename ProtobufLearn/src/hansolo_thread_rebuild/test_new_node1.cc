#include<iostream>
#include"hansolo_node_new.h"

#include"hansolo_std_msg.h"
#include"stdMsg.pb.h"

#include"hansolo_publisher.h"


int main(int argc,char **argv)
{
    // absl::ParseCommandLine(argc, argv);

    hansolo_node client{"hansolo node1"};

    sleep(1);

    auto pub= client.create_publisher<hansolo_stdMsg>("/test_node1");

    while(1){
        hansolo_stdMsg msg;
        msg.data = 233;
        // sleep(1);
        pub.pub(msg);
    }


    return 0;
}
