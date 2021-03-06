#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Float64MultiArray.h"
#include "std_msgs/Header.h"


/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "std_msgs_talker");

  ros::NodeHandle nh;

//-----------define different kinds of std_msgs Publisher--------------
  ros::Publisher pub_string = nh.advertise<std_msgs::String>("topic_string", 10);
  ros::Publisher pub_int8 = nh.advertise<std_msgs::Int8>("topic_int8",10);
  ros::Publisher pub_double = nh.advertise<std_msgs::Float64MultiArray>("topic_double",10);
  ros::Publisher pub_header = nh.advertise<std_msgs::Header>("topic_header",10);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
//----------publish std_msgs/String---------
    std_msgs::String msg;
    msg.data = "hello world";
    pub_string.publish(msg);
//----------publish std_msgs/Int8----------    
    std_msgs::Int8 val_int8;
    val_int8.data = count;
    pub_int8.publish(val_int8);
//----------publish std_msgs/Float64MultiArray----------
	std_msgs::Float64MultiArray vec_double;
	vec_double.data.push_back(0.1);
	vec_double.data.push_back(0.2);
	vec_double.data.push_back(0.3);
	pub_double.publish(vec_double);
//----------publish std_msgs/Header----------
	std_msgs::Header header;
	header.seq = count;
	header.stamp = ros::Time::now();
	header.frame_id = "header_id";
	pub_header.publish(header);
	

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}
