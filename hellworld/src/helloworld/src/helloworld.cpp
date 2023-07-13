#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    /* code */
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("hellworld");

    rclcpp::Rate r(10);
    while (rclcpp::ok())
    {
        /* code */
        RCLCPP_INFO(node->get_logger(), "helloworld");
        r.sleep();

    }
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
