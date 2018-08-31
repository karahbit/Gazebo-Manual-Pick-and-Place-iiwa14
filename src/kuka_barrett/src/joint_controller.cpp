#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <trajectory_msgs/JointTrajectory.h>

/* There are two mechanisms for sending trajectories to the controller:
 by means of the action interface or the topic interface.
 Both use the trajectory_msgs/JointTrajectory message to specify trajectories,
 and require specifying values for all the controller joints (as opposed to only a subset)
 if allow_partial_joints_goal is not set to True.
 I could use actionlib to send the trajectory but I just wanted to use the topic and move the
 arm joints. Also for Barrett Hand, I use the topic and no actionlib.
 one more thing, to move the arm joint, I could use position_controllers/JointPositionController
 instead of position_controllers/JointTrajectoryController but the later is used by MoveIt so
 that is why I used it.*/

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "joint_controller");
  ros::NodeHandle nh;
  ros::Publisher pub1 = nh.advertise<std_msgs::Float64>("/bh_j11_position_controller/command",1000);
  ros::Publisher pub2 = nh.advertise<std_msgs::Float64>("/bh_j12_position_controller/command",1000);
  ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/bh_j13_position_controller/command",1000);
  ros::Publisher pub4 = nh.advertise<std_msgs::Float64>("/bh_j21_position_controller/command",1000);
  ros::Publisher pub5 = nh.advertise<std_msgs::Float64>("/bh_j22_position_controller/command",1000);
  ros::Publisher pub6 = nh.advertise<std_msgs::Float64>("/bh_j23_position_controller/command",1000);
  ros::Publisher pub7 = nh.advertise<std_msgs::Float64>("/bh_j31_position_controller/command",1000);
  ros::Publisher pub8 = nh.advertise<std_msgs::Float64>("/bh_j32_position_controller/command",1000);
  ros::Publisher pub9 = nh.advertise<std_msgs::Float64>("/bh_j33_position_controller/command",1000);
  //ros::Publisher pub5 = nh.advertise<trajectory_msgs::JointTrajectory > ("/arm_controller/command", 1000);
  ros::Rate loop_rate(1);

  std_msgs::Float64 msg1;  msg1.data = 0.2f;
  std_msgs::Float64 msg2;  msg2.data = 1.7f;
  std_msgs::Float64 msg3;  msg3.data = 2.0f;
  std_msgs::Float64 msg4;  msg4.data = 0.9f;
  std_msgs::Float64 msg5;  msg5.data = 1.7f;
  std_msgs::Float64 msg6;  msg6.data = 2.0f;
  std_msgs::Float64 msg7;  msg7.data = 0.9f;
  std_msgs::Float64 msg8;  msg8.data = 1.7f;
  std_msgs::Float64 msg9;  msg9.data = 2.0f;
/*
  trajectory_msgs::JointTrajectory msg5;
  msg5.header.seq = 0;
  msg5.header.stamp.sec = 0;
  msg5.header.stamp.nsec = 0;
  msg5.header.frame_id = "";

  msg5.joint_names.push_back("iiwa_joint_1");
  msg5.joint_names.push_back("iiwa_joint_2");
  msg5.joint_names.push_back("iiwa_joint_3");
  msg5.joint_names.push_back("iiwa_joint_4");
  msg5.joint_names.push_back("iiwa_joint_5");
  msg5.joint_names.push_back("iiwa_joint_6");
  msg5.joint_names.push_back("iiwa_joint_7");

  msg5.points.resize(1);

  int ind = 0;
  msg5.points[ind].positions.resize(7);
  msg5.points[ind].positions[0] = 1.7;
  msg5.points[ind].positions[1] = 1.1;
  msg5.points[ind].positions[2] = 0.5;
  msg5.points[ind].positions[3] = 0.7;
  msg5.points[ind].positions[4] = 0.9;
  msg5.points[ind].positions[5] = 1.2;
  msg5.points[ind].positions[6] = 1.5;

  // Velocities
  msg5.points[ind].velocities.resize(7);
  msg5.points[ind].effort.resize(7);
       for (size_t j = 0; j < 7; ++j)
       {
         msg5.points[ind].velocities[j]=0.0;
         msg5.points[ind].effort[j] = 0.0;
       }
  // To be reached 1 second after starting along the trajectory
  msg5.points[ind].time_from_start = ros::Duration(1.0);
*/
  while(ros::ok()){
    pub1.publish(msg1);
    pub2.publish(msg2);
    pub3.publish(msg3);
    pub4.publish(msg4);
    pub5.publish(msg5);
    pub6.publish(msg6);
    pub7.publish(msg7);
    pub8.publish(msg8);
    pub9.publish(msg9);
    ros::spinOnce();
    loop_rate.sleep();
    }
  return 0;
}




