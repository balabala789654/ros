#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class server_client : public rclcpp::Node
{
    public:
        server_client(std::string name) : Node(name){   
            RCLCPP_INFO(this->get_logger(), "server_client node start");
        }
    private:


};
int main(int argc, char *argv[])
{
    /* code */
    rclcpp::init(argc, argv);
    auto node = std::make_shared<server_client>("client");
    rclcpp::spin(node);
    
    return 0;
}
