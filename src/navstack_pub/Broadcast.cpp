#include "ros/ros.h"
#include "navstack_pub/Broadcaster.h"

Broadcaster::Broadcaster():  nh_("~"), rate_(20)
{
    timer_ = nh_.createTimer(ros::Duration(0.01), boost::bind(&Broadcaster::timercallback, this, _1));
    mts_.spin();
};

Broadcaster::~Broadcaster(){}

void Broadcaster::timercallback(const ros::TimerEvent& event)
{
    odom_trans.header.frame_id = "odom";
    odom_trans.header.stamp = ros::Time::now();
    odom_trans.child_frame_id = "base_link";

    odom_trans.transform.translation.x = 0.0;
    odom_trans.transform.translation.y = 0.0;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(0);

    odom_broadcaster.sendTransform(odom_trans);
}