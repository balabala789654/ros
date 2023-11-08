#include <imu_to_odom/imu_to_odom.hpp>

using namespace std::chrono_literals;

IMU_TO_ODOM::IMU_TO_ODOM() : Node("imu_to_odom_node"){

    imu_subscriber = this->create_subscription<sensor_msgs::msg::Imu>("/livox/imu", 0, std::bind(&IMU_TO_ODOM::imu_callback, this, std::placeholders::_1));
    odom_publisher = this->create_publisher<nav_msgs::msg::Odometry>("/odom", 0);

    timer_ = this->create_wall_timer(1000ms, std::bind(&IMU_TO_ODOM::info_callback, this));
    timer_2 = this->create_wall_timer(10ms, std::bind(&IMU_TO_ODOM::odom_callback, this));
}
IMU_TO_ODOM::~IMU_TO_ODOM(){

}


void IMU_TO_ODOM::info_callback(){
    RCLCPP_INFO(this->get_logger(), "helloworld");
}

void IMU_TO_ODOM::imu_callback(const sensor_msgs::msg::Imu::SharedPtr _imu){
    orientation[0] = _imu->orientation.x;    
    orientation[1] = _imu->orientation.y;    
    orientation[2] = _imu->orientation.z;    
    orientation[3] = _imu->orientation.w;   

    angular_velocity[0] = _imu->angular_velocity.x; 
    angular_velocity[1] = _imu->angular_velocity.y; 
    angular_velocity[2] = _imu->angular_velocity.z; 

    linear_acceleration[0] = _imu->linear_acceleration.x;
    linear_acceleration[1] = _imu->linear_acceleration.y;
    linear_acceleration[2] = _imu->linear_acceleration.z;
}

void IMU_TO_ODOM::odom_callback(){
    odom_.header.frame_id = "odom";
    odom_.child_frame_id = "livox_frame";

    odom_.pose.pose.orientation.x = orientation[0];
    odom_.pose.pose.orientation.y = orientation[1];
    odom_.pose.pose.orientation.z = orientation[2];
    odom_.pose.pose.orientation.w = orientation[3];

    
    odom_publisher->publish(odom_);
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<IMU_TO_ODOM>());
    rclcpp::shutdown();
    return 0;
}
