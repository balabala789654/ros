#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

rclcpp::Publisher<std_msgs::msg::String>::SharedPtr talker2_publisher;

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("talker_2");
    talker2_publisher = node->create_publisher<std_msgs::msg::String>("aaa", 10);


    std_msgs::msg::String msg;
    msg.data="helloworld form tallker2";
    talker2_publisher->publish(msg);
    RCLCPP_INFO(node->get_logger(), "working");

    rclcpp::spin(node);

    return 0;
}
