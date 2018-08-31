#!/bin/bash


rostopic pub /arm_controller/command trajectory_msgs/JointTrajectory "header:
  seq: 0
  stamp:
    secs: 0
    nsecs: 0
  frame_id: ''
joint_names: ['iiwa_joint_1', 'iiwa_joint_2', 'iiwa_joint_3', 'iiwa_joint_4', 'iiwa_joint_5', 'iiwa_joint_6', 'iiwa_joint_7']
points:
- positions: [0,0,0,0,0,0,0]
  velocities: []
  accelerations: []
  effort: []
  time_from_start: {secs: 2.0, nsecs: 990099009}"
