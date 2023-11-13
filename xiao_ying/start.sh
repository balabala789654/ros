colcon build --symlink-install
cmds=(  "ros2 launch livox_ros_driver2 msg_MID360_launch.py"
	"ros2 launch imu_complementary_filter complementary_filter.launch.py"
	"ros2 launch fast_lio mapping.launch.py"
	"ros2 run livox_to_pointcloud2 livox_to_pointcloud2_node"
	"ros2 launch pointcloud_to_laserscan sample_pointcloud_to_lasser_cartographer.launch.py"
	"ros2 launch linefit_ground_segmentation_ros segmentation.launch.py"
	)

for cmd in "${cmds[@]}";
do
	echo Current CMD : "$cmd"
	gnome-terminal -- bash -c "cd $(pwd);source install/setup.bash;$cmd;exec bash;"
	sleep 0.2
done
