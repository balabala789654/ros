#ifndef IMU_TO_ODOM_HPP_
#define IMU_TO_ODOM_HPP_

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <chrono>

class IMU_TO_ODOM : public rclcpp::Node{

    public:
        IMU_TO_ODOM();
        ~IMU_TO_ODOM();

    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::TimerBase::SharedPtr timer_2;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscriber;

        sensor_msgs::msg::Imu imu_;
        nav_msgs::msg::Odometry odom_;

        void info_callback();
        void imu_callback(const sensor_msgs::msg::Imu::SharedPtr _imu);
        void odom_callback();

        double orientation[4];
        double angular_velocity[3];
        double linear_acceleration[3];
        
};
#endif