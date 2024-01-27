#include<ros/ros.h>
#include<iostream>
#include "proto_msg/hansolo.pb.h"
#include<std_msgs/String.h>


int main(int argc, char **argv)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;


    ros::init(argc,argv,"test_proto");

    ros::NodeHandle nh;

    ros::Publisher proto_pub;
    proto_pub= nh.advertise<std_msgs::String>("test_proto",100);

    std::cout << "1111\n";

    test::msgs::Person people;
    people.set_name("hansolo");
    people.set_age(23);
    people.set_id(1);

    std_msgs::String msg;

    people.SerializeToString(&msg.data);

    ros::Rate loop_rate(1);
    while(ros::ok())
    {
        proto_pub.publish(msg);
        loop_rate.sleep();
        ros::spinOnce();
    }


    return 0;
}
