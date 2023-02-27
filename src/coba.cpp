#include "ros/ros.h"
#include "navstack_pub/Broadcaster.h"


int main(int argc, char** argv)
{
  ros::init(argc, argv, "coba");

  Broadcaster br;

  ros::shutdown();
};
