#include<ros/ros.h>
#include<iostream>
#include "proto_msg/hansolo.pb.h"
#include<std_msgs/String.h>


void proto_sub_callback(const std_msgs::String::ConstPtr &msg)
{
    test::msgs::Person people;

    people.ParseFromString(msg->data);

    ROS_INFO("get name %s and age is %d",people.name().c_str(),people.age());


}

int main(int argc, char **argv)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;


    ros::init(argc,argv,"test_proto_sub");

    ros::NodeHandle nh;

    ros::Subscriber proto_sub;
    proto_sub = nh.subscribe<std_msgs::String>("/test_proto", 100, proto_sub_callback);




    ros::Rate loop_rate(1);
    while(ros::ok())
    {
        loop_rate.sleep();
        ros::spinOnce();
    }


    return 0;
}
