#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("node_1");
    while (rclcpp::ok())
    {
        
    }
    
    return 0;
}
