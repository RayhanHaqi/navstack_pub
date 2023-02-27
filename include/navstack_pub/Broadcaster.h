#include "ros/ros.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include <iostream>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf/transform_broadcaster.h>
#include <boost/bind.hpp>

class Broadcaster
{
public:
    Broadcaster();
    ~Broadcaster();

private:
    ros::NodeHandle                 nh_;
    ros::Rate                       rate_;
    ros::Timer                      timer_;
    ros::MultiThreadedSpinner       mts_;
    geometry_msgs::TransformStamped odom_trans;
    tf::TransformBroadcaster        odom_broadcaster;

    void timercallback(const ros::TimerEvent& event);
};